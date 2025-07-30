#include "ShaderFunctions.h"

unsigned int CompileShader(unsigned int type, const std::string& source)
{
	unsigned int id = glCreateShader(type);
	const char* src = source.c_str();
	// The second parameter indicates how many strings will be in the array of the source
	// The second one, if it's nullptr, indicates that the strings of the array will be null terminated
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);

	int result;
	// glGetShaderiv returns a parameter from a shader object. In this case the parameter will be stored in result
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE)
	{
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char* message = (char*)alloca(length * sizeof(char));
		glGetShaderInfoLog(id, length, &length, message);
		std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << "shader! " << "\n";
		std::cout << message << "\n";
		glDeleteShader(id);
		return 0;
	}

	return id;

}

unsigned int CreateShader(const std::string& vertexPath, const std::string& fragmentPath)
{
	unsigned int program = glCreateProgram();
	unsigned int vs = CompileShader(GL_VERTEX_SHADER, FileToString(vertexPath));
	unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, FileToString(fragmentPath));

	// A program is a group of glsl that can run on the GPU
	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(vs);
	glDeleteShader(fs);

	return program;
}

std::string FileToString(const std::string& filePath)
{
	std::ifstream file(filePath);
	if (!file.is_open()) std::cout << "ERROR WHILE TRYING TO OPEN " << filePath << "\n";
	std::stringstream buffer;
	buffer << file.rdbuf();
	return buffer.str();	
}
