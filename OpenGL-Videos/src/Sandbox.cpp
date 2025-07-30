#include "GL/glew.h"
#include <GLFW/glfw3.h>

#include <iostream>

#include "ShaderFunctions.h"

int main(void)
{
	GLFWwindow* window;

	if (!glfwInit())
		return -1;

	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK)
	{
		std::cout << "Error!" << "\n";
	}

	unsigned int vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	float vertices_coords[] = 
	{
	//	 X      Y     R     G     B     A
		-0.5f, -0.5f, 
		 0.5f, -0.5f, 
		 0.0f,  0.5f
	};

	float vertices_colors[] =
	{
		1.0f, 0.5f, 0.0f, 1.0f,
		0.0f, 0.5f, 0.1f, 1.0f,
		0.5f, 0.5f, 0.5f, 1.0f
	};

	unsigned int vbo_pos = 0;
	glGenBuffers(1, &vbo_pos);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_pos);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 3 * 2, vertices_coords, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);

	unsigned int vbo_color = 0;
	glGenBuffers(1, &vbo_color);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_color);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 3 * 4, vertices_colors, GL_STATIC_DRAW);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);

	unsigned int shaderProgram = CreateShader("res/shaders/BasicVertex.glsl", "res/shaders/BasicFragment.glsl");

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(shaderProgram);
		glBindVertexArray(vao);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window);

		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}