/**************************************************************************************************
*		FILE NAME	:	sort.cpp
*		PURPOSE		:	sort the numbers in an monotonically increasing order
*		DATE		:	21/09/2013
*		TEAM		:	Nalini Deswal
*					Narendra Nalli
*					Pankaj Kashyap
**************************************************************************************************/

#include <header.h>

/**************************************************************************************************
*		FUNCTION NAME	:	sort
*		DESCRIPTION	:	Recursively sort the elements in the subarrays and merge
*					them togather to generate final result
*		INPUTS		:	an array of edges to be sorted ,
*					starting index of array ,
*					end index of array
*		OUTPUT		:	void
**************************************************************************************************/

void sort(vector <edge> &e,int l,int r)
{
	int q;
	int i ;
	if(l<r)
	{
		q = (l+r)/2;			//finding out the middle element to divide array imto two
		sort(e,l,q);			//Recursively calling the sort function again
		sort(e,q+1,r);
		merge(e,l,q,r);			//merging two sorted lists togather
	}
}

/**************************************************************************************************
*		FUNCTION NAME	:	merge
*		DESCRIPTION	:	merge two sorted lists togather
*		INPUTS		:	an array of edges to be sorted , 
*					starting index of array,
*					index of the middle element, 
*					end index of array
*		OUTPUT		:	void
**************************************************************************************************/
void merge(vector <edge> &e,int l,int m,int r)
{
	int a=m-l+1;
	int b=r-m;
	edge L[a+1] ,R[b+1];		//two temporary sub arrays to store two sublists
	int i , j , k;
	for(i=1;i<=a;i++)	
	{
		L[i] = e[l+i-1];
	}
	for(j=1 ; j<=b ;j++)
	{
		R[j] = e[m+j];	
	}
	L[a+1].cost = 100001;		//assigning infinitely large values to detect end of array
	R[b+1].cost = 100001;
	i = 1;
	j = 1;
	for (k = l ; k <=r ; k++)	//merging sub lists togather in sorted order
	{
		if(L[i].cost <= R[j].cost)
		{
			e[k] = L[i];
			i = i+1;
		}
		else
		{
			e[k] = R[j];
			j = j+1;
		}
	}
}		
