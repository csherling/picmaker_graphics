#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>


int main(){

  int r, g, b, i, j;

  int fd = open("meme.ppm", O_CREAT | O_TRUNC | O_RDWR, 0644);

  int xres = 500;
  int yres = 500;

  char file[10];
  sprintf(file, "P3\n");
  write(fd, file, strlen(file));
  sprintf(file, "%d %d 255\n", xres, yres);
  write(fd, file, strlen(file));

  for(i = 0; i < yres; i++){
    for(j= 0; j < xres; j++){
      r = (i % 256 * j % 256) % 256;
      g = (i % 256 * j % 256 + 128) % 256;
      b = (i + j) % 256;
      sprintf(file, "%d %d %d\n", r, g, b);
      write(fd, file, strlen(file));      
    }
  }

  close(fd);
  
}
