// checkout pseudo-code at the bottom of this file.
// Type `Ctrl + F` to find "Pseudo Code"

#include <stdbool.h>
#include <stdio.h>

bool is_leap(int year);

int main(void) {

  int last_day_of_month[13] = {0,  31, 28, 31, 30, 31, 30,
                               31, 31, 30, 31, 30, 31};
  int day, month, year;

  scanf("%d%d%d", &day, &month, &year);

  // if leap year, max day of month 2 equal 29
  if (is_leap(year) == 1)
    last_day_of_month[2] = 29;

  day++;
  if (day > last_day_of_month[month]) {
    day = 1;
    month++;
    if (month > 12) {
      month = 1;
      year++;
    }
  }

  printf("%02d/%02d/%02d", day, month, year);

  return 0;
}

bool is_leap(int year) {
  bool output = false;
  /*
  year % 400 == 0:
      true
  else:
      if (year % 4 == 0 && year % 100 != 0):
          true
      else:
          false
  */
  if (year % 400 == 0)
    output = true;
  else if (year % 4 == 0 && year % 100 != 0)
    output = true;
  else
    output = false;
  return output;
}
// -*- Pseudo Code -*-
/* Show the next day

stdin: 3 integers decribe current day.
    6 8 2000
stdout: 3 integers decribe the next day.
    7 8 2000
solution:
    Get max day of month (max_day)
    day++
    if day > max_day
        day = 1
        month++
        if month > 12
            month = 1
            year++
*/