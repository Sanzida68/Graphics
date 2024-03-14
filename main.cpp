#include <iostream>
#include<GL/gl.h>
#ifdef __APPLE__
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <bits/stdc++.h>
#include<GL/gl.h>

#include<math.h>

using namespace std;
float windMillScalingFactor = 1;
float car1ScalingFactor = 1;
float car2ScalingFactor = 1;
float busScalingFactor = 1;

float car1MovingFactor = 0.05718;
float car2MovingFactor = -0.05318;

const int width = 1000;
const int height = 1000;

GLfloat eyeX = 13.5;
GLfloat eyeY = 30.79;
GLfloat eyeZ = 103.29;

GLfloat lookX = 20.0;
GLfloat lookY = 12.0;
GLfloat lookZ = -4;

bool moveCamera = false;


static void key(unsigned char key, int x, int y)
{
    float switchSpeed = 0.5;
    switch (key)
    {


    case 'd':
        eyeX=eyeX+switchSpeed;
        printf("eye x = %f \n", eyeX);
        break;
    case 'a':
        eyeX=eyeX-switchSpeed;
        printf("eye x = %f \n", eyeX);
    break;
    case 'w':
        eyeY=eyeY+switchSpeed;
        printf("eye y = %f\n", eyeY);
        break;
    case 's':
        eyeY=eyeY-switchSpeed;
        printf("eye y = %f\n", eyeY);
        break;
    case '1':
        eyeZ=eyeZ+switchSpeed;
        printf("eye z = %f\n", eyeZ);
        break;
    case '2':
        eyeZ=eyeZ-switchSpeed;
        printf("eye z = %f\n", eyeZ);
        break;


    case 'i':
        lookX=lookX+switchSpeed;
        printf("L X = %f\n", lookX);
    break;
    case 'j':
        lookX=lookX-switchSpeed;
        printf("L X = %f\n", lookX);
    break;
    case 'o':
        lookY=lookY+switchSpeed;
        printf("L Y = %f\n", lookY);
        break;
    case 'k':
        lookY=lookY-switchSpeed;
        printf("L Y = %f\n", lookY);
        break;
    case 'p':
        lookZ=lookZ+switchSpeed;
        printf("L Z = %f\n", lookZ);
        break;
    case 'l':
        lookZ=lookZ-switchSpeed;
        printf("L Z = %f\n", lookZ);
        break;

    case 'f':
       moveCamera = !moveCamera;
       break;
    case 'r':
        moveCamera = false;
        eyeX = 13.5;
        eyeY = 30.79;
        eyeZ = 103.29;
       break;
    case 'z':
        if(windMillScalingFactor == 1) {
        windMillScalingFactor = 0;
        } else {
        windMillScalingFactor = 1;
        }
        break;
    case 'x':
        if(car1ScalingFactor == 1) {
        car1ScalingFactor = 0;
        } else {
        car1ScalingFactor = 1;
        }
        break;

    case 'c':
        if(busScalingFactor == 1) {
        busScalingFactor = 0;
        } else {
        busScalingFactor = 1;
        }
        break;


    case 'v':
        if(car2ScalingFactor == 1) {
        car2ScalingFactor = 0;
        } else {
        car2ScalingFactor = 1;
        }
        break;


        //float car1MovingFactor = 0.05718;
//float car2MovingFactor = -0.05318;

    }


    glutPostRedisplay();
}


static GLfloat v_cube[8][3] =
{
    {0,0,0},
    {0,0,1},
    {0,1,0},
    {0,1,1},

    {1,0,0},
    {1,0,1},
    {1,1,0},
    {1,1,1}
};

static GLubyte c_ind[6][4] =
{
    {0,2,6,4},
    {1,5,7,3},
    {0,4,5,1},
    {2,3,7,6},
    {0,1,3,2},
    {4,6,7,5}
};

static void getNormal3p(GLfloat x1, GLfloat y1, GLfloat z1, GLfloat x2, GLfloat y2, GLfloat z2, GLfloat x3, GLfloat y3, GLfloat z3)
{
    GLfloat Ux, Uy, Uz, Vx, Vy, Vz, Nx, Ny, Nz;

    Ux = x2-x1;
    Uy = y2-y1;
    Uz = z2-z1;

    Vx = x3-x1;
    Vy = y3-y1;
    Vz = z3-z1;

    Nx = Uy*Vz - Uz*Vy;
    Ny = Uz*Vx - Ux*Vz;
    Nz = Ux*Vy - Uy*Vx;

    glNormal3f(Nx,Ny,Nz);
}

void cube(float r,float g,float b)
{

    glBegin(GL_QUADS);
    glColor3d(r,g,b);
    for (GLint i = 0; i <6; i++)
    {
        getNormal3p(v_cube[c_ind[i][0]][0], v_cube[c_ind[i][0]][1], v_cube[c_ind[i][0]][2],
                    v_cube[c_ind[i][1]][0], v_cube[c_ind[i][1]][1], v_cube[c_ind[i][1]][2],
                    v_cube[c_ind[i][2]][0], v_cube[c_ind[i][2]][1], v_cube[c_ind[i][2]][2]);

        for (GLint j=0; j<4; j++)
        {
            glVertex3fv(&v_cube[c_ind[i][j]][0]);
        }
    }
    glEnd();
}


void circle(GLfloat xAxis, GLfloat yAxis, GLfloat zAxis, GLfloat radius, GLfloat rColor, GLfloat gColor, GLfloat bColor)
{
    glPushMatrix(); // Push the current matrix onto the stack
    glTranslatef(xAxis, yAxis, zAxis);

    glColor3f(rColor/255.0, gColor/255.0, bColor/255.0); // Red color used to draw.
    glutSolidSphere(radius, 20, 20);

    glPopMatrix(); // Pop the matrix from the stack to revert to the previous state
}




void createBaseField(){
//FIELD
    glPushMatrix();
    glTranslated(-332,0-12,-200);
    glScaled(680,1,380);
    cube(0.4,0.8,0.5);
    glPopMatrix();


//Sky
    glPushMatrix();
    glTranslated(-2032,-220,-200);
    glScaled(3500,1000,1);
    cube(100/255.0, 255/255.0,255/255.0);
    glPopMatrix();
}


void groundDoor()
{
    float xBasePosition = -44;
    float yBasePosition = -12.2;
    float zBasePosition = 50;

    // ground door
    glPushMatrix();
    glTranslated(xBasePosition+25, yBasePosition, zBasePosition+0.5);
    glScaled(10, 10, 1);
    cube(0.6, 0.4, 0.2);
    glPopMatrix();

    // unlocker
    circle(xBasePosition+26.6, yBasePosition+4.7, zBasePosition+1, 0.7, 244, 255, 244);

    // ground door
    glPushMatrix();
    glTranslated(xBasePosition+25, yBasePosition+0.4, zBasePosition+1.7);
    glScaled(10, 1, 1.3);
    cube(0.4, 0.4, 0.5);
    glPopMatrix();
}


    float pillarColorR = 0.961;
    float pillarColorG = 0.925;
    float pillarColorB= 0.902;

void groundFloor() {
    float xBasePosition = -45;
    float yBasePosition = 0-12;
    float zBasePosition = 50;



    float floorColorR = 0.82;
    float floorColorG = 0.663;
    float floorColorB = 0.573;

    float roofColorR = 0.961;
    float roofColorG = 0.925;
    float roofColorB = 0.902;



    // down floor wall 1
    glPushMatrix();
    glTranslated(xBasePosition,yBasePosition,zBasePosition);
    glScaled(40,12,1);
    cube(floorColorR,floorColorG,floorColorB);
    glPopMatrix();

    // down floor wall 2
    glPushMatrix();
    glTranslated(xBasePosition+40,yBasePosition,zBasePosition-15);
    glScaled(0,12,15);
    cube(floorColorR,floorColorG,floorColorB);
    glPopMatrix();


    // down floor wall 3
    glPushMatrix();
    glTranslated(xBasePosition,yBasePosition,zBasePosition-15);
    glScaled(40,12,1);
    cube(floorColorR,floorColorG,floorColorB);
    glPopMatrix();

    // down floor wall 4
    glPushMatrix();
    glTranslated(xBasePosition,yBasePosition,zBasePosition-15);
    glScaled(0,12,15);
    cube(floorColorR,floorColorG,floorColorB);
    glPopMatrix();


    // down floor pillar 1
    glPushMatrix();
    glTranslated(xBasePosition+58,yBasePosition,zBasePosition-15);
    glScaled(2,12,2);
    cube(pillarColorR,pillarColorG,pillarColorB);
    glPopMatrix();

    // down floor pillar 2
    glPushMatrix();
    glTranslated(xBasePosition+58,yBasePosition,zBasePosition-1.5);
    glScaled(2,12,2);
    cube(pillarColorR,pillarColorG,pillarColorB);
    glPopMatrix();

    // down floor roof
    glPushMatrix();
    glTranslated(xBasePosition,yBasePosition+12,zBasePosition-15);
    glScaled(60,0.1,16);
    cube(roofColorR,roofColorG,roofColorB);
    glPopMatrix();
}


