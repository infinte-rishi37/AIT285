#include<GL/glut.h>
#include<math.h>
#include<GL/glu.h>
#include<bits/stdc++.h>
using namespace std;

int W = 700, H = 700;

void init()
{
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, W, 0, H);
}

GLint X[100], Y[100], i = 0;
GLint xc, yc;

void drawline(int i)
{
    glColor3f(0, 1, 0);
    glLineWidth(2.0);
    glBegin(GL_LINE_STRIP);
    glVertex2f(X[i-1], Y[i-1]);
    glVertex2f(X[i], Y[i]);
    glEnd();
    glFlush();
}

struct clr
{
    float r, g, b;
    clr(float _r,float _g,float _b)
    {
        r = _r;
        g = _g;
        b = _b;
    }
    bool comp(clr c)
    {
        return c.r == r && c.b == b && c.g == g;
    }
};

void setpixel(int x, int y, clr c)
{
    glColor3f(c.r, c.g, c.b);
    glPointSize(1.5);
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
    glFlush();
}

clr bg = clr(0, 0, 0);
clr side = clr(0, 1, 0);
clr fll = clr(1, 0, 1);

void mouse(int button, int status, int ax, int ay)
{
    if(status == GLUT_DOWN)
    {
        if(button == GLUT_LEFT_BUTTON)
        {
            X[i] = ax;
            Y[i] = H - ay;
            if(i) drawline(i);
            i++;
        }
        else if(button == GLUT_RIGHT_BUTTON)
        {
            xc = ax;
            yc = H - ay;
        }
    }
}

void display(){}

void floodfill(int x, int y)
{
    clr curr = clr(1, 1, 0);
    glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &curr);

    if( curr.comp(bg)  )
    {
        setpixel(x, y, fll);
        floodfill(x+2, y);
        floodfill(x, y+2);
        floodfill(x-2, y);
        floodfill(x, y-2);
    }
}

void boundfill(int x, int y)
{
    clr curr = clr(1, 1, 0);
    glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &curr);

    if( !curr.comp(fll) && !curr.comp(side)  )
    {
        setpixel(x, y, fll);
        boundfill(x-2, y);
        boundfill(x, y+2);
        boundfill(x+2, y);
        boundfill(x, y-2);
    }
}

void menu(int c)
{
    if( c==1 )
    {
        floodfill(xc, yc);
    }
    else if( c==2 )
    {
        boundfill(xc, yc);
    }
    else
    {
        exit(0);
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(W, H);
    glutCreateWindow("Polygon Fill");
    init();
    glutMouseFunc(mouse);
    glutDisplayFunc(display);
    glutCreateMenu(menu);
    glutAddMenuEntry("1. Polygon Fill", 1);
    glutAddMenuEntry("2. Boundary Fill", 2);
    glutAddMenuEntry("0. Exit", 0);
    glutAttachMenu(GLUT_MIDDLE_BUTTON);
    glutMainLoop();
    return 0;
}
