/* C program using ncurses to display info about currently installed packages with pacman */
/* Note: this is a early prototype and does not actually display accurate values */
/* I am also learning ncurses while writing this, so pardon any studpidity */
/* Author: bisen2 <bisenhar@uvm.edu> */

/*
 * Potentially use the windows library to implement a ranger-type ui?
 * 	need to read up on windows a bit more first
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <menu.h>

#define STR_LEN 100

MENU* menu_creator(ITEM*, ITEM**);

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
	ITEM **choices;
	MENU *choices_menu;
	MENU *packages_menu;
	ITEM *cur_item;
	choices = (ITEM **) calloc(6, sizeof(ITEM *));
	choices[0] = new_item(str_all, "");
	choices[1] = new_item(str_expl, "");
	choices[2] = new_item(str_all_off, "");
	choices[3] = new_item(str_all_aur, "");
	choices[4] = new_item(str_expl_off, "");
	choices[5] = new_item(str_expl_aur, "");
	choices_menu = new_menu((ITEM **)choices);
	post_menu(choices_menu);
	refresh();

	/* allow user to move through menu, or exit */
	while ((c=getch()) != 'q') {
		switch(c) {
			case KEY_DOWN:
			case 'j':
				menu_driver(choices_menu, REQ_DOWN_ITEM);
				break;
			case KEY_UP:
			case 'k':
				menu_driver(choices_menu, REQ_UP_ITEM);
				break;
			case KEY_ENTER:
			case 'l':
				/* call menu creator */
				packages_menu = menu_creator(cur_item, choices);
				/* move user to packages menu */
				unpost_menu(choices_menu);
				post_menu(packages_menu);
				refresh();
				break;
			case 'h':
				/* return to main menu */
				unpost_menu(packages_menu);
				post_menu(choices_menu);
				break;
		}
	}

	/* restore terminal and exit gracefully */
	free_item(choices[0]);
	free_item(choices[1]);
	free_item(choices[2]);
	free_item(choices[3]);
	free_item(choices[4]);
	free_item(choices[5]);
	free_menu(choices_menu);
	endwin();
	return 0;

}

MENU* menu_creator(ITEM *cur_item, ITEM **choices) {
	/* menu creator function */
	/* make empty menu */
	MENU *packages_menu;
	int num_packages;
	/* determine which menu to create and get number of packages */
	if (cur_item == choices[0]) {
		/* all packages */
		num_packages = 500;
	} else if (cur_item == choices[1]) {
		/* explicitly installed */
		num_packages = 100;
	} else if (cur_item == choices[2]) {
		/* all from official */
		num_packages = 300;
	} else if (cur_item == choices[3]) {
		/* all from AUR */
		num_packages = 200;
	} else if (cur_item == choices[4]) {
		/* explicit from official */
		num_packages = 70;
	} else if (cur_item == choices[5]) {
		/* explicit from AUR */
		num_packages = 30;
	} else { printw("Oops, you appear to have found a bug.\nPlease report to bisenhar@uvm.edu"); }
	/* make items for menu */
	ITEM **packages;
	for (int i=0; i<num_packages-1; i++) {
		/* make num_packages items for menu */
		printw("%d",i);
	}
}
