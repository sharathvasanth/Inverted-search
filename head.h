#ifndef HEAD_H
#define HEAD_H

#include "types.h"
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a linked list of filenames
typedef struct filename
{
    char *fname;
    struct filename *link;
}File_n;

// Define a structure for a sub-node in the database
typedef struct sub_node
{
    int wcount;
    char fname[20];
    struct sub_node *sslink;
}snode;

// Define a structure for a main-node in the database
typedef struct main_node
{
    char word[30];
    int fcount;
    struct main_node *mlink;
    struct sub_node *smlink;
}mnode;



// Function declarations for various database operations
int read_and_validate(char *argv[],File_n **head);
int create_database(File_n **head,mnode **arr);
int display_database(mnode **arr);
int search_database(mnode **arr, char *sword);
int save_database(mnode **arr,char filename[]);
int update_database(mnode **arr, char filedatabase[]);







#endif

