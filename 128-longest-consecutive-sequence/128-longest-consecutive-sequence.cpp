class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int> umap;
        for(auto x : nums){
            umap[x] = 1;
        }
        
        if(umap.size()==0 || umap.size()==1)
            return umap.size();
        int ans=INT_MIN , count = 1,pre;
        map<int, int>::iterator it,op;
        it = umap.begin();
        pre = it->first;
        it++;
        for(;it!=umap.end();it++){
            if(it->first == pre + 1){
                count++;
                op = it;
                // if(op++ == umap.end())
                //     ans = max(ans,count);
            }
            else{
                count = 1;
            }
                ans = max(ans,count);
            // cout<<pre<<" ";
            pre = it->first;
        }
          
        return ans;
    }
};