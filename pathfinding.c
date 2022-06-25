#include <stdlib.h>
#include <stdio.h>

#define LENGTH 10

void readFile(char* filename, int** maze) {
    FILE *file;
    file = fopen(filename, "r");
    int x = 0;
    int y = 0;
    while (!feof(file)) {
        char c;
        fscanf(file, "%c", &c);
        if (c != '\n') {
            maze[x][y++] = c - '0';
            if (y == LENGTH) {
                y = 0;
                x++;
            }
        }
    }
    fclose(file);
}

void printMaze(int** maze) {
    for (int x = 0; x < LENGTH; x++) {
        for (int y = 0; y < LENGTH; y++) {
            printf("%d", maze[x][y]);
        }
        printf("\n");
    }
}

void freeMaze(int** maze) {
    for (int i = 0; i < LENGTH; i++) {
        free(maze[i]);
    }
}

int getBestPath(int** maze) {
    int* path = malloc(sizeof(int) * LENGTH * LENGTH);
    int* current[LENGTH];
    for (int i = 0; i < LENGTH; i++) {
        current[i] = (int*)malloc(LENGTH * sizeof(int));
    }
    for (int x = 0; x < LENGTH; y++) {
        for (int y = 0; y < LENGTH; y++) {
            current[i] = 999;
        }
    }
    int bestRisk = getBestPathRecursive(maze, current, 0, 0, path, 0, -1 * maze[0][0]);
    freeMaze(current);
    return bestRisk;
}

int getBestPathRecursive(int** maze, int** current, int x, int y, int* path, int pathLength, int risk) {
    int newRisk = risk + maze[x][y];
    return newRisk;
    int lowestRisk = getBestPathRecursive();
}

int main(int argc, char* argv[]) {
    int* maze[LENGTH];
    for (int i = 0; i < LENGTH; i++) {
        maze[i] = (int*)malloc(LENGTH * sizeof(int));
    }
    readFile(argv[1], maze);
    printMaze(maze);
    freeMaze(maze);
    return 0;
}
