//************************* File Task Using Linked List ************************
//  Copyright (c) 2026 Trenser Technology Solutions 
//  All Rights Reserved 
//******************************************************************************
//
// File     : LinkedList.h
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
#include "ReadFile.h"

//******************************* Global Types *********************************

//***************************** Global Constants *******************************
#define FULL_PATH_SIZE 1024

//***************************** Global Variables *******************************

//**************************** Forward Declarations ****************************
bool InitializeLinkedList(FILE_LINKED_LIST **pstFileHead);
bool LinkedListAddNode(FILE_LINKED_LIST **pstLinkdListHead, 
    FILE_DATA *pstReadData);
bool LinkedListPrint(FILE_LINKED_LIST *pstLinkdListHead);
bool LinkedListCreate(FILE_LINKED_LIST **pstLinkdListHead, 
    FILE_DATA *pstReadData);
#endif //_LL_CREATION_H_
//EOF