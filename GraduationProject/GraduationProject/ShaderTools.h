#pragma once
#ifndef SHADER_TOOLS_H
#define SHADER_TOOLS_H

#include "NecessaryHeaders.h"

class ShaderTools {

public:

	static GLboolean glsl_ext_check(string &filename) {

		size_t len = filename.size();

		return len > 4 &&
			filename[len - 1] == 'l' &&
			filename[len - 2] == 's' &&
			filename[len - 3] == 'l' &&
			filename[len - 4] == 'g';

	}

	static GLchar ** convert_vector_to_dpointers(vector<string> &shader_src) {

		GLchar **shader_src2;
		
		shader_src2 = new GLchar*[shader_src.size()];

		for (int i = 0; i < shader_src.size(); i++) {
			
			shader_src2[i] = new GLchar[shader_src[i].size()+1];

			for (int j = 0; j < shader_src[i].size(); j++)
				shader_src2[i][j] = shader_src[i][j];

			shader_src2[i][shader_src[i].size()] = 0;

		}

		return shader_src2;
	}

	static GLint get_file_length(ifstream &file) {

		file.seekg(0, file.end);
		int len = (int)file.tellg();

		return (GLint)len;
	}

};

#endif