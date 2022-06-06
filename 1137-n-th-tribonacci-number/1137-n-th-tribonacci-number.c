

int tribonacci(int n){
    int i = 2, fib0 = 0, fib1 = 1, fib2 = 1, m;
    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    else if(n==2)
        return 1;
    else{
        while(i<n){
            m=fib2+fib1+fib0;
            fib0 = fib1;
            fib1 = fib2;
            fib2 = m;
            i++;
        }
        return m;
    }
}