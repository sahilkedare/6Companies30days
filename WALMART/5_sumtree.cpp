// https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1/

int t(Node *root){
        if(root==NULL) return 0;
        int old=root->data;
        int l=0,r=0;
        l=t(root->left);
        r=t(root->right);
        
        root->data=l+r;
        
        return old+l+r;
    }
    void toSumTree(Node *root)
    {
       t(root);
    }