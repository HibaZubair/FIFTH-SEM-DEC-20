#include<iostream>
#include <bits/stdc++.h> 
using namespace std;
	int tempans=0,mn=INT_MAX;
int mcs(int arr[],int i,int j)
{

	if(i==j || i>j)
	{
		return 0;
	}

		for(int k=i;k<j;k++)
		{
			tempans=(mcs(arr,i,k)+mcs(arr,k+1,j)+arr[i-1]*arr[k]*arr[j]);
//				cout<<mn<<endl;
		if(mn>tempans)
		{
			mn=tempans;
		cout<<mn<<endl;
		}
		
		}
		
	
	
	return mn;
	
}
int main()
{
	
	int arr[]={10,30,5,60};
	int n = sizeof(arr) / sizeof(arr[0]); 
	int cost;
	cost=mcs(arr,1,n-1);
	cout<<"Answer: "<<cost;
}
