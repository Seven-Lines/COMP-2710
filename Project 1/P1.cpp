/* FILE NAME - P1 ... for "Project 1"
* AUTHOR: Sean Bevensee 
* See Syllabus? Idk. 
*
* SEE "Project1.PDF" ON CANVAS
*/

#include <iostream>
using namespace std;

int main() {
  int loan_amount, interest_rate, monthly_payments; 

  cout.setf(ios::fixed);  // (currency formatting, idk.)
  cout.setf(ios::showpoint);
  cout.precision(2);

  do { cout << "\nLoan Amount: "; cin >> loan_amount; } while(loan_amount < 0);
  do { cout << "\nInterest Rate: "; cin >> interest_rate; } while (interest_rate < 0);
  do { cout << "\nMonthly Payments: "; cin >> monthly_payments; } while ();


}

// compile this shit first with the "g++ P1.cpp" 
