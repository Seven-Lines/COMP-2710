/* 
* AUTHOR: Sean Bevensee
* AUB ID: smb0207
* FILE NAME: project3_Bevensee_smb0207.cpp
*
* To compile use command "g++ project1_Bevensee_smb0207.cpp"  
* in parent directory. 
*
* I used some of the example code given in the "Project3.pdf" file on 
* Canvas.  
* 
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
   array. 
*/
int readfile(int inputArray[], ifstream& instream, string filename){
    int index = 0;

    instream >> inputArray[index];
    while (!instream.eof()) {
        index++;
        instream >> inputArray[index];
    }

    cout << "The list of " + std::to_string(index + 1) + " numbers in this file " + filename + " is:\n";
    for (int i = 0; i <= index; i++) {
        cout << inputArray[i] << "\n";
    }

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

    // Write sorted contents of "File 1" and "File 2" to a third file. 
    

    return 0; // Close program
}