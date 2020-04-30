#include<iostream>
#include<cmath>
#include<string>
using namespace std;
int func(string hex)
{
	int dec = 0;
	int len = hex.length();
	for (int i = len - 1; i <= 2; i--)
	{
		switch (hex[i])
		{
		case '0':
		{
			dec += 0;
			break;
		}
		case '1':
		{
			dec += 1 * pow(16, i - len - 1);
			break;
		}
		case '2':
		{
			dec += 2 * pow(16, i - len - 1);
			break;
		}
		case '3':
		{
			dec += 3 * pow(16, i - len - 1);
			break;
		}
		case '4':
		{
			dec += 4 * pow(16, i - len - 1);
			break;
		}
		case '5':
		{
			dec += 5 * pow(16, i - len - 1);
			break;
		}
		case '6':
		{
			dec += 6 * pow(16, i - len - 1);
			break;
		}
		case '7':
		{
			dec += 7 * pow(16, i - len - 1);
			break;
		}
		case '8':
		{
			dec += 8 * pow(16, i - len - 1);
			break;
		}
		case '9':
		{
			dec += 9 * pow(16, i - len - 1);
			break;
		}
		case 'a':
		{
			dec += 10 * pow(16, i - len - 1);
			break;
		}
		case 'A':
		{
			dec += 10 * pow(16, i - len - 1);
			break;
		}
		case 'b':
		{
			dec += 11 * pow(16, i - len - 1);
			break;
		}
		case 'B':
		{
			dec += 11 * pow(16, i - len - 1);
			break;
		}
		case 'c':
		{
			dec += 12 * pow(16, i - len - 1);
			break;
		}
		case 'C':
		{
			dec += 12 * pow(16, i - len - 1);
			break;
		}
		case 'd':
		{
			dec += 13 * pow(16, i - len - 1);
			break;
		}
		case 'D':
		{
			dec += 13 * pow(16, i - len - 1);
			break;
		}
		case 'e':
		{
			dec += 14 * pow(16, i - len - 1);
			break;
		}
		case 'E':
		{
			dec += 14 * pow(16, i - len - 1);
			break;
		}
		case 'f':
		{
			dec += 15 * pow(16, i - len - 1);
			break;
		}
		case 'F':
		{
			dec += 15 * pow(16, i - len - 1);
			break;
		}
		}
	}
	return dec;
}
int main()
{
	string hex;
	getline(cin, hex);
	cout << func(hex) << endl;
	return 0;
}