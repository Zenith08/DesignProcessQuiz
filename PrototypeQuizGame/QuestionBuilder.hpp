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
    MCQuestion generated[10];
    
    void generate(string file);
    
    //TEMP
    void findDir();
};

#endif /* QuestionBuilder_hpp */
