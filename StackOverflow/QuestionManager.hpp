#pragma once

#include "Common.hpp"
#include "Question.hpp"
#include <mutex>

class QuestionManager {
private:
    static QuestionManager* questionManagerInstance;
    unordered_map<int, Question*> questionMap;
    static mutex mtx;
    QuestionManager() {};
public:
    static QuestionManager* getQuestionManager();
    unordered_map<int, Question*> getQuestionMap();
    Question* getQuestion(int questionId);
    void addQuestion(int id, Question* question);
};