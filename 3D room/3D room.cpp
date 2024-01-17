/*****************************************************************************
		FILE : submit.c (Assignment 1)
		NOTE : you have to implement functions in this file
*****************************************************************************/
/*****************************************************************************
		Student Information (非常重要)
		Student ID (学号):162010312	
		Student Name(姓名):王康
*****************************************************************************/

#include <stdlib.h>
#include<iostream>
#include <gl\glut.h>
#include<time.h>
#include<string>
using namespace std;
const GLdouble FRUSTDIM = 100.0f;

int option = 0, i = 0;

GLfloat angle = 0 ;
GLfloat chairPosx = 0, drawerPosx = 0, ballPosy = 0, ballPosz = 0 , teapotSize = 1;
bool enableLight = true, ballJumpUp = true;
GLUquadricObj* quadobj;

/* For lighting*/
GLfloat light0pos[] = { 0.0f, 76.f, 0.f, 0.f };
GLfloat light0_mat1[] = { 1.0, 1.0, 1.0, 1.f };
GLfloat light0_diff[] = { 1.0, 1.0, 1.0, 0.3 };

void init(void) // All Setup For OpenGL Goes Here 
{
	/* Light 0 Settings */

	glLightfv(GL_LIGHT0, GL_POSITION, light0pos);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light0_mat1);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diff);

	quadobj = gluNewQuadric();

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable(GL_NORMALIZE);
	glEnable(GL_DEPTH_TEST);
	glFrontFace(GL_CCW);		/* Define Counter-Clockwise as front face */

	glEnable(GL_COLOR_MATERIAL);
}

void clotheboard() {
	//Draw the clotheboard
	glPushMatrix();
	glColor3ub(228, 175, 97);
	glTranslatef(100.f, -80.f, 210.f);
	glScalef(20.f, 80.0f, 30.f);
	glutSolidCube(1.f);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.168f, 0.522f, 0.169f);
	glTranslatef(89.f, -70.f, 210.f);
	glutSolidSphere(3.f, 10.f, 10.f);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(175, 135, 50);
	glTranslatef(100.f, 0.f, 210.f);
	glScalef(20.f, 80.0f, 30.f);
	glutSolidCube(1.f);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.168f, 0.522f, 0.169f);
	glTranslatef(89.f, 10.f, 210.f);
	glutSolidSphere(3.f, 10.f, 10.f);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(175, 135, 50);
	glTranslatef(100.f, -80.f, 176.f);
	glScalef(20.f, 80.0f, 30.f);
	glutSolidCube(1.f);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.168f, 0.522f, 0.169f);
	glTranslatef(89.f, -70.f, 180.f);
	glutSolidSphere(3.f, 10.f, 10.f);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(228, 175, 97);
	glTranslatef(100.f, 0.f, 176.f);
	glScalef(20.f, 80.0f, 30.f);
	glutSolidCube(1.f);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.168f, 0.522f, 0.169f);
	glTranslatef(89.f, 10.f, 180.f);
	glutSolidSphere(3.f, 10.f, 10.f);
	glPopMatrix();
}

void chair(GLfloat chairPosz) {
	glPushMatrix();
	glColor3ub(132, 155, 162);
	glTranslatef(-75.f, -110.f, 125.f + chairPosz);
	glRotatef(-90, 1.f, 0.f, 0.f);
	gluCylinder(quadobj, 1.f, 1.f, 30.f, 20.f, 20.f);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(132, 155, 162);
	glTranslatef(-75.f, -110.f, 105.f + chairPosz);
	glRotatef(-90, 1.f, 0.f, 0.f);
	gluCylinder(quadobj, 1.f, 1.f, 30.f, 20.f, 20.f);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(132, 155, 162);
	glTranslatef(-55.f, -110.f, 125.f + chairPosz);
	glRotatef(-90, 1.f, 0.f, 0.f);
	gluCylinder(quadobj, 1.f, 1.f, 30.f, 20.f, 20.f);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(132, 155, 162);
	glTranslatef(-55.f, -110.f, 105.f + chairPosz);
	glRotatef(-90, 1.f, 0.f, 0.f);
	gluCylinder(quadobj, 1.f, 1.f, 30.f, 20.f, 20.f);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(166, 183, 187);
	glTranslatef(-65.f, -80.f, 115.f + chairPosz);
	glScalef(30.f, 5.0f, 30.f);
	glutSolidCube(1.f);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(43, 53, 55);
	glTranslatef(-53.f, -83.f, 105.f + chairPosz);
	glRotatef(-90, 1.f, 0.f, 0.f);
	gluCylinder(quadobj, 1.f, 1.f, 30.f, 20.f, 20.f);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(43, 53, 55);
	glTranslatef(-53.f, -83.f, 125.f + chairPosz);
	glRotatef(-90, 1.f, 0.f, 0.f);
	gluCylinder(quadobj, 1.f, 1.f, 30.f, 20.f, 20.f);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(43, 53, 55);
	glTranslatef(-53.f, -60.f, 110.f + chairPosz);
	gluCylinder(quadobj, 1.f, 1.f, 20.f, 20.f, 20.f);
	glPopMatrix();
}

