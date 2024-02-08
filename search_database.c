#include "head.h"

int search_database(mnode **arr, char *sword)
{
    /*Calculate the index based on the first character of the search word*/
    int index = tolower(sword[0]) - 'a';

    /*Get the main node at the calculated index*/
    mnode *search = arr[index];

    /*Check if the main node is NULL*/
    if(search == NULL)
    {
	return FAILURE;      //Return Word not found in the database
    }
    else
    {
	/*Iterate through the main nodes*/
	while(search != NULL)
	{
	    /* Check if the main node's word matches the search word*/
	    if(strcmp(search -> word, sword) == 0)
	    {
		/*Get the sub-node linked list*/
		snode *sub_list = (snode *)search -> smlink;
		
		/*Get the sub-node linked list*/
		printf("The word \"%s\" is present in \"%d\" Files\n", sword, search -> fcount);

		/*Iterate through the sub-nodes*/
		while(sub_list != NULL)
		{
		    /*Print the filename*/
		    printf("%s->", sub_list -> fname);

		    /*Print the word count in the filename*/
		    printf("%d\n",sub_list -> wcount);

		    /*Move to the next sub-node*/
		    sub_list = sub_list -> sslink;

		}
		return SUCCESS;      // Word found in the database
	    }
	    search = search -> mlink;

	}
    }
    return FAILURE;                 // Word not found in the database


}
