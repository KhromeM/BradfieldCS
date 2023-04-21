#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/resource.h>
#include <sys/time.h>

#define SLEEP_SEC 3
#define NUM_MULS 100000000
#define NUM_MALLOCS 100000
#define MALLOC_SIZE 1000

// TODO define this struct
struct profile_times {
  int id;
  struct timeval user;
  struct timeval system;
  struct timeval total;
};

// TODO populate the given struct with starting information
void profile_start(struct profile_times *t) {
  t->id = (int) getpid();
  struct rusage r;
  getrusage(RUSAGE_SELF, &r);
  t->user = r.ru_utime;
  t->system = r.ru_stime;
  struct timeval tp;
  gettimeofday(&tp,NULL);
  t->total = tp;
}


void profile_log(struct profile_times *t) {
  struct rusage r;
  getrusage(RUSAGE_SELF, &r);
  struct timeval tp;
  gettimeofday(&tp,NULL);
  

  float d_user = (r.ru_utime.tv_sec - t->user.tv_sec) + (r.ru_utime.tv_usec - t->user.tv_usec) * .000001;
  float d_system = (r.ru_stime.tv_sec - t->system.tv_sec) + (r.ru_stime.tv_usec - t->system.tv_usec) * .000001;
  float d_total = (tp.tv_sec - t->total.tv_sec) + (tp.tv_usec - t->total.tv_usec) *  .000001;

  t->total = tp;
  t->user = r.ru_utime;
  t->system = r.ru_stime;


  printf("PID: %d User Time: %.2fms System Time: %.2fms Total Time: %.2fms\n",t->id,d_user,d_system, d_total);
}

int main(int argc, char *argv[]) {
  struct profile_times t;

  // TODO profile doing a bunch of floating point muls
  float x = 1.0;
  profile_start(&t);
  for (int i = 0; i < NUM_MULS; i++)
    x *= 1.1;
  profile_log(&t);

  // TODO profile doing a bunch of mallocs
  profile_start(&t);
  void *p;
  for (int i = 0; i < NUM_MALLOCS; i++)
    p = malloc(MALLOC_SIZE);
  profile_log(&t);

  // TODO profile sleeping
  profile_start(&t);
  sleep(SLEEP_SEC);
  profile_log(&t);
}
