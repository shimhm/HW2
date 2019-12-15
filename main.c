#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void put(const char* key, const char* value,char* arr_key[],char* arr_value[],int index);
int get(const char* key,char* arr_key[],int counter);
void open();
void close(char* arr_key[],char* arr_value[]);
char *arr_key[100];
char *arr_value[100];
int main(int argc, char *argv[])
{
        //char filename_put[]=argv[1];
        //char filename_get[]=argv[2];
	//char filename_result[]=argv[3];
        char key[99];
        char value[99];
        int counter=0;
        int index;
        FILE* fp_put;
        FILE* fp_get;
        FILE* fp_result;
        fp_put=fopen(argv[1],"r");
        if(fp_put==NULL){
                printf("fopen Error\n");
                return 0;
        }

        fp_get=fopen(argv[2],"r");
        if(fp_get==NULL){
                printf("fopen Error\n");
                return 0;
        }
        while(!feof(fp_put)){
                fscanf(fp_put,"%s %s\n",key,value);
                put(key,value,arr_key,arr_value,counter);
                counter++;
        }

        fp_result=fopen(argv[3],"w");
        if(fp_result==NULL){
                printf("fopen Error\n");
                return 0;
        }
        while(!feof(fp_get)){
                fscanf(fp_get,"%s\n",key);
                index=get(key,arr_key,counter);
                if(index!=-1){
                        printf("%s\n",arr_value[index]);
                        fputs(arr_value[index],fp_result);
                        fputs("\n",fp_result);
                }
        }
        fclose(fp_put);
        fclose(fp_get);
        fclose(fp_result);
        return 0;
}

