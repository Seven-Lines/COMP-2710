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
int readfile(int inputArray[], ifstream& instream);

int main( ) {
ifstream inStream1;
    int iArray1[MAX_SIZE];
    int iArray1_size;
    int iArray2[MAX_SIZE];
    int iArray2_size;

    inStream1.open("input1.txt");
    iArray1_size = readfile(inputAry, inStreamFirst);

    inStreamFirst.close( );
    
    return 0;
}

int readfile(int inputArray[], ifstream& inStream){
    int index;
    inStream >> inputArray[index];
    while (! inStream.eof()) {
        cout << inputArray[index] << endl;
        index++;
        inStream >> inputArray[index];
    }
    return index;
}