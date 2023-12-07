#include <fcntl.h> 
#include <stdio.h> 
#include <string.h>
#include <unistd.h> 
int global = 10;
int main()
{
      static char buf[2];
     char *p;
    int fd = open("omar.text", O_RDWR | O_CREAT | O_APPEND, 0777);
    write(fd,"qwedrfcvgtfdrfgtfcvhgytfkhuyoirerueuyreohu",33);
    int f = read(fd,buf,2);
    while(f != 0)
    {
        f = read(fd,buf,2);
        printf("%s",buf);
    }

     printf("%d",f);
}
