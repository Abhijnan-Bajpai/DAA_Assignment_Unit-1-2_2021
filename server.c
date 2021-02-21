#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "server.h"

long long int comp = 0;

void writeFile(int mode, FILE* fptrc, FILE* fptrt)
{
	long long int compRes;
	for(int size = 100000; size <= 1000000; size += 50000)
	{
		printf("%d\n", size);
		int arr[size];
		randArr(arr, size);
		clock_t t;
		t = clock();
		compRes = countComparisons(arr, size, mode);
		t = clock() - t;
		long double time_taken = ((long double)t)/CLOCKS_PER_SEC;
		fprintf(fptrc, "%d %lld\n", size, compRes);		
		fprintf(fptrt, "%d %LF\n", size, time_taken);
	}
}

void randArr(int arr[], int size) {
	for(int i = 0; i < size; i++)
	{
		arr[i] = rand() % (10000 + 1 - 1) + 1;	
	}
}

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int pick(int arr[], int i)
{
    // code here such that selecionSort() sorts arr[]
    int max = i;
    for(int j = 0; j <= i; j++)
    {
        if(arr[j] > arr[max])
            max = j;
        //counting the if condition compare and
        //the condition within for loop's incrementor
        comp+=2;  
    }
    return max;
}

void selectionSort(int arr[], int n)
{
   int i, j;
   for (i = n-1; i >=0; i--)      
   {
        int j = pick(arr, i);
        swap(&arr[i], &arr[j]);
        //the condition within for loop's incrementor
        comp++;
   }
}

void bubble(int arr[], int i, int n)
{   
    int temp;
    for(int i = 0; i < n - 1; i++)
    {
        if(arr[i] > arr[i + 1])
        {
            temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
        //counting the if condition compare and
        //the condition within for loop's incrementor
        comp+=2;
    }
}

void bubbleSort(int arr[], int n)
{
   int i;
   for (i = 0; i < n-1; i++)      
	{
		bubble(arr, i, n);
		//the condition within for loop's incrementor
		comp++;
	}
}

int partition (int arr[], int low, int high)
{
   int pivot = arr[high];
   int j = low - 1;
   int temp;
   
   for(int i = low; i <= high - 1; i++)
   {
       if(arr[i] <= pivot)
       {
           j++;
           temp = arr[j];
           arr[j] = arr[i];
           arr[i] = temp;
       }
       //counting the if condition compare and
       //the condition within for loop's incrementor
       comp+=2;
   }
   j++;
   temp = arr[high];
   arr[high] = arr[j];
   arr[j] = temp;
   
   return j;
}

void quickSort(int arr[], int low, int high)
{
    // code here
    if(low < high)
    {
    	//if condition comparison
        comp++;
        int pr = partition(arr, low, high);
        quickSort(arr, low, pr - 1);
        quickSort(arr, pr + 1, high);
    }
}

void merge(int arr[], int l, int m, int r)
{
     int res[r], i, j, k = 0;
     if(m == r)
        j = r;
     else
        j = m + 1;
     for(i = l; i <= m && j <= r;)
     {
         if(arr[i] < arr[j])
            res[k++] = arr[i++];
         else
            res[k++] = arr[j++];
        //counting the if condition compare and
        //the condition within for loop's incrementor
        comp+=2;
     }
     if(i != m + 1)
     {
         //if condition compare
         comp++;
         while(i != m + 1)
        {
        	res[k++] = arr[i++];
        	//while condition compare
        	comp++;
        }
     }
     else if(j != r)
     {
         //else if condition compare
         comp++;
         while(j != r)
        {
        	res[k++] = arr[j++];
        	//while condition compare
        	comp++;
        }
     }
     for(int a = l, b = 0; b < k; a++, b++)
     {
         arr[a] = res[b];
         //the condition within for loop's incrementor
         comp++;
     }
}


void mergeSort(int arr[], int l, int r)
{
	if(l < r)
	{
		int m = l + (r - l) / 2;
		//if condition's compare
		comp++;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);		
		merge(arr, l, m, r);
	}
}


long long int countComparisons(int arr[], int n, int mode)
{
	comp = 0;
	switch(mode)
	{
		case 0:
			selectionSort(arr, n);
			break;
		case 1:
			bubbleSort(arr, n);
			break;
		case 2:
			quickSort(arr, 0, n - 1);
			break;
		case 3:
			mergeSort(arr, 0, n - 1);
			break;		
	}	
	long long int compIn = comp;
	return compIn;
}













