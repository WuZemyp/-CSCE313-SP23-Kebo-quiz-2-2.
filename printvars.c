#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
char *custom_env[] = {"USER=Pikachu", "PATH=/tmp", NULL};

int main(void)
{
    // TODO
    pid_t pid1=fork();
    if(pid1==0)
    {
        printf("Running child process PID: %d\n",getpid());
        char *arg[]={"echoall","Bandicoot","Pacman",NULL};
        execle("/home/zwubn/-CSCE313-SP23-Kebo-quiz-2-2./echoall",arg[0],arg[1],arg[2],NULL,custom_env);
    }
    else{
        printf("Running parent process PID: %d\n",getpid());
        printf("\n");
        wait(NULL);
        pid_t pid2=fork();
        if(pid2==0)
        {
            printf("Running child process PID: %d\n",getpid());
            
            execlp("/home/zwubn/-CSCE313-SP23-Kebo-quiz-2-2./echoall","Spyro",NULL);

        }
        wait(NULL);
    }
    exit(0);
}