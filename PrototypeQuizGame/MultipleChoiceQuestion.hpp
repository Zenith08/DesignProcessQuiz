//
//  MultipleChoiceQuestion.hpp
//  PrototypeQuizGame
//
//  Created by Period 2 on 2019-01-29.
//  Copyright © 2019 Period 2. All rights reserved.
//
#ifndef MultipleChoiceQuestion_hpp
#define MultipleChoiceQuestion_hpp

#include <stdio.h>
#include <string>
#include <cstring>
using namespace std;
//A question will be asked to the user and has 4 answers only one of which is correct.
class MCQuestion{
    private:
        //The question which will be asked of the player.
        string question;
        //The 4 possible answers. (0 - A, 1 - B, 2 - C, 3 - D).
        string answers[4];
        //The correct answer represented by it's letter (A, B, C, D).
        string correct;
public:
    //The constructor to define everything a question needs.
    MCQuestion(string quest, string a, string b, string c, string d, string cAns);
    //The constructor to allow the array creation to work.
    MCQuestion();
    //Prints the question to the screen after formating.
    void printQuestion();
    //Returns true if the input matches this questions correct answer.
    bool isCorrect(string letter);
    //Returns true if the input is a possible answer. (A, B, C, D).
    bool validAns(string check);
    //Returns the string value of the correct answer.
    string getCorrectAns();
    
    //Builder methods should not be used by code except to generate questions
    void setQuestion(string qIn);
    void setA(string aIn);
    void setB(string bIn);
    void setC(string cIn);
    void setD(string dIn);
    void setCorrect(string ansIn);
};

#endif /* MultipleChoiceQuestion_hpp */
