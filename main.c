#include "NumClass.h"
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>

int main()
{
    const char PATH_[260] = "./self_check_hw1/inputs/";
    char text_from_file;
    struct dirent *dir;
    DIR *d;
    FILE *in_file;

    d = opendir(PATH_);
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            char path[515];
            sprintf(path, "%s%s", PATH_, dir->d_name);
            in_file = fopen(path, "r");
            // read only
            if (NULL == in_file)
            {
                printf("file can't be opened \n");
                break;
            }
            printf("content of this file are\n");
            printf("---%s\n", dir->d_name);

            do
            {
                text_from_file = fgetc(in_file);
                printf("%c", text_from_file);

                // Checking if character is not EOF.
                // If it is EOF stop eading.
            } while (text_from_file != EOF);

            // Closing the file
            fclose(in_file);
        }
        closedir(d);
    }
    return 0;
}