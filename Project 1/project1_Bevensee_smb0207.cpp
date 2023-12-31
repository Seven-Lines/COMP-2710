/* 
* AUTHOR: Sean Bevensee
* AUB ID: smb0207
* FILE NAME: project1_Bevensee_smb0207.cpp
*
* To compile use command "g++ project1_Bevensee_smb0207.cpp"  
* in parent directory. 
*
* I referenced w3schools.com for C++ basics (input, output,
* formatting, functions, etc). I also used the template given
* on the Canvas page "Project1_hints.pdf". To determine if 
* user inputs were numbers I used this YouTube video:
* https://www.youtube.com/watch?v=m2P5A4nR51g. 
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

// Clear Function 
void clear() { 
    cin.clear(); cin.ignore(123, '\n');  // <- clear previous input (taken from resource)
}

//----------- MAIN -----------//
int main() {
  // Formating #s...
  cout.setf(ios::fixed);     // <- display decimal point and all trailing zeros
  cout.setf(ios::showpoint); // <- shows decimal point
  cout.precision(2);         // <- exactly 2 decimal points

  // Get Loan Amount...
  cout << "\nLoan Amount: "; 
  while (!(cin >> loan_amount) || loan_amount < 0) {
    cout << "INVALID INPUT (Loan Amount must be a positive integer).\nLoan Amount: ";
    clear();
  }

  // Get Interest Rate...
  cout << "Interest Rate (\% per year): ";
  while (!(cin >> interest_rate) || interest_rate < 0) { 
    cout << "INAVLID INPUT (Interest Rate must be a positive integer).\nInterest Rate (\% per year): "; 
    clear();
  }
  interest_rate = interest_rate / 12 / 100;

  // Monthly Payments...
  cout << "Monthly Payments: ";
  while (!(cin >> monthly_payments) || monthly_payments <= 0 || monthly_payments <= loan_amount * interest_rate) { 
    cout << "INVALID INPUT (Monthly Payment must be a positive \ninteger that is large enough to terminate the loan).\nMonthly Payments: ";
    clear();
  }

  //----------- PRINT OUTPUT -----------//
  cout << "\n*****************************************************************\n"
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