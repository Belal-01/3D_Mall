#include "ObjLoader.h"
#include <fstream>
#include <sstream>
#include <iostream>

ObjLoader::ObjLoader() : displayListId(0) {}

ObjLoader::~ObjLoader() {
    if (displayListId != 0) {
        glDeleteLists(displayListId, 1);
    }
}

bool ObjLoader::loadObjFile(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Failed to open OBJ file: " << filePath << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string prefix;
        ss >> prefix;

        if (prefix == "v") {
            float x, y, z;
            ss >> x >> y >> z;
            vertices.push_back(x);
            vertices.push_back(y);
            vertices.push_back(z);
        }
        else if (prefix == "vn") {
            float nx, ny, nz;
            ss >> nx >> ny >> nz;
            normals.push_back(nx);
            normals.push_back(ny);
            normals.push_back(nz);
        }
        else if (prefix == "vt") {
            float u, v;
            ss >> u >> v;
            texCoords.push_back(u);
            texCoords.push_back(v);
        }
        else if (prefix == "f") {
            unsigned int vertexIndex[3], texCoordIndex[3], normalIndex[3];
            char slash; // To parse the `/` characters

            for (int i = 0; i < 3; ++i) {
                ss >> vertexIndex[i] >> slash >> texCoordIndex[i] >> slash >> normalIndex[i];
                indices.push_back(vertexIndex[i] - 1);  // OBJ indices are 1-based
            }
        }
    }

    file.close();
    return true;
}

void ObjLoader::createDisplayList() {
    if (displayListId != 0) {
        glDeleteLists(displayListId, 1); // Delete existing list, if any
    }

    displayListId = glGenLists(1); // Generate a new Display List ID
    glNewList(displayListId, GL_COMPILE); // Begin compiling the Display List

    // Render the model into the Display List
    glBegin(GL_TRIANGLES);
    for (size_t i = 0; i < indices.size(); i++) {
        unsigned int index = indices[i];

        if (!normals.empty()) {
            glNormal3f(normals[3 * index], normals[3 * index + 1], normals[3 * index + 2]);
        }

        if (!texCoords.empty()) {
            glTexCoord2f(texCoords[2 * index], texCoords[2 * index + 1]);
        }

        glVertex3f(vertices[3 * index], vertices[3 * index + 1], vertices[3 * index + 2]);
    }
    glEnd();

    glEndList(); // End compiling the Display List
}

void ObjLoader::render() {
    if (displayListId != 0) {
        glCallList(displayListId); // Use the Display List for rendering
    }
    else {
        std::cerr << "Display List not created. Call createDisplayList() first." << std::endl;
    }
}
