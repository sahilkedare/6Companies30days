// LINK : https://practice.geeksforgeeks.org/problems/burning-tree/1/#


// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  int burn_time( map<Node*,Node*>&mp,Node *start){
      queue<Node*>x;
      map<Node*,int>vis;
      vis[start]=1;
      x.push(start);
      int mx=0;
      
      while(!x.empty()){
          int n=x.size();
          int f=0;
          for(int i=0;i<n;i++){
              Node *t=x.front();
              x.pop();
              if(t->left and !vis[t->left]){
                  vis[t->left]=1;
                  x.push(t->left);
                  f=1;
              }
              if(t->right and !vis[t->right]){
                  vis[t->right]=1;
                  x.push(t->right);
                  f=1;
              }
              if(mp[t] and !vis[mp[t]]){
                  vis[mp[t]]=1;
                  x.push(mp[t]);
                  f=1;
              }
          }
        if(f==1) mx++;
      }
      return mx;
  } 
  
  Node *map_parent( map<Node*,Node*>&mp,Node* root,int target){
      queue<Node*>q;
      q.push(root);
      Node *res,*temp;
      while(!q.empty()){
          temp=q.front();
          if(temp->data == target) res=temp;
          q.pop();
          
          if(temp->left){
              q.push(temp->left);
              mp[temp->left]=temp;
          }
          if(temp->right){
              q.push(temp->right);
              mp[temp->right]=temp;
          }
      }
      return res;
  }
  int minTime(Node* root, int target) 
    {
        map<Node*,Node*>mp;
        Node *start= map_parent(mp,root,target);
        return burn_time(mp,start); 
    }
};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends