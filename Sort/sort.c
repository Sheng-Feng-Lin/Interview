#include <stdio.h>
#include <stdlib.h>


int main()
{
	int a[6] = {10,7,8,4,6,5};
	int i,j, temp;

	for(i =0; i < 6; i++){
		for(j =0; j < 6-i; j++){
			if(a[j] > a[j+1]){
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;

			}
		}
	}
	for(i = 0; i < 6; i++)
	printf("%d ", a[i]);
	printf("\n");
	
}
