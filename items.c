#include "items.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
/*
 * =========================
 * Functions for milestone 1
 * =========================
 */

/*
 * This function reads all items in file, and returns them in file-order
 * in a dynamically created list.  Each line of the file is one item,
 * and has format:
 * '<description>' <damage> <cost> <weight>
 * RETURNS: base pointer to items in file in file order.  NULL if file does
 *          not exist, or has no validly formated lines.
 */
 item_t *getItem(FILE *fpin,int line_number)
{
   item_t *item_list;
   item_list = malloc(sizeof(item_t));
   assert(item_list);
   if(fscanf(fpin, " '%[^']' %d %f %f",item_list->name,&item_list->
                   dam,&item_list->cost,&item_list->weight)!=4)
            {
               printf("line %d of swords.dat could not be read, exiting",line_number);
               exit(2);
            }
   item_list->next = NULL;
   return(item_list);
}

item_t *ReadItemsFromFile(char *file)
{

   FILE *fpin;
   fpin = fopen("swords.dat","r");
   if(fpin == NULL)  /* If no file was read, display message and exit */
   {
      printf("swords.dat is missing, exiting the program");
      exit(1);
   }

   /*  array generator here,looks like this      *
    *                                            *
    *    Description   Damage   Cost   Weight    *
    *                                            *
    *    sharp tool    4        1.5    1.1       *
    *    rusty sword   8        5.0    8.1       *
    *    sword         10       10.0   8.0       *
    *    fine sword    12       100.0  7.2       *
    *    two h sword   20       200.0  15.0      *
    *                                            */
   item_t *itb=NULL;/* base pointer to the start of the list*/
   item_t *items_list;/*??? NULL list ??? */
   while(1)
   {
      int line_number = 1;
      if (itb==NULL)/*if we haven't done anything yet*/
         itb = items_list = getItem(fpin,line_number);
      else/*we have done stuff, lets add more */
      {
         items_list->next = getItem(fpin,line_number);/*create a new item at the end of the last one*/
         items_list = items_list->next;/*??? not sure what this does???*/

      }
      line_number++;
   }
   return(itb);/*return base pointer to the start of all items*/
}


      /************** OLD CODE  ***************
      if (itb==NULL)
      {
         items_list = malloc(sizeof(item_t));
         assert(items_list);
         if(sscanf(fpin, "%s %f %f %d",items_list->name,items_list->
                   cost,items_list->weight,items_list->dam)!=4)
         {
            printf(" A item could not scan correctly");
            exit(2);
         }
         items_list->next=NULL;
         itb = items_list;
      }
      else
      {
         items_list = malloc(sizeof(item_t));
         if(sscanf(fpin, "%s %f %f %d",items_list->name,items_list->
                   cost,items_list->weight,items_list->dam)!=4)
            {
               printf(" A item could not scan correctly");
               exit(2);
            }
            items_list->next = items_list;
            items_list->next = NULL;
      }

      *********************************************/

/*
 * As a hint, here is a line that would print success or failure of a line
 * in the proper format.  Delete this crap code but you can use the format for
 * your own read in from file.  You will simply read in lines until one fails,
 * at which point you return the base ptr to all allocated structures.


#if 0
   if (fscanf(fpin, " '%[^']' %d %f %f", name, &dam, &cost, &weight) == 4)
      printf("Read the line!");
   else
      printf("Failed to read line!");
#endif
   return(NULL);
}
*/



/*
 * This routine frees all storage associated with entire list itb
 */
void KillAllItems(item_t *itb)
{
}

/*
 * This function prints out all items in an easy-to-read table, with an item
 * on each line, each column separated by 2 spaces, and:
 *    4 digits for item number
 *    31 characters for name
 *    7 digits for damage
 *    13 characters for cost, with 2 decimal places printed
 *    9 characters for weight, with 2 decimal places printes
 */
void PrintItemTable
(
   FILE *fpout,    /* FILE stream to print to (set to stdout for screen) */
   item_t *itb     /* list of items to dump to screen */
)
{
   /* declarations here! */
   fprintf(fpout,
   " NUM  NAME                             DAMAGE          COST    WEIGHT\n");
   fprintf(fpout,
   "====  ===============================  ======  ============  ========\n");
   /* print all the lines */
    printf("\n");
}

/*
 * This function prints all items in itb to the a file with name file.  Each
 * line of the file is one item, and has format:
 * '<description>' <damage> <cost> <weight>
 * Output files from this routine can be read in by ReadItemsFromFile.
 */
void WriteItemsToFile
(
   char *file,     /* name of file to dump itb to */
   item_t *itb     /* list of items to be dumped to file */
)
{
}

/*
 * RETURNS: number of items in list itb
 */
int CountItems(item_t *itb)
{

}

/*
 * RETURNS: cumulative weight of all items in list itb
 */
float SumItemsWeight(item_t *itb)
{
   return(0.0);
}

/*
 * =========================
 * Functions for milestone 2
 * =========================
 */

/*
 * This function deletes the item at position pos from queue.  pos must be
 * between 0 and 1 less than the number of items in the list.
 * RETURNS: possibly new base ptr for list
 */
item_t *DelItemAtPos(item_t *itb, int pos)
{
   return(itb);
}

/*
 * This function duplicates the item pointed to be old, except that
 * the new structure's next member is set to NULL.
 * RETURNS: pointer to new structure duplicating old
 */
item_t *DupItem(item_t *old)
{
   return(NULL);
}

/*
 * This function adds item new at position pos in list itb.  Pos should be
 * between 0 and N (number of items in list):
 * If pos==0, then item becomes the new base pointer for list.
 * else if pos==N, the item is added to the end of the list.
 * otherwise, it is added internal to the list.
 * RETURNS: possibly new base ptr of list with added item
 */
item_t *AddItemAtPos
(
   item_t *itb,   /* base ptr of list of items to add to */
   item_t *new,   /* item to add to list */
   int pos        /* position to add to (starting from 0) */
)
{
   return(itb);
}


/*
 * =========================
 * Functions for milestone 3
 * =========================
 */
/*
 * This function reverses the item order in list pointed to by itb
 * RETURNS: base pointer of list in opposite order
 * NOTE: the old list is destroyed in making the new!
 */
item_t *ReverseItemOrder(item_t *itb)
{
   return(itb);
}

/*
 * This function does greatest-to-least sort of list itb on cost.
 * RETURNS: base pointer of new list.
 * NOTE: old list (itb) is destroyed in process of creating new list!
 */
item_t *SortItemsByCost(item_t *itb)
{
   return(itb);
}

/*
 * This function does greatest-to-least sort of list itb on Weight
 * RETURNS: base pointer of new list.
 * NOTE: old list (itb) is destroyed in process of creating new list!
 */
item_t *SortItemsByWeight(item_t *itb)
{
   return(itb);
}

/*
 * This function does least-to-greatest (alphabetic) sort of list itb on name.
 * RETURNS: base pointer of new list.
 * NOTE: old list (itb) is destroyed in process of creating new list!
 */
item_t *SortItemsByName(item_t *itb)
{
   return(itb);
}
