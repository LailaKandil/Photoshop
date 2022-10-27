// Program: Enlargeimagebonus.cpp
// Purpose: Demonstrate use of bmplip for handling
//          bmp colored and RGBscale images
//          Program load a colored image and store in another file
// Author:  Laila Hesham
// Date:    20 April 2022
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
void EnlargeImage ();

int main()
{
  loadImage();
  EnlargeImage();
  saveImage();
  return 0;
}

//load colored image from source file
void loadImage () {
   char imageFileName[100];

   // Get gray scale image file name
   cout << "Enter the source image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   readRGBBMP(imageFileName, image);
   int readRGBBMP(const char* filename, unsigned char inputImage[][SIZE][RGB]);
}

//Save the coloured image
void saveImage () {
   char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeRGBBMP(imageFileName, image);
}

//Enlarge a certain quadrant
void EnlargeImage(){
    int choice;
    cout<<"Welcome. Enter which quadrant you would like to enlarge(1 to 4)";
    cin>>choice;
    unsigned char imageOriginal[SIZE][SIZE][RGB];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++){
            for (int k =0; k<RGB ; k++){
                imageOriginal[i][j][k] = image[i][j][k];
            }

        }
    }
    if (choice==1){
        for (int i = 0; i < SIZE/2; i++){
            for (int j = 0; j< SIZE/2; j++){
                 for(int k =0; k<RGB ; k++){
                    char c = imageOriginal[i][j][k];
                    image[(i+1)*2-1][(j+1)*2-1][k] = c;
                    image[(i+1)*2-1][(j+1)*2-2][k] = c;
                    image[(i+1)*2-2][(j+1)*2-1][k] = c;
                    image[(i+1)*2-2][(j+1)*2-2][k] = c;
                 }
                 }
                 }
                 }
    if (choice==2){
         for (int i = 0; i < SIZE/2; i++){
            for (int j = SIZE/2; j< SIZE; j++){
                 for(int k =0; k<RGB ; k++){
                     char c = imageOriginal[i][j][k];
                     image[(i+1)*2-1][2*j - SIZE][k] = c;
                     image[(i+1)*2-1][2*j - SIZE + 1][k] = c;
                     image[(i+1)*2-2][2*j - SIZE][k] = c;
                     image[(i+1)*2-2][2*j - SIZE + 1][k] = c;

            }
            }
            }
            }
    if (choice==3){
        for (int i = SIZE/2; i < SIZE; i++){
            for (int j = 0; j< SIZE/2; j++){
                for(int k =0; k<RGB ; k++){
                    char c = imageOriginal[i][j][k];
                    image[2*i - SIZE][(j+1)*2-1][k] = c;
                    image[2*i -SIZE][(j+1)*2-2][k] = c;
                    image[2*i -SIZE + 1][(j+1)*2-1][k] = c;
                    image[2*i -SIZE + 1][(j+1)*2-2][k] = c;
                }
                }
                }
                }
    if (choice==4){
        for (int i = SIZE/2; i < SIZE; i++){
            for (int j = SIZE/2; j< SIZE; j++){
                for(int k =0; k<RGB ; k++){
                    char c = imageOriginal[i][j][k];
                    image[2*i - SIZE][2*j - SIZE][k] = c;
                    image[2*i - SIZE][2*j - SIZE + 1][k] = c;
                    image[2*i - SIZE + 1][2*j - SIZE][k] = c;
                    image[2*i - SIZE + 1][2*j - SIZE + 1][k] = c;
                }
                }
                }
                }
}
