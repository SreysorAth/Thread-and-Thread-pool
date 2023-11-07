#include <pthread.h>
#include <semaphore.h>

void execute(void (*somefunction)(void *p), void *p);
int pool_submit(void (*somefunction)(void *p), void *p);
void *worker(void *param);
void pool_init(void);
void pool_shutdown(void);

struct task
{
    void (*function)(void *p,int thread_id);
    void *data;
    struct task *next;
    int task_id; //debug purpose
};

struct threadpool
{
    struct task *head;
    struct task *tail;
    pthread_mutex_t mutex;
    sem_t semaphore;
    int timespan;
};
