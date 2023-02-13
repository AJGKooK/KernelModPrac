#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

void user_input(char command[], char *command_parameter[]);
void builtin_commands(char input[]);
char command[1024], input[1024], *parameters[20], cwd[1024];
char* prompt = "/Prompt";

int main(int argc, char* argv[]){

    int errorFlagBIC;
    
    system("clear");

    for(;;){
        if (errorFlagBIC == 1){
            printf("Invalid user input\n");
            errorFlagBIC = 0;
        }
        getcwd(cwd, sizeof(cwd));
        printf("C:%s> ", cwd);

        user_input (input, parameters); // Take input
        builtin_commands (input);       // Run built-in commands

        if (strcmp(input, "exit" ) == 0){
            system("clear");
            break;
        }
    }
return 0;
}