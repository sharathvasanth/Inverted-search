#include "head.h"
#include "types.h"

// Function to read and validate input files
int read_and_validate(char *argv[],File_n **head)
{

    /*Loop through the arguments*/
    for(int i = 1; argv[i] != NULL; i++)
    {
	/*Create new node for the filename*/
	File_n *fname = (File_n *)malloc(sizeof(File_n));

	/*update the new node of data part with argv*/
	fname -> fname = argv[i];

	/*update the new node of link part with null*/
	fname -> link = NULL;

	// Open the file for reading
	FILE *file = fopen(argv[i],"r");

	// Check if the file does not exist
	if(file == NULL)
	{
	    continue;
	}

	char ch;
	int word = 0;

	// Check if the file is not empty
	if( (ch == fgetc(file) != EOF))
	{
	    word++;
	}

	// Check if the file is empty
	if(word == 0)
	{
	    printf("INFO : %s file is empty\n",argv[i]);
	    continue;
	}


	/*check list is empty or not*/
	if(*head == NULL)
	{
	    /*set head to the new node*/
	    *head = fname;
	}
	else
	{
	    /*create a temporary pointer and update with head*/
	    File_n *temp = *head;

	    /*Traverse till the last node*/
	    while(temp -> link != NULL)
	    {
		/*update temp with temp of link*/
		temp = temp -> link;
	    }

	    /*update temp of link with new node*/
	    temp -> link = fname;
	}
    }

    // Remove duplicate files from the list
    File_n *temp1 = *head;

    while(temp1 != NULL)
    {
	File_n *temp2 = temp1;
	while(temp2 -> link != NULL)
	{
	    if(strcmp(temp1 -> fname, temp2 -> link -> fname) == 0)
	    {
		/*Remove duplicates files from the list*/
		File_n *temp3 = temp2 -> link;
		temp2 -> link = temp2 -> link -> link;
		free(temp3);

		printf("Error : Dupilcate file of %s is found and duplicate file is removed in list successfully\n", temp1 -> fname);
	    }
	    else
	    {
		temp2 = temp2 -> link;
	    }
	}
	temp1 = temp1 -> link;
    }	

    // Check if the list is empty
    if(*head == NULL)
    {
	printf("Error : List is empty\n");
	return FAILURE;
    }
    else
    {
	// Print the filenames in the list
	File_n *temp4 = *head;

	while(temp4)
	{
	    printf("%s -> ",temp4 -> fname);

	    temp4 = temp4 -> link;
	}

	printf("NULL\n");

    }
    return SUCCESS;

}



        
        	


