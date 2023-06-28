#include "fork.hpp"

//實作 mutex 來避免筷子被同時取

Fork::Fork() {
    // TODO: implement fork constructor (value, mutex, cond)
    value = 1;
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);
}

//use the pthread mutex lock and condition variable to implement the mutex.
void Fork::wait() {
    // TODO: implement semaphore wait
    //If the fork is taken, it will send a wait to the other philosopher who wants to pick up
    //If the fork is free, the philosopher can just pick up the fork.
    
    pthread_mutex_lock(&mutex);
    while (value == 0) {
        //printf("Fork is taken.\n");
        pthread_cond_wait(&cond, &mutex);
    }
    //printf("Fork is free.\n");
    value = 0;
    pthread_mutex_unlock(&mutex);
}

void Fork::signal() {
    // TODO: implement semaphore signal
    //signal the other philosopher when the fork is released.
    
    pthread_mutex_lock(&mutex);
    value = 1;
    //printf("Fork is released.\n");
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&mutex);
}

Fork::~Fork() {
    // TODO: implement fork destructor (mutex, cond)
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
}