/*
 * Machine oriented programming
 * Chalmers University of Technology
 * Lab 3
 * Task 1: Translate to morse code
 * 
 * Author:	Emanuel Ferm
 *			emanuelf @ student.chalmers.se
 * Date:	24 November 2008
 */

#include <stdio.h>
#include <stddef.h>

#define MAX		29
#define BUF		300
#define OFF		32
#define A		65
#define ADOT	197
#define ADDOT	196
#define ODOT	214

int index_of(unsigned char);
const char * to_morse(char);

/*
 * The morse code alphabet
 */
const char *morse[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", 
	"..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", 
	"...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".--.-", ".-.-", 
	"---."};

/*
 * index_of takes a character and returns the position of it in the alphabet
 */
int index_of(unsigned char c)
{
	if (c > 64 && c < 91)
		return (c - A);
	else if (c > 96 && c < 123)
		return (c - (A + OFF));
	else if (c == ADOT || c == ADOT + OFF)
		return (MAX - 3);
	else if (c == ADDOT || c == ADDOT + OFF)
		return (MAX - 2);
	else if (c == ODOT || c == ODOT + OFF)
		return (MAX - 1);
	else
		return -1;
}

/*
 * to_morse takes a character and returns the morse code equivalent
 */
const char *to_morse(char c)
{
	int i;
	if ((i = index_of(c)) == -1)
		return "";
	else
		return morse[i];
}

/*
 * main reads user input, encodes it into morse and prints it to stdout
 */
int main()
{
	char s[BUF];
	int i = -1;
	
	fgets(s, BUF, stdin);
	
	while (s[++i] != EOF)
	{
		if (s[i] == ' ')
			putchar('\t');
		else
			printf(" %s", to_morse(s[i]));
	}
	putchar('\n');
}
