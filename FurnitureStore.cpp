#include "FurnitureStore.h"
#include "BilalMain.h"
#include <iostream>
#include "texture.h"
#include "Wall.h"
#include <GL/glut.h>
#define M_PI 3.14159265358979323846

void FurnitureStore::init() {
    FurnitureStore::SofaTextureID = LoadTexture((char*)"LeatherSofa1.bmp", 255.0f);
    FurnitureStore::Table1TextureID = LoadTexture((char*)"WoodTable3.bmp", 255.0f);
    FurnitureStore::CT_columnTextureID = LoadTexture((char*)"tmp4.bmp", 255.0f);
    FurnitureStore::CT_tabletopTextureID = LoadTexture((char*)"PlasticTable2.bmp", 255.0f);
    FurnitureStore::CH_tabletopTextureID = LoadTexture((char*)"CircularFabric1.bmp", 255.0f);
}
void FurnitureStore::display() {
    drawLambaderAtPosition(3700, 0, 4700);
    drawSofa(3500, 0, 1500, 400, 800, 300, 125, 75, 0, SofaTextureID, 0.0f);
    drawSofa(2800, 0, 2100, 400, 800, 300, 125, 75, 0, SofaTextureID, 270.0f);
    drawSofa(2800, 0, 900, 400, 800, 300, 120, 70, 0, SofaTextureID, 90.0f);

    drawTable(1375, 0, 1350, 250, 300, 200, 225, 75, 0, Table1TextureID);
    drawTable(1200, 0, 1250, 300, 500, 250, 225, 15, 0, Table1TextureID);
    drawTable(1075, 0, 1350, 250, 300, 200, 225, 75, 0, Table1TextureID);

    circlerTable(3200, 0, 4200, 300, 300, 32, CT_tabletopTextureID, CT_columnTextureID);
    drawCirclerChair(3400, 0, 3900, 80, 200, 100, CH_tabletopTextureID, CT_columnTextureID, 1);
    drawCirclerChair(2900, 0, 4000, 80, 200, 100, CH_tabletopTextureID, CT_columnTextureID, 1);
    drawCirclerChair(2900, 0, 4400, 80, 200, 100, CH_tabletopTextureID, CT_columnTextureID, 1);
}

