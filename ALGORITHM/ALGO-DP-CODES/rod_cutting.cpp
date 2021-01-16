#include<iostream>
using namespace std;
int unboundedknapsack(int length[],int price[],int n,int L)
{
	int t[n+1][L+1];
		for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<L+1;j++)
		{
			if(i==0||j==0)
			{
				t[i][j]=0;
			}
			else if(length[i-1]<=j)
			{
				t[i][j]=max(price[i-1]+t[i][j-length[i-1]],t[i-1][j]);
			}
			else if(length[i-1]>j)
			{
				t[i][j]=t[i-1][j];
			}
		}
	}
		for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<L+1;j++)
		{
			
			cout<<t[i][j]<<" ";
		}
		
				cout<<"\n";
			
	}
	cout<<t[n][L]<<endl;
	return t[n][L];
}
int main()
{
	int price[]={1,2,3,4},ans;
	int L=sizeof (price)/sizeof price[0]; 
	int *Length=new int (L);
	for(int i=0;i<L;i++)
	{
		Length[i]=i+1;
	}
	ans=unboundedknapsack(Length,price,L,L);
    cout<<"ans "<<ans;
}
