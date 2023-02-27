#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void heapify(long int arr[], long int n, long int i) {
    long int largest = i;
    long int left = 2 * i + 1;
    long int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
      largest = left;
    if (right < n && arr[right] > arr[largest])
      largest = right;
    if (largest != i) {
        long int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heapSort(long int arr[], long int n) {
    long int temp;
    for(long int i = n/2-1; i>=0; i--){
        heapify(arr, n, i);
    }
    for(n--; n>=0; n--){
        temp = arr[0];
        arr[0] = arr[n];
        arr[n] = temp;
        heapify(arr, n, 0);
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
		heapSort(data,SIZE);
		gettimeofday(&end,NULL);
		
		fprintf(f,"%ld ",(end.tv_sec - start.tv_sec)*1000000 + end.tv_usec - start.tv_usec);
		free(data);
	}
	
	fclose(f);
	return 0;
}
