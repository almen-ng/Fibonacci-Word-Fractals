#include "bmp.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    up,
    down,
    left,
    right
} direction;

char* fibonacci_word;
int index_concatenation = 0;

void draw(int x, int y, direction dir, int step, int w, RGB* im, RGB c)
{
#define I(i, j) im[(i)*w + j]
    int j;
    if (dir == up)
        for (j = 0; j < step; j++)
            I(x + j, y) = c;
    if (dir == down)
        for (j = 0; j < step; j++)
            I(x - j, y) = c;
    if (dir == right)
        for (j = 0; j < step; j++)
            I(x, y + j) = c;
    if (dir == left)
        for (j = 0; j < step; j++)
            I(x, y - j) = c;
#undef I
}

int calculation_of_size(int n){
  if (n == 1 || n == 2 ){
    return 1;
  }
  return calculation_of_size(n - 1) + calculation_of_size(n - 2);
}

void concatenation(int n){
  if (n == 1){
    fibonacci_word[index_concatenation] = '1';
    index_concatenation++;
  }
  else if (n == 2){
    fibonacci_word[index_concatenation] = '0';
    index_concatenation++;
  }
  else{
    concatenation(n - 1);
    concatenation(n - 2);
  }
}

int fib(int n, int x, int y, int step, RGB bc, RGB fc, int w, int h, RGB * image){
  direction direction = up;
  int index_fibonacci_word;
  int size_of_fibonacci_word;
  int index_pixel;
  int steps = 1;

  size_of_fibonacci_word = calculation_of_size(n);
  fibonacci_word = malloc(sizeof(char)*(size_of_fibonacci_word) + 1);
  concatenation(n);

  if (!(fibonacci_word) || !(image)){
    return 0;
  }

  for (index_pixel = 0; index_pixel < w * h; index_pixel++){
    image[index_pixel] = bc;
  }

  for (index_fibonacci_word = 0; index_fibonacci_word < size_of_fibonacci_word; index_fibonacci_word++){
    if ((x + step) < 0 || (x + step) > h || (y + step) < 0 || (y + step) > w){
      return 0;
    }

    draw (x, y, direction, step, w, image, fc);
    steps += 1;

    switch(direction){
      case up:
        x += step;
        break;
      case down:
        x -= step;
        break;
      case left:
        y -= step;
        break;
      case right:
        y += step;
        break;
    }

    if (fibonacci_word[index_fibonacci_word] == '0'){
      if ((index_fibonacci_word + 1) % 2 == 0){
        switch (direction){
          case up:
            direction = left;
            break;
          case down:
            direction = right;
            break;
          case left:
            direction = down;
            break;
          case right:
            direction = up;
            break;
        }
      }
      else if ((index_fibonacci_word + 1) % 2 != 0){
        switch (direction){
          case up:
            direction = right;
            break;
          case down:
            direction = left;
            break;
          case left:
            direction = up;
            break;
          case right:
            direction = down;
            break;
        }
      }
    }
  }
  return steps;
}
