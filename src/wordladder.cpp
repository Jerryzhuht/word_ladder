
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
using namespace std;

void getWords() {
    //prompt the user for two words
    string word1 = getLine("Word 1 (or Enter to quit): ");
    string word2 = getLine("word 2 (or Enter to quit): ");
}

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

Stack <string> findNeighbours(string word1, string word2, const Set<string> & infile){
    Queue<Stack<string> > queueOfStacks;
    while (queueOfStacks.size() != 0){
        for (char r = 'a'; r <= 'z'; r ++) {
            queueOfStacks.dequeue();
            for (int i = 0; i < word1.length(); i++) {
                //enqueue the orignal word to the queue
                Stack<string> q;
                q.push(word1);
                //substitute one letter in the word to the letter in the alphabet and assign it to a new word
                string newWord1 = word1;
                newWord1[i] = r;
                //Check if the new word (neighbour is a valid English word
                if (infile.contains(newWord1)){
                    //if the word(Newly found neighbour is valid aka can be found in the dictionary, add the neighbour to the word and form a new queue
                    Stack<string> q1;
                    q1 = queueOfStacks.peek();
                    q1.push(word1);
                    q1.push(newWord1);
                    // Enqueue the stack to the queue
                    queueOfStacks.enqueue(q1);
                    if (word1 == word2){
                        return q1;

                    }
                    else if (queueOfStacks.size() == 0) {
                        return null
                    }
                }
            }
        }
    }

}

int main() {
    // TODO: Finish the program!
    string word1, word2;
    set Dictionary;

    cout << "Welcome to CS 106B/X Word Ladder!" << endl;
    cout << "Please give me two English words, and I will convert the" << endl;
    cout << "first into the second by modifying one letter at a time." << endl <<endl;
    ifstream infile;

//    promptuserForFile(infile, "Dictionary file name:");

    string promptUserForFile(ifstream& stream, string prompt = "Dictionary file name:", string reprompt = "Unable to open that file. Try again.");
//    while (input.fail()){
//        input.clear();
//        cout<<"Unable to open that file. Try again."<<endl;
//        cin>>filename;
//        input.open(infile.c.str());

//    }
    cout << "Dictionary file name: dictionary.txt" << endl << endl;
    cout << "word1 (or Enter to quit):"<<word1<< endl;
    cout << "word2 (or Enter to quit):"<<word2<< endl;
    cout << "A ladder from data back to code:"<<endl;
    cout << findNeighbours(word1, word2, set)<<endl;

    cout << "Word 1 (or Enter to quit): "<< endl;
    cout << "Have a nice day." << endl;
    return 0;
}
