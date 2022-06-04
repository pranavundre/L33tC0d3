

bool checkPerfectNumber(int num){
    int i=1;
    int sum=0;
    while(i<=(num/2)){
        if(num%i==0){
            sum=sum+i;
        }
        i++;
    }
    if(sum==num){
        return true;
    }
    else{
        return false;
    }
}