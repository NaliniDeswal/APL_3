/************************************************************************************************
*		FILE NAME	:	header.h
*		PURPOSE		:	contains all the function declaration and graph 
*					declarations
*		DATE		:	21/09/2013
*		TEAM		:	Nalini Deswal(CS13M030)
*					Narendra Nalli(CS13M031)
*					Pankaj Kashyap(CS13M035)
**************************************************************************************************/

/*******************************************Header Files*****************************************/

#include <iostream>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
#include <vector>

using namespace std;

/****************************************Graph Declaration****************************************/

/*Structure to store the node name*/
struct node
{
	char name[10];
};

typedef struct node mynode;

/*class to store the edge information*/
class edge
{
    public :
    	mynode *start,*end;
   	int cost;
	bool min;
    	edge()
    	{
        	start=NULL;
        	end=NULL;
        	cost=0;
		min = false;
    	} 
};

/*class to define union find data structure*/
class union_find
{
	public:
	int c_count;
	class makenode
	{
		public:
		string data;
		int rank;
		makenode *parent;	
		makenode(string d) : data(d), rank(0), parent(this) {}			//constructor
	};
	vector <makenode*> mn;
	makenode *FindSet(string );
	void MakeSet(string );
	int UNION(string , string );
};

/**************************************FUNCTION DECLARATIONS****************************************/
int kruskal(vector <edge> &e,vector <mynode> &no , int n , int m);
void sort(vector <edge> &e ,int l ,int r);
void merge(vector <edge> &e ,int l , int m ,int r);
