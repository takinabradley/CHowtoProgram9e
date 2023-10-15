#include <stdio.h>

int main(void) {
  int size = 0;
  puts("Please enter a square size");
  scanf("%d", &size);

  // loop `size` times to create `size` amount of lines.
  for(int i = 0; i < size; i++) {

    if(i == 0 || i == size - 1) {
      // if it's the top or bottom line
      // print a line of length `size` consisting of all '*' characters on the current line
      for(int j = 0; j < size; j++) {
        printf("%c", '*');
      }
    } else if (i > 0 && i < size - 1) {
      // if not the top or bottom line
      // print a line of length `size` with only first and last character being '*'
      for(int j = 0; j < size; j++) {
        if(j == 0 || j == size - 1) {
          printf("%c", '*');
        } else {
          printf("%c", ' ');
        }
      }
    }

    // follow each line with a newline
    puts("");
  }
}