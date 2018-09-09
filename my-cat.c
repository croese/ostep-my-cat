#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 512

void print_file(const char* filename)
{
  FILE* fd = fopen(filename, "r");
  if (!fd) {
    perror("fopen");
    exit(1);
  }

  char buffer[BUFSIZE];

  while (fgets(buffer, BUFSIZE, fd)) {
    printf("%s", buffer);
  }

  if (ferror(fd)) {
    perror("file stream error");
    fclose(fd);
    exit(1);
  }

  fclose(fd);
}

int main(int argc, char** argv)
{
  if (argc < 2) {
    printf("USAGE: %s <file> [files..]\n", argv[0]);
    exit(1);
  }

  for (int i = 1; i < argc; i++) {
    print_file(argv[i]);
  }

  return 0;
}
