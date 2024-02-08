#include "head.h"

int save_database(mnode **arr, char filename[])
{
    /*Open the specified file in write mode*/
    FILE *file = fopen(filename, "w");

    /*Iterate through the 26 main nodes*/
    for(int i = 0; i < 26; i++)
    {
	/*Get the current main node from the array*/
	mnode *main = arr[i];

	/*Iterate through the main nodes linked list
        {*/
	while(main != NULL)
	{
	    /*Write main node data to the file*/
	    fprintf(file, "#%d;%s;%d;",i,main -> word, main -> fcount);

	    /*Get the sub-node linked list*/
	    snode *sub = (snode *)main -> smlink;

	    /* Iterate through the sub-nodes linked list*/
	    while(sub != NULL)
	    {
		/*Write sub-node data to the file*/
		fprintf(file, "%s;%d;",sub ->fname, sub -> wcount);

		/*Move to the next sub-node*/
		sub = (snode *)sub -> sslink;

	    }
	    /*Write the end of main node data to the file*/
	    fprintf(file,"#\n");

	    /*Move to the next main node*/
	    main = (mnode *)main -> mlink;
	}
    }
    /*Close the file*/
    fclose(file);
    return SUCCESS;
}

