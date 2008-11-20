/*
 * Machine oriented programming
 * Chalmers University of Technology
 * Lab 3
 * Task 1: Translate to morse code
 */

#include <stdio.h>
#include <stddef.h>

#define MAX		29
#define BUF		100

int index_of(char);
const char * to_morse(char);

/*
 * Two-dimensional array consisting of A-Ö and a-ö
 */
const char letters[2][MAX] = {{65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 
	77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 197, 196, 214},{97, 
	98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 
	113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 229, 228, 246}};

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
int index_of(char c)
{
	int i;
	for (i = 0; letters[0][i] != c && letters[1][i] != c && i < MAX; i++)
		;
	if (i == MAX)
		i = -1;
	return i;
}

/*
 * to_morse takes a character and returns the morse code equivalent
 */
const char * to_morse(char c)
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
	
	while (s[i++] != EOF)
	{
		if (s[i] == ' ')
			putchar('\t');
		else
			printf("%s ", to_morse(s[i]));
	}
	putchar('\n');
}
