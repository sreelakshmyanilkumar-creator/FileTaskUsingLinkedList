//************************* File Task Using Linked List ************************
//  Copyright (c) 2026 Trenser Technology Solutions 
//  All Rights Reserved 
//******************************************************************************
//
// File     : main.c
// Summary  : List all the files in the given directory of the system
//            using Linked List
// Note     : None
// Author   : Sreelakshmy M.A.
// Date     : 20/01/2026
//
//******************************************************************************

//******************************* Include Files ********************************
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <stdbool.h>
#include "LinkedList.h"
#include "ReadFile.h"

//******************************* Local Types **********************************

//******************************* Local Constants ******************************
#define MAIN_ARGC   (2)

//******************************* Local Variables ******************************

//******************************* Local Functions ******************************
bool CmdLineArgCheck(uint8_t ucargc, uint8_t **pucargv);

//********************************.main.****************************************
//Purpose : main function.
//Inputs  : Directory in the PC from which we need to read files as CLA
//Outputs : None
//Return  : Interger value - Upon success return will be 0 else any non zero
//Notes   : None
//*
int main(int argc, char *argv[])
{
    int lRet = false;
    FILE_DATA pstReadData;
    FILE_LINKED_LIST *pstLinkdListHead = NULL;

    if(CmdLineArgCheck(argc, (uint8_t**)argv))
    {
        InitializeLinkedList(&pstLinkdListHead);

       if(pstLinkdListHead == NULL)
        {
            printf("Linked List Initialized Successfully\n");

            if(ReadFilesAndBuildList(argv[1], &pstLinkdListHead))
            {
                printf("Data Read successfull\n");

                if(LinkedListPrint(pstLinkdListHead))
                {
                    lRet = true;
                }
            }
        }
    }

    return lRet;
}

//********************************.CmdLineArgCheck.*****************************
//Purpose : To check argument number from cmd line.
//Inputs  : largc - argc value from main function
//Outputs : None
//Return  : boolean value - Upon success return will true else false
//Notes   : None
//*
bool CmdLineArgCheck(uint8_t ucargc, uint8_t **pucargv)
{
    bool blRet = false;

    if(pucargv != NULL)
    {
        if(ucargc < MAIN_ARGC)
        {
            printf("Invalid Command Line Argument\n");
            printf("Use: %s <Directory path> \n", 
                (char*)pucargv[0]);
        }
        else
        {
            printf("The string passed is: %s\n", (char*)pucargv[1]);
            blRet = true;
        }
    }

    return blRet;
}