void window() {
	glPushMatrix();
	glColor4f(1.0f, 1.0f, 1.0f, 0.1f);
	glTranslatef(0.f, 40.f, 20.f);
	glScalef(50.f, 5.0f, 10.f);
	glutSolidCube(1.f);
	glPopMatrix();

	glPushMatrix();
	glColor4f(1.0f, 1.0f, 1.0f, 0.1f);
	glTranslatef(0.f, -10.f, 20.f);
	glScalef(50.f, 5.0f, 10.f);
	glutSolidCube(1.f);
	glPopMatrix();

	glPushMatrix();
	glColor4f(1.0f, 1.0f, 1.0f, 0.1f);
	glTranslatef(-25.f, 15.f, 20.f);
	glScalef(3.f, 50.0f, 10.f);
	glutSolidCube(1.f);
	glPopMatrix();

	glPushMatrix();
	glColor4f(1.0f, 1.0f, 1.0f, 0.1f);
	glTranslatef(0.f, 15.f, 20.f);
	glScalef(3.f, 50.0f, 10.f);
	glutSolidCube(1.f);
	glPopMatrix();

	glPushMatrix();
	glColor4f(1.0f, 1.0f, 1.0f, 0.1f);
	glTranslatef(25.f, 15.f, 20.f);
	glScalef(3.f, 50.0f, 10.f);
	glutSolidCube(1.f);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(79, 200, 221);
	glTranslatef(-12.5f, 15.f, 20.f);
	glScalef(20.f, 44.0f, 1.f);
	glutSolidCube(1.f);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(79, 200, 221);
	glTranslatef(12.5f, 15.f, 20.f);
	glScalef(20.f, 44.0f, 1.f);
	glutSolidCube(1.f);
	glPopMatrix();
}

void wall()
{
	/* Back wall */
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(183, 230, 119);
	glVertex3f(-110.0f, 110.0f, -200.0f);
	glVertex3f(-110.0f, -110.0f, -200.0f);
	glVertex3f(110.0f, -110.0f, -200.0f);
	glVertex3f(110.0f, 110.0f, -200.0f);
	glEnd();

	/* Top wall */
	glBegin(GL_POLYGON);
	glColor3f(0.7f, 1.f, 0.7f);
	glVertex3f(-110.0f, 110.0f, -200.0f);
	glVertex3f(110.0f, 110.0f, -200.0f);
	glVertex3f(110.0f, 110.0f, 220.0f);
	glVertex3f(-110.0f, 110.0f, 220.0f);
	glEnd();

	glBegin(GL_QUADS);
	/* Bottom wall */
	glColor3ub(63, 164, 192);
	glVertex3f(110.f, -110.f, -200.f);
	glColor3ub(40, 111, 215);
	glVertex3f(-110.f, -110.f, -200.f);
	glColor3ub(89, 104, 242);
	glVertex3f(-110.f, -110.f, 220.f);
	glColor3ub(18, 100, 237);
	glVertex3f(110.f, -110.f, 220.f);

	/* Right wall */
	glColor3ub(199, 249, 153);
	glVertex3f(110.0f, 110.0f, -200.0f);
	glVertex3f(110.0f, -110.0f, -200.0f);
	glVertex3f(110.0f, -110.0f, 220.0f);
	glVertex3f(110.0f, 110.0f, 220.0f);

	/* Left wall */
	glColor3ub(199, 249, 153);
	glVertex3f(-110.0f, 110.0f, 220.0f);
	glVertex3f(-110.0f, 110.0f, -200.0f);
	glVertex3f(-110.0f, -110.0f, -200.0f);
	glVertex3f(-110.0f, -110.0f, 220.0f);
	glEnd();
	/* Draw the wall END */
}

