#include<stdio.h>
#include<GL/glut.h>
#include <GL/gl.h>
#include <stdlib.h>
#include<math.h>
#include "Image.h"
#define SPEED 30.0
int scene=0;
float i=0.0,m=0.0,n=0.0,o=0.0,c=0,d=0,x=1,y=1,j,z=0; 
float main_zoom = 1.0;
int zoom_in = 1;
float zoom_speed = 0.003;
float zoom_back_speed = 0.003;
//double rotatex=0.5;
//double rotatey=0.5;

int xx = 0;
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
void DrawCircle(float cx, float cy, float cz, float r, int num_segments)
{
			i = (float)ii/(float)num_segments;
			theta = 2.0f*3.1415926f*i;
			x = r * cosf(theta);
			y = r * sinf(theta);
			glVertex3f(x + cx, y + cy, cz);
			
			glEnd();
	
}
void draw_object()
{	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(0,0);
	glVertex2f(0,700);
	glVertex2f(1100,700);
	glVertex2f(1100,0);
	glEnd();
	glPushMatrix();
	star();
	if(scene==2 || scene == 3 || scene ==4)
		drawImage(480,290,150,150,bgTexture5);	
	if(scene == 3)
	{	glColor3f(1,1,1);
        	drawstring(350,100,0,"These debris coalesces as it rotated arount the earth's orbit.");
		Debris();
	}
	if(scene == 4)
	{	glColor3f(1,1,1);
        	drawstring(250,100,0,"The debris after millions of years formed another selestial body now known as The Moon.");
		Moon();
	}
	if(scene == 1 || scene ==2)
	{	if(scene ==1){
		glColor3f(1,1,1);
        	drawstring(190,100,0,"Around a 45 billion years ago, an astronomical body nearly of the size of Mars, Theia was moving 			towards earth.");}
        	else{glColor3f(1,1,1);
        	drawstring(190,100,0,"Intense heat was created by the impact and huge amounts of debris from both earth and theia were 			thrown into the space.");}
		Comet();
	}
	
	
	glEnd();
	glPopMatrix();
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
void keyboardDown(unsigned char key, int x, int y) 
{
 
	  switch(key) 
	  {
		  case 13: //enter key
		    scene += 1;
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

/* executed when button 'button' is put into state 'state' at screen position ('x', 'y') */
void mouseClick(int button, int state, int x, int y) {
 /*if(button==3)
          rotatex -=0.5;
 else
 	rotatex +=0.5;
 glutPostRedisplay();*/
}
 
/* executed when the mouse moves to position ('x', 'y') */
void mouseMotion(int x, int y) {
 
}

void initRendering()
{
    glEnable(GL_DEPTH_TEST);
}

void scene1()
{
      //glScalef(main_zoom, main_zoom, 1);
	
      draw_object();
      glPopMatrix();
      glEnd();
	
      
}
void scene2()
{
	draw_object();
	glPopMatrix();
	glEnd();
	
}
void scene3()
{
	draw_object();
	glPopMatrix();
	glEnd();
	
}
void scene4()
{
	draw_object();
	glPopMatrix();
	glEnd();
}

/* reshaped window 
void reshape(int width, int height) {
 
  GLfloat fieldOfView = 90.0f;
  glViewport (0, 0, (GLsizei) width, (GLsizei) height);
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity();
  //gluPerspective(60,(GLfloat) width/(GLfloat) height,1.0,100.0);
  glOrtho(-662, 662, -350, 350, -450, 450);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}*/

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
	    case 2:
	      scene2();
	      break;
	    case 3:
		scene3();
		break;
	    case 4:
		scene4();
		break;
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
	loadTexture(&bgTexture5, "8cxBboKcp.png");
}


int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1100.0,700.0);
	glutInitWindowPosition(100,0);
	glutCreateWindow("Moon creation");
	//glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboardDown);
	glutKeyboardUpFunc(keyboardUp);
	glutSpecialFunc(keyboardSpecialDown);
	glutSpecialUpFunc(keyboardSpecialUp);
	glutMouseFunc(mouseClick);
  	glutMotionFunc(mouseMotion);
  	//glutDisplayFunc(display);
	glutDisplayFunc(draw);
	glutIdleFunc(idle);
	myinit();
	
	
	// create a sub menu 
  int subMenu = glutCreateMenu(menu);
  glutAddMenuEntry("Do nothing", 0);
  glutAddMenuEntry("Really Quit", 'q');
 
  // create main "right click" menu
  glutCreateMenu(menu);
  glutAddSubMenu("Sub Menu", subMenu);
  glutAddMenuEntry("Quit", 'q');
  glutAttachMenu(GLUT_RIGHT_BUTTON);
 
  //initGL(1244, 700);
 
	glutMainLoop();
	return 0;
}

			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
