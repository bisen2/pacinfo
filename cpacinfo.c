/* C program using ncurses to display info about currently installed packages with pacman */
/* Note: this is a early prototype and does not actually display accurate values */
/* I am also learning ncurses while writing this, so pardon any studpidity */
/* Author: bisen2 <bisenhar@uvm.edu> */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <menu.h>

#define STR_LEN 100

int main(void) {

	int c;

	/* initialize ncurses environment */
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);

	/* get numbers of packages */
	/* for now, just some test numbers to display */
	char all[] = "500";
	char expl[] = "100";
	char all_off[] = "300";
	char all_aur[] = "200";
	char expl_off[] = "70";
	char expl_aur[] = "30";

	/* defining strings without the numbers */
	char str_all[STR_LEN] = "All Packages: ";
	char str_expl[STR_LEN] = "Explicitly Installed Packages: ";
	char str_all_off[STR_LEN] = "All Packages from Official Repositories: ";
	char str_all_aur[STR_LEN] = "All Packages from AUR: ";
	char str_expl_off[STR_LEN] = "Explicitly Installed Packages from Official Repositories: ";
	char str_expl_aur[STR_LEN] = "Explicitly Installed Packages from AUR: ";

	/* add numbers to strings */
	strcat(str_all, all);
	strcat(str_expl, expl);
	strcat(str_all_off, all_off);
	strcat(str_all_aur, all_aur);
	strcat(str_expl_off, expl_off);
	strcat(str_expl_aur, expl_aur);

	/* make menu and items */
	ITEM **items;
	MENU *item_menu;
	ITEM *cur_item;
	items = (ITEM **) calloc(6, sizeof(ITEM *));
	items[0] = new_item(str_all, "");
	items[1] = new_item(str_expl, "");
	items[2] = new_item(str_all_off, "");
	items[3] = new_item(str_all_aur, "");
	items[4] = new_item(str_expl_off, "");
	items[5] = new_item(str_expl_aur, "");
	item_menu = new_menu((ITEM **)items);
	post_menu(item_menu);
	refresh();

	/* allow user to move through menu, or exit */
	while ((c=getch()) != 'q') {
		switch(c) {
			case KEY_DOWN:
				menu_driver(item_menu, REQ_DOWN_ITEM);
				break;
			case KEY_UP:
				menu_driver(item_menu, REQ_UP_ITEM);
				break;
			case 'k':
				menu_driver(item_menu, REQ_UP_ITEM);
				break;
			case 'j':
				menu_driver(item_menu, REQ_DOWN_ITEM);
				break;
//			case 'l':
//			case 10:	/* Enter */
//				cur_item = current_item(item_menu);
//				clear();
//				/* go to info about subset of packages */
//				refresh();
//				break;
//			case 'h':
//				clear();
//				post_menu(item_menu); /* return to main menu */
//				refresh();
//				break;
		}
	}

	/* restore terminal and exit gracefully */
	free_item(items[0]);
	free_item(items[1]);
	free_item(items[2]);
	free_item(items[3]);
	free_item(items[4]);
	free_item(items[5]);
	free_menu(item_menu);
	endwin();
	return 0;

}
