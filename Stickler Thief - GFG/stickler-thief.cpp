//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
    vector<int> m(n,0);
    int s=n;
    if(s==1)
    return arr[0];
    else if(s==2)
    return max(arr[0],arr[1]);
    else if(s==3)
    return max(arr[1],arr[0]+arr[2]);

    m[0]=arr[0];
    m[1]=arr[1];
    m[2]=arr[0]+arr[2];

    int mi=INT_MIN;

    for(int i=3;i<s;i++)
    {
        m[i]=arr[i]+max(m[i-2],m[i-3]);
        mi=max(mi,m[i]);
    }

    return mi;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends