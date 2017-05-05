//
// Created by inomu on 2017/05/04.
//

#ifndef STICKDROPOUT_STICKDROPOUT_H
#define STICKDROPOUT_STICKDROPOUT_H

#include <iostream>
#include <vector>

class StickDropOut {
public:
    StickDropOut(int gridWidth,int gridHeight);
    void dispMap();
    void summonRobot();


private:
    char m_robot;
    int m_robotX,m_robotY;
    int m_MapWidth , m_MapHeight;
    char m_wall;
    std::vector< std::vector<char> > mapArray;
    void createMap();
    void makeStickMap();
    int generateRandom();
    bool pushStick(int , int);
};


#endif //STICKDROPOUT_STICKDROPOUT_H
