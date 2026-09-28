#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#endif
#include <iostream>
using namespace std;

void drawBitmapString(void *font, const char *str) {
  for (const char *c = str; *c != '\0'; c++)
    glutBitmapCharacter(font, *c);
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1, 1, 1);
  glRasterPos2f(-0.25f, 0);
  drawBitmapString(GLUT_BITMAP_HELVETICA_18, "JOSHUA DANREI C. RUIZ");
  glFlush();
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitWindowSize(600, 300);
  glutCreateWindow("RUIZ_Q1");
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}
