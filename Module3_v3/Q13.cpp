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

int counter = 0;

void drawBitmapString(void *font, const char *str)
{
    for (const char *c = str; *c != '\0'; c++)
        glutBitmapCharacter(font, *c);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    char b[64];
    snprintf(b, sizeof(b), "Counter: %d", counter);
    glColor3f(1, 1, 1);
    glRasterPos2f(-0.3f, 0);
    drawBitmapString(GLUT_BITMAP_HELVETICA_18, b);
    glFlush();
}

void tick(int value)
{
    counter++;
    glutPostRedisplay();
    glutTimerFunc(1000, tick, value);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 300);
    glutCreateWindow("RUIZ_Q13");
    glutDisplayFunc(display);
    glutTimerFunc(1000, tick, 0);
    glutMainLoop();
    return 0;
}
