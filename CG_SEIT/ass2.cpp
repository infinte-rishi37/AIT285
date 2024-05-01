#include <GL/glut.h>
#include <GL/glu.h>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;
int W = 600, H = 600;
GLint A, B, C, D;
void setpixel(GLint x, GLint y){
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
    glFlush();
}
void dda(){
    GLfloat dx, dy, step, x, y;
    GLfloat ix, iy;

    dx = C-A;
    dy = D-B;

    step = max(abs(dx), abs(dy));

    ix = dx/step;
    iy = dy/step;

    x = A;
    y = B;

    glPointSize(1.0);
    glColor3f(0.0, 0.0, 1.0);

    for(int i=0; i<=step; i++){
        x += ix;
        y += iy;
        setpixel(x + 0.5, y + 0.5);
    }
}
void bre() {
    glPointSize(1.0);
    glColor3f(0.0, 0.0, 1.0);

    GLint dx = abs(A - C), dy = abs(B - D);

    if(dx > dy){
        if(A > C) {
            swap(B, D);
            swap(A, C);
        }
        GLint p = 2 * dy - dx;
        GLint sm = 2 * dy;
        GLint bg = 2 * (dy - dx);
        while ( A <= C ){
            setpixel(A, B);
            p += p<0 ? sm : bg;
            A ++;
            B += p<0 ? 0 : ((D > B) ? 1 : -1);
        }
    }
    else{
        if(B > D) {
            swap(B, D);
            swap(A, C);
        }
        GLint p = 2 * dx - dy;
        GLint sm = 2 * dx;
        GLint bg = 2 * (dx - dy);
        while ( B <= D ){
            setpixel(A, B);
            p += p<0 ? sm : bg;
            A += p<0 ? 0 : ((C > A) ? 1 : -1);
            B ++;
        }
    }
}

void mouse(int button, int state, int ax, int ay){
    if(state == GLUT_DOWN){
        glPointSize(3.0);
        glColor3f(1,1,1);
        if(button == GLUT_LEFT_BUTTON){
            A = ax - W/2;
            B = ay - H/2;
            cout << "Point A set to " << A << ' ' << B << '\n';
            setpixel(A, B);
        }
        else if(button == GLUT_RIGHT_BUTTON){
            C = ax - W/2;
            D = ay - H/2;
            cout << "Point B set to " << C << ' ' << D << '\n';
            setpixel(C, D);
        }
    }
}

void keyboard(unsigned char key, int x,int y){
    if(key == 27){
        exit(0);
    }
    else{
        cout << "You Entered " << key << endl;
    }
}

void init() {
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-W/2, W/2, H/2, -H/2);
}

void menu(int c){
    if(c == 1){
        dda();
    }
    else if(c == 2){
        bre();
    }
    else{
        exit(0);
    }
}
void draw()
{
    glPointSize(2.0);
    glColor3f(0.0, 1.0, 0.0);
    for(int i =-W; i<W; i++){
        setpixel(0, i%2 ? i : -i);
        setpixel(i%2 ? -i : i, 0);
    }
    glPointSize(1.0);
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(W, H);
    glutCreateWindow("Draw Line");
    init();
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    glutDisplayFunc(draw);
    glutCreateMenu(menu);
    glutAddMenuEntry("1. DDA Line Drawing", 1);
    glutAddMenuEntry("2. Bresenham's Drawing", 2);
    glutAddMenuEntry("0.Exit", 0);
    glutAttachMenu(GLUT_MIDDLE_BUTTON);
    glutMainLoop();
    return 0;
}