void drawCylinder(float baseX, float baseY, float baseZ, float radius, float height, int segments, int textureID, float repeatFactor) {
    glBindTexture(GL_TEXTURE_2D, textureID);
    glBegin(GL_QUAD_STRIP);

    for (int i = 0; i <= segments; i++) {
        float angle = 2.0f * M_PI * i / segments;
        float x = baseX + radius * cos(angle);
        float z = baseZ + radius * sin(angle);
        float texX = (float)i / segments * repeatFactor;

        glTexCoord2f(texX, 0.0f);
        glVertex3f(x, baseY, z);
        glTexCoord2f(texX, 1.0f);
        glVertex3f(x, baseY + height, z);
    }

    glEnd();
}
void FurnitureStore::drawCirclerChair(float baseX, float baseY, float baseZ, float radius, float height, int segments, int seatTextureID, int legTextureID, float repeatFactor) {
    float seatThickness = 20.0f;             // Thickness of the seat
    float legRadius = radius * 0.15f;        // Central leg radius
    float legHeight = height - seatThickness; // Height of the central leg
    float baseRadius = radius * 0.6f;        // Radius of the circular base
    float baseThickness = 10.0f;            // Thickness of the circular base

    // Enable texturing for the seat
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, seatTextureID);

    // Draw the top face of the circular seat
    glBegin(GL_TRIANGLE_FAN);
    glTexCoord2f(0.5f, 0.5f); // Center of the texture
    glVertex3f(baseX, baseY + height, baseZ); // Center of the seat

    for (int i = 0; i <= segments; i++) {
        float angle = 2.0f * M_PI * i / segments;
        float x = baseX + radius * cos(angle);
        float z = baseZ + radius * sin(angle);
        float texX = 0.5f + 0.5f * cos(angle) * repeatFactor;
        float texY = 0.5f + 0.5f * sin(angle) * repeatFactor;

        glTexCoord2f(texX, texY);
        glVertex3f(x, baseY + height, z);
    }
    glEnd();

    // Draw the bottom face of the seat
    glBegin(GL_TRIANGLE_FAN);
    glTexCoord2f(0.5f, 0.5f);
    glVertex3f(baseX, baseY + height - seatThickness, baseZ); // Center of the seat bottom

    for (int i = 0; i <= segments; i++) {
        float angle = 2.0f * M_PI * i / segments;
        float x = baseX + radius * cos(angle);
        float z = baseZ + radius * sin(angle);
        float texX = 0.5f + 0.5f * cos(angle) * repeatFactor;
        float texY = 0.5f + 0.5f * sin(angle) * repeatFactor;

        glTexCoord2f(texX, texY);
        glVertex3f(x, baseY + height - seatThickness, z);
    }
    glEnd();

    // Draw the sides of the seat
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= segments; i++) {
        float angle = 2.0f * M_PI * i / segments;
        float x = baseX + radius * cos(angle);
        float z = baseZ + radius * sin(angle);
        float texX = (float)i / segments * repeatFactor;

        glTexCoord2f(texX, 0.0f);
        glVertex3f(x, baseY + height - seatThickness, z); // Bottom edge
        glTexCoord2f(texX, 1.0f);
        glVertex3f(x, baseY + height, z); // Top edge
    }
    glEnd();

    // Draw the central leg
    glBindTexture(GL_TEXTURE_2D, legTextureID);
    drawCylinder(baseX, baseY + baseThickness, baseZ, legRadius, legHeight, segments, legTextureID, repeatFactor);

    // Draw the top face of the circular base
    glBegin(GL_TRIANGLE_FAN);
    glTexCoord2f(0.5f, 0.5f);
    glVertex3f(baseX, baseY + baseThickness, baseZ); // Center of the base top

    for (int i = 0; i <= segments; i++) {
        float angle = 2.0f * M_PI * i / segments;
        float x = baseX + baseRadius * cos(angle);
        float z = baseZ + baseRadius * sin(angle);
        float texX = 0.5f + 0.5f * cos(angle) * repeatFactor;
        float texY = 0.5f + 0.5f * sin(angle) * repeatFactor;

        glTexCoord2f(texX, texY);
        glVertex3f(x, baseY + baseThickness, z);
    }
    glEnd();

    // Draw the bottom face of the circular base
    glBegin(GL_TRIANGLE_FAN);
    glTexCoord2f(0.5f, 0.5f);
    glVertex3f(baseX, baseY, baseZ); // Center of the base bottom

    for (int i = 0; i <= segments; i++) {
        float angle = 2.0f * M_PI * i / segments;
        float x = baseX + baseRadius * cos(angle);
        float z = baseZ + baseRadius * sin(angle);
        float texX = 0.5f + 0.5f * cos(angle) * repeatFactor;
        float texY = 0.5f + 0.5f * sin(angle) * repeatFactor;

        glTexCoord2f(texX, texY);
        glVertex3f(x, baseY, z);
    }
    glEnd();

    // Draw the sides of the circular base
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= segments; i++) {
        float angle = 2.0f * M_PI * i / segments;
        float x = baseX + baseRadius * cos(angle);
        float z = baseZ + baseRadius * sin(angle);

        glTexCoord2f((float)i / segments, 0.0f);
        glVertex3f(x, baseY, z); // Bottom edge
        glTexCoord2f((float)i / segments, 1.0f);
        glVertex3f(x, baseY + baseThickness, z); // Top edge
    }
    glEnd();

    // Disable texturing
    glDisable(GL_TEXTURE_2D);
}



