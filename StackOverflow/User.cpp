#include "User.hpp"
#include "Common.hpp"
#include "Question.hpp"
#include "Answer.hpp"
#include "Comment.hpp"

int User::nextId = 1;

User::User(string username, string email): id(nextId++), username(username), email(email) {
    reputation = 0;
}

void User::addQuestion(Question* q) {
    questions[q->getId()] = q;
}

void User::addAnswer(Answer* a) {
    answers[a->getId()] = a;
}

void User::addComment(Comment* c) {
    comments[c->getId()] = c;
}

int User::getId() {
    return id;
}

unordered_map<int, Question*> User::getQuestions() {
    return questions;
}

unordered_map<int, Answer*> User::getAnswers() {
    return answers;
}

unordered_map<int, Comment*> User::getComments() {
    return comments;
}

void User::printDetails() {
    cout << "\n\n";
    cout << "Username: " << username << endl;
    cout << "Email: " << email << endl;
    cout << "Reputation: " << reputation << endl;
    cout << "Questions Posted: " << endl;
    for (auto& [id, question]: questions) {
        cout << "\t" << id << ") " << question->getContent() << endl;
    }
    cout << "Answers Posted: " << endl;
    for (auto& [id, answer]: answers) {
        cout << "\t" << id << ") " << answer->getContent() << endl;
    }
    cout << "Comments Posted: " << endl;
    for (auto& [id, comment]: comments) {
        cout << "\t" << id << ") " << comment->getContent() << endl;
    }
    cout << "\n\n";
}

int User::getReputation() {
    return reputation;
}

void User::addReputation(int value) {
    reputation += value;
}