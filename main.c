//
//  main.c
//  Homework
//
//  Created by Chloe Holland on 10/13/19.
//  Copyright © 2019 Chloe Holland. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "readFile.h"
#include "hw1given.h"
#include "formatPicture.h"
#include <stdbool.h>

int main(int argc, const char * argv[]) {
    FILE *fp;
    Pic dimensions;
    Pixel** picture;
    int fileType;
    int i = 0;
    bool colorValue = false;

    if (argc != 2) {
        return 1;
    }
    fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        return 1;
    }
    
    fileType = openReadFileType(fp);
    readDimensions(&dimensions, fp);
    colorValue = maxColorValue(fp);
    if (colorValue == false) {
	    return 1;
    }

    //Allocating memory for the picture array
    picture = (Pixel**)malloc(sizeof(Pixel*)*dimensions.col);
    for (i; i < dimensions.col; i++) {
        picture[i] = (Pixel*)malloc(sizeof(Pixel)*dimensions.rows);
    }

    int fileBinary = 2, fileASCII = 3;
    if (fileType == fileBinary) {
        readBinary(fp, &dimensions, picture);
    } else if (fileType == fileASCII) {
        readASCII(fp, &dimensions, picture);
    } else {
    	printf("It did not go in any of the functions to read the pixels \n");
    }

    downsizeImageAndPrint(picture, &dimensions);
    
    // Freeing memory
    for (int i = 0; i < dimensions.col; i++) {
    	free(picture[i]);
    }
    free(picture);

    return 0;
}
