#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>

int errorFlagBIC = 0;
void user_input(char input[], char *parameters[]){
    int count = 0, i=0, j=0, c=0;
    char character[1024];
    char *array[100], *token;

    // Read line  (Dumps core immediately)

    for(;;){
        c = fgetc(stdin);           // Reads one character of user input
        character[count++]=c;       // Assigns that character to a point in the array
        if (c=='\n') break;         // Breaks when it sees enter
    }
    token = strtok(character,"\n"); // Store token
    if (count==1) return;           // If line is empty, return

    // Parse the line into words  (Dumps core after first command)

    while(token != NULL){
        array[i++] = strdup(token);
        token = strtok (NULL, "\n");
    }

    // First word is the command  (Doesn't do anything with command, doesn't return value)
    strcpy(input,array[0]);

    // Others are parameters  (No effect, deals with second parameter)
    for (int j=0; j < i, j++;)
    parameters[j] = array[j];
    parameters[i] = NULL;  // NULL-terminate the parameter list
}

 void builtin_commands(char input[]){
    int inputLength = strlen(input);
    char delimiter[] = " ";
    char *inputCopy = (char*) calloc(inputLength + 1, sizeof(char));
    char *firstWord, *secondWord, *context;
    char cwd[1024];

    DIR *dirp;
    struct dirent *dp;

     // Exit defined in main.c

     strncpy(inputCopy, input, inputLength);
     firstWord = strtok_r(inputCopy, delimiter, &context);
     secondWord = strtok_r(NULL, delimiter, &context);

    system("clear");
    if (strcmp(firstWord, "cd") == 0){
        if (secondWord == NULL){
            chdir("..");
            getcwd(cwd, sizeof(cwd));
            dirp=opendir(cwd);
            while ((dp = readdir(dirp))) {
                puts(dp->d_name);
            }
            
        }
        else if (chdir (secondWord) != 0)
            perror("cd failure");
        else{
            chdir(secondWord);
            getcwd(cwd, sizeof(cwd));
            dirp=opendir(cwd);
            while ((dp = readdir(dirp))) {
                puts(dp->d_name);
            }
        }
    }
    else{
        errorFlagBIC = 1;
    }
    printf("\n\n");

 }