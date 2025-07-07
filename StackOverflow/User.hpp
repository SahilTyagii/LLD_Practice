#pragma once

#include <string>
#include <unordered_map>
using namespace std;

class Question;  // <-- forward declaration
class Answer;
class Comment;

class User {
private:
    int id;
    static int nextId;
    string username;
    string email;
    int reputation;
    unordered_map<int, Question*> questions;
    unordered_map<int, Answer*> answers;
    unordered_map<int, Comment*> comments;
public:
    User(string username, string email);
    void addQuestion(Question* q);
    void addAnswer(Answer* q);
    void addComment(Comment* q);
    int getId();
    int getReputation();
    void addReputation(int value);
    unordered_map<int, Question*> getQuestions();
    unordered_map<int, Answer*> getAnswers();
    unordered_map<int, Comment*> getComments();
    void printDetails();
};