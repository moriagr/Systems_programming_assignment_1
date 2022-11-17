#include "NumClass.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <dirent.h>
#include "advancedClassificationLoop.c"

#define PATH_ "./self_check_hw1/inputs/"
#define NUM_IN_FILE 2

int main()
{
    char text_from_file;
    struct dirent *dir;
    DIR *d;
    FILE *in_file;
    d = opendir(PATH_);
    if (d)
    {
        // read file into array
        while ((dir = readdir(d)) != NULL)
        {
            char path[515];
            int number;

            sprintf(path, "%s%s", PATH_, dir->d_name);
            printf("%s\n", dir->d_name);
            in_file = fopen(path, "r");

            if (NULL == in_file )
            {
                break;
            }

            int numberArray[NUM_IN_FILE];
            int i;

            for (i = 0; i < NUM_IN_FILE; i++)
            {
                fscanf(in_file, "%d", &numberArray[i]);
            }

            // printf("%d\n", isArmstrong(4));

            // Going all over the range of numbers
            for (number = numberArray[0]; number < numberArray[1]; number++)
            {
                // printf("Number is: %d\n", number);
            }

            // Closing the file
            fclose(in_file);
        }
        closedir(d);
    }
    return 0;
}