void bed()
{
	/*bed column*/
	glPushMatrix();
	glColor3ub(132, 155, 162);
	glTranslatef(50.f, -110.f, -200.f);
	glRotatef(-90, 1.f, 0.f, 0.f);
	gluCylinder(quadobj, 2.f, 2.f, 170.f, 20.f, 20.f);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(132, 155, 162);
	glTranslatef(50.f, -110.f, 00.f);
	glRotatef(-90, 1.f, 0.f, 0.f);
	gluCylinder(quadobj, 2.f, 2.f, 150.f, 20.f, 20.f);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(132, 155, 162);
	glTranslatef(50.f, -110.f, 150.f);
	glRotatef(-90, 1.f, 0.f, 0.f);
	gluCylinder(quadobj, 1.f, 1.f, 130.f, 20.f, 20.f);
	glPopMatrix();

	/*bed board*/
	glPushMatrix();
	glColor3ub(187, 139, 49);
	glTranslatef(71.f, -80.f, -60.f);
	glScalef(50.f, 3.0f, 120.f);
	glutSolidCube(1.f);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(187, 139, 49);
	glTranslatef(72.f, -80.f, 85.f);
	glScalef(50.f, 3.0f, 130.f);
	glutSolidCube(1.f);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(187, 139, 49);
	glTranslatef(71.f, -30.f, -60.f);
	glScalef(50.f, 3.0f, 120.f);
	glutSolidCube(1.f);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(187, 139, 49);
	glTranslatef(72.f, -30.f, 85.f);
	glScalef(50.f, 3.0f, 130.f);
	glutSolidCube(1.f);
	glPopMatrix();

	/*bed back*/
	glPushMatrix();
	glColor3ub(148, 124, 54);
	glTranslatef(72.f, -18.f, -130.f);
	glScalef(50.f, 20.0f, 3.f);
	glutSolidCube(1.f);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(148, 124, 54);
	glTranslatef(72.f, -72.f, -130.f);
	glScalef(50.f, 15.0f, 3.f);
	glutSolidCube(1.f);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(148, 124, 54);
	glTranslatef(72.f, -75.f, 0.f);
	glScalef(50.f, 15.0f, 3.f);
	glutSolidCube(1.f);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(148, 124, 54);
	glTranslatef(72.f, -23.f, 0.f);
	glScalef(50.f, 20.0f, 3.f);
	glutSolidCube(1.f);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(148, 124, 54);
	glTranslatef(72.f, -75.f, 149.f);
	glScalef(50.f, 15.0f, 3.f);
	glutSolidCube(1.f);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(148, 124, 54);
	glTranslatef(72.f, -25.f, 149.f);
	glScalef(50.f, 15.0f, 3.f);
	glutSolidCube(1.f);
	glPopMatrix();

	/*the quilt*/
	glPushMatrix();
	glColor4f(0.0f, 0.4f, 0.6f, 0.1f);
	glTranslatef(72.f, -75.f, -60.f);
	glScalef(50.f, 8.0f, 110.f);
	glutSolidCube(1.f);
	glPopMatrix();

	glPushMatrix();
	glColor4f(0.0f, 0.4f, 0.6f, 0.1f);
	glTranslatef(72.f, -75.f, 95.f);
	glScalef(50.f, 8.0f, 110.f);
	glutSolidCube(1.f);
	glPopMatrix();

	glPushMatrix();
	glColor4f(0.0f, 0.4f, 0.6f, 0.1f);
	glTranslatef(72.f, -25.f, -60.f);
	glScalef(50.f, 8.0f, 110.f);
	glutSolidCube(1.f);
	glPopMatrix();

	glPushMatrix();
	glColor4f(0.0f, 0.4f, 0.6f, 0.1f);
	glTranslatef(72.f, -25.f, 95.f);
	glScalef(50.f, 8.0f, 110.f);
	glutSolidCube(1.f);
	glPopMatrix();

	/*ladder*/
	glPushMatrix();
	glColor3ub(132, 155, 162);
	glTranslatef(40.f, -70.f, 40.f);
	glRotatef(-90, 1.f, 0.f, 0.f);
	gluCylinder(quadobj, 1.f, 1.f, 50.f, 20.f, 20.f);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(132, 155, 162);
	glTranslatef(40.f, -70.f, 150.f);
	glRotatef(-90, 1.f, 0.f, 0.f);
	gluCylinder(quadobj, 1.f, 1.f, 50.f, 20.f, 20.f);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(132, 155, 162);
	glTranslatef(40.f, -35.f, 40.f);
	gluCylinder(quadobj, 1.f, 1.f, 50.f, 20.f, 20.f);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(132, 155, 162);
	glTranslatef(40.f, -45.f, 40.f);
	gluCylinder(quadobj, 1.f, 1.f, 50.f, 20.f, 20.f);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(132, 155, 162);
	glTranslatef(40.f, -55.f, 40.f);
	gluCylinder(quadobj, 1.f, 1.f, 50.f, 20.f, 20.f);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(132, 155, 162);
	glTranslatef(45.f, -35.f, 70.f);
	gluCylinder(quadobj, 1.f, 1.f, 30.f, 20.f, 20.f);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(132, 155, 162);
	glTranslatef(45.f, -45.f, 70.f);
	gluCylinder(quadobj, 1.f, 1.f, 30.f, 20.f, 20.f);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(132, 155, 162);
	glTranslatef(45.f, -55.f, 70.f);
	gluCylinder(quadobj, 1.f, 1.f, 30.f, 20.f, 20.f);
	glPopMatrix();
}

