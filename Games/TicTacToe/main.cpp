#include "windowOperations.h"
#include <stdio.h>

int main(int argc, char* argv) {
	GLFWwindow* window = NULL;

	window = initWindow();
	if (window == NULL) {
		return 1;
	}
	//setColour();
	while (!glfwWindowShouldClose(window)) {
		setColour();
		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	destroyWindow(window);
	return 0;
}