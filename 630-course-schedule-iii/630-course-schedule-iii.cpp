class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        
        //sort the courses array with respect to second element
        sort(courses.begin(), courses.end(),[] (const auto &x, const auto &y) { return  x[1] < y[1]; });

        //int res=0;
        int sum=0;
				//storing each element in priority queue and if courses[i][1] crosses res then weremove element taking maximum days
        priority_queue<int>pq;
        for(int i=0;i<courses.size();i++){
            pq.push(courses[i][0]);
            sum+= courses[i][0];
            if(sum>courses[i][1]){
                sum-= pq.top();
                pq.pop();
            }
        }
        return pq.size();
        
        
        
        
        
        
        
        
//         int dur = 0;
//         int deadline = 0;
//         int prevDdln;
//         int count = 0;
        
//         for(int i = 0; i < courses.size(); i++){
//             for(int j = i; j < courses.size(); j++){
//                 prevDdln = deadline;
//                 dur = dur + courses[j][0];
//                 deadline = max(deadline, courses[j][1]);

//                 if(dur<=deadline){
//                     count++;
//                 }else{
//                     dur = dur - courses[j][0];
//                     deadline = prevDdln;
//                 }
//             }
//         }
//         return count;
    }
};