void desk()
{
	/*first bottom*/
	glPushMatrix();
	glColor3ub(222, 125, 88);
	glTranslatef(-100.f, -50.f, -190.f);
	glRotatef(90.f, 0.f, 0.f, 30.f);
	glScalef(3.f, 35.0f, 150.f);
	glutSolidCube(1.f);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(222, 125, 88);
	glTranslatef(-100.f, -18.f, -190.f);
	glRotatef(90.f, 0.f, 0.f, 30.f);
	glScalef(3.f, 30.0f, 150.f);
	glutSolidCube(1.f);
	glPopMatrix();

	/*first wall*/
	glPushMatrix();
	glColor3ub(221, 169, 72);
	glTranslatef(-100.f, -35.f, -190.f);
	glRotatef(90.f, 0.f, 1.f, 0.f);
	glScalef(3.f, 30.0f, 20.f);
	glutSolidCube(1.f);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(221, 169, 72);
	glTranslatef(-100.f, -2.f, -190.f);
	glRotatef(90.f, 0.f, 1.f, 0.f);
	glScalef(3.f, 30.0f, 25.f);
	glutSolidCube(1.f);
	glPopMatrix();

	/*secondbottom*/
	glPushMatrix();
	glColor3ub(184, 82, 52);
	glTranslatef(-100.f, -50.f, -60.f);
	glRotatef(90.f, 0.f, 0.f, 30.f);
	glScalef(3.f, 35.0f, 80.f);
	glutSolidCube(1.f);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(184, 82, 52);
	glTranslatef(-100.f, -18.f, -60.f);
	glRotatef(90.f, 0.f, 0.f, 30.f);
	glScalef(3.f, 30.0f, 80.f);
	glutSolidCube(1.f);
	glPopMatrix();

	/*second wall*/
	glPushMatrix();
	glColor3ub(187, 139, 49);
	glTranslatef(-100.f, -35.f, -90.f);
	glRotatef(90.f, 0.f, 1.f, 0.f);
	glScalef(3.f, 30.0f, 20.f);
	glutSolidCube(1.f);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(187, 139, 49);
	glTranslatef(-100.f, -2.f, -90.f);
	glRotatef(90.f, 0.f, 1.f, 0.f);
	glScalef(3.f, 30.0f, 25.f);
	glutSolidCube(1.f);
	glPopMatrix();

	/*third bottom*/
	glPushMatrix();
	glColor3ub(222, 125, 88);
	glTranslatef(-100.f, -50.f, 30.f);
	glRotatef(90.f, 0.f, 0.f, 30.f);
	glScalef(3.f, 35.0f, 80.f);
	glutSolidCube(1.f);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(222, 125, 88);
	glTranslatef(-100.f, -18.f, 30.f);
	glRotatef(90.f, 0.f, 0.f, 30.f);
	glScalef(3.f, 30.0f, 80.f);
	glutSolidCube(1.f);
	glPopMatrix();

	/*third wall*/
	glPushMatrix();
	glColor3ub(221, 169, 72);
	glTranslatef(-100.f, -35.f, -20.f);
	glRotatef(90.f, 0.f, 1.f, 0.f);
	glScalef(3.f, 30.0f, 20.f);
	glutSolidCube(1.f);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(221, 169, 72);
	glTranslatef(-100.f, -2.f, -20.f);
	glRotatef(90.f, 0.f, 1.f, 0.f);
	glScalef(3.f, 30.0f, 20.f);
	glutSolidCube(1.f);
	glPopMatrix();

	/*fourth bottom*/
	glPushMatrix();
	glColor3ub(184, 82, 52);
	glTranslatef(-100.f, -50.f, 80.f);
	glRotatef(90.f, 0.f, 0.f, 30.f);
	glScalef(3.f, 35.0f, 80.f);
	glutSolidCube(1.f);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(184, 82, 52);
	glTranslatef(-100.f, -18.f, 80.f);
	glRotatef(90.f, 0.f, 0.f, 30.f);
	glScalef(3.f, 30.0f, 80.f);
	glutSolidCube(1.f);
	glPopMatrix();

	/*fourth wall*/
	glPushMatrix();
	glColor3ub(187, 139, 49);
	glTranslatef(-100.f, -35.f, 70.f);
	glRotatef(90.f, 0.f, 1.f, 0.f);
	glScalef(3.f, 30.0f, 20.f);
	glutSolidCube(1.f);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(187, 139, 49);
	glTranslatef(-100.f, -2.f, 70.f);
	glRotatef(90.f, 0.f, 1.f, 0.f);
	glScalef(3.f, 30.0f, 36.f);
	glutSolidCube(1.f);
	glPopMatrix();

	/*fifth wall*/
	glPushMatrix();
	glColor3ub(221, 169, 72);
	glTranslatef(-100.f, -33.f, 125.f);
	glRotatef(90.f, 0.f, 1.f, 0.f);
	glScalef(3.f, 34.0f, 20.f);
	glutSolidCube(1.f);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(221, 169, 72);
	glTranslatef(-100.f, -3.f, 125.f);
	glRotatef(90.f, 0.f, 1.f, 0.f);
	glScalef(3.f, 30.0f, 36.f);
	glutSolidCube(1.f);
	glPopMatrix();

	/*cabinet*/
	glPushMatrix();
	glColor3ub(184, 82, 52);
	glTranslatef(-100.f, 27.f, 90.f);
	glScalef(35.f, 30.0f, 70.f);
	glutSolidCube(1.f);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(222, 125, 88);
	glTranslatef(-100.f, 27.f, 20.f);
	glScalef(35.f, 30.0f, 70.f);
	glutSolidCube(1.f);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(184, 82, 52);
	glTranslatef(-100.f, 27.f, -60.f);
	glScalef(35.f, 30.0f, 70.f);
	glutSolidCube(1.f);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(222, 125, 88);
	glTranslatef(-100.f, 27.f, -150.f);
	glScalef(35.f, 30.0f, 70.f);
	glutSolidCube(1.f);
	glPopMatrix();

	/*leg*/
	glPushMatrix();
	glColor3ub(221, 169, 72);
	glTranslatef(-100.f, -80.f, 125.f);
	glRotatef(90.f, 0.f, 1.f, 0.f);
	glScalef(3.f, 60.0f, 36.f);
	glutSolidCube(1.f);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(187, 139, 49);
	glTranslatef(-100.f, -80.f, 70.f);
	glRotatef(90.f, 0.f, 1.f, 0.f);
	glScalef(3.f, 60.0f, 36.f);
	glutSolidCube(1.f);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(221, 169, 72);
	glTranslatef(-100.f, -80.f, 20.f);
	glRotatef(90.f, 0.f, 1.f, 0.f);
	glScalef(3.f, 60.0f, 36.f);
	glutSolidCube(1.f);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(187, 139, 49);
	glTranslatef(-100.f, -80.f, -90.f);
	glRotatef(90.f, 0.f, 1.f, 0.f);
	glScalef(3.f, 60.0f, 36.f);
	glutSolidCube(1.f);
	glPopMatrix();

	/*drawer*/
	glPushMatrix();
	glColor3ub(184, 82, 52);
	glTranslatef(-100.f + drawerPosx, -57.f, 90.f);
	glScalef(38.f, 15.0f, 70.f);
	glutSolidCube(1.f);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.168f, 0.522f, 0.169f);
	glTranslatef(-80.f + drawerPosx, -57.f, 90.f);
	glutSolidSphere(3.f, 10.f, 10.f);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(222, 125, 88);
	glTranslatef(-100.f, -57.f, 20.f);
	glScalef(38.f, 15.0f, 70.f);
	glutSolidCube(1.f);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.168f, 0.522f, 0.169f);
	glTranslatef(-80.f, -57.f, 20.f);
	glutSolidSphere(3.f, 10.f, 10.f);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(184, 82, 52);
	glTranslatef(-100.f, -57.f, -60.f);
	glScalef(38.f, 15.0f, 70.f);
	glutSolidCube(1.f);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.168f, 0.522f, 0.169f);
	glTranslatef(-80.f, -57.f, -60.f);
	glutSolidSphere(3.f, 10.f, 10.f);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(222, 125, 88);
	glTranslatef(-100.f, -57.f, -150.f);
	glScalef(38.f, 15.0f, 70.f);
	glutSolidCube(1.f);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.168f, 0.522f, 0.169f);
	glTranslatef(-80.f, -57.f, -150.f);
	glutSolidSphere(3.f, 10.f, 10.f);
	glPopMatrix();
}

