#include <stdio.h>


int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
   
    if (numRows <= 0) {
        *returnSize = 0;
        return NULL;
    }

    
    int** triangle = (int**)malloc(numRows * sizeof(int*));
    *returnColumnSizes = (int*)malloc(numRows * sizeof(int));
    *returnSize = numRows;


    for (int i = 0; i < numRows; i++) {
        triangle[i] = (int*)malloc((i + 1) * sizeof(int));
        (*returnColumnSizes)[i] = i + 1;

        
        triangle[i][0] = triangle[i][i] = 1;


        for (int j = 1; j < i; j++) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }

    return triangle;
}


void printTriangle(int** triangle, int numRows, int* returnColumnSizes) {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d ", triangle[i][j]);
        }
        printf("\n");
    }
}


int main() {
    int numRows;

    
    printf("Enter the number of rows for Pascal's triangle: ");
    scanf("%d", &numRows);

    int returnSize;
    int* returnColumnSizes;

    int** triangle = generate(numRows, &returnSize, &returnColumnSizes);

    
    printf("Pascal's Triangle:\n");
    printTriangle(triangle, numRows, returnColumnSizes);

  
    for (int i = 0; i < numRows; i++) {
        free(triangle[i]);
    }
    free(triangle);
    free(returnColumnSizes);

    return 0;
}
