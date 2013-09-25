/**************************************************************************************************
*		FILE NAME	:	main.cpp
*		PURPOSE		:	driver program for the Kruskal's algorithm
*		DATE		:	21/09/2013
*		TEAM		:	Nalini Deswal (CS13M030)
*					Narendra Nalli(CS13M031)
*					Pankaj Kashyap(CS13M035)
**************************************************************************************************/
#include<algorithm>
#include <header.h>
bool Lesser(mynode a, mynode b) {
        if (strcmp(a.name, b.name) < 0)
                return true;
        return false;
}

		
int main(int argc , char *argv[])
{
	int i ;				//local loop variables
	FILE *fp;			//file pointer
	vector <edge> e;
	vector <mynode> nodes;
	vector <mynode> tnodes;
	edge t;
	mynode tempnode;
	int line_no = 0;		//keep track of the line numbers in the input file
	int node_end = 0;		//keep track of where the node counting is ending
	int file_end = 0;
	char line[500];			//temporary variable for reading from file line by line	
	int x;
	int no_nodes = 0;		//keep track of total number of nodes
	int no_edges = 0;		//keep track of total number  of edges
	int size;			

	/********************* strings for string comparisons***********************************/

	char graphname[30];	
	char graph[6] = "graph";	
	char node[9] = "// nodes";
	char edge[9] = "// edges";
	char semicolon[2] = ";";
	char space[2] = " ";
	char hyphen[3] = "--";
	char opening[2] ="{";
	char closing[2] ="}";
	char temp1[100] , temp2[100] ,temp3[100];	
	if(3 != argc)							//Checking for correct number of command line arguments
	{
		cout <<"\nEnter correct number of command line arguments\n";
		exit(-1);
	}
	else
	{
		fp = fopen(argv[1],"r");				//Opening the input file for reading
	}

	if(NULL == fp)							//Checking if file is open or not
	{
		cout <<"\nUnable to open file for reading";
		exit(-1);
	}
	else
	{
		while(!feof(fp))
		{
			if(fgets(line,sizeof(line),fp)!=NULL)		//Reading every line 1 by 1	
			{
				line_no ++;				//Incrementing line number for every line read
				char *templine = (char *)malloc(sizeof(char)*500);
				size = strlen(line)-1;
				strncpy(templine,line,size);
				if(size == 0)	
				{
					continue;
				}
				else if(line_no ==1)
				{
					stringstream ss(templine);
					ss >>temp1;
					ss >>temp2;
					ss >>temp3;
					if(strcmp(temp1,graph))
					{
						cout <<"\nThere is an error at line " <<line_no<<"\n";
						exit(-1);
					}
					if(strcmp(temp3,opening))
					{
						cout <<"\nThere is an error at line "<<line_no<<"\n";
						exit(-1);
					}
					cout<<"\nGraph name is : "<<temp2;
					strcpy(graphname,temp2);
				}
				else if((strcmp(templine,graph)) && (line_no == 1))
				{
					cout <<"\nFormat of the file is wrong on line "<< line_no <<"\n";
					exit(-1);
				}
				else if((!strcmp(templine,node)) && (line_no == 2 ))//Checking 2nd line is according to the format or not
				{
					//cout <<"\nSecond line is : "<<templine<<"\n";
				}
				else if((strcmp(templine,node)) && (line_no == 2))
				{
					cout <<"\nFormat of file is wrong on line " << line_no <<"\n";
					exit(-1);
				}
				else if (line_no != 1 && line_no != 2 && strcmp(templine,edge) && (node_end == 0)) //extracting nodes
				{
					if(!strcmp((templine+size-1),semicolon))
					{
						char *n = (char *)malloc(sizeof(char)*20);
						strncpy(n,templine,size-1);
						strcpy(tempnode.name,n);
						nodes.push_back(tempnode);
						tnodes.push_back(tempnode);
						no_nodes++;
					}
					else if(strcmp((templine+size-1),semicolon) && strcmp(templine,closing))
					{
						cout <<"\n There is a semicolon missing in line \n"<<line_no <<"\n";
						exit(-1);
					}
					else if(!strcmp(templine,closing))
					{
						cout <<"\nError in line : "<<line_no <<"\n"<<endl;
						exit(-1);
					}	
				}
				else if (!strcmp(templine,edge))	//extracting edge information
				{
				//	cout <<"\n Now we will look for edges\n";
					node_end = line_no;	
					sort(tnodes.begin(), tnodes.end(), Lesser);
					for(x = 0 ; x < tnodes.size() ; x++)
					{
						if(!strcmp(tnodes[x].name,tnodes[x-1].name))
					 	{
							cout <<"\nDuplicate node = "<<tnodes[x].name<<"\n"<<endl;
							exit(-1);
						}
					}
				}
				else if(node_end != 0 && strcmp(templine,closing))
				{
					if(!strcmp((templine+size-1),semicolon))
					{
						int loc1 , loc2;
						int turn1 = 0 , turn2 = 0;
						int  i = 0;
						int cost;     //Keep trck of the cost of each edge
						int flag1 =3 , flag2 = 3;
						string temp;
						char *node1 = (char *)malloc(sizeof(char)*30);  //For storing starting node of the edge
						char *node2 = (char *)malloc(sizeof(char)*30);	//For storing end node of the edge
						char output[10][100];
					
						/*Converting the string into an input stream and then tokenizing it*/
						stringstream ssin(templine);
						while(ssin.good())
						{
							ssin >> output[i];
							++i;
						}
						if(!strcmp(output[1],hyphen))		//extracting the edge information
						{
							strcpy(node1,output[0]);
							strcpy(node2,output[2]);
							stringstream ss(output[3]);	//extracting the cost of the edge
							getline(ss,temp,'"');
							if(temp != "[label=")
							{
								cout <<"\nError at line number : "<<line_no<<endl;	
								exit(-1);
							}
							getline(ss,temp,'"');
							if(temp == "")	
							{
								cout <<"\nThere is an error in line : "<<line_no <<endl;
								exit(-1);
							}
							ss.str(temp);
							ss>>cost;
							if( cost <0)			//checking if edge weight is negative
							{
								cout <<"\nEdge weight can not be negative \n";
								cout <<"Error at line = "<<line_no<<"\n";
								exit(-1);
							}
							for( i = 0 ; i<=no_nodes ; i++) //checking for valid staring and ending nodes
							{
								if(flag1 != 0)
								{
									flag1= strcmp(nodes[i].name,node1);
								}
								else if (flag1 == 0 && turn1 == 0)
								{
									loc1 = i-1;
									turn1 = 1;
								}
								if(flag2 != 0)
								{
									flag2 = strcmp(nodes[i].name,node2);
								}
								else if(flag2 == 0 && turn2 == 0)
								{
									loc2 = i-1;
									turn2 = 1;
								}
							}
							if(!flag1 && !flag2)
							{	
								t.start = &nodes[loc1];
								t.end = &nodes[loc2];
								t.cost = cost;
								e.push_back(t); 
								no_edges++;
							}
							else
							{
								cout <<"\nNode not present\n";
								cout <<"\nerror is at line : "<<line_no;
								exit(-1);
							}
						}
						else if(strcmp(output[1],hyphen))		//checking for -- inbetween nodes
						{
							cout <<"\nThere is an error in line "<<line_no<<"\n";
							exit(-1);
						}
						else if(strcmp((templine+size-1),semicolon))	//Checking for semicolon at the end of each line
						{
							cout <<"\n There is a semicolon missing in line \n"<<line_no;
							exit(1);
						}
					}
					else
					{
						cout <<"\nThere is an error in line :  "<<line_no;
						exit(-1);
					}

				}
				else if(!strcmp(templine,closing))		//Checking the last line of the program
				{
					file_end = line_no;
					cout <<"\nEnd of the program\n";	
				}
				else
				{
					cout <<"\nThere is an error in line : "<<line_no<<"\n"<<endl;
				}
			} 
		}
	}
	fclose(fp);   		//closing the input file
	
	/*Calling kruskal*/
	size = kruskal(e,nodes,no_nodes,no_edges);

	fp = fopen(argv[2],"w");					//Opening the input file for reading

	if(NULL == fp)							//Checking if file is open or not
	{
		cout <<"\nUnable to open file for writing";
		exit(-1);
	}
	else								//Writing the final output to output file
	{
		char *temp = (char *)malloc(sizeof(char)*30);
		fprintf(fp, "graph ");
		fprintf(fp , "%s",graphname);
		fprintf(fp , " {\n");
		fprintf(fp, "// nodes\n");
	}
	for(int a = 0 ; a<no_nodes ; a++)				//Writing the nodes to output file
	{
		fprintf(fp, "%s;\n", nodes[a].name);
	}
	fprintf(fp, "// edges\n");

	for(int a = 0 ; a<no_edges ; a++)				//Writing the edges to output file
	{
		if (e[a].min == false)
			fprintf(fp, "%s -- %s [label=\"%d\",style=dotted];\n", (e[a].start)->name, (e[a].end)->name, e[a].cost);
		else
			fprintf(fp, "%s -- %s [label=\"%d\",color=blue];\n", (e[a].start)->name, (e[a].end)->name, e[a].cost);
	
	}
	fprintf(fp , "}");
	return 0;	
}	
