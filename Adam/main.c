//
//  main.c
//  Adam
//
//  Created by Jeremy Petter on 2015-05-05.
//  Copyright (c) 2015 Jeremy Petter. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>


char input[255];
char responseToDefaultInput[] = "Whatever.\n";
char responseToBlankInput[] = "Fine. Be that way!\n";
char responseToCapsInput[] = "Woah, chill out!\n";
char responseToQuestionInput[] = "Sure\n";
int isAQuestion (char[]);
int isAYell (char[]);

int main(int argc, const char * argv[])
{
    char exit[] = "exit";
    
    //initial prompt
    printf("What do you want?\n> ");
    scanf("%[^\n]", input);
    
    //check for exit prompt and begin loop
    while (strcmp(input, exit) != 0)
    {
  
        //purge stdin
        fpurge(stdin);
        
        //parse response
        if (strlen(input) == 0)
        {
            printf("%s", responseToBlankInput);
        }
        else if (isAQuestion(input))
        {
            printf("%s", responseToQuestionInput);
        }
        else if (isAYell(input))
        {
            printf("%s", responseToCapsInput);
        }
                else
        {
            printf("%s", responseToDefaultInput);
        }
        
        //clear input buffer
        memset(input, 0, sizeof input);
        
        //prompt
        printf("> ");
        scanf("%[^\n]", input);
    }
    
    return 0;
}

int isAQuestion (char input[])
{
    int stringLength = (int)strlen(input);
    char lastCharacter = input[--stringLength];
    
    if (lastCharacter == '?')
    {
        return 1;
    }
    
    return 0;
}

int isAYell (char input[])
{
    int stringLength = (int)strlen(input);
    for (int i = 0; i < stringLength; i++)
        {
        if (islower(input[i])){
            return 0;
        }
    }
    return 1;
}
