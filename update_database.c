#include "head.h"

int update_database(mnode **arr,char filedatabase[])
{
    /*Open the input file for reading*/
    FILE *file = fopen(filedatabase, "r");

    /*Create a character array to store lines from the file*/
    char str[100];

    /* Pointer to tokenize the data*/
    char *data;

    int index, filecount, wordcount;

    /*Read lines from the file*/
    while( fscanf(file,"%s",str) > 0 )
    {
	/*Tokenize the data using '#' and ';' as delimiters*/
	data = strtok(str,"#;");

	/*Convert the index to an integer*/
	index = atoi(data);

	/* Create a new main node*/
	mnode *main = malloc(sizeof(mnode));

	/*Initialize main node's link*/
	main -> mlink = NULL;

	/*Initialize sub-node link*/
	main -> smlink = NULL;

	if(arr[index] == NULL)
	{
	    arr[index] = main;
	}
	else
	{
	    mnode *temp = arr[index];

	    while(temp -> mlink != NULL)
	    {
		/*Traverse to the last main node*/
		temp = temp -> mlink;
	    }
	    /*Link the new main node*/
	    temp -> mlink = main;
	}
	/*Move to the next token*/
	data = strtok(NULL, "#;");

	/*Copy the word data*/
	strcpy(main -> word,data);

	/*Move to the next token*/
	data = strtok(NULL, "#;");

	/*Convert file count to an integer*/
	filecount = atoi(data);

	/* Set the file count for the main node*/
	main -> fcount = filecount;

	for(int i = 0; i < filecount; i++)
	{
	    /*Move to the next token*/
	    data = strtok(NULL, "#;");

	    /*Create a new sub-node*/
	    snode *sub = malloc(sizeof(snode));

	    /*Copy the filename data*/
	    strcpy(sub -> fname, data);

	    /*Move to the next token*/
	    data = strtok(NULL, "#;");

	    /*Convert word count to an integer*/
	    wordcount = atoi(data);

	    /*Set the word count for the sub-node*/
	    sub -> wcount = wordcount;

	    /*Initialize sub-node's link*/
	    sub -> sslink = NULL;

	    if(main -> smlink == NULL)
	    {
		/*Set the main node's sub-node link*/
		main -> smlink = sub;
	    }
	    else
	    {
		snode *temp1 = (snode *)main -> smlink;

		while(temp1 -> sslink != NULL)
		{
		    /*Traverse to the last sub-node*/
		    temp1 = temp1 -> sslink;
		}
		/* Link the new sub-node*/
		temp1 -> sslink = (snode *)sub;
	    }
	}

    }

}

