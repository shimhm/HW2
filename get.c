#include <string.h>
int get(const char* key,char* arr_key[],int counter)
{
	for(int i=0;i<counter;i++){
		int res=strcmp(key,arr_key[i]);
		if(res==0){
			return i;
		}
	}
	return -1;
}
