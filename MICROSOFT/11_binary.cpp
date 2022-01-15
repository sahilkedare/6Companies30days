// LINK : https://practice.geeksforgeeks.org/problems/generate-binary-numbers-1587115620/1/

vector<string> generate(int N)
{
	vector<string>ans;
	queue<string>q;
	q.push("1");
	
	while(N--){
	    string s1=q.front();
	    q.pop();
	    
	    ans.push_back(s1);
	    
	    q.push(s1+"0");
	    q.push(s1+"1");
	}
	return ans;
}

