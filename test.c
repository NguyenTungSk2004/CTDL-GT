#include <stdio.h>

void selection_sort(int a[], int n){
	for (int i = 0; i < n-1; i++){
		int k = i;
		for (int j = i+1; j < n; j++){
			if (a[k] > a[j]) k =j;
		}
		if (k != i){
			int tmp = a[k];
			a[k] = a[i];
			a[i] = tmp;
		}
	}
}

void indl(int a[], int n){
	for (int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
}

int main(){
	int a[100000];
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	selection_sort(a, n);
	indl(a,n);
}