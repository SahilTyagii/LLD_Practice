#pragma once
#include <string>
using namespace std;

// Forward declarations
class User;
class Question;

class Answer: public Commentable, public Votable {
private:
    int id;
    static int nextId;
    string content;
    User* author;
    chrono::system_clock::time_point creationDate;
    Question* question;
    bool isAccepted;
public:
    Answer(string content, User* author, Question* question): id(nextId++), content(content), author(author), question(question) {
        author->addAnswer(this);
        question->addAnswer(this);
        creationDate = chrono::system_clock::now();
    }
    int getId() {
        return id;
    }
    void setAccepted(bool isAccepted) {
        this->isAccepted = isAccepted;
    }
    void addVote(Vote* vote) override {
        voteMap[vote->getId()] = vote;
    }
    int getVoteCount() const override {
        int voteCount = 0;
        for (auto& [id, v]: voteMap) {
            voteCount += v->getValue();
        }
        return voteCount > 0 ? voteCount : 0;
    }
    unordered_map<int, Comment*> getCommentMap() const override {
        return commentMap;
    }
    void addComment(Comment* comment) override {
        commentMap[comment->getId()] = comment;
    }
    string getContent() {
        return content;
    }
    User* getVoter() const override {
        return author;
    }
};