class Solution {
public:
    bool isPossible(vector<int>& target) {
        long sum=0,max=0;
        for(int i=0;i<target.size();i++)
        {
            sum+=target[i];
            if(target[max]<target[i]){
                max=i;
            }
        }
        
        long diff=sum-target[max];
        if(target[max]==1 || diff==1){
            return 1;
        }
        if(diff>target[max] || diff==0 || target[max]%diff==0){
            return 0;
        }
        target[max]%=diff;
        return isPossible(target);
    }
};