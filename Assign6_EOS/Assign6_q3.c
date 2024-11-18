
#include <stdio.h>
#include <unistd.h>

int main() {
    int ret, cnt = 0;
    while(1) {
        ret = fork();
        if(ret == -1) { // parent
            printf("fork() failed.\n");
            waitpid((-1,NULL,0)>0);
            _exit(0);
        }
        else if(ret == 0) {
            // child process
            sleep(5);
            _exit(0);
        }
        else {
            // parent process
            cnt++;
            printf("child count: %d\n", cnt);
        }
    }
    return 0;
}
