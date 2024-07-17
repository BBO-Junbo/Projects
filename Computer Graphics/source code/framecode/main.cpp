#include <GL/freeglut.h>
#include <GL/glut.h>
#include <cmath>
#include <ctime>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
//#include "pngimage.h"
#include "test1.h"
#include "test2.h"
#include "test3.h"
#include "outdoor.h"
#include "geomodeling.h"


using namespace std;

int windowWidth = 600;   // Á™óÂè£ÂÆΩÂ∫¶
int windowHeight = 350;  // Á™óÂè£È´òÂ∫¶

int WinWidth,WinHeight;
static unsigned int texName;
unsigned char checkImage[64][64][3];
static int checkImageHeight = 64, checkImageWidth = 64;
static float eye[3] = { 0,0,20 }, eobj[3] = { 0,0,0 };
float armAngle = 0.0f;    // Initial angle for the right arm
bool armGoingUp = true;   // Direction of the arm movement
//‰∫ßÁîüÁ∫πÁêÜ
void makeCheckImages(void)
{
    int i, j, c;
    for (i = 0; i < checkImageHeight; i++) {
        for (j = 0; j < checkImageWidth; j++) {
            c = ((((i & 0x8) == 0) ^ ((j & 0x8)) == 0)) * 255;
            if (c == 255)
            {
                checkImage[i][j][0] = (GLubyte)180;
                checkImage[i][j][1] = (GLubyte)180;
                checkImage[i][j][2] = (GLubyte)180;
                checkImage[i][j][3] = (GLubyte)255;
            }
            else
            {
                checkImage[i][j][0] = (GLubyte)c;
                checkImage[i][j][1] = (GLubyte)c;
                checkImage[i][j][2] = (GLubyte)c;
                checkImage[i][j][3] = (GLubyte)255;
            }
        }
    }
}

void setLight0(bool Light0)
{
    Light0 = 0;

    GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
    GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    GLfloat light1_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
    GLfloat light1_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light1_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light1_position[] = { -2.0, 2.0, 1.0, 1.0 };
    GLfloat spot_direction[] = { -1.0, -1.0, 0.0 };

    glLightfv(GL_LIGHT1, GL_AMBIENT, light1_ambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular);
    glLightfv(GL_LIGHT1, GL_POSITION, light1_position);
    glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 1.5);
    glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.5);
    glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.2);
    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 45.0);
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction);
    glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 2.0);
    glEnable(GL_LIGHT1);
}






