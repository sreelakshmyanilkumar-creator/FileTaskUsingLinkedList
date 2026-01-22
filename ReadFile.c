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
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include "LinkedList.h"

//******************************* Local Types **********************************

//***************************** Local Constants ********************************

//***************************** Local Variables ********************************

//****************************** Local Functions *******************************

//******************************.ReadFileSize.**********************************
//Purpose : To read file size and save to a structure variable.
//Inputs  : pucReadFileName - Character Pointer to give the name of the 
//          directory
//          pstDirData - Pointer to dirent struct
//Outputs : stStatFileData - updated with new file size
//Return  : Boolean value - return true if success else false
//Notes   : None
//*
bool ReadFileSize(struct stat *pstStatFileData, struct dirent *pstDirData,
            uint8_t *pucReadFileName)
{
    bool blRet = false;
    uint8_t ucFullPath[FULL_PATH_SIZE] = {0};

    if(pstDirData != NULL && pucReadFileName != NULL)
    {
        snprintf((char*)ucFullPath, sizeof(ucFullPath), "%s/%s", 
        pucReadFileName, pstDirData->d_name);
        stat(ucFullPath, pstStatFileData);
        blRet = true;
    }
    else
    {
        printf("ReadFileSize fail\n");
    }

    return blRet;
}

//******************************.ReadFileType.**********************************
//Purpose : To read file type in a structure variable
//Inputs  : pstDirData - Character Pointer to give the name of the 
//          directory
//Outputs : pucFileType - FileType is updated
//Return  : Boolean value - return true if success else false
//Notes   : None
//*
bool ReadFileType(struct dirent *pstDirData, uint8_t *pucFileType)
{
    bool blRet = false;
    const uint8_t *pucCheckDot;

    if(pstDirData != NULL && pucFileType != NULL)
    {
        pucCheckDot = strrchr(pstDirData->d_name, '.');

        if (!pucCheckDot || pucCheckDot == pstDirData->d_name)
        {
            strcpy((char*)pucFileType, "No");
        }
        strcpy((char*)pucFileType, pucCheckDot+1);
        blRet = true;
    }
    else
    {
        printf("Read file type fail\n");
    }

    return blRet;
}

//******************************.ReadFileData.**********************************
//Purpose : To read file data and save to file data structure
//Inputs  : pucReadFileName - Character Pointer to give the name of the 
//          directory
//Outputs : pReadFileHead - Updated file data in the structure pointer
//          pstLinkdListHead - Add linked list node
//Return  : Boolean value - for both input success return will be true else 
//          false
//Notes   : None
//*
bool ReadFilesAndBuildList(const uint8_t *pucReadFileName, 
    FILE_DATA *pstReadData, FILE_LINKED_LIST **pstLinkdListHead)
{
    bool blRet = false;
    struct dirent *pstDirData;
    struct stat stStatFileData;
    uint8_t ucFileType[25] = {0};
    DIR *pstDirDataOprtn = NULL;

    if(pucReadFileName != NULL && pstReadData != NULL && 
        *pstLinkdListHead == NULL)
    {
        pstDirDataOprtn = opendir(pucReadFileName);

        if(pstDirDataOprtn != NULL)
        {
            pstReadData = (FILE_DATA*)malloc(sizeof(FILE_DATA));

            if(pstReadData != NULL)
            {
                while ((pstDirData = readdir(pstDirDataOprtn)) != NULL)
                {   
                    if (strcmp(pstDirData->d_name, ".") == 0 || 
                    strcmp(pstDirData->d_name, "..") == 0) 
                    { 
                        continue;
                    }

                    // Read file size and file type
                    if(ReadFileSize(&stStatFileData, pstDirData, 
                        pucReadFileName))
                    {
                        if(ReadFileType(pstDirData, ucFileType))
                        {
                            // Assign the read value to the output structure
                            strcpy(pstReadData->mpucFileName, 
                                pstDirData->d_name);
                            pstReadData->mucFileSize = stStatFileData.st_size;
                            strcpy(pstReadData->mucFileType, ucFileType);
                        }
                    }

                    // debug prints
                    printf("%s\n", pstReadData->mpucFileName);
                    printf("%d\n", pstReadData->mucFileSize);
                    printf("%s\n", pstReadData->mucFileType);

                    if(LinkedListAddNode(pstLinkdListHead, pstReadData))
                    {
                        blRet = true;
                    }
                }
            }
        }
    }
    else
    {
        printf("Read data fail\n");
    }

    return blRet;
}