#include <stdio.h>

#define maxvertex 4

void addNode(int array[][maxvertex], int i, int j) {
    array[i][j] = 1;
    array[j][i] = 1;
}

void adjMatrix(int array[][maxvertex]) {
    for (int i = 0; i < maxvertex; i++) {
        for (int j = 0; j < maxvertex; j++) {
            array[i][j] = 0;
        }
    }
}

void printadjMatrix(int array[][maxvertex]) {
    for (int i = 0; i < maxvertex; i++) {
        for (int j = 0; j < maxvertex; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int array[maxvertex][maxvertex];
    adjMatrix(array);

    addNode(array, 1, 1);
    addNode(array, 1, 2);
    addNode(array, 3, 2);
    addNode(array, 2, 1);
    printadjMatrix(array);
}
