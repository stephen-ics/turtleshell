#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  // Flush after every printf
  setbuf(stdout, NULL);

  char *fullPath = getenv("PATH");
  char copyPath[strlen(fullPath) + 1];

  strcpy(copyPath, fullPath);

  char* pathPointer = strtok(copyPath, ":");
  char path[strlen(fullPath) + 1];

  strcpy(path, pathPointer);

  // Wait for user input
  const int commandSize = 100;
  const int argumentSize = 100;
  const int inputSize = 100;

  char input[inputSize];

  while(1) {
    char exit[] = "exit 0";
    char echo[] = "echo";
    char type[] = "type";

    char commandList[][50] = {"exit", "type", "echo", "ls"};
    int commandListLength = sizeof(commandList) / sizeof(commandList[0]);

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
      strncpy(arguments[argumentCount], token, 99);
      arguments[argumentCount][99] = '\0';
      argumentCount++;
  
      token = strtok(NULL, " ");
    }

    if (strcmp(echo, command) == 0) {
        for (int i = 1; i < argumentCount; i++) {
            printf("%s ", arguments[i]);
        }
        printf("\n");
    }

    else if (strcmp(type, command) == 0) {

      for(int i = 1; i < argumentCount; i++) {
        int found = 1;

        char arg[50];
        strcpy(arg, arguments[i]);

        for(int j = 0; j < commandListLength; j++) {
          if(strcmp(commandList[j], arg) == 0) {
            printf("%s is %s/%s", arg, path, arg);
            found = 0;
            break;
          }
        }

        if(found == 1) {
          printf("%s: not found\n", arg);
        }
      }
    }

    else {
      printf("%s: command not found \n", input);
    }
  }

  return 0;
}
