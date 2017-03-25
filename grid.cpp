#include "grid.h"

    /*****************************
		Function to initialize the 
		initial configuration and
		placement of predator and 
		prey.
		*****************************/

void Grid::initialize(std::vector<predator> &pd, std::vector<prey> pr){
			for (int i = 0; i < PREDATOR; ++i)
			{
				Point a = randPoint();
				if(isEmpty(a)){
					matrix[a.x][a.y] = PREDATOR_ID;
					pd.push_back(new predator(a));
				}
			}
			for (int i = 0; i < PREY; ++i)
			{
				Point a = randPoint();
				if(isEmpty(a)){
					matrix[a.x][a.y] = PREY_ID;
					pr.push_back(new prey(a));
				}
			}
		}
    
    
		/***************************************
		Function to return an array of 
		neighbours of a specified creature at 
		Point a.
		Function has optional parameter to define
		neighbourhood type, default set to moore
		neighbourhood.
		***************************************/
    
vector<Point> Grid::get_neighbours(Point a,String neighbour_type="moore"){

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
			return neighbours;
		}
