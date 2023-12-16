#include <stdio.h>
//#include <../arch/i386/vga.h>
#include <kernel/tty.h>
#include <kernel/home.h>
#include "kernel/ports.h"
#include "kernel/kbd.h"
#include "../../libc/include/string.h"

void kernel_main(void) {

	// terminal_initialize();
	// print_logo();
	// //printf("Hello, kernel World!\n");
	// about();
	char buffer[1024];
	uint8_t byte;

	terminal_initialize();
	printf("Welcome! I'm a super advanced operational system with lots of features.\n\n");

	strcpy(&buffer[strlen(buffer)], "");
	print_prompt();
	while (1)
	{
		while (byte = scan())
		{
			if (byte == 0x1c)
			{
				if (strlen(buffer) > 0 && strcmp(buffer, "exit") == 0)
				{
					printf("\nGoodbye!");
				}
				if (strlen(buffer) > 0 && strcmp(buffer, "hello") == 0)
				{
					printf("\nHi!");
				}
				print_prompt();
				memset(&buffer[0], 0, sizeof(buffer));
				break;
			}
			else
			{
				char c = normalmap[byte];
				char *s;
				s = ctos(s, c);
				printf("%s", s);
				strcpy(&buffer[strlen(buffer)], s);
			}
			move_cursor(get_terminal_row(), get_terminal_col());
		}
	}
	//return 0;
}
