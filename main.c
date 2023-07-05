#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
#include<pthread.h>
char directory[1000];
char *var[1000]; 
int i = 0;

void *echocall(void *ptr);
void *pwdcall(void *ptr);
void *lscall(void *ptr);
void *catcall(void *ptr);
void *datecall(void *ptr);
void *mkdircall(void *ptr);
void *rmcall(void *ptr);
void *cdcall(void *ptr);


int main(){
    getcwd(directory, 1000);
    printf("starting directory: %s\n", directory);
    while(1){
        char str[1000];
        fgets(str, 1000, stdin);
        char tcmnd[1000];
        for(int j = 0; j<sizeof(str)/sizeof(str[0]); j++){
            tcmnd[j] = str[j]; 
        }
            char *cmnd = tcmnd;
            char *token;
            token = strtok(str, " ");
            while(token!=NULL){
                var[i] = token;
                token = strtok(NULL," ");
                i++;
            }
            printf("%s", cmnd);
            if(strcmp(var[0], "cd")==0  || strcmp(var[0], "cd\n")==0){
                if(i==1){
                    // printf("%s\n", getcwd(s, 100));
                    chdir("/home");
                    getcwd(directory, 1000);
                    printf("IN: %s\n", directory);
                }
                else if(i>=3){
                    // char s[100];
                    printf("var: %s\n", var[1]);
                    if(chdir(var[1])==0){
                        getcwd(directory, 1000);
                    }
                    else{
                        printf("failed to change directory");
                    }
                    printf("%s\n", directory);
                }
                // printf("cmnd : %s ", cmnd);
                // pthread_t p1;
                // pthread_create(&p1, NULL, cdcall, (void*)cmnd);
                // pthread_join(p1, NULL);
            }
            else if(strcmp(var[0], "echo")==0 || strcmp(var[0], "echo\n")==0){
                // char *cmnd = tcmnd;
                printf("cmnd : %s ", cmnd);
                pthread_t p1;
                pthread_create(&p1, NULL, echocall, (void*)cmnd);
                pthread_join(p1, NULL);
            }
            else if(strcmp(var[0], "pwd")==0 || strcmp(var[0], "pwd\n")==0){
                // char *cmnd = tcmnd;
                printf("cmnd : %s ", cmnd);
                pthread_t p1;
                pthread_create(&p1, NULL, pwdcall, (void*)cmnd);
                pthread_join(p1, NULL);
                
            }
            else if(strcmp(var[0], "ls")==0 || strcmp(var[0], "ls\n")==0){
                pthread_t p1;
                pthread_create(&p1, NULL, lscall, (void*)cmnd);
                pthread_join(p1, NULL);
                
            }
            else if(strcmp(var[0], "cat")==0 || strcmp(var[0], "cat\n")==0 ){
                
                pthread_t p1;
                pthread_create(&p1, NULL, catcall, (void*)cmnd);
                pthread_join(p1, NULL);
                printf("\n");
                
            }
            else if(strcmp(var[0], "date")==0 || strcmp(var[0], "date\n")==0 ){
               
                pthread_t p1;
                pthread_create(&p1, NULL, datecall, (void*)cmnd);
                pthread_join(p1, NULL);
            }
            else if(strcmp(var[0], "rm")==0  || strcmp(var[0], "rm\n")==0 ){
                pthread_t p1;
                pthread_create(&p1, NULL, rmcall, (void*)cmnd);
                pthread_join(p1, NULL);

            }
            else if(strcmp(var[0], "mkdir")==0 || strcmp(var[0], "mkdir\n")==0 ){
                pthread_t p1;
                pthread_create(&p1, NULL, mkdircall, (void*)cmnd);
                pthread_join(p1, NULL);                 
            }
            else{
                printf("Commmand not found- %s\n", var[0]);
            }
        }
        
    return 0;
}



void *echocall(void *ptr){
    char *action;
    action = (char *) ptr;
    // printf("%s", action);
    system(action);
    pthread_exit(0);
}


void *pwdcall(void *ptr){
    char *action;
    action = (char *) ptr;
    // printf("%s", action);
    system(action);
    pthread_exit(0);
}


void *lscall(void *ptr){
    char *action;
    action = (char *) ptr;
    printf("%s", action);
    char path1[10000] = "/home/ronit/c/Assignment1/ques/./cmdls.o";
    strcat(path1," t ");
    if(i==1 ){
        // printf("only\n");
        strcat(path1, "ls ");
        // strcat(path1, directory);
    }
    else if(i>=3){
        // printf("multi");
        strcat(path1, "ls ");
        strcat(path1, var[1]);
        strcat(path1, " ");
        // strcat(path1, directory);
    }
    system(path1);
    pthread_exit(0);
}

void *catcall(void *ptr){
    char *action;
    action = (char *) ptr;
    // printf("%s", action);
    char path1[1000] = "/home/ronit/c/Assignment1/ques/./cmdcat.o";
    strcat(path1," t ");
    // printf("%s", path1);
    strcat(path1,action);
    printf("%s", path1);
    system(path1);
    pthread_exit(0);
}

void *datecall(void *ptr){
    char *action;
    action = (char *) ptr;
    // printf("%s", action);
    char path1[1000] = "/home/ronit/c/Assignment1/ques/./cmddate.o";
    strcat(path1," t ");
    // printf("%s", path1);
    strcat(path1,action);
    // printf("%s", path1);
    system(path1);
    pthread_exit(0);
}

void *mkdircall(void *ptr){
    char *action;
    action = (char *) ptr;
    // printf("action/cmd : %s", action);
    char path1[1000] = "/home/ronit/c/Assignment1/ques/./cmdmkdir.o";
    strcat(path1," t ");
    // printf("%s", path1);
    strcat(path1,action);
    printf("%s", path1);
    system(path1);
    pthread_exit(0);
}


void *rmcall(void *ptr){
    char *action;
    action = (char *) ptr;
    // printf("action/cmd : %s", action);
    char path1[1000] = "/home/ronit/c/Assignment1/ques/./cmdrm.o";
    strcat(path1," t ");
    // printf("%s", path1);
    strcat(path1,action);
    // printf("rm: %s", path1);
    system(path1);
    pthread_exit(0);
}

