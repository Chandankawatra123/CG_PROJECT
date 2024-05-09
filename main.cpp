#include <GLUT/glut.h>
#include <stdlib.h>
#include <stdio.h>

// Function to execute os.c
void execute_os() {
    system("gcc os.c -o os && ./os");
}

// Function to execute dsa.c
void execute_dsa() {
    system("gcc dsa.c -o dsa && ./dsa");
}

void drawText(float x, float y, char *string) {
    glRasterPos2f(x, y);
    for (int i = 0; string[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
    }
}

void drawButton(float x, float y, float width, float height, char *label) {
    glColor3f(0.7, 0.7, 0.7);
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();
    
    glColor3f(0, 0, 0);
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();
    
    drawText(x + width / 2 - 30, y + height / 2 - 5, label);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawButton(100, 300, 200, 50, "Operating System");
    drawButton(100, 200, 200, 50, "DSA");
    glFlush();
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if (x >= 100 && x <= 300 && y >= 250 && y <= 350) {
            execute_os();
        } else if (x >= 100 && x <= 300 && y >= 150 && y <= 250) {
            execute_dsa();
        }
    }
}

void init() {
    glClearColor(1, 1, 1, 1);
    gluOrtho2D(0, 400, 0, 400);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Menu");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    init();
    glutMainLoop();
    return 0;
}
