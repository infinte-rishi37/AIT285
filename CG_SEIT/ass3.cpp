#include<bits/stdc++.h>
#include<GL/glut.h>
#include<math.h>
using namespace std;

int W = 500, H = 500;
int xc, yc, r;
void init()
{
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(0, W, 0, H);
}

void display(){}

void setcenter()
{
    glColor3f(1, 1, 1);
    glPointSize(3.0);
    glBegin(GL_POINTS);
    glVertex2f(xc, yc);
    glEnd();
    glFlush();
}

void setpoint(int x, int y)
{
    glColor3f(0, 1, 0);
    glPointSize(1.0);
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
    glFlush();
}

void setcircle(int x, int y)
{
    setpoint(xc - x,yc + y);
    setpoint(xc - x,yc - y);
    setpoint(xc + x,yc - y);
    setpoint(xc + x,yc + y);
    setpoint(xc - y,yc + x);
    setpoint(xc - y,yc - x);
    setpoint(xc + y,yc - x);
    setpoint(xc + y,yc + x);
}

void drawCircle()
{
    GLint s = 3 - 2*r;
    GLint x = 0, y = r;
    while(x <= y)
    {
        setcircle(x, y);
        x++;
        if(s > 0)
        {
            y--;
            s = s + 4*(x - y) + 10;
        }
        else
            s = s + 4*x + 6;
    }
}

void mouse(int button , int status, int ax, int ay)
{
    if(status == GLUT_DOWN)
    {
        if(button == GLUT_LEFT_BUTTON)
        {
            xc = ax;
            yc = H - ay;
            setcenter();
        }
    }
}

void keyboard(unsigned char key, int x, int y)
{
    if(key == 27) exit(0);
}

void menu(int c)
{
    if (c == 1)
    {
        cout << "Enter Radius of Circle : ";
        cin >> r;
        drawCircle();
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(W, H);
    glutCreateWindow("Circle Drawing");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    glutCreateMenu(menu);
    glutAddMenuEntry("Circle", 1);
    glutAttachMenu(GLUT_MIDDLE_BUTTON);
    glutMainLoop();
    return 0;
}