// Global variables to track the position, limb angles, and rotation angle
float x_position = -10.0f;
float y_position = -3.5f;
float z_position = -18.0f;
float chair_position = 14.5f;
float arm_angle = 0.0f;
float leg_angle = 0.0f;
float rotation_angle = 0.0f;
float rotation_angle_y = 0.0f;
float rotation_angle_z = 0.0f;
bool inside = true;
bool walking1 = true;
bool sleeping = false;
bool walking2 = false;
bool move_chair = false;
bool tv_open = true;
bool sitting = false; // New global variable to track sitting status
bool arm_up = false;
bool closing_tv = false; 
bool walking3 = false;
bool walking4 = false;
bool outing = false;
bool walking5 = false;
bool fly = false;
bool landing = false;
float sleeping_time = 0;
float sitting_time = 0;
float arm_up_time = 0;
void update(int value) {
	if(walking1){
		if (x_position < -7.0f) {
    	arm_angle += 0.1f;
    	leg_angle += 0.1f;
        x_position += 0.1f;
    	}
    	if (z_position <-6.0f) {
    	arm_angle += 0.1f;
    	leg_angle += 0.1f;
        z_position += 0.1f;
    	}
    	if (x_position >= -7.0f && z_position >=-6.0f) {
        // Start lying down
        x_position = 0.0f;
        y_position = -6.0f ; 
        z_position = -7.0f;
        rotation_angle = -90.0f;
        sleeping = true;
        walking1 = false;
		}
	} 
	 else if (sleeping) {
        if (sleeping_time < 125) { // Wait for 2 seconds
            sleeping_time += 1;
        } else {
            sleeping = false;
            walking2 = true;
            x_position = 6.0f;
            y_position = -3.5f;
            z_position = -7.0f;
            rotation_angle = 0.0f;
			rotation_angle_y = 90.f;
        }
    } else if (walking2) {
        if (x_position < 13.0f) {
            x_position += 0.1f;
            arm_angle += 0.1f;
            leg_angle += 0.1f;
        } else {
            walking2 = false;
            move_chair = true;
        }
    } else if (move_chair){
    	if (x_position >= 11.5f){
    		x_position -= 0.1f;
    		chair_position -=0.1f;
		}else{
			move_chair = false;
			sitting = true;
		}
	}else if(sitting){
		x_position = 12.4f;
		y_position = -3.0f;
		if (sitting_time< 125) { // Wait for 2 seconds
            sitting_time += 1;
        } else {
        	sitting = false;
        	closing_tv = true;
		}
	}else if(closing_tv) {
		x_position = 14.5f;
		float y_position = -3.5f;
		arm_up = true;
		if(arm_up_time<125){
			arm_up_time++;
		}else{
			tv_open = false;
			arm_up = false;
			closing_tv = false;
			walking3 = true;
		}

	}else if(walking3){
		rotation_angle_y = 0.0f;
		if (x_position > 0.0f && z_position <10.0f) {
    	arm_angle += 0.1f;
    	leg_angle += 0.1f;
        x_position -= 0.1f;
		z_position += 0.1f;
    	}else{
    		walking3 = false;
			walking4 = true;
    	}
	}else if(walking4){
		rotation_angle_y = -90.0f;
		if (x_position <15.0f)
			outing = true;
		
		if (x_position > -20.0f) {
    	arm_angle += 0.1f;
    	leg_angle += 0.1f;
        x_position -= 0.1f;
    	}
    	if (z_position >0.0f) {
    	arm_angle += 0.1f;
    	leg_angle += 0.1f;
        z_position -= 0.1f;
    	}
    	if(x_position <= -20.f){
    		inside = false;
    		
    		walking4 = false;
			x_position = 19.0f;
    		walking5 = true; 
		}
	}else if(walking5){
		if (x_position > 5.0f) {
    	arm_angle += 0.1f;
    	leg_angle += 0.1f;
        x_position -= 0.1f;
    	}
    	if (z_position >0.0f) {
    	arm_angle += 0.1f;
    	leg_angle += 0.1f;
        z_position -= 0.1f;
    	}
    	if(x_position <= 5.0f){
    		walking5 = false;
    		fly = true;
		} 
	}else if(fly){
		if (x_position > -6.0f) {
        x_position -= 0.1f;
    	}
    	if (y_position < 9.0f) {
        y_position += 0.1f;
    	}
    	if(y_position>=9.0f){
    		fly = false;
    		landing = true;
		}
	}
	else if(landing){

    	if (y_position > -3.3f) {
        y_position -= 0.05f;
    	}

	}

    
    

    // Redraw the scene
    glutPostRedisplay();

    // Register the update function to be called again after 16 milliseconds
    glutTimerFunc(16, update, 0);
}



void display(void) // Here's Where We Do All The Drawing
{
    // TODO:
    // Place light source here
    setLight0(Light0);

    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    if (!inside) {
        glClearColor(0.529f, 0.808f, 0.922f, 1.0f); // ÃÏ¿∂…´
    } else {
        // ∆‰À˚◊¥Ã¨œ¬µƒ±≥æ∞…´
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // ∫⁄…´
    }
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);//texture

    // TODO:
    // Draw walls and objects here
    draw_wall();
    draw_window();
    draw_light();
    draw_tv();

    /*testcode1();*/
    draw_tvdesk();
    draw_seat();
    draw_bed();
    draw_closet();
    draw_taideng();
    draw_clock(); 
	draw_people();
	draw_door();
	draw_grass_land();
	draw_pool();
	draw_flowerbed();
	draw_tree();
    glutSwapBuffers();

}

void reshape(int w, int h) // Resize the GL Window. w=width, h=height
{
    if (h == 0) h = 1;
    WinWidth = w;
    WinHeight = h;

    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(60, (GLfloat)w / (GLfloat)h, 1.0, 100.0);
    gluLookAt(eye[0], eye[1], eye[2], eobj[0], eobj[1], eobj[2], 0.0, 1.0, 0.0);
}

void init(void) 
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);

    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_POINT_SMOOTH);
    glEnable(GL_LINE_SMOOTH);

    //texture mapping
    makeCheckImages();
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    glGenTextures(1, &texName);
    glBindTexture(GL_TEXTURE_2D, texName);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, checkImageWidth,checkImageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, checkImage);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

}

int main(int argc, char** argv)
{
    int width = 600, height = 350;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

    glutInitWindowSize(width, height);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Add furnitures");

    init();    

    glutReshapeFunc(reshape);
    glutDisplayFunc(display);

    glutTimerFunc(16, update, 0);  // Initialize the timer function

    glutMainLoop();

    return 0;
}



