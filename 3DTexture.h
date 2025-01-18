#ifndef GLTEXTURE_H
#define GLTEXTURE_H

#include <GL/glut.h>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>

class GLTexture {
private:
    GLuint textureID; // OpenGL texture ID
    std::string textureName; // Name of the texture

public:
    // Constructor
    GLTexture();

    // Destructor
    ~GLTexture();

    // Load texture from a file
    bool loadTexture(const char* name);

    // Bind the texture for rendering
    void bind() const;

    // Unbind any texture
    static void unbind();

    // Getters
    GLuint getTextureID() const;
    const std::string& getTextureName() const;
};

#endif // GLTEXTURE_H
