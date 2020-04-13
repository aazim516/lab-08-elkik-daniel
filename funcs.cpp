#include <iostream>
#include "imagehelpers.h"
#include "funcs.h"

void invert(int width, int height, int img[MAX_HE][MAX_WI]){
  int newImg[MAX_HE][MAX_WI];
  for (int row = 0; row < height; row++){
    for (int col = 0; col < width; col++){
      newImg[row][col] = 255 - img[row][col];
    }
  }
  writeImage("taskA.pgm",newImg, height, width);
}

void invertHalf(int width, int height, int img[MAX_HE][MAX_WI]){
  int newImg[MAX_HE][MAX_WI];
  for (int row = 0; row < height; row++){
    for (int col = 0; col < width/2; col++){
      newImg[row][col] = img[row][col];
    }
    for (int col = width/2; col < width; col++){
      newImg[row][col] = 255 - img[row][col];
    }
  }
  writeImage("taskB.pgm",newImg, height, width);
}

void box(int width, int height, int img[MAX_HE][MAX_WI]){
  int newImg[MAX_HE][MAX_WI];
  for (int row = 0; row < height; row++){
    for (int col = 0; col < width; col++){
      if ((row>=height/4 && row<height-height/4) && (col>=width/4 && col<width-width/4)){
          newImg[row][col] = 255;
        }
      else{
        newImg[row][col] = img[row][col];
      }
    }
  }
  writeImage("taskC.pgm",newImg, height, width);
}

void frame(int width, int height, int img[MAX_HE][MAX_WI]){
  int newImg[MAX_HE][MAX_WI];
  for (int row = 0; row < height; row++){
    for (int col = 0; col < width; col++){
      if ((row==height/4 || row == height-height/4-1) && (col>=width/4 && col<width-width/4)){
        newImg[row][col] = 255;
      }
      else if (row > height/4 && row < height-height/4-1 && (col == width/4 || col == width-width/4-1)){
        newImg[row][col] = 255;
      }
      else {
        newImg[row][col] = img[row][col];
      }
    }
  }
  writeImage("taskD.pgm",newImg, height, width);
}

void scale(int width, int height, int img[MAX_HE][MAX_WI]){
  int newImg[MAX_HE][MAX_WI], row2=0, col2=0;
  for (int row = 0; row < height; row++){
    col2=0;
    for (int col = 0; col < width; col++){
      newImg[row2][col2] = img[row][col];
      newImg[row2][col2+1] = img[row][col];
      newImg[row2+1][col2] = img[row][col];
      newImg[row2+1][col2+1] = img[row][col];
      col2+=2;
    }
    row2+=2;
  }
  writeImage("taskE.pgm",newImg, (height*2), (width*2));
}

void pixelate(int width, int height, int img[MAX_HE][MAX_WI]){
  int newImg[MAX_HE][MAX_WI];
  int area;
  for (int row = 0; row < height; row+=2){
    for (int col = 0; col < width; col+=2){
      area = (img[row][col]+img[row][col+1]+img[row+1][col]+img[row+1][col+1])/4;
      newImg[row][col] = area;
      newImg[row][col+1] = area;
      newImg[row+1][col] = area;
      newImg[row+1][col+1] = area;
    }
  }
  writeImage("taskF.pgm",newImg, height, width);
}
