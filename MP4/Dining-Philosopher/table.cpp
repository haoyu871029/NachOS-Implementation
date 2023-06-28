#include "table.hpp"
#include "stdio.h"

//控制餐桌上的人數
//利用Semaphore確保至多只有四位哲學家在餐桌上
//吃完就滾

Table::Table(int n) {
    // TODO: implement table constructor (value, mutex, cond)
    value = n-1;
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);
}

//use the pthread mutex lock and condition variable to implement the semaphore.
void Table::wait() {
    // TODO: implement semaphore wait
    pthread_mutex_lock(&mutex);
    while (value == 0) {
        printf("Table is full.\n");
        pthread_cond_wait(&cond, &mutex);
    }
    printf("Table is not full.\n");
    value -= 1;
    pthread_mutex_unlock(&mutex);  
}

void Table::signal() {
    // TODO: implement semaphore signal
    pthread_mutex_lock(&mutex);
    value += 1;
    printf("Someone left the table.\n");
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&mutex);
}

Table::~Table() {
    // TODO: implement table destructor (mutex, cond)
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
}