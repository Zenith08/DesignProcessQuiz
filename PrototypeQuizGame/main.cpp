//
//  main.cpp
//  PrototypeQuizGame
//
//  Title: Quiz Prototype
//  Description:
//  This is a testing draft for the quiz game project for the first programming project in Programming Level 2
//  It is intended to be used to try new creations and attempt new ideas.
//  Designed by: Kaiden Richardson
//  Date Created: January 29, 2019
//  Date last modified: Sometime after that.
//
//  Known Limitations: The answer must be upper or lowercase depending on what is initially defined for the questions.

#include <iostream>

#include <chrono>
#include <thread>
#include "MultipleChoiceQuestion.hpp"
#include "QuestionBuilder.hpp"

using namespace std;

//The total number of questions in the quiz.
const int maxQuestions = 2;
//Makes every display of dashes to line things up the same.
const string dashes = "-------------------------";

//The array of all questions which will be asked in this quiz.
MCQuestion questions[maxQuestions];

//The number of questions the player get's correct.
int score = 0;

//Basically just wait for a number of miliseconds.
void delay(int mSec);
void loadQuestions();

int main(int argc, const char * argv[]) {
    
    //Define the initial questions. Should this be on github?
    /*questions[0] = MCQuestion("Hello World", "No", "Yes", "True", "False", "B");
    questions[1] = MCQuestion("Goodbye World", "Awe", "Yay", "What", "Hey!", "A");*/
    
    loadQuestions();
    
    //Introduction
    cout << "Quiz has begun! \n";
    cout << dashes + "\n";
    
    //A buffer to hold the user's input throughout the program.
    string ans;
    
    //Main game loop of asking questions.
    for(int i = 0; i < maxQuestions; i++){
        delay(1000); //Delay slightly before each question
        
        //Tell them what question it is and state the question.
        cout << "Question Number? " << i+1 << "\n";
        cout << dashes + "\n";
        questions[i].printQuestion();
        
        //If they enter a valid answer (A, B, C, D) then this loop will only run once.
        //Otherwise this will repeat until we get a valid answer.
        do{
            //Get the answer and validate against what is considered a valid answer.
            cin >> ans;
            if(questions[i].validAns(ans)){
            
            }else{
                cout << "Answer must be either A, B, C, or D \n";
            }
        }while(questions[i].validAns(ans) == false);
        
        //Once we're here it is a valid answer.
        //Now we need to see if it is the correct answer.
        if(questions[i].isCorrect(ans)){
            score++;
            cout << "Correct, good job. \n";
        }else{
            cout << "Sorry, wrong answer. The correct answer was " + questions[i].getCorrectAns() + "\n";
        }
        cout << dashes + "\n";
    }
    
    delay(500); //Small delay before results.
    
    //Ends the game and gives summary statistics of the users performance.
    cout << dashes + "\n";
    cout << "Quiz Finished \n";
    cout << "Final Score " << score << " out of " << maxQuestions << "! \n";
    float scoreBuf = score;
    float questionBuf = maxQuestions;
    
    cout << "That's " << (scoreBuf/questionBuf)*100.0 << " Percent! \n";
    
    cout << dashes + "\n";
    
    return 0;
}

void delay(int mSec){
    this_thread::sleep_for(chrono::milliseconds(mSec));
}

void loadQuestions(){
    QuestionBuilder builder = QuestionBuilder();
    builder.findDir();
    
    builder.generate("basequestions.txt");
    for(int i = 0; i < maxQuestions; i++){
        questions[i] = builder.generated[i];
    }
}
