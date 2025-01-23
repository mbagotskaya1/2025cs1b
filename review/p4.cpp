#include <iostream>
#include <fstream>
using namespace std; 

void readArray(int array[5])
{
    ifstream f("inversion.txt");
    for (int i = 0; i < 5; i++)
    {
        f >> array[i];
    }
    f.close();
}

int main()
{
    int array[5];
    readArray(array);

    int count = 0;
    for(int i = 0; i < 5; i++)
    {
        for(int j = i + 1; j < 5; j++)
        {
         if(array[i] > array[j])
            {
                count++;
            }
        }
    }
    cout << "number of inversions: " << count << endl;

}   