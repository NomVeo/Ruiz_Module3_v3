#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#endif
#include <iostream>

using namespace std;
float px = 0;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.2f, 0.7f, 1);
    glBegin(GL_QUADS);
    glVertex2f(px - 0.12f, -0.12f);
    glVertex2f(px - 0.12f, 0.12f);
    glVertex2f(px + 0.12f, 0.12f);
    glVertex2f(px + 0.12f, -0.12f);
    glEnd();
    glFlush();
}

void keyboard(unsigned char key, int, int)
{
    if (key == 'a' || key == 'A')
        px -= 0.05f;
    else if (key == 'd' || key == 'D')
        px += 0.05f;
    else if (key == 27)
        exit(0);
    if (px > 0.78f)
        px = 0.78f;
    if (px < -0.78f)
        px = -0.78f;
    glutPostRedisplay();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 500);
    glutCreateWindow("RUIZ_Q8");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
