#include "UserManager.hpp"
#include "QuestionManager.hpp"
#include "TagManager.hpp"
#include "Common.hpp"

int main() {
    UserManager* userManager = UserManager::getUserManager();
    QuestionManager* questionManager = QuestionManager::getQuestionManager();
    TagManager* tagManager = TagManager::getTagManager();

    User* sahil = new User("Sahil Tyagi", "tyagi28sahil@gmail.com");
    User* punisher = new User("Frank Castle", "realpunisher@gmail.com");
    User* billy = new User("Billy Russo", "russobilly@gmail.com");

    Question* howToReload = new Question("How to reload a Magnum 400?", sahil);
    questionManager->addQuestion(howToReload->getId(), howToReload);

    Answer* howToReloadAnswer = new Answer("Search on youtube!", punisher, howToReload);
    Comment* commentToSahil = new Comment(howToReload, billy, "Why do you need to know that!?");
    Comment* commentToPunisher = new Comment(howToReloadAnswer, billy, "sybau");

    Vote* upVote = new Vote(howToReload, billy, 1);
    Vote* downVote = new Vote(howToReloadAnswer, billy, -1);

    Tag* tag1 = new Tag("Gun");
    Tag* tag2 = new Tag("Punisher");
    Tag* tag3 = new Tag("Daredevil");
    
    tagManager->addTag(tag1->getName(), tag1);
    tag1->addQuestion(howToReload);

    tagManager->addTag(tag2->getName(), tag2);
    tag2->addQuestion(howToReload);

    tagManager->addTag(tag2->getName(), tag2);
    tag2->addQuestion(howToReload);

    sahil->printDetails();
    punisher->printDetails();
    billy->printDetails();

    return 0;
}