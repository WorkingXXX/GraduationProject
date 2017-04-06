#pragma once
#ifndef SHADER_MANAGER_H
#define SHADER_MANAGER_H

#include "NecessaryHeaders.h"
#include "ShaderTypeList.h"

class ShaderManager {

public:
	// 检测文件后缀是否为glsl
	GLboolean glsl_ext_check(string &filename);

	GLint get_file_length(fstream &file);
	// 将GLSL代码从文件加载到内存中
	GLvoid load_shader(string &filename, GLchar **shader_src, GLint &len);

	GLvoid unload_shader(GLchar **shader_src);

	GLuint compile_shader(GLchar **shader_src, GLuint shader_type, GLint &len);

	GLvoid link_shader(GLuint &prgm_idx, vector<GLuint> shaders_idx);

	GLvoid execute_shader_program(GLuint &prgm_idx);

	GLvoid stop_shader_program();

	GLuint create_shader_program(ShaderTypeList &shader_list);

private:

	vector<GLuint> prgms_vtr;

};

#endif