#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void quicksort(long int arr[], long int first, long int last){
    if(first<last){
        long int i, j, pivot, temp;
        pivot=first;
        i=first;
        j=last;
        while(i<j){
            while(arr[i]<=arr[pivot]&&i<last)
                i++;
            while(arr[j]>arr[pivot])
                j--;
            if(i<j){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
        temp=arr[pivot];
        arr[pivot]=arr[j];
        arr[j]=temp;
        quicksort(arr,first,j-1);
        quicksort(arr,j+1,last);
    }
}

int main(){
	srand(time(0));
	FILE* f = fopen("res.txt","w");
	for(int k=0;k<400;k++){
		long int i,SIZE=k*10000;
		long int* data = (long int*)malloc(sizeof(long int)*SIZE);
		for(long int i=0;i<SIZE;i++){
			data[i] = rand()*32768+rand();
		}
		struct timeval start, end;
		
		gettimeofday(&start,NULL);
		quicksort(data,0,SIZE-1);
		gettimeofday(&end,NULL);
		
		fprintf(f,"%ld ",(end.tv_sec - start.tv_sec)*1000000 + end.tv_usec - start.tv_usec);
		free(data);
	}
	
	fclose(f);
	return 0;
}
