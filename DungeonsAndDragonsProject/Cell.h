//! @file Cell.h
//! @brief Header file for the Cell class
//! @author Yousra El Ghomari, 26855873
#pragma once

class Cell
{
public:
	
	//! Constructor
	Cell();
	Cell(char type);
	
	//! Destructor
	virtual ~Cell();
	
	//! Returns the type of the Cell
	//! @return char value, the type of Cell
	char getType() { return type; }
private:
	char type;
};