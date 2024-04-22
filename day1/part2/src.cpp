#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

vector <string> srt_to_int(vector <string> &str)
{
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == "one")
            str[i] = "1";
        else if (str[i] == "two")
            str[i] = "2";
        else if (str[i] == "three")
            str[i] = "3";
        else if (str[i] == "four")
            str[i] = "4";
        else if (str[i] == "five")
            str[i] = "5";
        else if (str[i] == "six")
            str[i] = "6";
        else if (str[i] == "seven")
            str[i] = "7";
        else if (str[i] == "eight")
            str[i] = "8";
        else if (str[i] == "nine")
            str[i] = "9";
    }

    return str;
}
string vec_to_str(vector <string> &strs, string &str)
{
    for (string s : strs)
    {
        str += s;
    }

    return str;
}
int str_to_num(vector <string> str)
{    
    char tmp[2];
    int index = 0;
    string stri;
    char temp;

    vec_to_str(str,stri);
    for(char nb : stri)
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
int string_split(string &str)
{
    string numbers[18] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    vector <string> store;
    vector <string> vec;
    string tmp;

    for (int i = 0; i < str.length(); i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            vec.push_back(str.substr(i, j));;
        }
    }

    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < 18; j++)
        {
            if (vec[i] == numbers[j])
                store.push_back(numbers[j]);
        }
    }

    return str_to_num(srt_to_int(store)); 
}
int main() 
{
    string line;
    int result = 0;

    ifstream file("file.txt");

    while (getline(file, line))
    {
        result += string_split(line);
    }
    
    std::cout << result << endl;

    file.close();

    return 0;
}
