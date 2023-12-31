#include "philosopher.hpp"

#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv) {
// TODO: create forks, table, and philosophers. 
    // The number of forks and philosophers are defined in the config.hpp
    
    //create forks
    Fork *f[PHILOSOPHERS];
    for (int i = 0; i < PHILOSOPHERS; i++) {
        f[i] = new Fork();
    }

    //create table
    Table *table = new Table(PHILOSOPHERS);

    //create philosophers
    Philosopher* philosophers[PHILOSOPHERS];
    for (int i = 0; i < PHILOSOPHERS; i++) {
        philosophers[i] = new Philosopher(i, f[i], f[(i + 1) % PHILOSOPHERS], table);
                            //Philosopher(int id, Fork *leftFork, Fork *rightFork, Table *table);
    }

// TODO: start running philosopher threads
    for (int i = 0; i < PHILOSOPHERS; i++) {
        philosophers[i]->start();
    }

    sleep(RUNTIME);

// TODO: cancel philosopher threads 
    //send termination signals to all philosophers after running a period of time
    for (int i = 0; i < PHILOSOPHERS; i++) {
        philosophers[i]->cancel();
    }
    printf("All philosophers have been cancelled.\n");

// TODO: join philosopher threads (i.e. wait for them to finish) 
    for (int i = 0; i < PHILOSOPHERS; i++) {
        philosophers[i]->join();
    }

// TODO: delete forks, table, and philosophers
    for (int i = 0; i < PHILOSOPHERS; i++) {
        delete philosophers[i];
        delete f[i];
    }
    delete table;
      
    return 0;
}