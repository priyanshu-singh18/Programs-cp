class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answer;
        
        stack<pair<int,int>> sop;
        
        for(int i=temperatures.size()-1;i>=0;i--){
            if(sop.empty())
                answer.push_back(0);
            else if(sop.top().first > temperatures[i])
                answer.push_back(sop.top().second -i);
            else{
                while(!sop.empty() and sop.top().first <= temperatures[i])
                    sop.pop();
                
                if(sop.empty())
                    answer.push_back(0);
                else
                    answer.push_back(sop.top().second - i);
            }
            sop.push({temperatures[i],i});
        }
        reverse(answer.begin(),answer.end());
        return answer;
    }
};