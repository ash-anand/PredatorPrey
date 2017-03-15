#ifndef PREDATOR_H
#define PREDATOR_H

/**********************************************
Header file to define the predator functions
and behaviour.
**********************************************/

#include "grid.h"				//To import grid and grid functions
#include "objective.h"			//To get the objective functions
#include <math.h>

class predator{
	private:
		Point position;				//Current Position of the predator on the grid     
		int allowed_moves;			//Moves allowed by predator in that iteration	
		double *func_weights;		//Weights of a particular objective function
		int no_objectives;			//Total number of objective function
	public:

		predator(Point a);
		Point get_position();
		void move();
		void attack();

};

#endif