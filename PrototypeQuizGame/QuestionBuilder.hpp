//
//  QuestionBuilder.hpp
//  PrototypeQuizGame
//
//  Created by Period 2 on 2019-01-31.
//  Copyright © 2019 Period 2. All rights reserved.
//

#ifndef QuestionBuilder_hpp
#define QuestionBuilder_hpp

#include <stdio.h>
#include "MultipleChoiceQuestion.hpp"

class QuestionBuilder{
public:
    //Supposed to be a buffer of the questions generated before they are put into the main game loop.
    MCQuestion generated[10];
    //Asks for the questions to be made using the file specified.
    void generate(string file);
    
    //TEMP
    //A test method to try and write a file to find what directory it is located in.
    void findDir();
};

#endif /* QuestionBuilder_hpp */
