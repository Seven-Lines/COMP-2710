/* 
* AUTHOR: Sean Bevensee
* AUB ID: smb0207
* FILE NAME: project2_bevensee_smb0207.cpp
*
* To compile use command "g++ project1_Bevensee_smb0207.cpp"  
* in parent directory. 
*
* I used the "Project2.pdf" file on Canvas. I also referenced 
* this stackoverflow article for the shorthand version of if/else
* statements in C++: https://shorturl.at/qvFL3. For information on 
* "for" loops I used https://www.w3schools.com/cpp/cpp_for_loop.asp. 
* I used https://www.geeksforgeeks.org/static_cast-in-cpp/ for when I 
* used "<static_cast>".
*/

# include <iostream>
# include <stdlib.h>
# include <assert.h>
# include <ctime>
using namespace std;

//----------- INITIALIZE VARIABLES -----------//
const int aaron_accuracy = 33; 
const int bob_accuracy = 50; 
//const double charlie_accuracy = 1.0; < unused

//----------- FUNCTIONS -----------//
/* Wait for user... */  
void wait(void) { 
    cout << "Press Enter to continue...";
    cin.ignore().get(); 
}

/* Shoots Function... 
*
* NOTE: Will return TRUE if shot connects, and FALSE if shot 
* doesn't connect. 
*/
bool shoots(double accuracy) { 
    int shot_simulation = rand() % 100 + 1; 

    //return accuracy < shot_simulation ? true : false; 

    if (accuracy > shot_simulation) { return true; } else { return false; }
}


/* At least two alive... */ 
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive) { 
    int num_alive; 
    if (A_alive) { num_alive++; }
    if (B_alive) { num_alive++; }
    if (C_alive) { num_alive++; }
    if (num_alive >= 2) { return true; } else { return false; }
}

/* Shoots... 
* 
* Code (1) selects a target and (2) tests to see if the shot hit.
*
* NOTE: The following "[person]_shoots" functions won't run 
* in the first place if at_least_two_alive = false. IE: there 
* cannot be two false inputs. This hasn't been accounted for in the 
* following code. 
*/
string Aaron_shoots1(bool& B_alive, bool& C_alive) { 
    string target; 
    C_alive ? target = "c" : target = "b"; 
    if (shoots(aaron_accuracy)) { target == "c" ? C_alive = false : B_alive = false; }
    return target;
}

string Bob_shoots(bool& A_alive, bool& C_alive) { 
    string target; 
    C_alive ? target = "c" : target = "a";
    if (shoots(bob_accuracy)) { target == "c" ? C_alive = false : A_alive = false; }
    return target; 
}

string Charlie_shoots(bool& A_alive, bool& B_alive) { 
    string target; 
    B_alive ? target = "b" : target = "a";
    target == "b" ? B_alive = false : A_alive = false;
    return target; 
}

string Aaron_shoots2(bool& B_alive, bool& C_alive) { 
    /* NOTE: This code assumes that Charlie hits his shot 100% of 
     * the time and that there doesn't exist a possibility where 
     * either Bob or Charlie don't die in the first round.  */
    string target; 
    (B_alive && C_alive) ? target = "null" : target = Aaron_shoots1(B_alive, C_alive);  
    return target; 
}

//----------- TEST FUNCTIONS -----------//
/* At least two alive test... */
void test_at_least_two_alive(void) { 
    cout << "Unit Testing 1: Function at_least_two_alive()\n";
    
    cout << "\tCase 1: Aaron alive, Bob alive, Charlie alive\n";
    assert(true == at_least_two_alive(true, true, true));
    cout << "\t\tCase passed ...\n";
    
    cout << "\tCase 2: Aaron dead, Bob alive, Charlie alive\n";
    assert(true == at_least_two_alive(false, true, true));
    cout << "\t\tCase passed ...\n";
    
    cout << "\tCase 3: Aaron alive, Bob dead, Charlie alive\n";
    assert(true == at_least_two_alive(true, false, true));
    cout << "\t\tCase passed ...\n";
    
    cout << "\tCase 4: Aaron alive, Bob alive, Charlie dead\n";
    assert(true == at_least_two_alive(true, true, false));
    cout << "\t\tCase passed ...\n";
    
    cout << "\tCase 5: Aaron dead, Bob dead, Charlie alive\n";
    assert(false == at_least_two_alive(false, false, true));
    cout << "\t\tCase passed ...\n";
    
    cout << "\tCase 6: Aaron dead, Bob alive, Charlie dead\n";
    assert(false == at_least_two_alive(false, true, false));
    cout << "\t\tCase passed ...\n";
    
    cout << "\tCase 7: Aaron alive, Bob dead, Charlie dead\n";
    assert(false == at_least_two_alive(true, false, false));
    cout << "\t\tCase passed ...\n";
    
    cout << "\tCase 8: Aaron dead, Bob dead, Charlie dead\n";
    assert(false == at_least_two_alive(false, false, false));
    cout << "\t\tCase passed ...\n";
}

