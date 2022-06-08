

bool canMakeArithmeticProgression(int* arr, int arrSize){
    int a, sum;
    for (int i = 0; i < arrSize; ++i)
        for (int j = i + 1; j < arrSize; ++j)
            if (arr[i] > arr[j]){
                a =  arr[i];
                arr[i] = arr[j];
                arr[j] = a;
            }
    for(int i = 1; i < arrSize-1; i++)
        if((arr[i] - arr[i-1]) != (arr[i+1] - arr[i]))
            return false;
    return true;
    // if(arrSize%2==0){
    //     sum=arr[0]+arr[arrSize-1];
    //     int i=1;
    //     while(i<(arrSize/2)){
    //         if(arr[0+i]+arr[arrSize-1-i]==sum)
    //             continue;
    //         else
    //             return false;
    //         i++;
    //     }
    // }else{
    //     sum=arr[0]+arr[arrSize-1];
    //     int j=1;
    //     if(arr[(arrSize-1)/2]*2==sum)
    //         while(j<(arrSize/2)){
    //             if(arr[0+j]+arr[arrSize-1-j]==sum)
    //                 continue;
    //             else
    //                 return false;
    //             j++;
    //         }
    //     else
    //         return false;
    // }
    // return true;
}