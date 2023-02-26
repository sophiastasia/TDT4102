//Oppgave 2a
#include "std_lib_facilities.h"

int maxOfTwo(int a, int b)
{
    if (a>b)
    {
        cout << "A is grater than B" << endl;
        return a;
    }
    else
    {
        cout << "B is greater than or equal to A" << endl;
        return b;
    }
}

int fibonacci(int n) 
{
    int a = 0;
    int b = 1;
    cout << "Fibonacci numbers:" << endl;

    for (int x = 1; x < n+1; ++x)
    {
        cout << x << " " << b << endl;
        int temp = b;
        b += a;
        a = temp;
    }
    cout << "----" << endl;
    return b;
}

int squareNumberSum(int n)
{
    int totalsum = 0;
    for (int i = 1; i < n+1; ++i)
    {
        totalsum += i*i;
        cout << i*i << endl;
    }
    cout << totalsum << endl;
    return totalsum;
}

void triangleNumbersBelow(int n)
{
    int acc = 1;
    int num = 2;
    cout << "Triangle numbers below " << n << ":" << endl;
    while (acc < n)
    {
        cout << acc << endl;
        acc += num;
        num +=1;
    }
    cout << "\n" << endl;
}

bool isPrime(int n)
{
    for (int j = 2; j < n; ++j)
    {
        if (n%j == 0)
        {
            return false;
        }
    }
    return true;
}

void naivePrimeNumberSearch(int n)
{
    for (int number = 2; number < n; ++number)
    {
        if (isPrime(number))
        {
            cout << number << " is a prime." << endl;
        }
    }
}

int findGreatestDivisor(int n)
{
    for (int divisor = n-1; divisor > 0; divisor = divisor -1)
    {
        if (n%divisor == 0)
        {
            return divisor;
        }
    }
    return 1; 
}

int main()
{
    cout << "Oppgave 2a:" << endl;
    cout << maxOfTwo(5,6) << endl;

    cout << "\nOppgave 2c:" << endl;
    cout << fibonacci(5) << endl;

    cout << "\nOppgave 2d:" << endl;
    cout << squareNumberSum(5) << endl;

    cout << "\nOppgave 2e:" << endl;
    triangleNumbersBelow(10);

    cout << "\nOppgave 2f og 2g:" << endl; 
    naivePrimeNumberSearch(14);

    cout << "\nOppgave 2h:" << endl;
    cout << findGreatestDivisor(14) << endl;
    cout << findGreatestDivisor(13) << endl;

    return 0;
}