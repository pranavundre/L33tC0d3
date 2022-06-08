int sumOfDigits(int n){
    int sum = 0;
    while(n != 0){
        sum+=pow((n%10),2);
        n = n/10;
    }
    return sum;
}

bool isHappy(int n){
    int i = 0;
    while(n!=1 && i<10){
        n = sumOfDigits(n);
        i++;
    }
    if(n == 1) return true;
    else return false;
}