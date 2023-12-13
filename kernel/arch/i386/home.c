#include <stdio.h>
#include <kernel/home.h>

void print_logo(void)
{
    printf("\t                                                         \n");
    printf("\t _______                      ____    _____ \n");
    printf("\t|__  ___|                    / __ \\  / ____|\n");
    printf("\t   | |  _ __  _   _   ____  | |  | || (___  \n");
    printf("\t   | | | '__|| | | | |/ __| | |  | | \\___ \\ \n");
    printf("\t   | | | |   | |_| | \\__ \\  | |__| | ____) |\n");
    printf("\t   |_| |_|    \\__,_| |____/  \\____/ |_____/ \n");
    printf("\t                                                         \n");
    printf("\t                                                         \n");
}

void about()
{
    printf("\n\tTrusOS - A simple 32-bit x86 operating system" );
    printf("\n\tGitHub repository: https://github.com/PrathumP/TrusOS dvdsvsdfvvvfzfvvvvvvvvvvvvvvvvvvvv");
    printf("\t                                                         \n");

}