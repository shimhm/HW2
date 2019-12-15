#include <string.h>
#include <stdlib.h>
void put(const char* key, const char* value,char* arr_key[],char* arr_value[],int index)
{
	int len=strlen(key)+1;
	arr_key[index]=malloc(len*sizeof(char));
	strcpy(arr_key[index],key);

	len=strlen(value)+1;
	arr_value[index]=malloc(len*sizeof(char));
	strcpy(arr_value[index],value);
}
