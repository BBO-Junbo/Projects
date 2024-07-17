#include <GL/freeglut.h>
#include <stdlib.h>
#include "geomodeling.h"
#include "outdoor.h"

extern bool outing;
extern bool inside;
extern bool landing;
void draw_door() {
    if (outing && inside) {
        // ���ò�������
        glMaterialfv(GL_FRONT, GL_AMBIENT, matGreen);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, matGreen);
        glMaterialfv(GL_FRONT, GL_SPECULAR, matWhite);
        glMaterialf(GL_FRONT, GL_SHININESS, matShininess);
        glMaterialfv(GL_FRONT, GL_EMISSION, matBlack);
        
        // ������
        glBegin(GL_QUADS);
        glColor3f(0.529f, 0.808f, 0.922f); // ����ɫ
        glVertex3f(-19, -10, -5);
        glVertex3f(-19, -10, 5);
        glVertex3f(-19, 0, 5);
        glVertex3f(-19, 0, -5);
        glEnd();
    }
}



void draw_grass_land(){
	if(!inside){
	    GLfloat x = 100;
    GLfloat y = 10;
    GLfloat z = 40;
    // ʹ����ɫ�����Ʋݵ�
    glColor3f(0, 1, 0);

    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex3f(-x,-y, -z);
    glTexCoord2f(0.0, 1.0); glVertex3f(-x,-y,  0);
    glTexCoord2f(1.0, 1.0); glVertex3f( x,-y,  0);
    glTexCoord2f(1.0, 0.0); glVertex3f( x,-y, -z);
    glEnd();	
	} 


}

// ������
void draw_tree() {
		if(!inside){    glColor3f(0.5, 0.35, 0.05); // ����������ɫΪ��ɫ

    // ��������
    glPushMatrix();
    glTranslatef(-18, -7, -5.0); // �������Ƶ��ײ�
    glScalef(1.0, 6, 1.0); // �������ɵĳߴ�
    glutSolidCube(1.0); // ��������
    glPopMatrix();

    // ������Ҷ
    glColor3f(0.0, 0.6, 0.0); // ������Ҷ��ɫΪ��ɫ
    glPushMatrix();
    glTranslatef(-18, -5, -5.0); // ����Ҷ�Ƶ����ɶ���

    // ������Ҷ�İ뾶
    float leafRadius = 1.5;

    // ������Ҷ�ļ���Ƕ�
    float angleStep = 360.0 / 5; // 5��ʾ�����Ҷ

    // ���������Ҷ���໥�ص���������Χ
    for (int i = 0; i < 5; ++i) {
        glPushMatrix();
        float angle = i * angleStep;
        float x = leafRadius * cos(angle * 3.14159 / 180.0);
        float y = leafRadius * sin(angle * 3.14159 / 180.0);
        glTranslatef(x, y, 0.0);
        glutSolidSphere(1.5, 16, 16); // ������Ҷ
        glPopMatrix();
    }
    glPopMatrix();
        glColor3f(0.5, 0.35, 0.05); // ����������ɫΪ��ɫ
		
	} 



}



// ���ƻ���
void draw_flowerbed() {
		if(!inside){    
	for(int num=0;num<6;num++){
		glColor3f(1.0, 0.0, 0.0); // ���û�����ɫΪ��ɫ
		// ���ƻ�
	    glPushMatrix();
	    glTranslatef(-15.0, -10.0, -10.0-(num*3)); // �����Ƶ�ָ��λ��
	    glutSolidSphere(1.0, 16, 16); // ���ƻ�������
	    glColor3f(1.0, 1.0, 0.0); // ���û������ɫΪ��ɫ
	    for (int i = 0; i < 8; i++) { // ���ƻ���
	        glRotatef(45.0, 0.0, 1.0, 0.0);
	        glTranslatef(0.0, 0.0, 1.0);
	        glutSolidSphere(0.5, 16, 16);
	        glTranslatef(0.0, 0.0, -1.0);
	    }
	    glPopMatrix();	
	} 
	for(int num=0;num<6;num++){
		glColor3f(1.0, 0.0, 0.0); // ���û�����ɫΪ��ɫ
		// ���ƻ�
	    glPushMatrix();
	    glTranslatef(-19.0, -10.0, -10.0-(num*3)); // �����Ƶ�ָ��λ��
	    glutSolidSphere(1.0, 16, 16); // ���ƻ�������
	    glColor3f(1.0, 1.0, 0.0); // ���û������ɫΪ��ɫ
	    for (int i = 0; i < 8; i++) { // ���ƻ���
	        glRotatef(45.0, 0.0, 1.0, 0.0);
	        glTranslatef(0.0, 0.0, 1.0);
	        glutSolidSphere(0.5, 16, 16);
	        glTranslatef(0.0, 0.0, -1.0);
	    }
	    glPopMatrix();	
	} 
		
	} 

    
    
}



// ����Ӿ��
// ����Ӿ��
void draw_pool() {
		if(!inside){    // ����Ӿ��ˮ��
     glColor3f(0.1,0.22 , 1);// ǳ��ɫ
    glBegin(GL_QUADS);
    glVertex3f(-4.5, -9, -7);  // ע�� z �����޸�Ϊ -7
    glVertex3f(4.5, -9, -7);   // ע�� z �����޸�Ϊ -7
    glVertex3f(4.5, -9, 1);    // ע�� z �����޸�Ϊ 1
    glVertex3f(-4.5, -9, 1);   // ע�� z �����޸�Ϊ 1
    glEnd();

    // ����Ӿ�ر߿�
    glColor3f(1.0, 1.0, 1.0); // ��ɫ
    glLineWidth(2.0); // �����߿�
    glBegin(GL_LINE_LOOP);
    glVertex3f(-4.5, -9, -7);  // ע�� z �����޸�Ϊ -7
    glVertex3f(4.5, -9, -7);   // ע�� z �����޸�Ϊ -7
    glVertex3f(4.5, -9, 1);    // ע�� z �����޸�Ϊ 1
    glVertex3f(-4.5, -9, 1);   // ע�� z �����޸�Ϊ 1
    glEnd();
		
	} 

}


