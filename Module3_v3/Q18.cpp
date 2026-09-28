#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#endif
#include <iostream>
#include <cmath>

using namespace std;

bool inside = false;

float angle = 0.0f;

void display() {

    glClear(GL_COLOR_BUFFER_BIT);

    float x = 0.5f * cosf(angle);
    float y = 0.5f * sinf(angle);

    glColor3f(1.0f, 0.4f, 0.2f);

    glBegin(GL_QUADS);

        glVertex2f(x - 0.1f, y - 0.1f);
        glVertex2f(x + 0.1f, y - 0.1f);
        glVertex2f(x + 0.1f, y + 0.1f);
        glVertex2f(x - 0.1f, y + 0.1f);

    glEnd();

    glFlush();
}

void entry(int state) {

    if (state == GLUT_ENTERED) {
        inside = true;
    }

    if (state == GLUT_LEFT) {
        inside = false;
    }
}

void idle() {

    if (inside) {

        angle +=  0.0005f;

        if (angle > 6.28318f) {
            angle -= 6.28318f;
        }

        glutPostRedisplay();
    }
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutCreateWindow("RUIZ_Q18");

    glutDisplayFunc(display);
    glutEntryFunc(entry);
    glutIdleFunc(idle);

    glutMainLoop();

    return 0;
}