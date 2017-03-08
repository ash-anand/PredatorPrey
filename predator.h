#ifndef PREDATOR_H
#define PREDATOR_H

/**********************************************
Header file to define the predator functions
and behaviour.
**********************************************/

#include <stdlib.h>				//Random number generator
#include "grid.h"				//To import grid and grid functions
#include "objective.h"			//To get the objective functions


class predator{
	private:
		Point position;				//Current Position of the predator on the grid     
		int allowed_moves;			//Moves allowed by predator in that iteration	
		double *func_weights;		//Weights of a particular objective function
		int no_objectives;			//Total number of objective function
	public:

		predator(Grid &grid);
		Point get_position();
		
}