#include "main.h"
#include "subsytemHeaders/globals.hpp"

//config these when we get act camera
const int RED_ID = 1;
const int BLUE_ID = 2;
const int GREEN_ID = 3;

//minimum area of acceptable object
const int MIN_SIZE = 5000;
//maximum area of acceptable object
const int MAX_SIZE = 6000;

int CURRENT_ID = 0;

pros::vision_object_s_t currentObj = visionCam.get_by_sig(0, CURRENT_ID);

void checkExposure(int exposure) {
  if(visionCam.get_exposure() > exposure) {
    visionCam.set_exposure(exposure);
  }
}

void findObject() {
  currentObj = visionCam.get_by_sig(0, CURRENT_ID);
}

double getArea() {
  return currentObj.width * currentObj.height;
}

double getAngle() {
  //test both in degrees
  return currentObj.angle / 10.0;
  // return currentObj.x_middle_coord
}

int checkDistance() {
  int area = getArea();
  if(area > MAX_SIZE) {
    //too close
    return -1;
  } else if(area <= MAX_SIZE && area >= MIN_SIZE) {
    //just right
    return 0;
  } else {
    //too far
    return 1;
  }
}

void setVision() {
  checkExposure(50);
  findObject();
}
