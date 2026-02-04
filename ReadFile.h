//************************* File Data Lister ***********************************
//  Copyright (c) 2026 Trenser Technology Solutions 
//  All Rights Reserved 
//******************************************************************************
//
// File     : ReadFile.h
// Summary  : List all the files in the given directory using Linked List
// Note     : None
// Author   : Sreelakshmy M.A.
// Date     : 20/01/2026
//
//******************************************************************************
#ifndef _READ_FILE_H_ 
#define _READ_FILE_H_

//******************************* Include Files ********************************
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include "LinkedList.h"


//***************************** Global Variables *******************************
#define FILE_NAME_SIZE  (256)
#define FILE_TYPE_SIZE  (256)

//******************************* Global Types *********************************
typedef struct _FILE_DATA_
{
    uint8_t mpucFileName[FILE_NAME_SIZE];
    uint8_t mucFileType[FILE_TYPE_SIZE];
    uint16_t mucFileSize;
}FILE_DATA;

typedef struct _FILE_LINKED_LIST_
{
    FILE_DATA *mpstFileData;
    struct _FILE_LINKED_LIST_ *mpstnext;
}FILE_LINKED_LIST;

//***************************** Global Constants *******************************

//**************************** Forward Declarations ****************************
bool ReadFilesAndBuildList(const uint8_t *pucReadFileName);
bool ReadFileSize(struct stat *pstStatFileData, struct dirent *pstDirData,
            uint8_t *pucReadFileName);
bool ReadFileType(struct dirent *pstDirData, uint8_t *pucFileType);
#endif //_READ_FILE_H_
//EOF