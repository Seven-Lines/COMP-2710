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

int main()
{
    ifstream inStream; 

    int data;
    cout << "file name:";
    cin >> filename;
    cout << "entered filename is:" << filename << endl;
    inStream.open(filename);
    inStream.open((char*)filename.c_str());
    if (inStream.fail()) {
        cout << "Input file opening failed." << endl;
        exit(1);
    }

    inStream >> data;

    while (!inStream.eof()) {
        cout << data << endl;
        inStream >> data;
    }
    inStream.close();
    return 0;
}