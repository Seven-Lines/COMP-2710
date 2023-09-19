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
* statements in C++: https://shorturl.at/qvFL3.
*/

# include <iostream>
# include <stdlib.h>
# include <assert.h>
# include <ctime>
using namespace std;

//----------- INITIALIZE VARIABLES -----------//
const double aaron_accuracy = 33.3; 
const double bob_accuracy = 50.0; 
const double charlie_accuracy = 100.0;

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
    srand(time(0)); //  < Generate new seed for rand()
    double shot_simulation = rand() % 100; 
    if (shot_simulation <= accuracy) { return true; } else { return false; }
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
* NOTE: The following "[person]_shoots" functions won't run 
* in the first place if at_least_two_alive = false. IE: there 
* cannot be two false inputs. 
*/
string Aaron_shoots1(bool& B_alive, bool& C_alive) { 
    string target; 
    C_alive ? target = "c" : B_alive ? target = "b" : ""; 
    if (shoots(aaron_accuracy)) { target == "c" ? C_alive = false : B_alive = false; }
    return target;
}

string Bob_shoots(bool& A_alive, bool& C_alive) { 
    string target; 
    C_alive ? target = "c" : A_alive ? target = "a" : "";
    if (shoots(bob_accuracy)) { target == "c" ? C_alive = false : A_alive = false; }
    return target; 
}

void Charlie_shoots(bool& A_alive, bool& B_alive) { 
//return(; 
}

void Aaron_shoots2(bool& B_alive, bool& C_alive) { 

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
    bool b, c;
    cout << "Unit 4 Testing: Function Charlie_shoots";
}

//----------- MAIN -----------//
int main() { 
    /* Testing Functions... */  
    test_at_least_two_alive(); wait(); 
    test_aaron_shoots1(); wait();
    test_bob_shoots(); wait(); 

}