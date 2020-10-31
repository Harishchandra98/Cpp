#include<iostream>
using namespace std;
int main(){
	int i,n,count=0;
	int k,a,j=0;
	
	cout<<"Enter the Number of packets--";
	cin>>n;
	cout<<"Enter the values of array=";
	int array[n];
	for(i=0;i<n;i++){
	cin>>array[i];	
	}
	 for (i = 0; i < n; ++i) 
        {
 
            for (j = i + 1; j < n; ++j)
            {
 
                if (array[i] > array[j]) 
                {
 
                    a =  array[i];
                    array[i] = array[j];
                    array[j] = a;
 
                }
 
            }
 
        }
	i=0;
	while(i<n){
	k=array[i];
		
		while(array[i]<=k+4){		
		i++;
	}
	
	count++;
	
}
cout<<"Number of Containers = "<<count;
}
