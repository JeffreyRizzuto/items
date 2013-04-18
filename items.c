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
item_t *getItem(FILE *fpin,char *file, int line_number)
{
   item_t *item_list;
   item_list = malloc(sizeof(item_t));
   assert(item_list);
   int temp;
   if(fscanf(fpin,"'%[^']' %d %f %f",item_list->name,&item_list->
                   dam,&item_list->cost,&item_list->weight)!=4)
   {
      printf("Line %d of %s could not be read\n",line_number,file);
      printf("Program will now exit\n");
      exit(2);
   }
   while((temp = fgetc(fpin))!=('\n'));
   item_list->next = NULL;
   return(item_list);
}

item_t *ReadItemsFromFile(char *file)
{
   FILE *fpin;
   fpin = fopen(file,"r");
   assert(fpin);
   fpos_t current_position;
   int line_number = 1;
   item_t *itb=NULL;/* base pointer to the start of the list*/
   item_t *items_list;/*??? NULL list ??? */
   while(1)
   {
      fgetpos(fpin,&current_position);
      fseek(fpin,8,SEEK_CUR);
      if(getc(fpin)==EOF)
         break;
      else
         fsetpos(fpin,&current_position);

      if (itb==NULL)/*if we haven't done anything yet*/
         {
         itb = items_list = getItem(fpin,file,line_number);
         }

      else/*we have done stuff, lets add more */
      {
   
         items_list->next = getItem(fpin,file,line_number);/*create a new item at the end of the last one*/
         items_list = items_list->next;/*??? not sure what this does???*/
      }
      line_number++;
   }
   /*rewind(fpin);*/
   fclose(fpin);
   return(itb);/*return base pointer to the start of all items*/
}

void KillAllItems(item_t *itb)
{
   while(itb)
   {
      item_t *to_be_freed = itb;
      itb = itb->next;
      free(to_be_freed); 
   }
}

/*
 * This function prints out all items in an easy-to-read table, with an item
 * on each line, each column separated by 2 spaces, and:
 *    4 digits for item number
 *    31 characters for name
 *    7 digits for damage
 *    13 characters for cost, with 2 decimal places printed
 *    9 characters for weight, with 2 decimal places printed
 */
 
void PrintItemTable
(
   FILE *fpout,    /* FILE stream to print to (set to stdout for screen) */
   item_t *itb     /* list of items to dump to screen */
)
{
   int item_number = 1;/*assume one item for now*/
   fprintf(fpout,
   " NUM  NAME                             DAMAGE          COST    WEIGHT\n");
   fprintf(fpout,
   "====  ===============================  ======  ============  ========\n");
   while(1)
   {
      printf("%04d  ",item_number);
      if(itb->next==NULL)
      {
         fprintf(fpout, "%-31s  %-6d  %-12.2f  %-9.2f\n",itb->name,itb->
                   dam,itb->cost,itb->weight);
         break;
      }
      fprintf(fpout, "%-31s  %-6d  %-12.2f  %-9.2f\n",itb->name,itb->
                   dam,itb->cost,itb->weight);/*!!! This line needs to be correctly formated*/
                   /*{
                      printf("Problem Printing Line Number %d, exiting\n", item_number);
                      exit(2);
                   }
                   */
      itb = itb->next;
      item_number++;
      if(item_number == 9999)
      {
         printf("Max Number Of Items Reached\n");
         break;
      }
   }
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

   FILE *fpinout;
   fpinout = fopen(file,"w");
   assert(fpinout);
   while(1)
   {
      if(itb->next==NULL)
      {
         fprintf(fpinout, "'%s' %.1d %.1f %.1f\n",itb->name,itb->
                   dam,itb->cost,itb->weight);
         break;
      }
      fprintf(fpinout, "'%s' %.1d %.1f %.1f\n",itb->name,itb->
                   dam,itb->cost,itb->weight);
      itb = itb->next;
   }
   fclose(fpinout);
}

/*
 * RETURNS: number of items in list itb
 */
int CountItems(item_t *itb)/*test this*/
{
   int Counter = 1;/*for now we are going so assume there is always atleast one item*/
   while(itb->next!= '\0')
   {
      itb=itb->next;
      Counter++;
   }
   return(Counter);
}

/*
 * RETURNS: cumulative weight of all items in list itb
 */
float SumItemsWeight(item_t *itb)
{
   float Sum_Weight = 0;
   
   while(itb->next!='\0')
   {
      Sum_Weight+=itb->weight;
      itb = itb->next;
   }
   Sum_Weight+=itb->weight;/*to get weight of last item, also if there is only 1 item*/
   return(Sum_Weight);
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
