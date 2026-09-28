#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#endif
#include <iostream>

using namespace std;

float labelX = -0.8f;
float speed = 0.0002f;

void drawBitmapString(void* font, const char* str) {
    for (const char* c = str; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 1.0f, 1.0f);

    glRasterPos2f(labelX, 0.0f);

    drawBitmapString(
        GLUT_BITMAP_HELVETICA_18,
        "RUIZ"
    );

    glFlush();
}

void idle() {

    labelX += speed;

    if (labelX >= 0.8f) {
        labelX = 0.8f;
        speed = -speed;
    }

    if (labelX <= -0.8f) {
        labelX = -0.8f;
        speed = -speed;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(700, 400);
    glutCreateWindow("RUIZ_Q12");

    glutDisplayFunc(display);
    glutIdleFunc(idle);

    glutMainLoop();

    return 0;
}