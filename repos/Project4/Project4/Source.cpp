#include <iostream>
#include <cstdlib>


using namespace std;

int main()
{
	int tries = 10000000;
	int inCircle = 0;
	double randX;
	double randY;

	for (int i = 0; i < tries; i++)
	{
		randX = (double)(rand() / RAND_MAX);
		randY = (double)(rand() / RAND_MAX);

		if (sqrt(randX*randX + randY*randY) <= 1) inCircle++;
	}

	double PI = (double)((double)inCircle /(double)tries);
	PI *= 4;

	cout << PI << endl;
}