void FurnitureStore::drawTable(float x, float y, float z, float width, float depth, float height, int red, int green, int blue, int textureID) {
    int baseLayerHeight = height / 8;
    drawCube(x, y + height - baseLayerHeight, z, width, depth, baseLayerHeight, red, green, blue, textureID, 1);

    drawLeg(x + 20, 0, z + 20, 20, 20, height - baseLayerHeight, 0, 0, 0, textureID);
    drawLeg(x + 20, 0, z + depth - 40, 20, 20, height - baseLayerHeight, 0, 0, 0, textureID);
    drawLeg(x + width - 40, 0, z + 20, 20, 20, height - baseLayerHeight, 0, 0, 0, textureID);
    drawLeg(x + width - 40, 0, z + depth - 40, 20, 20, height - baseLayerHeight, 0, 0, 0, textureID);
}

void FurnitureStore::drawSofa(float x, float y, float z, float width, float depth, float height, int red, int green, int blue, int textureID, float rotationAngle) {
    glPushMatrix();

    
    glTranslatef(x + width / 2, y, z + depth / 2); 
    glRotatef(rotationAngle, 0, 1, 0);            
    glTranslatef(-(x + width / 2), -y, -(z + depth / 2)); 

    int legHeight = 50;
    drawCube(x + 20, y, z + 20, 20, 20, legHeight, 150, 75, 0, -1, 1);
    drawCube(x + width - 40, y, z + 20, 20, 20, legHeight, 150, 75, 0, -1, 1);
    drawCube(x + 20, y, z + depth - 60, 20, 20, legHeight, 150, 75, 0, -1, 1);
    drawCube(x + width - 40, y, z + depth - 60, 20, 20, legHeight, 150, 75, 0, -1, 1);

    int baseLayer = 130;
    drawCube(x, y + 50, z, width, depth, baseLayer, red, green, blue, textureID, 2);

    drawCube(x, y + legHeight + baseLayer, z, width, depth / 6, baseLayer / 2, red, green, blue, textureID, 1);
    drawCube(x, y + legHeight + baseLayer, z + depth - depth / 6, width, depth / 6, baseLayer / 2, red, green, blue, textureID, 1);

    drawCube(x + width - ((width) / 3), y + legHeight + baseLayer, z + depth / 6, width / 3, depth - depth / 3, height - baseLayer - legHeight, red, green, blue, textureID, 2);

    glPopMatrix(); 
}



void FurnitureStore::drawLeg(float x, float y, float z, float width, float depth, float height, int red, int green, int blue, int texture) {
    drawCube(x, y, z, width, depth, height, 150, 75, 0, -1, 1);
}

void FurnitureStore::drawCube(float x, float y, float z, float width, float depth, float height, int red, int green, int blue, int textureID, float repeatFactor) {
    glColor3ub(red, green, blue);

    if (textureID != -1) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    }
    else {
        glDisable(GL_TEXTURE_2D);
    }

    glBegin(GL_QUADS);

    // Front face
    if (textureID != -1) { glTexCoord2f(0, 0); }
    glVertex3f(x, y, z);
    if (textureID != -1) { glTexCoord2f(0, repeatFactor); }
    glVertex3f(x, y, z + depth);
    if (textureID != -1) { glTexCoord2f(repeatFactor, repeatFactor); }
    glVertex3f(x, y + height, z + depth);
    if (textureID != -1) { glTexCoord2f(repeatFactor, 0); }
    glVertex3f(x, y + height, z);

    // Back face
    if (textureID != -1) { glTexCoord2f(0, 0); }
    glVertex3f(x + width, y, z);
    if (textureID != -1) { glTexCoord2f(0, 1); }
    glVertex3f(x + width, y, z + depth);
    if (textureID != -1) { glTexCoord2f(1, 1); }
    glVertex3f(x + width, y + height, z + depth);
    if (textureID != -1) { glTexCoord2f(1, 0); }
    glVertex3f(x + width, y + height, z);

    // Top face
    if (textureID != -1) { glTexCoord2f(0, 0); }
    glVertex3f(x, y + height, z);
    if (textureID != -1) { glTexCoord2f(0, repeatFactor); }
    glVertex3f(x, y + height, z + depth);
    if (textureID != -1) { glTexCoord2f(repeatFactor, repeatFactor); }
    glVertex3f(x + width, y + height, z + depth);
    if (textureID != -1) { glTexCoord2f(repeatFactor, 0); }
    glVertex3f(x + width, y + height, z);

    // Bottom face
    //if (textureID != -1) { glTexCoord2f(0, 0); }
    glVertex3f(x, y, z);
    //if (textureID != -1) { glTexCoord2f(0, repeatFactor); }
    glVertex3f(x, y, z + depth);
    //if (textureID != -1) { glTexCoord2f(repeatFactor, repeatFactor); }
    glVertex3f(x + width, y, z + depth);
    //if (textureID != -1) { glTexCoord2f(repeatFactor, 0); }
    glVertex3f(x + width, y, z);

    // Left face (x constant)
    if (textureID != -1) { glTexCoord2f(0, 0); }
    glVertex3f(x, y, z + depth);
    if (textureID != -1) { glTexCoord2f(0, 1); }
    glVertex3f(x, y + height, z + depth);
    if (textureID != -1) { glTexCoord2f(1, 1); }
    glVertex3f(x + width, y + height, z + depth);
    if (textureID != -1) { glTexCoord2f(1, 0); }
    glVertex3f(x + width, y, z + depth);

    // Right face (x constant)
    if (textureID != -1) { glTexCoord2f(0, 0); }
    glVertex3f(x, y, z);
    if (textureID != -1) { glTexCoord2f(0, 1); }
    glVertex3f(x, y + height, z);
    if (textureID != -1) { glTexCoord2f(1, 1); }
    glVertex3f(x + width, y + height, z);
    if (textureID != -1) { glTexCoord2f(1, 0); }
    glVertex3f(x + width, y, z);


    glEnd();

    if (textureID != -1) {
        glDisable(GL_TEXTURE_2D);
    }
}

