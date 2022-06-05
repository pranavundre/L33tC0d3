

double average(int* salary, int salarySize){
    int min, max;
    double sum=0.0000;
    if(salary[0]>salary[1]){
        max=salary[0];
        min=salary[1];
    }else{
        max=salary[1];
        min=salary[0];
    }
    int i=2;
    while(i<salarySize){
        if(salary[i]>min && salary[i]<max){
            sum+=salary[i];
        }else if(salary[i]<min){
            sum+=min;
            min = salary[i];
        }else if(salary[i]>max){
            sum+=max;
            max = salary[i];
        }
        i++;
    }
    return sum/(salarySize-2);
}