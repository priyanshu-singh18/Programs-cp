// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


 // } Driver Code Ends
/*
// node structure:

struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/

class Solution{
public:

    Node* parentop(unordered_map<Node*,Node*>& ump , int target,Node* root){
        
        queue<Node*> qop;
        qop.push(root);
        
        Node* targetNode;
        while(!qop.empty()){
            int n = qop.size();
            
            while(n--){
                Node *temp = qop.front();
                qop.pop();
                if(temp->data == target)
                    targetNode = temp;
                    
                if(temp->left){
                    ump[temp->left] = temp;
                    qop.push(temp->left);
                }
                if(temp->right){
                    ump[temp->right] = temp;
                    qop.push(temp->right);
                }
            }
        }
        return targetNode;
    }
    

    
    
    int sum_at_distK(Node* root, int target, int k)
    {
        // code heren
        unordered_map<Node*,Node*> ump;
        Node* targetNode = parentop(ump,target,root);
        
        unordered_map<Node*,bool> vis;
        queue<Node*> qop;
        qop.push(targetNode);
        vis[targetNode] = true;
        int cnt = 0;
         int ans = 0;
        while(!qop.empty()){
            int n = qop.size();
            if(cnt++==k){
                break;
            }
            while(n--){
                Node* temp = qop.front();
                qop.pop();
                ans += temp->data;
                if(temp->left and !vis[temp->left]){
                    qop.push(temp->left);
                    vis[temp->left] = true;
                }
                
                if(temp->right and !vis[temp->right]){
                    qop.push(temp->right);
                    vis[temp->right] = true;
                }
                
                if(ump[temp] and !vis[ump[temp]]){
                    qop.push(ump[temp]);
                    vis[ump[temp]] = true;
                }
            }
            
        }
        
        while(!qop.empty()){
            ans+=qop.front()->data;
            qop.pop();
        }
        return ans;
    }
};



// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        
        int target,k;
        cin>> target >> k;
        getchar();
        
        Solution ob;
        cout<< ob.sum_at_distK(root,target,k) << endl;
    }
	return 0;
}

  // } Driver Code Ends