//Subet sum problem
#include<iostream>
using namespace std;

bool subset(int arr[],int sum,int size)
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
			else if(arr[i-1]<=j)
			{
				t[i][j]=(t[i-1][j-arr[i-1]]||t[i-1][j]);
			}
			else if(arr[i-1]>j)
			{
				t[i][j]=t[i-1][j];
			}
		}
	}
	//display matrix
	for(int i=0;i<size+1;i++)
	{
		for(int j=0;j<sum+1;j++)
		{
			
			cout<<t[i][j]<<" ";
		}
		
				cout<<"\n";
			
	}
//	cout<<t[n][W]<<endl;
	return t[size][sum];
}
int main()
{
	int arr[5]={1,2,3,4,5},sum=5;
	bool ans;
	int size=5;
	ans=subset(arr,sum,size);
	cout<<"Answer: "<<ans;
}
