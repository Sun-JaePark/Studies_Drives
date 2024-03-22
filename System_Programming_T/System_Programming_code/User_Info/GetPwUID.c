#include <unistd.h>
#include <stdio.h>
#include <pwd.h>

int main(void)
{
    struct passwd* pw;

    pw = getpwuid(getuid());

    printf("UID: %d\n", (int)pw->pw_uid);
    printf("Login Name: %s\n", pw->pw_name);
    printf("Password: %s\n", pw->pw_passwd);
    printf("GID: %d\n", (int)pw->pw_gid);
    printf("Real Name: %s\n", pw->pw_gecos);
    printf("Home dir.: %s\n", pw->pw_dir);
    printf("Shell Program: %s\n", pw->pw_shell);
    
    return 0;
}