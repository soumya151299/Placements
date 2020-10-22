#include <bits/stdc++.h> 
using namespace std; 

 
int main() 
{ 
    //Standard Input Part
	int n,i;
	cin>>n;
	vector<int>arr(n,0);
	for(int i=0;i<n;i++) cin>>arr[i];
	
	//Answer Part
	int ans=0; //no of pairs
	unordered_map<int,int> mp; //storing count of remainders (arr[i]%60)
	for(i=0;i<n;i++)
	{
	    if(arr[i]%60==0)
	    {
	        ans+= mp[0]; //Two multiples of 60 can be added together to form another multiple of 60
	    }
	    else
	    {
	        //If curent guy has remainder= z and there are k guys that we have found earlier
	        //having remainder= 60-z, then there will be k no of pairs having remainder 0 when divided
	        //by 60
	        int tofind= 60-(arr[i]%60);
    	    if(mp[tofind]>=1)
    	    {
    	        ans+=mp[tofind];
    	    }
	    }
	    //we add current guy to our remainders map
	    mp[arr[i]%60]++;
	    
	    
	}
	cout<<ans;
} 