void secondFloor() {
    float xBasePosition = -35;
    float yBasePosition = 0-12;
    float zBasePosition = 50;


    float floorColorR = 0.969;
    float floorColorG = 0.702;
    float floorColorB = 0.573;

    float roofColorR = 0.961;
    float roofColorG = 0.925;
    float roofColorB = 0.902;

    float balconyColorR = 0.969;
    float balconyColorG = 0.802;
    float balconyColorB = 0.573;
    // 2nd floor pillar 1
    glPushMatrix();
    glTranslated(xBasePosition+4,yBasePosition+12,zBasePosition-15);
    glScaled(2,10.5,2);
    cube(0.859,  0.682, 0.557);
    glPopMatrix();

    // 2nd floor pillar 2
    glPushMatrix();
    glTranslated(xBasePosition+4,yBasePosition+12,zBasePosition-2);
    glScaled(2,10.5,2);
    cube(0.859,  0.682, 0.557);
    glPopMatrix();

    // 2nd floor balcony wall 1
    glPushMatrix();
    glTranslated(xBasePosition+50,yBasePosition+12,zBasePosition-15);
    glScaled(1,5,16);
    cube(0.969,0.802,0.573);
    glPopMatrix();

    // 2nd floor balcony wall 2

    glPushMatrix();
    glTranslated(xBasePosition+39.5,yBasePosition+12,zBasePosition);
    glScaled(10.5,5,1);
    cube(balconyColorR,balconyColorG,balconyColorB);
    glPopMatrix();

    // 2nd floor balcony wall 3
    glPushMatrix();
    glTranslated(xBasePosition+39.5,yBasePosition+12,zBasePosition-15);
    glScaled(10.5,5,1);
    cube(balconyColorR,balconyColorG,balconyColorB);
    glPopMatrix();

    // floor room
    // 2nd floor wall 4
    glPushMatrix();
    glTranslated(xBasePosition+14,yBasePosition+12,zBasePosition-15);
    glScaled(1,10,15);
    cube(floorColorR,floorColorG,floorColorB);
    glPopMatrix();

    // 2nd floor wall 5
    glPushMatrix();
    glTranslated(xBasePosition+14,yBasePosition+12,zBasePosition-0.5);
    glScaled(26-0.5,10,1);
    cube(floorColorR,floorColorG,floorColorB);
    glPopMatrix();

    // 2nd floor wall 6
    glPushMatrix();
    glTranslated(xBasePosition+14,yBasePosition+12,zBasePosition-15-0.5);
    glScaled(26-0.5,10,1);
    cube(floorColorR,floorColorG,floorColorB);
    glPopMatrix();

    // 2nd floor wall 7
    glPushMatrix();
    glTranslated(xBasePosition+39,yBasePosition+12,zBasePosition-15-0.5);
    glScaled(1,10,15-0.5);
    cube(floorColorR,floorColorG,floorColorB);
    glPopMatrix();

    // 2nd floor roof
    glPushMatrix();
    glTranslated(xBasePosition+05,yBasePosition+22,zBasePosition-15-0.5);
    glScaled(35-0.5,1,16);
    cube(roofColorR, roofColorG, roofColorB);
    glPopMatrix();
}


void thirdFloor() {

    float xBasePosition = -31;
    float yBasePosition = 10-12;
    float zBasePosition = 50;


    float balconyColorR = 0.841;
    float balconyColorG = 0.884;
    float balconyColorB = 0.376;

    float floorColorR = 0.941;
    float floorColorG = 0.784;
    float floorColorB = 0.376;

    float roofColorR = 0.961;
    float roofColorG = 0.925;
    float roofColorB = 0.902;

    float roofColorR2 = 0.829;
    float roofColorG2 = 0.514;
    float roofColorB2 = 0.124;
    // 3rd floor balcony wall 1
    glPushMatrix();
    glTranslated(xBasePosition,yBasePosition+12,zBasePosition-15);
    glScaled(1,5,15);
    cube(balconyColorR,balconyColorG,balconyColorB);
    glPopMatrix();

    // 3rd floor balcony wall 2
    glPushMatrix();
    glTranslated(xBasePosition,yBasePosition+12,zBasePosition);
    glScaled(11,5,1);
    cube(balconyColorR,balconyColorG,balconyColorB);
    glPopMatrix();

    // 3rd floor balcony wall 3
    glPushMatrix();
    glTranslated(xBasePosition,yBasePosition+12,zBasePosition-15);
    glScaled(11,5,1);
    cube(balconyColorR,balconyColorG,balconyColorB);
    glPopMatrix();

    // floor room
    // 3rd floor wall 4
    glPushMatrix();
    glTranslated(xBasePosition+11,yBasePosition+12,zBasePosition-15);
    glScaled(1,10,16);
    cube(floorColorR,floorColorG,floorColorB);
    glPopMatrix();

    // 3rd floor wall 5
    glPushMatrix();
    glTranslated(xBasePosition+11,yBasePosition+12,zBasePosition);
    glScaled(14,10,1);
    cube(floorColorR,floorColorG,floorColorB);
    glPopMatrix();

    // 3rd floor wall 6
    glPushMatrix();
    glTranslated(xBasePosition+11,yBasePosition+12,zBasePosition-15);
    glScaled(14,10,1);
    cube(floorColorR,floorColorG,floorColorB);
    glPopMatrix();

    // 3rd floor wall 7
    glPushMatrix();
    glTranslated(xBasePosition+25,yBasePosition+12,zBasePosition-15);
    glScaled(1,10,16);
    cube(floorColorR,floorColorG,floorColorB);
    glPopMatrix();

    //3rd floor roof
    glPushMatrix();
    glTranslated(xBasePosition+11,yBasePosition+22,zBasePosition-15);
    glScaled(15,1,16);
    cube(roofColorR,roofColorG,roofColorB);
    glPopMatrix();


    //3rd floor roof pillar 1
    glPushMatrix();
    glTranslated(xBasePosition+11,yBasePosition+23,zBasePosition-15);
    glScaled(2,6,2);
    cube(pillarColorR,pillarColorG,pillarColorB);
    glPopMatrix();

    //3rd floor roof pillar 2
    glPushMatrix();
    glTranslated(xBasePosition+11,yBasePosition+23,zBasePosition-0.2);
    glScaled(1.2,6,1.2);
    cube(pillarColorR,pillarColorG,pillarColorB);
    glPopMatrix();

    //3rd floor roof 2
    glPushMatrix();
    glTranslated(xBasePosition+26.5,yBasePosition+23,zBasePosition-15);
    glRotatef(155, 0, 0, 1);
    glScaled(16.5,1,17);
    cube(roofColorR2,roofColorG2,roofColorB2);
    glPopMatrix();
}

