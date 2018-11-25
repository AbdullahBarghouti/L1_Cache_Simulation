/*
	ECE 485
	Travis Hermant, Alex Pinzon, Abdullah Barghouti, Ammar Khan
	This file contains the code implementation for the data cache.


*/

#include "data_cache.h"

extern struct stats Stats_Cache;
extern struct cache	Data_Cache[SETS][DATA_WAY];


//This function performs three checks,
// Checks if there is a miss, if there is then the miss will be delt
// with accordingly.
// If there is a hit, then data evict will be called.

// This function checks for a hit and takes appropriate action
int data_hit_check(int set_index, int tag_size)
{
	for(i = 0; i < DATA_WAY; i++)
	{
	// Check if the tag bits are equivalent and check if the state is valid
		if(cache_data[set_index][i].mesi != 3 && cache_data[set_index][i].TAG == tag_size)
		{
			DataUpdateLRU(set_index, i, cache_data[set_index][i].TAG, cache_data[set_index][i].LRU);
		}
		else if (i == DATA_WAY - 1)
			return 0;
	}
	return 2;


}

//This function checks for a miss and takes appropriate action
int data_miss_check(int set_index, int tag_size)
{

	for(i = 0; i < DATA_WAY; i++)
	{
		if(cache_data[set_index][i].mesi == 3)
		{
			cache_data[set_index][i].ADDRESS = address;
			cache_data[set_index][i].TAG = tag_size;
			DataUpdateLRU(set_index, i, tag_size, cache_data[set_index][i].LRU);	//lruupdate function still unsure how it works
			return 1;
		}
		if( i == DATA_WAY - 1)
		return 0;
	}
	return 2;
}

// This function checks the index and way, and clears the
// content of the cache by resetting LRU to NULL, and setting the MESI bits to invalid (3). 

void data_clear(void)
{
	int index1 = 0;	//set index
	int index2 = 0; //way index

	for(index1 = 0; index1 < DATA_SETS; index1++)
	{
		for(index2 = 0; index2 < DATA_WAY; index2++)
		{
			cache_data[index1][index2].lru = -1; //decrement LRU values
			cache_data[index1][index2].mesi = 3;	//v	
		}
	}

}

// The purpose of this function is to evict the LRU.
// Its going to check if we're in the MESI state
void data_evict_LRU(int tag_size, int idx)
{

	int index2 = 1;
	for(index2; index2 < DATA_WAY; index2++)
	{



	}

}


