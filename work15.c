#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <dirent.h>

#define COMMAND_LINE_INVOCATION "ls -a -l"

// ============================================================================

int spaceCounter(char * str) {

  int numSpaces = 0;

  int i = 0;
  while (str[i]) {
    if (str[i] == ' ') numSpaces++;
    i++;
  }

  return numSpaces;

}

// ============================================================================

char ** parse_args(char * line) {

  char * c;
  char ** ret = malloc(spaceCounter(line) * sizeof(c));

  int i = 0;
  while (line) {
    ret[i] = strsep(&line, " ");
    i++;
  }

  return ret;

}

// ============================================================================

int main() {

  char line[100] = COMMAND_LINE_INVOCATION;
  char ** args = parse_args( line );

  printf("\n$ %s\n\n", COMMAND_LINE_INVOCATION);

  execvp(args[0], args);

  return 0;

}
