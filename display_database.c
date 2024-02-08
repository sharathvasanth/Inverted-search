#include "head.h"


int display_database(mnode **arr)
{
    printf("%-15s%-15s%-15s%-15s%-15s\n", "[Index]", "[Word]", "[Filecount]", "[Filename]", "[Wordcount]");
   
   /*Iterate through the 26 indices (a to z)*/ 
    for(int i = 0; i < 26; i++)
    {
	/*Get the main node at the current index*/
	mnode *main = arr[i];

	/*Iterate through the main nodes*/
	while(main != NULL)
	{
            /*Print index, word, and file count*/    
            printf("%-15d%-15s%-15d", i, main -> word, main -> fcount);

	    /* Get the sub-node linked list*/
	    snode *sub = (snode *)main -> smlink;

	    /*Iterate through the sub-nodes*/
	    while(sub != NULL)
	    {
		/*Print filename and word count*/
		printf("%-15s%-15d", sub -> fname, sub -> wcount);

		/* Move to the next sub-node*/
		sub = (snode *)sub -> sslink;
	    }
	    /*Newline to separate entries*/
	    printf("\n");

	    /*Move to the next main node*/
            main = (mnode *)main -> mlink;
	}
	

    }
    return SUCCESS;

}




		








