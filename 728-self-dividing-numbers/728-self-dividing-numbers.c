

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// int* selfDividingNumbers(int left, int right, int* returnSize){
//     int* arr = (int*) malloc((right - left) * sizeof(int));
//     int flag=0, c=0;
//     for(int i=left; i<=right; i++){
//         int n;
//         while(i%10!=0){
//             n = i%10;
//             if(i%n==0){
//                 flag = 0;
//             }else{
//                 flag = 1;
//                 break;
//             }
//             i=i/10;
//         }
//         if(flag == 0){
//             arr[c++] = i;
//         }
//     }
//     *returnSize=c;
//     return arr;
// }

bool check(int num) {
    int ori = num;
    while(num > 1) {
        int tmp = num % 10;
        if(tmp == 0 || ori % tmp != 0) return false;
        num -= tmp;
        num /= 10;
    }
    return true;
}

int* selfDividingNumbers(int left, int right, int* returnSize) {
    int cnt = 0;
    int* res = (int*) malloc((right - left) * sizeof(int));
    for(int i = left; i <= right; i++) {
        if(i % 10 == 0) continue;
        if(check(i)) res[cnt++] = i;
    }
    *returnSize = cnt;
    return res;
}