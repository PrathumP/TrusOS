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
    printf("\tTrusOS - A simple 32-bit x86 operating system \n");
    printf("\tGitHub repository: https://github.com/PrathumP/TrusOS \n");
    printf("\t                                                         \n");

}