void airfan()
{
	glPushMatrix();
	glColor4f(0.8f, 0.8f, 0.7f, 0.1f);
	glTranslatef(0.f, 90.f, 160);
	glRotatef(-90.f, 1.f, 0.f, 0.f);
	glutSolidTorus(5, 5, 100.f, 110.f);
	glPopMatrix();

	glPushMatrix();
	glColor4f(0.5f, 0.8f, 0.2f, 0.1f);
	glTranslatef(5.f, 85.f, 170.f);
	glRotatef(60.f, 0.f, 1.f, 0.f);
	glScalef(2.f, 2.0f, 10.f);
	glutSolidCube(1.f);
	glPopMatrix();

	glPushMatrix();
	glColor4f(0.5f, 0.8f, 0.2f, 0.1f);
	glTranslatef(-5.f, 85.f, 170.f);
	glRotatef(-60.f, 0.f, 1.f, 0.f);
	glScalef(2.f, 2.0f, 10.f);
	glutSolidCube(1.f);
	glPopMatrix();

	glPushMatrix();
	glColor4f(0.5f, 0.8f, 0.2f, 0.1f);
	glTranslatef(0.f, 85.f, 160.f);
	glScalef(2.f, 2.0f, 10.f);
	glutSolidCube(1.f);
	glPopMatrix();
}
void selectFont(int size, int charset, const char* face)//选择字体对象（包括格式）
{
	HFONT hFont = CreateFontA(size, 0, 0, 0, FW_MEDIUM, 0, 0, 0,
		charset, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, face);
	HFONT hOldFont = (HFONT)SelectObject(wglGetCurrentDC(), hFont);//选择字体对象，返回旧的对象
	DeleteObject(hOldFont);//删除旧的对象
}

