#include "cell.h"
#include <iostream>
using namespace std;
class map{

public:
	unsigned int gridLengthX;
	unsigned int gridWidthY;
	const char player = '@';


public:

	map();
	map(int x, int y);
	~map();
	void initializeMap(int x, int y);
	void printmap();
	void updatemap();
	cell **mapgrid = new cell*[gridLengthX];


};