void drawCylinder(float x, float y, float z, float radius, float height, int slices, int red, int green, int blue) {
    glColor3ub(red, green, blue); // Set color

    // Draw the sides
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= slices; i++) {
        float angle = 2.0f * M_PI * i / slices; // Angle for this slice
        float xOffset = cos(angle) * radius;
        float zOffset = sin(angle) * radius;

        glVertex3f(x + xOffset, y, z + zOffset);             // Bottom circle
        glVertex3f(x + xOffset, y + height, z + zOffset);   // Top circle
    }
    glEnd();

    // Draw the top and bottom circles
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(x, y, z); // Center of bottom circle
    for (int i = 0; i <= slices; i++) {
        float angle = 2.0f * M_PI * i / slices;
        float xOffset = cos(angle) * radius;
        float zOffset = sin(angle) * radius;
        glVertex3f(x + xOffset, y, z + zOffset);
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(x, y + height, z); // Center of top circle
    for (int i = 0; i <= slices; i++) {
        float angle = 2.0f * M_PI * i / slices;
        float xOffset = cos(angle) * radius;
        float zOffset = sin(angle) * radius;
        glVertex3f(x + xOffset, y + height, z + zOffset);
    }
    glEnd();
}

void drawFrustum(float x, float y, float z, float baseRadius, float topRadius, float height, int slices, int red, int green, int blue) {
    glColor3ub(red, green, blue); // Set color

    // Draw the sides
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= slices; i++) {
        float angle = 2.0f * M_PI * i / slices; // Angle for this slice
        float xOffsetBase = cos(angle) * baseRadius;
        float zOffsetBase = sin(angle) * baseRadius;
        float xOffsetTop = cos(angle) * topRadius;
        float zOffsetTop = sin(angle) * topRadius;

        glVertex3f(x + xOffsetBase, y, z + zOffsetBase);       // Bottom circle
        glVertex3f(x + xOffsetTop, y + height, z + zOffsetTop); // Top circle
    }
    glEnd();

    // Draw the top circle
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(x, y + height, z); // Center of the top circle
    for (int i = 0; i <= slices; i++) {
        float angle = 2.0f * M_PI * i / slices;
        float xOffset = cos(angle) * topRadius;
        float zOffset = sin(angle) * topRadius;
        glVertex3f(x + xOffset, y + height, z + zOffset);
    }
    glEnd();
}

