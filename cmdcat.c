#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>


int main(int argc, char **argv){
    if(strcmp(argv[0], "f")==0){
        char *bin = "/bin/cat";
        // char dir[] = argv[0];
        
        // printf("%d\n", argc);
        // printf("%s\n", argv[0]);
        char *str = argv[0];
        if(strcmp(str, "f")==0){
            if(argc==2){
            execl(bin, "cat", argv[1], NULL);
            }
            else if(argc==3){
            // printf("%s\n", argv[0]);
                
                execl(bin,"cat" ,argv[1], argv[2], NULL); 
            }
        }
        else{
            system(argv[1]);
        } 
    }
    else{
        char action[]="";
        for(int i = 2; i<argc; i++){
            printf("%s\n", argv[i]);
            strcat(action, argv[i]);
            strcat(action, " ");
        }
        printf("%s\n", action);
        system(action);
    }
    return 0;
}