#pragma once

#include "Common.hpp"
#include "Comment.hpp"

class Commentable {
protected:
    unordered_map<int, Comment*> commentMap;
public:
    virtual unordered_map<int, Comment*> getCommentMap() const = 0;
    virtual void addComment(Comment*) = 0;
};