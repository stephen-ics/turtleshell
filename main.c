#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  // Flush after every printf
  setbuf(stdout, NULL);

  // Uncomment this block to pass the first stages

  // Wait for user input
  char input[100];

  while(1) {
    printf("$ ");
    fgets(input, 100, stdin);

    size_t len = strlen(input);
    if(len > 0 && input[len - 1] == '\n') {
      input[len - 1] = '\0';
    }

    if(strcmp("exit 0", input)) {
      break;
    }

    printf("%s: command not found \n", input);
  }

  return 0;
}
