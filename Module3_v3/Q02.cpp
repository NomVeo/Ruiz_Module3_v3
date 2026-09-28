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
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 1, 1);
    glRasterPos2f(-0.35f, 0.55f);
    drawBitmapString(GLUT_BITMAP_HELVETICA_10, "FONT SIZE CHECK");
    glRasterPos2f(-0.35f, 0.15f);
    drawBitmapString(GLUT_BITMAP_HELVETICA_18, "FONT SIZE CHECK");
    glRasterPos2f(-0.35f, -0.35f);
    drawBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, "FONT SIZE CHECK");
    glFlush();
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(700, 500);
    glutCreateWindow("RUIZ_Q2");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
