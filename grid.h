#ifndef GRID_H
#define GRID_H

#define GRID_ROW 300
#define GRID_COLS 300
#define PREDATOR 30
#define PREY 300
#define PREDATOR_MOVES 10
#define PREY_MOVES 5
#define PREDATOR_ID 2
#define PREY_ID 1

#include <stdlib.h>				//Random number generator
#include <math.h>
#include "objective.h"

struct Point{
	int x;
	int y;
	//Constructor to initialise a Point structure from x y int values
	Point(int _x,int _y){
		x = _x;
		y = _y;
	}
};

class Grid{
	int matrix[GRID_COLS][GRID_ROW];
	public:

		/*****************************
		Default constructor to 
		initialise the random number 
		generator.
		*****************************/
		Grid(){
			srand(NULL);
		}

		/*****************************
		Function to return whether the
		specific point is empty.
		*****************************/
		bool isEmpty(Point a){
			return !(matrix[a.x][a.y]);
		}

		//Function Overloading
		bool isEmpty(int x, int y){
			return !(matrix[x][y]);
		}

		/*****************************
		Generates a random point to 
		initialize predators and prey
		*****************************/
		Point randPoint(){
			Point a;
			a.x = rand()%GRID_COLS;
			a.y = rand()%GRID_ROW;
			return a;
		}

		/*****************************
		Function to initialize the 
		initial configuration and
		placement of predator and 
		prey.
		*****************************/
		void initialize(std::vector<predator> &pd, std::vector<prey> pr);

		/******************************
		Function to update the position
		of any creature once they move
		or attack.
		******************************/
		void update(Point to, Point from,int id){
			matrix[to.x%GRID_ROW][to.y%GRID_COLS] = id;
			matrix[from.x%GRID_ROW][from.y%GRID_COLS] = 0;
		}

		/***************************************
		Function to return an array of 
		neighbours of a specified creature at 
		Point a.
		Function has optional parameter to define
		neighbourhood type, default set to moore
		neighbourhood.
		***************************************/

		vector<Point> get_neighbours(Point a,String neighbour_type="moore");

		//Returns the ID stored at point a
		int get_id(Point a){
			return matrix[a.x][a.y];
		}
};


#endif
