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

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 0.5f, 0);
    glBegin(GL_QUADS);
    glVertex2f(px - 0.12f, py - 0.12f);
    glVertex2f(px - 0.12f, py + 0.12f);
    glVertex2f(px + 0.12f, py + 0.12f);
    glVertex2f(px + 0.12f, py - 0.12f);
    glEnd();
    glFlush();
}

void keyboard(unsigned char key, int, int)
{
    if (key == 'w' || key == 'W')
        py += 0.05f;
    else if (key == 's' || key == 'S')
        py -= 0.05f;
    else if (key == 27)
        exit(0);
    if (py > 0.78f)
        py = 0.78f;
    if (py < -0.78f)
        py = -0.78f;
    glutPostRedisplay();
}

void mouse(int button, int state, int, int)
{
    if (state == GLUT_DOWN)
    {
        px = 0;
        py = 0;
        glutPostRedisplay();
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 500);
    glutCreateWindow("RUIZ_Q14");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}
