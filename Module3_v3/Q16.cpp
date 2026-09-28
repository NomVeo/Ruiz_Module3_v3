#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#endif
#include <iostream>

using namespace std;

float px = 0, py = 0;

bool dragging = false;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.3f, 0.8f, 1);
    glBegin(GL_QUADS);
    glVertex2f(px - 0.12f, py - 0.12f);
    glVertex2f(px - 0.12f, py + 0.12f);
    glVertex2f(px + 0.12f, py + 0.12f);
    glVertex2f(px + 0.12f, py - 0.12f);
    glEnd();
    glFlush();
}

void toGL(int x, int y, float &ox, float &oy)
{
    int w = glutGet(GLUT_WINDOW_WIDTH), h = glutGet(GLUT_WINDOW_HEIGHT);
    ox = 2.0f * x / w - 1.0f;
    oy = 1.0f - 2.0f * y / h;
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON)
    {
        if (state == GLUT_DOWN)
        {
            dragging = true;
            toGL(x, y, px, py);
        }
        else if (state == GLUT_UP)
            dragging = false;
        glutPostRedisplay();
    }
}

void motion(int x, int y)
{
    if (dragging)
    {
        toGL(x, y, px, py);
        glutPostRedisplay();
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 500);
    glutCreateWindow("RUIZ_Q16");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutMainLoop();
    return 0;
}
