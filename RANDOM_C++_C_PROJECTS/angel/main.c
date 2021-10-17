#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define OUT   0
#define IN    1

#define FALSE 0
#define TRUE  1

#define SIZE  32
#define LEN   512

int getInputFromMenu();
void fileToFile();
void fileToConsole();
void consoleToFile();
void consoleToConsole();
void sharedLogic(FILE *input, FILE *output);
void getFileName(char *arr, int mode);
int getData(char *line, int *brackets);

int main()
{
    while(1)
    {
        system("cls");
        switch (getInputFromMenu())
        {
            case 1:
                fileToFile();
                break;
            case 2:
                fileToConsole();
                break;
            case 3:
                consoleToFile();
                break;
            case 4:
                consoleToConsole();
                break;
            default:
                return 0;
                break;
        }
        system("PAUSE");
    }
}
int getInputFromMenu()
{
    int input;

    printf("--------------------MENU--------------------\n");
    printf("1. Read from FILE     and write in FILE\n");
    printf("2. Read from FILE     and write on SCREEN\n");
    printf("3. Read from KEYBOARD and write in FILE\n");
    printf("4. Read from KEYBOARD and write on SCREEN\n");
    printf("0. Exit\n");
    printf("--------------------------------------------\n");
    do
    {
        printf("\nSelect option: ");
        fflush(stdin);
        scanf("%d", &input);
    }
    while( (input < 0) || (input > 4) );

    return input;
}

void fileToFile()
{
    FILE *fileInput = NULL;
    FILE *fileOutput = NULL;
    char fileNameR[SIZE];
    char fileNameW[SIZE];

    getFileName(fileNameR, TRUE);
    fileInput = fopen(fileNameR, "r");
    if(NULL == fileInput)
    {
        perror("\nERROR");
        return 1;
    }
    getFileName(fileNameW, FALSE);
    fileOutput = fopen(fileNameW, "w");
    if(NULL == fileOutput)
    {
        perror("\nERROR");
        return 1;
    }

    sharedLogic(fileInput, fileOutput);

    if(fclose(fileInput) != 0)
    {
        perror("\nERROR");
        return 1;
    }
    if(fclose(fileOutput) != 0)
    {
        perror("\nERROR");
        return 1;
    }
}

void fileToConsole()
{
    FILE *fileInput = NULL;
    char fileNameR[SIZE];

    getFileName(fileNameR, TRUE);
    fileInput = fopen(fileNameR, "r");
    if(NULL == fileInput)
    {
        perror("\nERROR");
        return 1;
    }

    sharedLogic(fileInput, stdout);

    if(fclose(fileInput) != 0)
    {
        perror("\nERROR");
        return 1;
    }
}
void consoleToFile()
{
    FILE *fileOutput = NULL;
    char fileNameW[SIZE];

    getFileName(fileNameW, FALSE);
    fileOutput = fopen(fileNameW, "w");
    if(NULL == fileOutput)
    {
        perror("\nERROR");
        return 1;
    }

    printf("\nEnter your program:\n");
    sharedLogic(stdin, fileOutput);

    if(fclose(fileOutput) != 0)
    {
        perror("\nERROR");
        return 1;
    }
}

void consoleToConsole()
{
    printf("\nEnter your program:\n\n");
    sharedLogic(stdin, stdout);
}

void getFileName(char * arr, int mode)
{
    if(FALSE == mode)
    {
        printf("\nEnter output file name: ");
        fflush(stdin);
        scanf("%31s", arr);
    }
    else
    {
        printf("\nEnter input file name(.c): ");
        fflush(stdin);
        scanf("%31s", arr);

        while( FALSE == ((arr[strlen(arr) - 2] == '.') && (arr[strlen(arr) - 1] == 'c')) )
        {
            printf("\nERROR: %s does not end in .c!\n", arr);
            printf("\nEnter new name: ");
            scanf("%s", arr);
        }
    }
}

void sharedLogic(FILE *input, FILE *output)
{
    int brackets = 0;
    int symbolCounter = 0;
    int symbolMax = 0;
    char line[LEN];
    char lineMax[LEN];

    while(fgets(line, LEN, input) != NULL)
    {
         symbolCounter = getData(line, &brackets);
         if(symbolCounter > symbolMax)
         {
             symbolMax = symbolCounter;
             strcpy(lineMax, line);
         }
    }
    fprintf(output, "The row with highest count of meaningful symbols is:\n%s", lineMax);
    fprintf(output, "Brackets after if are: %d\n", brackets);
}

int getData(char *line, int *brackets)
{
    static char state = OUT;
    static char stateIf = OUT;
    char *str = line;
    static int bracketsCounter = 0;
    int symbolCounter = 0;

    while(*str != '\0')
    {
        if((*str == '/' || *str == '"' || *str == '\'' || *str == '#') && state == OUT)
        {
            state = *str;
            if(*str != '/')
            {
                symbolCounter++;
            }
        }
        else if(state != OUT)
        {
            switch(state)
            {
                case '/':
                    if(*str == '/')
                    {
                        state = OUT;
                        while(*str != '\n')
                        {
                            str++;
                        }
                    }
                    else if(*str == '*')
                    {
                        state = *str;
                        while((*str != '\n') && (state != OUT))
                        {
                            str++;
                            if (*str == '*')
                            {
                                str++;
                                if(*str == '/')
                                {
                                    state = OUT;
                                    str++;
                                }
                                else
                                {
                                    str--; //because of cases like /*...**...*/
                                }
                            }
                        }
                    }
                    else
                        symbolCounter++;
                        state = OUT;
                    break;
                case '*':
                    while((*str != '\n') && (state != OUT))
                    {
                        if (*str == '*')
                        {
                            str++;
                            if(*str == '/')
                            {
                                state = OUT;
                            }
                            else
                            {
                                str--; //because of cases like /*...**...*/
                            }
                        }
                        str++;
                    }
                    break;
                case '\"':
                    while(*str != '\"')
                    {
                        if(*str == '\\') //because of cases like "...\"..."
                        {
                            str++;
                            symbolCounter++;
                        }
                        str++;
                        symbolCounter++;
                    }
                    state = OUT;
                    break;
                case '\'':
                    while(*str != '\'')
                    {
                        if(*str == '\\') //because of the case '/''
                        {
                            str++;
                            symbolCounter++;
                        }
                        str++;
                        symbolCounter++;
                    }
                    state = OUT;
                    break;
                case '#':
                    while(*str != '\n')
                    {
                        str++;
                        symbolCounter++;
                    }
                    state = OUT;
                    break;
            }
        }
        if(state == OUT)
        {
            if(stateIf == OUT)
            {
                if(*str == 'i')
                {
                    str++;
                    if(*str == 'f')
                    {
                        stateIf = IN;
                        symbolCounter++;
                    }
                    else
                    {
                        str--;
                    }
                }
            }
            else if(stateIf == IN)
            {
                if(*str == '{')
                {
                    (*brackets)++;
                    bracketsCounter++;
                }
                else if(*str == '}')
                {
                    bracketsCounter--;
                    if(bracketsCounter == 0)
                    {
                        stateIf = OUT;
                    }
                }
            }
        }
        if(isspace(*str) == FALSE)
        {
            symbolCounter++;
        }
        str++;
    }

    return symbolCounter;
}
