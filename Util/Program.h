#pragma once

#include <glad/glad.h>


class Program {
public:
	void InitializeGLFW() const;
	void ConfigureGLFW() const;
	int LoadGLFunctionPointers() const;
	void HandlePositionAttrib() const;
	void HandleTexCoordAttrib() const;
	void SetTexture(unsigned int& texture) const;
	// void LoadImageTexture(const char* ImagePath, int& width, int& height, int& nrChannels) const;

private:
	void GenAndBindTexture(unsigned int& texture) const
	{
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);
	}

	void SetTextureWrapping() const
	{
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	}
	void SetTextureFiltering() const
	{
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	}
};