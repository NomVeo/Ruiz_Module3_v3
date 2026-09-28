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

float mx = 0, my = 0;

bool hasPoint = false;

void drawBitmapString(void *font, const char *str)
{
    for (const char *c = str; *c != '\0'; c++)
        glutBitmapCharacter(font, *c);
}

void toGL(int x, int y, float &ox, float &oy)
{
    int w = glutGet(GLUT_WINDOW_WIDTH), h = glutGet(GLUT_WINDOW_HEIGHT);
    ox = 2.0f * x / w - 1.0f;
    oy = 1.0f - 2.0f * y / h;
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    if (hasPoint)
    {
        char b[64];
        snprintf(b, sizeof(b), "OpenGL: (%.2f, %.2f)", mx, my);
        glColor3f(1, 1, 1);
        glRasterPos2f(-0.45f, 0);
        drawBitmapString(GLUT_BITMAP_HELVETICA_18, b);
        glPointSize(8);
        glBegin(GL_POINTS);
        glVertex2f(mx, my);
        glEnd();
    }
    glFlush();
}

void motion(int x, int y)
{
    toGL(x, y, mx, my);
    hasPoint = true;
    glutPostRedisplay();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 500);
    glutCreateWindow("RUIZ_Q9");
    glutDisplayFunc(display);
    glutMotionFunc(motion);
    glutMainLoop();
    return 0;
}
