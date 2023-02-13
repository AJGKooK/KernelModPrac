#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>

int main(){
    char cwd[1024], command[1024], parameter[1024];
    system("clear");

    for(;;){
        getcwd(cwd, sizeof(cwd));
        printf("\n\nC:%s> ", cwd);
        scanf("%s %s", command, parameter);
        system("clear");
        DIR *derp;
        struct dirent *dp;

        if (strcmp(command, "cd") == 0){
            chdir(parameter);
            getcwd(cwd, sizeof(cwd));
            derp=opendir(cwd);
            while ((dp = readdir(derp))) {
                puts(dp->d_name);
            }
        }
    }

return 0;
}