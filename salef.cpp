   #include<bits/stdc++.h>
   using namespace std;
//   #define ll long long int
   int main()
   {
    int arr[]={1,2,4};
    int l=3;
    int m=9;
    int sum=0;
    int ans=0;
 

    //Calculating the maximum possible sum
    for(int i=0;i<l;i++)
    {
     sum+=arr[i];
    }

    int DP[l+2][sum+2];
    for(int i=0;i<l+2;i++)
    {
      for(int j=0;j<sum+2;j++)
      {
      DP[i][j]=0;
      }
     }
 

    //Filling 0th row of the table
    //With all possible sum values
    for(int j=1;j<sum+2;j++)
    {
     DP[0][j]=j-1;
    }

    //Filling 0th column 
    //With all the array values
   DP[1][0]=0;
   for(int j=2;j<l+2;j++)
   {
   DP[j][0]=arr[j-2];
   }

   //Filling 1st column 
   //Where sum value=0 with all 1's
   for(int i=1;i<l+2;i++)
   {
   DP[i][1]=1;
   } 
 

   //Filling the DP table
   //according to given logic
   for(int i=2;i<l+2;i++)
   {
     for(int j=1;j<sum+2;j++)
     {      
      if(DP[i-1][j]!=0)
      {
       DP[i][j+arr[i-2]]=DP[i-1][j+arr[i-2]]+DP[i-1][j];
      }
     }
     for(int j=1;j<sum+2;j++)
     {
      DP[i][j]=max(DP[i-1][j],DP[i][j]); 
     }  
    }
 

   //counting the number of values
   //divisible by m
   for(int j=1;j<sum+2;j++)
   {
    if((j-1)%m==0)
    ans+=DP[l+1][j];
  
   }
   cout<<"Number of subsets is:"<<ans<<"\n";
   return 0;
   }
