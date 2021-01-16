//Longest common substring
#include<iostream>
using namespace std;
int lcs(string x,string y,int m,int n)
{
	int t[m+1][n+1];
	 int result = 0;  // To store length of the  
                     // longest common substring 
	for(int i=0;i<m+1;i++)
	{
		for(int j=0;j<n+1;j++)
		{
			if(i==0||j==0)
			{
				t[i][j]=0;
			}
		}
	}
	for(int i=1;i<m+1;i++)
	{
		for(int j=1;j<n+1;j++)
		{
			if(x[i-1]==y[j-1])
			{
				t[i][j]=1+t[i-1][j-1];
				result = max(result,t[i][j]); 
			}
			else
			{
				t[i][j]=0;
			}
		}
	}
	return result;
	
}
int main()
{
	string x="abdgf",y="abcdfhr";
    int m=x.size();
    int n=y.size();
    int ans;
    ans=lcs(x,y,m,n);
	cout<<"Answer: "<<ans;
}
