#pragma once

const int MAX_HE = 512;
const int MAX_WI = 512;

void invert(int width, int height, int img[MAX_HE][MAX_WI]);
void invertHalf(int width, int height, int img[MAX_HE][MAX_WI]);
void box(int width, int height, int img[MAX_HE][MAX_WI]);
void frame(int width, int height, int img[MAX_HE][MAX_WI]);
void scale(int width, int height, int img[MAX_HE][MAX_WI]);
void pixelate(int width, int height, int img[MAX_HE][MAX_WI]);
