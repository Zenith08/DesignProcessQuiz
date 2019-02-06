//
//  StringUtils.cpp
//  PrototypeQuizGame
//
//  Created by Period 2 on 2019-02-05.
//  Copyright © 2019 Period 2. All rights reserved.
//
//  Known limitation: This will only work for the letters included in the game.

#include "StringUtils.hpp"

using namespace std;

string StringUtil::toUpperCase(string valueIn){
    if(valueIn.compare("a") == 0){
        return "A";
    }else if(valueIn.compare("b") == 0){
        return "B";
    }else if(valueIn.compare("c") == 0){
        return "C";
    }else if(valueIn.compare("d") == 0){
        return "D";
    }else if(valueIn.compare("e") == 0){
        return "E";
    }else if(valueIn.compare("f") == 0){
        return "F";
    }else if(valueIn.compare("g") == 0){
        return "G";
    }
    
    return "null";
}
