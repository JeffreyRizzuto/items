#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#define UL (unsigned long)

typedef struct node NODE;
struct node
{
  int info;
  NODE *next;
};

NODE *getnode()
{
	printf("In getnode\n");
	NODE *p;
	p = malloc(sizeof(NODE));
	return(p);
}

void printQueue()
{
	NODEPTR i;
	i = list;
	printf("Current Queue Is: ");
	if(i == NULL)
	{
		printf("EMPTY\n");
		return;
	}
	while(1)
	{
		printf("%d ", i->info);
		i = i->next;
		if(i == NULL)
			break;
	}
	printf("\n");
}

void pqinsert(NODEPTR list, FILE *file)
{
	printf("In pqinsert\n");
	int x;
	NODE *n;
	n = getnode();
	printf("Address of n is: %lu\n", UL&n);
	printf("Returned from getting node\n");
	fscanf(file, " %d", &x);
	printf("Inserting #: %d\n", x);
	n->info = x;
	n->next = list;
	list = n;
	printf("List's info is: %d\n", (list->info));
	printQueue(list);
}

void pqmindelete(NODE *list)
{
	printf("In pqmindelete\n");
	int minpos = 0;
	int x;
	int minval =0;
	if(list == NULL)
	{
		printf("INVALID DELETION: CANNOT DELETE EMPTY LIST\n");
		exit(1);
	}
	if(list->next == NULL)
	{
		printf("INVALID DELETION: CANNOT DELETE A SINGLE ITEM LIST\n");
		exit(2);
	}
	
	NODE *temp, *temp2;
	temp = list;
	
	for(x=0;temp->next != NULL; x++)
	{
		if((temp->info) < minval)
		{
			minval = temp->info;
			min = x;
		}
		temp = temp->next;
	}
	temp = list;
	for(x=0;x<min-1;x++)
	{
		temp = temp->next;
	}
	
	temp2 = temp;
	temp = temp->next;
	temp2->next = temp->next;
	free(temp);
	printf("Min. info is: %d\n", x);
	printQueue(list);
}

int main(int argc, char* argv[])
{
	FILE *file;
	file = fopen(argv[1], "r");

	NODE *list = NULL;


	while(!feof(file))
	{
		char tester[10];
		fscanf(file, "%s", tester);

		if(strcmp(tester, "INSERT") == 0)
			pqinsert(list, file);

		if(strcmp(tester, "REMOVE") == 0)
			pqmindelete(list);
	}

//EMPTY LIST
	printQueue(list);

	return(0);
}
