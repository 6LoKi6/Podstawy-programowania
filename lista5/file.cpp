#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    // pliki wyjsciowe

    string outputFileName = "output_nauka";
    string message = "Hello";
    int count = 3;

    ofstream outputFile(outputFileName);

    for(int i = 0; i < count; i++)
        outputFile << message << endl;

    outputFile.close();

    // pliki wejsciowe

    string inputFileName = "input_nauka";

    ifstream inputFile(inputFileName);

    string bufor;
    while (!inputFile.eof())
    {
        getline(inputFile, bufor);

        cout << bufor << endl;
    }

    inputFile.seekg(0, ios::beg);

    string content[3];
    for(int i = 0; i < 3; i++)
    {
        inputFile >> content[i];
    }

    for(int i = 0; i < 3; i++)
        cout << content[i] << endl;

    inputFile.close();
    
    cout << endl;
    return 0;
}