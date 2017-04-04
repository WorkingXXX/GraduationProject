
#include "ShaderManager.h"

GLboolean glsl_ext_check(string &filename) {

	GLint len = filename.size();

	return len > 4 &&
		filename[len - 1] == 'l' &&
		filename[len - 2] == 's' &&
		filename[len - 3] == 'l' &&
		filename[len - 4] == 'g';

}

GLint ShaderManager::get_file_length(fstream &file) {

	GLint pos = file.tellg();
	file.seekg(0, ios::end);

	GLint len = file.tellg();
	file.seekg(ios::beg);

	return len;
}

GLvoid ShaderManager::load_shader(string &filename, GLchar **shader_src, GLint &len) {

	cout << "Loading Shader..." << endl;

	if (!glsl_ext_check(filename)) {
		cout << "Error : Please input an glsl file" << endl;
		return;
	}

	fstream file(filename, fstream::in);

	if (!file) {
		cout << "Error : Fail to open file " << filename << endl;
		return;
	}

	len = get_file_length(file);

	if (len) {

		*shader_src = new GLchar[len + 1];

		if (*shader_src == 0) {
			cout << "Error : Fail to reserve memory to shader_src" << endl;
			return;
		}
			
		*shader_src[len] = 0;

		GLint i = 0;

		// 将GLSL源文件一行行读入shader_src中
		while (file.good()) {

			*shader_src[i] = file.get();
			if (!file.eof())
				i++;

		}

		// 手动添加字符串结束符
		*shader_src[i] = 0;

		file.close();

	}

	cout << "Loading End" << endl;

}

GLvoid ShaderManager::unload_shader(GLchar **shader_src) {

	cout << "Unloading Shader..." << endl;

	if (*shader_src != 0)
		delete[] *shader_src;

	*shader_src = 0;

	cout << "Unloading End" << endl;

}

GLuint ShaderManager::compile_shader(GLchar **shader_src, int shader_type, GLint &len) {
	
	cout << "Compiling Shader..." << endl;

	GLuint shader_index;

	// 创建相应类型的Shader
	switch (shader_type) {
	
	case GL_COMPUTE_SHADER:shader_index = glCreateShader(GL_COMPUTE_SHADER); break;
	case GL_VERTEX_SHADER:shader_index = glCreateShader(GL_VERTEX_SHADER);break;
	case GL_TESS_CONTROL_SHADER:shader_index = glCreateShader(GL_TESS_CONTROL_SHADER);break;
	case GL_TESS_EVALUATION_SHADER:shader_index = glCreateShader(GL_TESS_EVALUATION_SHADER);break;
	case GL_GEOMETRY_SHADER:shader_index = glCreateShader(GL_GEOMETRY_SHADER);break;
	case GL_FRAGMENT_SHADER:shader_index = glCreateShader(GL_FRAGMENT_SHADER); break;

	default:
		cout << "Error : Unkown Shader Type" << endl;
		return;
	}

	// 编译Shader
	glShaderSource(shader_index, 1, shader_src, &len);
	glCompileShaderARB(shader_index);

	// 检测编译结果
	GLint compile_status;

	glGetObjectParameterivARB(shader_index, GL_COMPILE_STATUS, &compile_status);
	
	if (compile_status) {

		cout << "Shader " << shader_index << " has been compiled successfully" << endl;

	}
	else {

		cout << "Error : Fail to compile" << endl;

		GLint blen = 0, slen = 0;
		// 输出编译日志
		glGetShaderiv(shader_index, GL_INFO_LOG_LENGTH, &blen);

		if (blen > 1) {

			GLchar *compiler_log = new GLchar[blen];

			glGetInfoLogARB(shader_index, blen, &slen, compiler_log);

			cout << compiler_log << endl;

			delete compiler_log;

		}

	}

	return shader_index;

	cout << "Compiling End" << endl;
}

GLvoid ShaderManager::link_shader(GLuint &prgm_idx, vector<GLuint> shaders_idx) {

	cout << "Linking Shaders..." << endl;

	for (int i = 0; i < shaders_idx.size(); i++)
		glAttachShader(prgm_idx, shaders_idx[i]);

	this->prgms_vtr.push_back(prgm_idx);

	GLint link_status;

	if (link_status) {

		cout << "Shader Program " << prgm_idx << " has been linked successfully" << endl;

	}
	else {

		cout << "Error : Fail to link" << endl;

		GLint blen = 0, slen = 0;
		// 输出编译日志
		glGetShaderiv(prgm_idx, GL_INFO_LOG_LENGTH, &blen);

		if (blen > 1) {

			GLchar *linker_log = new GLchar[blen];

			glGetInfoLogARB(prgm_idx, blen, &slen, linker_log);

			cout << linker_log << endl;

			delete linker_log;

		}

	}

	cout << "Linking End" << endl;
}

GLvoid ShaderManager::execute_shader_program(GLuint &prgm_idx) {

	if(this->prgms_vtr.end() == 
		find(this->prgms_vtr.begin(), this->prgms_vtr.end(), prgm_idx)) {

		cout << "Error : Shader Program " << prgm_idx << " has not been created" << endl;

	}
	else {

		cout << "Executing Shader Program " << prgm_idx << endl;

		glUseProgram(prgm_idx);

	}

}

GLvoid ShaderManager::stop_shader_program() {

	cout << "Stop the shader program" << endl;

	glUseProgram(0);

}