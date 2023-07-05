#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>


int main(){
    char directory[1000];
    getcwd(directory, 1000);
    printf("%s\n", directory);
    while(1){
        char str[10000];
        fgets(str, 10000, stdin);
        // if(fork()==0){
            char *token;
            int i = 0;
            char *var[1000]; 
            token = strtok(str, " ");
            while(token!=NULL){
                var[i] = token;
                token = strtok(NULL," ");
                i++;
            }
            if(strcmp(var[0], "cd")==0  || strcmp(var[0], "cd\n")==0){
                if(i==1){
                    // printf("%s\n", getcwd(s, 100));
                    chdir("/home");
                    getcwd(directory, 100);
                    printf("IN: %s\n", directory);
                }
                else if(i==3){
                    // char s[100];
                    // printf("%s\n", getcwd(s, 100));
                    chdir(var[1]);
                    getcwd(directory, 100);
                    printf("%s\n", directory);
                }
            }
            else if(strcmp(var[0], "echo")==0 || strcmp(var[0], "echo\n")==0){
                // printf("echo");
                // printf("%d\n", i);
                if(fork()==0){
                    if(i==3){
                        // printf("%s\n", var[1]);
                        execl("/bin/echo", "echo", var[1], NULL);
                    }
                    else if(i==4){
                        execl("/bin/echo", "echo",var[1], var[2], NULL);
                    }
                }
                else{
                    wait(NULL);
                }
            }
            else if(strcmp(var[0], "pwd")==0 || strcmp(var[0], "pwd\n")==0){
                if(fork()==0){
                    if(i==2){
                        // printf("%s\n", var[1]);
                        execl("/bin/pwd", "pwd", NULL);
                    }
                    else if(i==3){
                        execl("/bin/pwd", "pwd",var[1], NULL);
                    }
                }
                else{
                    wait(NULL);
                }
                
            }
            else if(strcmp(var[0], "ls")==0 || strcmp(var[0], "ls\n")==0){
                char *path = "/home/ronit/c/Assignment1/ques/./cmdls.o";
                if(i==2){
                    if(fork()==0){
                        execl(path,"f" ,directory, var[1]);
                    }
                    else{
                        wait(NULL);
                    }
                }
                else if(i==3){
                    if(fork()==0){
                        execl(path,"f" ,directory, var[1], var[2]);
                    }
                    else{
                        wait(NULL);
                    }
                }
                else{
                    if(fork()==0){
                        execl(path, "f",directory, NULL);
                    }
                    else{
                        wait(NULL);
                    }
                }
                
            }
            else if(strcmp(var[0], "cat")==0 || strcmp(var[0], "cat\n")==0 ){
                // printf("cat");
                if(fork()==0){
                    char *path1 = "/home/ronit/c/Assignment1/ques/./cmdcat.o";
                    if(i==3){
                        char * fileName= var[1];
                        execl(path1, "f", fileName, NULL);
                    }
                    else if(i==4){
                        char *fun = var[1];
                        char *fileName = var[2];
                        execl(path1,"f",fileName, fun, NULL);
                    }
                }
                else{
                    wait(NULL);
                }
                printf("\n");
            }
            else if(strcmp(var[0], "date")==0 || strcmp(var[0], "date\n")==0 ){
                // printf("date");
                char *path1 = "/home/ronit/c/Assignment1/ques/./cmddate.o";
                printf("%d\n", i);
                if(i==4){
                    if(fork()==0){
                        char *fun = var[1];
                        char *name=var[2];
                        execl(path1, "f", name, fun, NULL);
                    }
                    else{
                        wait(NULL);
                    }
                }
                if(i==3){
                    if(fork()==0){
                        char *fun = var[1];
                        // char *name=var[2];
                        execl(path1,"f",fun, NULL);
                    }
                    else{
                        wait(NULL);
                    }
                }
                else if(i==1) {
                    if(fork()==0){
                        execl(path1, "f", NULL);
                    }
                    else{
                        wait(NULL);
                    }
                }
            }
            else if(strcmp(var[0], "rm")==0  || strcmp(var[0], "rm\n")==0 ){
                // printf("rm");
                char *path1 = "/home/ronit/c/Assignment1/ques/./cmdrm.o";
                printf("%d\n", i);
                if(i==4){
                    if(fork()==0){
                        char *fun = var[1];
                        char *name=var[2];
                        execl(path1,"f",name, fun, NULL);
                    }
                    else{
                        wait(NULL);
                    }
                }
                else if(i==3) {
                    if(fork()==0){
                        char *name = var[1];
                        execl(path1,"f",name, NULL);
                    }
                    else{
                        wait(NULL);
                    }
                }

            }
            else if(strcmp(var[0], "mkdir")==0 || strcmp(var[0], "mkdir\n")==0 ){
                char *path1 = "/home/ronit/c/Assignment1/ques/./cmdmkdir.o";
                printf("%d\n", i);
                if(i==4){
                    if(fork()==0){
                        char *fun = var[1];
                        char name[1000];
                        printf("%s\n",var[2]);
                        memcpy( &name, var[2], sizeof(var[2])*4);
                        char to[1000];
                        memcpy(&to, &directory, sizeof(directory));
                        strcat(to, "/");
                        strcat(to,name);
                        execl(path1,"f",to, fun, NULL);
                    }
                    else{
                        wait(NULL);
                    }
                }
                else if(i==3) {
                    if(fork()==0){
                        char name[1000];
                        memcpy( &name, var[1], sizeof(var[1])*4);
                        char to[1000];
                        memcpy(&to, &directory, sizeof(directory));
                        strcat(to, "/");
                        strcat(to,name);

                        execl(path1,"f",to, NULL);
                    }
                    else{
                        wait(NULL);
                    }
                }
            }
            else{
                printf("Commmand not found- %s\n", var[0]);
            }
        }
        
    return 0;
}