// LINK : https://practice.geeksforgeeks.org/problems/connect-nodes-at-same-level/1/#K

void connect(Node *root)
    {
        // queue<Node*>v;
        // printlevelorder(root,v);
        // v.push(NULL);
        // Node* r=v.front();
       
        // while(!v.empty()){
        //     if(v.front()!=NULL){
        //         r=v.front();
        //         v.pop();
        //         r->nextRight=v.front();
        //     }
        //     else v.pop();
        // }
        // cout<<endl;
       if(!root) return;
       queue<Node *> q;
       q.push(root);
       
       while(!q.empty()) {
           Node *prev;
           int n = q.size();
           
           for(int i = 0; i < n; ++i) {
               prev = q.front();q.pop();
               Node *curr = NULL;
               if(!q.empty() and i != n-1) curr = q.front();
               
               prev->nextRight = curr;
               
               if(prev->left) q.push(prev->left);
               if(prev->right) q.push(prev->right);
           }
       }
    }    