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
    TriviaNode *first; 
    TriviaNode *latest;
    TriviaNode *current; // <- Placeholder for iteration.  
    int questions; 
    int score;

    /* Constructor 
    *
    * NOTE: There is no user input for this because the entire program is 
    * the game.  
    */
    TriviaGame () { 
        first = nullptr; 
        latest = nullptr; 
        current = nullptr; 
        questions = 0; 
        score = 0;
    }

    /* Add question */
    void add_question(string question_input, string answer_input, int points_input) { 
        TriviaNode* node = new TriviaNode(question_input, answer_input, points_input);
        (questions == 0) ? first = node : latest->next = node; 
        latest = node; 
        questions++; 
    };

    /* Play Game (ask quesitons). Will return if the game was a success.
    * 
    *  NOTE: This will pull questions from the questions defined in TriviaNode. They
    *  are simply asked in order of appearance, there is no way to organize the 
    *  questions right now. 
    *  
    *  Also, for each iteration of asking questions, the program will keep a unique 
    *  score, which is automatically updated in the structure as a whole. The score 
    *  will be manually reset in another location.
    */
    int play_game(int num_of_questions) { 
        // Error handling...
        if (num_of_questions < 1 || questions < num_of_questions) { return false; }
        
        // Variables...
        int question_count = 0;
        score = 0;
        string user_answer;  
        current = first; 

        // Ask Questions...
        while (question_count < num_of_questions && current != nullptr) { 
            // Ask the question and assign points...
            cout << "\nQuestion: " << current->question << "\nAnswer: ";
            getline(cin, user_answer);

            if (user_answer.compare(current->answer) == 0) { 
                cout << "Your answer is correct! You receive " << current->points << " points.";
                score += current->points; 
            } else { 
                cout << "Your answer is wrong. The correct answer was " << current->answer << ".";
            }
            
            // Iteration...
            current = current->next; 
            question_count++; 
        } 

        // Return...
        cout << "\nYour total points: " << score << "\n";
        return true; 
    }    
};

//--------------------------- MAIN ---------------------------//
#define UNIT_TESTING 
#define ACTIVE_GAME

int main() { 
    // Create game...
    TriviaGame game = TriviaGame(); 

    game.add_question("How long was the shortest war on record? (Hint: how many minutes)", "38", 100);
    game.add_question("What was Bank of America's original name? (Hint: Bank of Italy or Bank of Germany)", "Bank of Italy", 50);
    game.add_question("What is the best-selling video game of all time? (Hint: Call of Duty or Wii Sports)?", "Wii Sports", 20);
    
    // Unit testing... 
    #ifdef UNIT_TESTING
        bool game_test;

        cout << "*** This is a debugging version ***\n";

        // Test ONE 
        cout << "Unit Test Case 1: Ask no question. The program should give a warning message." << endl;
        game_test = game.play_game(0);
        assert(!game_test); cout << "\nCase 1 Passed\n\n";        

        // Test TWO 
        cout << "Unit Test Case 2.1: Ask 1 question in the linked list. The tester enters an incorrect answer." << endl;
        game_test = game.play_game(1);
        assert(game.score == 0); cout << "\nCase 2.1 Passed\n\n";

        // Test THREE
        cout << "Unit Test Case 2.2: Ask 1 question in the linked list. The tester enters a correct answer." << endl;
        game_test = game.play_game(1);
        assert(game.score == 100); cout << "\nCase 2.2 Passed\n\n";

        // Test FOUR 
        cout << "Unit Test Case 3: Ask all the questions of the last trivia in the linked list." << endl;
        game_test = game.play_game(1);
        assert(game_test); cout << "\nCase 3 Passed\n\n";

    #endif

    // Close program...
    return 0;
}