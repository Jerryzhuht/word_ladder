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
    promptUserForFile(infile, "Dictionary file name?");
    Set<string>file_set;

    string line;
    while(getline(infile, line)){
        file_set.add(line);

    }
    cout<<endl;
return file_set;

}

Stack <string> findNeighbours(string word1, string word2, const Set<string> & dictionary){
    Queue<Stack<string> > queueOfStacks;
    Stack<string> initStack;
    initStack.push(word1);
    queueOfStacks.enqueue(initStack);
    Set<string> usedWord;
    usedWord.add(word1);

    while (queueOfStacks.size() != 0){
        //take out the first stack of the queue
        Stack<string> analyzingStack = queueOfStacks.dequeue();
        //check out the last word of the stack
        string analyzingWord = analyzingStack.peek();
        int len = analyzingWord.length();

        for (char r = 'a'; r <= 'z'; r ++) {
            for (int i = 0; i < len; i++) {
                //substitute one letter in the word to the letter in the alphabet and assign it to a new word
                string neighbourWord;
                neighbourWord = analyzingWord;
                neighbourWord[i] = r;
                //if new word is not old word
                if (neighbourWord != analyzingWord){
                    //if dictionary have this word and this word not used previously
                    if((dictionary.contains(neighbourWord)==true) && (usedWord.contains(neighbourWord)==false)){
                        //push into new stack
                        Stack<string> newStack = analyzingStack;
                        newStack.push(neighbourWord);
                        //if new word is the correct word
                        if(neighbourWord == word2){
                            return newStack;
                        }
                        //enqueue this current stack
                        queueOfStacks.enqueue(newStack);
                        //add new word in used word
                        usedWord.add(neighbourWord);
                    }


                }
            }
        }
    }
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
        word1 = toLowerCase(word1);
        if (word1 ==""){
            break;
        }
        string word2 = getLine("Word 2 (or Enter to quit): ");
        word2 = toLowerCase(word2);
        if (word2 ==""){
            break;
        }

        if((dictionary.contains(word1)==false)||(dictionary.contains(word2)==false)){
            cout<<"The two words must be found in the dictionary."<<endl;
            cout<<endl;
            continue;
        }

        if(word1.length() != word2.length()){
            cout<<"The two words must be the same length."<<endl;
            cout<<endl;
            continue;
        }

        if(word1 == word2){
            cout<<"The two words must be different."<<endl;
            cout<<endl;
            continue;
        }

        Stack<string> presentStack = findNeighbours(word1,word2,dictionary);
        if(presentStack.isEmpty()){
            cout<<"No word ladder found from azure back to metal."<<endl;
            cout<<endl;
            continue;
        }
        cout << "A ladder from "<< word2 <<" back to "<<word1 << ":"<<endl;
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
