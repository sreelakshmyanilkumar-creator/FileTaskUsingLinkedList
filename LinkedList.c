//************************* File Task Using Linked List ************************
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

//****************************** Local Functions *******************************

//******************************.InitializeLinkedList.**************************
//Purpose : To initialize the linked list
//Inputs  : None
//Outputs : Update Linked List head with NULL
//Return  : Pointer of Linked List head
//Notes   : None
//*
bool InitializeLinkedList(FILE_LINKED_LIST **pstFileHead)
{
    bool blRet = false;

    if(pstFileHead == NULL)
    {
        *pstFileHead = NULL;
        blRet = true;
    }

    return blRet;
}

//******************************.LinkedListCreate.******************************
//Purpose : To create a Linked list
//Inputs  : pstReadData - Data to be added to each node
//Outputs : pstLinkdListHead - Data add to new node 
//Return  : Boolean value - for both input success return will be true else 
//Notes   : None
//*
bool LinkedListCreate(FILE_LINKED_LIST **pstLinkdListHead, 
    FILE_DATA *pstReadData)
{
    bool blRet = false;

    if(*pstLinkdListHead == NULL && pstReadData != NULL)
    {
        while(pstReadData != NULL)
        {
            printf("%s\n", pstReadData->mpucFileName);
            printf("%d\n", pstReadData->mucFileSize);
            printf("%s\n", pstReadData->mucFileType);

            LinkedListAddNode(pstLinkdListHead, pstReadData);
            pstReadData++;
        }

        blRet = true;
    }
    else
    {
        printf("Create Linked List Fail\n");
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
bool LinkedListAddNode(FILE_LINKED_LIST **pstLinkdListHead, 
    FILE_DATA *pstReadData)
{
    bool blRet = false;
    FILE_LINKED_LIST *pstNewNode = NULL;

    if(pstReadData != NULL)
    {
        pstNewNode = (FILE_LINKED_LIST*)malloc(sizeof(FILE_LINKED_LIST));
        pstNewNode->mpstFileData = (FILE_DATA*)malloc(sizeof(FILE_DATA));

        if(pstNewNode != NULL)
        {
            strcpy(pstNewNode->mpstFileData->mpucFileName, 
                pstReadData->mpucFileName);
            pstNewNode->mpstFileData->mucFileSize = pstReadData->mucFileSize;
            strcpy(pstNewNode->mpstFileData->mucFileType, 
                pstReadData->mucFileType);
            if(*pstLinkdListHead == NULL)
            {
                printf("LL Null\n");
                pstNewNode->mpstnext = NULL;
                *pstLinkdListHead = pstNewNode;
            }
            else
            {
                printf("LL Not Null\n");
                pstNewNode->mpstnext = *pstLinkdListHead;
                *pstLinkdListHead = pstNewNode;
            }

            blRet = true;
        }
    }

    return blRet;
}

//******************************.LinkedListPrint.*******************************
//Purpose : To print linked list
//Inputs  : pstLinkdListHead - Head of the linked list
//Outputs : None 
//Return  : Boolean value - for both input success return will be true else 
//Notes   : None
//*
bool LinkedListPrint(FILE_LINKED_LIST *pstLinkdListHead)
{
    bool blRet = false;
    FILE_LINKED_LIST *pstTempNode = NULL;
    pstTempNode = pstLinkdListHead;

    if(pstLinkdListHead != NULL)
    {
        printf("%-20s %-10s %-10s\n", "FileName", "FileSize", "FileType");

        while(pstTempNode != NULL)
        {
            printf("%-20s %-10d %-10s\n",
            pstTempNode->mpstFileData->mpucFileName,
            pstTempNode->mpstFileData->mucFileSize,
            pstTempNode->mpstFileData->mucFileType);

            pstTempNode = pstTempNode->mpstnext;
        }

        blRet = true;
    }

    return blRet;
}










//******************************.AddNewNodeLL.**********************************
//Purpose : To create new node in linked list.
//Inputs  : pstDirData      - library pointer to structure to get file data
//          pReadFileHead   - Linked list head 
//Outputs : New node is created
//Return  : None
//Notes   : None
//*
#if 0
void AddNewNodeLL(struct dirent *pstDirData, FILE_LINKED_LIST **pReadFileHead, 
    uint8_t *pucReadFileName)
{
    struct stat st;
    uint8_t ucfullpath[FULL_PATH_SIZE] = {0};

    snprintf((char*)ucfullpath, sizeof(ucfullpath), "%s/%s", pucReadFileName, 
    pstDirData->d_name);
    stat(ucfullpath, &st);

    FILE_LINKED_LIST *pstNewNode = 
    (FILE_LINKED_LIST*)malloc(sizeof(FILE_LINKED_LIST));

    pstNewNode->mpstFileData = (FILE_DATA*)malloc(sizeof(FILE_DATA));

    ReadFileType(pstDirData, pstNewNode->mpstFileData->mucFileType);

    strcpy(pstNewNode->mpstFileData->mpucFileName, pstDirData->d_name);
    pstNewNode->mpstFileData->mucFileSize  = st.st_size;
    //strcpy(pstNewNode->mpstFileData->mucFileType, (char*)pucFileType);

    if(*pReadFileHead == NULL)
    {
        pstNewNode->mpstnext = NULL;
        *pReadFileHead = pstNewNode;
    }
    else
    {
        pstNewNode->mpstnext = *pReadFileHead;
        *pReadFileHead = pstNewNode;
    }

    return;
}

//******************************.PrintLinkedList.*******************************
//Purpose : To print linked list.
//Inputs  : pReadFileHead   - Linked list head 
//Outputs : Linked list printed
//Return  : None
//Notes   : None
//*
bool PrintLinkedList(FILE_LINKED_LIST *pReadFileHead)
{
    bool blRet = false;

    if(pReadFileHead != NULL)
    {
        FILE_LINKED_LIST *pstTempNode = pReadFileHead;

        while(pstTempNode != NULL)
        {
            printf("%-20s %-10d %-10s\n",
            pstTempNode->mpstFileData->mpucFileName,
            pstTempNode->mpstFileData->mucFileSize,
            pstTempNode->mpstFileData->mucFileType);

            pstTempNode = pstTempNode->mpstnext;
        }
        printf("NULL\n");
        blRet = true;
    }

    return blRet;
}
#endif