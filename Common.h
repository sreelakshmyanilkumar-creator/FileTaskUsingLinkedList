//************************* File Task Using Linked List ************************
//  Copyright (c) 2026 Trenser Technology Solutions 
//  All Rights Reserved 
//******************************************************************************
//
// File     : Common.h
// Summary  : List all the files in the given directory using Linked List
// Note     : None
// Author   : Sreelakshmy M.A.
// Date     : 20/01/2026
//
//******************************************************************************

#ifndef _COMMON_H_ 
#define _COMMON_H_

//******************************* Include Files ********************************
#include <stdio.h>

//******************************* Global Types *********************************
typedef struct _FILE_DATA_
{
    uint8_t mpucFileName[256];
    uint8_t mucFileType;
    uint16_t mucFileSize;
}FILE_DATA;

typedef struct _FILE_LINKED_LIST_
{
    FILE_DATA mpstFileData;
    struct _FILE_LINKED_LIST_ *mpstnext;
}FILE_LINKED_LIST;

//***************************** Global Constants *******************************

//***************************** Global Variables *******************************

//**************************** Forward Declarations ****************************
#endif //_COMMON_H_
//EOF