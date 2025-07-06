#pragma once
#include "Common.hpp"
#include "Commentable.hpp"
#include "User.hpp"

class Comment {
private:
    int id;
    string content;
    Commentable* commentable;
    User* author;
    chrono::system_clock::time_point creationDate;
public:
    Comment(Commentable* commentable, User* author, string content): commentable(commentable), author(author), content(content) {
        creationDate = chrono::system_clock::now();
    }
    int getId() {
        return id;
    }
};