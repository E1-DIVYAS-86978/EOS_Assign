#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int i, pid1, pid2, pid3,pid4,pid5,s;

    pid1 = fork();
    if(pid1 == 0) { // child 1
        for(i=1; i<=3; i++) {
            printf("child1: %d\n child1 pid: %d\n", i,getpid());
            sleep(5);
        }
        _exit(3);
    }

    // parent continues
    pid2 = fork();
    if(pid2 == 0) { // child 2
        for(i=1; i<=3; i++) {
            printf("child2: %d\n child2 pid: %d\n", i,getpid());
            sleep(5);
        }
        _exit(7);
    }

    // parent continues
    pid3 = fork();
    if(pid3 == 0) { // child 3
        for(i=1; i<=3; i++) {
            printf("child3: %d\n child3 pid: %d\n", i,getpid());
            sleep(5);
        }
        _exit(9);
    }
    pid4 = fork();
    if(pid4 == 0) { // child 4
        for(i=1; i<=3; i++) {
            printf("child4: %d\n child4 pid: %d\n", i,getpid());
            sleep(5);
        }
        _exit(2);
    }
    pid5 = fork();
    if(pid5 == 0) { // child 5
        for(i=1; i<=3; i++) {
            printf("child5: %d\n child5 pid: %d\n", i,getpid());
            sleep(5);
        }
        _exit(1);
    }

    // parent continues
    for(i=1; i<=3; i++) {
        printf("parent: %d\n parent pid: %d\n", i,getpid());
        sleep(5);
    }

    //waitpid(pid1, &s1, 0);
    //waitpid(pid2, &s2, 0);
    //waitpid(pid3, &s3, 0);

    while(waitpid(-1, &s, 0) > 0)
        printf("child exit status: %d\n", WEXITSTATUS(s));
    return 0;
}

