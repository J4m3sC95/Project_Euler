#include <stdio.h>
#include <inttypes.h>

char *day_string[8] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
char *month_string[13]={"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
uint8_t month_days[] = {
	 /*Jan*/		31,	
	 /*Feb*/	28,
	 /*Mar*/	31,
	 /*Apr*/	30,
	 /*May*/	31,
	 /*Jun*/	30,
	 /*Jul*/		31,
	 /*Aug*/	31,
	 /*Sep*/	30,
	 /*Oct*/	31,
	 /*Nov*/	30,
	 /*Dec*/	31
 };

int main(){
	uint8_t day = 0;
	uint8_t date = 1;
	uint8_t month = 0;
	uint16_t year = 1900;
	uint16_t sunday_count = 0;
	
	month_days[1] = 28;
	
	while(!((year == 2000) && (date == 31) && (month == 11))){
	//while(year != 1901){
		day++;
		if(day == 7){
			day = 0;
		}
		date++;
		if(date> month_days[month]){
			date = 1;
			month++;
			if(month == 12){
				month = 0;
				year++;
				//check if leap year
				if(year == 2000){
					month_days[1] = 29;
				}
				else if((year % 4) == 0){
					month_days[1] = 29;
				}
				else{
					month_days[1] = 28;
				}
			}
		}
		if((date == 1) && (day == 6) && (year > 1900)){
			sunday_count++;			
			//printf("\n%s\t%d\t%s\t%d", day_string[day], date, month_string[month], year);
		}
		//printf("\n%s\t%d\t%s\t%d", day_string[day], date, month_string[month], year);
		
	}			
	
	printf("\n\nThere are %d sundays on the 1st of a month between 1st Jan 1901 and 31 Dec 2000\n\n", sunday_count);
	
	return 0;

}
