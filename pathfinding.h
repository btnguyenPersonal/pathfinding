#include <stdlib.h>
#include <stdio.h>

#define LENGTH 100
#define MAX 999999

void freeMaze(int** maze);
void printMaze(int** maze);
void incrementMaze(int** maze);
void fillMaze(int num, int** current);
int getBestPath(int** maze);
int getBestPathRecursive(int** maze, int** current, int x, int y, int risk);
int** cloneMaze(int** maze);
int** createMaze();
int readFile(char* filename, int** maze);
