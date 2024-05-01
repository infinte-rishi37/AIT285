#include <bits/stdc++.h>
#include <GL/glut.h>
using namespace std;

int W = 700, H = 700;

struct point{
    double x, y;
    point(double _x = 0,double _y = 0){x = _x; y = _y;}
};

void setpoint(point p){
    glBegin(GL_POINTS);
    glVertex2f(p.x, p.y);
    glEnd();
    glFlush();
}

void setline(point a, point b){
    glBegin(GL_LINE_STRIP);
    glVertex2f(a.x, a.y);
    glVertex2f(b.x, b.y);
    glEnd();
    glFlush();
}

class BeizerCurve{
public:
    int size;
    vector<point> dots;
    BeizerCurve(){
        size = 0;
        dots.clear();
    }

    point beizerPoint(point p0, point p1, point p2, point p3, double t){
        GLfloat c1 = (1 - t) * (1 - t) * (1 - t);
        GLfloat c2 = (1 - t) * (1 - t) * t * 3;
        GLfloat c3 = (1 - t) * t * t * 3;
        GLfloat c4 = t * t * t;
        point p = point();
        p.x = c1 * p0.x + c2 * p1.x + c3 * p2.x + c4 * p3.x;
        p.y = c1 * p0.y + c2 * p1.y + c3 * p2.y + c4 * p3.y;
        return p;
    }

    void handle(point p){
        if(size<4){
            glColor3f(0.4, 0, 0);
            if(dots.size()) setline(p, dots[size-1]);
            setpoint(p);
            dots.push_back(p);
            size++;
        }
        if(size == 4){
            point p = point(dots[0].x ,dots[0].y);
            glColor3f(1, 1, 0);
            for(GLdouble i = 0; i<=1.0; i+= 0.01){
                point _p = beizerPoint(dots[0], dots[1], dots[2], dots[3], i);
                setline(p, _p);
                p = _p;
            }
            size = 0;
            dots.clear();
        }
    }
};

BeizerCurve BC = BeizerCurve();

void keyboard(unsigned char key, int x, int y){
    if(key == 27) exit(0);
}

void mouse(int button, int status, int ax, int ay){
    if(status == GLUT_DOWN)
        BC.handle(point(ax, H - ay));
}

void init(){
    glClearColor(0, 0, 0, 0);
    glPointSize(4.0);
    gluOrtho2D(0, W, 0, H);
}

void display(){}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(W, H);
    glutCreateWindow("Beizer Curve");
    init();
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
