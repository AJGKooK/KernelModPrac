#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char command[1024], input[1024], *parameters[20];

int main(int argc, char* argv[]){

    int errorFlagBIC;
    char* prompt = "Prompt> ";

    system("clear");

    for(;;){
        if (errorFlagBIC == 1){
            printf("Invalid user input\n");
            errorFlagBIC = 0;
        }
        printf("%s", prompt);

        if (strcmp(input, "exit" ) == 0){
            break;
        }
    }
return 0;
}