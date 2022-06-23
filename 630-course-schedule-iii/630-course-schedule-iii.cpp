class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size();
        
        sort(courses.begin(), courses.end(), [](vector<int> a, vector<int> b){
            return a[1]< b[1];
        });
        
        priority_queue<int> pq;
        
        int days=0,cnt=0;
        
        for(int i=0;i<n;i++){
            days+=courses[i][0];
            cnt++;
            pq.push(courses[i][0]);
            if(days>courses[i][1]){
                days-=pq.top();
                pq.pop();
                cnt--;
            }
        }
        return cnt;
    }
};