void createGate()
{
    float xBasePosition = -31;
    float yBasePosition = 0-12;
    float zBasePosition = 50;


    // Front gate door
    glPushMatrix();
    glTranslated(xBasePosition +24, yBasePosition+1, zBasePosition+11);
    glScaled(25, 5, 1);
    cube(0.3, 0.1, 0.3);
    glPopMatrix();


    glPushMatrix();
    glTranslated(xBasePosition +26.5, yBasePosition+1, zBasePosition+12);
    glScaled(1.5, 5, 1);
    cube(0.7, 0.1, 0.1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(xBasePosition +45, yBasePosition+1, zBasePosition+12);
    glScaled(1.5, 5, 1);
    cube(0.7, 0.1, 0.1);
    glPopMatrix();
}


void createWalls() {

    float xBasePosition = -31;
    float yBasePosition = 0-12;
    float zBasePosition = 50;

    //wall <-
    glPushMatrix();
    glTranslated(xBasePosition-26.5,yBasePosition,zBasePosition-22);
    glScaled(1,6,35);
    cube(0.9,0.4,0.22);
    glPopMatrix();

    //wall back
    glPushMatrix();
    glTranslated(xBasePosition-26.5,yBasePosition,zBasePosition-23);
    glScaled(94,6,1);
    cube(0.9,0.4,0.22);
    glPopMatrix();


    //wall ->
    glPushMatrix();
    glTranslated(xBasePosition+66.5,yBasePosition,zBasePosition-22);
    glScaled(1,6,35);
    cube(0.9,0.4,0.22);
    glPopMatrix();



    //wall front <- part
    glPushMatrix();
    glTranslated(xBasePosition-26.5,yBasePosition,zBasePosition+12);
    glScaled(53,6,1);
    cube(0.9,0.4,0.22);
    glPopMatrix();


    glPushMatrix();
    glTranslated(xBasePosition+46.5,yBasePosition,zBasePosition+12);
    glScaled(20,6,1);
    cube(0.9,0.4,0.22);
    glPopMatrix();
}


void window(float xBasePosition, float yBasePosition, float zBasePosition, float rotateDegree, float rX, float rY, float rZ) {
    // total glass
    glPushMatrix();
    glTranslated(xBasePosition,yBasePosition,zBasePosition);
    glRotated(rotateDegree, rX, rY, rZ);
    glScaled(7,5,0.01);
    cube(0.6, 0.6, 1.0);
    glPopMatrix();

    // out line
    glPushMatrix();
    glTranslated(xBasePosition-0.5,yBasePosition-0.5,zBasePosition-0.2);
    glRotated(rotateDegree, rX, rY, rZ);
    glScaled(7.7,5.65,0.01);
    cube(0.9,0.9,0.9);
    glPopMatrix();

    float xPlus = 0.12;
    float zPlus = -3;

    if(rotateDegree == 0) {
        xPlus = 3.2;
        zPlus = 0.2;
    }
    // middle line
    glPushMatrix();
    glTranslated(xBasePosition+xPlus,yBasePosition+0.06,zBasePosition+zPlus);
    glRotated(rotateDegree, rX, rY, rZ);
    glScaled(0.7, 5.35,0.01);
    cube(0.9,0.9,0.9);
    glPopMatrix();
}

void createWindows() {
    float xBasePosition = -31;
    float yBasePosition = -8;
    float zBasePosition = 50;

    // ground window 1
    window(xBasePosition-8.5, yBasePosition+0.5, zBasePosition+2, 0, 0, 0, 0);
    // ground window 2
    window(xBasePosition+1.5, yBasePosition+0.5, zBasePosition+2, 0, 0, 0, 0);
    // 2nd floor window 1
    window(xBasePosition+14.5, yBasePosition+11.5, zBasePosition+2, 0, 0, 0, 0);
    // 2nd floor window 2
    window(xBasePosition+25.5, yBasePosition+11.5, zBasePosition+2, 0, 0, 0, 0);
    // 3rd floor window 1
    window(xBasePosition+15, yBasePosition+20.55, zBasePosition+2, 0, 0, 0, 0);
    // 3rd floor window 2
    window(xBasePosition+26.5, yBasePosition+20.65, zBasePosition-2, 89, 0, 1, 0);
}



void createDoors() {
    groundDoor();
}


void buildHouse() {
    groundFloor();
    secondFloor();
    thirdFloor();
    createWindows();
    createDoors();
    createWalls();
    createGate();
}


void buildPlayingField() {
    float xBasePosition = -31+98;
    float yBasePosition = 0.5-12;
    float zBasePosition = 50+1;

    //field base
    glPushMatrix();
    glTranslated(xBasePosition-26.5,yBasePosition,zBasePosition-22);
    glScaled(37,0.8,33);
    cube(0.192, 0.729, 0.122);
    glPopMatrix();

     //border up
    glPushMatrix();
    glTranslated(xBasePosition-26.5,yBasePosition,zBasePosition-22);
    glScaled(37,1,.80);
    cube(1,1,1);
    glPopMatrix();

    //border square top
    glPushMatrix();
    glTranslated(xBasePosition-14,yBasePosition,zBasePosition-14);
    glScaled(13.5,1,0.7);
    cube(1,1,1);
    glPopMatrix();

    //border square left
    glPushMatrix();
    glTranslated(xBasePosition-14,yBasePosition,zBasePosition-14);
    glRotated(+90,0,1,0);
    glScaled(8,1,0.7);
    cube(1,1,1);
    glPopMatrix();

    //border square right
    glPushMatrix();
    glTranslated(xBasePosition-1,yBasePosition,zBasePosition-14);
    glRotated(+90,0,1,0);
    glScaled(8,1,0.7);
    cube(1,1,1);
    glPopMatrix();

    // Border down
    glPushMatrix();
    glTranslated(xBasePosition-26.5,yBasePosition,zBasePosition+10.5);
    glScaled(37,1,.80);
    cube(1,1,1);
    glPopMatrix();

    //border square top
    glPushMatrix();
    glTranslated(xBasePosition-14,yBasePosition,zBasePosition+3);
    glScaled(13.5,1,0.7);
    cube(1,1,1);
    glPopMatrix();

    //border square left
    glPushMatrix();
    glTranslated(xBasePosition-14,yBasePosition,zBasePosition+3);
    glRotated(-90,0,1,0);
    glScaled(8,1,0.7);
    cube(1,1,1);
    glPopMatrix();

    //border square right
    glPushMatrix();
    glTranslated(xBasePosition,yBasePosition,zBasePosition+3);
    glRotated(-90,0,1,0);
    glScaled(8,1,0.7);
    cube(1,1,1);
    glPopMatrix();

    //middle line
    glPushMatrix();
    glTranslated(xBasePosition-26.5,yBasePosition,zBasePosition-4);
    glScaled(37,1,.30);
    cube(1,1,1);
    glPopMatrix();


    // Goal Post 1
    glPushMatrix();
    glTranslated(xBasePosition-4,yBasePosition,zBasePosition-22);
    glScaled(1,8,1);
    cube(0.85,0.85,0.85);
    glPopMatrix();

    glPushMatrix();
    glTranslated(xBasePosition-11,yBasePosition,zBasePosition-22);
    glScaled(1,8,1);
    cube(0.85,0.85,0.85);
    glPopMatrix();

    glPushMatrix();
    glTranslated(xBasePosition-11,yBasePosition+7,zBasePosition-22);
    glScaled(7,1,1);
    cube(0.85,0.85,0.85);
    glPopMatrix();

    // Goal Post 2

    glPushMatrix();
    glTranslated(xBasePosition-4,yBasePosition,zBasePosition+10);
    glScaled(1,8,1);
    cube(0.85,0.85,0.85);
    glPopMatrix();

    glPushMatrix();
    glTranslated(xBasePosition-11,yBasePosition,zBasePosition+10);
    glScaled(1,8,1);
    cube(0.85,0.85,0.85);
    glPopMatrix();


    glPushMatrix();
    glTranslated(xBasePosition-11,yBasePosition+7,zBasePosition+10);
    glScaled(7,1,1);
    cube(0.85,0.85,0.85);
    glPopMatrix();

    // sitting position
    glPushMatrix();
    glTranslated(xBasePosition+13.5,yBasePosition,zBasePosition-22);
    glScaled(2,1.5,33);
    cube(0.75,0.85,0.85);
    glPopMatrix();

    glPushMatrix();
    glTranslated(xBasePosition+15.5,yBasePosition,zBasePosition-22);
    glScaled(2,3,33);
    cube(0.75,0.55,0.85);
    glPopMatrix();

    glPushMatrix();
    glTranslated(xBasePosition+17.5,yBasePosition,zBasePosition-22);
    glScaled(2,5.5,33);
    cube(0.75,0.85,0.35);
    glPopMatrix();
}

void createHills() {

    float xBasePosition = -183;
    float yBasePosition = 0.5-12-14;
    float zBasePosition = -90;


    // hill 1
    glPushMatrix();
    glTranslated(xBasePosition-83,yBasePosition-35,zBasePosition-11);
    glRotated(40, 1, 0, 1);
    glScaled(105,55,1);
    cube(0.35,0.35,0.35);
    glPopMatrix();

    // hill 2
    glPushMatrix();
    glTranslated(xBasePosition-33,yBasePosition-30,zBasePosition-14);
    glRotated(40, 1, 0, 1);
    glScaled(115,55,1);
    cube(0.75,0.35,0.35);
    glPopMatrix();

    // hill 3
    glPushMatrix();
    glTranslated(xBasePosition+43,yBasePosition-30,zBasePosition-12);
    glRotated(47, 1, 0, 1);
    glScaled(115,55,1);
    cube(0.25,0.45,0.35);
    glPopMatrix();

    float rightShift = 172;
    // hill 4
    glPushMatrix();
    glTranslated(xBasePosition-83+rightShift+2,yBasePosition-38,zBasePosition-3);
    glRotated(46, 1, 0, 1);
    glScaled(105,55,1);
    cube(0.35,0.35,0.35);
    glPopMatrix();

    // hill 5
    glPushMatrix();
    glTranslated(xBasePosition+33+rightShift,yBasePosition-11,zBasePosition-44);
    glRotated(60, 1, 0, 1);
    glScaled(85,85,1);
    cube(0.75,0.35,0.35);
    glPopMatrix();

    // hill 6
    glPushMatrix();
    glTranslated(xBasePosition+88+rightShift,yBasePosition-38,zBasePosition+2);
    glRotated(45, 0, 0, 1);
    glScaled(75,75,1);
    cube(0.25,0.45,0.35);
    glPopMatrix();


    float rightShift2 = 350;
    // hill 7
    glPushMatrix();
    glTranslated(xBasePosition-83+rightShift2+57,yBasePosition-44,zBasePosition-3);
    glRotated(44, 0, 0, 1);
    glScaled(85,85,1);
    cube(0.35,0.35,0.35);
    glPopMatrix();

    // hill 8
    glPushMatrix();
    glTranslated(xBasePosition+33+rightShift2+72,yBasePosition-31,zBasePosition-44);
    glRotated(55, 0, 0, 1);
    glScaled(85,85,1);
    cube(0.75,0.35,0.35);
    glPopMatrix();

    // hill 9
    glPushMatrix();
    glTranslated(xBasePosition+88+rightShift2+20,yBasePosition-44,zBasePosition+2);
    glRotated(50, 0, 0, 1);
    glScaled(75,75,1);
    cube(0.25,0.45,0.35);
    glPopMatrix();
}

    float sunXPosition = -183;
    float sunYPosition = 45;
    float sunZPosition = -90;

    float cloud1XPosition = -190;
    float cloud1YPosition = 72;
    float cloud1ZPosition = -57;

    float cloud2XPosition = -253;
    float cloud2YPosition = 45;
    float cloud2ZPosition = -90;


    float cloud3XPosition = -100;

    float cloud4XPosition = 13;

void createSunAndCloud() {
    // sun
    circle(sunXPosition, sunYPosition, sunZPosition, 6, 255, 255, 0);

    // cloud 1
    circle(cloud1XPosition+14, cloud1YPosition, cloud1ZPosition, 5, 245, 255, 255);
    circle(cloud1XPosition+23, cloud1YPosition, cloud1ZPosition, 8, 255, 245, 235);
    circle(cloud1XPosition+32, cloud1YPosition, cloud1ZPosition, 5, 245, 255, 255);
    // cloud 2
    circle(cloud2XPosition+13, cloud2YPosition+13, cloud2ZPosition, 5, 245, 255, 255);
    circle(cloud2XPosition+22, cloud2YPosition+13.5, cloud2ZPosition, 8, 255, 245, 245);
    circle(cloud2XPosition+33, cloud2YPosition+13, cloud2ZPosition, 5, 245, 255, 255);


    // cloud 3
    circle(cloud3XPosition+14, cloud1YPosition-1.2, cloud1ZPosition, 5, 245, 255, 255);
    circle(cloud3XPosition+23, cloud1YPosition-1.2, cloud1ZPosition, 8, 255, 245, 235);
    circle(cloud3XPosition+32, cloud1YPosition-1.2, cloud1ZPosition, 5, 245, 255, 255);
    // cloud 4
    circle(cloud4XPosition+13, cloud2YPosition+13+1.5, cloud2ZPosition, 5, 245, 255, 255);
    circle(cloud4XPosition+22, cloud2YPosition+13.5+1.5, cloud2ZPosition, 8, 255, 245, 245);
    circle(cloud4XPosition+33, cloud2YPosition+13+1.5, cloud2ZPosition, 5, 245, 255, 255);


    float shiftX = 87;
    // cloud 1
    circle(cloud1XPosition+14-shiftX, cloud1YPosition, cloud1ZPosition, 5, 245, 255, 255);
    circle(cloud1XPosition+23-shiftX, cloud1YPosition, cloud1ZPosition, 8, 255, 245, 235);
    circle(cloud1XPosition+32, cloud1YPosition, cloud1ZPosition, 5, 245, 255, 255);
    // cloud 2
    circle(cloud2XPosition+13-shiftX, cloud2YPosition+13, cloud2ZPosition, 5, 245, 255, 255);
    circle(cloud2XPosition+22-shiftX, cloud2YPosition+13.5, cloud2ZPosition, 8, 255, 245, 245);
    circle(cloud2XPosition+33-shiftX, cloud2YPosition+13, cloud2ZPosition, 5, 245, 255, 255);


    // cloud 3
    circle(cloud3XPosition+14-shiftX, cloud1YPosition-1.2, cloud1ZPosition, 5, 245, 255, 255);
    circle(cloud3XPosition+23-shiftX, cloud1YPosition-1.2, cloud1ZPosition, 8, 255, 245, 235);
    circle(cloud3XPosition+32-shiftX, cloud1YPosition-1.2, cloud1ZPosition, 5, 245, 255, 255);
    // cloud 4
    circle(cloud4XPosition+13-shiftX, cloud2YPosition+13+1.5, cloud2ZPosition, 5, 245, 255, 255);
    circle(cloud4XPosition+22-shiftX, cloud2YPosition+13.5+1.5, cloud2ZPosition, 8, 255, 245, 245);
    circle(cloud4XPosition+33-shiftX, cloud2YPosition+13+1.5, cloud2ZPosition, 5, 245, 255, 255);
}

void road()
{
    // Foot path
    glPushMatrix();
    glTranslated(-170,-10,64+1);
    glScaled(400,1,4);
    cube(0.7,0.7,0.7);
    glPopMatrix();

    //upper Border line
    glPushMatrix();
    glTranslated(-170,-10.5,69);
    glScaled(400,0.7,.5);
    cube(1,1,1);
    glPopMatrix();

    // Main road
    glPushMatrix();
    glTranslated(-170,-11,65.3);
    glScaled(400,1,14);
    cube(0,0,0);
    glPopMatrix();

    //lower Border line
    glPushMatrix();
    glTranslated(-170,-10.5,79.5);
    glScaled(400,0.7,.45);
    cube(1,1,1);
    glPopMatrix();

    // Foot path
    glPushMatrix();
    glTranslated(-170,-10,80.3);
    glScaled(400,1,4);
    cube(0.7,0.7,0.7);
    glPopMatrix();

    //middle lines
    glPushMatrix();
    glTranslated(-168,-10.5,75.3);
    glScaled(8,1,.2);
    cube(1,1,1);
    glPopMatrix();

    //middle lines
    glPushMatrix();
    glTranslated(-154,-10.5,75.3);
    glScaled(8,1,.2);
    cube(1,1,1);
    glPopMatrix();

    //middle lines
    glPushMatrix();
    glTranslated(-140,-10.5,75.3);
    glScaled(8,1,.2);
    cube(1,1,1);
    glPopMatrix();

    //middle lines
    glPushMatrix();
    glTranslated(-126,-10.5,75.3);
    glScaled(8,1,.2);
    cube(1,1,1);
    glPopMatrix();

    //middle lines
    glPushMatrix();
    glTranslated(-112,-10.5,75.3);
    glScaled(8,1,.2);
    cube(1,1,1);
    glPopMatrix();

    //middle lines
    glPushMatrix();
    glTranslated(-98,-10.5,75.3);
    glScaled(8,1,.2);
    cube(1,1,1);
    glPopMatrix();

    //middle lines
    glPushMatrix();
    glTranslated(-84,-10.5,75.3);
    glScaled(8,1,.2);
    cube(1,1,1);
    glPopMatrix();

    //middle lines
    glPushMatrix();
    glTranslated(-70,-10.5,75.3);
    glScaled(8,1,.2);
    cube(1,1,1);
    glPopMatrix();

    //middle lines
    glPushMatrix();
    glTranslated(-56,-10.5,75.3);
    glScaled(8,1,.2);
    cube(1,1,1);
    glPopMatrix();

    //middle lines
    glPushMatrix();
    glTranslated(-42,-10.5,75.3);
    glScaled(8,1,.2);
    cube(1,1,1);
    glPopMatrix();

    //middle lines
    glPushMatrix();
    glTranslated(-28,-10.5,75.3);
    glScaled(8,1,.2);
    cube(1,1,1);
    glPopMatrix();

    //middle lines
    glPushMatrix();
    glTranslated(-14,-10.5,75.3);
    glScaled(8,1,.2);
    cube(1,1,1);
    glPopMatrix();

    //middle lines
    glPushMatrix();
    glTranslated(0,-10.5,75.3);
    glScaled(8,1,.2);
    cube(1,1,1);
    glPopMatrix();

    //middle lines
    glPushMatrix();
    glTranslated(14,-10.5,75.3);
    glScaled(8,1,.2);
    cube(1,1,1);
    glPopMatrix();

    //middle lines
    glPushMatrix();
    glTranslated(28,-10.5,75.3);
    glScaled(8,1,.2);
    cube(1,1,1);
    glPopMatrix();

    //middle lines
    glPushMatrix();
    glTranslated(42,-10.5,75.3);
    glScaled(8,1,.2);
    cube(1,1,1);
    glPopMatrix();

    //middle lines
    glPushMatrix();
    glTranslated(56,-10.5,75.3);
    glScaled(8,1,.2);
    cube(1,1,1);
    glPopMatrix();

    //middle lines
    glPushMatrix();
    glTranslated(210,-10.5,75.3);
    glScaled(8,1,.2);
    cube(1,1,1);
    glPopMatrix();

    //middle lines
    glPushMatrix();
    glTranslated(196,-10.5,75.3);
    glScaled(8,1,.2);
    cube(1,1,1);
    glPopMatrix();

    //middle lines
    glPushMatrix();
    glTranslated(182,-10.5,75.3);
    glScaled(8,1,.2);
    cube(1,1,1);
    glPopMatrix();


    //middle lines
    glPushMatrix();
    glTranslated(168,-10.5,75.3);
    glScaled(8,1,.2);
    cube(1,1,1);
    glPopMatrix();

    //middle lines
    glPushMatrix();
    glTranslated(154,-10.5,75.3);
    glScaled(8,1,.2);
    cube(1,1,1);
    glPopMatrix();

    //middle lines
    glPushMatrix();
    glTranslated(140,-10.5,75.3);
    glScaled(8,1,.2);
    cube(1,1,1);
    glPopMatrix();

    //middle lines
    glPushMatrix();
    glTranslated(126,-10.5,75.3);
    glScaled(8,1,.2);
    cube(1,1,1);
    glPopMatrix();

    //middle lines
    glPushMatrix();
    glTranslated(112,-10.5,75.3);
    glScaled(8,1,.2);
    cube(1,1,1);
    glPopMatrix();

    //middle lines
    glPushMatrix();
    glTranslated(98,-10.5,75.3);
    glScaled(8,1,.2);
    cube(1,1,1);
    glPopMatrix();

    //middle lines
    glPushMatrix();
    glTranslated(84,-10.5,75.3);
    glScaled(8,1,.2);
    cube(1,1,1);
    glPopMatrix();

    //middle lines
    glPushMatrix();
    glTranslated(70,-10.5,75.3);
    glScaled(8,1,.2);
    cube(1,1,1);
    glPopMatrix();
}

float windmillFan1Degree = 0;
float windmillFan2Degree = 120;
float windmillFan3Degree = 240;

void windMill(float xBasePosition,float yBasePosition,float zBasePosition) {
// pillar
glPushMatrix();
glTranslated(xBasePosition,yBasePosition,zBasePosition);
glScaled(2,26,2);
cube(0.9,0.9,0.9);
glPopMatrix();

// center circle
circle(xBasePosition+1, yBasePosition+24, zBasePosition+2, 2.5, 255, 255, 0);


// Fan 1
glPushMatrix();
glTranslated(xBasePosition,yBasePosition+24,zBasePosition+2);
glRotated(windmillFan1Degree, 0, 0, 1);
glScaled(17,2,0.5);
cube(1,1,1);
glPopMatrix();

// Fan 2
glPushMatrix();
glTranslated(xBasePosition,yBasePosition+24,zBasePosition+2);
glRotated(windmillFan2Degree, 0, 0, 1);
glScaled(17,2,0.5);
cube(1,1,1);
glPopMatrix();

// Fan 3
glPushMatrix();
glTranslated(xBasePosition,yBasePosition+24,zBasePosition+2);
glRotated(windmillFan3Degree, 0, 0, 1);
glScaled(17,2,0.5);
cube(1,1,1);
glPopMatrix();
}

void windMills() {
float xBasePosition = -150;
float yBasePosition = -10.5;
float zBasePosition = -25;
// windmill 1
windMill(xBasePosition, yBasePosition, zBasePosition);
// windmill 2
windMill(xBasePosition+37, yBasePosition, zBasePosition);
// windmill 3
windMill(xBasePosition+174, yBasePosition, zBasePosition);
// windmill 4
windMill(xBasePosition+214, yBasePosition, zBasePosition);
// windmill 5
windMill(xBasePosition+254, yBasePosition, zBasePosition);
// windmill 6
windMill(xBasePosition+294, yBasePosition, zBasePosition);
}

void createTree(float xBasePosition, float yBasePosition, float zBasePosition) {
// pillar
glPushMatrix();
glTranslated(xBasePosition, yBasePosition, zBasePosition);
glScaled(1, 10, 1);
cube(166/255.0, 137/255.0, 101/255.0);
glPopMatrix();

// center circle
circle(xBasePosition+1, yBasePosition+6.5, zBasePosition+1.4, 2.35, 0, 247, 32);

// outside circle 1
circle(xBasePosition+4.5, yBasePosition+8, zBasePosition+1.4, 2.5, 0, 235, 22);

// outside circle 2
circle(xBasePosition+2, yBasePosition+11, zBasePosition+1.4, 2.5, 0, 241, 32);

// outside circle 3
circle(xBasePosition-1.5, yBasePosition+8, zBasePosition+1.4, 2.5, 0, 242, 32);

}

void trees() {

float xBasePosition = -100;
float yBasePosition = -6.5;
float zBasePosition = 17;

// between windmill and hills
// tree x
    createTree(xBasePosition-15, yBasePosition, zBasePosition-55);
// tree x
    createTree(xBasePosition-30, yBasePosition, zBasePosition-52);
// tree x
    createTree(xBasePosition-55, yBasePosition, zBasePosition-65);
// tree x
    createTree(xBasePosition-65, yBasePosition, zBasePosition-60);
// tree x
    createTree(xBasePosition-73, yBasePosition, zBasePosition-55);
// tree x
    createTree(xBasePosition-88, yBasePosition, zBasePosition-50);

    float shift1 = 45;
// tree x
    createTree(xBasePosition-1+shift1, yBasePosition, zBasePosition-55);
// tree x
    createTree(xBasePosition+18+shift1, yBasePosition, zBasePosition-52);
// tree x
    createTree(xBasePosition+39+shift1, yBasePosition, zBasePosition-65);
// tree x
    createTree(xBasePosition+65+shift1, yBasePosition, zBasePosition-60);
// tree x
    createTree(xBasePosition+83+shift1, yBasePosition, zBasePosition-55);
// tree x
    createTree(xBasePosition+98+shift1, yBasePosition, zBasePosition-50);

    float shift2 = 130;
// tree x
    createTree(xBasePosition-1+shift2, yBasePosition, zBasePosition-55);
// tree x
    createTree(xBasePosition+28+shift2, yBasePosition, zBasePosition-52);
// tree x
    createTree(xBasePosition+49+shift2, yBasePosition, zBasePosition-65);
// tree x
    createTree(xBasePosition+85+shift2, yBasePosition, zBasePosition-60);
// tree x
    createTree(xBasePosition+113+shift2, yBasePosition, zBasePosition-55);
// tree x
    createTree(xBasePosition+150+shift2, yBasePosition, zBasePosition-50);

    float shift3 = 180;
// tree x
    createTree(xBasePosition-1+shift3, yBasePosition, zBasePosition-55);
// tree x
    createTree(xBasePosition+28+shift3, yBasePosition, zBasePosition-52);
// tree x
    createTree(xBasePosition+49+shift3, yBasePosition, zBasePosition-65);
// tree x
    createTree(xBasePosition+85+shift3, yBasePosition, zBasePosition-60);
// tree x
    createTree(xBasePosition+113+shift3, yBasePosition, zBasePosition-55);
// tree x
    createTree(xBasePosition+150+shift3, yBasePosition, zBasePosition-50);


// between windmill and house
// tree x
    createTree(xBasePosition-10, yBasePosition, zBasePosition-5);
// tree x
    createTree(xBasePosition+4-8, yBasePosition, zBasePosition-11-5);
// tree x
    createTree(xBasePosition+29-6, yBasePosition, zBasePosition-5);
// tree x
    createTree(xBasePosition+33-7, yBasePosition, zBasePosition+18-5);

    float shift4 = 120;
// tree x
    createTree(xBasePosition+shift4-10, yBasePosition, zBasePosition-5);
// tree x
    createTree(xBasePosition+4+shift4, yBasePosition, zBasePosition-11-5);
// tree x
    createTree(xBasePosition+29+shift4-8, yBasePosition, zBasePosition-5);
// tree x
    createTree(xBasePosition+37+shift4, yBasePosition, zBasePosition+18-14);


    float shift5 = 189;
// tree x
    createTree(xBasePosition+4+shift5, yBasePosition, zBasePosition-11-5);
// tree x
    createTree(xBasePosition+29+shift5-8, yBasePosition, zBasePosition-5);
// tree x
    createTree(xBasePosition+33+shift5, yBasePosition, zBasePosition+18-10);


// tree inside house
    createTree(xBasePosition+122, yBasePosition, zBasePosition+23);

// tree inside house
    createTree(xBasePosition+56, yBasePosition, zBasePosition+43);
}


void humanFrontFace(float xBasePosition,float yBasePosition, float zBasePosition) {

    // Head
    glPushMatrix();
    circle(xBasePosition, yBasePosition+6.6, zBasePosition+1.3, 0.85, 249, 241, 210);
    glPopMatrix();

    // hair
    glPushMatrix();
    circle(xBasePosition, yBasePosition+7, zBasePosition+1.3, 0.75, 55, 66, 33);
    glPopMatrix();

    // Body (torso)
    glPushMatrix();
    glTranslated(xBasePosition-1.2, yBasePosition+5.0-2.5, zBasePosition+1);
    glScaled(2.5, 3.5, 0.8);
    cube(0.106, 0.051, 0.588);
    glPopMatrix();


    //left arm
    glPushMatrix();
    glTranslated(xBasePosition-1.35, yBasePosition+9.0-4, zBasePosition+1.2);
    glRotated(45.0, 0.0, 0.0, 1.0);
    glScaled(0.5, 3, 0.5);
    cube(0.106, 0.051, 0.588);
    glPopMatrix();

    //left hand
    glPushMatrix();
    circle(xBasePosition-3.35, yBasePosition+11.4-4, zBasePosition+1.5, 0.5, 249, 241, 210);
    glPopMatrix();

    //right arm
    glPushMatrix();
    glTranslated(xBasePosition+0.6, yBasePosition+10.0-4.2, zBasePosition+1.5);
    glRotated(-45.0, 0.0, 0.0, 1.0);
    glScaled(0.8, 3, 0.8);
    cube(0.106, 0.051, 0.588);
    glPopMatrix();

    //right hand
    glPushMatrix();
    circle(xBasePosition+3.6, yBasePosition+12.5-4.6, zBasePosition+1.5, 0.5, 249, 241, 210);
    glPopMatrix();


     //left leg
    glPushMatrix();
    glTranslated(xBasePosition -1.2, yBasePosition+0.7, zBasePosition+1);
    glScaled(0.4, 2, 0.4);
    cube(0.749, 1, 0);
    glPopMatrix();

    //left foot
    glPushMatrix();
    glTranslated(xBasePosition -1.3, yBasePosition, zBasePosition+1);
    glScaled(0.6, 0.6, 0.6);
    cube(0.4, 0.055, 0.055);
    glPopMatrix();

     //left leg
    glPushMatrix();
    glTranslated(xBasePosition+0.5+0.3, yBasePosition+0.7, zBasePosition+1);
    glScaled(0.4, 2, 0.4);
    cube(0.749, 1, 0);
    glPopMatrix();

    //left foot
    glPushMatrix();
    glTranslated(xBasePosition+0.5+0.2, yBasePosition, zBasePosition+1);
    glScaled(0.6, 0.6, 0.6);
    cube(0.4, 0.055, 0.055);
    glPopMatrix();

}

void humanRightFace(float xBasePosition,float yBasePosition, float zBasePosition) {
    // Head
    glPushMatrix();
    circle(xBasePosition, yBasePosition+6.6, zBasePosition+1.3, 0.85, 249, 241, 210);
    glPopMatrix();

    // hair
    glPushMatrix();
    circle(xBasePosition, yBasePosition+7, zBasePosition+1.3, 0.75, 55, 66, 33);
    glPopMatrix();

    // Body (torso)
    glPushMatrix();
    glTranslated(xBasePosition-1.2, yBasePosition+5.0-2.5, zBasePosition+1);
    glScaled(2.5, 3.5, 0.8);
    cube(0.106, 0.051, 0.588);
    glPopMatrix();


    //left arm
    glPushMatrix();
    glTranslated(xBasePosition-1.35, yBasePosition+9.0-4, zBasePosition+1.2);
    glRotated(45.0, 0.0, 0.0, 1.0);
    glScaled(0.5, 3, 0.5);
    cube(0.106, 0.051, 0.588);
    glPopMatrix();

    //left hand
    glPushMatrix();
    circle(xBasePosition-3.35, yBasePosition+11.4-4, zBasePosition+1.5, 0.5, 249, 241, 210);
    glPopMatrix();

    //right arm
    glPushMatrix();
    glTranslated(xBasePosition+0.6, yBasePosition+10.0-4.2, zBasePosition+1.5);
    glRotated(-45.0, 0.0, 0.0, 1.0);
    glScaled(0.8, 3, 0.8);
    cube(0.106, 0.051, 0.588);
    glPopMatrix();

    //right hand
    glPushMatrix();
    circle(xBasePosition+3.6, yBasePosition+12.5-4.6, zBasePosition+1.5, 0.5, 249, 241, 210);
    glPopMatrix();


     //left leg
    glPushMatrix();
    glTranslated(xBasePosition -1.2, yBasePosition+0.7, zBasePosition+1);
    glScaled(0.4, 2, 0.4);
    cube(0.749, 1, 0);
    glPopMatrix();

    //left foot
    glPushMatrix();
    glTranslated(xBasePosition -1.3, yBasePosition, zBasePosition+1);
    glScaled(0.6, 0.6, 0.6);
    cube(0.4, 0.055, 0.055);
    glPopMatrix();

     //left leg
    glPushMatrix();
    glTranslated(xBasePosition+0.5+0.3, yBasePosition+0.7, zBasePosition+1);
    glScaled(0.4, 2, 0.4);
    cube(0.749, 1, 0);
    glPopMatrix();

    //left foot
    glPushMatrix();
    glTranslated(xBasePosition+0.5+0.2, yBasePosition, zBasePosition+1);
    glScaled(0.6, 0.6, 0.6);
    cube(0.4, 0.055, 0.055);
    glPopMatrix();
}


void humanXAxisFace(float xBasePosition,float yBasePosition, float zBasePosition) {
    // Head
    glPushMatrix();
    circle(xBasePosition, yBasePosition+6.6, zBasePosition+1.3, 0.85, 249, 241, 210);
    glPopMatrix();

    // hair
    glPushMatrix();
    circle(xBasePosition, yBasePosition+7, zBasePosition+1.3, 0.75, 55, 66, 33);
    glPopMatrix();

    // Body (torso)
    glPushMatrix();
    glTranslated(xBasePosition-1.2, yBasePosition+5.0-2.5, zBasePosition+1);
    glScaled(2.5, 3.5, 0.8);
    cube(0.906, 0.451, 0.588);
    glPopMatrix();


    //left arm
    glPushMatrix();
    glTranslated(xBasePosition-2.35, yBasePosition+9.0-4, zBasePosition+1.2);
    glScaled(1.4, 1, 0.5);
    cube(0.106, 0.051, 0.588);
    glPopMatrix();

    glPushMatrix();
    glTranslated(xBasePosition-2.35, yBasePosition+9.0-5.3, zBasePosition+1.1);
    glScaled(0.8, 1.5, 0.5);
    cube(0.306, 5.051, 0.588);
    glPopMatrix();

    //left hand
    glPushMatrix();
    circle(xBasePosition-2.17, yBasePosition+11.4-7.9, zBasePosition+1.5, 0.5, 249, 241, 210);
    glPopMatrix();

    //right arm
    glPushMatrix();
    glTranslated(xBasePosition+0.6, yBasePosition+10.0-4.2-0.75, zBasePosition+1.5);
    glScaled(2, 1, 0.5);
    cube(0.106, 0.051, 0.588);
    glPopMatrix();

    glPushMatrix();
    glTranslated(xBasePosition+1.8, yBasePosition+10.0-5.5-0.75, zBasePosition+1.5);
    glScaled(0.8, 1.5, 0.5);
    cube(0.306, 5.051, 0.588);
    glPopMatrix();

    //right hand
    glPushMatrix();
    circle(xBasePosition+1.8, yBasePosition+12.5-8.6, zBasePosition+1.3, 0.5, 249, 241, 210);
    glPopMatrix();


     //left leg
    glPushMatrix();
    glTranslated(xBasePosition -1.2, yBasePosition+0.7, zBasePosition+1);
    glScaled(0.4, 2, 0.4);
    cube(0.749, 1, 0);
    glPopMatrix();

    //left foot
    glPushMatrix();
    glTranslated(xBasePosition -1.3, yBasePosition, zBasePosition+1);
    glScaled(0.6, 0.6, 0.6);
    cube(0.4, 0.055, 0.055);
    glPopMatrix();

     //left leg
    glPushMatrix();
    glTranslated(xBasePosition+0.5+0.3, yBasePosition+0.7, zBasePosition+1);
    glScaled(0.4, 2, 0.4);
    cube(0.749, 1, 0);
    glPopMatrix();

    //left foot
    glPushMatrix();
    glTranslated(xBasePosition+0.5+0.2, yBasePosition, zBasePosition+1);
    glScaled(0.6, 0.6, 0.6);
    cube(0.4, 0.055, 0.055);
    glPopMatrix();
}


        float human1XBasePosition = -20;
        float human1YBasePosition = -8.5;
        float human1ZBasePosition = 66;

        float human2XBasePosition = 56;
        float human2YBasePosition = -8.5;
        float human2ZBasePosition = 36;

        float human3XBasePosition = 56;
        float human3YBasePosition = -8.5;
        float human3ZBasePosition = 59;

        float human4XBasePosition = 56;
        float human4YBasePosition = -8.5;
        float human4ZBasePosition = 45;

        float ballYAxis = 0.6;

        float human5XBasePosition = 70.5;
        float human5YBasePosition = -8.5;
        float human5ZBasePosition = -38;


        float human6XBasePosition = 56;
        float human6YBasePosition = -8.5;
        float human6ZBasePosition = 78;
void humans() {
        // Human football watcher
    glPushMatrix();
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);  // Rotate around the Y-axis by 45 degrees
    humanRightFace(human1XBasePosition-20, human1YBasePosition, human1ZBasePosition+14);
    glPopMatrix();

    glPushMatrix();
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);  // Rotate around the Y-axis by 45 degrees
    humanRightFace(human1XBasePosition-25.5, human1YBasePosition, human1ZBasePosition+14);
    glPopMatrix();

    // Goal Man 2
    glPushMatrix();
    glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);  // Rotate around the Y-axis by 45 degrees
    humanRightFace(human4ZBasePosition+3, human1YBasePosition, human1ZBasePosition-133);
    glPopMatrix();

        // GoalPost Human 2
    humanFrontFace(human2XBasePosition, human2YBasePosition, human2ZBasePosition);
        // GoalPost Human 3
    humanFrontFace(human3XBasePosition, human3YBasePosition, human3ZBasePosition);
        // GoalPost Human 4
    humanFrontFace(human4XBasePosition, human4YBasePosition, human4ZBasePosition);
        // GoalPost football
    circle(human4XBasePosition, human1YBasePosition+ballYAxis, human4ZBasePosition+2.6, 1, 255,243,233);


    // footpath human 1
    glPushMatrix();
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);  // Rotate around the Y-axis by 45 degrees
    // human x axis face
    humanXAxisFace(human5XBasePosition-139, human5YBasePosition, human5ZBasePosition-25);
    glPopMatrix();

    // footpath human 2
    glPushMatrix();
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);  // Rotate around the Y-axis by 45 degrees
    // human x axis face
    humanXAxisFace(human6XBasePosition-139, human6YBasePosition, human6ZBasePosition-25);
    glPopMatrix();


    // footpath human 2
    glPushMatrix();
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);  // Rotate around the Y-axis by 45 degrees
    // human x axis face
    humanXAxisFace(human6XBasePosition-139, human6YBasePosition, human6ZBasePosition+65);
    glPopMatrix();
}


