// Program: rotateImage.cpp
// Purpose: Demonstrate use of bmplip for handling
//          RGB colored and coloured images
//          Program load a colcoured image and store in another file
// Author:  Laila Hesham
// Date:    23 APril 2022
// Version: 1.0

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE][RGB];

void loadImage ();
void saveImage ();
void rotateImage ();

int main()
{
  loadImage();
  rotateImage();
  saveImage();
  return 0;
}

//to load the image from its new directory
void loadImage () {
   char imageFileName[100];

   // Get gray scale image file name
   cout<<"Welcome user!";
   cout << "Enter the source image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   readRGBBMP(imageFileName, image);
   int readRGBBMP(const char* filename, unsigned char inputImage[][SIZE][RGB]);

}

//To save the new image
void saveImage () {
   char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeRGBBMP(imageFileName, image);
}

//this function is to rotate the image.
void rotateImage() {
    int choice;
    cout<<"Enter the degree you want to rotate the image with \n 1.90 degrees \n 2.180 degrees \n 3.270 degrees";
    cin>>choice;
    char tempArr[SIZE][SIZE][RGB];
    for (int countRotations = 0; countRotations < choice; countRotations++) {
        for (int i = 0; i < SIZE; i++){
            for (int j =0; j<SIZE; j++){
                for(int k =0; k<RGB ; k++){
                    tempArr[i][j][k] = image[i][j][k];
                }

            }
        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j< SIZE; j++) {
                for(int k =0; k<RGB ; k++){
                    image[j][SIZE-1-i][k] = tempArr[i][j][k];
                }



            }
        }
    }
}
