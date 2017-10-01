// Jacob Claytor
// COSC 2030
// September 25th, 2017

#include <iostream>
#include <iomanip>
using namespace std;

short sum1(int n);
long sum2(int n);
float factorial1(int n);
double factorial2(int n);
float strangeBehavior1(int n);
double strangeBehavior2(int n);

int main()
{
	// Shorts begin to overflow at 8 bits or 2^8.
	// 2^8 - 1 is last number to not overflow.
	cout << "Sum with shorts: " << endl << endl;
	cout << sum1(255) << endl;
	cout << sum1(256) << endl;

	// Longs begin to overflow at 16 bits or 2^8.
	// 2^16 - 1 is last number to not overflow.
	cout << "Sum with longs: " << endl << endl;
	cout << sum2(65535) << endl;
	cout << sum2(65536) << endl;

	// Last number to not overflow in factorial is 34 for float.
	// 35+ overflows.
	cout << "Factorial with floats: " << endl << endl;
	cout << factorial1(34) << endl;
	cout << factorial1(35) << endl;

	// Last number to not overflow in factorial is 170 for double.
	// 171+ overflows.
	cout << "Factorial with doubles: " << endl << endl;
	cout << factorial2(170) << endl;
	cout << factorial2(171) << endl;

	// I could not find any difference between doubles and floats for the strange behavior method.
	// I should be getting 0 every time anyway, because (1/n)n is just one, and then 1 - 1 is 0.
	for (int i = 1000000; i <= 1000100; i++)
	{
		cout << "Strange behavior for sum up to " << i << endl;
		cout << "Float is: " << strangeBehavior1(i) << endl;
		cout << "Double is: " << strangeBehavior2(i) << endl;
	}

	cout << "\nPuzzle problem with float for index:" << endl;
	for (float i = 3.4; i < 4.4; i += 0.2)
	{
		cout << "i = " << i << endl;
	}

	cout << "\nPuzzle problem with double for index:" << endl;
	for (double i = 3.4; i < 4.4; i += 0.2)
	{
		cout << "i = " << i << endl;
	}

	// Technically the error is because we are printing all values from 3.4 to 4.4 with floats.
	// The logic makes sense however because when 4.2 is checked against 4.4 it is less than 4.4.
	// So .2 is added and 4.4 is printed, but when we change it to double, that error does not occur.
	// Double sees that 4.2 + .2 is 4.4 so it does not print the value.



	return 0;
}

short sum1(int n)
{
	short sum = 0;
	if (n == 0)
	{
		sum = sum + 0;
	}
	else
	{
		sum = n + sum1(n - 1);
	}
	return sum;
}

long sum2(int n)
{
	long sum = 0;
	for (int i = 0; i <= n; i++)
	{
		sum = sum + i;
	}
	return sum;
}

float factorial1(int n)
{
	float product = 1;
	for (long i = 1; i <= n; i++)
	{
		product = product * i;
	}
	return product;
}

double factorial2(int n)
{
	double product = 1;
	for (long i = 1; i <= n; i++)
	{
		product = product * i;
	}
	return product;
}

float strangeBehavior1(int n)
{
	float sum = 1;
	for (float i = 1; i <= n; i++)
	{
		sum = sum + (1 / n);
	}
	return sum - 1;
}

double strangeBehavior2(int n)
{
	double sum = 1;
	for (double i = 1; i <= n; i++)
	{
		sum = sum + (1 / n);
	}
	return sum - 1;
}




