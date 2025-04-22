#include<iostream>
#include<glad\glad.h>
#include<GLFW\glfw3.h>
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

int main()
{

	glfwInit();
	//opengl 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	GLFWwindow* window = glfwCreateWindow(800, 600, "OPENGL LEARNING", NULL, NULL);//window create (width , height , name)
	if (window == NULL)//window not created
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	glViewport(0, 0, 800, 600); //(coord of lower left corner , width and height)

	glfwSetFramebufferSizeCallback(window , framebuffer_size_callback);

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	while (!glfwWindowShouldClose(window))
	{
		
		glfwSwapBuffers(window);//swap buffer , back to front , then draws in back and it comnes to front and it goes on...
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}