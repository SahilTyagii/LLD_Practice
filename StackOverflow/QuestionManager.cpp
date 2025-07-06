#include "QuestionManager.hpp"

QuestionManager* QuestionManager::questionManagerInstance = nullptr;
mutex QuestionManager::mtx;

QuestionManager* QuestionManager::getQuestionManager() {
    if (questionManagerInstance == nullptr) {
        mtx.lock();
        if (questionManagerInstance == nullptr) {
            questionManagerInstance = new QuestionManager();
        }
        mtx.unlock();
    }
    return questionManagerInstance;
}

unordered_map<int, Question*> QuestionManager::getQuestionMap() {
    return questionMap;
}

Question* QuestionManager::getQuestion(int questionId) {
    return questionMap[questionId];
}

void QuestionManager::addQuestion(int id, Question* question) {
    questionMap[id] = question;
}