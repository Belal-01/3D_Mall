#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stb_image.h>
#include <iostream>
#include "texture.h"
using namespace std;
int num_texture = -1;
int LoadTexture( char* filename, int alphaOverride) {
    int i, j = 0;
    FILE* l_file;
    unsigned char* l_texture;

    BITMAPFILEHEADER fileheader;
    BITMAPINFOHEADER infoheader;
    RGBQUAD rgba;

    num_texture++;

    if ((l_file = fopen(filename, "rb")) == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        return -1;
    }
    else printf("File %s opened successfully.\n", filename);

    fread(&fileheader, sizeof(fileheader), 1, l_file);
    fseek(l_file, sizeof(fileheader), SEEK_SET);
    fread(&infoheader, sizeof(infoheader), 1, l_file);

    printf("Width: %d, Height: %d, BitCount: %d\n", infoheader.biWidth, infoheader.biHeight, infoheader.biBitCount);

    if (infoheader.biWidth <= 0 || infoheader.biHeight <= 0 || (infoheader.biBitCount != 24 && infoheader.biBitCount != 32)) {
        printf("Unsupported BMP format. Only 24-bit and 32-bit are supported.\n");
        fclose(l_file);
        return -1;
    }

    // Allocate memory for texture
    l_texture = (byte*)malloc(infoheader.biWidth * infoheader.biHeight * 4);
    if (!l_texture) {
        printf("Error: Memory allocation failed.\n");
        fclose(l_file);
        return -1;
    }
    memset(l_texture, 0, infoheader.biWidth * infoheader.biHeight * 4);

    // Read pixel data
    for (i = 0; i < infoheader.biWidth * infoheader.biHeight; i++) {
        if (infoheader.biBitCount == 24) {
            RGBTRIPLE rgb;
            fread(&rgb, sizeof(rgb), 1, l_file);
            l_texture[j + 0] = rgb.rgbtRed;
            l_texture[j + 1] = rgb.rgbtGreen;
            l_texture[j + 2] = rgb.rgbtBlue;
            l_texture[j + 3] = alphaOverride; // Use the provided alpha value
        }
        else if (infoheader.biBitCount == 32) {
            fread(&rgba, sizeof(rgba), 1, l_file);
            l_texture[j + 0] = rgba.rgbRed;
            l_texture[j + 1] = rgba.rgbGreen;
            l_texture[j + 2] = rgba.rgbBlue;
            l_texture[j + 3] = rgba.rgbReserved; // Use alpha channel from the file
        }
        j += 4;
    }

    fclose(l_file);

    // Bind the texture
    glBindTexture(GL_TEXTURE_2D, num_texture);

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

    glTexImage2D(GL_TEXTURE_2D, 0, 4, infoheader.biWidth, infoheader.biHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, l_texture);

    gluBuild2DMipmaps(GL_TEXTURE_2D, 4, infoheader.biWidth, infoheader.biHeight, GL_RGBA, GL_UNSIGNED_BYTE, l_texture);

    free(l_texture);

    return num_texture;
}