void drawCNString(const char* str)
{
	int len, i;
	wchar_t* wstring;
	HDC hDC = wglGetCurrentDC();
	GLuint list = glGenLists(1);
	// 计算字符的个数
	// 如果是双字节字符的（比如中文字符），两个字节才算一个字符
	// 否则一个字节算一个字符
	len = 0;
	for (i = 0; str[i] != '\0'; ++i)
	{
		if (IsDBCSLeadByte(str[i]))
			++i;
		++len;
	}
	// 将混合字符转化为宽字符
	wstring = (wchar_t*)malloc((len + 1) * sizeof(wchar_t));
	MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str, -1, wstring, len);
	wstring[len] = L'\0';
	// 逐个输出字符
	for (i = 0; i < len; ++i)
	{
		wglUseFontBitmapsW(hDC, wstring[i], 1, list);
		glCallList(list);
	}
	// 回收所有临时资源
	free(wstring);
	glDeleteLists(list, 1);
}

void display(void) // Here's Where We Do All The Drawing
{
	/* Clear the buffer */
	glClearColor(0.0, 0.0, 0.0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

	glLoadIdentity();
	glPushMatrix();
	glTranslatef(0, 0, -550);

	/* Initialize material properties */
	GLfloat no_mat[] = { 0.0,0.0,0.0,1.0 };
	GLfloat mat_diffuse[] = { 0.9,0.9,0.9,1.0 };
	GLfloat mat_specular[] = { 0.3,0.3,0.3,1.0 };
	GLfloat high_shininess[] = { 20.0 };
	GLfloat high_mat[] = { 1.0,1.0,1.0,1.0 };


	glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);

	time_t timep;
	struct tm t;
	time(&timep);
	localtime_s(&t, &timep);
	string sec = t.tm_sec>9 ? to_string(t.tm_sec) :"0"+ to_string(t.tm_sec);
	string min = t.tm_min>9 ? to_string(t.tm_min) : "0" + to_string(t.tm_min);
	string hour = t.tm_hour>9 ? to_string(t.tm_hour) : "0" + to_string(t.tm_hour);
	string time = hour + ":" + min + ":" + sec;

	const char* c_s = time.c_str();
	selectFont(48, GB2312_CHARSET, "华光楷体_CNKI");
	glColor3ub(188, 206, 28);//设置字体颜色
	glRasterPos3f(-30.f, -90.1f,250.f);
	drawCNString("慧园606-02");

	selectFont(28, GB2312_CHARSET, "微软雅黑");
	glColor3ub(194, 79, 198);//设置字体颜色
	glRasterPos3f(20.f, 45.1f, 150.f);
	drawCNString(c_s);

	/*Draw desk START*/
	desk();

	/*chair*/
	GLfloat chairPosz = 80.f;
	glTranslatef(chairPosx, 0, 0);
	for (int i = 0; i < 4; i++)
	{
		chairPosz = chairPosz- 80.f;
		//cout << chairPos;
		chair(chairPosz);
	}
	glTranslatef(-chairPosx, 0, 0);

	/*Draw Light bulb START*/
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_EMISSION, light0_mat1);
	glColor4f(0.8f, 0.8f, 0.7f, 0.1f);
	glTranslatef(0.f, 90.f, 230.f);
	glScalef(5.f, 5.0f, 50.f);
	glutSolidCube(1.f);
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_EMISSION, light0_mat1);
	glColor4f(0.8f, 0.8f, 0.7f, 0.1f);
	glTranslatef(0.f, 90.f, 80.f);
	glScalef(5.f, 5.0f, 60.f);
	glutSolidCube(1.f);
	glPopMatrix();

	glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);

	/*Draw Light bulb END*/

	/*Draw the airfan*/
	airfan();

	/*Draw clotheboard*/
	clotheboard();

	/*aircondition*/
	glPushMatrix();
	glColor4f(1.0f, 1.0f, 1.0f, 0.1f);
	glTranslatef(0.f, 70.f, -20.f);
	glScalef(50.f, 20.0f, 10.f);
	glutSolidCube(1.f);
	glPopMatrix();

	glPushMatrix();
	glColor4f(0.0f, 0.0f, 0.0f, 0.1f);
	glTranslatef(0.f, 63.f, -10.f);
	glScalef(40.f, 1.0f, 1.f);
	glutSolidCube(1.f);
	glPopMatrix();

	glPushMatrix();
	glColor4f(1.0f, 1.0f, 1.0f, 0.1f);
	glTranslatef(-37.f, 65.f, -20.f);
	glScalef(25.f, 2.0f, 2.f);
	glutSolidCube(1.f);
	glPopMatrix();

	glPushMatrix();
	glColor4f(1.0f, 1.0f, 1.0f, 0.1f);
	glTranslatef(-48.f, 55.f, -20.f);
	glScalef(2.f, 20.0f, 2.f);
	glutSolidCube(1.f);
	glPopMatrix();

	glPushMatrix();
	glColor4f(1.0f, 1.0f, 1.0f, 0.1f);
	glTranslatef(-48.f, 48.f, -20.f);
	glutSolidSphere(5.f, 10.f, 10.f);
	glPopMatrix();

	/*window*/
	window();

	/* Draw the wall */
	wall();

	/* Draw the left door */
	glPushMatrix();
	glColor3ub(145, 103, 87);
	glTranslatef(-100.f, -24.f, 250.f);
	glRotatef(angle, 0.f, -1.f, 0.f);
	glScalef(2.f, 150.0f, 130.f);
	glutSolidCube(1.f);
	glPopMatrix();

	/*Draw the ball*/
	glPushMatrix();
	glColor3ub(232, 113, 26);
	glTranslatef(20.f, -70.f + ballPosy, -10.f + ballPosz);
	glutWireSphere(15.f, 30.f, 30.f);
	glPopMatrix();

	/*Draw the teapot*/
	glPushMatrix();
	glColor3ub(130, 130, 104);
	glTranslatef(90.f, 48.f, 195.f);
	glRotatef(-90.f, 0.f, 1.f, 0.f);
	glScalef(100.f, 100.0f, -100.f);
	glutSolidTeapot(0.1*teapotSize);
	glPopMatrix();

	/*Draw the bed */
	bed();

	glPopMatrix();
	glutSwapBuffers();
	glFlush();

	/* Refresh the frame */
	glutPostRedisplay();
}

