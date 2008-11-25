/*
 * Machine oriented programming
 * Chalmers University of Technology
 * Lab 3
 * Task 2: Translate from morse code to letters
 * 
 * Author:	Emanuel Ferm
 *			emanuelf @ student.chalmers.se
 * Date:	24 November 2008
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX		29
#define A		97
#define ADOT	229
#define ADDOT	228
#define ODOT	246

int search(const char *);
char to_letters(const char *);

/*
 * The morse code alphabet
 */
const char *morse[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....",
	"..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", 
	"...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".--.-", ".-.-", 
	"---."};

/*
 * search returns the index in the alphabet of the morse code equivalent
 */
int search(const char *code)
{
	int i = -1;
	
	while (i != MAX && abs(strcmp(code, morse[++i])))
		;
	
	if (i == MAX)
		i = -1;

	return i;
}

/*
 * to_letters takes a morse code and returns the letter equivalent
 */

char to_letters(const char *code)
{
	int i = search(code);
	
	if (i < (MAX - 3))
		return A + i;
	else if (i == (MAX - 3))
		return ADOT;
	else if (i == (MAX - 2))
		return ADDOT;
	else if (i == (MAX - 1))
		return ODOT;
	else
		return '?';
}

/*
 * main reads input morse code, converts it letters and prints to stdout
 */
int main()
{
	char s[6];
	
	while(scanf("%s", s) != -1)
	{
		putchar(to_letters(s));
		if (getchar() == '\t')
			putchar(' ');
	}
	putchar('\n');
}
