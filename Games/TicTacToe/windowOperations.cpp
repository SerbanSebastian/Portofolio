#include "windowOperations.h"
#include <stdio.h>


void windowResizeCallBack(GLFWwindow* window, int width, int height) {
	fprintf(stdout, "Window was resized to width %d and height %d", width, height);
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {

		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
}

GLFWwindow* initWindow() {

	GLFWwindow* window = NULL;

	if (!glfwInit()) {
		fprintf(stderr, "Could not start glfw3");
		return window;
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_SCALE_TO_MONITOR, GLFW_TRUE);
	glfwWindowHint(GLFW_SAMPLES, 4);

	window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, glfwGetPrimaryMonitor(), NULL);

	if (window == NULL) {
		fprintf(stderr, "Could not create window");
		return window;
	}
	
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glfwSetWindowSizeCallback(window, windowResizeCallBack);
	glfwSetKeyCallback(window, keyCallback);
	glfwMakeContextCurrent(window);
	
	return window;
}

void destroyWindow(GLFWwindow* window) {

	if(window != NULL)
		glfwDestroyWindow(window);
	window = NULL;
	glfwTerminate();
}

void setColour() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}