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

int elapsed = 0;
bool running = false;

void drawBitmapString(void *font, const char *str)
{
    for (const char *c = str; *c != '\0'; c++)
        glutBitmapCharacter(font, *c);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    char b[64];
    snprintf(b, sizeof(b), "Stopwatch: %d seconds", elapsed);
    glColor3f(1, 1, 1);
    glRasterPos2f(-0.4f, 0);
    drawBitmapString(GLUT_BITMAP_HELVETICA_18, b);
    glFlush();
}

void mouse(int button, int state, int, int)
{
    if (state == GLUT_DOWN)
    {
        if (button == GLUT_LEFT_BUTTON)
            running = true;
        else if (button == GLUT_RIGHT_BUTTON)
            running = false;
        glutPostRedisplay();
    }
}

void tick(int)
{
    if (running)
    {
        elapsed++;
        glutPostRedisplay();
    }
    glutTimerFunc(1000, tick, 0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(650, 300);
    glutCreateWindow("RUIZ_Q17");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutTimerFunc(1000, tick, 0);
    glutMainLoop();
    return 0;
}
