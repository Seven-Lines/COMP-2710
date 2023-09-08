/* 
* AUTHOR: Sean Bevensee
* AUB ID: smb0207
* FILE NAME: project1_bevensee_smb0207.cpp
*
* To compile use command "g++ project1_bevensee_smb0207.cpp"  
* in parent directory. 
*
* I referenced w3schools.com for C++ basics (input, output,
* formatting, functions, etc). I also used the template given
* on the Canvas page "Project1_hints.pdf". 
*/

#include <iostream>
using namespace std;

//----------- INITIALIZE VARIABLES / FUNCTIONS -----------//
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
  bool eh_la, eh_ir, eh_mp;  // <- eh = "error handling". produces error message after initial failure.


  // Loan Amount...
  do { 
    if (eh_la) { 
      cout << "INVALID INPUT (Loan Amount must be positive).\nLoan Amount: ";
    } else {
      cout << "\nLoan Amount: "; 
      eh_la = true;
    }
    cin >> loan_amount;
  } while (loan_amount < 0);

  // Interest Rate...
  do {
    if (eh_ir) { 
      cout << "INAVLID INPUT (Interest Rate must be positive).\nInterest Rate (\% per year): "; 
    } else { 
      cout << "Interest Rate (\% per year): "; 
      eh_ir = true;
    }
    cin >> interest_rate; interest_rate = interest_rate / 12 / 100;
  } while (interest_rate < 0);
  
  // Montly Payments...
  do { 
    if(eh_mp) { 
      cout << "INVALID INPUT (Monthly Payment must be positive \nAND large enough to terminate the loan.)\nMonthly Payments: ";
    } else { 
      cout << "Monthly Payments: ";
      eh_mp = true; 
    }
    cin >> monthly_payments;
  } while (monthly_payments <= 0 || monthly_payments <= loan_amount * interest_rate);

  //----------- PRINT OUTPUT -----------//
  cout << "*****************************************************************\n"
  << "\tAmortization Table\n"
  << "*****************************************************************\n"
  << "Month\tBalance\t  Payment\tRate\tInterest\tPrincipal\n";

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