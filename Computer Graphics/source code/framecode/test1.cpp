// 提示：在合适的地方修改或添加代码
#include "geomodeling.h"
#include "test1.h"
extern bool inside;
//bed
void draw_bed(void)
{
	if(inside){
	
    // Set materials
    glMaterialfv(GL_FRONT, GL_AMBIENT, matBrown);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, matBrown);
    glMaterialfv(GL_FRONT, GL_SPECULAR, matWhite);
    glMaterialf(GL_FRONT, GL_SHININESS, matShininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, matBlack);

    /********** begin your code below*************/        

    // Draw the headboard
    glColor3f(0.f, 0.54f, 0.5f);
    glPushMatrix();
    glTranslatef(0, -7, -19.5); 
    glScalef(12, 6, 1); 
    glutSolidCube(1);
    glPopMatrix();

    // Draw the bed frame
    glColor3f(1.f, 0.54f, 0.5f);
    glPushMatrix();
    glTranslatef(0, -9.25, -10.5); 
    glScalef(12, 1.5, 14); 
    glutSolidCube(1);
    glPopMatrix();

    // Set line width for the border
    glLineWidth(2);

    // Draw the white border for the headboard
    glColor3f(1.0f, 1.0f, 1.0f); // White color
    glPushMatrix();
    glTranslatef(0, -7, -19.5);
    glScalef(12, 6, 1);
    glutWireCube(1);
    glPopMatrix();

    // Draw the white border for the bed frame
    glColor3f(1.0f, 1.0f, 1.0f); // White color
    glPushMatrix();
    glTranslatef(0, -9.25, -10.5);
    glScalef(12, 1.5, 14);
    glutWireCube(1);
    glPopMatrix();

    /***********end your code here****************/
	}
}


//台灯+床头柜
void draw_taideng(void)
{
	if(inside){
    GLUquadric *obj;
    obj = gluNewQuadric();
    glColor3f(1, 0, 1);
    glMaterialfv(GL_FRONT, GL_AMBIENT, matBrown);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, matBrown);
    glMaterialfv(GL_FRONT, GL_SPECULAR, matBlack);
    glMaterialfv(GL_FRONT, GL_SHININESS, matBlack);
    glMaterialfv(GL_FRONT, GL_EMISSION, matBlack);
    if(Light2)
        glMaterialfv(GL_FRONT, GL_EMISSION, matBrown);

    /********** begin your code below *************/
    glColor3f(1, 0.6, 0.3);

    // Draw the solid cube
    glPushMatrix();
    glTranslatef(8, -8.5, -18.5); 
    glScalef(3, 3, 3); 
    glutSolidCube(1);
    glPopMatrix();

    // Draw the black border
    glLineWidth(2.0);
    glColor3f(0, 0, 0); // Set the color to black
    glPushMatrix();
    glTranslatef(8, -8.5, -18.5); 
    glScalef(3, 3, 3); 
    glutWireCube(1);
    glPopMatrix();

    // Draw two black points
    glPointSize(5.0);
    glColor3f(0, 0, 0); // Set the color to black
    glBegin(GL_POINTS);
        glVertex3f(8 + 0.5, -8.5, -16.99); // Right point
        glVertex3f(8 - 0.5, -8.5, -16.99); // Left point
    glEnd();


    glColor3f(1, 0, 1); // Set color to magenta
    glPushMatrix();
    glTranslatef(8, -4.5, -18.5); // Translate to the position where you want to draw the cone
    glRotatef(-90, 1, 0, 0);
    glutSolidCone(1.5, 2, 16, 16); // Draw a solid cone
    glPopMatrix();

    glColor3f(0, 0, 0); // Set color to black
    glPushMatrix();
    
    glTranslatef(8,-7, -18.5); // 平移圆柱体到所需位置
    glRotatef(-90, 1, 0, 0); // 旋转使得圆柱体朝向 y 轴方向
    gluCylinder(obj, 0.5, 0.2, 2.5, 40, 40); // 绘制圆柱体
    glPopMatrix();

    /*********** end your code here ****************/



    gluDeleteQuadric(obj);
	}
}

