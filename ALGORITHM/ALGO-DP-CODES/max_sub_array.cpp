#include<iostream>
#include<cmath>
using namespace std;
//int mid,max_right_sum,max_left_sum,max_cross_sum;
int max_sum (int right_subarray_sum,int left_subarray_sum,int crossing_sum)
{
	cout<<"jhj,";
	int answer;
	if(right_subarray_sum>left_subarray_sum)
	{
		if(right_subarray_sum>crossing_sum)
		{
			return right_subarray_sum;
		}
		else
		{
			return crossing_sum;
		}
	}
	else if(left_subarray_sum>crossing_sum)
	{
		return left_subarray_sum;
	}
	else
	{
			return crossing_sum;
	}
}
int max_crossing_sum(int arr[],int l,int mid,int h)
{
	int i;
	//left sum
	int left=INT_MIN;
 int	sum=0;
	for(i=mid;i<=0;i--)
	{
		sum=sum+arr[i];
		if(sum>left)
		{
			left=sum;
		}
		
	}
    
	//right sum
	int right=INT_MIN;
	sum=0;
	for( i=mid+1;i<=h;i++)
	{
		sum=sum+arr[i];
		if(sum>right)
		{
			right=sum;
		}
		
	}
	cout<<"right "<<right;
	return (left+right);
		
}
int maxsum(int arr[],int l,int h)
{
	if(l==h)//low==high means ek element tou smallest valid input
	{
		
		return arr[l];
	}
  
   		int mid=l+h/2;
   		
   	int	max_right_sum=maxsum(arr,l,mid);
   	int	max_left_sum=maxsum(arr,mid+1,h);
   	int	max_cross_sum=max_crossing_sum(arr,l,mid,h);
   
   return  max_sum (max_right_sum,max_left_sum,max_cross_sum);
	
}

int main()
{
	int arr[]={-2,1,-3,4,-1,2,1,-5,4};
    int ans;
    ans= maxsum(arr,0,8);
    cout<<ans;
	
}
