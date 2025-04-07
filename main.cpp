#include <iostream>
#include <string>
#include "User.h"
#include "Cat.h"
#include "TranslationQuiz.h"

using namespace std;

int main()
{
    User user("Spurga");

    TranslationQuiz quiz(user);
    quiz.addWordPair("hello", "hallo");
    quiz.addWordPair("cat", "katze");
    quiz.addWordPair("dog", "hund");

    quiz.startQuiz();

    return 0;
}
