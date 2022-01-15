// LINK : https://practice.geeksforgeeks.org/problems/rotate-by-90-degree0356/1/


#include<bits/stdc++.h>
using namespace std;
void rotate (vector<vector<int> >& matrix);


void transpose(vector<vector<int> >& v,int N)
{
    for (int i = 0; i < N; i++)
        for (int j = i+1; j < N; j++)
            swap(v[i][j], v[j][i]);
}

void rotate(vector<vector<int> >& m)
{
    int n=m.size();
    transpose(m,n);
    int i=0,j=n-1;
   
    while(i<j){
        for(int k=0;k<n;k++){
            swap(m[i][k],m[j][k]);
        }
        i++;
        j--;
    }
    
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
          cout << m[i][j]<<" ";
        cout <<"\n";
    }
}


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t; 
    while(t--)
    {
        int n;
        cin>>n; 
        vector<vector<int> > matrix(n);
        for(int i=0; i<n; i++)
        {
            matrix[i].resize(n);
            for(int j=0; j<n; j++)
                cin>>matrix[i][j]; 
        }
        rotate(matrix);
        for (int i = 0; i < n; ++i)
        {
            for(int j=0; j<n; j++)
                cout<<matrix[i][j]<<" ";
            cout<<"\n";
        }
    }
    return 0;
}

  // } Driver Code Ends