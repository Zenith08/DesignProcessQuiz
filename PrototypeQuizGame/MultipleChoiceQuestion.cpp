//
//  MultipleChoiceQuestion.cpp
//  PrototypeQuizGame
//
//  Created by Period 2 on 2019-01-29.
//  Copyright © 2019 Period 2. All rights reserved.
//

#include "MultipleChoiceQuestion.hpp"
#include <iostream>

//A default constructor to allow the program to use the class in an array.
MCQuestion::MCQuestion(){
    MCQuestion("", "", "", "", "", "");
}

//A constructor which creates the multiple choice question with values for the question, all answers, and a correct answer.
MCQuestion::MCQuestion(string quest, string a, string b, string c, string d, string cAns){
    question = quest;
    answers[0] = a;
    answers[1] = b;
    answers[2] = c;
    answers[3] = d;
    correct = cAns;
}

void MCQuestion::printQuestion(){
    cout << question << endl; //Prints the question
    cout << "A) " + answers[0] + "    B) " + answers[1] << endl; //Should appear as A) <answer a>    B) <answer b>
    cout << "C) " + answers[2] + "    D) " + answers[3] << endl; //Should appear as C) <answer c>    D) <answer d>
}

bool MCQuestion::isCorrect(string letter){
    if(letter.compare(correct) == 0){ //If the input string matches the preset correct answer, this is true.
        return true;
    }else{
        return false; //Otherwise it's false.
    }
}

bool MCQuestion::validAns(string check){
    if(check.compare("A") == 0 || check.compare("B") == 0 || check.compare("C") == 0 || check.compare("D") == 0){ //If the input string can be a possible answer, then this returns true.
        return true;
    }else{
        return false; //Otherwise it returns false.
    }
}

//Returns the string representing the correct answer.
string MCQuestion::getCorrectAns(){
    return correct;
}

//Builder methods not for normal use
void MCQuestion::setQuestion(string qIn){
    question = qIn;
}

void MCQuestion::setA(string aIn){
    answers[0] = aIn;
}

void MCQuestion::setB(string bIn){
    answers[1] = bIn;
}

void MCQuestion::setC(string cIn){
    answers[2] = cIn;
}

void MCQuestion::setD(string dIn){
    answers[3] = dIn;
}

void MCQuestion::setCorrect(string ansIn){
    correct = ansIn;
}
