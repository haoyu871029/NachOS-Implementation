#include "philosopher.hpp"


Philosopher::Philosopher(int id, Fork *leftFork, Fork *rightFork, Table *table) :id(id), cancelled(false), leftFork(leftFork), rightFork(rightFork), table(table) {
    srand((unsigned) time(&t1));
}

void Philosopher::start() {
    // TODO: start a philosopher thread
}

int Philosopher::join() {
    // TODO: join a philosopher thread
}

int Philosopher::cancel() {
    // TODO: cancel a philosopher thread
}

void Philosopher::think() {
    int thinkTime = rand() % MAXTHINKTIME + MINTHINKTIME;
    sleep(thinkTime);
    // printf("Philosopher %d is thinking for %d seconds.\n", id, thinkTime);
}

void Philosopher::eat() {
    // printf("Philosopher %d is eating.\n", id);
    sleep(EATTIME);
}

void Philosopher::pickup(int id) {
    // TODO: implement the pickup interface, the philosopher needs to pick up the left fork first, then the right fork
}

void Philosopher::putdown(int id) {
    // TODO: implement the putdown interface, the philosopher needs to put down the left fork first, then the right fork
}

void Philosopher::enter() {
    // TODO: implement the enter interface, the philosopher needs to join the table first
}

void Philosopher::leave() {
    // TODO: implement the leave interface, the philosopher needs to let the table know that he has left
}

void* Philosopher::run(void* arg) {
    // TODO: complete the philosopher thread routine. 

    /* 
    pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL);

    while (!p->cancelled) {
        p->think();
        pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);

        p->eat();

        pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
    }
    */

    return NULL;
}