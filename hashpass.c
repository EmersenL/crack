#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "md5.h"

int main(int argc, char *argv[])
{
    // Check how many filenames user supplied.
    // If not enough, error message and exit.
    if (argc < 3)
    {
        printf("You need to supply two filenames\n");
        exit(1);
    }
    
    // Check if output file is the same as input file
    if (strcmp(argv[1], argv[2]) == 0)
    {
        printf("Output file is same as input file\n");
        exit(1);
    }
    
    // open first file for reading
    FILE *in = fopen(argv[1], "r");
    if (!in)
    {
        printf("Can't open %s for reading\n", argv[1]);
        exit(1);
    }
    
    // Open second file for writing
    FILE *out = fopen(argv[2], "w");
    if (!out)
    {
        printf("Can't open %s for writing\n", argv[2]);
        exit(1);
    }
    
    // Loop through first file, one line at a time
    char line[15];
    while(fgets(line, 15, in) != NULL)
    {
        line[strlen(line) - 1] = 0;
        char *hash = md5(line, strlen(line));
        fprintf(out, "%s\n", hash);
        free(hash);
    }
        
    // Close both files
    fclose(in);
    fclose(out);
}