#include "picmaker.h"

int main() {
  int status;

  int fd;
  fd = open("pic.ppm", O_CREAT | O_RDWR, 0644);
  if (fd == -1) printf("Error opening file: %s", strerror(errno));

  char * buf = "P3\n600 600\n255\n";
  write(fd, buf, 15);

  char * red = "255 0 0";
  char * orange = "255 165 0";
  char * yellow = "255 255 0";
  char * green = "0 255 0";
  char * blue = "0 0 255";
  char * indigo = "75 0 130";
  char * violet = "238 130 238";

  char * tab = "\t";
  char * newline = "\n";
  char * space = " ";

  int c1, c2, c3;
  c1 = 255;
  c2 = 255;
  c3 = 255;
  int digs = 3;
  char* temp;

  int i=0;
  int i2=0;
  for(i=0;i<600;i++) {
    for (i2=0;i2<600;i2++) {
      if (i2 > 230 && i2 <= 250) write(fd,red,15);
      else if (i2 > 250 && i2 <= 270) write(fd,orange,15);
      else if (i2 > 270 && i2 <= 290) write(fd,yellow,15);
      else if (i2 > 290 && i2 <= 310) write(fd,green,15);
      else if (i2 > 310 && i2 <= 330) write(fd,blue,15);
      else if (i2 > 330 && i2 <= 350) write(fd,indigo,15);
      else if (i2 > 350 && i2 <= 370) write(fd,violet,15);
      // if (i%50 >= 0 && i%50<=4)write(fd,yellow,10);
      // else write(fd,green,10);
      else {
        if (i2 > 230 && i2<= 370) printf("wait a minute\n");
        sprintf(temp, "%d", c1);
        write(fd,temp,3);
        write(fd,space,1);
        sprintf(temp, "%d", c2);
        write(fd,temp,3);
        write(fd,space,1);
        sprintf(temp, "%d", c3);
        write(fd,temp,digs);
      }
      write(fd,tab,2);
    }
    write(fd,newline,1);
    c3 = (c3+3) % 255;
    if (c3 < 10) digs = 1;
    else if (c3 < 100) digs = 2;
    else digs = 3;
    //printf("%d: %d\n", c3, digs);
  }

  close(fd);
  return 0;
}
