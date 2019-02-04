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
//  Known Limitations: The answer must be upper case A, B, C, or D.
//                     The catagory must be upper case A, B, C, D, E, F, or G.
//                     Ending the quiz without answering questions gets a score of nan.

#include <iostream>

#include <chrono>
#include <thread>
#include "MultipleChoiceQuestion.hpp"
#include "QuestionBuilder.hpp"

using namespace std;

//The total number of questions in the quiz.
const int maxQuestions = 5;
//Makes every display of dashes to line things up the same.
const string dashes = "----------------------------------------";

string catagory = "null!?";
int catNum = -1;

//The array of all questions which will be asked in this quiz.
MCQuestion questions[maxQuestions];

//The number of questions the player get's correct.
int totalRight = 0;
int score = 0;
int questionsTaken = 0;

//Basically just wait for a number of miliseconds.
void delay(int mSec);
void loadQuestions();
void offerQuestions();
void gameLoop();

void endCatagory();

//Question catagories
bool catComplete[6];
int catScore[6];
bool inQuiz = true;

void defining();
void ideating();
void prototyping();
void testing();
void making();
void sharing();

int main(int argc, const char * argv[]) {
    inQuiz = true;
    
    while(inQuiz == true){
        offerQuestions();
        if(inQuiz){
            gameLoop();
        }
    }
    
    cout << dashes << endl;
    cout << "Quiz ended. Thanks for playing." << endl;
    cout << "Final Score " << totalRight << " out of " << questionsTaken << "!" << endl;
    float scoreBuf = totalRight;
    float questionBuf = questionsTaken;
    
    cout << "That's " << (scoreBuf/questionBuf)*100.0 << " Percent!" << endl;

    return 0;
}

void delay(int mSec){
    this_thread::sleep_for(chrono::milliseconds(mSec));
}

void gameLoop(){
    score = 0;
    questionsTaken += maxQuestions;
    
    //Introduction
    cout << dashes << endl;
    cout << "Quiz has begun!" << endl;
    cout << "Catagory: " + catagory << endl;
    cout << dashes << endl;
    
    //A buffer to hold the user's input throughout the program.
    string ans;
    
    //Main game loop of asking questions.
    for(int i = 0; i < maxQuestions; i++){
        delay(500); //Delay slightly before each question
        
        //Tell them what question it is and state the question.
        cout << "Question Number " << i+1 << "   Catagory " + catagory << endl;
        cout << dashes << endl;
        questions[i].printQuestion();
        
        //If they enter a valid answer (A, B, C, D) then this loop will only run once.
        //Otherwise this will repeat until we get a valid answer.
        do{
            //Get the answer and validate against what is considered a valid answer.
            cin >> ans;
            if(questions[i].validAns(ans)){
                
            }else{
                cout << "Answer must be either A, B, C, or D." << endl;
            }
        }while(questions[i].validAns(ans) == false);
        
        //Once we're here it is a valid answer.
        //Now we need to see if it is the correct answer.
        if(questions[i].isCorrect(ans)){
            score++;
            cout << "Correct, good job." << endl;
        }else{
            cout << "Sorry, wrong answer. The correct answer was " + questions[i].getCorrectAns() << endl;
        }
        cout << dashes << endl;
    }
    
    delay(500); //Small delay before results.
    
    //Ends the game and gives summary statistics of the users performance.
    cout << dashes << endl;
    cout << "Quiz Finished!" << endl;
    cout << "Final Score " << score << " out of " << maxQuestions << "!" << endl;
    float scoreBuf = score;
    float questionBuf = maxQuestions;
    
    cout << "That's " << (scoreBuf/questionBuf)*100.0 << " Percent!" << endl;
    
    cout << dashes << endl;
    
    endCatagory();
    
    delay(750);
}

void endCatagory(){
    totalRight += score;
    catScore[catNum] = score;
    catComplete[catNum] = true;
}

void offerQuestions(){
    cout << dashes << endl;
    cout << "Choose a step in the design process." << endl;
    cout << dashes << endl;
    if(catComplete[0] == false)
        cout << "A: Defining" << endl;
    if(catComplete[1] == false)
        cout << "B: Ideating" << endl;
    if(catComplete[2] == false)
        cout << "C: Prototyping" << endl;
    if(catComplete[3] == false)
        cout << "D: Testing" << endl;
    if(catComplete[4] == false)
        cout << "E: Making" << endl;
    if(catComplete[5] == false)
        cout << "F: Sharing" << endl;
    cout << "G: End Quiz" << endl;
    
    string input;
    bool valid = false;
    do{
        cin >> input;
        
        if((input.compare("A") == 0 && catComplete[0] == false) || (input.compare("B") == 0 && catComplete[1] == false) || input.compare("C") == 0 || input.compare("D") == 0 || input.compare("E") == 0 || input.compare("F") == 0 || input.compare("G") == 0){
            valid = true;
        }else{
            cout << "Sorry, you must enter a letter based on the catagory you have not already taken." << endl;
        }
    }while(valid == false);
    
    if(input.compare("G") != 0){
        cout << "Alright, loading those questions" << endl;
    }
    
    if(input.compare("A") == 0){
        defining();
        catagory = "Defining";
        catNum = 0;
    }else if(input.compare("B") == 0){
        ideating();
        catagory = "Ideating";
        catNum = 1;
    }else if(input.compare("C") == 0){
        prototyping();
        catagory = "Prototyping";
        catNum = 2;
    }else if(input.compare("D") == 0){
        testing();
        catagory = "Testing";
        catNum = 3;
    }else if(input.compare("E") == 0){
        making();
        catagory = "Making";
        catNum = 4;
    }else if(input.compare("F") == 0){
        sharing();
        catagory = "Sharing";
        catNum = 5;
    }else if(input.compare("G") == 0){
        inQuiz = false;
    }
    
    delay(1000);
}

