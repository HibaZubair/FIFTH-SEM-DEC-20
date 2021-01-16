//Print Longest common substring
#include<iostream>
#include<bits/stdc++.h> 
using namespace std;
int lcs(string x,string y,int m,int n)
{
	string s;
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
		for(int i=0;i<m+1;i++)
	{
		for(int j=0;j<n+1;j++)
		{
			if(t[i][j]==result)
			{
				m=i;
				n=j;
			}
		}
	
	}

	for(int i=0;i<m+1;i++)
	{
		for(int j=0;j<n+1;j++)
		{
			cout<<t[i][j]<<" ";
		}
		cout<<endl;
	}
			int i=m, j=n;
		
	while(i>0 && j>0)
	{
		cout<<"i:" <<i<<endl;
				cout<<t[i-1][j]<<" "<<endl;
			cout<<t[i][j-1]<<" "<<endl<<endl;
	
		if(x[i-1]==y[j-1])
		{
			s.push_back(x[i-1]);
		
			--i;
			--j;
		}
		else if(t[i-1][j]==0 && t[i][j-1]==0)
		{
			cout<<t[i-1][j]<<" "<<endl;
			cout<<t[i][j-1]<<" "<<endl<<endl;
			i=-1;
			j=-1;
		}
		else
		{
			if(t[i-1][j]>t[i][j-1])
			{
				--i;
			}
			else
			{
				--j;
			}
		}
	}
	reverse(s.begin(),s.end());
	cout<<s;
	cout<<endl;
	return result;
	
}
int main()
{
	string x="abcde",y="abcdf";
    int m=x.size();
    int n=y.size();
    int ans;
    ans=lcs(x,y,m,n);
	cout<<"Answer: "<<ans;
}
