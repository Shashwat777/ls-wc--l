#include <stdio.h>
#include <unistd.h>
//ls | wc -l
int main()
{
    int pid;
    int fd[2];
    int ret;
    ret = pipe (fd);
    if (ret == -1) {
        printf ("Unable to create pipe\n");
        return 0;
    }
    pid = fork ();
    if (pid == 0) {
        close(1);
        
        dup(fd[1]);
        
     
        close(fd[0]);
        

        execlp("ls","ls",NULL);
    }
    else if (pid > 0) {
       

        close(0);
        

        dup(fd[0]);
        
  
        close(fd[1]);
        

        execlp("wc","wc",NULL);
    }
    else {
        close(fd[0]);
        printf ("Unable to fork\n");
        close(fd[1]);
    }
    return 0;
}
