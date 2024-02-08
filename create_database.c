#include "head.h"
#include "types.h"
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int create_database(File_n **head, mnode **arr)
{
    /*create a temporary pointer and initiliaze with the head of the filename list*/
    File_n *temp = *head;

    /*Traverse temp reaches null*/
    while(temp != NULL)
    {
	
	char word[40];
	
	/*Create a file and opens in read mode*/
	FILE *file = fopen(temp -> fname, "r");

	/*checking the file is null or not*/
	if(file == NULL)
	{
	    continue;
	}


	/* Read words from the file*/
	while( fscanf(file,"%s",word) == 1 )
	{


	    char ch = word[0];

	     /*Convert the first character to lowercase and calculate the index*/
	    int index = tolower(ch) - 'a';

	    mnode *main = arr[index];

	    /*Iterate through the main nodes*/
	    while(main != NULL)
	    {
		/*check If the word matches*/
		if( strcmp(main -> word, word) == 0 )
		{
		    /*Get the sub-node linked list*/
		    snode *sub = (snode *) main -> smlink;

		    snode *prev = NULL;

		    /*Iterate through sub-nodes*/
		    while(sub != NULL)
		    {
			/*check If the filename match*/
			if(strcmp(sub -> fname, temp -> fname) == 0)
			{
			    /*Increment word count for the file*/
			    sub -> wcount++;

			    break;
			}
			prev = sub;

			/*Move to the next sub-node*/
			sub = (snode *)sub -> sslink;
		    }
		    
		    /* If sub-node doesn't exist, create a new one*/
		    if(sub == NULL)
		    {
			/*Allocate memory for a new sub-node*/
			snode *newsub = malloc(sizeof(snode));

			/*Initialize word count*/
			newsub -> wcount = 1;

		        /*Increment file count for the word*/
			main -> fcount++;

			/*Copy the filename*/
			strcpy(newsub -> fname, temp -> fname);

			/*Set the next sub-node link to NULL*/
			newsub -> sslink = NULL;

			/*If there's a previous sub-node*/
			if(prev != NULL)
			{
			    /*previous sub-node, link the new one*/
			    prev -> sslink = newsub;
			}
		    }
		    
		    break;
		}
		
	    	/*Move to the next main node*/
		main = main -> mlink;
	    }
	    
	    if(main == NULL)
	    {
		/*Allocate memory for a new main node*/
		mnode *newmain = malloc(sizeof(mnode));

		/*Set the next main node link to the current list*/
		newmain -> mlink = arr[index];

		/*Update the list to point to the new main node*/
		arr[index] = newmain;

		/*Set the sub-node link to NULL*/
		newmain -> smlink = NULL;

		/*Initialize file count*/
		newmain -> fcount = 1;

		/*Copy the word*/
		strcpy(newmain -> word, word);

		/*Allocate memory for a new sub-node*/
		snode *smain = malloc(sizeof(snode));

		/*Initialize word count for the sub-node*/
		smain -> wcount = 1;

		/* Copy the filename*/
		strcpy(smain ->  fname, temp -> fname);

		/*Set the next sub-node link to NULL*/
		smain -> sslink = NULL;

		/*Link the new sub-node to the main node*/
		newmain -> smlink = smain;
	    }
	}

        /*Close the file*/
	fclose(file);

	/*Move to the next filename in the list*/
	temp = temp -> link;
    }

    return SUCCESS;

}
















	
