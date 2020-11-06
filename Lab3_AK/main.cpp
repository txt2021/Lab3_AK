#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
int main(int argc, char *argv[]){
    int i;
    float val;
    int list, version, help, all, short_, create;
    char *file, *arr;
    struct option options[] = {{"list", required_argument, 0, 'l'},
        {"version", no_argument, 0, 'v'},
        {"help", no_argument, 0, 'h'},
        {"all", no_argument, 0, 'a'},
        {"short", no_argument, 0, 's'},
        {"create", required_argument, 0, 'c'},
        {0, 0, 0, 0}};
    while ((i = getopt_long(argc, argv, "ahvsc:V:l:o::", options, NULL)) != -1){
        switch (i){
            case 'l':
                list = 1;
                arr = optarg;
                break;
            case 'v':
                version = 1;
                break;
            case 'h':
                help = 1;
                break;
            case 'a':
                   all = 1;
                break;
            case 's':
                   short_ = 1;
                break;
            case 'c':
                   create = 1;
                file = optarg;
                break;
            default:
                break;}
    }
    if (all == 1)
        printf("Arg: All\n");
    if (help == 1)
        printf("Arg: Help\n");
    if (version == 1)
        printf("Arg: Version\n");
    if (short_ == 1)
        printf("Arg: Short\n");
    if (create == 1)
        printf("Arg: Create file - %s\n", file);
    if (list == 1){
        printf("Arg: Array = [");
        arr = strtok(arr, ",");
        while (1){
            printf("%f", atof(arr));
            arr = strtok(NULL, ",");
            if (arr != NULL)
                printf(", ");
            else
                break;
        }
        printf("]\n");}
}

