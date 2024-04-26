#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int red(string str)
{
    vector <int> numbers;
    string tmp;
    int number = 0;

    for (int i = str.find(':'); i < str.length(); i++)
    {
        tmp = str.substr(i, 3);
        if (tmp == "red")
        {
            tmp = str.substr(i - 3, 2);
            for(char c : tmp)
            {
                if (isdigit(c))
                    number = number * 10 + (c - '0');
            }
            numbers.push_back(number);
            number = 0;
        }
    }
    int max = numbers[0];
    for (int num : numbers)
    {
        if (num > max)
            max = num;
    }
    
    return max;
}
int green(string str)
{
    vector <int> numbers;
    string tmp;
    int number = 0;

    for (int i = str.find(':'); i < str.length(); i++)
    {
        tmp = str.substr(i, 5);
        if (tmp == "green")
        {
            tmp = str.substr(i - 3, 2);
            for(char c : tmp)
            {
                if (isdigit(c))
                    number = number * 10 + (c - '0');
            }
            numbers.push_back(number);
            number = 0;
        }
    }
    int max = numbers[0];
    for (int num : numbers)
    {
        if (num > max)
            max = num;
    }
    
    return max;
}
int blue(string str)
{
    vector <int> numbers;
    string tmp;
    int number = 0;

    for (int i = str.find(':'); i < str.length(); i++)
    {
        tmp = str.substr(i, 4);
        if (tmp == "blue")
        {
            tmp = str.substr(i - 3, 2);
            for(char c : tmp)
            {
                if (isdigit(c))
                    number = number * 10 + (c - '0');
            }
            numbers.push_back(number);
            number = 0;
        }
    }
    int max = numbers[0];
    for (int num : numbers)
    {
        if (num > max)
            max = num;
    }
    
    return max;
}
int mult(string str)
{
    return red(str) * green(str) * blue(str);
}
int main()
{
    ifstream input_file("input.txt");
    string line;
    vector<string> vec;

    if (!input_file.is_open()) 
    {
        std::cout << "Error opening the file!" << endl;
        return 1;
    }

    while (getline(input_file, line)) 
    {
        vec.push_back(line);
    }

    string str;
    int total = 0;

    for (int i = 0; i < vec.size(); i++)
    {
        str = vec[i];
        total += mult(str);
    }
    std::cout << total << endl;

    return 0;
}