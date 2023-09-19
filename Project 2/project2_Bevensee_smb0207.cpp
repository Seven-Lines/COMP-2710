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

//----------- FUNCTIONS -----------//
/* Wait for user... */  
void wait(void) { 
    cout << "Press Enter to continue...";
    cin.ignore().get(); 
}

/* Shoots... 
*
* NOTE: Will return TRUE if shot connects, and FALSE if shot 
* doesn't connect. 
*/
bool shoots(double accuracy) { 
    double shot_simulation = rand() % 100; 
    shot_simulation <= accuracy ? return true : return false;
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
void Aaron_shoots1(bool& B_alive, bool& C_alive) { 
    /*
    if (C_alive) { 

    } else if (B_alive) { 

    } else { 
        //return(; 
    }
    */
   B_alive = !B_alive;
}

void Bob_shoots(bool& A_alive, bool& C_alive) { 

}

void Charlie_shoots(bool& A_alive, bool& B_alive) { 

}

void Aaron_shoots2(bool& B_alive, bool& C_alive) { 

}

//----------- TEST FUNCTIONS -----------//
/* At least two alive test... */
void test_at_least_two_alive(void) { 
    cout << "Unit Testing 1: Function - at_least_two_alive()\n";
    
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



//----------- MAIN -----------//
int main() { 
    /* Testing Functions... */  
    test_at_least_two_alive(); wait(); 
    
    bool b_test = true; bool c_test = false; 
    cout << b_test << c_test << endl; 
    Aaron_shoots1(b_test, c_test);
    cout << b_test << c_test << endl; 


}