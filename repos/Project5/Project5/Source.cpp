#include <iostream>
#include <stdio.h>
#include <Windows.h>
using namespace std;

int main()
{
	int sleep;

	cout << "Enter Sleep time: ";

	cin >> sleep;

	for (;sleep > 0; sleep--)
	{
		Sleep(1000);
		cout << sleep << endl;
	}

	system("shutdown -s -t 0");
}

