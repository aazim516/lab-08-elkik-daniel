#include <iostream>
#include "funcs.h"
#include "imagehelpers.h"

int main(){
  int width = 0, height = 0, img[MAX_H][MAX_W];
  readImage("inImage.pgm", img, height, width );
  // invert(width, height, img);
  // invertHalf(width, height, img);
  // box(width, height, img);
  // frame(width, height, img);
  // scale(width, height, img);
  pixelate(width, height, img);
}
