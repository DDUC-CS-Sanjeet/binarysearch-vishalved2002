#include<iostream>
#include <bits/stdc++.h>
using namespace std;

bool binarySearchReacursive(int* array, int startIndex, int lastIndex, int element)
{
	if(lastIndex>=startIndex)
	{ int midIndex=(lastIndex + startIndex)/2;
	  if (array[midIndex]>element)
	   return binarySearchReacursive( array, startIndex,midIndex-1,element);
   	else if( array[midIndex]<element)
	   return binarySearchReacursive( array,midIndex+1,lastIndex, element );
	 else    
     return true;
	}
	return false;
}

bool binarySearchIterative(int* array, int startIndex, int lastIndex, int element)
{  int midIndex=0, flag=0;

   while(lastIndex>=startIndex)
   {
   	int midIndex=(lastIndex + startIndex)/2;
   	if (array[midIndex]>element)
   	    lastIndex=midIndex-1;
   	else if( array[midIndex]<element)
	   startIndex=midIndex+1;
	else
	return true;       
   	
   }
  
     
  return false;
}

int main()
{
	int* arr = NULL;
	int n ,element;
	cout<<"Enter the size of array"<<endl;
	cin>>n;
	arr = new int [n];
	cout<<"Enter the elements of array"<<endl;
	for(int i=0;i<n;i++)
	   cin>>arr[i];
	   sort(arr, arr+n);  
	 cout<<"Enter the element to be searched"<<endl;
	 cin>>element; 
	 
	
   cout<<"Result by iterative binary search "<<endl;
   bool result1 = binarySearchIterative( arr, 0, n-1,element);
   (result1 ==false)? cout<<"Element not found !!"<<endl
                     :cout<<"Element is in the array."<<endl;
                     
    cout<<" Result by recursive binary search "<<endl;
	bool result2 = binarySearchReacursive( arr,0, n-1,element);
	(result2 ==false)? cout<<"Element not found !!"<<endl
                     :cout<<"Element is in the array."<<endl;
                                      


  return 0;
}
