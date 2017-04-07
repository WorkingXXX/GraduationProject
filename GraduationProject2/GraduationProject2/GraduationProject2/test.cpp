
#include "NecessaryHeaders.h"
#include "ShaderTypeList.h"
#include "ShaderManager.h"
#include "ShaderTools.h"

//int main() {
//
//	glewInit();
//
//	string file1 = "vertex_shader.glsl";
//	string file2 = "fragment_shader.glsl";
//	string file3 = "asd.zxc";
//
//	ShaderManager shader_mgr;
//
//	// ²âÊÔ glsl_ext_check º¯Êý
//	cout << (shader_mgr.glsl_ext_check(file1) == true) << endl;
//	cout << (shader_mgr.glsl_ext_check(file2) == false) << endl;
//	cout << (shader_mgr.glsl_ext_check(file3) == true) << endl;
//
//	ifstream infile1(file1, ifstream::in);
//	ifstream infile2(file2, ifstream::in);
//
//	// ²âÊÔ get_file_length º¯Êý
//	cout << shader_mgr.get_file_length(infile1) << endl;
//	cout << shader_mgr.get_file_length(infile2) << endl;
//
//	int len = shader_mgr.get_file_length(infile1);
//
//	vector<string> shader_src;
//	shader_mgr.load_shader(file1, shader_src);
//	for (int i = 0; i < shader_src.size(); i++)
//		cout << shader_src[i] << endl;
//
//	GLchar **shader_src2 = ShaderTools::convert_vector_to_dpointers(shader_src);
//
//	for (int i = 0; i < shader_src.size(); i++)
//		cout << shader_src2[i];// << endl;
//
//	/*GLuint prgm_idx = 0;
//	ShaderTypeList shader_type_list("vertex_shader.glsl", "fragment_shader.glsl");
//	shader_mgr.create_shader_program(shader_type_list);*/
//
//	system("pause");
//}

GLuint vert_array;
GLuint buffer;

int vPosition = 0;

void init() {

	glGenVertexArrays(1, &vert_array);
	glBindVertexArray(vert_array);

	GLdouble verts[6][2] = {
		{-0.9, -0.9},
		{0.85, -0.9},
		{-0.9, 0.85},
		{0.9, -0.85},
		{0.9, 0.9},
		{-0.85, 0.9}
	};

	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);

	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);

	ShaderTypeList shader_type_list("vertex_shader.glsl", "fragment_shader.glsl");

	ShaderManager shader_mgr;
	
	GLuint prgm_idx = shader_mgr.create_shader_program(shader_type_list);
	shader_mgr.execute_shader_program(prgm_idx);

	glVertexAttribPointer(vPosition, 2, GL_DOUBLE, GL_FALSE, 0, BUFFER_OFFSET(0));

	glEnableVertexAttribArray(vPosition);

	glClearColor(1.0, 1.0, 1.0, 1.0);
}

void display() {

	glClear(GL_COLOR_BUFFER_BIT);
	glBindVertexArray(vert_array);
	glDrawArrays(GL_TRIANGLES, 0, 6);

	glFlush();

}

int main(int argc, char **argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowSize(1000, 600);
	glutInitContextVersion(4, 3);
	glutInitContextProfile(GLUT_CORE_PROFILE);
	glutCreateWindow(argv[0]);

	if (glewInit()) {
		cerr << "Unable to initialize GLEW...exiting" << endl;
		exit(EXIT_FAILURE);
	}

	init();
	glutDisplayFunc(display);

	glutMainLoop();
}

//#include<GL\glew.h>
//#include<iostream>
//#include<GL\freeglut.h>
//
//#pragma once
//
//void Render_All()
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	glBegin(GL_POLYGON);
//	glColor3f(1, 0, 0); glVertex2f(0.5, 0.5);
//	glColor3f(1, 0, 0); glVertex2f(0.5, -0.5);
//	glColor3f(1, 0, 0); glVertex2f(-0.5, -0.5);
//	glColor3f(1, 0, 0); glVertex2f(-0.5, 0.5);
//	glEnd();
//	glFlush();
//}
//
//int main(int argc, char** argv)
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(300, 300);
//	glutCreateWindow("Square");
//	glutFullScreen();
//	glutDisplayFunc(Render_All);
//
//	GLenum Error = glewInit();
//
//	if (GLEW_OK != Error)
//	{
//		fprintf(stderr, "GLEW Error");
//		return EXIT_FAILURE;
//	}
//
//	glutMainLoop();
//	return 0;
//}
