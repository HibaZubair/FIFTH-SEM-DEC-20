//minimum Subset difference problem
#include<iostream>
#define INT_MAX 100000
#include <algorithm> 
using namespace std;

int subset(int arr[],int sum,int size)
{

	int t[size+1][sum+1];
     for(int i=0;i<size+1;i++)
	{
		for(int j=0;j<sum+1;j++)
		{
			
			if(i==0)
			{
				t[i][j]=0;
			}
			if(j==0)
			{
				t[i][j]=1;
				
			}
		}
	}
	 
		for(int i=1;i<size+1;i++)
	{
		for(int j=1;j<sum+1;j++)
		{
			
			 if(arr[i-1]<=j)
			{
				t[i][j]=(t[i-1][j-arr[i-1]]||t[i-1][j]);
				
			}
			else if( arr[i-1]>j)
			{
				t[i][j]=t[i-1][j];
			}
		}
	}
		
	int sub[sum+1];
	cout<<endl<<"sum"<<sum<<endl;
	int count=0;
	for(int i=0;i<size+1;i++)
	{
		for(int j=0;j<sum+1;j++)
		{
			if(i==size&&count<sum+1)
			{
				sub[count]=t[i][j];
				++count;
//				cout<<sub[i]<<endl;
			}
		}
	}
	
	int range=sum/2,minimum=INT_MAX;
	int Range=sum;

//	cout<<range<<endl;
	for(int i=0;i<range;i++)
	{
		if(sub[i]==1)
		{
//			cout<<i<<endl;
			minimum=min(minimum,Range-(2*i));
//			cout<<minimum<<endl;
		}
	}
	return minimum;
}
int main()
{
	int arr[5]={2,4,6,8,10};
	int ans,sum,size=5;
	for(int i=0;i<size+1;i++)
	{
		sum=sum+arr[i];
	}
cout<<endl<<sum<<endl<<endl;
	ans=subset(arr,sum,size);
	cout<<endl<<endl<<"Answer: "<<ans;
}
