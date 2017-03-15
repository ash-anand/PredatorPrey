#ifndef GRID_H
#define GRID_H

#define GRID_ROW 300
#define GRID_COLS 300
#define PREDATOR 30
#define PREY 300
#define PREDATOR_MOVES 10
#define PREY_MOVES 5

#include <stdlib.h>				//Random number generator
#include <math.h>
#include "objective.h"
#include <boost/any.hpp>
struct Point{
	int x;
	int y;
};

class Grid{
	boost::any matrix[GRID_COLS][GRID_ROW];
+
	int id;
	public:
		Grid(){
			srand(NULL);
		}

		bool isEmpty(Point a){
			return !(matrix[a.x][a.y]);
		}

		Point randPoint(){
			Point a;
			a.x = rand()%GRID_COLS;
			a.y = rand()%GRID_ROW;
			return a;
		}

		void initialize(){
			for (int i = 0; i < PREDATOR; ++i)
			{
				Point a = randPoint();
				if(isEmpty(a)){
					matrix[a.x][a.y] = new predator(a);
				}
			}
			for (int i = 0; i < PREY; ++i)
			{
				Point a = randPoint();
				if(isEmpty(a)){
					matrix[a.x][a.y] = new prey(a);
				}
			}
		}
};


#endif