#include "predator.h"

/*************************************
Constructor for Predetor Class.
Asigns position alloted by the grid 
initialisation.
Initialises number of objective 
functions and random weights for one
specific predator using random function.
**************************************/

predator::predator(Point a){
	position = a;
	srand(NULL);

	no_objectives = 2;
	func_weights = new double[no_objectives];		//Dynamic allocation of number of weights

	for(int i = 0; i < no_objectives; i++){
		func_weights[i] = (rand()%1000)/1000;		//Random assignment of weights between 0 and 1
	}
}

/***************************************
Funtion to return current position 
***************************************/
Point predator::get_position(){
	return position;
}

/***************************************
Function to make predator jump to new 
places if it is unsuccessful to hunt 
prey in current iteration.
This function must be called only by 
attack() function once attack fails.
***************************************/

void predator::move(Grid &grid){

	int direction = rand()%4;
	switch(direction){
		case 0:			//Moves in left direction
			Point a = position;
			a.x--;
			a.x += GRID_ROW;
			a.x %= GRID_ROW;		//Ensures circular property of grid
			if(grid.isEmpty(a)){
				grid.update(a,position,PREDATOR_ID);
				position = a;
			}
			break;

		case 1:			//Moves in right direction
			Point a = position;
			a.x++;
			a.x %= GRID_ROW;		//Ensures circular property of grid
			if(grid.isEmpty(a)){
				grid.update(a,position,PREDATOR_ID);
				position = a;
			}
			break;

		case 2:			//Moves in down direction
			Point a = position;
			a.y--;
			a.y += GRID_COLS;
			a.y %= GRID_COLS;		//Ensures circular property of grid
			if(grid.isEmpty(a)){
				grid.update(a,position,PREDATOR_ID);
				position = a;
			}
			break;

		case 3:			//Moves in up direction
			Point a = position;
			a.y++;
			a.y %= GRID_COLS;		//Ensures circular property of grid
			if(grid.isEmpty(a)){
				grid.update(a,position,PREDATOR_ID);
				position = a;
			}
			break;
	}
}


/***************************************
Function to make the predator take their 
turns and attack the prey in their 
neighbourhood. If fails then simply 
calls the move() function.
***************************************/

void predator::attack(Grid &grid){

	std::vector<Point> neighbours = grid.get_neighbours(position);		//Default call of moore neighbourhood

	if(neighbours.empty())
		for(int i = 0; i < PREDATOR_MOVES; i++)
			move(grid);
		else{
			Prey p = grid.findweakest(neighbours);
			if(!p){
				grid.update(p.get_position(),position,PREDATOR_ID);
			}
		}
}