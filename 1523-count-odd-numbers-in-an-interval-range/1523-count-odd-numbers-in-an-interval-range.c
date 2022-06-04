

int countOdds(int low, int high){
    if(low%2!=0 && high%2!=0){
        return ((high-low)/2)+1;
    }
    else if((low%2!=0 && high%2==0) || (low%2==0 && high%2!=0)){
        return ((high-low)+1)/2;
    }
    else{
        return (high-low)/2;
    }
  
    // int cnt = 0;
    // for(int i = low; i<=high; i++){
    //     if(i%2 == 1){
    //         cnt++;
    //     }
    // }
    // return cnt;
}