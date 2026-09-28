#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#endif
#include <iostream>

using namespace std;

float bg = 0.2f;

void display()
{
    glClearColor(bg, bg, bg, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

void entry(int state)
{
    if (state == GLUT_ENTERED)
        bg = 0.8f;
    else if (state == GLUT_LEFT)
        bg = 0.15f;
    glutPostRedisplay();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 400);
    glutCreateWindow("RUIZ_Q11");
    glutDisplayFunc(display);
    glutEntryFunc(entry);
    glutMainLoop();
    return 0;
}
