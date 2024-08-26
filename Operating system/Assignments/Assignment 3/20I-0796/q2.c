#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  
#include <pthread.h>



// quad core
// merge sort code taken from geeks for geeks

int size;

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}
 
/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}


void* thread_sort(void *arg)
{
	int *val_p = (int *) arg;
	int arr_size = size;
	printf("Given array is \n");
    	printArray(val_p, arr_size);
 
    	mergeSort(val_p, 0, arr_size - 1);
 
    	printf("\nSorted array is \n");
    	printArray(val_p, arr_size);
	pthread_exit(NULL);	
}



int main()
{
	int s;
	printf("Entern size of array(multiple of 4)\n");
	scanf("%d", &s);
	 
	int array[s];
	
	for(int i=0; i<s;i++)
	{
		printf("Enter element %i \n", i);
		scanf("%d",&array[i]);
	}
	 
	size= s / 4; 
	 
	int sarr1[size];
	int sarr2[size];
	int sarr3[size];
	int sarr4[size]; 
	
	int t1,t2,t3;
	t1=size-1;
	t2=(s/2)-1;
	t3=t1+t2+1;
	int i1=0,i2=0,i3=0,i4=0;
	
	for(int i=0;i<s;i++)
	{
		if(i<= t1)
		{
			sarr1[i1]=array[i];
			i1++;
		}
		else if(i<= t2)
		{
			sarr2[i2]=array[i];
			i2++;
		}
		else if(i<= t3)
		{
			sarr3[i3]=array[i];
			i3++;
		}
		else
		{
			sarr4[i4]=array[i];
			i4++;
		}
	}
	
	
	pthread_t thread1,thread2,thread3,thread4;
/*	
	for(int i=0;i<4;i++)
	{
		sarr1[i]= array[i];
	}
*/	
	
	
	pthread_create(&thread1, NULL, thread_sort,(void*)&sarr1);
	pthread_join(thread1,NULL);
	
	pthread_create(&thread2, NULL, thread_sort,(void*)&sarr2);
	pthread_join(thread1,NULL);
	
	pthread_create(&thread3, NULL, thread_sort,(void*)&sarr3);
	pthread_join(thread1,NULL);
	
	pthread_create(&thread4, NULL, thread_sort,(void*)&sarr4);
	pthread_join(thread1,NULL);
		

}
