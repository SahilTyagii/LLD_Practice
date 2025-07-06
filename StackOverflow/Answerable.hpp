#pragma once

#include "Common.hpp"
#include "Answer.hpp"

class Answerable {
protected:
    unordered_map<int, Answer*> answerMap;
public:
    virtual unordered_map<int, Answer*> getAnswerMap() const = 0;
    virtual void addAnswer(Answer*) = 0;
};