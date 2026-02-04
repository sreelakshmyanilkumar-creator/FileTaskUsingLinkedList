//************************* File Data Lister ***********************************
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
#define FULL_PATH_SIZE  (1024)

//***************************** Global Variables *******************************
extern FILE_LINKED_LIST *pstLinkdListHead;

//**************************** Forward Declarations ****************************
bool InitializeLinkedList();
bool LinkedListAddNode(FILE_DATA *pstReadData);
bool LinkedListPrint();
#endif //_LL_CREATION_H_
//EOF