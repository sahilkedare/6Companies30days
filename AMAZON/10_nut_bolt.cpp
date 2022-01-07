// LINK : https://practice.geeksforgeeks.org/problems/nuts-and-bolts-problem0431/1#


	void matchPairs(char nuts[], char bolts[], int n) {
	   // sort(nuts,nuts+n);
	   //  sort(bolts,bolts+n);
	   char a[]={ '!','#','$','%','&', '*', '@', '^', '~'};
	   unordered_set<char>s;
	   for(int i=0;i<n;i++){
	       s.insert(nuts[i]);
	   }
	   int i=0,j=0;
	   while(i<9){
	       if(s.find(a[i])!=s.end()){
	           nuts[j]=a[i];
	           bolts[j]=a[i];
	           j++;
	           i++;
	       }       
	       else i++;
	   }
	}