//
//  readFile.h
//  Homework
//
//  Created by Chloe Holland on 10/13/19.
//  Copyright © 2019 Chloe Holland. All rights reserved.
//

#ifndef readFile_h
#define readFile_h

#include <stdio.h>
#include <stdbool.h>
#include "hw1given.h"

typedef struct Pic {
    unsigned long int col;
    unsigned long int rows;
    
} Pic;

int openReadFileType(FILE *fp);
void readDimensions(Pic *dimensions, FILE *fp);
bool maxColorValue(FILE *fp);
void readASCII(FILE *fp, Pic *dimensions, Pixel **picture);
void readBinary(FILE *fp, Pic *dimensions, Pixel **picture);

#endif /* readFile_h */
