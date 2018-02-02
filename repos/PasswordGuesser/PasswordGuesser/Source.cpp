#include "Stopwatch.h"
#include <iostream>
#include <string>

using namespace std;

void guessPassword(string &pw);

int main()
{
	Stopwatch s;

	string password = "holahola";

	s.start();
	guessPassword(password);
	s.stop();

	int time = s.getDuration(Stopwatch::MILLISECONDS);

	cout << "time == " << time << endl;

}

void guessPassword(string &pw)
{
	string guess = "";

	for (short int a = 0; a < 26; a++)
	{
		for (short int b = 0; b < 26; b++)
		{
			for (short int c = 0; c < 26; c++)
			{
				for (short int d = 0; d < 26; d++)
				{
					for (short int e = 0; e < 26; e++)
					{
						for (short int f = 0; f < 26; f++)
						{
							for (short int g = 0; g < 26; g++)
							{
								for (short int h = 0; h < 26; h++)
								{
									guess = "";

									guess += ('a' + a);
									guess += ('a' + b);
									guess += ('a' + c);
									guess += ('a' + d);
									guess += ('a' + e);
									guess += ('a' + f);
									guess += ('a' + g);
									guess += ('a' + h);

									if (guess == pw)
									{
										cout << "found" << endl;
										return;
									}
								}
							}
						}
					}
				}
			}
		}
	}
}