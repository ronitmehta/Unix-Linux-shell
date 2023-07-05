#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>


int main(int argc, char **argv){
    char *bin = "/bin/date";
    // char dir[] = argv[0];
    
    // printf("%d\n", argc);
    // printf("%s\n", argv[0]);

    if(strcmp(argv[0], "f")==0){
        if(argc==1){
        execl(bin, "date", NULL);
        }
        if(argc==2){
            execl(bin,"date" ,argv[1],  NULL); 

        }
        else if(argc==3){
            execl(bin,"date" ,argv[1], argv[2], NULL); 
        }
    }
    else{
        // system(argv[1]);
        char action[]="";
        for(int i = 2; i<argc; i++){
            // printf("%s\n", argv[i]);
            strcat(action, argv[i]);
            strcat(action, " ");
        }
        // printf("%s\n", action);
        system(action);
    }
    // else if(argc==3){
    //     execl(bin,  b, arg1, arg2, NULL);
    // }
    return 0;
}