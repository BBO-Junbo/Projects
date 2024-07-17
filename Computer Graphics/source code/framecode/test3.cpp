#include <GL/freeglut.h>
#include<stdlib.h>
#include "geomodeling.h"
#include "test3.h"
#include <cmath>

// Material properties (example values, you need to set these accordingly)
extern GLfloat matBrown[];
extern GLfloat matBlack[];
extern GLfloat matWhite[];

// Light status
extern bool Light2;

// Global variables to track the position, limb angles, and rotation angle
extern float x_position;
extern float y_position;
extern float z_position;
extern float arm_angle;
extern float leg_angle;
extern float rotation_angle;
extern float rotation_angle_y;
extern float rotation_angle_z;
extern bool sitting; // New global variable to track sitting status
extern bool arm_up;

void draw_people() {
    glPushMatrix();
    glTranslatef(x_position, y_position, z_position + 0.3f);  // Use updated positions
    glRotatef(rotation_angle, 1.0, 0.0, 0.0); // Rotate the entire person
    glRotatef(rotation_angle_y, 0.0, 1.0, 0.0); // Rotate around the y-axis
    glRotatef(rotation_angle_z, 0.0, 0.0, 1.0); // Rotate around the z-axis

    glMaterialfv(GL_FRONT, GL_AMBIENT, matBrown);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, matBrown);
    glMaterialfv(GL_FRONT, GL_SPECULAR, matBlack);
    glMaterialfv(GL_FRONT, GL_SHININESS, matBlack);
    glMaterialfv(GL_FRONT, GL_EMISSION, matBlack);
    if (Light2)
        glMaterialfv(GL_FRONT, GL_EMISSION, matBrown);

    // Head
    glColor3ub(239, 228, 176);
    glPushMatrix();
    if (sitting) {
        glTranslatef(0.0, -1.0, 0);
    }
    glScalef(0.8, 1.0, 0.7);
    glutSolidSphere(1.0, 100, 100);
    glPopMatrix();

    // Eyes


    glColor3ub(0, 0, 0);
    // Left eye
    glPushMatrix();
    glTranslatef(-0.3, 0.4, 0.6);
    if (sitting) {
        glTranslatef(0.0, -1.0, 0);
    }
    glutSolidSphere(0.04, 10, 10);
    glPopMatrix();
    // Right eye
    glPushMatrix();
    glTranslatef(0.3, 0.4, 0.6);
    if (sitting) {
        glTranslatef(0.0, -1.0, 0);
    }
    glutSolidSphere(0.04, 10, 10);
    glPopMatrix();
	

	
    // Mouth
	    double c= 3.1415926/180;
	    float anglem=15.0*c;
	    float mz=1.0*cos(anglem);
	    float my = 1.0*sin(anglem);
	    glPushMatrix();
	    glTranslatef(0,-1*my+0.2,+mz);
	    glColor3f(1,0,0);
	    glPointSize(3.0);
	    glBegin(GL_POINTS);
	    glVertex3f(0, 0, 0);
	    glEnd();
	    glPopMatrix();    
    
    

    // Neck
    glColor3ub(239, 228, 176);
    glPushMatrix();
    glTranslatef(0, -0.7, 0);
    if (sitting) {
        glTranslatef(0.0, -1.0, 0);
    }
    glScalef(0.7, 0.4, 0.6);
    glutSolidCube(1.0);
    glPopMatrix();

    // Torso
    glColor3f(0.0, 0.0, 1.0);
    glPushMatrix();
    glTranslatef(0, -1.7, 0);
    if (sitting) {
        glTranslatef(0.0, -1.0, 0);
    }
    glScalef(2, 2, 0.6);
    glutSolidCube(1.0);

    // Buttons
    glColor3f(0.7, 0.5, 0.5);
    glPushMatrix();
    glTranslatef(0, 0.5, 0.31);
    glutSolidSphere(0.04, 10, 10);
    glTranslatef(0, -1.0, 0);
    glutSolidSphere(0.04, 10, 10);
    glPopMatrix();

    glPopMatrix();

    
	if (sitting){
		// Left arm
	    glColor3f(0.0, 0.0, 1.0);
	    // Upper part
	    glPushMatrix();
	    glTranslatef(-1.25, -1.0, 0);
	    glRotatef(50, 1.0, 0.0, 0.0);
	    glTranslatef(0,1,1);
	    glScalef(0.5, 3.5, 0.5);
	    glutSolidCube(1.0);
	    glPopMatrix();

		// Hand of the left arm
		glColor3ub(239, 228, 176);
		glPushMatrix();
		glTranslatef(0, 1, 3); // Move along the y-axis
		glTranslatef(-1.0, -0.8, 0);
		glScalef(0.5, 0.5, 0.5);
		glutSolidCube(1.0);
		glPopMatrix();
		
		
		   // Right arm
	    glColor3f(0.0, 0.0, 1.0);
	    // Upper part
	    glPushMatrix();
	    glTranslatef(1.25, -1.0, 0);
	    glRotatef(50, 1.0, 0.0, 0.0);
	    glTranslatef(0,1,1);
	    glScalef(0.5, 3.5, 0.5);
	    glutSolidCube(1.0);
	    glPopMatrix();
	    
	    //right hand
		glColor3ub(239, 228, 176);
		glPushMatrix();
		glTranslatef(0, 1, 3); // Move along the y-axis
		glTranslatef(-1.0, -0.8, 0);
		glScalef(0.5, 0.5, 0.5);
		glutSolidCube(1.0);
		glPopMatrix();
	}else if(arm_up){
		// Left arm
	    glColor3f(0.0, 0.0, 1.0);
	    // Upper part
	    glPushMatrix();
	    glTranslatef(-1.25, -1.0, 0);
	    glRotatef(sin(arm_angle) * 45, 1.0, 0.0, 0.0);
	    glRotatef(50, 1.0, 0.0, 0.0);
	    glScalef(0.5, 3.0, 0.5);
	    glutSolidCube(1.0);
	    glPopMatrix();

		// Hand of the left arm
		glColor3ub(239, 228, 176);
		glPushMatrix();
		glScalef(0.5, 0.5, 0.5);
		glutSolidCube(1.0);
		glPopMatrix();
		// Right arm
	    glColor3f(0.0, 0.0, 1.0);
	    // Upper part
	    glPushMatrix();
	    glTranslatef(1.25, -1.0, 0);
	    glRotatef(-sin(arm_angle) * 45, 1.0, 0.0, 0.0);
	    if (sitting) {
	        glRotatef(70, 1.0, 0.0, 0.0);
	        glTranslatef(0,-1, 0);
	        
	    }
	    glScalef(0.5, 1.0, 0.5);
	    glutSolidCube(1.0);
	    glPopMatrix();
	    // right lower
	    glPushMatrix();
	    glTranslatef(1.25, -2.0, 0);
	    glRotatef(-sin(arm_angle) * 45, 1.0, 0.0, 0.0);
	    glScalef(0.4, 1.0, 0.5);
	    glutSolidCube(1.0);
	    glPopMatrix();
	    
	    // Hand
	    glColor3ub(239, 228, 176);
	    glPushMatrix();
	    glTranslatef(1.25, -2.75, 0);
	    glScalef(0.5, 0.5, 0.5);
	    glutSolidCube(1.0);
	    glPopMatrix();
		
	}else{
		// Left arm
	    glColor3f(0.0, 0.0, 1.0);
	    // Upper part
	    glPushMatrix();
	    glTranslatef(-1.25, -1.0, 0);


	    glScalef(0.5, 1.0, 0.5);
	    glutSolidCube(1.0);
	    glPopMatrix();
	    
	    //lower
	    glPushMatrix();
	    glTranslatef(-1.25, -2.0, 0);
	    glRotatef(sin(arm_angle) * 45, 1.0, 0.0, 0.0);
	    glScalef(0.4, 1.0, 0.5);
	    glutSolidCube(1.0);
	    glPopMatrix();    
		
		// Hand
	    glColor3ub(239, 228, 176);
	    glPushMatrix();
	    glTranslatef(-1.25, -2.75, 0);
	    if (sitting) {
	        glTranslatef(0, -1.0, 1.25);
	    }
	    glRotatef(sin(arm_angle) * 30, 1.0, 0.0, 0.0);
	    glScalef(0.5, 0.5, 0.5);
	    glutSolidCube(1.0);
	    glPopMatrix();
	    
	    
	    // Right arm
	    glColor3f(0.0, 0.0, 1.0);
	    // Upper part
	    glPushMatrix();
	    glTranslatef(1.25, -1.0, 0);
	    if (sitting) {
	        glRotatef(70, 1.0, 0.0, 0.0);
	        glTranslatef(0,-1, 0);
	        
	    }
	    glScalef(0.5, 1.0, 0.5);
	    glutSolidCube(1.0);
	    glPopMatrix();
	    // right lower
	    glPushMatrix();
	    glTranslatef(1.25, -2.0, 0);
	    glRotatef(-sin(arm_angle) * 45, 1.0, 0.0, 0.0);
	    glScalef(0.4, 1.0, 0.5);
	    glutSolidCube(1.0);
	    glPopMatrix();
	    
	    // Hand
	    glColor3ub(239, 228, 176);
	    glPushMatrix();
	    glTranslatef(1.25, -2.75, 0);
	    glRotatef(sin(leg_angle) * 30, 1.0, 0.0, 0.0);
	    glScalef(0.5, 0.5, 0.5);
	    glutSolidCube(1.0);
	    glPopMatrix();
	}






    // Left leg
    glColor3f(0.7, 0.5, 0.5);
    // Upper part
    glPushMatrix();
    glTranslatef(-0.5, -3.7, 0);
    if (sitting) {
        glRotatef(90, 1.0, 0.0, 0.0);
        glTranslatef(0, 0.5, 0);
    }
    glScalef(0.8, 2.0, 0.6);
    glutSolidCube(1.0);
    glPopMatrix();
    // Lower part
    glPushMatrix();
    glTranslatef(-0.5, -5.7, 0);
    glRotatef(-sin(leg_angle) * 30, 1.0, 0.0, 0.0);
    if (sitting) {
        glTranslatef(0, 1.0, 1.5);
    }
    glScalef(0.5, 2.0, 0.5);
    glutSolidCube(1.0);
    glPopMatrix();
    // Foot
    glColor3ub(0, 0, 0);
    glPushMatrix();
    glTranslatef(-0.5, -6.7, 0.25);
    if (sitting) {
        glTranslatef(0.0, 1.0, 1.5);
    }
    glScalef(0.5, 0.5, 1.0);
    glutSolidCube(1.0);
    glPopMatrix();

    // Right leg
    glColor3f(0.7, 0.5, 0.5);
    // Upper part
    glPushMatrix();
    glTranslatef(0.5, -3.7, 0);
    if (sitting) {
        glRotatef(90, 1.0, 0.0, 0.0);
        glTranslatef(0, 0.5, 0);
    }
    glScalef(0.8, 2.0, 0.6);
    glutSolidCube(1.0);
    glPopMatrix();
    // Lower part
    glPushMatrix();
    glTranslatef(0.5, -5.7, 0);
    glRotatef(sin(leg_angle) * 30, 1.0, 0.0, 0.0);
    if (sitting) {
        glTranslatef(0, 1.0, 1.5);
    }
    glScalef(0.5, 2.0, 0.5);
    glutSolidCube(1.0);
    glPopMatrix();
    // Foot
    glColor3ub(0, 0, 0);
    glPushMatrix();
    glTranslatef(0.5, -6.7, 0.25);
    if (sitting) {
        glTranslatef(0.0, 1.0, 1.5);
    }
    glScalef(0.5, 0.5, 1.0);
    glutSolidCube(1.0);
    glPopMatrix();

    glPopMatrix();
}

