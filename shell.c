// 260930902
// Created by jonayed islam on 1/29/2020.
//
#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "interpreter.h"
#include "shell.h"

int shellUI()
{
    printf("Kernel 1.0 loaded");
    printf("Welcome to the Jonayed Islam shell!\n");
    printf("Shell version 2.0 Updated February 2020\n");
    char prompt[100] = {'$', '\0'};
    char userInput[1000];
    int errorCode = 0;

    while (1)
    {
        printf("%s ", prompt);
        fgets(userInput, 999, stdin);
        ///printf("your input is : %s", userInput);
        int errorCode;
        errorCode = parseInput(userInput);
        if (errorCode == 2)
        {
            printf("BYE!");
            break;
        }
        if (errorCode == -1)
            exit(99);
        printf("\n");
    }

    return 0;
}

int parseInput(char ui[1000])
{

    char tmp[200];
    char *words[100];

    int w = 0;

    char *word = strtok(ui, " ");
    //    char bad = " \t\n";
    while (word != NULL)
    {
        {
            //printf("%s", word);
            words[w++] = word;
            word = strtok(NULL, " \t\r\n\v\f");
        }
    }
    for (w = 0; w < 10; ++w)
    {
        //printf("%s\n", words[w]);
    }

    return interpreter(words);
}
