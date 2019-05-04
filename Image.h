
#include "SOIL.h"
int cur_win;
void drawImage(int x, int y, int w, int h, GLuint texture);
void loadTexture(GLuint* texture, char* path);
int xView = 100;
int yView = 100;
GLuint bgTexture,bgTexture1,bgTexture2,bgTexture3,bgTexture4,bgTexture5;

void loadTexture(GLuint* texture, char* path){
    *texture = SOIL_load_OGL_texture(path,
                                     SOIL_LOAD_AUTO,
                                     SOIL_CREATE_NEW_ID,
                                     SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_MULTIPLY_ALPHA
                                    );
    if(texture == NULL){
        printf("[Texture loader] \"%s\" failed to load!\n", path);
    }
}

void drawImage(int x, int y, int w, int h, GLuint texture){
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);

    glColor3f(1,1,1);
    glBegin(GL_QUADS);

    glTexCoord2f(0,1);
    glVertex2f(x,y);

    glTexCoord2f(1,1);
    glVertex2f(x+w,y);

    glTexCoord2f(1,0);
    glVertex2f(x+w,y+h);

    glTexCoord2f(0,0);
    glVertex2f(x,y+h);

    glEnd();

    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_TEXTURE_2D);

}
