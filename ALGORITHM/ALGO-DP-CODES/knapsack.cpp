#include<iostream>
using namespace std;
int knapsack(int wt[],int val[],int n,int W)
{
	int t[n+1][W+1];
		for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<W+1;j++)
		{
			if(i==0||j==0)
			{
				t[i][j]=0;
			}
			else if(wt[i-1]<=j)
			{
				t[i][j]=max(val[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);
			}
			else if(wt[i-1]>j)
			{
				t[i][j]=t[i-1][j];
			}
		}
	}
	cout<<t[n][W]<<endl;
	return t[n][W];
}
int main()
{
	int n=4,wt[n]={1,3,4,5},val[n]={1,4,5,7},W=7,ans;
	ans=knapsack(wt,val,n,W);
    cout<<"ans "<<ans;
}
