#include <iostream>
#include <cmath>
using namespace std; 

int isPrime(int n)
{
    int root = ceil(sqrt(n));
    if(n < 2)
    {
        return false;
    }
    for(int i = 2; i <= root; i++)
    {
        if (n % i == 0 && n != i)
        {
            return false;
            break;
        }
    }
    return true;
}

int main()
{
    int n;
    cout << "enter number: ";
    cin >> n;

    if(isPrime(n))
    {
        cout << "the number is prime!\n";
    }
    else
    {
        cout << "the number is not prime!\n";
    }
}