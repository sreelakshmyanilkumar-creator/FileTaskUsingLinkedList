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
#include <sys/stat.h>
#include "Common.h"
#include "LlCreation.h"

//******************************* Local Types **********************************

//***************************** Local Constants ********************************

//***************************** Local Variables ********************************

//****************************** Local Functions *******************************

//******************************.ReadFileType.**********************************
//Purpose : To create new node in linked list.
//Inputs  : pstDirData  - library pointer to structure to get file data
//          FileType    - file type name/ extension
//Outputs : Read file type from file name in a pointer 
//Return  : None
//Notes   : None
//*
void ReadFileType(struct dirent *pstDirData, uint8_t *FileType)
{
    const uint8_t *pucCheckDot = strrchr(pstDirData->d_name, '.');

    if (!pucCheckDot || pucCheckDot == pstDirData->d_name)
    {
        strcpy((char*)FileType, "No");
    }
    strcpy((char*)FileType, pucCheckDot+1);

    return;
}
//******************************.AddNewNodeLL.**********************************
//Purpose : To create new node in linked list.
//Inputs  : pstDirData      - library pointer to structure to get file data
//          pReadFileHead   - Linked list head 
//Outputs : New node is created
//Return  : None
//Notes   : None
//*
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
