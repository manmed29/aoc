#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int str_to_num(string str)
{    
    char tmp[2];
    int index = 0;
    
    for(char nb : str)
    {
        if (isdigit(nb))
        {
            tmp[index++] = nb;
        }
        if (index > 1)
            index = 1;
    }
    if (tmp[1] == '\0')
    {
        tmp[1] = tmp[0];
    }

    return atoi(tmp);
}
int main() 
{
    int results = 0;
    string line;
    
    ifstream file("file.txt");

    if (!file.is_open())
    {
        return 1;
    }
    
    while (getline(file, line))
    {
        results += str_to_num(line);
    }

    cout << results << endl;

    file.close();

    return 0;
}
