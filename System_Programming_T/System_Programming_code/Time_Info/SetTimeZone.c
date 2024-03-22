#include <time.h>
#include <stdio.h>

int main(void)
{
    printf("Timezone : %d\n", (int)__timezone);
    printf("Daylight : %d\n", __daylight);
    printf("TZname[0] : %s\n", __tzname[0]);
    printf("TZname[1] : %s\n", __tzname[1]);

    tzset();

    printf("Timezone : %d\n", (int)__timezone);
    printf("Daylight : %d\n", __daylight);
    printf("TZname[0] : %s\n", __tzname[0]);
    printf("TZname[1] : %s\n", __tzname[1]);
    
    return 0;
}