#include <iostream>
#include <limits>
using namespace std;

int fibonacci(int n);
void printSequence(int n);
int countEven(int n);
int sumSequence(int n);
int getNumber(int low, int high);


int fibonacci(int n)
{
    if (n == 0)          
        return 0;
    if (n == 1)         
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);   
}


void printSequence(int n)
{
    cout << "Sequence = ";
    for (int i = 0; i < n; i++)
    {
        cout << fibonacci(i) << " ";
    }
    cout << endl;
}

int countEven(int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (fibonacci(i) % 2 == 0)   
            count++;
    }
    return count;
}

int sumSequence(int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + fibonacci(i);
    }
    return sum;
}

int getNumber(int low, int high)
{
    int number;
    while (true)
    {
        cin >> number;

        if (cin.fail())                       
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid number; retry: ";
        }
        else if (number < low || number > high)   
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid number; retry: ";
        }
        else                                  
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return number;
        }
    }
}

int main()
{
    int choice;
    int n;

    do
    {
        cout << endl;
        cout << "1 - Display first n Fibonacci terms" << endl;
        cout << "2 - Find Fibonacci term at index n" << endl;
        cout << "3 - Count even terms among first n" << endl;
        cout << "4 - Sum first n Fibonacci terms" << endl;
        cout << "0 - Exit" << endl;
        cout << "Choose an option: ";

       
        choice = getNumber(0, 4);

        if (choice == 1)
        {
            cout << "Enter n (1-20): ";
            n = getNumber(1, 20);
            printSequence(n);
        }
        else if (choice == 2)
        {
            cout << "Enter index n (0-20): ";   
            n = getNumber(0, 20);
            cout << "F(" << n << ") = " << fibonacci(n) << endl;
        }
        else if (choice == 3)
        {
            cout << "Enter n (1-20): ";
            n = getNumber(1, 20);
            cout << "Even count = " << countEven(n) << endl;
        }
        else if (choice == 4)
        {
            cout << "Enter n (1-20): ";
            n = getNumber(1, 20);
            cout << "Sum = " << sumSequence(n) << endl;
        }

    } while (choice != 0);

    cout << "Goodbye!" << endl;
    return 0;
}
