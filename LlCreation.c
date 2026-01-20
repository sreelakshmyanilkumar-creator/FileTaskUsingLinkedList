//************************* File Task Using Linked List ************************
//  Copyright (c) 2026 Trenser Technology Solutions 
//  All Rights Reserved 
//******************************************************************************
//
// File     : LlCreation.c
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
#include "Common.h"
#include "LlCreation.h"

//******************************* Local Types **********************************

//***************************** Local Constants ********************************

//***************************** Local Variables ********************************

//****************************** Local Functions *******************************

//******************************.AddNewNodeLL.**********************************
//Purpose : To create new node in linked list.
//Inputs  : pstDirData      - library pointer to structure to get file data
//          pReadFileHead   - Linked list head 
//Outputs : New node is created
//Return  : None
//Notes   : None
//*
void AddNewNodeLL(struct dirent *pstDirData, FILE_LINKED_LIST **pReadFileHead)
{
    FILE_LINKED_LIST *pstNewNode = 
    (FILE_LINKED_LIST*)malloc(sizeof(FILE_LINKED_LIST));

    pstNewNode->mpstFileData = (FILE_DATA*)malloc(sizeof(FILE_DATA));

    strcpy(pstNewNode->mpstFileData->mpucFileName, pstDirData->d_name);
    pstNewNode->mpstFileData->mucFileSize  = pstDirData->d_reclen;
    pstNewNode->mpstFileData->mucFileType  = pstDirData->d_type;

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

//******************************.PrintLinkedList.**********************************
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
            printf("%s,", pstTempNode->mpstFileData->mpucFileName);
            printf("%d,", pstTempNode->mpstFileData->mucFileSize);
            printf("%d->", pstTempNode->mpstFileData->mucFileType);

            pstTempNode = pstTempNode->mpstnext;
        }
        printf("NULL\n");
        blRet = true;
    }

    return blRet;
}
