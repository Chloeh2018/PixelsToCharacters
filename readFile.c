//
//  readFile.c
//  Homework
//
//  Created by Chloe Holland on 10/13/19.
//  Copyright © 2019 Chloe Holland. All rights reserved.
//

#include "readFile.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 30
#define ERROR -1
#define LINE_SIZE 250


int openReadFileType(FILE *fp) {
    char lineRead[MAX];
    int fileBinary = 2;
    int fileASCII = 3;
    
    fgets(lineRead, LINE_SIZE, fp);
    if (strncmp(lineRead, "P6", 2) == 0) {
	return fileBinary;
    } if (strncmp(lineRead, "P3", 2) == 0) {
        return fileASCII;
    } else {
        printf("ERROR READING FILE: Not binary nor ASCII /n");
        return ERROR;
    }
    
    return 0;
}

void readDimensions(Pic *dimensions, FILE *fp) {
    char lineRead[LINE_SIZE];
    char *ptr;
     
    fgets(lineRead, LINE_SIZE, fp);
    while (strncmp(lineRead, "#", 1) == 0) {
        fgets(lineRead, LINE_SIZE, fp);
    }
    
    dimensions->col = strtol(lineRead, &ptr, 10);
    dimensions->rows = strtol(ptr, NULL, 10);
}

bool maxColorValue(FILE *fp) {
    char lineRead[MAX];
    bool colorValue = false;
    
    fgets(lineRead, LINE_SIZE, fp);
    while (strncmp(lineRead, "#", 1) == 0) {
        fgets(lineRead, LINE_SIZE, fp);
    }
    if (strncmp(lineRead, "255", 3) == 0) {
        colorValue = true;
    } else {
        colorValue = false;
    }
    return colorValue;
}

void readASCII(FILE *fp, Pic *dimensions, Pixel **picture) {
    int x = 0, y = 0;
    int count = 0;
    char lineRead[MAX];
    // Reading in pixels and storing them into the struct Pixel picture
    for (y; y < dimensions->rows; y++) {
        for (x = 0; x < dimensions->col; x++) {
            fgets(lineRead, LINE_SIZE, fp);
            picture[x][y].Red = strtol(lineRead, NULL, 10);
            fgets(lineRead, LINE_SIZE, fp);
            picture[x][y].Green = strtol(lineRead, NULL, 10);
            fgets(lineRead, LINE_SIZE, fp);
            picture[x][y].Blue = strtol(lineRead, NULL, 10);
	}
    }
    fclose(fp);
}

void readBinary(FILE *fp, Pic *dimensions, Pixel **picture) {
    int x = 0, y = 0;
    char lineRead[MAX];
    // Reading in pixels and storing them into the struct Pixel picture    
    for (y; y < dimensions->rows; y++) {
        for (x = 0; x < dimensions->col; x++) {
            fread(&picture[x][y].Red, sizeof(char), 1, fp);
            fread(&picture[x][y].Green, sizeof(char), 1, fp);
            fread(&picture[x][y].Blue, sizeof(char), 1, fp);
        }
    }
    fclose(fp);
}
