#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  // Flush after every printf
  setbuf(stdout, NULL);

  // Wait for user input
  char input[100];

  while(1) {
    printf("$ ");
    fgets(input, 100, stdin);

    char exit[] = "exit 0";

    size_t len = strlen(input);
    if(len > 0 && input[len - 1] == '\n') {
      input[len - 1] = '\0';
    }

    if(strcmp(exit, input) == 0) {
      break;
    }

    printf("%s: command not found \n", input);
  }

  return 0;
}
