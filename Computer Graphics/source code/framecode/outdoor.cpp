#include <GL/freeglut.h>
#include <stdlib.h>
#include "geomodeling.h"
#include "outdoor.h"

extern bool outing;
extern bool inside;
extern bool landing;
void draw_door() {
    if (outing && inside) {
        // 设置材质属性
        glMaterialfv(GL_FRONT, GL_AMBIENT, matGreen);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, matGreen);
        glMaterialfv(GL_FRONT, GL_SPECULAR, matWhite);
        glMaterialf(GL_FRONT, GL_SHININESS, matShininess);
        glMaterialfv(GL_FRONT, GL_EMISSION, matBlack);
        
        // 绘制门
        glBegin(GL_QUADS);
        glColor3f(0.529f, 0.808f, 0.922f); // 天蓝色
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
    // 使用绿色来绘制草地
    glColor3f(0, 1, 0);

    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex3f(-x,-y, -z);
    glTexCoord2f(0.0, 1.0); glVertex3f(-x,-y,  0);
    glTexCoord2f(1.0, 1.0); glVertex3f( x,-y,  0);
    glTexCoord2f(1.0, 0.0); glVertex3f( x,-y, -z);
    glEnd();	
	} 


}

// 绘制树
void draw_tree() {
		if(!inside){    glColor3f(0.5, 0.35, 0.05); // 设置树干颜色为棕色

    // 绘制树干
    glPushMatrix();
    glTranslatef(-18, -7, -5.0); // 将树干移到底部
    glScalef(1.0, 6, 1.0); // 设置树干的尺寸
    glutSolidCube(1.0); // 绘制树干
    glPopMatrix();

    // 绘制树叶
    glColor3f(0.0, 0.6, 0.0); // 设置树叶颜色为绿色
    glPushMatrix();
    glTranslatef(-18, -5, -5.0); // 将树叶移到树干顶部

    // 设置树叶的半径
    float leafRadius = 1.5;

    // 设置树叶的间隔角度
    float angleStep = 360.0 / 5; // 5表示五个树叶

    // 绘制五个树叶，相互重叠在树干周围
    for (int i = 0; i < 5; ++i) {
        glPushMatrix();
        float angle = i * angleStep;
        float x = leafRadius * cos(angle * 3.14159 / 180.0);
        float y = leafRadius * sin(angle * 3.14159 / 180.0);
        glTranslatef(x, y, 0.0);
        glutSolidSphere(1.5, 16, 16); // 绘制树叶
        glPopMatrix();
    }
    glPopMatrix();
        glColor3f(0.5, 0.35, 0.05); // 设置树干颜色为棕色
		
	} 



}



// 绘制花丛
void draw_flowerbed() {
		if(!inside){    
	for(int num=0;num<6;num++){
		glColor3f(1.0, 0.0, 0.0); // 设置花的颜色为红色
		// 绘制花
	    glPushMatrix();
	    glTranslatef(-15.0, -10.0, -10.0-(num*3)); // 将花移到指定位置
	    glutSolidSphere(1.0, 16, 16); // 绘制花的中心
	    glColor3f(1.0, 1.0, 0.0); // 设置花瓣的颜色为黄色
	    for (int i = 0; i < 8; i++) { // 绘制花瓣
	        glRotatef(45.0, 0.0, 1.0, 0.0);
	        glTranslatef(0.0, 0.0, 1.0);
	        glutSolidSphere(0.5, 16, 16);
	        glTranslatef(0.0, 0.0, -1.0);
	    }
	    glPopMatrix();	
	} 
	for(int num=0;num<6;num++){
		glColor3f(1.0, 0.0, 0.0); // 设置花的颜色为红色
		// 绘制花
	    glPushMatrix();
	    glTranslatef(-19.0, -10.0, -10.0-(num*3)); // 将花移到指定位置
	    glutSolidSphere(1.0, 16, 16); // 绘制花的中心
	    glColor3f(1.0, 1.0, 0.0); // 设置花瓣的颜色为黄色
	    for (int i = 0; i < 8; i++) { // 绘制花瓣
	        glRotatef(45.0, 0.0, 1.0, 0.0);
	        glTranslatef(0.0, 0.0, 1.0);
	        glutSolidSphere(0.5, 16, 16);
	        glTranslatef(0.0, 0.0, -1.0);
	    }
	    glPopMatrix();	
	} 
		
	} 

    
    
}



// 绘制泳池
// 绘制泳池
void draw_pool() {
		if(!inside){    // 绘制泳池水面
     glColor3f(0.1,0.22 , 1);// 浅蓝色
    glBegin(GL_QUADS);
    glVertex3f(-4.5, -9, -7);  // 注意 z 坐标修改为 -7
    glVertex3f(4.5, -9, -7);   // 注意 z 坐标修改为 -7
    glVertex3f(4.5, -9, 1);    // 注意 z 坐标修改为 1
    glVertex3f(-4.5, -9, 1);   // 注意 z 坐标修改为 1
    glEnd();

    // 绘制泳池边框
    glColor3f(1.0, 1.0, 1.0); // 白色
    glLineWidth(2.0); // 设置线宽
    glBegin(GL_LINE_LOOP);
    glVertex3f(-4.5, -9, -7);  // 注意 z 坐标修改为 -7
    glVertex3f(4.5, -9, -7);   // 注意 z 坐标修改为 -7
    glVertex3f(4.5, -9, 1);    // 注意 z 坐标修改为 1
    glVertex3f(-4.5, -9, 1);   // 注意 z 坐标修改为 1
    glEnd();
		
	} 

}


