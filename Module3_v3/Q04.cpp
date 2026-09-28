#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#endif
#include <iostream>

using namespace std;

float bg[3] = {0, 0, 0};

void display()
{
    glClearColor(bg[0], bg[1], bg[2], 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

void keyboard(unsigned char key, int, int)
{
    if (key == 'r' || key == 'R')
    {
        bg[0] = 1;
        bg[1] = 0;
        bg[2] = 0;
    }
    else if (key == 'g' || key == 'G')
    {
        bg[0] = 0;
        bg[1] = 1;
        bg[2] = 0;
    }
    else if (key == 'b' || key == 'B')
    {
        bg[0] = 0;
        bg[1] = 0;
        bg[2] = 1;
    }
    else if (key == 27)
        exit(0);
    glutPostRedisplay();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 400);
    glutCreateWindow("RUIZ_Q4");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
