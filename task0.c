/**
 * main - Entry point
 *
 * Description: This is the main function
 * that prints a greeting based on the time of day.
 *
 * Return: Always 0 (Success)
 */
#include <stdio.h>
#include <time.h>

int main(void)
{
	time_t t = time(NULL);
	struct tm *current_time = localtime(&t);
	int hour = current_time->tm_hour;

	switch (hour)
	{
	case 0 ... 11:
		printf("Good morning bruh!\n");
	break;
	case 12 ... 17:
		printf("Good afternoon buddy!\n");
	break;
	case 18 ... 23:
		printf("Good evening my friend!\n");
	break;
	default:
		printf("Hello there boi!\n");
	break;
	}

	return (0);
}
