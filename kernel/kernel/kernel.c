#include <stdio.h>
//#include <../arch/i386/vga.h>
#include <kernel/tty.h>
#include <kernel/home.h>
#include "kernel/ports.h"
#include "kernel/bool.h"
#include "kernel/keyboard.h"
#include "../../libc/include/string.h"

uint8_t numlock = true;
uint8_t capslock = false;
uint8_t shift = false;

void kernel_main(void) {

	terminal_initialize(default_font_color, VGA_COLOR_BLACK);
	print_logo();
	// //printf("Hello, kernel World!\n");
	// about();
	char buffer[1024];
	uint8_t byte;

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
					terminal_initialize(default_font_color, VGA_COLOR_BLACK);
					strcpy(&buffer[strlen(buffer)], "");
				}
				else if (strlen(buffer) > 0 && strcmp(buffer, "coloroptions") == 0)
				{
					color_options();
					terminal_setcolor(default_font_color, VGA_COLOR_BLACK);
					print_prompt();
				}
				else if (strlen(buffer) > 0 && strcmp(buffer, "lightcyan") == 0)
				{
					terminal_setcolor(VGA_COLOR_LIGHT_CYAN, VGA_COLOR_BLACK);
					default_font_color = VGA_COLOR_LIGHT_CYAN;
					terminal_render();
				}
				else if (strlen(buffer) > 0 && strcmp(buffer, "green") == 0)
				{
					terminal_setcolor(VGA_COLOR_GREEN, VGA_COLOR_BLACK);
					default_font_color = VGA_COLOR_GREEN;
					terminal_render();
				}
				else if (strlen(buffer) > 0 && strcmp(buffer, "blue") == 0)
				{
					terminal_setcolor(VGA_COLOR_BLUE, VGA_COLOR_BLACK);
					default_font_color = VGA_COLOR_BLUE;
					terminal_render();
				}
				else if (strlen(buffer) > 0 && strcmp(buffer, "red") == 0)
				{
					terminal_setcolor(VGA_COLOR_RED, VGA_COLOR_BLACK);
					default_font_color = VGA_COLOR_RED;
					terminal_render();
				}
				else if (strlen(buffer) > 0 && strcmp(buffer, "magenta") == 0)
				{
					terminal_setcolor(VGA_COLOR_MAGENTA, VGA_COLOR_BLACK);
					default_font_color = VGA_COLOR_MAGENTA;
					terminal_render();
				}
				else if (strlen(buffer) > 0 && strcmp(buffer, "brown") == 0)
				{
					terminal_setcolor(VGA_COLOR_BROWN, VGA_COLOR_BLACK);
					default_font_color = VGA_COLOR_BROWN;
					terminal_render();
				}
				else if (strlen(buffer) > 0 && strcmp(buffer, "yellow") == 0)
				{
					terminal_setcolor(VGA_COLOR_LIGHT_BROWN, VGA_COLOR_BLACK);
					default_font_color = VGA_COLOR_LIGHT_BROWN;
					terminal_render();
				}
				else if (strlen(buffer) > 0 && strcmp(buffer, "grey") == 0)
				{
					terminal_setcolor(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
					default_font_color = VGA_COLOR_LIGHT_GREY;
					terminal_render();
				}
				else if (strlen(buffer) > 0 && strcmp(buffer, "darkgrey") == 0)
				{
					terminal_setcolor(VGA_COLOR_DARK_GREY, VGA_COLOR_BLACK);
					default_font_color = VGA_COLOR_DARK_GREY;
					terminal_render();
				}
				else if (strlen(buffer) > 0 && strcmp(buffer, "white") == 0)
				{
					terminal_setcolor(VGA_COLOR_WHITE, VGA_COLOR_BLACK);
					default_font_color = VGA_COLOR_WHITE;
					terminal_render();
				}
				else if (strlen(buffer) > 0 && strcmp(buffer, "lightred") == 0)
				{
					terminal_setcolor(VGA_COLOR_LIGHT_RED, VGA_COLOR_BLACK);
					default_font_color = VGA_COLOR_LIGHT_RED;
					terminal_render();
				}
				else if (strlen(buffer) > 0 && strcmp(buffer, "lightblue") == 0)
				{
					terminal_setcolor(VGA_COLOR_LIGHT_BLUE, VGA_COLOR_BLACK);
					default_font_color = VGA_COLOR_LIGHT_BLUE;
					terminal_render();
				}
				else if (strlen(buffer) > 0 && strcmp(buffer, "cyan") == 0)
				{
					terminal_setcolor(VGA_COLOR_CYAN, VGA_COLOR_BLACK);
					default_font_color = VGA_COLOR_CYAN;
					terminal_render();
				}
				else if (strlen(buffer) > 0 && strcmp(buffer, "lightgreen") == 0)
				{
					terminal_setcolor(VGA_COLOR_LIGHT_GREEN, VGA_COLOR_BLACK);
					default_font_color = VGA_COLOR_LIGHT_GREEN;
					terminal_render();
				}
				else if (strlen(buffer) > 0 && strcmp(buffer, "lightmagenta") == 0)
				{
					terminal_setcolor(VGA_COLOR_LIGHT_MAGENTA, VGA_COLOR_BLACK);
					default_font_color = VGA_COLOR_LIGHT_MAGENTA;
					terminal_render();
				}
				else if (strlen(buffer) > 0 && strcmp(buffer, "cyan") == 0)
				{
					terminal_setcolor(VGA_COLOR_LIGHT_BLUE, VGA_COLOR_BLACK);
					default_font_color = VGA_COLOR_LIGHT_BLUE;
					terminal_render();
				}
				else
				{
					printf("\n'%s' : Command not found ", buffer);
				}
				print_prompt();
				memset(buffer, 0, sizeof(buffer));
				break;
			}
			else if ((byte == BACKSPACE) && (get_terminal_col()==4))
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
				//char c = (normalmap[byte]);
				char c1 = togglecode[byte];
				char c2 = shiftcode[byte];
				char c;
				if (c1 == CAPSLOCK)
				{
					if (!capslock)
					{
						capslock = true;
					}
					else
					{
						capslock = false;
					}
				}
				if(c2 == SHIFT) shift = true;
				if (capslock)
				{
					c = capslockmap[byte];
				}
				else if (shift)
				{
					c = shiftmap[byte];
					shift = false;
				}
				else
				{
					c = normalmap[byte];
				}
				char *s;
				s = ctos(s, c);
				printf("%s", s);
				strcpy(&buffer[strlen(buffer)], s);
				if (byte == 0x2A || byte == 0x36)
				{
					shift = true;
				}
			}
			move_cursor(get_terminal_row(), get_terminal_col());
		}
	}
}
