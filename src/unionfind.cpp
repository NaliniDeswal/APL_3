/**************************************************************************************************
*		FILE NAME	:	unionfind.cpp
*		PURPOSE		:	contains the implementation of the unionfind datastructure
*		DATE		:	21/09/2013
*		TEAM		:	Nalini Deswal
*					Narendra Nalli
*					Pankaj Kashyap
**************************************************************************************************/
#include <header.h>


static int i = 0;
/**************************************************************************************************
*		FUNCTION NAME	:	FindSet
*		DESCRIPTION	:	returns a pointer to the representative of the set contatning
*					node x (returns address of parent of a node).
*					uses path compression 
*		INPUTS		:	node name whose parent you want to find out
*		OUTPUT		:	address of the parent of the input node
**************************************************************************************************/

union_find :: makenode * union_find :: FindSet(string x)
{
	int j;
	struct makenode *temp1 , *temp2;
	for(j = 0 ; j < mn.size() ; j++)		//Checking if node whose set you want to find out exists or not
	{
		if(x == mn[j] -> data)
		{
			temp1 = mn[j];
			temp2 = mn[j] -> parent;
		}
//		else
//		{
//			cout <<"\n No such node exists \n";
//			exit(-1);
//		}
	}
	while(temp1 != temp2)			//making the node points to its parent;
	{
        	temp1 = temp2;
		temp2 = temp1->parent;
	}
    	return (temp2);
}

/**************************************************************************************************
*		FUNCTION NAME	:	MakeSet
*		DESCRIPTION	:	creates a new set whose only member(and thus the parent) is x 
*		INPUTS		:	node name whose parent you want to find out
*		OUTPUT		:	address of the parent of the input node
**************************************************************************************************/

void union_find :: MakeSet(string x)
{
	makenode* tempnode = new makenode(string(x));
	mn.push_back(tempnode);
	i++;
	c_count ++;			//keep track of number of sets
}

/**************************************************************************************************
*		FUNCTION NAME	:	UNION
*		DESCRIPTION	:	unites two sets containing x and y into a new set assuming
*					initially x and y belong to two different sets. 
*					in it union by rank is used . 
*					element with smaller rank is made to point to element with 
*					larger rank					
*		INPUTS		:	two nodes whose union need to be performed
*		OUTPUT		:	number of sets at the end of the union operation
**************************************************************************************************/

int  union_find :: UNION(string x,string y)
{
	makenode* xRoot = FindSet(x);
	makenode* yRoot = FindSet(y);
	/*using unio by rank (upper bound on the height of the tree)*/
	if(xRoot->rank > yRoot->rank)
	{
		yRoot->parent = xRoot;
	}
	else if(xRoot->rank < yRoot->rank)
	{
		xRoot->parent = yRoot;
	}
	else
	{
		yRoot->parent = xRoot;
		xRoot->rank = (xRoot->rank)+1;
	}
	c_count --;				//keep track of number of sets
	return c_count;
}
