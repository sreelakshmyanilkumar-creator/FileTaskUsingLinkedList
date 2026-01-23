//************************* File Data Lister ***********************************
//  Copyright (c) 2026 Trenser Technology Solutions 
//  All Rights Reserved 
//******************************************************************************
//
// File     : LinkedList.c
// Summary  : To Create Nodes in LL
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
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include "LinkedList.h"

//******************************* Local Types **********************************

//***************************** Local Constants ********************************

//***************************** Local Variables ********************************
FILE_LINKED_LIST *pstLinkdListHead = NULL;

//****************************** Local Functions *******************************

//******************************.InitializeLinkedList.**************************
//Purpose : To initialize the linked list
//Inputs  : None
//Outputs : Update Linked List head with NULL
//Return  : Pointer of Linked List head
//Notes   : None
//*
bool InitializeLinkedList()
{
    bool blRet = false;
    if(pstLinkdListHead == NULL)
    {
        blRet = true;
    }
    
    return blRet;
}

//******************************.LinkedListAddNode.*****************************
//Purpose : To create new node in the beginning of the linked list
//Inputs  : pstReadData - Data to be added to each node
//Outputs : pstLinkdListHead - Data add to new node 
//Return  : Boolean value - for both input success return will be true else 
//Notes   : None
//*
bool LinkedListAddNode(FILE_DATA *pstReadData)
{
    bool blRet = false;
    FILE_LINKED_LIST *pstNewNode = NULL;

    if(pstReadData != NULL)
    {
        pstNewNode = (FILE_LINKED_LIST*)malloc(sizeof(FILE_LINKED_LIST));
    
        if(pstNewNode != NULL)
        {
            pstNewNode->mpstFileData = (FILE_DATA*)malloc(sizeof(FILE_DATA));

            if(pstNewNode->mpstFileData != NULL)
            {
                strncpy(pstNewNode->mpstFileData->mpucFileName, 
                pstReadData->mpucFileName, 
                sizeof(pstNewNode->mpstFileData->mpucFileName) - 1);
                pstNewNode->mpstFileData->mucFileSize = 
                pstReadData->mucFileSize;
                strncpy(pstNewNode->mpstFileData->mucFileType, 
                pstReadData->mucFileType, 
                sizeof(pstNewNode->mpstFileData->mucFileType) - 1);

                pstNewNode->mpstnext = pstLinkdListHead;
                pstLinkdListHead = pstNewNode;
            }

            blRet = true;
        }
    }

    return blRet;
}

//******************************.LinkedListPrint.*******************************
//Purpose : To print linked list
//Inputs  : None
//Outputs : None 
//Return  : Boolean value - for both input success return will be true else 
//Notes   : None
//*
bool LinkedListPrint()
{
    bool blRet = false;
    FILE_LINKED_LIST *pstTempNode = NULL;
    pstTempNode = pstLinkdListHead;
    
    printf("%-20s %-10s %-10s\n", "FileName", "FileSize", "FileType");
    
    while(pstTempNode != NULL)
    {
        printf("%-20s %-10d %-10s\n",
        pstTempNode->mpstFileData->mpucFileName,
        pstTempNode->mpstFileData->mucFileSize,
        pstTempNode->mpstFileData->mucFileType);

        pstTempNode = pstTempNode->mpstnext;
        blRet = true;
    }
    
    return blRet;
}