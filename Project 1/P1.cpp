/* 
* FILE NAME: P1.cpp
* AUTHOR: Sean Bevensee  
*
* I referenced w3schools.com for C++ basics (input, output,
* formatting, functions, etc). I also used the template given
* on the Canvas page "Project1_hints.pdf". 
*/

#include <iostream>
using namespace std;

//----------- INITIALIZE VARIABLES -----------//
float loan_amount, monthly_payments, interest_rate, interest_total; 
int current_month = 0; 

// Print Statment Function 
void print(bool na, float principle_payment, float interest_payment) {
  cout << current_month++ << "\t$" << loan_amount;
  if (loan_amount < 1000) cout << "\t"; 
  if (na) { 
    cout << "  N/A\t\tN/A\tN/A\t\tN/A\n";
  } else { 
    cout << "  $" << monthly_payments << "\t" << interest_rate * 100 << "\t$" << interest_payment << "\t\t$" << principle_payment << "\n"; 
  }
}

//----------- MAIN -----------//
int main() {
  // Formating #s...
  cout.setf(ios::fixed);     // <- display decimal point and all trailing zeros
  cout.setf(ios::showpoint); // <- shows decimal point
  cout.precision(2);         // <- exactly 2 decimal points

  // Getting user input...
  do { cout << "\nLoan Amount: "; cin >> loan_amount; } while (loan_amount < 0);
  do { cout << "Interest Rate: "; cin >> interest_rate; interest_rate = interest_rate / 12 / 100; } while (interest_rate < 0);
  do { cout << "Monthly Payments: "; cin >> monthly_payments; } while (monthly_payments <= 0 || monthly_payments <= loan_amount * interest_rate);   

  //----------- PRINT OUTPUT -----------//
  cout << "*****************************************************************\n"
  << "\tAmortization Table\n"
  << "*****************************************************************\n"
  << "Month\tBalance\t\tPayment\tRate\tInterest\tPrincipal\n";

  // Main loop ... 
  while (loan_amount > 0){ 
    if(current_month == 0) {  // Exception handling ... 
      print(true, 0, 0);
    } else {                  // Main ...
      float interest_payment = loan_amount * interest_rate; 
      float principle_payment = monthly_payments - interest_payment;

      loan_amount -= principle_payment;
      interest_total += interest_payment; 

      if (loan_amount < 0) { principle_payment += loan_amount; monthly_payments += loan_amount; loan_amount = 0; }
      print(false, principle_payment, interest_payment); 
    }    
  }
  cout << "****************************************************************\n";
	cout << "\nIt takes " << --current_month << " months to pay off "
	     << "the loan.\n"
	     << "Total interest paid is: $" << interest_total;
	cout << endl << endl;

  return 0; 
}