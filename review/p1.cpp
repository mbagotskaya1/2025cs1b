#include <iostream>
using namespace std;

int primeFactors(int num, int factors[100])
{
    if (num < 2)
    {
        return -1;
    }
    int count = 0;
    int origNum = num;
    while (num > 1)
    {
        for (int i = 2; i <= origNum; i++)
        {
            while (num % i == 0)
            {
                factors[count++] = i;
                num /= i;
            }
        }
    }
    return count;
}

int main()
{
    for(;;)
    {
        cout << "Enter number: (-1 to exit)"; //infinite loop
        int x;
        cin >> x;

        if (x == -1)
        {
            break;
        }
        int factors[100];
        int count = primeFactors(x, factors);

        for (int i = 0; i < count; i++)
        {
            cout << factors[i] << ", ";
        }
        cout << endl;
    }

    return 0;
}