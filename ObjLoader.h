#ifndef OBJLOADER_H
#define OBJLOADER_H

#include <string>
#include <vector>
#include <GL/glut.h> // Include OpenGL and GLUT headers

class ObjLoader {
public:
    // Constructor and Destructor
    ObjLoader();
    ~ObjLoader();

    // Methods
    bool loadObjFile(const std::string& filePath); // Load OBJ file
    void createDisplayList(); // Create Display List for the model
    void render(); // Render the model using the Display List

private:
    // Data members to store OBJ data
    std::vector<float> vertices;   // Vertex positions
    std::vector<float> normals;    // Vertex normals
    std::vector<float> texCoords;  // Texture coordinates
    std::vector<unsigned int> indices; // Indices for faces

    GLuint displayListId; // Display List ID
};

#endif // OBJLOADER_H
