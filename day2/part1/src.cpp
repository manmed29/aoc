#include <iostream>
#include <fstream> 
#include <vector> 

using namespace std;

bool check(string str)
{
    string tmp;
    string s;
    int num = 0;

        for (int i = str.find(':') + 2; i < str.length(); i++)
        {
            tmp = str.substr(i, 2);
            num = 0;
            for(char c : tmp)
            {
                if (isdigit(c))
                    num = num * 10 + (c - '0');
            }
                if (num > 12 && str.substr(i + 3, 3) == "red")
                    return false; 
                if (num > 13 && str.substr(i + 3, 5) == "green")
                    return false; 
                if (num > 14 && str.substr(i + 3, 4) == "blue")
                    return false; 
        }

    return true;
}
int main() 
{
    ifstream input_file("file.txt");
    string line;
    vector<string> vec;
    int res = 0;

    if (!input_file.is_open()) 
    {
        std::cout << "Error opening the file!" << endl;
        return 1;
    }

    while (getline(input_file, line)) 
    {
        vec.push_back(line);
    }
    for (int i = 0; i < vec.size(); i++)
    {
        if (check(vec[i]))
            res += (i + 1);
    }
    std::cout << res << endl;

    input_file.close();

    return 0;
}
