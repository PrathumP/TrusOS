#include <stdio.h>
//#include <../arch/i386/vga.h>
#include <kernel/tty.h>
#include <kernel/home.h>
#include "kernel/ports.h"
#include "kernel/kbd.h"
#include "../../libc/include/string.h"

void kernel_main(void) {

	terminal_initialize();
	print_logo();
	// //printf("Hello, kernel World!\n");
	// about();
	char buffer[1024];
	uint8_t byte;

	//terminal_initialize();
	printf("Hello ! Nice to meet you \n");

	strcpy(&buffer[strlen(buffer)], "");
	print_prompt();
	while (1)
	{
		while (byte = scan())
		{
			if (byte == ENTER)
			{
				if (strlen(buffer) > 0 && strcmp(buffer, "exit") == 0)
				{
					printf("\nGoodbye!");
				}
				if (strlen(buffer) > 0 && strcmp(buffer, "hello") == 0)
				{
					printf("\nHi!");
				}
				else if (strlen(buffer) > 0 && strcmp(buffer, "clear") == 0)
				{
					terminal_initialize();
					strcpy(&buffer[strlen(buffer)], "");
				}
				print_prompt();
				memset(buffer, 0, sizeof(buffer));
				break;
			}
			else if ((byte == BACKSPACE) && (strlen(buffer) == 0))
			{
			}
			else if (byte == BACKSPACE)
			{
				//char c = normalmap[byte];
				//char *s;
				//s = ctos(s, c);
				//buffer[strlen(buffer) - 1] = '\0';
				//terminal_write(buffer,strlen(buffer) - 1);
				//terminal_column--;
				//strcpy(&buffer[strlen(buffer)-1], "");
				backspace();
				//printf("%s", s);
				//memset(buffer[strlen(buffer) - 1], "", 1);
				move_cursor(get_terminal_row(), get_terminal_col());
				// strcpy(&buffer[strlen(buffer)], "");
			}
			else 
			{
				char c = (normalmap[byte]);
				char *s;
				s = ctos(s, c);
				printf("%s", s);
				strcpy(&buffer[strlen(buffer)], s);
			}
			move_cursor(get_terminal_row(), get_terminal_col());
		}
	}
}
