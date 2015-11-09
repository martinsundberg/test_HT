#include "test_HT.h"

options* set_opts(){
	options *option = (options*)malloc(sizeof(options)*(NUM_THREADS_NO_HT+NUM_THREADS_HT));
	// mem bound no ht
	option[0].mod   = MOD;
	option[0].start = 0;
	option[0].stop  = ARRAY_SIZE;
	option[1].mod   = MOD;
	option[1].start = 1;
	option[1].stop  = ARRAY_SIZE;
	option[2].mod   = MOD;
	option[2].start = 2;
	option[2].stop  = ARRAY_SIZE;
	option[3].mod   = MOD;
	option[3].start = 3;
	option[3].stop  = ARRAY_SIZE; 
	option[4].mod   = MOD*2;
	option[4].start = 0;
	option[4].stop  = ARRAY_SIZE;
	option[5].mod   = MOD*2;
	option[5].start = 1;
	option[5].stop  = ARRAY_SIZE;
	option[6].mod   = MOD*2;
	option[6].start = 2;
	option[6].stop  = ARRAY_SIZE;
	option[7].mod   = MOD*2;
	option[7].start = 3;
	option[7].stop  = ARRAY_SIZE; 
	option[8].mod   = MOD*2;
	option[8].start = 5;
	option[8].stop  = ARRAY_SIZE;
	option[9].mod   = MOD*2;
	option[9].start = 7;
	option[9].stop  = ARRAY_SIZE;
	option[10].mod   = MOD*2;
	option[10].start = 11;
	option[10].stop  = ARRAY_SIZE;
	option[11].mod   = MOD*2;
	option[11].start = 13;
	option[11].stop  = ARRAY_SIZE; 

	return option;
}