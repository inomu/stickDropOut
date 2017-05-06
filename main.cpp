#include <iostream>
#include "StickDropOut.h"

#define GRID_WIDTH 5
#define GRID_HEIGHT 7

int main(){
    std::cout<<"Hello, World!"<<std::endl;

    StickDropOut s(GRID_WIDTH,GRID_HEIGHT);

    s.summonRobot();
    s.dispMap();

    //キーボードでの移動を実装．
    int c;
    int r;
    while(true) {
        c = getchar();
        rewind(stdin);
        if(c == 'w'){
            c = 0;
        }else if(c == 'd'){
            c = 1;
        }else if(c == 's'){
            c = 2;
        }else if(c == 'a'){
            c = 3;
        }else{
            std::cout << "not wasd" << std::endl;
            break;
        }

        r = s.moveRobot(c);
        if(r == 3){
            break;
        }
        std::cout << "r:" << r << std::endl;
        s.dispMap();
    }

    s.summonRobot();
    s.dispMap();



    return 0;
}