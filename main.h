#include "map.h"
#include <iostream>

using namespace std;
int main()
{
	cout << "Hello World!" <<endl;
	//cell **c1 = new cell*[5];

	cell **c1 = new cell*[5];
	for (int i = 0; i < 5; ++i)
	{
		c1[i] = new cell[5];
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i == 0 || i == 4 || j == 4 || j==0)
			{
				c1[i][j] = *new wallCell();
			}
			else
			{
				c1[i][j] = *new cell();
			}
			
		}
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << c1[i][j].getType();
			//cout << '#';


		}
		cout << endl;

	};
	system("pause");
	return 0;
}