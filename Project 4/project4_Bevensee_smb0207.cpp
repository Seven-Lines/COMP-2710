/* 
* AUTHOR: Sean Bevensee
* AUB ID: smb0207
* FILE NAME: project4_bevensee_smb0207.cpp
*
* To compile use command "g++ project4_Bevensee_smb0207.cpp"  
* in parent directory. 
*
* I used the "Project4.pdf" file on Canvas. I got my information 
* and the basic implementation of structures from w3schools.com. 
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <assert.h>
using namespace std;

//----------- STRUCTURES -----------//
/* Trivia Node */
struct TriviaNode { 
    string question; 
    string answer; 
    int points; 
    TriviaNode *next; 

    // > Constructor
    TriviaNode (string question_input, string answer_input, int points_input) { 
        question = question_input; 
        answer = answer_input; 
        points = points_input;
        next = nullptr; 
    };
};