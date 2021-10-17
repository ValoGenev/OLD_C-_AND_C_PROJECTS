#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{

    ifstream inFile;
    inFile.open("pedal.txt");

    if(inFile.fail()){
        cout << "Error openning File";
        return 0;
    }

    string item;
    int count=0;

    while(!inFile.eof()){
        inFile >> item;
        count++;

    }

    cout << count

    cout << "Hello worssld!" << endl;
    return 0;
}