void reshape(int w, int h) // Resize the GL Window. w=width, h=height
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-FRUSTDIM, FRUSTDIM, -FRUSTDIM, FRUSTDIM, 300., 800.);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y) // Handle the keyboard events here
{
	switch (key)
	{
	case '\033'://press 'esc' to quit
		exit(0);
		break;
	case 'p': /*pause*/
		option = 1;
		break;

	case '1': /*decrease light*/
		if (enableLight)
			if (light0_mat1[0] >= 0) {
				for (i = 0; i <= 3; i++) {
					light0_mat1[i] -= 0.01;
					light0_diff[i] -= 0.01;
				}
				glLightfv(GL_LIGHT0, GL_AMBIENT, light0_mat1);
				glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diff);
				glEnable(GL_LIGHT0);
			}
		break;

	case '2': /*increase light*/
		if (enableLight)
			if (light0_mat1[0] <= 1) {
				for (i = 0; i <= 3; i++) {
					light0_mat1[i] += 0.01;
					light0_diff[i] += 0.01;
				}
				glLightfv(GL_LIGHT0, GL_AMBIENT, light0_mat1);
				glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diff);
				glEnable(GL_LIGHT0);
			}
		break;

	case 's': /*switch on/off the light*/
		option = 4;
		break;
	case '3':/* open the door */
		option = 2;
		break;
	case '4':/* close the door */
		option = 3;
		break;
	case '7':/*make the ball jump up*/
		option = 5;
		break;
	case 'w':/*put back the chair*/
		option = 7;
		break;
	case 'q':/*pull the chair*/
		option = 8;
		break;
	case 'e':/*pull the drawer*/
		option = 9;
		break;
	case 'r':/*push back the drawer*/
		option = 10;
		break;
	case '5':/*Open the door guadually*/
		option = 99;
		if (angle >= 0)
		{
			if (angle < 60)
				angle+=2;
		}
		break;
	case '6':/*close the door guadually*/
		option = 99;
		if (angle <= 60)
		{
			if (angle > 0)
				angle-=2;
		}
		break;
	case 'a':/*make the teapot bigger*/
		option = 11;
		break;
	case 'd':/*make the teapot smaller*/
		option = 6;
		break;
	}
}

