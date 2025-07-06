#pragma once

#include "Answerable.hpp"
#include "Commentable.hpp"
#include "Taggable.hpp"
#include "Votable.hpp"
#include "User.hpp"

class Question: public Answerable, Commentable, Taggable, Votable {
private:
    int id;
    string content;
    User* author;
    chrono::system_clock::time_point creationDate;
public:
    Question(string content, User* author): id(id), content(content), author(author) {
        creationDate = chrono::system_clock::now();
    }
    int getId() {
        return id;
    }
    void addAnswer(Answer* answer) override {
        answerMap[answer->getId()] = answer;
    }
    unordered_map<int, Answer*> getAnswerMap() const override {
        return answerMap;
    }
    void addTag(Tag* tag) override {
        tagsMap[tag->getId()] = tag;
    }
    unordered_map<int, Tag*> getTagsMap() const override {
        return tagsMap;
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