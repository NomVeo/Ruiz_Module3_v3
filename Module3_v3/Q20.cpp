#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#endif
#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

float px = 0, py = 0, pulseAngle = 0;
int mouseX = 0, mouseY = 0;

const float PI = 3.14159265f;

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
    float size = 0.08f + 0.025f * sinf(pulseAngle);
    glColor3f(0.2f, 0.7f, 1);
    glBegin(GL_QUADS);
    glVertex2f(px - size, py - size);
    glVertex2f(px - size, py + size);
    glVertex2f(px + size, py + size);
    glVertex2f(px + size, py - size);
    glEnd();
    glColor3f(1, 1, 1);
    glRasterPos2f(px + 0.12f, py);
    drawBitmapString(GLUT_BITMAP_HELVETICA_12, "RUIZ");
    char b[64];
    snprintf(b, sizeof(b), "Mouse: (%d, %d)", mouseX, mouseY);
    glRasterPos2f(-0.3f, -0.85f);
    drawBitmapString(GLUT_BITMAP_HELVETICA_12, b);
    glFlush();
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        toGL(x, y, px, py);
        glutPostRedisplay();
    }
}

void passive(int x, int y)
{
    mouseX = x;
    mouseY = y;
    glutPostRedisplay();
}

void idle()
{
    pulseAngle += 0.0005f;
    if (pulseAngle > 2 * PI)
        pulseAngle -= 2 * PI;
    glutPostRedisplay();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(700, 600);
    glutCreateWindow("RUIZ_Q20");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutPassiveMotionFunc(passive);
    glutIdleFunc(idle);
    glutMainLoop();
    return 0;
}
