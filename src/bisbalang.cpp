#include <fstream>
#include <iostream>
#include <string>

using namespace std;

#define DATA_SIZE 30000

// camina = Ook.
// y = Ook?
// ven = Ook!

int main()
{
    unsigned char data[DATA_SIZE];
    unsigned int pointer = 0;

    string filename;
    cout << "File name: ";
    cin >> filename;

    ifstream file(filename);
    if(!file.is_open())
    {
        cout << "Couldn't open file " << filename << endl;
        return 1;
    }

    string compiled;
    while(!file.eof())
    {
        string wordA, wordB;
        file >> wordA >> wordB;

        int instrA, instrB;
        if(wordA == "camina") instrA = 1;
        else if(wordA == "y") instrA = 2;
        else if(wordA == "ven") instrA = 3;
        else
        {
            cout << "Unknown instruction: " << wordA << endl;
            return 1;
        }

        if(wordB == "camina") instrB = 1;
        else if(wordB == "y") instrB = 2;
        else if(wordB == "ven") instrB = 3;
        else
        {
            cout << "Unknown instruction: " << wordB << endl;
            return 1;
        }
        
        if(instrA == 1 && instrB == 2) compiled += '>';
        else if(instrA == 2 && instrB == 1) compiled += '<';
        else if(instrA == 1 && instrB == 1) compiled += '+';
        else if(instrA == 3 && instrB == 3) compiled += '-';
        else if(instrA == 3 && instrB == 1) compiled += '.';
        else if(instrA == 1 && instrB == 3) compiled += ',';
        else if(instrA == 3 && instrB == 2) compiled += '[';
        else if(instrA == 2 && instrB == 3) compiled += ']';
        else
        {
            cout << "Unknown instruction: " << wordA << " " << wordB << endl;
            return 1;
        }
    }

    for(int i = 0; i < compiled.length() && i >= 0; i++)
    {
        switch(compiled[i])
        {
            case '>': pointer++; break;
            case '<': pointer--; break;
            case '+': data[pointer]++; break;
            case '-': data[pointer]--; break;
            case '.': cout << data[pointer]; break;
            case ',': cin >> data[pointer]; break;
            case '[':
            {
                if(data[pointer] == 0) while(compiled[i] != ']' && i < compiled.length()) i++;
                break;
            }
            case ']':
            {
                if(data[pointer] != 0) while(compiled[i] != '[' && i >= 0) i--;
                break;
            }
        }
    }
}