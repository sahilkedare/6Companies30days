// Link : https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1

 int *findTwoElement(int *arr, int n) {
         int xors = 0;
       int i;
       int x = 0;
       int y = 0;
      
       for(i=0; i<n; i++)
          xors = xors ^ arr[i];
     
       for(i=1; i<=n; i++)
          xors = xors ^ i;
       
       int setBitNum = xors & ~ (xors-1);
       
       for(i = 0; i < n; i++)
       {
          if(arr[i] & setBitNum)
               x = x ^ arr[i]; 
          else
               y = y ^ arr[i]; 
       }
       for(i = 1; i <= n; i++)
       {
          if(i & setBitNum)
              x = x ^ i;  
          else
              y = y ^ i;  
       }