void car(float baseXPosition, float baseYPosition, float baseZPosition, float color1, float color2, float color3)
{
    color1 = color1/255.0;
    color2 = color2/255.0;
    color3 = color3/255.0;
	// chaka 1
    circle(3.3+baseXPosition, -5.5+baseYPosition, 76+baseZPosition, 0.7, 221,221,221);
	// chaka 1
    circle(8.5+baseXPosition, -5.5+baseYPosition, 76+baseZPosition, 0.7, 221,221,221);


    glPushMatrix();
    glTranslated(1+baseXPosition,-6+baseYPosition,75+baseZPosition);
    glScaled(1,1,1);

     //Lower
    glPushMatrix();
    glTranslated(baseXPosition, baseYPosition, baseZPosition);
    glScaled(9.80 ,1.75 ,1);
    cube(color1,color2,color3);
    glPopMatrix();

    //Upper
    glPushMatrix();
    glTranslated(3.30+baseXPosition,3.60+baseYPosition,0+baseZPosition);
    glScaled(3.5,.5,0);
    cube(color1,color2,color3);
    glPopMatrix();


    //Left angle
    glPushMatrix();
    glTranslated(1+baseXPosition,1+baseYPosition,0+baseZPosition);
    glRotated(43,0,0,1);
    glScaled(3.80,.60,0.2);
    cube(color1,color2,color3);
    glPopMatrix();

    //Divide
    glPushMatrix();
    glTranslated(5+baseXPosition,1.5+baseYPosition,0+baseZPosition);
    glScaled(.5,2.5,0);
    cube(color1,color2,color3);
    glPopMatrix();

    //Left Window
     glBegin(GL_TRIANGLES);
		glColor3f(0.0,0.0,0.0);
		glVertex2f(4.0+baseXPosition,4.0+baseYPosition);
		glColor3f(0.0,0.0,0.0);
		glVertex2f(4.0+baseXPosition,0.0+baseYPosition);
		glColor3f(0.0,0.0,0.0);
		glVertex2f(0.0+baseXPosition,0.0+baseYPosition);
	glEnd();

	glPushMatrix();
    glTranslated(4+baseXPosition,1.5+baseYPosition,0+baseZPosition);
    glScaled(1,2.2,0);
    cube(0.0,0.0,0.0);
    glPopMatrix();

    //Right angle
	glPushMatrix();
    glTranslated(6.50+baseXPosition,3.75+baseYPosition,0+baseZPosition);
    glRotated(-45,0,0,1);
    glScaled(3.30,.5,0);
    cube(color1,color2,color3);
    glPopMatrix();

    //Right window
    glPushMatrix();
    glTranslated(5.5+baseXPosition,1.5+baseYPosition,0+baseZPosition);
    glScaled(1,2.2,0);
    cube(0.0,0.0,0.0);
    glPopMatrix();

    glBegin(GL_TRIANGLES);
		glColor3f(0.0,0.0,0.0);
		glVertex2f(6.5+baseXPosition,4.0+baseYPosition);
		glColor3f(0.0,0.0,0.0);
		glVertex2f(10+baseXPosition,0.0+baseYPosition);
		glColor3f(0.0,0.0,0.0);
		glVertex2f(6.5+baseXPosition,0.0+baseYPosition);
	glEnd();

	glPopMatrix();
}

