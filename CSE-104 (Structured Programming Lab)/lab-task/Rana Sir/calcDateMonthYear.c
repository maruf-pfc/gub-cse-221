// calculate date, month, year;
#include <stdio.h>

int main(){
    int y1, m1, d1, y2, m2, d2, year, month, date;
    printf("Enter 1st date: ");
    scanf("%d:%d:%d", &y1, &m1, &d1);
    printf("Enter 2nd date: ");
    scanf("%d:%d:%d", &y2, &m2, &d2);

    if(d1 < d2){
        d1 = d1 + 30;
        m2++;
    }
    if(m1 < m2){
        m1 = m1 + 12;
        y2++;
    }

    year = y1 - y2;
    month = m1 - m2;
    date = d1 - d2;

    printf("%d:%d:%d", year, month, date);

    return 0;
}