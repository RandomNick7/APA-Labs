#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void merge(long int* arr, long int low, long int mid, long int high){
    long int i = low, j = mid + 1, k = 0;
    long int* temp = (long int*)malloc((high - low + 1)*sizeof(long int));
    while ((i <= mid) && (j <= high))
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    while (j <= high)
        temp[k++] = arr[j++];
    while (i <= mid)
        temp[k++] = arr[i++];
    for (i = low, k = 0; i <= high; i++, k++)
        arr[i] = temp[k];
    free(temp);
}

void mergesort(long int* arr, long int low, long int high){
    if (low < high) {
        long int mid = (low + high) / 2;
        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);
        if (arr[mid] > arr[mid + 1]){
            merge(arr, low, mid, high);
        }
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
		mergesort(data,0,SIZE-1);
		gettimeofday(&end,NULL);
		
		fprintf(f,"%ld ",(end.tv_sec - start.tv_sec)*1000000 + end.tv_usec - start.tv_usec);
		free(data);
	}
	
	fclose(f);
	return 0;
}