float car1XAxis = -10;
float car2XAxis = 100;

void makeCars() {

    //left to right car
	glPushMatrix();
    glTranslated(car1XAxis,0,0);
    car(0, 0, 0, 0, 0, 245);
    glPopMatrix();

    //right to left car
	glPushMatrix();
    glTranslated(car2XAxis,0,4.4);
    car(0, 0, 0, 211, 44, 0);
    glPopMatrix();


    //car on the field
	glPushMatrix();
    glTranslated(-70,0,-26.4);
    car(0, 0, 0, 155, 23, 22);
    glPopMatrix();

    //car on the field
	glPushMatrix();
    glTranslated(-71,0,-17.4);
    car(0, 0, 0, 233, 43, 233);
    glPopMatrix();

    //car on the field
	glPushMatrix();
    glTranslated(-69,0,-21.4);
    car(0, 0, 0, 53, 53, 193);
    glPopMatrix();
    //car on the field
	glPushMatrix();
    glTranslated(-69,0,-12.4);
    car(0, 0, 0, 53, 53, 193);
    glPopMatrix();

}



void busX()
{
    float baseXPosition = 0;
    float baseYPosition = -6;
    float baseZPosition = 0;

    glPushMatrix();
    glTranslated(11+baseXPosition,-1+baseYPosition,83.5+baseZPosition);
    glScaled(20,7,5);
    cube(0.5,0,0.7);
    glPopMatrix();

    glPushMatrix();
    glTranslated(30+baseXPosition,-1+baseYPosition,83.5+baseZPosition);
    glScaled(5,3.5,5);
    cube(0.5,0,.2);
    glPopMatrix();


    glPushMatrix();
    circle(26+baseXPosition,-1+baseYPosition, 88+baseZPosition, 1.5, 178.5,178.5,178.5);
    glScaled(2,3.5,5);
    glPopMatrix();

    glPushMatrix();
    circle(15+baseXPosition,-1+baseYPosition, 88+baseZPosition, 1.5, 178.5,178.5,178.5);
    glScaled(2,3.5,5);
    glPopMatrix();

    glPushMatrix();
    glTranslated(13+baseXPosition,2.5+baseYPosition,88+baseZPosition);
    glScaled(2,2,1);
    cube(1,1,1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(17+baseXPosition,2.5+baseYPosition,88+baseZPosition);
    glScaled(2,2,1);
    cube(1,1,1);
    glPopMatrix();


    glPushMatrix();
    glTranslated(21+baseXPosition,2.5+baseYPosition,88+baseZPosition);
    glScaled(2,2,1);
    cube(1,1,1);
    glPopMatrix();


    glPushMatrix();
    glTranslated(25+baseXPosition,2.5+baseYPosition,88+baseZPosition);
    glScaled(2,2,1);
    cube(1,1,1);
    glPopMatrix();



    glPushMatrix();
    glTranslated(29+baseXPosition,2.5+baseYPosition,88+baseZPosition);
    glScaled(1.7,2,1);
    cube(1,1,1);
    glPopMatrix();


}

float moveBusX = 10;

void bus() {
    glPushMatrix();
    glTranslated(moveBusX, 1, -12.5);
    busX();
    glPopMatrix();
}

float scalingFactor = 1;



void movingSun() {
    // sun
    sunYPosition += 0.001 * scalingFactor;
}

void movingClouds() {
    // cloud 1
    cloud1XPosition += 0.0125 * scalingFactor;


    // cloud 2
    cloud2XPosition += 0.02 * scalingFactor;

        // cloud 3
    cloud3XPosition += 0.0155 * scalingFactor;


    // cloud 4
    cloud4XPosition += 0.018 * scalingFactor;


    if((int)cloud1XPosition == 190) {

     cloud1XPosition = -190-300;
     cloud1YPosition = 72;
     cloud1ZPosition = -57;

     cloud2XPosition = -253-300;
     cloud2YPosition = 45;
     cloud2ZPosition = -90;


     cloud3XPosition = -100-300;

     cloud4XPosition = 13-300;
    }
}


void movingWindMill() {
// windmill 1
windmillFan1Degree -= 0.1 * windMillScalingFactor;
windmillFan2Degree -= 0.1 * windMillScalingFactor;
windmillFan3Degree -= 0.1 * windMillScalingFactor;
}

float goalKeeper1MoveBy = 0.005;

float goalKeeper2MoveBy = -0.005;

float human4MoveBy = 0.005;

float footBallMoveBy = 0.009;

void MovingHumanInFootballField() {
    human2XBasePosition += goalKeeper1MoveBy * scalingFactor;
    if((int)human2XBasePosition == 59) {
        goalKeeper1MoveBy = -0.005;
    } else if((int)human2XBasePosition == 54) {
        goalKeeper1MoveBy = 0.005;
    }


    human3XBasePosition += goalKeeper2MoveBy * scalingFactor;
    if((int)human3XBasePosition == 51) {
        goalKeeper2MoveBy = 0.005;
    } else if((int)human3XBasePosition == 58) {
        goalKeeper2MoveBy = -0.005;
    }


    human4ZBasePosition += human4MoveBy * scalingFactor;
    if((int)human4ZBasePosition == 45) {
        human4MoveBy = 0.005;
    } else if((int)human4ZBasePosition == 55) {
        human4MoveBy = -0.005;
    }

    ballYAxis += footBallMoveBy * scalingFactor;
    if((int)ballYAxis == 4) {
        footBallMoveBy = -0.009;
    } else if((int)ballYAxis == 0) {
        footBallMoveBy = 0.009;
    }
}

float human5MoveBy = 0.0109;
float human6MoveBy = -0.0123;

movingHumanInFootPath() {
human5ZBasePosition += human5MoveBy * scalingFactor;
    if((int)human5ZBasePosition == 108) {
        human5MoveBy = -0.009;
    } else if((int)human5ZBasePosition == -49) {
        human5MoveBy = 0.009;
    }


human6ZBasePosition += human6MoveBy * scalingFactor;
    if((int)human5ZBasePosition == 108) {
        human6MoveBy = 0.009;
    } else if((int)human5ZBasePosition == -49) {
        human6MoveBy = -0.009;
    }
}


void movingCars() {
    car1XAxis += car1MovingFactor * scalingFactor *car1ScalingFactor;
    float differenceCar1AndBus = moveBusX - car1XAxis;
    printf("%2f\n", differenceCar1AndBus);
    if((int) differenceCar1AndBus == 5) {
        car1ScalingFactor = 0;
    }
   car2XAxis += car2MovingFactor * scalingFactor*car2ScalingFactor;

    if((int)car1XAxis == 110) {
        car1XAxis = -110;
    }


    if((int)car2XAxis == -66) {
        car2XAxis = 90;
    }
}

void movingBus() {
    moveBusX += car1MovingFactor*scalingFactor*busScalingFactor;

    if((int)moveBusX == 90) {
        moveBusX = -90;
    }
}

float eyeXIncrement = 0.01;
float eyeYIncrement = 0;

movingCamera() {
        eyeX += eyeXIncrement * scalingFactor;
        if((int)eyeX == 55) {
            eyeXIncrement = 0;
            eyeYIncrement = -0.01;
        }
        eyeY += eyeYIncrement * scalingFactor;
        if((int)eyeY == 12) {
            eyeXIncrement = -0.01;
            eyeYIncrement = 0;
        }
        eyeX += eyeXIncrement * scalingFactor;
        if((int)eyeX == -32) {
            eyeXIncrement = 0;
            eyeYIncrement = 0.01;
        }

        eyeY += eyeYIncrement * scalingFactor;
        if((int)eyeY == 33) {
            eyeXIncrement = 0.01;
            eyeYIncrement = 0;
        }
}

void initMovingThings() {
    movingSun();
    movingClouds();
    movingWindMill();
    MovingHumanInFootballField();
    movingHumanInFootPath();
    movingCars();
    movingBus();
    if(moveCamera == true) {
        movingCamera();
    }

}

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    // near x, max x, near y, max y, near z, max z
    glFrustum(-3.5, 3, -3, 3, 2.0, 800.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(eyeX,eyeY,eyeZ, lookX,lookY,lookZ, 0,1,0);
    glViewport(0, 0, width, height);

    createBaseField();
    buildHouse();
    buildPlayingField();
    createHills();
    createSunAndCloud();
    windMills();
    trees();
    road();
    makeCars();
    humans();
    bus();
    initMovingThings();

    glutSwapBuffers();
}

int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowPosition(100,100);
    glutInitWindowSize(900,700);
    glutCreateWindow("Duplex House");

    glShadeModel( GL_SMOOTH );
    glEnable( GL_DEPTH_TEST );

    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(display);
    glutMainLoop();

    return 0;
}



