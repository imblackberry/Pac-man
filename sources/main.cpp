#include "Game.hpp"
#include <iostream>

int main(){

	char map[MAP_HEIGHT][MAP_WIDTH] = { "#####......W###############################################",
										"#####.......###############################################",
										"##.......................................................##",
										"##.......................................................##",
										"##.......................................................##",
										"##.......................................................##",
										"##.......................................................##",
										"##.......................................................##",
										"##.......................................................##",
										"##.......................................................##",
										"##.......................................................##",
										"##.................O.....................................##",
										"##.......................................................##",
										"##.......................................................##",
										"##.......................................................##",
										"##.........X.............................................##",
										"##.......................................................##",
										"##.......................................................##",
										"##.......................................................##",
										"##.......................................................##",
									};
	cout << map[2];
	Game *pacman = new Game(map);
	pacman->gameCycle();
	delete pacman;
	return 0;
}