#include "test_HT.h"
static int* array;

void *mem_bound(void *_option){
	struct options *option;
	option = (struct options*) _option;
	int mod   = option->mod;
	int start = option->start;
	int stop  = option->stop;
	for(int i = start; i < stop; i += mod) 
		array[i] += 1;
	pthread_exit(NULL);
}

void *cpu_bound(void *_option){
	struct options *option;
	option = (struct options*) _option;
	int start = option->start;
	int stop  = option->stop;
	int cache_size = option->cache_size;
	for(int i = 0; i < stop; i++)
		for(int j = start; j < start + cache_size; j++)
			array[j] += 1;
	pthread_exit(NULL);
}

int main() {
	int rc;
	pthread_t threads[NUM_THREADS_HT];
	options *option;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
   	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
   	struct timeval start, stop;
   	double runtime[4];

	/* CREATE ARRAY */
	array = (int*) malloc(sizeof(int*)*ARRAY_SIZE);
	for(int i = 0; i < ARRAY_SIZE; i++) 
		array[i] = 0;

	/* SET OPTIONS */
	option = set_opts();

	/* MEMORY BOUND NO HT */
	gettimeofday(&start, NULL);
	for(int i = 0; i < NUM_THREADS_NO_HT; i++){
		rc = pthread_create(&threads[i], NULL, mem_bound, (void*)&option[i]);

		if(rc){
			cout << "Error:unable to create thread," << rc << endl;
         	exit(-1);
		}
	}
	for(int i = 0; i < NUM_THREADS_NO_HT; i++)
		pthread_join(threads[i], NULL);
	gettimeofday(&stop, NULL);
	runtime[0] = double(stop.tv_sec)*1000.0f + double(stop.tv_usec)/1000.0f - double(start.tv_sec)*1000.0f - double(start.tv_usec)/1000.0f;

	/* MEMORY BOUND WITH HT */
	gettimeofday(&start, NULL);
	for(int i = 0; i < NUM_THREADS_HT; i++){
		rc = pthread_create(&threads[i], NULL, mem_bound, (void*)&option[i+4]);

		if(rc){
			cout << "Error:unable to create thread," << rc << endl;
         	exit(-1);
		}
	}
	for(int i = 0; i < NUM_THREADS_HT; i++)
		pthread_join(threads[i], NULL);
	gettimeofday(&stop, NULL);
	runtime[1] = double(stop.tv_sec)*1000.0f + double(stop.tv_usec)/1000.0f - double(start.tv_sec)*1000.0f - double(start.tv_usec)/1000.0f;

	cout << "no ht: " << runtime[0] << " with ht: " << runtime[1] << endl;

	/* KILL ALL */
	pthread_attr_destroy(&attr);
}


















