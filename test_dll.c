#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dlfcn.h>
char *arr_key[100];
char *arr_value[100];
int main(int argc, char *argv[])
{
	void *handle;
	void (*func_put)(const char*val1,const char* val2,char* arr1[],char* arr2[],int index);
	int (*func_get)(const char*val,char* arr[],int counter);
        char* error;
	char key[16];
        char value[99];
        int counter=0;
        int index;
        FILE* fp_put;
        FILE* fp_get;
        FILE* fp_result;
	handle=dlopen("./dll.so",RTLD_LAZY);
	if(!handle){
		fprintf(stderr,"%s\n",dlerror());
		exit(1);
	}
	func_put=dlsym(handle,"put");
	if((error=dlerror())!=NULL){
		fprintf(stderr,"%s\n",error);
		exit(1);
	}
	fuc_get=dlsym(handle,"get");
	if((error=dlerror())!=NULL){
		fprintf(stderr,"%s\n",error);
		exit(1);
	}

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
                func_put(key,value,arr_key,arr_value,counter);
                counter++;
        }

        fp_result=fopen(argv[3],"w");
        if(fp_result==NULL){
                printf("fopen Error\n");
                return 0;
	}
        while(!feof(fp_get)){
                fscanf(fp_get,"%s\n",key);
                index=func_get(key,arr_key,counter);
                if(index!=-1){
                        printf("%s\n",arr_value[index]);
                        fputs(arr_value[index],fp_result);
                        fputs("\n",fp_result);
                }
        }
	if(dlclose(handle)<0){
		fprintf(stderr,"%s\n",dlerror());
		exit(1);
	}
        fclose(fp_put);
        fclose(fp_get);
        fclose(fp_result);
        return 0;
}

    
