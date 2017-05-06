//
// Created by inomu on 2017/05/04.
//

#include "StickDropOut.h"

#include <random>

char m_robot = 'R';
int m_robotLocation[2];
int m_MapWidth , m_MapHeight;
char m_wall = 'W';
std::vector< std::vector<char> > mapArray;

StickDropOut::StickDropOut(int gridWidth, int gridHeight) {

    //GridMapを作成する為に必要な配列の数を求める．
    m_MapWidth = gridWidth * 2 + 1;
    m_MapHeight = gridHeight * 2 + 1;

    StickDropOut::createMap();
    StickDropOut::dispMap();
    StickDropOut::makeStickMap();
    StickDropOut::dispMap();
}

void StickDropOut::createMap() {
    //グリッドマップの作成.

    //mapArray[y][x];
    mapArray = std::vector<std::vector<char>>(m_MapHeight, std::vector<char>(m_MapWidth));
    for (int i = 0; i < m_MapHeight; i++) {
        for (int j = 0; j < m_MapWidth; j++) {

            if (i == 0 || i == m_MapHeight - 1) {
                mapArray[i][j] = m_wall;
            } else if (j == 0 || j == m_MapWidth - 1) {
                mapArray[i][j] = m_wall;
            } else if (i % 2 == 0 && j % 2 == 0) {
                mapArray[i][j] = m_wall;
            }else{
                mapArray[i][j] = ' ';
            }

        }
    }

    // Place start and goal in map.
    mapArray[1][1] = 'S';
    mapArray[m_MapHeight-2][m_MapWidth -2] = 'G';
}

void StickDropOut::dispMap() {
    //グリッドマップを表示する．
    for (int i = 0; i < m_MapHeight; i++) {
        for (int j = 0; j < m_MapWidth; j++) {
            std::cout << mapArray[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void StickDropOut::makeStickMap() {
    //棒倒し法の実行

    //棒の位置だけを走査する．
    for (int i = 2; i < m_MapHeight - 2; i += 2) {
        for (int j = 2; j < m_MapWidth - 2; j += 2) {
            StickDropOut::pushStick(i, j);
        }
    }
}

int StickDropOut::generateRandom() {
    //random生成機

    //seed
    std::random_device rd;
    const auto seed = rd();

    //engine
    std::mt19937 rng(seed);

    //probability density distribution
    const double mean = 0.0;
    const double sd = 1.0;
    std::uniform_int_distribution<> rand100(0, 99);     // [0, 99] 範囲の一様乱数

    return rand100(rng);
}

bool StickDropOut::pushStick(int y, int x) {
    //棒を倒す再帰関数.
    //棒の座標を受け取り，その座標にある棒を倒す.
    //棒を倒す方向は，上方向を0として右回りに1,2,3とする．

    int setx = x;
    int sety = y;

    //determine stick push direction.
    int number = StickDropOut::generateRandom() % 4;

    //棒を倒す先の座標をセット
    if (number == 0) {
        sety--;
    } else if (number == 1) {
        setx++;
    } else if (number == 2) {
        sety++;
    } else if (number == 3) {
        setx--;
    }

    if( mapArray[sety][setx] == ' ' ){
        mapArray[sety][setx] = m_wall;
        return true;
    }else{
        return StickDropOut::pushStick(y,x);
    }

}

void StickDropOut::summonRobot() {
    //ロボットを召喚する．
    mapArray[1][1] = m_robot;
    mapArray[m_MapHeight-2][m_MapWidth -2] = 'G';
    StickDropOut::setRobotLocate(1,1);
}

void StickDropOut::setRobotLocate(int x , int y) {
    //ロボットの座標を記録する．
    m_robotLocation[1] = x;
    m_robotLocation[0] = y;
}

int StickDropOut::moveRobot(int direction) {
    //ロボットの移動方向(int direction)は，上方向を0として右回りに1,2,3とする．

    int setx = m_robotLocation[1];
    int sety = m_robotLocation[0];

    //ロボットの移動先の座標をセット
    if (direction == 0) {
        setx--;
    } else if (direction == 1) {
        sety++;
    } else if (direction == 2) {
        setx++;
    } else if (direction == 3) {
        sety--;
    }

    if(mapArray[setx][sety] == 'W'){
        return -1;
    }else if(mapArray[setx][sety] == 'G'){
        deleteRobot();
        setRobotLocate(setx,sety);
        mapArray[m_robotLocation[1]][m_robotLocation[0]] = 'R';
        deleteRobot();
        return 3;
    }else{
        deleteRobot();
        setRobotLocate(setx,sety);
        mapArray[m_robotLocation[1]][m_robotLocation[0]] = 'R';
        return 0;
    }

}

void StickDropOut::deleteRobot() {
    mapArray[m_robotLocation[1]][m_robotLocation[0]] = ' ';
}



