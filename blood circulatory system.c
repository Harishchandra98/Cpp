#include<stdio.h>
#include<stdlib.h> 

typedef struct adjlist_node
{
	int vertex;					//Index of Adjacency list
	struct adjlist_node *next;	
}node_src, *node_dest;

typedef struct adjlist
{								
	int num;					//Number of elements in the Adjacency list
	node_src *head;
}adj_src, *adj_dest;

typedef struct graph
{
	int num;					//Number of vertices in the Graph
	adj_dest adjListArr;
}graph_src, *graph_dest;

//Structure of Red Blood Cells
struct RedBloodCells{
	int lifespan;
	int prob;
	int cycle;
	float amountRed;
};

//Structure of White Blood Cells
struct WhiteBloodCells{
	int lifespan;
	int prob;
	int cycle;
	float amountWhite;
};

//Structure of Platlates
struct Platlates{
	int lifespan;
	int prob;
	int cycle;
	float amountP;
};

node_dest createNode(int v)
{
	node_dest newNode = (node_dest)malloc(sizeof(node_src));
	
	if(!newNode)
	{
		printf("Unable to allocate memory for new node");
	}
	
	newNode->vertex = v;
	newNode->next = NULL;
	
	return newNode;
}

graph_dest createGraph(int n)
{
	int i;
	
	graph_dest graph = (graph_dest)malloc(sizeof(graph_src));
	
	if(!graph)
	{
		printf("Unable to allocate memory for graph");
	}
	
	graph->num = n;
	
	graph->adjListArr = (adj_dest)malloc(n*sizeof(adj_src));
	
	if(!graph->adjListArr)
	{
		printf("Unable to allocate memory for adjacency list array");
	}
	
	for(i=0;i<n;i++)
	{
		graph->adjListArr[i].head = NULL;
		graph->adjListArr[i].num = 0;
	}
	return graph;
}

void addEdge(graph_src *graph, int src, int dest, int weight)
{
	node_dest newNode = createNode(dest);
	newNode->next = graph->adjListArr[src].head;
	graph->adjListArr[src].head = newNode;
	graph->adjListArr[src].num++;
}

void displayGraph(graph_dest graph)
{
	int i;
	
	for(i=0;i<graph->num;i++)
	{
		printf("Blood flows from %d to: \n",i);
		
		node_dest adjListPtr = graph->adjListArr[i].head;
		printf("%d-> ",i);
		
		while(adjListPtr)
		{
			printf("%d->", adjListPtr->vertex);
			adjListPtr = adjListPtr->next;
		}
		printf("/0\n\n");
	}
}

int main()
{
	float amountRed;
	float amountWhite;
	float amountP;
	
	printf("\n*****************************\n\n");
	printf("HUMAN BLOOD CIRCULORY SYSTEM\n\n");
	printf("\t0:- Right Atrium\n");
	printf("\t1:- Right Ventricle\n");
	printf("\t2:- Left Atrium\n");
	printf("\t3:- Left Ventricle\n");
	printf("\t4:- Lungs\n");
	printf("\t5:- Upper Body\n");
	printf("\t6:- Liver\n");
	printf("\t7:- Stomach\n");
	printf("\t8:- Kidney\n");
	printf("\t9:- Legs\n");
	printf("\n*****************************\n\n");
	
	graph_dest dir_graph = createGraph(10);
	
	addEdge(dir_graph, 0, 1, 0);
	
	addEdge(dir_graph, 1, 4, 0);
	
	addEdge(dir_graph, 2, 3, 0);
	
	addEdge(dir_graph, 3, 5, 30);
	addEdge(dir_graph, 3, 6, 0);
	addEdge(dir_graph, 3, 7, 5);
	addEdge(dir_graph, 3, 8, 10);
	addEdge(dir_graph, 3, 9, 100);
	
	addEdge(dir_graph, 4, 2, 0);
	
	addEdge(dir_graph, 5, 0, 30);
	
	addEdge(dir_graph, 6, 0, 0);
	
	addEdge(dir_graph, 7, 0, 5);
	
	addEdge(dir_graph, 8, 0, 10);
	
	addEdge(dir_graph, 9, 0, 100);
	
	displayGraph(dir_graph);
	
	printf("Enter the amount of Red Blood Cells per 1ml: ");
	scanf("%0.0f", amountRed);
	
	printf("Enter the amount of White Blood Cells per 1ml: ");
	scanf("%0.0f", amountWhite);
	
	//printf("Enter the amount of Platelates per 1ml: ");
	//scanf("%f", amountP);
	
	return 0;
}
