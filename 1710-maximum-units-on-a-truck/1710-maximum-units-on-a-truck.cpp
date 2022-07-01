class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end() , [] (vector<int> a , vector<int> b){
           return a[1]>b[1]; 
        });   
        int units=0,i=0;
        while(i<boxTypes.size() and truckSize){
            int need = min(truckSize, boxTypes[i][0]); 
            units+=boxTypes[i][1]*need;
            truckSize-=need;
            i++;
        }
        return units;
    }
};