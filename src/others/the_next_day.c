/* checkout pseudo-code at the bottom of this file.
// Type `Ctrl + F` to find "Pseudo Code" */

#include <stdbool.h>
#include <stdio.h>

bool is_leap(int year);

int main(void) {

    int day, month, year, maxDay;

    printf("Enter dd/mm/yyyy: ");
    scanf("%d/%d/%d", &day, &month, &year);

    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 ||
        month == 10 || month == 12)
        maxDay = 31;
    else if (month == 2)
        maxDay = is_leap(year) == 1 ? 29 : 28;
    else
        maxDay = 30;

    ++day;
    if (day > maxDay) {
        day = 1;
        ++month;
        if (month > 12) {
            month = 1;
            ++year;
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
/* ============ Pseudo Code ============ */
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