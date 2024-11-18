#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

struct input {
    int start;
    int end;
};

struct output {
    int sum;
};

void* add(void *param) {
    struct input *ip = (struct input *)param;
    struct  output *op = (struct output *)malloc(sizeof(struct output));
  for(int j = ip->start;j <= ip->end;j++) {
    op->sum = op->sum + j;
 };
 return op;
    
}
int main() {
    pthread_t th;
    struct input in = { .start = 1, .end = 5};
    struct output *out;
    pthread_create(&th, NULL, add, &in);
    pthread_join(th,(void**)&out);
    printf("main: sum = %d\n", out->sum);

    free(out);
    return 0;
}