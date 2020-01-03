//
//  formatPicture.c
//  Homework
//
//  Created by Chloe Holland on 10/13/19.
//  Copyright © 2019 Chloe Holland. All rights reserved.
//

#include "formatPicture.h"
#include "hw1given.h"
#include "readFile.h"
#include <math.h>

void downsizeImageAndPrint(Pixel **picture, Pic *dimensions) {
    enum Ansi_Color color = 0;
    char character;
    int i, j;
    int redSum = 0, blueSum = 0, greenSum = 0, count = 0;
    int numOfCol = 0, numOfRows = 0;
    int printCol = 4, printRow = 8;
    float avgRed = 0.0, avgBlue = 0.0, avgGreen = 0.0; 
    
    numOfCol = dimensions->col/printCol;
    numOfRows = dimensions->rows/printRow;
    
    //Finding average color for all of the pixels
    for (int n = 0; n < numOfRows; n++) {
        // moving the row index to read more pixels
	if (n > 0) {
		j = j + printRow;
	} else {
		j = 0;
	}
	for (int m = 0; m < numOfCol; m++) {
            // Finding the average color in the condensed pixel
	    // moving the column index to read more pixels
	    if (m > 0) {
		i = i + printCol;
	    } else {
	    	i = 0;
	    }
            for (int y = 0; y < printRow; y++) {
		for (int x = 0; x < printCol; x++) {
                    redSum = picture[x+i][y+j].Red + redSum;
                    blueSum = picture[x+i][y+j].Blue + blueSum;
                    greenSum = picture[x+i][y+j].Green + greenSum;
                    count++;
                }
            }
            avgRed = redSum/count;
            avgBlue = blueSum/count;
            avgGreen = greenSum/count;
	    
	    // Chain of functions:    
	    character = luminanceOfPixel(avgRed, avgBlue, avgGreen);
	    // Prints in here:
	    colorOfPixel(avgRed, avgBlue, avgGreen, color, character);
	    
	    redSum = 0;
	    blueSum = 0;
	    greenSum = 0;
	    avgRed = 0;
	    avgBlue = 0;
	    avgGreen = 0;
	    count = 0;
       	}
	printf("\n");
    }
}

char luminanceOfPixel(float avgRed, float avgBlue, float avgGreen) {
	int luminance = 0;
	char character;
	
	luminance = ((0.21*avgRed) + (0.71*avgGreen) + (0.08*avgBlue));	
	
	character = characterOfPixel(luminance);
	return character;
}

char characterOfPixel(float luminance) {
	int characterValue = (luminance * (sizeof(ASCII_MAP_STRING)-1))/255;
	char character = ASCII_MAP_STRING[characterValue];
	return character;	
}

void colorOfPixel(float avgRed, float avgBlue, float avgGreen, enum Ansi_Color color, char character) {
	float pixelColor = 256, tempColor = 0;
	color = 0;
	for(int i = 0; i < NUM_ANSI_COLORS; i++) {
		// Calculating Color to compare to eachother
		if (i == 0) {
			tempColor = sqrt(pow((0 - avgRed), 2) + pow((0 - avgGreen), 2) + 
					pow((255 - avgBlue), 2)); 
		} else if (i == 1) {
			tempColor = sqrt(pow((0-avgRed), 2) + pow((255 - avgGreen), 2) + 
					pow((0 - avgBlue), 2));
		} else if (i == 2) {
			tempColor = sqrt(pow((0 - avgRed), 2) + pow((255 - avgGreen), 2) + 
					pow((255 - avgBlue), 2));
		} else if (i == 3) {
			tempColor = sqrt(pow((255 - avgRed), 2) + pow((0 - avgGreen), 2) + 
					pow((0 - avgBlue), 2));
		} else if (i == 4) {
			tempColor = sqrt(pow((255 - avgRed), 2) + pow((0 - avgGreen), 2) + 
					pow((255 - avgBlue), 2));
		} else if (i == 5) {
			tempColor = sqrt(pow((255 - avgRed), 2) + pow((255 - avgGreen), 2) + 
					pow((0 - avgBlue), 2));
		} else if (i == 6) {
			tempColor = sqrt(pow((255 - avgRed), 2) + pow((255 - avgGreen), 2) + 
					pow((255 - avgBlue), 2));
		}

		if (tempColor < pixelColor) {
			pixelColor = tempColor;
			color = i;
		}
	}
	PrintASCIIChar(color, character);
}
