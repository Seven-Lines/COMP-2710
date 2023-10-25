/* 
* AUTHOR: Sean Bevensee
* AUB ID: smb0207
* FILE NAME: project4_bevensee_smb0207.cpp
*
* To compile use command "g++ project4_Bevensee_smb0207.cpp"  
* in parent directory. 
*
* I used the "Project4.pdf" file on Canvas. I got my information 
* on structures and linked lists from w3schools.com. Other than the basics, 
* I got specifics from...
*   - getline() - https://www.geeksforgeeks.org/getline-string-c/
*  
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <assert.h>
using namespace std;

//--------------------------- STRUCTURES ---------------------------//
/* Trivia Node */
struct TriviaNode { 
    string question; 
    string answer; 
    int points; 
    TriviaNode *next; 

    // Constructor
    TriviaNode (string question_input, string answer_input, int points_input) { 
        question = question_input; 
        answer = answer_input; 
        points = points_input;
        next = nullptr; 
    };
};

/* TriviaGame */
struct TriviaGame {
    TriviaNode *oldest; 
    TriviaNode *latest;
    int questions; 
    int score;

    /* Constructor 
    *
    * NOTE: There is no user input for this because the entire program is 
    * the game.  
    */
    TriviaGame () { 
        oldest = nullptr; 
        latest = nullptr; 
        questions = 0; 
        score = 0;
    }

    // Add question
    void add_question(string question_input, string answer_input, int points_input) { 
        TriviaNode* node = new TriviaNode(question_input, answer_input, points_input);
        (questions == 0) ? oldest = node : latest->next = node; 
        latest = node; 
        questions++; 
    };

    // Ask question
    void ask_question(int current_quesiton) { 

    }

};

//--------------------------- MAIN ---------------------------//
int main() { 
    TriviaGame game = TriviaGame(); 
    
    game.add_question("test question", "test answer", 100);


    return 0;
}