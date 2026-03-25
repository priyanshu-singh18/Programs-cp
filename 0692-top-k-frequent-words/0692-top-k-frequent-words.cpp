class Solution {
public:
    struct comp{
    bool operator()(pair<int,string> &a , pair<int,string> &b){
        if(a.first == b.first){
            return a.second < b.second;
        }
        return a.first > b.first ;
    }};

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string , int> umap;
        vector<string> res;

        for(string word : words){
            umap[word]++;
        }

        priority_queue<pair<int , string> , vector<pair<int,string>> , comp> pq; 

        for(auto it : umap){
            pq.push({it.second, it.first}); 

            if(pq.size() > k){
                pq.pop();
            }
        }



        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }

        reverse(res.begin(),res.end());
        return res;    
    }
};