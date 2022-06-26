#include <stdlib.h>
#include <stdio.h>

#define LENGTH 100
#define MAX 999999

int readFile(char* filename, int** maze) {
    FILE *file;
    if ((file = fopen(filename, "r")) != NULL) {
        int x = 0;
        int y = 0;
        for (int i = 0; i < (LENGTH * LENGTH) + LENGTH; i++) {
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
}

int** createMaze() {
    int** maze = malloc(LENGTH * sizeof(int*));
    for (int i = 0; i < LENGTH; i++) {
        maze[i] = malloc(LENGTH * sizeof(int));
    }
    return maze;
}

void fillMaze(int num, int** current) {
    for (int x = 0; x < LENGTH; x++) {
        for (int y = 0; y < LENGTH; y++) {
            current[x][y] = num;
        }
    }
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
            if (maze[x][y] == MAX) {
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
    int newRisk = risk + maze[x][y];
    if (current[x][y] > newRisk) {
        current[x][y] = newRisk;
    } else {
        return MAX;
    }
    if (x == LENGTH - 1 && y == LENGTH - 1) {
        return newRisk;
    }
    int lowestRisk = MAX;
    int nextRisk = MAX;
    if (x + 1 < LENGTH && newRisk + maze[x + 1][y] < current[x + 1][y]) {
        nextRisk = getBestPathRecursive(maze, current, x + 1, y, newRisk);
        if (lowestRisk < nextRisk) {
            lowestRisk = nextRisk;
        }
    }
    if (y + 1 < LENGTH && newRisk + maze[x][y + 1] < current[x][y + 1]) {
        nextRisk = getBestPathRecursive(maze, current, x, y + 1, newRisk);
        if (lowestRisk < nextRisk) {
            lowestRisk = nextRisk;
        }
    }
    if (y > 0 && newRisk + maze[x][y - 1] < current[x][y - 1]) {
        nextRisk = getBestPathRecursive(maze, current, x, y - 1, newRisk);
        if (lowestRisk < nextRisk) {
            lowestRisk = nextRisk;
        }
    }
    if (x > 0 && newRisk + maze[x - 1][y] < current[x - 1][y]) {
        nextRisk = getBestPathRecursive(maze, current, x - 1, y, newRisk);
        if (lowestRisk < nextRisk) {
            lowestRisk = nextRisk;
        }
    }
    return lowestRisk;
}

int getBestPath(int** maze) {
    int** current = createMaze();
    fillMaze(MAX, current);
    getBestPathRecursive(maze, current, 0, 0, -1 * maze[0][0]);
    int bestRisk = current[LENGTH - 1][LENGTH - 1];
    freeMaze(current);
    return bestRisk;
}

int main(int argc, char* argv[]) {
    int** maze = createMaze();
    readFile(argv[1], maze);
    printf("answer: %d\n", getBestPath(maze));
    freeMaze(maze);
    return 0;
}
