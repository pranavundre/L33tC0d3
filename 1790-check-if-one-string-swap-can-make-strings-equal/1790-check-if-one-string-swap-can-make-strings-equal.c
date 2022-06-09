

bool areAlmostEqual(char * s1, char * s2){
    int i = 0, n = 0;
    int arr[2];
    while(i<strlen(s1)){
        if(s1[i] != s2[i]){
            n=n+1;
            if(n>2)
                return false;
            arr[n-1]=i;
        }
        i++;
    }
    if(n==0)
        return true;
    else if(n==1)
        return false;
    else if(n==2){
        if(s1[arr[0]]==s2[arr[1]] && s1[arr[1]]==s2[arr[0]])
            return true;
        else
            return false;
    }
    return false;
}