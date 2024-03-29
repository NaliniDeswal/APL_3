/**************************************************************************************************
*		FILE NAME	:	kruskal.cpp
*		PURPOSE		:	contains the implementation of Kruskal's algorithm
*		DATE		:	21/09/2013
*		TEAM		:	Nalini Deswal
*					Narendra Nalli
*					Pankaj Kashyap
**************************************************************************************************/
#include <header.h>

int c;				//local variable to check the graph is connected or not
union_find uf;			//object of union_find class type

/**************************************************************************************************
*		FUNCTION NAME	:	kruskal
*		DESCRIPTION	:	implementation of greedy algorithm to find out minimum spanning 
*					tree generated by adding edge of minimum weight at each step
*		INPUTS		:	array of edges of the graph,
*					array of nodes of the graph,
*					number of nodes,
*					number of edges,
*		OUTPUT		:	returns the number of edges in the minimum spanning tree
**************************************************************************************************/
int kruskal(vector <edge> &e , vector <mynode> &no ,int n , int m)
{
	// n = number of nodes;
	// m = total number of edges

	int k = 0;
	for(int i = 0 ; i <n ; i++)
	{
		uf.MakeSet(no[i].name);
	}
	
	//sorting the edges in the increasing order
	sort(e,0,m-1);
	
	//kruskal's algorithm
	for(int i = 0 ; i < m ; i++)
	{
		char *u = (char *)malloc(sizeof(char)*100);
		char *v = (char *)malloc(sizeof(char)*100);
		
		union_find::makenode *U, *V;  //Local variables fro temporary storing parent information
		
		strcpy(u,(e[i].start)->name);
		strcpy(v,(e[i].end)->name);
	
		U = uf.FindSet(u);
		V = uf.FindSet(v);
		if(U == V)
		{
			continue;
		}
		else
		{
			c = uf.UNION(U->data,V->data);
			e[i].min = true;
			k++;
		}
	}
	if(c != 1)
	{
		cout <<"\nEnter a connected graph \n"<<endl;
		exit(-1);
	}
	return k;
}

