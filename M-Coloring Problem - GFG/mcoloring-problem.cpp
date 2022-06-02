// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.

// bool possible(int node, int col, bool graph[101][101],int n, vector<int>& color){
//   for(int k=0;k<n;k++){ 
//       if( k!=node and graph[node][k] == 1 and color[k]==col)
//         return false;
       
//   }
//     return true;
// }

// bool solve(int node,int n,int m,vector<int>& color,bool graph[101][101]){
//     if(node==n){
//         return true;
//     }
    
//     for(int i=1;i<=m;i++){
//         if(possible(node,i,graph,n,color)){
//             color[node] = i;
//             if(solve(node+1,n,m,color,graph) == true)
//                 return true;
            
//             color[node] = 0;
//         }
//     }
//     return false;
// }

// bool graphColoring(bool graph[101][101], int m, int n) {
//     // your code here
    
//     vector<int> color(n,0);
//     if(solve(0,n,m,color,graph));
//         return true;
  
//     return false;
    
// }


bool isValid(int node, int col, bool graph[101][101],int V, vector<int>& colors){
    for(int j=0;j<V;j++){
        if(j!=node && colors[j]==col && graph[node][j] ==1){
            return false;
        }
    }
    return true;
}

bool solve(int node, bool graph[101][101], int m, int V,vector<int>& colors){
    if(node == V){
        return true;    
    }
    for(int i=1;i<=m;i++){
        if(isValid(node,i,graph,V,colors)){
            colors[node] = i;
            if(solve(node+1, graph, m , V, colors)){
                return true;
            }
            colors[node] = 0;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int V)
{
    vector<int> colors(V,0);
    // your code here
    if(solve(0,graph,m,V,colors)){
        return true;
    }
    return false;
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends