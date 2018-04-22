#include <stdio.h>

int
main(int argc, char *argv[])
{
	int year;
	int month;
	int day;
	int week_of_day;
	char *a_day[15];
	int real_year;
	int real_month;
	
	printf("year：");
	scanf("%d", &year);
	printf("month：");
	scanf("%d", &month);
	printf("day：");
	scanf("%d", &day);
	
	real_year = year;
	real_month = month;
	
	// month = 1 → (month = 13, year--), month = 2 → (month = 14, year--)
	switch(month) {
		case 1:
			month = 13;
			year--;
			break;
		case 2:
			month = 14;
			year--;
			break;
		default:
			break;
	}
	
	// Zeller's congruence
	week_of_day = (year + year/4 - year/100 + year/400 + (13*month + 8)/5 + day)%7;
	
	switch(week_of_day) {
		case 0:
			strcpy(a_day, "Sunday");
			break;
		case 1:
			strcpy(a_day, "Monday");
			break;
		case 2:
			strcpy(a_day, "Tuesday");
			break;
		case 3:
			strcpy(a_day, "Wednesday");
			break;
		case 4:
			strcpy(a_day, "Thursday");
			break;
		case 5:
			strcpy(a_day, "Friday");
			break;
		default:
			strcpy(a_day, "Saturday");
			break;
	}
	
	printf("%d/%d/%d is %s.\n", real_year, real_month, day, a_day);
	
	return 0;
}
