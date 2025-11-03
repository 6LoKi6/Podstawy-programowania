#include <iostream>
#include <fstream>

using namespace std;

bool pomoc(string source)
{
    int index = source.find('@');

    if(index != string::npos)
        return true;

    return false;
}

bool selektor(ifstream &iFile, ofstream &oFile)
{
    while (!iFile.eof())
    {
        
    }
    
}

int main()
{
    
    
    cout << endl;
    return 0;
}