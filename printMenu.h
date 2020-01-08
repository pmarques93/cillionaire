#include <stdio.h>

/* print the option menu */
void printMenu(void)
{	
	puts("********************************************");
	puts("***            CILLIONAIRE                 *");
	puts("********************************************");
	puts("*** n <name>     - new game                *");
	puts("*** q            - quit                    *");
	puts("*** h            - show this menu          *");
	puts("*** r <filename> - resume game             *");
	puts("*** s <filename> - save progress and quit  *");
	puts("*** j 50         - play 50:50 joker        *");
	puts("*** j 25         - play 25:75 joker        *");
	puts("*** c            - show credits            *");
	puts("********************************************");
}