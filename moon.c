#include<stdio.h>
#include<GL/glut.h>
#include <GL/gl.h>
#include <stdlib.h>
#include<math.h>
#define SPEED 30.0
int scene=0;
float i=0.0,m=0.0,n=0.0,o=0.0,c=0.0;    

int comet=0;      
char ch;
int moon = 0;

void declare(char *string)
{
     while(*string)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *string++);
}

void DrawCircle(float cx, float cy, float cz, float r, int num_segments)
{

	int ii;
	float theta, x, y, i;
	glBegin(GL_POLYGON); 
	for(ii = 0; ii < num_segments; ii++)
	{
		if(moon){
		glColor3f(0+i,0+i,0+i);
	
		i = (float)ii/(float)num_segments;
		theta = 2.0f*3.1415926f*i;
		x = r * cosf(theta);
		y = r * sinf(theta);
		glVertex3f(x + cx, y + cy, cz);}
		else{
			glColor3f(1,1,1);
	
		i = (float)ii/(float)num_segments;
		theta = 2.0f*3.1415926f*i;
		x = r * cosf(theta);
		y = r * sinf(theta);
		glVertex3f(x + cx, y + cy, cz);}

           
	}
	glEnd();
}
void draw_object()
{
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(0,0);
	glVertex2f(0,700);
	glVertex2f(1100,700);
	glVertex2f(1100,0);
	glEnd();
	glPushMatrix();
    	
        glColor3f( 1.0, 1.0, 1.0 );
        glPointSize( 3 );
        glBegin( GL_POINTS );
        for( int i = 1; i < 100; i++ )
        {
            int x = rand() % 1100;
            int y = rand() % 700;
            glVertex2i( x, y );
        }
	int l;
	for(l=0;l<=35;l++)
	{
		glColor3f(1.0,1.0,1.0);
		moon = 1;
		DrawCircle(550,350,0,60,500);
		//DrawCircle(500,100,0,60,50);
	}
	//comet	
		for(l=0;l<=7;l++)
		{
			glColor3f(1.0,1.0,1.0);
			moon = 0;
			DrawCircle(300,675,0,10,360);
		}

	glColor3f(1.0,1.0,1.0);
		glBegin(GL_TRIANGLES);
		glVertex2f(200+c,675);
		glVertex2f(300+c,682);
		glVertex2f(300+c,668);
		glEnd();



        glEnd();
       	glPopMatrix();
   	glFlush();
}


void display()
{
glClear(GL_COLOR_BUFFER_BIT);
draw_object();
glFlush();
}


void myinit()
{
glClearColor(0,0,0,0);
glColor3f(0.0,0.0,1.0);
glPointSize(2.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,1100.0,0.0,700.0);
}


int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1100.0,700.0);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Moon creation");
	glutDisplayFunc(display);
       	myinit();
	glutMainLoop();
	return 0;
}

