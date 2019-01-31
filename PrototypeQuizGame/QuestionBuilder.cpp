//
//  QuestionBuilder.cpp
//  PrototypeQuizGame
//
//  Created by Period 2 on 2019-01-31.
//  Copyright © 2019 Period 2. All rights reserved.
//
//  Known limitations: If the file is not formated exactly correct the code will fail with an error.

#include <fstream>
#include <vector>
#include <iostream>
#include "QuestionBuilder.hpp"

void QuestionBuilder::generate(string file){
    ifstream inFile(file);
    
    std::vector<MCQuestion> building;
    
    cout << "Question building start \n";
    
    if(inFile.is_open()){
        cout << "Loading online questions \n";
        //Use it
        string buffline;
        int qcount = 0;
        
        while(inFile.good()){
            //Generate a question
            std::getline(inFile, buffline);
            building.push_back(MCQuestion());
            building.at(qcount).setQuestion(buffline);
            
            std::getline(inFile, buffline);
            building.at(qcount).setA(buffline);
            
            std::getline(inFile, buffline);
            building.at(qcount).setB(buffline);
            
            std::getline(inFile, buffline);
            building.at(qcount).setC(buffline);
            
            std::getline(inFile, buffline);
            building.at(qcount).setD(buffline);
            
            std::getline(inFile, buffline);
            building.at(qcount).setCorrect(buffline);
            
            qcount++;
        }
        inFile.close();
        
        //Once all questions have been loaded put 10 into the array.
        for(int i = 0; i < 2; i++){
            generated[i] = building.at(i);
        }
        
    }else{
        //Load offline questions
        cout << "Questions failed, resorting to offline \n";
        generated[0] = MCQuestion("Hello World", "No", "Yes", "True", "False", "B");
        generated[1] = MCQuestion("Goodbye World", "Awe", "Yay", "What", "Hey!", "A");
        
    }
}

void QuestionBuilder::findDir(){
    ofstream idk("HelloWorld.txt");
    idk<<100<<endl;
    idk.close();
}
