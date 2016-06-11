#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define SWAP(x,y) {int t; t = x; x=y; y=t;}

void quickSort(int[], int , int);
int binarySearch(int[], int);

int main()
{
	int number[MAX] = {5,3,2,10,4,1,75,80,35,9};
	int i = 0;
	quickSort(number, 0, MAX-1);
	
	printf("數列: ");
	for(i = 0; i < MAX; i++)
		printf("%d ", number[i]);

	printf("\n");
	
	//if((i = binarySearch(number, 10)) >= 0)
	if((i = binarySearch2(number, 10,0,MAX)) >= 0)
		printf("find digit index is %d\n", i);
	else
		printf("can't find this digit");
	
	return 0;
}

void quickSort(int number[], int left, int right)
{
	if(left < right){
		int s = number[(left+right)/2];
		int i = left -1;
		int j = right +1;
		
		while(1){
			while(number[++i] < s);
			while(number[--j] > s);
			if(i >= j)
				break;
			SWAP(number[i], number[j]);

		}
		quickSort(number, left, i-1);
		quickSort(number, j+1, right);
	}


}

int binarySearch(int number[], int data)
{
	int low = 0;
	int upper = MAX-1;

	while(low <= upper){
		int mid = (low+upper)/2;
		if(number[mid] < data)
			low = mid + 1;
		else if(number[mid] > data)
			upper = mid -1;
		else
			return mid;
	}
	return -1;
}


//recursive 
int binarySearch2(int number[], int data, int left, int right)
{
	int mid = (left+right)/2;
	if (left > right)
		return -1;
	if(number[mid] < data)
		return binarySearch2(number, data, mid+1, right);
	else if(number[mid] > data)
		return binarySearch2(number, data, left, mid-1);
	else
		return mid;
}


