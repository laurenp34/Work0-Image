#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
  int status;

  int fd;
  fd = open("pic.ppm", O_CREAT | O_RDWR, 0644);
  if (fd == -1) printf("Error opening file: %s", strerror(errno));

  char * buf = "p3\n600 600\n255\n";
  write(fd, buf, 15);

  buf = "255 255 0";
  char * tab = "\t";
  char * newline = "\n";
  
  int i=0;
  int i2=0;
  for(i=0;i<600;i++) {
    for (i2=0;i2<600;i2++) {
      write(fd,buf,10);
      write(fd,tab,1);
    }
    write(fd,newline,1);
  }

  return 0;
}
