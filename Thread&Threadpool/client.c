/**
 * Example client program that uses thread pool.
 */

#include <stdio.h>
#include <unistd.h>
#include "threadpool.h"

struct data
{
    int a;
    int b;
};

void add(void *param)
{
    struct data *temp;
    temp = (struct data*)param;

    printf("I add two values %d and %d result = %d\n",temp->a, temp->b, temp->a + temp->b);
}

int main(void)
{
    // create some work to do
    struct data work0;
    work0.a = 5;
    work0.b = 10;

    struct data work1;
    work1.a = 15;
    work1.b = 110;

    struct data work2;
    work2.a = 55;
    work2.b = 150;

    struct data work3;
    work3.a = 155;
    work3.b = 1105;

    struct data work4;
    work4.a = 25;
    work4.b = 210;

    struct data work5;
    work5.a = 158;
    work5.b = 1108;

    struct data work6;
    work6.a = 9;
    work6.b = 99;

    struct data work7;
    work7.a = 1;
    work7.b = 11;

    // initialize the thread pool
    pool_init();
    // submit the work to the queue
    pool_submit(&add,&work0);
    pool_submit(&add,&work1);
    //
    pool_submit(&add,&work2);
    pool_submit(&add,&work3);
    pool_submit(&add,&work4);
    pool_submit(&add,&work5);
    pool_submit(&add,&work6);
    pool_submit(&add,&work7);

    // may be helpful 
   // sleep(1);

    pool_shutdown();

printf("\nprogram terminated\n");
    return 0;
}