void idle()
{
	if (option == 1)
	{

	}
	else if (option == 2)	/* open the door */
	{
		if (angle >= 0)
		{
			if(angle<60)
				angle++;
		}
	}
	else if (option == 3)	/* close the door */
	{
		if (angle <= 60)
		{
			if (angle > 0)
				angle--;
		}
	}
	else if (option == 4)	/*switch on/off the light*/
	{
		if (enableLight)
		{
			enableLight = 0;
			for (i = 0; i <= 3; i++) {
				light0_mat1[i] = 0.0;
			}
			glLightfv(GL_LIGHT0, GL_AMBIENT, light0_mat1);
			glDisable(GL_LIGHT0);
			option = 1;
		}
		else
		{
			enableLight = 1;
			for (i = 0; i <= 3; i++) {
				light0_diff[i] = 1.0;
				light0_mat1[i] = 1.0;
			}
			glLightfv(GL_LIGHT0, GL_AMBIENT, light0_mat1);
			glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diff);
			glEnable(GL_LIGHT0);
			option = 1;
		}
	}
	else if (option == 5)	/*make the ball jump up*/
	{
		if (ballJumpUp) {
			ballPosy += 1;
			ballPosz += 2;
			if (ballPosy >= 20) ballJumpUp = false;
		}
		else {
			ballPosy -= 1;
			ballPosz -= 2;
			if (ballPosy <= 0) ballJumpUp = true;
		}
	}
	else if (option == 6)
	{
		if (teapotSize > 1)
			teapotSize -= 0.05;
	}
	else if (option == 7)	/*put back the chair*/
	{
		if (chairPosx >= 0)
			chairPosx -= 1;
	}

	else if (option == 8)	/*pull the chair*/
	{
		if (chairPosx <= 40)
			chairPosx += 1;
	}

	else if (option == 9)	/*pull the drawer*/
	{
		if (drawerPosx <= 15)
			drawerPosx += 1;
	}
	else if (option == 10)	/*push back the drawer*/
	{
		if (drawerPosx >= 0)
			drawerPosx -= 1;
	}
	else if (option == 11)
	{
		if (teapotSize <= 1.5)
			teapotSize += 0.05;
	}
	else {}
}

void main(int argc, char** argv)
{

	/* Initialization of GLUT Library */
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

	/* Create a window with title specified */
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Assignment 1: Creating a 3D Room");

	init();	/* not GLUT call, initialize several parameters */

	/* Register different CALLBACK function for GLUT to response
	 * with different events, e.g. window sizing, mouse click or
	 * keyboard stroke*/
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutIdleFunc(idle);

	/*Enter the GLUT event processing loop which never returns.
	it will call different registered CALLBACK according
	to different events. */
	glutMainLoop();
}