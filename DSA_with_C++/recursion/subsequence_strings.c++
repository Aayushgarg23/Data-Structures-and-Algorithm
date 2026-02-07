#include <bits/stdc++.h> 
using namespace std;


void solve(string str, string output, vector<string>&ans,int idx)
{
	if(idx==str.length())
	{
		if(output.length()>0)
		ans.push_back(output);
		return;
	}

	solve(str, output, ans, idx+1);

	output.push_back(str[idx]);
	solve(str, output, ans, idx+1);

}
vector<string> subsequences(string str){
	
	// Write your code here

	string output ="";
	vector<string>ans;

	solve(str, output, ans, 0);
	return ans;
	
}
