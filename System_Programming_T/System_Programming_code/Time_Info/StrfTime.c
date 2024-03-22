#include <time.h>
#include <stdio.h>

char *output[] = 
{
    "%x %X",
    "%G년 %m월 %d일 %U주 %H:%M",
    "%r"
};

int main(void)
{
    struct tm* tm;
    int n = 0;
    time_t t = 0;
    char buf[257] = {0, };

    time(&t);
    tm = localtime(&t);

    for (n = 0; n < 3; n++)
    {
        strftime(buf, sizeof(buf), output[n], tm);
        printf("%s = %s\n", output[n], buf);
    }
    
    return 0;
}