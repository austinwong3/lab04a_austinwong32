#include "WordCount.h"

#include <iostream>
#include "tddFuncs.h"
using namespace std;

int main() {
    cout << "adding valid words"<<endl;
    WordCount w;
    w.incrWordCount("hello");
    w.incrWordCount("wassup");
    w.incrWordCount("deuces");
    
    ASSERT_EQUALS(3,w.getTotalWords());
    ASSERT_EQUALS(3,w.getNumUniqueWords());
    ASSERT_EQUALS(1,w.getWordCount("hello"));
    ASSERT_EQUALS(2,w.incrWordCount("hello"));
    ASSERT_EQUALS(4,w.getTotalWords());
    ASSERT_EQUALS(3,w.getNumUniqueWords());
    ASSERT_EQUALS(2,w.getWordCount("hello"));

    cout << "adding invalid words"<<endl;
    ASSERT_EQUALS(3,w.incrWordCount("__123123123123hello-123")); //just invalid
    ASSERT_EQUALS(4,w.incrWordCount("-__123123123123hello-123-")); // starts with -
    ASSERT_EQUALS(5,w.incrWordCount("'_123123123123hello-123'")); //starts with '
    ASSERT_EQUALS(0,w.incrWordCount("")); //empty string
    ASSERT_EQUALS(7,w.getTotalWords());
    ASSERT_EQUALS(3,w.getNumUniqueWords());

    ASSERT_EQUALS(1,w.incrWordCount("hel-lo")); //- center
    ASSERT_EQUALS(4,w.getNumUniqueWords());
    ASSERT_EQUALS(8,w.getTotalWords());

    ASSERT_EQUALS(1,w.incrWordCount("hel'lo")); //' center
    ASSERT_EQUALS(5,w.getNumUniqueWords());
    ASSERT_EQUALS(9,w.getTotalWords());

    cout << "testing caps"<<endl;
    ASSERT_EQUALS(6,w.incrWordCount("hElLO")); //' center
    ASSERT_EQUALS(5,w.getNumUniqueWords());
    ASSERT_EQUALS(10,w.getTotalWords());


    return 0; //stub
}