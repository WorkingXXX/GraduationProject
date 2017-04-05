#pragma once
#ifndef SHADER_TYPE_PACKAGE_H
#define SHADER_TYPE_PACKAGE_H

#include "NecessaryHeaders.h"

class ShaderTypePackage {

private:

	// vertex shader(顶点着色器)和fragment shader(片元着色器)
	// 是渲染管线必不可少的两个着色器
	string compute_shader = NULL;
	string vertex_shader; 
	string tess_control_shader = NULL;
	string tess_evaluation_shader = NULL;
	string geometry_shader = NULL;
	string fragment_shader;

public:

	ShaderTypePackage(
		string vertex_shader,
		string fragment_shader
	):vertex_shader(vertex_shader),
		fragment_shader(fragment_shader) {}

	ShaderTypePackage(
		string compute_shader,
		string vertex_shader,
		string tess_control_shader,
		string tess_evaluation_shader,
		string geometry_shader,
		string fragment_shader
	) :compute_shader(compute_shader),
		vertex_shader(vertex_shader),
		tess_control_shader(tess_control_shader),
		tess_evaluation_shader(tess_evaluation_shader),
		geometry_shader(geometry_shader),
		fragment_shader(fragment_shader) {}

	GLvoid  add_compute_shader(string compute_shader) {
		this->compute_shader = compute_shader;
	}

	string get_compute_shader() {
		return this->compute_shader;
	}

	GLvoid  add_tess_control_shader(string tess_control_shader) {
		this->tess_control_shader = tess_control_shader;
	}

	string get_tess_control_shader() {
		return this->tess_control_shader;
	}

	GLvoid  add_tess_evaluation_shader(string tess_evaluation_shader) {
		this->tess_evaluation_shader = tess_evaluation_shader;
	}

	string get_tess_evaluation_shader() {
		return this->tess_evaluation_shader;
	}

	GLvoid  add_geometry_shader(string geometry_shader) {
		this->geometry_shader = geometry_shader;
	}

	string get_geometry_shader() {
		return this->geometry_shader;
	}

	string get_vertex_shader() {
		return this->vertex_shader;
	}

	string get_fragment_shader() {
		return this->fragment_shader;
	}
};

#endif
