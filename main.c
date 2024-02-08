
#include "main.h" 
#include "head.h"
#include "types.h"
/*
Name: Revanth 
Date: 05/11/2023
Title: Inverted Search
*/

int main(int argc, char *argv[])
{
    File_n *head = NULL; // Declare a pointer to the head of the file database

    int check_create_database = 0;  // Declare a flag to check if the database has been created
    int check_save_database = 0;  // Declare a flag to check if the database has been saved 
    int check_update_database = 0;   // Declare a flag to check if the database has been updated
    
    /*check whether the sufficient arguments are passed or not*/
    if(argc > 1)
    {
	/*call the read and validate function and check whether it is success or not*/
	if(read_and_validate(argv, &head) == SUCCESS)
	{
	    printf("INFO : Read and Validate is Success\n");

	    /*create an array index*/
	    mnode *arr[27];

	    /*place NULL in all the index*/
	    for(int i = 0; i < 27; i++)
	    {
		arr[i] = NULL;
	    }


	    /*print the Menu*/
	    char menu = 'y';
	    while(menu == 'y' || menu == 'Y')
	    {
		printf("Select your choice:\n1.Create Database\n2.Display Database\n3.Search\n4.Save\n5.Update\nEnter your choice: ");

		int choice;
		scanf(" %d",&choice);
                
		/*For selecting menu option*/
		switch(choice)
		{
		    case 1:
			if(check_create_database == 0)
			{
			    printf("INFO : Selected create database\n");
			    
			    if(create_database(&head, arr) == SUCCESS)
		 	    {
				/*If the create_database function is successful, set the check_create_database flag to 1 and print a message*/
				check_update_database = 1;
				check_save_database = 1;
				check_create_database=1;
			        printf("INFO : Data base created successfully\n");
			    }
			    else
			    {
			        printf("ERROR : Data base not created\n");
			    }
			}
			else
			{
                            printf("INFO:A previous update of the database was performed, so creating a new database is not allowed\n");
			}
			
			break;

		    case 2: 
			printf("INFO : Seclected Display database\n");
			if(display_database(arr) == SUCCESS)
			{
			    printf("INFO : Display Database is success\n");
			}
			else
			{
			    printf("INFO : Display Database is failure\n");
			}
			break;

		    case 3:
			printf("INFO : Selected search database\n");
			printf("Enter a word to search in data base : ");
			char sword[30];
			scanf(" %s",sword);
			if(search_database(arr,sword) == SUCCESS)
			{
			}
			else
			{
			    printf("DATA NOT FOUND, Enter valid data\n");
			    
			}
			break;

		    case 4:
			if(check_save_database == 1)
			{

			    printf("INFO : Selected save database\n");
			    printf("Enter the file name to save database: \n");
			    char filename[50];
			    scanf(" %s",filename);

			    char* file_extn = strrchr(filename, '.');
			   
			    if (file_extn != NULL && strcmp(file_extn, ".txt") == 0)
			    {
				FILE *file = fopen(filename,"w");
				if(file == NULL)
				{
				    printf("ERROR : Please pass the valid filename\n");
				}
				else
				{
				    if(save_database(arr,filename) == SUCCESS)
			            {
					printf("INFO : Save database is success\n");
				    }
				}
			    }
			    
			    else
			    {
			        printf("Error : Please pass the filename with .txt extension\n");
	
			    }
			    break;
			}
			else
			{
			    printf("ERROR : Create database is failure\n");
			}
			break;

		    case 5:
			if(check_update_database == 0)
			{
			    check_update_database = 1;
			    
			    check_create_database=1;
			    
			    char filedatabase[40];

			    char store[40];

			    printf("Enter the file name: ");
			    scanf(" %s",filedatabase);

			    FILE *file = fopen(filedatabase, "r");

			    if(file == NULL)
			    {
				printf("ERROR : Enter the correct file name\n");
				break;
			    }
			    else
			    {
				char ch1, ch2;

				fscanf(file, "%c", &ch1);

				fseek(file, 0, SEEK_END);

				fscanf(file, "%c", &ch2);

				if(ch1 != '#' && ch2 != '#')
				{
				    printf("ERROR : Enter file is not backup file\n");
				    break;
				}
			    }
			    if(update_database(arr,filedatabase) == SUCCESS)
			    {
				printf("INFO : Update database is success\n");
			    }
			}
			else
			{
			    printf("ERROR : A Previous creation of the database was done, so updating the database is not allowed.\n");
			}

			break;


		}
		printf("Do you want to continue? \nEnter y/Y to continue: ");
		scanf(" %c",&menu);


	    }

	}
	else
	{
	    printf("Error : Read and Validate Failure, Please pass correct file names\n");
	    return FAILURE;
	}

    }
    else
    {
	printf("Error : Read and validate Failure, Please pass the file names\n");
	return FAILURE;
    }

}

