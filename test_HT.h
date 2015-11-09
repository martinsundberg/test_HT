#include <iostream>
#include <pthread.h>
#include <sys/time.h>
#include "set_options.cpp"
#define ARRAY_SIZE 1000*1000*1000
#define UPPER_LIMIT 1000*1000
#define NUM_THREADS_NO_HT 4
#define NUM_THREADS_HT 8
#define MOD 100
using namespace std;


struct options{
	int mod;
	int start;
	int stop;
	int cache_size;
};
