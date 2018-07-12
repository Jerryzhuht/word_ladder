
//how to find a word ladder from word w1 to w2:
//    create a queue of stacks, initially containing only a single stack storing {w1}.
//    repeat until queue is empty or w2 is found:
//        dequeue a stack s.
//        for each valid unused English word w
//                that is a "neighbor" (differs by 1 letter)
//                of the word on top of s:
//            create a new stack s2 whose contents are the same as s,
//                    but with w added on top,
//            and add s2 to the queue.
#include <iostream>
#include "console.h"
#include <string>
#include "lexicon.h"
#include "strlib.h"
#include "simpio.h"
#include "vector.h"
#include "queue.h"
#include "filelib.h"
#include "stack.h"
using namespace std;


Set <string> transferDictionary(){

    ifstream infile;
    promptUserForFile(infile, "Dictionary name?");
    Set<string>file_set;

    string line;
    while(getline(infile, line)){
        file_set.add(line);

    }
return file_set;

}

Stack <string> findNeighbours(string word1, string word2, const Set<string> & dictionary){
    Queue<Stack<string> > queueOfStacks;
    Stack<string> s1;
    s1.push(word1);
    queueOfStacks.enqueue(s1);
    Set<string> usedWord;
    usedWord.add(word1);

    while (queueOfStacks.size() != 0){
        Stack<string> analyzingStack = queueOfStacks.dequeue();
        string analyzingWord = analyzingStack.peek();
        int len = analyzingWord.length();

        for (char r = 'a'; r <= 'z'; r ++) {
            //queueOfStacks.dequeue();
            for (int i = 0; i < len; i++) {
                //substitute one letter in the word to the letter in the alphabet and assign it to a new word
                string neighbourWord;
                neighbourWord = analyzingWord;
                neighbourWord[i] = r;
                //new word is not old word
                if (neighbourWord != analyzingWord){
                    if((dictionary.contains(neighbourWord)==true) && (usedWord.contains(neighbourWord)==false)){
                        analyzingStack.push(neighbourWord);
                        queueOfStacks.enqueue(analyzingStack);
                    }
                    if(neighbourWord == word2){
                        return analyzingStack;
                    }
                }
            }
        }
    }
    cout << "Exhausted!"<<endl;
    Stack<string> emptyStack;
    return emptyStack;

}


int main() {
    cout << "Welcome to CS 106B/X Word Ladder!" << endl;
    cout << "Please give me two English words, and I will convert the" << endl;
    cout << "first into the second by modifying one letter at a time." << endl;
    cout<<endl;

    Set<string> dictionary = transferDictionary();
    while(true){
        string word1 = getLine("Word 1 (or Enter to quit): ");
        if (word1 ==""){
            break;
        }
        string word2 = getLine("Word 2 (or Enter to quit): ");
        if (word2 ==""){
            break;
        }

        Stack<string> presentStack = findNeighbours(word1,word2,dictionary);
        if(presentStack.isEmpty()){
            cout<<"Exhausted"<<endl;
        }
        while(!presentStack.isEmpty()){
            string word = presentStack.pop();
            cout<<word<<" ";

        }
        cout<<endl;
        cout<<endl;
    }


    cout << "Have a nice day." << endl;
    return 0;
}
