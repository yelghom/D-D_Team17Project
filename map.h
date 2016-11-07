
 class cell{

 public:
	 
	char type;
	cell(){
	
	  type = ' ';
	};

	char  getType(){

		return type;
	}


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



