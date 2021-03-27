#include "main.h"

int CURRENT_ID;

//X & Y pos of object in cam FOV
int currentTargetX;
int currentTargetY;

void setVision();
void findObjects();
double getArea();
double getAngle();
double getDistance();
int getXCord();
int getYCord();
void clearVision();
void checkExposure(int exposure);
