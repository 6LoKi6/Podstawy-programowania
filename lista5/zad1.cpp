#include <iostream>
#include <fstream>

using namespace std;

void zapisz(string plik_wyj, string zawartosc, int ile)
{
    ofstream outputFile(plik_wyj);

    for(int i = 0; i < ile; i++)
        outputFile << zawartosc << endl;

    outputFile.close();
}

void zapisz(ofstream &outputFile, string content, int count)
{
    for(int i = 0; i < count; i++)
        outputFile << content << endl;

    outputFile.close();
}

int main()
{
    string outputFileName = "zad1_out";
    string message = "Hello";
    int count = 3;

    zapisz(outputFileName, message, count);

    ofstream outputFile(outputFileName, ios_base::app);
    zapisz(outputFile, message, count);
    
    cout << endl;
    return 0;
}