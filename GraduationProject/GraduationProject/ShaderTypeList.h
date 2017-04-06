#pragma once
#ifndef SHADER_TYPE_LIST_H
#define SHADER_TYPE_LIST_H

#include "NecessaryHeaders.h"

const int SHADER_TYPE_NUM = 6;

enum ShaderType {
	COMPUTE_SHADER,
	VERTEX_SHADER,
	TESS_CONTROL_SHADER,
	TESS_EVALUATION_SHADER,
	GEOMETRY_SHADER,
	FRAGMENT_SHADER
};

const GLuint ShaderTypeIndex[SHADER_TYPE_NUM] = {
	GL_COMPUTE_SHADER,
	GL_VERTEX_SHADER,
	GL_TESS_CONTROL_SHADER,
	GL_TESS_EVALUATION_SHADER,
	GL_GEOMETRY_SHADER,
	GL_FRAGMENT_SHADER
};


class ShaderTypeList {

private:

	string shader_type_list[SHADER_TYPE_NUM] = { "" };

public:

	ShaderTypeList(
		string vertex_shader,
		string fragment_shader
	) {
		this->shader_type_list[VERTEX_SHADER] = vertex_shader;
		this->shader_type_list[FRAGMENT_SHADER] = fragment_shader;
	}

	ShaderTypeList(
		string compute_shader,
		string vertex_shader,
		string tess_control_shader,
		string tess_evaluation_shader,
		string geometry_shader,
		string fragment_shader
	) {
		this->shader_type_list[COMPUTE_SHADER] = compute_shader;
		this->shader_type_list[VERTEX_SHADER] = vertex_shader;
		this->shader_type_list[TESS_CONTROL_SHADER] = tess_control_shader;
		this->shader_type_list[TESS_EVALUATION_SHADER] = tess_evaluation_shader;
		this->shader_type_list[GEOMETRY_SHADER] = geometry_shader;
		this->shader_type_list[FRAGMENT_SHADER] = fragment_shader;
	}
		GLvoid  add_compute_shader(string compute_shader) {
		this->shader_type_list[COMPUTE_SHADER] = compute_shader;
	}

	string get_compute_shader() {
		return this->shader_type_list[COMPUTE_SHADER];
	}

	GLvoid  add_tess_control_shader(string tess_control_shader) {
		this->shader_type_list[TESS_CONTROL_SHADER] = tess_control_shader;
	}

	string get_tess_control_shader() {
		return this->shader_type_list[TESS_CONTROL_SHADER];
	}

	GLvoid  add_tess_evaluation_shader(string tess_evaluation_shader) {
		this->shader_type_list[TESS_EVALUATION_SHADER] = tess_evaluation_shader;
	}

	string get_tess_evaluation_shader() {
		return this->shader_type_list[TESS_EVALUATION_SHADER];
	}

	GLvoid  add_geometry_shader(string geometry_shader) {
		this->shader_type_list[GEOMETRY_SHADER] = geometry_shader;
	}

	string get_geometry_shader() {
		return this->shader_type_list[GEOMETRY_SHADER];
	}

	string get_vertex_shader() {
		return this->shader_type_list[VERTEX_SHADER];
	}

	string get_fragment_shader() {
		return this->shader_type_list[FRAGMENT_SHADER];
	}

	string *get_list() {
		return this->shader_type_list;
	}
};

#endif
