class StockSpanner {
public:
    StockSpanner() {
        
    }
    
     stack<pair<int,int>> sop;
    vector<int> v;
    int idx=-1;
    
    int ngl(vector<int>& stocks){
            
        
        // for(int i = idx-1; i< stocks.size();i++){
            if(sop.empty())
                v.push_back(1);
            else if(!sop.empty() and sop.top().first > stocks[idx])
                v.push_back(idx - sop.top().second );
            else {
                while(!sop.empty() and sop.top().first<=stocks[idx])
                    sop.pop();
                
                if(sop.empty())
                    v.push_back(idx+1);
                else
                    v.push_back(idx - sop.top().second );
            }
            
            sop.push({stocks[idx],idx});
    // }
        return v[stocks.size()-1];
    }
    
    vector<int> stocks;
    
    int next(int price) {
        idx++;
        stocks.push_back(price);
        return ngl(stocks);
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */