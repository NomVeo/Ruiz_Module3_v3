#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#endif
#include <iostream>

using namespace std;

void drawBitmapString(void *font, const char *str)
{
    for (const char *c = str; *c != '\0'; c++)
        glutBitmapCharacter(font, *c);
}

void display()
{
    glClearColor(0.95f, 0.95f, 0.95f, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0, 0);
    glRasterPos2f(-0.45f, 0);
    drawBitmapString(GLUT_BITMAP_HELVETICA_18, "My Custom Window");
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(800, 500);
    glutInitWindowPosition(150, 150);
    glutCreateWindow("RUIZ_Q3");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
