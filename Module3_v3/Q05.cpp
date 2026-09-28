#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#endif
#include <iostream>

using namespace std;

int message = 0;

void drawBitmapString(void *font, const char *str)
{
    for (const char *c = str; *c != '\0'; c++)
        glutBitmapCharacter(font, *c);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    if (message == 1)
    {
        glColor3f(0, 1, 0);
        glRasterPos2f(-0.35f, 0);
        drawBitmapString(GLUT_BITMAP_HELVETICA_18, "Left button text");
    }
    else if (message == 2)
    {
        glColor3f(1, 0, 0);
        glRasterPos2f(-0.4f, 0);
        drawBitmapString(GLUT_BITMAP_HELVETICA_18, "Right button text");
    }
    glFlush();
}

void mouse(int button, int state, int, int)
{
    if (state == GLUT_DOWN)
    {
        if (button == GLUT_LEFT_BUTTON)
            message = 1;
        else if (button == GLUT_RIGHT_BUTTON)
            message = 2;
        glutPostRedisplay();
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 300);
    glutCreateWindow("RUIZ_Q5");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}
