#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#endif
#include <iostream>

using namespace std;

void drawBitmapString(void *font, const char *str)
{
    for (const char *c = str; *c != '\0'; c++)
        glutBitmapCharacter(font, *c);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.2f, 0.6f, 1);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.5f, -0.4f);
    glVertex2f(0.5f, -0.4f);
    glVertex2f(0, 0.5f);
    glEnd();
    glColor3f(1, 1, 1);
    glRasterPos2f(-0.28f, -0.7f);
    drawBitmapString(GLUT_BITMAP_HELVETICA_18, "Filled Triangle");
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 500);
    glutCreateWindow("RUIZ_Q6");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
