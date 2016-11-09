//! @file Cell.cpp
//! @brief Concrete implementation of the Cell class
//! @author Yousra El Ghomari, 26855873
#include "Cell.h"

//! Default constructor and the type is an open cell.
Cell::Cell()
{
	type = ' ';
}

//! Constructor setting the type to the user preference.
Cell::Cell(char type)
{
	this->type = type;
}

//! Destructor
Cell::~Cell()
{
}