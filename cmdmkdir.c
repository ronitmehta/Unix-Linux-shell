#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char **argv){
    if(strcmp(argv[0], "f")==0){
        char *bin = "/bin/mkdir";
        // char dir[] = argv[0];
        
        // printf("%d\n", argc);
        // printf("%s\n", argv[0]);

        if(argc==2){
            execl(bin, "mkdir", argv[1], NULL);
        }
        else if(argc==3){
            execl(bin,"mkdir" ,argv[1], argv[2], NULL); 
        }
    }
    else{
        char action[]="";
        // printf("hello");
        for(int i = 2; i<argc; i++){
            // printf("%s\n", argv[i]);
            strcat(action, argv[i]);
            strcat(action, " ");
        }
        printf("aaction: %s\n", action);
        system(action);
    }
    // else if(argc==3){
    //     execl(bin,  b, arg1, arg2, NULL);
    // }
    return 0;
}