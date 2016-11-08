#ifndef cell_H
#define cell_H
class cell{

public:

	char type;
	cell();

	char  getType();


};

//derived Class

class wallCell : public cell {
public:
	wallCell(){

		type = '#';
	}

};

class emptyCell : public cell{
public:

	emptyCell()
	{

		type = ' ';
	}

};


#endif




/*
 class Cell {

	public:
		 
		char type;
		Cell(){

			type = ' ';
		};

		char  getType(){

			return type;
		}
		//char * Type; 
		//char* getType();
};

class emptyCell : public Cell{
	
public:

	emptyCell(){
		type = ' ';
	};


	// empty cell is going to have the empty char ' ' or maybe E
	//copy constructor emptyCell(type);



};

class wallCell : public Cell{
public:
	wallCell(){

		type = '#';

	}
	// wall cell is going to contain the '#' delimeter chartacter 

};
*/