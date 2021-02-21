#include <stdlib.h>
#include <stdio.h>
#include "server.h"

int main()
{	
	FILE *fptrc;
	FILE *fptrt;
	
	fptrc = fopen("/home/abhijnan/Documents/PESU/DAA_Assignments/Unit-1_2/data/selection_sort_comp.txt", "w");
	fptrt = fopen("/home/abhijnan/Documents/PESU/DAA_Assignments/Unit-1_2/data/selection_sort_time.txt", "w");
	printf("Selection sort\n");
	writeFile(0, fptrc, fptrt);
	fclose(fptrc);
	fclose(fptrt);
	
	fptrc = fopen("/home/abhijnan/Documents/PESU/DAA_Assignments/Unit-1_2/data/Bubble_sort_comp.txt", "w");
	fptrt = fopen("/home/abhijnan/Documents/PESU/DAA_Assignments/Unit-1_2/data/Bubble_sort_time.txt", "w");
	printf("Bubble sort\n");
	writeFile(1, fptrc, fptrt);
	fclose(fptrc);
	fclose(fptrt);

	fptrc = fopen("/home/abhijnan/Documents/PESU/DAA_Assignments/Unit-1_2/data/Quick_sort_comp.txt", "w");
	fptrt = fopen("/home/abhijnan/Documents/PESU/DAA_Assignments/Unit-1_2/data/Quick_sort_time.txt", "w");
	printf("Quick sort\n");
	writeFile(2, fptrc, fptrt);
	fclose(fptrc);
	fclose(fptrt);
		
	fptrc = fopen("/home/abhijnan/Documents/PESU/DAA_Assignments/Unit-1_2/data/Merge_sort_comp.txt", "w");
	fptrt = fopen("/home/abhijnan/Documents/PESU/DAA_Assignments/Unit-1_2/data/Merge_sort_time.txt", "w");
	printf("Merge sort\n");
	writeFile(3, fptrc, fptrt);
	fclose(fptrc);
	fclose(fptrt);

	return 0;
}