void FurnitureStore::drawLambaderAtPosition(float x, float y, float z) {
    // Enable lighting for the lampader
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT1); // Use a specific light ID for this lampader

    // Configure light properties
    GLfloat lightPosition[] = { x, y + 600, z, 1.0f };  // Position above the lampshade
    GLfloat ambientLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    GLfloat diffuseLight[] = { 1.0f, 1.0f, 0.9f, 1.0f };
    GLfloat specularLight[] = { 1.0f, 1.0f, 0.9f, 1.0f };

    glLightfv(GL_LIGHT1, GL_POSITION, lightPosition);
    glLightfv(GL_LIGHT1, GL_AMBIENT, ambientLight);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuseLight);
    glLightfv(GL_LIGHT1, GL_SPECULAR, specularLight);

    // Material properties for the lampader
    GLfloat materialAmbient[] = { 0.5f, 0.4f, 0.3f, 1.0f }; // Slightly brown
    GLfloat materialDiffuse[] = { 0.5f, 0.4f, 0.3f, 1.0f };
    GLfloat materialSpecular[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    GLfloat materialShininess[] = { 32.0f };

    glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);
    glMaterialfv(GL_FRONT, GL_SHININESS, materialShininess);

    // Draw the lampader parts
    drawCylinder(x, y, z, 100, 10, 32, 125, 75, 0);        // Base
    drawCylinder(x, y + 10, z, 15, 590, 32, 125, 75, 0);   // Column

    // Set material for the lampshade
    GLfloat lampshadeAmbient[] = { 1.0f, 0.8f, 0.6f, 1.0f }; // Soft light color
    GLfloat lampshadeDiffuse[] = { 1.0f, 0.8f, 0.6f, 1.0f };
    GLfloat lampshadeSpecular[] = { 0.1f, 0.1f, 0.1f, 1.0f };

    glMaterialfv(GL_FRONT, GL_AMBIENT, lampshadeAmbient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, lampshadeDiffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, lampshadeSpecular);
    glMaterialfv(GL_FRONT, GL_SHININESS, materialShininess);

    drawFrustum(x, y + 500, z, 150, 100, 100, 32, 255, 200, 100); // Lampshade

    // Disable lighting for this lampader
    glDisable(GL_LIGHT1);
    glDisable(GL_LIGHTING);
}


void FurnitureStore::enableLampLight(float x, float y, float z) {
    // Define the light source for the lamp
    GLenum lampLightID = GL_LIGHT1;  // Use a unique ID, e.g., GL_LIGHT1

    GLfloat lightPosition[] = { x, y, z, 1.0f };  // Light position (x, y, z, w)
    GLfloat ambientLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };  // Ambient light
    GLfloat diffuseLight[] = { 1.0f, 1.0f, 0.8f, 1.0f };  // Diffuse light
    GLfloat specularLight[] = { 1.0f, 1.0f, 0.8f, 1.0f };  // Specular light

    // Enable and configure the light
    glEnable(lampLightID);
    glLightfv(lampLightID, GL_POSITION, lightPosition);
    glLightfv(lampLightID, GL_AMBIENT, ambientLight);
    glLightfv(lampLightID, GL_DIFFUSE, diffuseLight);
    glLightfv(lampLightID, GL_SPECULAR, specularLight);

    // Add rendering-specific code here if needed

    // Disable the light after rendering the lamp
    glDisable(lampLightID);
}

