//#include "GL/glew.h"
//#include <GLFW/glfw3.h>
//
//#include <iostream>
//
//#include "ShaderFunctions.h"
//
//int main(void)
//{
//	GLFWwindow* window;
//
//	if (!glfwInit())
//		return -1;
//
//	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
//	if (!window)
//	{
//		glfwTerminate();
//		return -1;
//	}
//
//	glfwMakeContextCurrent(window);
//
//	if (glewInit() != GLEW_OK)
//	{
//		std::cout << "Error!" << "\n";
//	}
//
//	float vertices[] = {
//	//   X      Y     
//		-0.5f, -0.5f, 
//		 0.5f, -0.5f, 
//		 0.0f,  0.5f, 
//	};
//
//	unsigned int vbo = 0;
//	glGenBuffers(1, &vbo);
//	glBindBuffer(GL_ARRAY_BUFFER, vbo);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 3 * 2, vertices, GL_STATIC_DRAW);
//
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);
//
//	while (!glfwWindowShouldClose(window))
//	{
//		glClear(GL_COLOR_BUFFER_BIT);
//
//		glBindBuffer(GL_ARRAY_BUFFER, vbo);
//		glDrawArrays(GL_TRIANGLES, 0, 3);
//
//		glfwSwapBuffers(window);
//
//		glfwPollEvents();
//	}
//
//	glfwTerminate();
//	return 0;
//}