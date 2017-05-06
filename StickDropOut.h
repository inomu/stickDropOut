//
// Created by inomu on 2017/05/04.
//

#ifndef STICKDROPOUT_STICKDROPOUT_H
#define STICKDROPOUT_STICKDROPOUT_H

#include <iostream>
#include <vector>

class StickDropOut {
public:
    StickDropOut(int , int);
    void dispMap();
    void summonRobot();
    int moveRobot(int);

private:
    //generate map
    void createMap();
    void makeStickMap();
    int generateRandom();
    bool pushStick(int , int);

    //move robot
    void setRobotLocate(int , int);
    void deleteRobot();
};


#endif //STICKDROPOUT_STICKDROPOUT_H
