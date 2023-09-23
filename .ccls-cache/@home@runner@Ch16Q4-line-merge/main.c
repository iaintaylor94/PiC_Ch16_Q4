// Program to merge two files

#include <stdio.h>
#include <stdbool.h>

int main(void) {

  char in1[64], in2[64], out[64];
  FILE *file1, *file2, *outFile;
  
  // Get file names from the terminal
  printf ("Enter the name of the first file: ");
  scanf ("%63s", in1);
  printf ("Enter the name of the second file: ");
  scanf ("%63s", in2);
  printf ("Enter the name of the output file: ");
  scanf ("%63s", out);

  // Open files
  if ( (file1 = fopen(in1, "r")) == NULL) {
    printf ("Can't open %s for reading\n", in1);
    return 1;
  }
  if ( (file2 = fopen(in2, "r")) == NULL) {
    printf ("Can't open %s for reading\n", in2);
    return 2;
  }
  if ( (outFile = fopen(out, "w")) == NULL) {
    printf ("Can't open %s for writing\n", out);
    return 3;
  }

  // Merge files
  bool end1 = false;
  bool end2 = false;
  char temp[64];
  
  while (!(end1 && end2)) {
    if (end1 == false) {
      fgets (temp, 64, file1);
      fputs (temp, outFile);
      if (feof(file1)) {
        if (end1 == false)
          fputc ('\n', outFile);
        end1 = true;
      }
    }
    if (end2 == false) {
      fgets (temp, 64, file2);
      fputs (temp, outFile);
      if (feof(file2)) {
        if (end2 == false)
          fputc ('\n', outFile);
        end2 = true;
      }
    }
  }

  // Close files
  fclose (file1);
  fclose (file2);
  fclose (outFile);

  printf ("Files have been merged\n");
  
  return 0;
}