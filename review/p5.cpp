#include <iostream>
#include <string>
#include <fstream>
using namespace std; 

void readArray(char arr[4][4])
{
    ifstream f("grid.txt");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            f >> arr[i][j];
        }
    }
    f.close();
}

bool findRestOfTheWordInCol(string w, char arr[4][4], int r, int c, int step, int edge)
{
    int wordIndex = 0;
    int i = r;
    while (i != edge)
    {
        if(w[wordIndex] != arr[i][c])
        {
            break;
        }
        if (wordIndex == w.length() - 1)
        {
            cout << "found vertically it at the row " << r << " and col " << c << endl;
        }
        wordIndex++;
        i += step;
    }
    return false;
}

bool findRestOfTheWordInRow(string w, char arr[4][4], int r, int c, int step, int edge)
{
    int wordIndex = 0;
    int i = c;
    while (i != edge)
    {
        if(w[wordIndex] != arr[r][i])
        {
            break;
        }
        if (wordIndex == w.length() - 1)
        {
            cout << "found horizontally it at the row " << r << " and col " << c << endl;
        }
        wordIndex++;
        i += step;
    }
    return false;
}

void findWord(string w, char arr[4][4])
{
    for (int r = 0; r < 4; r++)
    {
        for (int c = 0; c < 4; c++)
        {
            if(arr[r][c] == w[0])
            {
                findRestOfTheWordInRow(w, arr, r, c, 1, 4);
                findRestOfTheWordInRow(w, arr, r, c, -1, -1);
                findRestOfTheWordInCol(w, arr, r, c, 1, 4);
                findRestOfTheWordInCol(w, arr, r, c, -1, -1);
            }
        }
    }
}

int main()
{
    char arr[4][4];
    readArray(arr);

    cout << "enter a word: ";
    string word;
    cin >> word;

    findWord(word, arr);

}