#include<stdio.h>
#include<GL/glut.h>
#include <GL/gl.h>
#include <stdlib.h>
#include<math.h>
#include "Image.h"

#define SPEED 30.0
int scene=0;
float i=0.0,m=0.0,n=0.0,o=0.0,c=0.0;    

int comet=0;      
char ch;
int moon = 0;

void menu(int op) {
 
  switch(op) {
  case 'Q':
  case 'q':
    exit(0);
  }
}

void declare(char *string)
{
     while(*string)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *string++);
}
void earth()
{
        glClear(GL_COLOR_BUFFER_BIT);
        //glBegin(GL_QUADS);
        //glColor3ub(227,227,227);
                //glVertex2f(0,0);
                //glVertex2f(1100,0);
        //glColor3ub(255,255,255);
                //glVertex2f(1100,700);
                //glVertex2f(0,700);           
        //glEnd();
	drawImage(440,500,500,500,bgTexture5);	
	glFlush();
	//glColor3f(0,0,0);
	//drawstring(600,1900,0,"Don’t Act MEAN, Go GREEN.”");
	//drawstring(750,1800,0," Celebrate An Eco Friendly Diwali This Year.");

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
        for( int i = 1; i < 5; i++ )
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
		
	earth();


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

void drawText(char text[], int x, int y, int z)
{

  // The color, red for me
  glColor3f(0, 0, 0);
  // Position of the text to be printer
  glRasterPos3f(x, y, z);
  for(int i = 0; text[i] != '\0'; i++)
      glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
}


void drawMainScene()
{
  glClearColor(1.0,1.0, 1.0, 1.0);
  char h1[] = "COMPUTER GRAPHICS PROJECT"; 
  char h2[] = "CREATION OF MOON";
  char h3[] = "by";
  char name1[] = "MONISHA TARKAR";
  char usn1[] = "4SF15CS095";
  char name2[] = "DEVIKA PJ";
  char usn2[] = "4SF15CS042";
  char message[] = "Press Enter to start";

  drawText(h1, 450, 600, 0);
  drawText(h2, 490, 500, 0);
  drawText(h3, 560, 400, 0);
  drawText(name1, 200, 300, 0);
  drawText(usn1, 200, 280, 0);
  drawText(name2, 800, 300, 0);
  drawText(usn2, 800, 280, 0);
  drawText(message, 510, 100, 0);
}

void keyboardDown(unsigned char key, int x, int y) 
{
 
	  switch(key) 
	  {
		  case 13: //enter key
		    scene = 1;
		    break;
		  case 'Q':
		  case 'q':
		  case  27:   // ESC
		    exit(0);
	  }
}
 
/* executed when a regular key is released */
void keyboardUp(unsigned char key, int x, int y) {
 
}
 
/* executed when a special key is pressed */
void keyboardSpecialDown(int k, int x, int y) {
 
}
 
/* executed when a special key is released */
void keyboardSpecialUp(int k, int x, int y) {
 
}

void scene1()
{
      
      display();
      glPopMatrix();
      
}

void draw() 
{
 
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
 
  /* render the scene here */

	  switch(scene)
	  {
	    case 0:
	      drawMainScene();
	      break;
	    case 1:
	      scene1();
	      break;
	    /*case 2:
	      scene2();
	      break;
	    case 3:
		scene3();
		break;
	    case 4:
		scene4();
		break;
	    case 5:
		scene5();
		break;
	    case 6:
		scene6();
		break;*/

	  }
 
          glFlush();
	  glutSwapBuffers();
}

void idle() 
{   
  glutPostRedisplay();
}

void myinit()
{
	glClearColor(0,0,0,0);
	glColor3f(0.0,0.0,1.0);
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,1100.0,0.0,700.0);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
   	//glEnable( GL_BLEND );
    	loadTexture(&bgTexture5, "preview.png");
}


int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1100.0,700.0);
	glutInitWindowPosition(100,0);
	glutCreateWindow("Moon creation");
	glutKeyboardFunc(keyboardDown);
	glutKeyboardUpFunc(keyboardUp);
	glutSpecialFunc(keyboardSpecialDown);
	glutSpecialUpFunc(keyboardSpecialUp);
	glutIdleFunc(idle);
	glutDisplayFunc(draw);
       	myinit();
	glutMainLoop();
	return 0;
}

