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
int xx = 0;
int comet=0;      
char ch;
int moon = 0;
int firework_position = 0;
int firework_size = 0;

GLubyte patt[] = {
  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,
  0x22, 0x22, 0x22, 0x22,
  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,
  0x22, 0x22, 0x22, 0x22,
  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,
  0x22, 0x22, 0x22, 0x22,
  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,
  0x22, 0x22, 0x22, 0x22,
  0x00, 0x00, 0x00, 0x00

};
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

	int ii;
	float theta, x, y, i;
	glBegin(GL_POLYGON); 
	for(ii = 0; ii < num_segments; ii++)
	{
		if(moon==1){
			glColor3f(0+i,0+i,0+i);
		
			i = (float)ii/(float)num_segments;
			theta = 2.0f*3.1415926f*i;
			x = r * cosf(theta);
			y = r * sinf(theta);
			glVertex3f(x + cx, y + cy, cz);
		}
		else if(moon==0)
		{
			glColor3f(1,1,1);
			i = (float)ii/(float)num_segments;
			theta = 2.0f*3.1415926f*i;
			x = r * cosf(theta);
			y = r * sinf(theta);
			glVertex3f(x + cx, y + cy, cz);
		}
		else
		{		
			i = (float)ii/(float)num_segments;
			theta = 2.0f*3.1415926f*i;
			x = r * cosf(theta);
			y = r * sinf(theta);
			glVertex3f(x + cx, y + cy, cz);
		}
			           
	}
	glEnd();
}

void Moon()
{
	
	for(int l=0;l<=35;l++)
	{
		moon = 1;
		DrawCircle(300,450,0,30,500);
		
	}
}

void star()
{
	glColor3f( 1.0, 1.0, 1.0 );
        glPointSize( 3 );
        glBegin( GL_POINTS );
        for( int i = 1; i < 5; i++ )
        {
            int x = rand() % 1100;
            int y = rand() % 700;
            glVertex2i( x, y );
        }
	glEnd();
}

void Explosion()
{		
		if(d==300)
		{   moon=4;
	            glColor3f(1,0.5,0);
		    DrawCircle(500, 325, 0,25,360);
		    glColor3f(1,1,0);
		    DrawCircle(500, 325, 0,20,360);
		    glColor3f(1,1,1);
		    DrawCircle(500, 325, 0,10,360);
		 }   
		    
}

void Comet()
{	if(scene==2)
	{		
		glColor3f(1.0,1.0,1.0);
		moon = 0;
		Explosion();
		DrawCircle(200+d,325,0,10,360);
					
		glColor3f(1.0,1.0,1.0);
		glBegin(GL_TRIANGLES);
		glVertex2f(100+d,325);
		glVertex2f(200+d,335);
		glVertex2f(200+d,315);
			
		Explosion();
		if(xx < 309)		
		{	
			if(d < 300)
				d++;
		}
		
		glEnd();
	}
	else
	{	
		glColor3f(1.0,1.0,1.0);
		moon = 0;
		DrawCircle(200+c,325,0,10,360);
		glColor3f(1.0,1.0,1.0);
		glBegin(GL_TRIANGLES);
		glVertex2f(100+c,325);
		glVertex2f(200+c,335);
		glVertex2f(200+c,315);		
			c+=2;
		glEnd();
	}
}

void Debris()
{	glPushMatrix();
	glLoadIdentity();
	glColor3f(1.0,1.0,1.0);
	moon = 0;
        if(x<=30 && y<=25){
        	x+=0.2;
		y+=0.2;}
	DrawCircle(690-x,350+y,0,10.5,500);
	DrawCircle(600+0.5*x,347,0,5,500);
	DrawCircle(580+0.5*x,340-0.05*y,0,8,500);
	DrawCircle(630+0.3*x,330+0.05*y,0,8.3,500);
	DrawCircle(650-0.45*x,360+0.25*y,0,3.7,500);
	DrawCircle(520+0.9*x,335-0.5*y,0,5,500);
	DrawCircle(425+x,375-0.6*y,0,8.5,500);
	DrawCircle(450+x,400+0.2*y,0,4,500);
	DrawCircle(500+x,330+0.25*x,0,8,500);
	DrawCircle(650-x,390+0.5*y,0,6,500);
	DrawCircle(450+1.3*x,348-0.2*y,0,6.8,500);
	glPopMatrix();
	glEnd();
}

void drawstring(float x,float y,float z,char *string)
{
        char *c;
        glRasterPos3f(x,y,z);
        for(c=string;*c!='\0';c++)
 	        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*c);
}
void drawFireworks()
{
  if (firework_size < 200) //animates the firework
  {
    firework_size++;
    glEnable(GL_POLYGON_STIPPLE);
    glPolygonStipple(patt);
    x=150;
    glColor3f(1.0, 1.0, 0.0);
    DrawCircle(450+x, 350, 0, firework_size, 100);
    glColor3f(1.0, 0.5, 1.0);
    DrawCircle(300+x, 350, 0, firework_size, 100);
    glColor3f(1.0, 1.0, 1.0);
    DrawCircle(600+x, 350, 0, firework_size, 100);
    glColor3f(1.0, 0.0, 1.0);
    DrawCircle(180+x, 350, 0, firework_size, 100);
    glDisable(GL_POLYGON_STIPPLE);
    if(firework_size ==200) //stops the fireworks
    	scene=6;
  }
  
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
	if(scene !=5)
		star();
    	//assigning coordinates for the earth
	if(scene==2 || scene == 3 || scene ==4)
	{	drawstring(890,650,0,"Press enter to continue -->");
		drawImage(480,290,150,150,bgTexture5);
	}
	if(scene == 3)
	{	glColor3f(1,1,1);
        	drawstring(350,100,0,"These debris combined together as it rotated arount the earth's orbit.");
		Debris();
	}
	if(scene == 4)
	{	glColor3f(1,1,1);
        	drawstring(250,100,0,"The debris after millions of years formed another selestial body now known as The MOON.");
		Moon();
	}
	if(scene == 1 || scene ==2)
	{	if(scene ==1){
		glColor3f(1,1,1);
		drawstring(890,650,0,"Press enter to continue -->");
	  	drawstring(190,100,0,"Around 45 billion years ago, an astronomical body nearly of the size of Mars, Theia, was moving 	towards the earth.");}
        	else{
		glColor3f(1,1,1);
        	drawstring(190,100,0,"Intense heat was created by the impact and huge amounts of debris from both earth and theia were thrown into the space.");}
		Comet();
	}
	if(scene ==5)
	{
		drawFireworks();
		glColor3f(0.5,0.8,0.4);
		drawstring(500,350,0,"THANK YOU");
		glEnd();
		
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


void drawMainScene()
{
	glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_QUADS);
        glColor3ub(91,36,122);
                glVertex2f(0,0);
                glVertex2f(1100,0);
        glColor3ub(27,206,223);
                glVertex2f(1100,700);
                glVertex2f(0,700);
        glEnd();
  
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

void scene5()
{ 
	draw_object();
	glPopMatrix();
	glEnd();
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
	    case 2:
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
	    default : exit(0);
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
 
	glutMainLoop();
	return 0;
}

