//#include "apue.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>

int main (int argc, char *argv[])
{
    DIR *dp;
    struct dirent *dirp;
    if (argc != 2)
        std::cout << "usage: ls directory name" << std::endl;
        //err_quit ("usage: ls directory name");
    if ((dp = opendir (argv[1])) == NULL)
        std::cout << "can't open " << argv[1] << std::endl;
        //err_sys ("can't open %s", argv [1]);
    while ((dirp = readdir(dp)) != NULL)
        printf("%s\n", dirp->d_name) ;
    closedir (dp);
    exit (0);
}
