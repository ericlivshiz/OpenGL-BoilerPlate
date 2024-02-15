#include "Program.h"
#include <GLFW/glfw3.h>

#include <iostream>

void Program::InitializeGLFW() const
{
	glfwInit();
}

void Program::ConfigureGLFW() const
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
}

int Program::LoadGLFunctionPointers() const
{
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}
}

void Program::HandlePositionAttrib() const 
{
	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
}
void Program::HandleTexCoordAttrib() const 
{
	// texture coord attribute
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
}

void Program::SetTexture(unsigned int& texture) const
{
	GenAndBindTexture(texture);
	SetTextureWrapping();
	SetTextureFiltering();

}

//void Program::LoadImageTexture(const char* ImagePath, int& width, int& height, int& nrChannels) const
//{
//	stbi_set_flip_vertically_on_load(true);
//
//	unsigned char* data = stbi_load(ImagePath, &width, &height, &nrChannels, 0);
//	if (data)
//	{
//		if (ImagePath = "Images/container.jpg")
//			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//
//		else if (ImagePath = "Images/smileyface.png")
//			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
//
//		glGenerateMipmap(GL_TEXTURE_2D);
//	}
//	else
//	{
//		std::cout << "Failed to load texture" << std::endl;
//	}
//	stbi_image_free(data);
//}
