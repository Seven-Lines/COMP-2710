/* 
* AUTHOR: Sean Bevensee
* AUB ID: smb0207
* FILE NAME: project3_Bevensee_smb0207.cpp
*
* To compile use command "g++ project3_Bevensee_smb0207.cpp"  
* in parent directory. Use the command "./a.out" to run the code.
* If you are denied access, give the file execute permissions with 
* "chmod". 
*
* I used some of the example code given in the "Project3.pdf" file on 
* Canvas as well as https://www.geeksforgeeks.org/ articles and a single 
* https://www.sololearn.com/ forum page. 
*/
#include <fstream>
#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

int iArray1[MAX_SIZE], iArray2[MAX_SIZE], iArray3[MAX_SIZE];
int iArray1_size, iArray2_size, iArray3_size; 

//----------------------------- FILE HANDLING -----------------------------//
/* Read's the file's contents...
*
*  NOTE: Taken from Project3.pdf file. The functionality of this function is
*  to return the number of lines in the file AND assign values to the given 
*  array. 
*/
int readfile(int inputArray[], ifstream& instream, string filename){
    int index = 0;

    instream >> inputArray[index];
    while (!instream.eof()) {
        index++;
        instream >> inputArray[index];
    }

    cout << "The list of " + std::to_string(index + 1) + " numbers in this file " + filename + " is:\n";
    for (int i = 0; i <= index; i++) { cout << inputArray[i] << "\n"; }

    cout << endl;

    return index;
}

/* Fetch's the file based on user input... 
*  
*  NOTE: The functionality of this function is to (1) make sure the file is 
*  valid and (2) send that valid file to the "readfile" function.
*/
int fetch_file(string file_index, int array[]) { 
    ifstream instream; 
    string filename; 

    do{ 
        cout << "Enter the " + file_index + " input file name: ";
        cin >> filename;
        instream.open((char*)filename.c_str());
    } while(!(instream.good())); 

    return readfile(array, instream, filename);
}

//--------------------- NUMBER SORTING ALGORITHMS ------------------------//
/* Bubble Sort Algorithm...
*
*   NOTE: I got this from COMP-1220 (last semester), and I specifically chose
*   it because it is the easiest to implement. The code that I'm using I 
*   implemented from a  geeksforgeeks.org article (1), linked below.
*
*   (1) https://www.geeksforgeeks.org/bubble-sort/
*/
void bubble_sort_algorithm(int array[], int array_size)
{
    for (int i = 0; i < array_size - 1; i++) {
        for (int j = 0; j < array_size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                // Swap array[j] and array[j+1]
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

/* Write to file. 
*
*  NOTE: A friend recommended that I use "ofstream outstream" and I also used 
*  this forum for help (1).
*
*  (1) https://www.sololearn.com/Discuss/2977617/how-is-c_str-function-working-in-this-c-code-please-explain-complete-code-in-description
*/
void write_file(int array[], int array_size) { 
    ofstream outstream; 
    string filename; 

    cout << "Enter the output file name: "; cin >> filename; 

    outstream.open((char*)filename.c_str());
    for (int i = 0; i < array_size; i++) { outstream << array[i] << "\n"; }

    cout << "*** Please check the new file - " << filename << " ***\n";
} 

//----------------------------- MAIN -----------------------------//
/* Main function... */
int main() { 
    cout << endl << "*** Welcome to Sean's sorting program ***\n";
    
    // Fetch "File 1" and "File 2"...
    iArray1_size = fetch_file("first", iArray1);
    iArray2_size = fetch_file("second", iArray2); 

    // Combine and sort "File 1" and "File 2"... 
    iArray3_size = iArray1_size + iArray2_size + 2;
    for (int i = 0; i <= iArray1_size; i++) { iArray3[i] = iArray1[i]; }
    for (int i = 0; i <= iArray2_size; i++) { iArray3[i + iArray1_size + 1] = iArray2[i]; }

    // Print contents of "File 1" and "File 2"
    bubble_sort_algorithm(iArray3, iArray3_size);
    cout << "The sorted list of " << iArray3_size << " numbers is:";
    for (int i = 0; i < iArray3_size; i++) {
        cout << " " << iArray3[i];
    }
    cout << endl;
    
    // Write new array to "File 3".  
    write_file(iArray3, iArray3_size); 

    // Close program
    cout << "*** Goodbye. ***" << endl;
    return 0; 
}