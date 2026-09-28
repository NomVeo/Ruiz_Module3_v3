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

int score = 0;

void drawBitmapString(void *font, const char *str)
{
    for (const char *c = str; *c != '\0'; c++)
        glutBitmapCharacter(font, *c);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    int stage = score / 5;
    float r, g, b;
    if (stage % 3 == 0)
    {
        r = 1;
        g = 0;
        b = 0;
    }
    else if (stage % 3 == 1)
    {
        r = 0;
        g = 1;
        b = 0;
    }
    else
    {
        r = 0;
        g = 0;
        b = 1;
    }
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
    glVertex2f(-0.3f, -0.3f);
    glVertex2f(-0.3f, 0.3f);
    glVertex2f(0.3f, 0.3f);
    glVertex2f(0.3f, -0.3f);
    glEnd();
    char text[64];
    snprintf(text, sizeof(text), "Score: %d", score);
    glColor3f(1, 1, 1);
    glRasterPos2f(-0.2f, 0.6f);
    drawBitmapString(GLUT_BITMAP_HELVETICA_18, text);
    glFlush();
}

void mouse(int button, int state, int, int)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        score++;
        glutPostRedisplay();
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 500);
    glutCreateWindow("RUIZ_Q19");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}
