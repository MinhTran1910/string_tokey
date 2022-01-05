#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>

using namespace std;


struct HashTable {

	int K = 100;
	//K = 50;
	int M = K;
	int* table;

	void construct(int arr[], int N) {
		int key;
		table = new int[K];
		for (int i = 0; i < K; i++)
			table[i] = NULL;
		for (int i = 0; i < N; i++)
		{
			key = arr[i] % K;
			while (table[key] != NULL)
			{
				if ((key + 1) < K)
					key++;
				else
				{
					key = 0;
				}
			}
			table[key] = arr[i];
		}
		/*for (int i = 0; i < K; i++)
		{
			if (table[i] == NULL)
				printf("0\n");
			else
				printf("%d\n", table[i]);
		}*/
	}
	int string_tokey(int S)
	{
		int key = S;
		/*for (int i = 1; i < S.length(); i++)
			key += S[i] * i;*/
		key = S % (M);
		int i = 1;
		while (table[key] != NULL && S != table[key])
		{
			key = (key + i) % M;
			i++;
		}
		printf("%d\n", i);

		return i;
	}
};


void main()
{
	clock_t start, end;
	double time = 0, min=10 , max =0;
	int sum=0;
	int r = 80;
	int* arr = new int[r];
	int m, n;
	for (int i = 0; i < r; i++)
	{
		arr[i] = rand()+rand();
	}
	HashTable h;
	h.construct(arr, r);
	int a;
	for (int i = 0; i < r; i++)
	{
		a = arr[i];
		start = clock();
		int step = h.string_tokey(a);
		end = clock();
		double time_use = (double)(end - start) / CLOCKS_PER_SEC;
		time += time_use;
		if (min > time_use)
		{
			min = time_use;
		}
		if (max < time_use)
		{
			max = time_use;
		}
		sum += step;
	}
	for (int i = 0; i < 5; i++)
	{
		a = rand();
		start = clock();
		int step = h.string_tokey(a);
		end = clock();
		double time_use = (double)(end - start) / CLOCKS_PER_SEC;
		time += time_use;
		if (min > time_use)
		{
			min = time_use;
		}
		if (max < time_use)
		{
			max = time_use;
		}
		sum += step;
	}
	//printf("trung binh %f \ntong so buoc cua 95 lan %d", (double)sum / (r + 5), sum);
	printf("\nThoi gian trung binh= %f\nmin= %f\nmax= %f", time / (r + 5), min, max);
}