/* FILE NAME - P1 ... for "Project 1"
* AUTHOR: Sean Bevensee 
* See Syllabus? Idk. 
*
* SEE "Project1.PDF" ON CANVAS
*/

#include <iostream>
using namespace std;

int main() {
  //----------- INITIALIZE VARIABLES -----------//
  int loan_amount, interest_rate, monthly_payments; 

  cout.setf(ios::fixed);  // (currency formatting, idk.)
  cout.setf(ios::showpoint);
  cout.precision(2);

  do { cout << "\nLoan Amount: "; cin >> loan_amount; } while(loan_amount < 0);
  do { cout << "Interest Rate: "; cin >> interest_rate; } while (interest_rate < 0);
  do { cout << "Monthly Payments: "; cin >> monthly_payments; } while (monthly_payments <= 0 || monthly_payments <= loan_amount * interest_rate); 

  //----------- PRINT OUTPUT -----------//
  cout << "*****************************************************************\n"
  << "\tAmortization Table\n"
  << "*****************************************************************\n"
  << "Month\tBalance\t\tPayment\tRate\tInterest\tPrincipal\n";

  int current_month = 0; 
  float interest_rate = 0;

  while (loan_amount > 0){ 
    if(current_month == 0) {
      cout << current_month++ << "\t$" << loan_amount;  
    }

    //if(loan_amount < 1000) cout << "\t";

    
  }
}

// compile this shit first with the "g++ P1.cpp" 
