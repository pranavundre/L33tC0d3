

int fib(int n){
    int i = 1, fib0 = 0, fib1 = 1, m;
    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    else{
        while(i<n){
            m=fib1+fib0;
            fib0 = fib1;
            fib1 = m;
            i++;
        }
        return m;
    }
}