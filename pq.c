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
typedef struct node *NODEPTR;
NODEPTR list;

NODEPTR getnode()
{
	printf("In getnode\n");
	NODEPTR p;
	p = (NODEPTR) malloc(sizeof(NODE));
	return(p);
}

void printQueue(NODEPTR list)
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
	NODEPTR n;
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

void pqmindelete(NODEPTR list)
{
	printf("In pqmindelete\n");
	int x;
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
	x = list->info;
	NODEPTR temp;
	NODEPTR min;
	temp = min = list;
	while((temp->next) != NULL)
	{
		temp = temp->next;
		if((temp->info) < x)
		{
			x = temp->info;
			min = temp;
		}
	}
	printf("Min. info is: %d\n", x);
	printQueue(list);
}

int main(int argc, char* argv[])
{
	FILE *file;
	file = fopen(argv[1], "r");

	list = NULL;


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
