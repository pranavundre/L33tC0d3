

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes){
    
    if(r*c != matSize*(*matColSize)){
        *returnSize = matSize;
        *returnColumnSizes = matColSize;
        return mat;
    }
    
    *returnColumnSizes = malloc(sizeof(int) * r);
    int** newMat = malloc(sizeof(int*) * r);
    for (int i = 0; i < r; i++) {
        newMat[i] = malloc(sizeof(int) * c);
        returnColumnSizes[0][i] = c;
    }

    int row[r*c];
    int n = 0;
    
    for(int i = 0; i < matSize; i++)
        for(int j = 0; j < *matColSize; j++){
            row[n] = mat[i][j];
            n++;
        }
    
    int m = 0;
    
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++){
            newMat[i][j] = row[m];
            m++;
        }
    
    **returnColumnSizes = c;
    *returnSize = r;
    return newMat;
}