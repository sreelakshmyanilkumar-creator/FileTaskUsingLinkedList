//************************* File Data Lister ***********************************
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
//Outputs : pstStatFileData - updated with new file size
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

    return blRet;
}

//******************************.ReadFileType.**********************************
//Purpose : To read file type in a structure variable.
//Inputs  : pstDirData - A dirent pointer to get the name of the file.
//Outputs : pucFileType - A character to update the type.
//Return  : Boolean value - return true if success else false.
//Notes   : None
//*
bool ReadFileType(struct dirent *pstDirData, uint8_t *pucFileType)
{
    bool blRet = false;
    uint8_t *pucCheckDot = NULL;

    if (pstDirData != NULL && pucFileType != NULL)
    {
        pucCheckDot = strrchr(pstDirData->d_name, '.');

        if (!pucCheckDot || pucCheckDot == pstDirData->d_name)
        {
            strncpy((char*)pucFileType, "No", FILE_TYPE_SIZE);
            pucFileType[255] = '\0';
        }
        else
        {
            strncpy((char*)pucFileType, pucCheckDot + 1, FILE_TYPE_SIZE);
            pucFileType[FILE_TYPE_SIZE-1] = '\0';
        }

        blRet = true;
    }

    return blRet;
}


//**************************.ReadFilesAndBuildList.*****************************
//Purpose : To read file data and create linked list node
//Inputs  : pucReadFileName - Character Pointer to give the name of the 
//          directory
//Return  : Boolean value - for both input success return will be true else 
//          false
//Notes   : None
//*
bool ReadFilesAndBuildList(const uint8_t *pucReadFileName)
{
    bool blRet = false;
    struct dirent *pstDirData = NULL;
    struct stat stStatFileData = {0};
    uint8_t ucFileType[FILE_TYPE_SIZE] = {0};
    DIR *pstDirDataOprtn = NULL;
    FILE_DATA *pstReadData = NULL;

    if(pucReadFileName != NULL)
    {
        pstDirDataOprtn = opendir(pucReadFileName);

        if(pstDirDataOprtn != NULL)
        {
            while ((pstDirData = readdir(pstDirDataOprtn)) != NULL)
            {
                if (strcmp(pstDirData->d_name, ".") == 0 || 
                strcmp(pstDirData->d_name, "..") == 0) 
                { 
                    continue;
                }
                
                pstReadData = (FILE_DATA*)malloc(sizeof(FILE_DATA));

                if(pstReadData != NULL)
                {
                    // Read file size and file type
                    if(ReadFileSize(&stStatFileData, pstDirData, 
                        pucReadFileName))
                    {
                        if(ReadFileType(pstDirData, ucFileType))
                        {
                            // Assign the read value to the output structure
                            strncpy(pstReadData->mpucFileName, 
                                pstDirData->d_name, 
                                sizeof(pstReadData->mpucFileName) - 1);
                            pstReadData->mucFileSize = stStatFileData.st_size;
                            strncpy(pstReadData->mucFileType, ucFileType, 
                                sizeof(pstReadData->mucFileType) - 1);

                            //Add Node in the beginning of linked list
                            if(LinkedListAddNode(pstReadData))
                            {
                                blRet = true;
                            }
                        }
                    }
                }
            }
        }
    }

    return blRet;
}