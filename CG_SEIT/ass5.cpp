#include <bits/stdc++.h>
#include <GL/glut.h>
using namespace std;

GLint W=600 , H=600;
GLint A[100][3], n=0;

void init(){
    glClearColor(1, 1, 1 ,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-W/2, W/2, H/2, -H/2);
}

void drawline(int x, int y){
    glBegin(GL_LINE_STRIP);
    glVertex2f(A[x][0], A[x][1]);
    glVertex2f(A[y][0], A[y][1]);
    glEnd(); glFlush();
}

void setpoint(int x, int y){
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd(); glFlush();
}

void draw(int n){
    for(int i=1;i<n;i++){
        drawline(i-1, i);
    }
}

void Mul3x3(GLdouble T[3][3]){
    for(int i=0;i<n;i++){
        GLdouble t[3]={0};
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                t[j] += T[j][k] * A[i][k];
            }
        A[i][j] = t[j];
        }
    }
}

void translate(int tx, int ty){
    glColor3f(1, 0, 0);
    GLdouble tm[3][3] = {
        {1, 0, tx},
        {0, 1, ty},
        {0, 0,  1}};
    Mul3x3(tm);
}

void rotate(double a){
    glColor3f(1, 1, 0);
    double th = (22 / 7.0)/180.0;
    a *= th;
    GLdouble tm[3][3] = {
        { cos(a) , sin(a) , 0},
        {-sin(a) , cos(a) , 0},
        {0, 0, 1 }};
    Mul3x3(tm);
}

void scale(float s){
    glColor3f(0, 0, 1);
    GLdouble tm[3][3] = {
        {s, 0, 0},
        {0, s, 0},
        {0, 0, s}};
    Mul3x3(tm);
}

void reflect(char c){
    glColor3f(0, 1, 1);
    GLdouble tmx[3][3] = {
        {-1, 0, 0},
        { 0, 1, 0},
        { 0, 0, 1}};
    GLdouble tmy[3][3] = {
        { 1, 0, 0},
        { 0,-1, 0},
        { 0, 0, 1}};
    Mul3x3(c == 'x' ? tmx : tmy);
}

void display(){
    glColor3f(0, 0, 0);
    for(int i=-W; i<=W; i+=3){
        setpoint(0, i%2 ? i : -i);
        setpoint(i%2 ? -i : i, 0);
    }
}

void mouse(int button, int status, int ax, int ay){
    if(status == GLUT_DOWN){
        if(button == GLUT_LEFT_BUTTON){
            A[n][0] = ax - W/2;
            A[n][1] = ay - H/2;
            A[n][2] = 1;
            setpoint(A[n][0], A[n][1]);
            if(n >= 1){
                glColor3f(0, 1, 0);
                drawline(n-1, n);
            }
            n++;
        }
    }
}

void keyboard(unsigned char key, int x, int y){
    if(key==27) exit(0);
}

void Clear() {
    n=0;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 1, 1);
    display();
}

void menu(int c){
    GLfloat x, y, a, s;
    char ch;
     switch(c){
     case 1:
         cout << "Enter the X Translate :";cin >> x;
         cout << "Enter the Y Translate :";cin >> y;
         translate(x, y);
         draw(n);
        break;
     case 2:
         cout << "Enter angle of rotation :"; cin>>a;
         rotate(a);
         draw(n);
        break;
     case 3:
         cout << "Enter the value to scale :"; cin >> s;
         scale(s);
         draw(n);
        break;
    case 4:
         cout << "Enter the axis :"; cin >> ch;
         reflect(ch);
         draw(n);
        break;
     default:
        Clear();
     }
}

int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(W, H);
    glutCreateWindow("2D Transforms");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    glutCreateMenu(menu);
    glutAddMenuEntry("Transform", 1);
    glutAddMenuEntry("Rotate", 2);
    glutAddMenuEntry("Scale", 3);
    glutAddMenuEntry("Reflect", 4);
    glutAddMenuEntry("Clear", 0);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();
}
