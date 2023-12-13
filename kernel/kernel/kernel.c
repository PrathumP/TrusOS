#include <stdio.h>
//#include <../arch/i386/vga.h>
#include <kernel/tty.h>
#include <kernel/home.h>

void kernel_main(void) {

	terminal_initialize();
	print_logo();
	//printf("Hello, kernel World!\n");
	about();
}
