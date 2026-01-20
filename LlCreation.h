//************************* File Task Using Linked List ************************
//  Copyright (c) 2026 Trenser Technology Solutions 
//  All Rights Reserved 
//******************************************************************************
//
// File     : LlCreation.h
// Summary  : To Create Nodes in LL
// Note     : None
// Author   : Sreelakshmy M.A.
// Date     : 20/01/2026
//
//******************************************************************************

#ifndef _LL_CREATION_H_ 
#define _LL_CREATION_H_

//******************************* Include Files ********************************
#include <stdio.h>
#include <dirent.h>
#include "Common.h"

//******************************* Global Types *********************************

//***************************** Global Constants *******************************
#define FULL_PATH_SIZE 1024

//***************************** Global Variables *******************************

//**************************** Forward Declarations ****************************
void AddNewNodeLL(struct dirent *pstDirData, FILE_LINKED_LIST **pReadFileHead, 
    uint8_t *pucReadFileName);
bool PrintLinkedList(FILE_LINKED_LIST *pReadFileHead);
void ReadFileType(struct dirent *pstDirData, uint8_t *FileType);
#endif //_LL_CREATION_H_
//EOF