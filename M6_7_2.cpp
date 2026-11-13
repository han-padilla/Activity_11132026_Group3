#include<iostream>
#include<math.h>
using namespace std;

int factorial(int n)
{
	int fac = 1;
	if (n < 0)
	{
		cout << "Invalid equation.";
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			fac *= i;
		}
	}
	return fac;
}

int sumNatural(int n2)
{
	int sum = 0;
	for (int i = 0; i <= n2; i++)
	{
		sum += i;
	}
	return sum;
}

int sumSquares(int n3)
{
	int sumSq = 0;
	for (int i = 1; i <= n3; i++)
	{
		sumSq += pow(i, 2);
	}
	return sumSq;
}

string compareResults(int n4, int n5)
{
	if (n4 > n5)
		return "Factorial greater";
	else if (n4 < n5)
		return "Sum greater";
	else if (n4 == n5)
		return "Equal";
	else
		return "Zero";
	return 0;
}

int main()
{
	int choice, num;

	do
	{
		cout << "\n";
		cout << "*=-= MAIN MENU =-=*";
		cout << "\n";
		cout << "\nChoose an operation";
		cout << "\n------------------";
		cout << "\n01. Factorial n!";
		cout << "\n02. Sum 1 + 2 + ... n";
		cout << "\n03. Sum of Squares 1^2 + 2^2 + ... n^2";
		cout << "\n04. Comparing Factorial Product and Sum";
		cout << "\n00. EXIT";
		cout << "\n------------------";
		cout << "\nEnter choice : ";
		cin >> choice;
	loop:
		cout << "Enter number to perform operation : ";
		cin >> num;
		if (num < 0 || num > 12)
		{
			cout << "Invalid number ; retry";
			cout << "\n";
			goto loop;
		}

		int fact = factorial(num);
		int naturalSum = sumNatural(num);
		int sumOfSquares = sumSquares(num);
		string comparison = compareResults(fact, naturalSum);

		switch (choice)
		{
		case 1:
			cout << "The FACTORIAL of " << num << " is " << fact;
			cout << "\n";
			break;
		case 2:
			cout << "The SUM of " << num << " from 1 until the number is " << naturalSum;
			cout << "\n";
			break;
		case 3:
			cout << "The SUM OF SQUARES of " << num << " from 1 until the number is " << sumOfSquares;
			cout << "\n";
			break;
		case 4:
			cout << "The comparison says " << comparison;
			cout << "\n";
			break;
		}
	} while (choice != 0);

	cout << "*-= THANK YOU FOR USING MY PROGRAM +-*";

	return 0;
}
