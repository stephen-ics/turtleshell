#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  // Flush after every printf
  setbuf(stdout, NULL);

  // Wait for user input
  const int commandSize = 50;
  const int argumentSize = 50;
  const int inputSize = 100;

  char input[inputSize];


  while(1) {
    char exit[] = "exit 0";
    char echo[] = "echo";

    printf("$ ");
    fgets(input, inputSize, stdin);

    size_t len = strlen(input);
  
    if(len > 0 && input[len - 1] == '\n') {
      input[len - 1] = '\0';
    }

    if(strcmp(exit, input) == 0) {
      break;
    }

    char *token = strtok(input, " ");

    char command[commandSize];
    strcpy(command, token);

    char arguments[argumentSize][commandSize];
    int argumentCount = 0;

    while(token != NULL) {
      strncpy(arguments[argumentCount], token, 19);
      arguments[argumentCount][19] = '\0';
      argumentCount++;
  
      token = strtok(NULL, " ");
    }

    if(strcmp(echo, command) == 0) {
      int count = 1;

      while(arguments[count][0] != '\0') {
        printf("%s ", arguments[count]);
        count++;
      }

      printf("\n");
    }

    else {
      printf("%s: command not found \n", input);
    }
  }

  return 0;
}
