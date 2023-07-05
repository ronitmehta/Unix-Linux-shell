#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char **argv){
    // printf("im1: %s", argv[0]);
    if(strcmp(argv[0], "f")==0){
        char *bin = "/bin/ls";
        char *b = argv[1];
        
        printf("%d\n", argc);
        // printf("%s\n", argv[0]);

        if(argc==2){
            execl(bin, "ls", b, NULL);
        }
        else if(argc==3){
            if(strcmp(argv[2], "-a\n")==0 || strcmp(argv[2], "-a")==0){
                execl(bin,  b, "-a", NULL);
            }
            else if(strcmp(argv[2], "-s\n")==0 || strcmp(argv[2], "-s")==0){
                execl(bin,  b, "-s", NULL);
            }
        }
        else if(argc>=4){
            execl(bin,  b, "-a", "-s", NULL);
        }
    }
    else{
        char action[] = "";
        // printf("hello");
        for(int i = 2; i<argc; i++){
            // printf("%s\n", argv[i]);
            strcat(action, argv[i]);
            strcat(action, " ");
        }
        printf("aaction: %s\n", action);
        system(action);
    }
    return 0;
}