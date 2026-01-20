//************************* File Task Using Linked List ************************
//  Copyright (c) 2026 Trenser Technology Solutions 
//  All Rights Reserved 
//******************************************************************************
//
// File     : LinkedList.c
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
#include "Common.h"

//******************************* Local Types **********************************

//***************************** Local Constants ********************************

//***************************** Local Variables ********************************

//****************************** Local Functions *******************************

//******************************.main.******************************************
//Purpose : main function.
//Inputs  : None
//Outputs : None
//Return  : Interger value - Upon success return will be 0 else any non zero
//Notes   : None
//*
int main(int argc, char *argv[])
{
    bool blRet = false;
    FILE_LINKED_LIST *pstFileHead = NULL;

    if (argc < 2) 
    {
        printf("Usage: %s /home/sree/LL_Test \n", argv[0]);
    }
    else
    {
            printf("The string passed is: %s\n", argv[1]);
            
            if(ReadFileData(argv[1], &pstFileHead) != false)
            {
                blRet = true;
            }
    }

    return blRet;
}