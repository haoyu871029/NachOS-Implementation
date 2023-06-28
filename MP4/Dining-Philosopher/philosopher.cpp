#include "philosopher.hpp"

Philosopher::Philosopher(int id, Fork *leftFork, Fork *rightFork, Table *table) :id(id), cancelled(false), leftFork(leftFork), rightFork(rightFork), table(table) {
    srand((unsigned) time(&t1));
}

void Philosopher::start() {
    // TODO: start a philosopher thread
    printf("Philosopher %d is starting.\n", id);
    pthread_create(&t, NULL, run, this);
}

int Philosopher::join() {
    // TODO: join a philosopher thread
    printf("Philosopher %d has joined.\n", id);
    return pthread_join(t, NULL);
}

int Philosopher::cancel() {
    // TODO: cancel a philosopher thread
    cancelled = true;
    printf("Philosopher %d has been cancelled.\n", id);
    return pthread_cancel(t);
}

//在吃或想
void Philosopher::think() {
    int thinkTime = rand() % MAXTHINKTIME + MINTHINKTIME;
    //printf("Philosopher %d is thinking for %d seconds.\n", id, thinkTime);
    sleep(thinkTime);
}

void Philosopher::eat() {
    //printf("Philosopher %d is eating.\n", id);
    sleep(EATTIME);
}

//拿放叉子
void Philosopher::pickup(int id) {
    // TODO: implement the pickup interface, 
    // the philosopher needs to pick up the left fork first, then the right fork
    leftFork->wait();
    rightFork->wait();
}

void Philosopher::putdown(int id) {
    // TODO: implement the putdown interface, 
    // the philosopher needs to put down the left fork first, then the right fork
    leftFork->signal();
    rightFork->signal();
}

//進出桌子
void Philosopher::enter() {
    // TODO: implement the enter interface, 
    // the philosopher needs to join the table first
    table->wait();
}

void Philosopher::leave() {
    // TODO: implement the leave interface, 
    // the philosopher needs to let the table know that he has left
    table->signal();
}

void* Philosopher::run(void* arg) {
    // TODO: complete the philosopher thread routine. 
    //runs in a loop that philosopher alternates between thinking and eating. 

    Philosopher* p = (Philosopher*) arg;
 
    pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL);
    //取消類型被設置為 PTHREAD_CANCEL_DEFERRED
    //意味著取消請求會在線程達到某個取消點時才會生效

    while (!p->cancelled) {
        //如果沒有被取消，就一直吃和想
        p->think();
        
        pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);
        p->enter();
        p->pickup(p->id);
        p->eat();
        p->putdown(p->id);
        p->leave();
        pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
    }

    return NULL;
}