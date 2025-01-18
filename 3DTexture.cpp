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
    GLTexture() : textureID(0), textureName("") {}

    // Destructor
    ~GLTexture() {
        // Free OpenGL texture resources
        if (textureID != 0) {
            glDeleteTextures(1, &textureID);
        }
    }

    // Load texture from a file

    bool loadTexture(const char* name) {
        if (!name || std::strlen(name) == 0) {
            printf("Invalid texture name.\n");
            return false;
        }

        // Store the lowercase version of the texture name
        char* lowerCaseName = _strdup(name);
        if (!lowerCaseName) {
            printf("Memory allocation failed for texture name.\n");
            return false;
        }

        // Convert the name to lowercase using _strlwr_s
        errno_t err = _strlwr_s(lowerCaseName, std::strlen(lowerCaseName) + 1);
        if (err != 0) {
            printf("Error converting texture name to lowercase.\n");
            free(lowerCaseName);
            return false;
        }

        textureName = lowerCaseName;
        free(lowerCaseName);

        // Simulate texture loading (replace with actual loading logic)
        glGenTextures(1, &textureID);
        glBindTexture(GL_TEXTURE_2D, textureID);

        // Placeholder for actual texture loading logic
        printf("Texture '%s' loaded with ID: %u\n", textureName.c_str(), textureID);

        return true;
    }

    // Bind the texture for rendering
    void bind() const {
        if (textureID != 0) {
            glBindTexture(GL_TEXTURE_2D, textureID);
        }
        else {
            printf("Attempting to bind an uninitialized texture.\n");
        }
    }

    // Unbind any texture
    static void unbind() {
        glBindTexture(GL_TEXTURE_2D, 0);
    }

    // Getters
    GLuint getTextureID() const { return textureID; }
    const std::string& getTextureName() const { return textureName; }
};
