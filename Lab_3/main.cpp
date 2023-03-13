#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <cmath>

using namespace std;

void Algo1(long int n){
	bool* c = (bool*)malloc(sizeof(bool)*n);
	for(long int i=0;i<n;i++){
		c[i] = true;
	}
	
	c[1] = false;
	long int i=2, j=0;
	while(i<=n){
		if(c[i] == true){
			j=2*i;
		}
		while(j<=n){
			c[j] = false;
			j+=i;
		}
		i++;
	}
	free(c);
}

void Algo2(long int n){
	bool* c = (bool*)malloc(sizeof(bool)*n);
	for(long int i=0;i<n;i++){
		c[i] = true;
	}
	
	c[1] = false;
	long int i=2, j=0;
	while(i<=n){
		j=2*i;
		while(j<=n){
			c[j] = false;
			j+=i;
		}
		i++;
	}
	free(c);
}

void Algo3(long int n){
	bool c[n];
	for(long int i=0;i<n;i++){
		c[i] = true;
	}
	
	c[1] = false;
	long int i=2, j=0;
	while(i<=n){
		if(c[i] == true){
			j=i+1;
		}
		while(j<=n){
			if(j%i==0){
				c[j] = false;
			}
			j++;
		}
		i++;
	}
	free(c);
}

void Algo4(long int n){
	bool c[n];
	for(long int i=0;i<n;i++){
		c[i] = true;
	}
	
	c[1] = false;
	long int i=2;
	while(i<=n){
		long int j=2;
		while(j<i){
			if(i%j==0){
				c[i] = false;
			}
			j++;
		}
		i++;
	}
	free(c);
}

void Algo5(long int n){
	bool c[n];
	for(long int i=0;i<n;i++){
		c[i] = true;
	}
	
	c[1] = false;
	long int i=2;
	while(i<=n){
		long int j=2;
		while(j<=sqrt(i)){
			if(i%j==0){
				c[i] = false;
			}
			j++;
		}
		i++;
	}
	free(c);
}

int main(){
	srand(time(0));
	FILE* f = fopen("results.txt","a");
	for(long int k=1000000;k<5000000;k+=50000){
		struct timeval start, end;
		
		gettimeofday(&start,NULL);
		Algo2(k);
		gettimeofday(&end,NULL);
		
		fprintf(f,"%ld ",(end.tv_sec - start.tv_sec)*1000000 + end.tv_usec - start.tv_usec);
	}
	fprintf(f,"\n");
	
	fclose(f);
	return 0;
}