#pragma once

#include <iostream>

using namespace std;

class ShaderManager {

public:

	unsigned long get_file_length();

	int load_shader();

	int unload_shader();



};