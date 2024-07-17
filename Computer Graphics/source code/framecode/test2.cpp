#include "test2.h"
#include <time.h>
extern bool inside;
// 提示：在合适的地方修改或添加代码
void draw_clock(void)
{
	if(inside){
    // 获取当前时间
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    int hours = timeinfo->tm_hour;
    int minutes = timeinfo->tm_min;
    int seconds = timeinfo->tm_sec;

    // 计算每个指针的旋转角度
    float hour_angle = (hours % 12 + minutes / 60.0) * -30.0;  // 每小时30度
    float minute_angle = (minutes + seconds / 60.0) * -6.0;    // 每分钟6度
    float second_angle = seconds * -6.0;                       // 每秒6度

    //========begin========
    // Draw the outer disk
    glPushMatrix();
    glTranslatef(0.0, 4.0, -19.9);
    glColor3f(1, 0.6, 0.3);
    GLUquadric* obj = gluNewQuadric();
    gluDisk(obj, 3, 3.5, 20, 4);

    // Draw the inner disk
    glColor3f(0.25, 0.25, 0.25);
    gluDisk(obj, 0, 3, 20, 4);
    gluDeleteQuadric(obj);
    glPopMatrix();

    // Draw clock face tick marks
    glPushMatrix();
    glTranslatef(0.0, 4.0, -19.8); // Move the clock slightly forward
    glColor3f(1, 1, 1); // White color for tick marks
    for (int i = 0; i < 60; i++) {
        glPushMatrix();
        glRotatef(i * 6, 0.0, 0.0, 1.0); // Rotate to each tick mark
        if (i % 5 == 0) {
            glLineWidth(4.0); // Thicker lines for hour marks
            glTranslatef(0.0, 2.0, 0.0); // Move to the edge of the inner circle (2 units from the center)
            glBegin(GL_LINES);
                glVertex2f(0.0, 0.0);
                glVertex2f(0.0, 1.0); // Length for hour marks
            glEnd();
        } else {
            glLineWidth(2.0); // Thinner lines for minute marks
            glTranslatef(0.0, 2.5, 0.0); // Move to the edge of the inner circle (2.5 units from the center)
            glBegin(GL_LINES);
                glVertex2f(0.0, 0.0);
                glVertex2f(0.0, 0.5); // Length for minute marks
            glEnd();
        }
        glPopMatrix();
    }
    glPopMatrix();

    // Draw clock hands
    glPushMatrix();
    glTranslatef(0.0, 4.0, -19.7); // Move the hands slightly forward
    glColor3f(1, 1, 1); // White color for the hands

    // Draw hour hand
    glPushMatrix();
    glRotatef(hour_angle, 0.0, 0.0, 1.0); // Rotate to the current hour angle
    glLineWidth(3.0);
    glBegin(GL_LINES);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.0, 1.5); // Length is 1.5 units
    glEnd();
    glPopMatrix();

    // Draw minute hand
    glPushMatrix();
    glRotatef(minute_angle, 0.0, 0.0, 1.0); // Rotate to the current minute angle
    glLineWidth(3.0);
    glBegin(GL_LINES);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.0, 1.8); // Length is 1.8 units
    glEnd();
    glPopMatrix();

    // Draw second hand
    glPushMatrix();
    glRotatef(second_angle, 0.0, 0.0, 1.0); // Rotate to the current second angle
    glLineWidth(2.0);
    glBegin(GL_LINES);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.0, 2.1); // Length is 2.1 units
    glEnd();
    glPopMatrix();

    glPopMatrix();

    //=========end=========
	}
}


