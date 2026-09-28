#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#endif
#include <cstdio>
#include <iostream>

using namespace std;

int mx = 0, my = 0;

void drawBitmapString(void *font, const char *str)
{
    for (const char *c = str; *c != '\0'; c++)
        glutBitmapCharacter(font, *c);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    char b[64];
    snprintf(b, sizeof(b), "Mouse at (%d, %d)", mx, my);
    glColor3f(1, 1, 1);
    glRasterPos2f(-0.35f, 0);
    drawBitmapString(GLUT_BITMAP_HELVETICA_18, b);
    glFlush();
}

void passive(int x, int y)
{
    mx = x;
    my = y;
    glutPostRedisplay();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 400);
    glutCreateWindow("RUIZ_Q10");
    glutDisplayFunc(display);
    glutPassiveMotionFunc(passive);
    glutMainLoop();
    return 0;
}
