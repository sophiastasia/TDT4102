#pragma once
#include "std_lib_facilities.h"

double acclY();
double velY(double initVelocityY, double time);
double posX(double initPosition, double initVelocity, double time);
double posY(double initPosition, double initVelocity, double time);
void printTime(double seconds);
double flightTime(double initVelocityY);
void testDeviation(double compareOperand, double toOperand, double maxError, string name);
double getUserInputTheta();
double getUserInputAbsVelocity();
double degToRad(double deg);
double getVelocityX(double theta, double absVel);
double getVelocityY(double theta, double absVel);
vector<double> getVelocityVector(double theta, double absVel);
double getDistanceTraveled(double velocityX, double velocityY);
double targetPractice(double distanceToTarget, double velocityX, double veloctyY);
bool checkIfDistanceToTargetIsCorrect();
void playTargetPractice();