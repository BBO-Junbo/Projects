#include <GL/freeglut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);  // 红色
    glVertex2f(0.0, 1.0);
    
    glColor3f(0.0, 1.0, 0.0);  // 绿色
    glVertex2f(-1.0, -1.0);
    
    glColor3f(0.0, 0.0, 1.0);  // 蓝色
    glVertex2f(1.0, -1.0);
    glEnd();
    
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("FreeGLUT Example");
    
    glClearColor(0.0, 0.0, 0.0, 1.0);  // 设置背景色为黑色
    
    glutDisplayFunc(display);
    glutMainLoop();
    
    return 0;
}