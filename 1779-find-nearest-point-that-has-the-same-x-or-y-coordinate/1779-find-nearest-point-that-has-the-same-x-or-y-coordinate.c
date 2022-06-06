

int nearestValidPoint(int x, int y, int** points, int pointsSize, int* pointsColSize){
    int arr[pointsSize][3];
    int c=0;
    for(int i = 0; i<pointsSize; i++){
        if(points[i][0] == x || points[i][1] == y){
            arr[c][0] = i;
            arr[c][1] = points[i][0];
            arr[c][2] = points[i][1];
            c=c+1;
        }
    }
    
    int index = arr[0][0];
    int min = abs(arr[0][1] - x) + abs(arr[0][2] - y);
    
    if(c>0)
        for(int i=0; i<c; i++){
            if((abs(arr[i][1] - x) + abs(arr[i][2] - y)) < min){
                min = abs(arr[i][1] - x) + abs(arr[i][2] - y);
                index = arr[i][0];
            }
        }
    else
        return -1;
    return index;
}