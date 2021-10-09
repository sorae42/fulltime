/*
 * fulltime - Tell the time in full-formatted text
 *
 * Author: Rosetta / skyventuree / sora
 *
 */ 
#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[])
{
	const char numbers[12][7] = {"twelve", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven"};

	const char extras[10][10] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

	time_t now = time(NULL);
	struct tm *tm_struct = localtime(&now);
	int hour = tm_struct->tm_hour;
	int minute = tm_struct->tm_min;

	if (hour >= 12) hour = hour - 12;

	if( minute == 0 ) printf("%s o' clock\n", numbers[hour]);
	else if ( minute == 15 ) printf("quarter past %s\n", numbers[hour]);
	else if ( minute == 30 ) printf("half past %s\n", numbers[hour]);
	else if ( minute == 45 ) printf("quarter to %s\n", numbers[hour]);
	else if ( minute < 30 ) {
		if ( minute <= 10 ) printf("%s past %s\n", numbers[minute], numbers[hour]);
		else if (minute < 20 ) printf("%s past %s\n", extras[minute-10],numbers[hour]);
		else if (minute == 20 ) printf("twenty past %s\n", numbers[hour]);
		else printf("twenty-%s past %s\n", numbers[minute-20], numbers[hour]);
	}
	else {
		if ( minute <= 40 ) printf("twenty-%s to %s\n", numbers[10-(minute-30)], numbers[hour]);
		else if (minute == 40 ) printf("twenty to %s\n", numbers[hour]);
		else if (minute < 50 ) printf("twenty-%s to %s\n", numbers[10-(minute-40)], numbers[hour]);
		else printf("%s to %s\n", numbers[10-(minute-50)], numbers[hour]);
	}

	return 0;
}
