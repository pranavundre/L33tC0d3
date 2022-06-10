

int diagonalSum(int** mat, int matSize, int* matColSize){
    int sum = 0;
    for(int i = 0; i < matSize; i++)
        sum += mat[i][i];
    for(int i = 0; i < matSize; i++)
        sum += mat[i][matSize-i-1];
    if(matSize%2 != 0)
        sum -= mat[matSize/2][matSize/2];
    return sum;
}