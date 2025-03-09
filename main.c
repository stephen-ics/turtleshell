#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  setbuf(stdout, NULL);

  // Wait for user input
  char input[100];

  while(1) {
    printf("$ ");
    fgets(input, 100, stdin);

    size_t len = strlen(input);
    if(len > 0 && input[len - 1] == '\n') {
      input[len - 1] = '\0';
    }

    printf("%s: command not found \n", input);
  }

  return 0;
}
