#pragma once

#include "Commentable.hpp"
#include "Votable.hpp"
#include "Question.hpp"

class Answer: public Commentable, Votable {
private:
    int id;
    string content;
    User* author;
    chrono::system_clock::time_point creationDate;
    Question* question;
    bool isAccepted;
public:
    Answer(string content, User* author, Question* question): content(content), author(author), question(question) {
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
};