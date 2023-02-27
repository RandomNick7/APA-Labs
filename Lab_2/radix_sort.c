#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void countSort(long int arr[], long int n, long int exp) {
	long int* out = (long int*)malloc(sizeof(long int)*n);
    long int i, cnt[10] = {0};
    for (i = 0; i < n; i++){
        cnt[(arr[i] / exp) % 10]++;
	}
	for (i = 1; i < 10; i++){
        cnt[i] += cnt[i - 1];
	}
    for (i = n-1; i>=0; i--) {
        out[cnt[(arr[i] / exp) % 10] - 1] = arr[i];
        cnt[(arr[i] / exp) % 10]--; 
    }
    for (i = 0; i < n; i++){
        arr[i] = out[i];
	}
	free(out);
}

void radixSort(long int arr[], long int n) {
    long int max = arr[0];
    for (long int i = 1; i < n; i++)
        if (arr[i] > max){
            max = arr[i];
		}
    for (long int exp = 1; max / exp > 0; exp *= 10){
        countSort(arr, n, exp);
	}
}

int main(){
	srand(time(0));
	FILE* f = fopen("res.txt","w");
	for(int k=0;k<400;k++){
		long int i,SIZE =k*10000;
		long int* data = (long int*)malloc(sizeof(long int)*SIZE);
		for(long int i=0;i<SIZE;i++){
			data[i] = rand()*32768+rand();
		}
		struct timeval start, end;
		
		gettimeofday(&start,NULL);
		radixSort(data, SIZE);
		gettimeofday(&end,NULL);
		
		fprintf(f,"%ld ",(end.tv_sec - start.tv_sec)*1000000 + end.tv_usec - start.tv_usec);
		free(data);
	}
	
	fclose(f);
	return 0;
}