void draw_tvdesk(void)
{
	if(inside){
    glMaterialfv(GL_FRONT, GL_AMBIENT, matBrown);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, matBrown);
    glMaterialfv(GL_FRONT, GL_SPECULAR, matWhite);
    glMaterialf(GL_FRONT, GL_SHININESS, matShininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, matBlack);    
    
    glColor3f(1, 0.6, 0.3);

    // Draw the top desk board (上层桌面板)
    glPushMatrix();
    glTranslatef(18.2, -4, -9.2); // Position the desk top, tight against the right wall
    glScalef(3.6, 0.4, 8.4); // Dimensions: 3.6 (X) x 0.4 (Y) x 8.4 (Z)
    glutSolidCube(1);
    glPopMatrix();

    // Draw the bottom desk board (下层桌面板)
    glPushMatrix();
    glTranslatef(18.2, -7.4, -9.2); // Position the bottom desk board, tight against the right wall
    glScalef(3.6, 0.4, 8.4); // Dimensions: 3.6 (X) x 0.4 (Y) x 8.4 (Z)
    glutSolidCube(1);
    glPopMatrix();

    // Draw the lower side panels (上部板)
    glPushMatrix();
    glTranslatef(18.2, -5.8, -9.2); // Position the lower side panels, tight against the right wall
    glScalef(3.6, 3.6, 0.4); // Dimensions: 3.6 (X) x 2.0 (Y) x 0.4 (Z)
    glutSolidCube(1);
    glPopMatrix();


        // Draw the lower side panels (上部板)
    glPushMatrix();
    glTranslatef(18.2, -5.8, -5.2); // Position the lower side panels, tight against the right wall
    glScalef(3.6, 3.6, 0.4); // Dimensions: 3.6 (X) x 2.0 (Y) x 0.4 (Z)
    glutSolidCube(1);
    glPopMatrix();
        // Draw the lower side panels (上部板)
    glPushMatrix();
    glTranslatef(18.2, -5.8, -13.2); // Position the lower side panels, tight against the right wall
    glScalef(3.6, 3.6, 0.4); // Dimensions: 3.6 (X) x 2.0 (Y) x 0.4 (Z)
    glutSolidCube(1);
    glPopMatrix();

    // Draw the lower side panels (下部板)
    glPushMatrix();
    glTranslatef(18.2, -8.8, -13.2); // Position the lower side panels, tight against the right wall
    glScalef(3.6, 2.4, 0.4); // Dimensions: 3.6 (X) x 2.0 (Y) x 0.4 (Z)
    glutSolidCube(1);
    glPopMatrix();
        // Draw the lower side panels (下部板)
    glPushMatrix();
    glTranslatef(18.2, -8.8, -5.2); // Position the lower side panels, tight against the right wall
    glScalef(3.6, 2.4, 0.4); // Dimensions: 3.6 (X) x 2.0 (Y) x 0.4 (Z)
    glutSolidCube(1);
    glPopMatrix();
	}

}
extern float chair_position;
void draw_seat() {
	if(inside){
    glMaterialfv(GL_FRONT, GL_AMBIENT, matBrown);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, matBrown);
    glMaterialfv(GL_FRONT, GL_SPECULAR, matWhite);
    glMaterialf(GL_FRONT, GL_SHININESS, matShininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, matBlack);
    GLUquadric *obj;
    obj = gluNewQuadric();

    glColor3f(1, 0.6, 0.3);
    glPushMatrix();
    glTranslatef(chair_position, -7.25, -7.5); // Position the seat
    glScalef(3, 0.5, 3); // Dimensions: 3 (X) x 0.5 (Y) x 3 (Z)
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(chair_position+1, -10, -8.5);
    glRotatef(-90, 1, 0, 0);
    gluCylinder(obj, 0.2, 0.2, 2.5, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(chair_position+1, -10, -6.5);
    glRotatef(-90, 1, 0, 0);
    gluCylinder(obj, 0.2, 0.2, 2.5, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(chair_position-1, -10, -6.5);
    glRotatef(-90, 1, 0, 0);
    gluCylinder(obj, 0.2, 0.2, 2.5, 10, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(chair_position-1, -10, -8.5);
    glRotatef(-90, 1, 0, 0);
    gluCylinder(obj, 0.2, 0.2, 2.5, 10, 10);
    glPopMatrix();

    gluDeleteQuadric(obj);
	}
}


//closet
void draw_closet(void)
{
	if(inside){
    glMaterialfv(GL_FRONT, GL_AMBIENT, matBrown);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, matBrown);
    glMaterialfv(GL_FRONT, GL_SPECULAR, matWhite);
    glMaterialf(GL_FRONT, GL_SHININESS, matShininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, matBlack);

    /********** begin your code below *************/
    // Draw the closet
    glColor3f(1, 0.6, 0.3);
    glPushMatrix();
    glTranslatef(-18, -3, -17); // Position the desk top, tight against the right wall
    glScalef(4, 14, 6); // Dimensions: 4 (X) x 14 (Y) x 6 (Z)
    glutSolidCube(1);
    glPopMatrix();

    // Draw the black border
    glLineWidth(2.0);
    glColor3f(0, 0, 0); // Set the color to black
    glPushMatrix();
    glTranslatef(-18, -3, -17); // Position the border the same as the closet
    glScalef(4, 14, 6); // Dimensions: 4 (X) x 14 (Y) x 6 (Z)
    glutWireCube(1);
    glPopMatrix();

    // Draw a vertical black line on the right side of the closet
    glLineWidth(1.0);
    glColor3f(0, 0, 0); // Set the color to black
    glBegin(GL_LINES);
        // Line from bottom to top on the right side of the cube
        glVertex3f(-16, -10, -17); // Bottom point of the line
        glVertex3f(-16, 4, -17);   // Top point of the line
    glEnd();

    glColor3f(0, 0, 0);
    glPushMatrix();
    glTranslatef(-15.9, -3, -17.7); // Position the desk top, tight against the right wall
    glScalef(0.2, 2, 0.2); // Dimensions: 4 (X) x 14 (Y) x 6 (Z)
    glutSolidCube(1);
    glPopMatrix();


    glColor3f(0, 0, 0);
    glPushMatrix();
    glTranslatef(-15.9, -3, -16.3); // Position the desk top, tight against the right wall
    glScalef(0.2, 2, 0.2); // Dimensions: 4 (X) x 14 (Y) x 6 (Z)
    glutSolidCube(1);
    glPopMatrix();
    /*********** end your code here ****************/
	}
}