//All of the questions which will be aksed. ---------------------------------------------
void defining(){
    questions[0] = MCQuestion("In the defining process, it is important to find", "a design opportunity.", "someone to make it.", "How best to monetize it.", "a good computer to make it on.", "A");
    questions[1] = MCQuestion("Part of defining is", "taking creative risks.", "identify creative inspiration.", "identify potential users.", "use materials wisely.", "C");
    questions[2] = MCQuestion("What step is defining in the design process?", "2", "1", "5", "6", "B");
    questions[3] = MCQuestion("When defining a problem, what is not important.", "Having a problem statement.", "understanding solution requirements.", "research existing solutions.", "Planning and carying out design.", "D");
    questions[4] = MCQuestion("When finishing the defining stage, this can be useful.", "A clear list of criteria.", "A programming language to use.", "An ad for help.", "A list of issues with existing solutions.", "A");
}

void ideating(){
    questions[0] = MCQuestion("This is the step when creative risks can be suggested.", "Prototyping", "Defining", "Making", "Ideating", "D");
    questions[1] = MCQuestion("By the time ideating begins, this is already available.", "Abandoned prototypes.", "Project requirements.", "Viable options.", "A Macbook.", "B");
    questions[2] = MCQuestion("After ideating, only one idea should be continued and others should be abandoned.", "True", "False", "Only if the other ideas are bad.", "All viable options should remain open.", "D");
    questions[3] = MCQuestion("When ideating, you should", "brainstorm with all options available.", "keep track of who suggested the worst idea.", "question viability.", "make models of good suggestions.", "A");
    questions[4] = MCQuestion("The step after ideating is", "Testing.", "Defining", "Prototyping", "Making", "C");
}

void prototyping(){
    questions[0] = MCQuestion("At this point in development, what is started?", "Making a website to publish.", "Existing code is tested to make sure it works.", "Code is written to see if it works.", "Ideas are brainstormed as possabilities.", "C");
    questions[1] = MCQuestion("In prototyping, ", "Resources are changed as needed.", "Old ideas are deleted.", "Everything is properly tested.", "Creative risks are taken.", "A");
    questions[2] = MCQuestion("Durring prototyping, you should always ", "make a plan and cary it out.", "record all iterations of prototyping.", "identify potential feedback.", "avoid trying difficult ideas.", "B");
    questions[3] = MCQuestion("A project team had a clear list of possible ideas, they should now ", "make and publish it.", "test them for bugs.", "try to come up with even more creative ideas.", "design prototypes and get feedback.", "D");
    questions[4] = MCQuestion("After prototyping, a team uses", "all ideas.", "ideas that worked well.", "new ideas thought of while prototyping.", "ideas the manager suggested.", "B");
}

void testing(){
    questions[0] = MCQuestion("Testing should only begin after", "defining.", "sharing.", "prototyping.", "making.", "C");
    questions[1] = MCQuestion("What happens now that didn't while prototyping?", "Changes made are not loged.", "Ideas which do not work are abandoned.", "The project is published to the world.", "Brainstorming.", "B");
    questions[2] = MCQuestion("Ideas which are not abandoned are", "remade.", "restarted.", "tested.", "iterated.", "D");
    questions[3] = MCQuestion("When testing, changes should be made", "because it seems fun.", "because the data shows it doesn't work.", "anytime something doesn't seem right.", "only if it is critical to success.", "B");
    questions[4] = MCQuestion("After testing initial ideas, the next thing to do is", "make the project.", "prototype new ideas.", "define requirements.", "share the ideas with the world.", "A");
}

void making(){
    questions[0] = MCQuestion("The making phase begins after what finishes?", "Prototyping.", "Ideating.", "Defining.", "Testing.", "D");
    questions[1] = MCQuestion("In making, it is a good idea to", "make sure requirements are met.", "brainstorm new ideas.", "choose tools and technologies to make it.", "show the world the plan.", "C");
    questions[2] = MCQuestion("When making, the ideas used are", "ideas which were worked on in testing", "the best ones from prototyping.", "every idea thought of.", "none of the above.", "A");
    questions[3] = MCQuestion("The questions for this game should be written in what phase?", "Defining.", "Making.", "Sharing.", "Testing.", "B");
    questions[4] = MCQuestion("It is only good to do this after the making phase.", "Publish the project.", "Test for Bugs.", "Choose tools to use.", "Take risks creativly.", "A");
}

void sharing(){
    questions[0] = MCQuestion("What phase should be completed before sharing a project?", "Testing.", "Prototyping.", "Making.", "Defining.", "C");
    questions[1] = MCQuestion("When sharing, how should success be regarded?", "Always posativly.", "Critically.", "Negativly.", "Financially.", "B");
    questions[2] = MCQuestion("Who should a project be shared with?", "Whoever is appropriate for the project.", "Everyone.", "The client who ordered it.", "No one. Keep it to yourself.", "A");
    questions[3] = MCQuestion("After sharing a project, the team or developer should", "move on to the next project.", "reflect on abandoned ideas.", "prepare a followup product.", "reflect on the dsign process used.", "D");
    questions[4] = MCQuestion("By the time you're reading this question, the project has been", "shared with others.", "planned and defined.", "prototyped.", "assigned to a team.", "A");
}
