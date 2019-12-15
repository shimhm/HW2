#include <stdlib.h>
#include <string.h>
void close(char* arr_key[],char* arr_value[],int counter)
{
	for(int i=0;i<counter;i++){
		int len=strlen(arr_key[i]);
		for(int j=0;j<=len;j++){
			free(&arr_key[i][j]);
		}
		len=strlen(arr_value[i]);
		for(int j=0;j<=len;j++){
			free(&arr_value[i][j]);
		}
	}
}
