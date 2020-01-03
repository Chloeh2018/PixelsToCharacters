//
//  formatPicture.h
//  Homework
//
//  Created by Chloe Holland on 10/13/19.
//  Copyright © 2019 Chloe Holland. All rights reserved.
//

#ifndef formatPicture_h
#define formatPicture_h

#include <stdio.h>
#include "hw1given.h"
#include "readFile.h"

void downsizeImageAndPrint(Pixel **picture, Pic *dimensions);
char luminanceOfPixel(float, float, float);
char characterOfPixel(float);
void colorOfPixel(float, float, float, enum Ansi_Color, char);

#endif /* formatPicture_h */
