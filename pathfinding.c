#include <stdlib.h>
#include <stdio.h>

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
            if (y == 10) {
                y = 0;
                x++;
            }
        }
    }
    fclose(file);
}

void printMaze(int** maze) {
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            printf("%d", maze[x][y]);
        }
        printf("\n");
    }
}

int main(int argc, char* argv[]) {
    int* maze[10];
    for (int i = 0; i < 10; i++) {
        maze[i] = (int*)malloc(10 * sizeof(int));
    }
    readFile(argv[1], maze);
    printMaze(maze);
    return 0;
}
