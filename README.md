# PixelsToCharacters
This is a project I did for class and had so much fun doing!

You start by running the project with an argument of one of the various .ppm files. 
The code will start by reading the header of the file you attached and check to see if it is a binary or ascii file. If it is not either, the program will end. 
It will then read the dimensions of the image and the max color value. It will store the dimensions in a struct and check to see if the max color value is 255. If it is not 255, the program will end. 
After the program reads the header, it will then read each pixel in the image and convert it to the corresponding character and color based on color values it reads from the .ppm file. 
It will then, downsize the image to the correct size to be displayed on the console and print it to the screen. 
