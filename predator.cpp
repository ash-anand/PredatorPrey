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
Function to return an array of 
neighbours of a specified Predator at 
Point a.
Function has optional parameter to define
neighbourhood type, default set to moore
neighbourhood.
***************************************/

vector<Point> neighbours(Grid &grid,Point a,String neighbour_type="moore"){

	vector<Point> neighbours;

	switch(neighbour_type){
		case "moore":
			for(int i = a.x-1; i < a.x+2; i++)
				for(int j = a.y - 1; j < a.y + 2; j++)
					if(i == a.x && j == a.y)
						continue;
					else
						if(!grid.isEmpty(i,j)){
							neighbours.push_back(new Point(i,j));
						}
			break;
		case "extended_moore":
			for(int i = a.x-2; i < a.x+3; i++)
				for(int j = a.y - 2; j < a.y + 3; j++)
					if(i == a.x && j == a.y)
						continue;
					else
						if(!grid.isEmpty(i,j)){
							neighbours.push_back(new Point(i,j));
						}
			break;
		case "von":
			for(int i = a.x-1; i < a.x+2; i++)
				for(int j = a.y - 1; j < a.y + 2; j++)
					if(i == a.x && j == a.y)
						continue;
					else
						if(!grid.isEmpty(i,j) && 
							(i + j - a.x - a.y)%2 == 1){		//Chooses the + sign around the centre
							neighbours.push_back(new Point(i,j));
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

void attack(Grid &grid){


}