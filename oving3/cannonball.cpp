#include "cannonball.h"
#include "std_lib_facilities.h"
#include "utilities.h"
#include "cannonball_viz.h"

double acclY(){
    double a = -9.81;
    return a;
}
double velY(double initVelocityY, double time){
    double a = acclY();
    double FartY = initVelocityY + a*time;
    return FartY;
}
double posX(double initPosition, double initVelocity, double time){
    double a = 0;
    double positionX = initPosition + initVelocity*time + (a*time*time)/2;
    return positionX;
}
double posY(double initPosition, double initVelocity, double time){
    double a = acclY();
    double positionY = initPosition + initVelocity*time + (a*time*time)/2;
    return positionY;
}
void printTime(double seconds){
    int timer = seconds/3600;
    int minutter = (static_cast<int>(seconds)%3600)/60;
    int sekund = seconds - timer*3600 - minutter*60;
    cout << seconds << " sekund er " << timer << " timer, " << minutter << " minutter og " << sekund << " sekunder." << endl;
}
double flightTime(double initVelocityY){
    double a = acclY();
    double tid = -(2*initVelocityY)/a;
    return tid;
}
void testDeviation(double compareOperand, double toOperand, double maxError, string name){
    bool testing = (abs(compareOperand-toOperand) <= maxError);
    if (testing){
        cout << name << " is valid. " << endl;
    }
    else {
        cout << name << " is not valid, expected " << toOperand << ", got " << compareOperand << endl;
    }
}
double getUserInputTheta(){
    double theta;
    cout << "Enter angle in degrees: " << endl;
    cin >> theta;
    return static_cast<double>(theta);
}
double getUserInputAbsVelocity(){
    double absVel;
    cout << "Enter absolute velocity: " << endl;
    cin >> absVel;
    return static_cast<double>(absVel);
}
double degToRad(double deg){
    double rad = deg*0.0174532925;
    return rad;
}
double getVelocityX(double theta, double absVel){
    double rad = degToRad(theta);
    double velX = absVel*static_cast<double>(cos(rad));
    return velX;
}
double getVelocityY(double theta, double absVel){
    double rad = degToRad(theta);
    double velY = absVel*static_cast<double>(sin(rad));
    return velY;
}
vector<double> getVelocityVector(double theta, double absVel){
    double velX = getVelocityX(theta, absVel);
    double velY = getVelocityY(theta, absVel);
    vector<double> vektor = {velX, velY};
    return vektor;
}
double getDistanceTraveled(double velocityX, double velocityY){
    return posX(0., velocityX, flightTime(velocityY));
}
double targetPractice(double distanceToTarget, double velocityX, double veloctyY){
    return distanceToTarget - getDistanceTraveled(velocityX, veloctyY);
}
bool checkIfDistanceToTargetIsCorrect(){
    double error = targetPractice(100,0,0);
    if (error == 0)
        return true;
    else
        return false;
}

//Oppgave 5
void playTargetPractice(){
    //nedre:100 og ovre:1000, ti forsøk
    double avstand = randomWithLimits(100, 1000);
    cout << "Avstanden til maalet er " << avstand << "." << endl;
    bool won = true;
    bool trial = false;

    for (int i = 0; i < 11; i++){
            double theta = getUserInputTheta();
            double absvel = getUserInputAbsVelocity();
            double diffDist = targetPractice(avstand, getVelocityX(theta, absvel), getVelocityY(theta, absvel));
            double distanceTraveled = getDistanceTraveled(getVelocityX(theta, absvel), getVelocityY(theta, absvel));
            double travelTime = flightTime(getVelocityY(theta, absvel));
            
            cannonBallViz(avstand, 1000, getVelocityX(theta, absvel), getVelocityY(theta, absvel), 100);


            if (abs(diffDist) < 5 ){
                cout << "Gratulerer, du traff blinken!" << endl;
                cout << "Avstand fra blink til ball ble " << diffDist << "." << endl;
                cout << "Tiden ballen brukte i lufta var " << travelTime << "." << endl;
                trial = true;
            }
            
            else{
                if (diffDist<0){
                    cout << "Du kastet " << abs(diffDist) << " meter for langt. Prov igjen!" << endl;
                }
                else {
                    cout << "Du kastet" << diffDist << " meter for kort. Prov igjen!" << endl;
                }
                cout << "Ballen brukte " << travelTime << " sekunder i luften." << endl;
                cout << "Du har " << 9-i << " forsok igjen." << endl;
            }

            if (trial == won) {
                break;
            }
    }
    if (trial != won){
        cout << "Du klarte det desverre ikke denne gangen. Men du gjorde ditt beste! Better luck next time." << endl;
    }
}