/*======================================================================================================================
                                             Command interpreter
Developer: J2AC
Date: 2026/01
Version: 1.0.0
=======================================================================================================================
*/

/* --- Libraries --- */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>
#include <windows.h>

/* --- Macros --- */
#define NUMBER_COMMANDS 8

/* --- Function Prototype --- */
uint8_t command_reading(char *input);
const char *instructions(int8_t i);
void execute_command(char *input);
char *uppercase(char *word);
void f_exit();
void f_help();
void f_clear();
void f_run();
void f_clear_all();
void f_txt();
void f_rep();
void f_run_soud();
void load();
void simple_load();


/* --- Global Variables --- */
char txt[100];
int8_t repetition_number = 0;
uint8_t control = 1;


int main()
{

    char input[12];
    char *command;
    

    while(control)
    {

        printf("\n- Command Input: ");

        fgets(input, sizeof(input), stdin);

        input[strcspn(input, "\r\n")] = '\0';

        command = uppercase(input);

        if(!command_reading(command))
        {   
            puts("");
            puts("Invalid command ");
            system("PAUSE");
            system("CLS");

        }

        execute_command(command);
    }
        
    return 0;
}/* End main */

/*=====================================================================================================================*/
/* --- Function Development --- */
uint8_t command_reading(char *input)
{
    for(int8_t i = 0; i < NUMBER_COMMANDS; i++)
    {   
        if(strcmp(input, instructions(i)) == 0) return 1;
        
    }

    return 0;
} /* end command_reading*/

const char *instructions(int8_t i)
{
    const char *instruction[] = {    
                                    "RUN", 
                                    "RUN SOUND",
                                    "REP",
                                    "TXT",
                                    "CLEAR",
                                    "CLEAR ALL",
                                    "EXIT",
                                    "HELP"
                                };

    return instruction[i];  
}/*end instructions*/

void execute_command(char *input)
{
    if(strcmp(input, "RUN") == 0) f_run();

    else if(strcmp(input, "RUN SOUND") == 0) f_run_soud();

    else if(strcmp(input, "REP") == 0) f_rep();

    else if(strcmp(input, "TXT") == 0) f_txt();

    else if(strcmp(input, "CLEAR") == 0) f_clear();

    else if(strcmp(input, "CLEAR ALL") == 0) f_clear_all();

    else if(strcmp(input, "EXIT") == 0) f_exit();

    else if(strcmp(input, "HELP") == 0) f_help();

}/*end execute_command*/

char *uppercase(char *word)
{

    for(int8_t i = 0; i < strlen(word); i++) word[i] = toupper(word[i]);

    return word;

}/*end uppercase*/

void f_exit()
{   
    puts("");
    puts("Your program will be terminated ... ");
    puts("Closing program ... ");
    system("PAUSE");
    control = 0;

}/* end f_exit*/

void f_help()
{   
    puts("===========================");
    puts("         HELP              ");
    puts("===========================");
    puts("Command List: ");
    puts("RUN       - Run the interpreter. ");
    puts("RUN SOUND - Run the interpreter with 'beeps'. ");
    puts("REP       - Defines the number of repetitions of a previously saved using the TXT command. ");
    puts("TXT       - Command for entering a new sentence. The argument and the text sentence.. ");
    puts("CLEAR     - Clean the screen. ");
    puts("CLEAR ALL - Clears the screen and restores the variables.. ");
    puts("EXIT      - Interpreter's end. ");
    puts("HELP      - Presents the current version of the interpreter with explanations..  ");

    system("PAUSE");
}/* end f_help*/

void f_clear()
{
    simple_load();
    system("CLS");

}/* end clear*/

void f_run()
{
    if(repetition_number == 0 || strlen(txt) == 0)
    {
        puts("");
        puts("You need to define the text and the number of times it should be repeated! ");
        return;
    }

    for(uint8_t i = 0; i < repetition_number; i++) printf("%s\n", txt);
}/* end f_run*/

void f_run_soud()
{
    if(repetition_number == 0 || strlen(txt) == 0)
    {
        puts("You need to define the text and the number of times it should be repeated! ");
        return;
    }

    for(uint8_t i = 0; i < repetition_number; i++) printf("%s\a\n", txt);
}/*end f_run_sound*/

void f_clear_all()
{     

    puts("Clearing variables...");

    load();
   
    puts("");

    repetition_number = 0;
    txt[0] = '\0';

    Sleep(300);
    system("cls");

}/*end f_clear_all*/

void f_txt()
{       
     printf("Enter text: ");
     fgets(txt, sizeof(txt), stdin);
     puts("Text saved! ");

}/*end f_txt*/

void f_rep()
{
     printf("Enter the number of repetitions: ");
     scanf("%d", &repetition_number);
     puts("Saved repetition number");
     while(getchar() != '\n'); 

}/*end f_rep*/

void load()
{   
    const uint8_t bar_width = 20;
    uint8_t percent = 0;

    for(uint8_t i = 0; i < bar_width; i++)
    {
        percent += 5;

        printf("\r[");

        for(uint8_t j = 0; j < i; j++) printf("#");

        for(uint8_t z = 0; z < (bar_width - i) - 1; z++) printf(" ");

        printf("] %3d%%", percent);

        fflush(stdout);

        Sleep(300);

    }
}/*end load*/

void simple_load()
{

    for(uint8_t i = 0; i <= 100; i += 10)
    {
        printf("\rCleaning %3d%%", i);
        fflush(stdout);
        Sleep(200);
    }

}/* end simple_load*/


