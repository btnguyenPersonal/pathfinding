#include <stdlib.h>
#include <stdio.h>

#define LENGTH 100

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

void incrementMaze(int** maze) {
    for (int x = 0; x < LENGTH; x++) {
        for (int y = 0; y < LENGTH; y++) {
            maze[x][y]++;
            if (maze[x][y] == 10) {
                maze[x][y] = 1;
            }
        }
    }
}

void printMaze(int** maze) {
    for (int x = 0; x < LENGTH; x++) {
        for (int y = 0; y < LENGTH; y++) {
            if (maze[x][y] == 999999) {
                printf("%d", 0);
            } else {
                printf("%d", maze[x][y]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

void freeMaze(int** maze) {
    for (int i = 0; i < LENGTH; i++) {
        free(maze[i]);
    }
}

int getBestPathRecursive(int** maze, int** current, int x, int y, int risk) {
    if (x < 0 || y < 0 || x >= LENGTH || y >= LENGTH) {
        return 999999;
    }
    int newRisk = risk + maze[x][y];
    if (current[x][y] > newRisk) {
        current[x][y] = newRisk;
    } else {
        return 999999;
    }
    if (x == LENGTH - 1 && y == LENGTH - 1) {
        return newRisk;
    }
    int lowestRisk = getBestPathRecursive(maze, current, x + 1, y, newRisk);
    int nextRisk = getBestPathRecursive(maze, current, x, y + 1, newRisk);
    if (lowestRisk < nextRisk) {
        lowestRisk = nextRisk;
    }
    nextRisk = getBestPathRecursive(maze, current, x, y - 1, newRisk);
    if (lowestRisk < nextRisk) {
        lowestRisk = nextRisk;
    }
    nextRisk = getBestPathRecursive(maze, current, x - 1, y, newRisk);
    if (lowestRisk < nextRisk) {
        lowestRisk = nextRisk;
    }
    return lowestRisk;
}

int getBestPath(int** maze) {
    int* current[LENGTH];
    for (int i = 0; i < LENGTH; i++) {
        current[i] = (int*)malloc(LENGTH * sizeof(int));
    }
    for (int x = 0; x < LENGTH; x++) {
        for (int y = 0; y < LENGTH; y++) {
            current[x][y] = 999999;
        }
    }
    getBestPathRecursive(maze, current, 0, 0, -1 * maze[0][0]);
    int bestRisk = current[LENGTH - 1][LENGTH - 1];
    freeMaze(current);
    return bestRisk;
}

int main(int argc, char* argv[]) {
    int* maze[LENGTH];
    for (int i = 0; i < LENGTH; i++) {
        maze[i] = (int*)malloc(LENGTH * sizeof(int));
    }
    readFile(argv[1], maze);
    printMaze(maze);
    incrementMaze(maze);
    printMaze(maze);
    incrementMaze(maze);
    printMaze(maze);
    incrementMaze(maze);
    printMaze(maze);
    incrementMaze(maze);
    printMaze(maze);
    incrementMaze(maze);
    printMaze(maze);
    incrementMaze(maze);
    printMaze(maze);
    incrementMaze(maze);
    printMaze(maze);
    incrementMaze(maze);
    printMaze(maze);
    incrementMaze(maze);
    /* printf("%d\n", getBestPath(maze)); */
    freeMaze(maze);
    return 0;
}
