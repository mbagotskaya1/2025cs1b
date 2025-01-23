#include <iostream>
using namespace std; 

string getSubstr(string str, int i, int j)
{
    string retVal = "";
    while (i <= j)
    {
        retVal += str[i++];
    }
    return retVal;
}

bool noRepChar(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        char targetChar = str[i];
        for(int j = 0; j < str.length(); j++)
        {
            if(i != j && targetChar == str[j])
            {
                return false;
            }
        }
    }
    return true;
}

void longestSubstring(string str)
{
    string maxLenStr = "";
    for (int start = 0; start < str.length(); start++)
    {
        for (int end = start; end < str.length(); end++)
        {
            string substr = getSubstr(str, start, end);
            if(noRepChar(substr))
            {
                if (substr.length() > maxLenStr.length())
                {
                    maxLenStr = substr;
                }
            }
        }
    }
    cout << "longest substring: " << maxLenStr << " with length of: " << maxLenStr.length() << endl;
}

int main()
{
    string str;
    cin >> str;
    longestSubstring(str);
}