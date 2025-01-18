#pragma once
#include <gl/glut.h>
//#include "Cuboid.h"
class TTexture
{
public:
	GLuint textureID;
	void loadTexture(const char* filename);

	void Use();
};
