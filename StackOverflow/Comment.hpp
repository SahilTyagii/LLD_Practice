#pragma once
#include "Common.hpp"
#include "Commentable.hpp"
#include "User.hpp"

class Comment {
private:
    int id;
    static int nextId;
    string content;
    Commentable* commentable;
    User* author;
    chrono::system_clock::time_point creationDate;
public:
    Comment(Commentable* commentable, User* author, string content): id(nextId++), commentable(commentable), author(author), content(content) {
        author->addComment(this);
        commentable->addComment(this);
        creationDate = chrono::system_clock::now();
    }
    int getId() {
        return id;
    }
    string getContent() {
        return content;
    }
};