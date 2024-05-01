#include <GL/glut.h>
#include <math.h>
float k=0.0;
void draw(float k,float p){
    k += p;
    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(sin(k)/2,cos(k)/2);
    glVertex2f(sin(k+0.3)/2,cos(k+0.3)/2);
    glEnd();
}
void display(void) {
    glClearColor(0.9, 0.9, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.5,0.25,0);
    glRectf(-0.02, -1, 0.02, 0 );
    glColor3f(0,0,1);
    for(int i=0;i<6;i++) draw(k, (i*60)*(22/7.0)*(1/180.0) );
    glColor3f(0.5,0.5,0.5);
    glutSolidSphere(0.06, 40, 2);
    glEnd();
    glFlush();
}
void idle(){
    k+=0.0004;
    glutPostRedisplay();
}
int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutCreateWindow("WindMill");
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutMainLoop();
    return 0;
}
