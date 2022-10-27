// Program: Shuffle image bonus.cpp
// Purpose: Demonstrate use of RGBbmplip for handling
//          bmp colored and colored scale images
//          Program load a colored image and store in another file
// Author:  Laila Hesham
// Date:    23 April 2022
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
void Shuffle_Image();

int main()
{
  loadImage();
  Shuffle_Image();
  saveImage();
  return 0;
}

//_________________________________________
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

//_________________________________________
void saveImage () {
   char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeRGBBMP(imageFileName, image);
}

//Shuffles the image to order the quadrants the way the user wants it
void Shuffle_Image(){
    unsigned char imageOriginal[SIZE][SIZE][RGB];
    int quadrant1,quadrant2,quadrant3,quadrant4;
    cout<<"Welcome.Please enter which quadrant you want to place in the first quadrant ";
    cin>>quadrant1;
    cout<<"Please enter which quadrant you want to place in the second quadrant ";
    cin>>quadrant2;
    cout<<"Please enter which quadrant you want to place in the third quadrant ";
    cin>>quadrant3;
    cout<<"Please enter which quadrant you want to place in the fourth quadrant ";
    cin>>quadrant4;
    cout<<quadrant1<<quadrant2<<quadrant3<<quadrant4<<endl;

    for(int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
                for(int k =0; k<RGB ; k++){
                    imageOriginal[i][j][k] = image[i][j][k];
                }
        }
    }
    //quadrant 1:
    if(quadrant1 != 1){
        int x = 0;
        int y = 0;
        if(quadrant1 == 2 || quadrant1 == 4)
            y = SIZE/2;
        if(quadrant1 == 3 || quadrant1 == 4)
            x = SIZE/2;
        int y1 = y;
        for(int i = 0; i < SIZE/2; i++, x++){
            y = y1;
            for(int j = 0; j< SIZE/2; j++, y++){
                for(int k =0; k<RGB ; k++){
                    image[i][j][k] = imageOriginal[x][y][k];
                }
            }
        }
    }
    //quadrant 2:
    if (quadrant2 !=2){
        int x=0;
        int y=0;
        if(quadrant2 == 4)
            y = SIZE/2;
        if(quadrant2 == 3 || quadrant2 == 4)
            x = SIZE/2;
        int y1 = y;
        for (int i = 0; i < SIZE/2; i++, x++){
            y = y1;
            for (int j = SIZE/2; j< SIZE; j++, y++){
                for(int k =0; k<RGB ; k++){
                    image[i][j][k]=imageOriginal[x][y][k];
                }
            }
        }
    }
    //quadrant 3:
    if(quadrant3 != 3){
        int x = 0;
        int y = 0;
        if(quadrant3 == 2 || quadrant3 == 4)
            y = SIZE/2;
        if(quadrant3 == 4)
            x = SIZE/2;
        int y1 = y;
        for (int i = SIZE/2; i < SIZE; i++, x++){
                y = y1;
            for (int j = 0; j< SIZE/2; j++, y++){
                for(int k =0; k<RGB ; k++){
                    image[i][j][k]=imageOriginal[x][y][k];
                }
            }
        }
    }
    //quadrant 4:
    if(quadrant4 != 4){
        int x=0;
        int y=0;
        if(quadrant4 == 2)
            y = SIZE/2;
        if(quadrant4 == 3)
            x = SIZE/2;
        int y1 = y;
        for (int i = SIZE/2; i < SIZE; i++, x++){
            y = y1;
            for (int j = SIZE/2; j< SIZE; j++, y++){
                for(int k =0; k<RGB ; k++){
                    image[i][j][k]=imageOriginal[x][y][k];
                }
            }
        }
    }
}
