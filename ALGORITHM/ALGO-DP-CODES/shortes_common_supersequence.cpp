//Shortest common supersequence
#include<iostream>
using namespace std;
int lcs(string x,string y,int m,int n)
{
	int t[m+1][n+1];
	
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
			}
			else
			{
				t[i][j]=max(t[i][j-1],t[i-1][j]);
			}
		}
	}
	return t[m][n];
	
}
int main()
{
	string x="aggtab",y="gxtxayb";
    int m=x.size();
    int n=y.size();
    int ans;
    ans=lcs(x,y,m,n);
    int ssshort=m+n;
    cout<<ssshort<<endl;
    ssshort=ssshort-ans;
	cout<<"Answer: "<<ssshort;
}