void FurnitureStore::circlerTable(float x, float y, float z, float radius, float height, int slices, int tabletopTexture, int columnTexture) {
    // Bind and apply texture for the tabletop
    glBindTexture(GL_TEXTURE_2D, tabletopTexture);
    glEnable(GL_TEXTURE_2D);

    // Tabletop (top face with texture)
    glBegin(GL_TRIANGLE_FAN);
    glTexCoord2f(0.5f, 0.5f); // Center of the tabletop
    glVertex3f(x, y + height, z);
    for (int i = 0; i <= slices; i++) {
        float angle = 2.0f * M_PI * i / slices;
        float xOffset = cos(angle) * radius;
        float zOffset = sin(angle) * radius;
        glTexCoord2f(0.5f + 0.5f * cos(angle), 0.5f + 0.5f * sin(angle)); // Map texture around the circular edge
        glVertex3f(x + xOffset, y + height, z + zOffset);
    }
    glEnd();

    glDisable(GL_TEXTURE_2D);

    // Table edge (with tabletop texture)
    glBindTexture(GL_TEXTURE_2D, tabletopTexture);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= slices; i++) {
        float angle = 2.0f * M_PI * i / slices;
        float xOffset = cos(angle) * radius;
        float zOffset = sin(angle) * radius;
        glTexCoord2f((float)i / slices, 0.0f); // Bottom edge of tabletop texture
        glVertex3f(x + xOffset, y + height, z + zOffset);     // Top edge
        glTexCoord2f((float)i / slices, 1.0f); // Top edge of tabletop texture
        glVertex3f(x + xOffset, y + height - 10, z + zOffset); // Bottom edge of the tabletop
    }
    glEnd();

    glDisable(GL_TEXTURE_2D);

    // Bind and apply texture for the column (central leg)
    glBindTexture(GL_TEXTURE_2D, columnTexture);
    glEnable(GL_TEXTURE_2D);

    // Central leg as a textured cylinder
    float legRadius = radius * 0.5 * 0.15f;
    float legHeight = height - 10;
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= slices; i++) {
        float angle = 2.0f * M_PI * i / slices;
        float xOffset = cos(angle) * legRadius;
        float zOffset = sin(angle) * legRadius;
        glTexCoord2f((float)i / slices, 0.0f); // Bottom of the leg texture
        glVertex3f(x + xOffset, y, z + zOffset);
        glTexCoord2f((float)i / slices, 1.0f); // Top of the leg texture
        glVertex3f(x + xOffset, y + legHeight, z + zOffset);
    }
    glEnd();

    glDisable(GL_TEXTURE_2D);

    // Circular base (color only, no texture)
    glColor3ub(100, 100, 100); // Dark gray color for the base
    float baseRadius = radius * 0.4f;
    float baseHeight = 10.0f;

    // Bottom face
    glColor3ub(80, 80, 80); // Slightly darker gray for the bottom face
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(x, y, z); // Center of the bottom face
    for (int i = 0; i <= slices; i++) {
        float angle = 2.0f * M_PI * i / slices;
        float xOffset = cos(angle) * baseRadius;
        float zOffset = sin(angle) * baseRadius;
        glVertex3f(x + xOffset, y, z + zOffset);
    }
    glEnd();

    // Top face (with tabletop texture)
    glBindTexture(GL_TEXTURE_2D, columnTexture);
    glEnable(GL_TEXTURE_2D);
    glColor3ub(120, 120, 120); // Lighter gray for the top face
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(x, y + baseHeight, z); // Center of the top face
    for (int i = 0; i <= slices; i++) {
        float angle = 2.0f * M_PI * i / slices;
        float xOffset = cos(angle) * baseRadius;
        float zOffset = sin(angle) * baseRadius;
        glTexCoord2f(0.5f + 0.5f * cos(angle), 0.5f + 0.5f * sin(angle)); // Map texture around the circular edge
        glVertex3f(x + xOffset, y + baseHeight, z + zOffset);
    }
    glEnd();

    glDisable(GL_TEXTURE_2D);

    // Side faces
    glBindTexture(GL_TEXTURE_2D, columnTexture);
    glEnable(GL_TEXTURE_2D);
    glColor3ub(120, 120, 120); // Dark gray for the sides
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= slices; i++) {
        float angle = 2.0f * M_PI * i / slices;
        float xOffset = cos(angle) * baseRadius;
        float zOffset = sin(angle) * baseRadius;
        glVertex3f(x + xOffset, y, z + zOffset);           // Bottom edge
        glVertex3f(x + xOffset, y + baseHeight, z + zOffset); // Top edge
    }
    glDisable(GL_TEXTURE_2D);
    glEnd();
}