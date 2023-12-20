#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <kernel/tty.h>

#include "vga.h"

static uint16_t* const VGA_MEMORY = (uint16_t*) 0xB8000;

static size_t terminal_row;
static size_t terminal_column;
static uint8_t terminal_color;
static uint16_t* terminal_buffer;

static inline uint8_t vga_entry_color(enum vga_color fg, enum vga_color bg) {
	return fg | bg << 4;
}

void terminal_initialize(enum vga_color font, enum vga_color background) {
	terminal_row = 0;
	terminal_column = 0;
	terminal_color = vga_entry_color(font, background );
	terminal_buffer = VGA_MEMORY;
	for (size_t y = 0; y < VGA_HEIGHT; y++) {
		for (size_t x = 0; x < VGA_WIDTH; x++) {
			const size_t index = y * VGA_WIDTH + x;
			terminal_buffer[index] = vga_entry(' ', terminal_color);
		}
	}
}

void terminal_render(){
    for (size_t y = 0; y < VGA_HEIGHT; y++) {
		for (size_t x = 0; x < VGA_WIDTH; x++) {
			const size_t index = y * VGA_WIDTH + x;
			terminal_buffer[index] = vga_entry(terminal_buffer[index], terminal_color);
		}
	}
}

void terminal_setcolor(enum vga_color font, enum vga_color background) {
	terminal_color = vga_entry_color(font, background );
}

void terminal_scroll(void) {
    size_t y;
    for (y = 0; y < VGA_HEIGHT; y++)
    {
        size_t x;
        for (x = 0; x < VGA_WIDTH; x++)
        {
            terminal_buffer[y * VGA_WIDTH + x] = terminal_buffer[(y + 1) * VGA_WIDTH + x];
        }
        terminal_row--;
    }
    terminal_row = VGA_HEIGHT - 1;
}

void terminal_putentryat(unsigned char c, uint8_t color, size_t x, size_t y) {
	//if( y > VGA_HEIGHT-1) terminal_scroll();
	const size_t index = y * VGA_WIDTH + x;
	terminal_buffer[index] = vga_entry(c, color);
}

void terminal_putchar(char c) {
	if (c == '\n') {
        terminal_row++;
		terminal_column = 0;
		if(terminal_row==VGA_HEIGHT) terminal_scroll();
    } else {
	unsigned char uc = c;
	terminal_putentryat(uc, terminal_color, terminal_column, terminal_row);
	if (++terminal_column == VGA_WIDTH) {
		terminal_column = 0;
		if (++terminal_row == VGA_HEIGHT) {
			terminal_row = 0;
	}
}}
}

int putchar(int ic)
{
    char c = (char)ic;
    terminal_write(&c, sizeof(c));
    return ic;
}

void terminal_write(const char* data, size_t size) {
	for (size_t i = 0; i < size; i++)
		terminal_putchar(data[i]);
}

void terminal_writestring(const char* data) {
	terminal_write(data, strlen(data));
}

void term_putc(char c, enum vga_color char_color)
{

    int index;
    switch (c)
    {
    case '\n':
    {
        terminal_column = 0;
        terminal_row += 2;
        break;
    }

    default: 
    {
        index = (VGA_WIDTH * terminal_row) + terminal_column; 
        VGA_MEMORY[index] = c;
        VGA_MEMORY[index + 1] = char_color;
        break;
    }
    }
    if (terminal_column >= VGA_WIDTH)
    {
        terminal_column = 0;
        terminal_row++;
    }

    if (terminal_row >= VGA_WIDTH)
    {
        terminal_column = 0;
        terminal_scroll();
    }
}

int get_terminal_row(void) {
    return terminal_row;
}

int get_terminal_col(void) {
    return terminal_column;
}

void backspace(){
    size_t row = get_terminal_row();
    size_t col = get_terminal_col();
    terminal_buffer[row*VGA_WIDTH + col-1] = vga_entry(' ', terminal_color);
    terminal_column--;
}

void color_options(){
    printf("\nPlease select a font color. Valid options are:\n");
    terminal_setcolor(VGA_COLOR_BLUE, VGA_COLOR_BLACK);
    printf("\nCOLOR_BLUE : Type 'blue' to set color blue ");
    terminal_setcolor(VGA_COLOR_GREEN, VGA_COLOR_BLACK);
    printf("\nCOLOR_GREEN : Type 'green' to set color green");
    terminal_setcolor(VGA_COLOR_CYAN, VGA_COLOR_BLACK);
    printf("\nCOLOR_CYAN : Type 'cyan' to set color cyan ");
    terminal_setcolor(VGA_COLOR_RED, VGA_COLOR_BLACK);
    printf("\nCOLOR_RED : Type 'red' to set color red ");
    terminal_setcolor(VGA_COLOR_MAGENTA, VGA_COLOR_BLACK);
    printf("\nCOLOR_MAGENTA : Type 'magenta' to set color magenta ");
    terminal_setcolor(VGA_COLOR_BROWN, VGA_COLOR_BLACK);
    printf("\nCOLOR_BROWN : Type 'brown' to set color brown ");
    terminal_setcolor(VGA_COLOR_LIGHT_GREY,VGA_COLOR_BLACK);
    printf("\nCOLOR_LIGHT_GREY : Type 'grey' to set color grey ");
    terminal_setcolor(VGA_COLOR_DARK_GREY, VGA_COLOR_BLACK);
    printf("\nCOLOR_DARK_GREY : Type 'darkgrey' to set color dark gray ");
    terminal_setcolor(VGA_COLOR_LIGHT_BLUE, VGA_COLOR_BLACK);
    printf("\nCOLOR_LIGHT_BLUE : Type 'lightblue' to set color light blue ");
    terminal_setcolor(VGA_COLOR_LIGHT_GREEN, VGA_COLOR_BLACK);
    printf("\nCOLOR_LIGHT_GREEN : Type 'lightgreen' to set color light green ");
    terminal_setcolor(VGA_COLOR_LIGHT_CYAN, VGA_COLOR_BLACK);
    printf("\nCOLOR_LIGHT_CYAN : Type 'lightcyan' to set color light cyan ");
    terminal_setcolor(VGA_COLOR_LIGHT_RED, VGA_COLOR_BLACK);
    printf("\nCOLOR_LIGHT_RED : Type 'lightred' to set color light red ");
    terminal_setcolor(VGA_COLOR_LIGHT_MAGENTA, VGA_COLOR_BLACK);
    printf("\nCOLOR_LIGHT_MAGENTA : Type 'lightmagenta' to set color light magenta ");
    terminal_setcolor(VGA_COLOR_LIGHT_BROWN, VGA_COLOR_BLACK);
    printf("\nCOLOR_YELLOW : Type 'yellow' to set color yellow ");
    terminal_setcolor(VGA_COLOR_WHITE, VGA_COLOR_BLACK);
    printf("\nCOLOR_WHITE : Type 'white' to set color white \n");
    terminal_setcolor(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
}