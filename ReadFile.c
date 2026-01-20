//************************* File Task Using Linked List ************************
//  Copyright (c) 2026 Trenser Technology Solutions 
//  All Rights Reserved 
//******************************************************************************
//
// File     : ReadFile.c
// Summary  : List all the files in the given directory using Linked List
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
#include "Common.h"
#include "LlCreation.h"

//******************************* Local Types **********************************

//***************************** Local Constants ********************************

//***************************** Local Variables ********************************

//****************************** Local Functions *******************************

//******************************.ReadFileData.**********************************
//Purpose : To read file data and save to linked list.
//Inputs  : pucReadFileName - Character Pointer to give the name of the 
//          directory
//          psReadFileHead - Structure pointer to give the head of the 
//          linked list
//Outputs : pReadFileHead - Updated file data in the structure pointer
//Return  : Boolean value - for both input success return will be true else 
//          false
//Notes   : None
//*
bool ReadFileData(const uint8_t *pucReadFileName, 
    FILE_LINKED_LIST *pReadFileHead)
{
    bool blRet = false;
    struct dirent *pstDirData;
    DIR *DirData = opendir(pucReadFileName);
 
    if(DirData != NULL)
    {
        while ((pstDirData = readdir(DirData)) != NULL)
        {
            //printf("%s\n", pstDirData->d_name);
            AddNewNodeLL(pstDirData, &pReadFileHead);
        }
        if(PrintLinkedList(pReadFileHead) != false)
        {
            blRet = true;
        }
    }

    return blRet;
}