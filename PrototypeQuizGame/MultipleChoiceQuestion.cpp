//
//  MultipleChoiceQuestion.cpp
//  PrototypeQuizGame
//
//  Created by Period 2 on 2019-01-29.
//  Copyright © 2019 Period 2. All rights reserved.
//

#include "MultipleChoiceQuestion.hpp"
#include <iostream>

MCQuestion::MCQuestion(){
    MCQuestion("", "", "", "", "", "");
}

MCQuestion::MCQuestion(string quest, string a, string b, string c, string d, string cAns){
    question = quest;
    answers[0] = a;
    answers[1] = b;
    answers[2] = c;
    answers[3] = d;
    correct = cAns;
};

void MCQuestion::printQuestion(){
    cout << question +"\n";
    cout << "A)" + answers[0] + "    B)" + answers[1] + "\n";
    cout << "C)" + answers[2] + "    D)" + answers[3] + "\n";
}

bool MCQuestion::isCorrect(string letter){
    if(letter.compare(correct) == 0){
        return true;
    }else{
        return false;
    }
}

bool MCQuestion::validAns(string check){
    if(check.compare("A") == 0 || check.compare("B") == 0 || check.compare("C") == 0 || check.compare("D") == 0){
        return true;
    }else{
        return false;
    }
}

string MCQuestion::getCorrectAns(){
    return correct;
}