/* Shoots testing... */
void test_aaron_shoots1(void) { 
    bool b, c;
    cout << "Unit Testing 2: Function Aaron_shoots1(B_alive, C_alive)\n";

    cout << "\tCase 1: Bob alive, Charlie alive\n";
    b = true; c = true;
    assert("c" == Aaron_shoots1(b, c));
    cout << "\t\tAaron is shooting at Charlie\n";
    
    cout << "\tCase 2: Bob dead, Charlie alive\n";
    b = false; c = true;
    assert("c" == Aaron_shoots1(b, c));
    cout << "\t\tAaron is shooting at Charlie\n";

    cout << "\tCase 3: Bob alive, Charlie dead\n";
    b = true; c = false;
    assert("b" == Aaron_shoots1(b, c));
    cout << "\t\tAaron is shooting at Bob\n";
}

void test_bob_shoots(void) { 
    bool a, c;
    cout << "Unit 3 Testing: Function bob_shoots(A_alive, C_alive)\n";

    cout << "\tCase 1: Aaron alive, Charlie alive\n"; 
    a = true; c = true; 
    assert("c" == Bob_shoots(a, c)); 
    cout << "\t\tBob is shooting at Charlie\n";

    cout << "\tCase 2: Aaron dead, Charlie alive\n"; 
    a = false; c = true; 
    assert("c" == Bob_shoots(a, c)); 
    cout << "\t\tBob is shooting at Charlie\n";

    cout << "\tCase 3: Aaron alive, Charlie dead\n"; 
    a = true; c = false; 
    assert("a" == Bob_shoots(a, c)); 
    cout << "\t\tBob is shooting at Aaron\n";
}

void test_charlie_shoots(void) { 
    bool a, b;
    cout << "Unit 4 Testing: Function Charlie_shoots(A_alive, B_alive)\n";

    cout << "\tCase 1: Aaron alive, Bob alive\n";
    a = true; b = true; 
    assert("b" == Charlie_shoots(a, b));
    cout <<  "\t\tCharlie is shooting at Bob\n";

    cout << "\tCase 2: Aaron dead, Bob alive\n";
    a = false; b = true; 
    assert("b" == Charlie_shoots(a, b));
    cout <<  "\t\tCharlie is shooting at Bob\n";

    cout << "\tCase 3: Aaron alive, Bob dead\n";
    a = true; b = false; 
    assert("a" == Charlie_shoots(a, b));
    cout <<  "\t\tCharlie is shooting at Aaron\n";
}

void test_aaron_shoots2(void) { 
    bool b, c;
    cout << "Unit Testing 5: Function Aaron_shoots2(B_alive, C_alive)\n";

    cout << "\tCase 1: Bob alive, Charlie alive\n";
    b = true; c = true;
    assert("null" == Aaron_shoots2(b, c));
    cout << "\t\tAaron intentionally misses his first shot.\n\t\tBoth Bob and Charlie are alive.\n";
    
    cout << "\tCase 2: Bob dead, Charlie alive\n";
    b = false; c = true;
    assert("c" == Aaron_shoots2(b, c));
    cout << "\t\tAaron is shooting at Charlie\n";

    cout << "\tCase 3: Bob alive, Charlie dead\n";
    b = true; c = false;
    assert("b" == Aaron_shoots2(b, c));
    cout << "\t\tAaron is shooting at Bob\n";
}

/* Strategy testing... */
int test_strategy(int strat, int test_runs) { 
    int a_victory = 0, b_victory = 0, c_victory = 0;
    bool a_alive, b_alive, c_alive;

    for (int i = 0; i < test_runs; i++) { 
        a_alive = true; b_alive = true; c_alive = true; 

        while(at_least_two_alive(a_alive, b_alive, c_alive)) { 
            (a_alive && strat == 1) ? Aaron_shoots1(b_alive, c_alive) : (a_alive && strat == 2) ? Aaron_shoots2(b_alive, c_alive) : "";            
            b_alive ? Bob_shoots(a_alive, c_alive) : ""; 
            c_alive ? Charlie_shoots(a_alive, b_alive) : ""; 
        }

        a_alive ? a_victory++ : b_alive ? b_victory++ : c_victory++; 
    }

    cout << "Aaron won " << a_victory << "/" << test_runs << " duels or " << static_cast <double>(a_victory) / test_runs * 100 << "%\n";
    cout << "Bob won " << b_victory << "/" << test_runs << " duels or " << static_cast <double>(b_victory) / test_runs * 100 << "%\n";
    cout << "Charlie won " << c_victory << "/" << test_runs << " duels or " << static_cast <double>(c_victory) / test_runs * 100 << "%\n";

    return 3; 
}

//----------- MAIN -----------//
int main() { 
    /* Testing Functions... */  
    //test_at_least_two_alive(); wait(); 
    //test_aaron_shoots1(); wait();
    //test_bob_shoots(); wait(); 
    //test_charlie_shoots(); wait(); 
    //test_aaron_shoots2(); wait();

    cout << "Ready to test strategy 1 (run 10,000 times):\n"; wait();
    int strategy_1_effectiveness = test_strategy(1, 10000); cout << endl; 
    cout << "Ready to test strategy 2 (run 10,000 times):\n"; wait();
    int strategy_2_effectiveness = test_strategy(2, 10000); cout << endl;

    //(strategy_1_effectiveness > strategy_2_effectiveness) ? cout << "Strategy 1 is better than strategy 2.\n" : cout << "Strategy 2 is better than strategy 1.\n\n";

    return 0; 
}