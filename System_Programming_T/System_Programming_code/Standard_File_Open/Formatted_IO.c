#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int ID;
    char name[8];
    float score;

} Student;

int fileOpen(FILE** _fp, char* _file_name, char* _mode);

int main(void)
{
    Student info = {0, };
    char* file_name = "StudentList.txt";
    FILE* fp = NULL;

    int num_student = 0;
    float sum = .0f;

    if(fileOpen(&fp, file_name, "a") < 0)
        exit(1);
    
    while(1)
    {
        printf("Enter ID Name Score (Exit: -1): ");
        scanf("%d", &info.ID);

        if(info.ID < 0)
            break;
        
        scanf("%s %f", (char*) &info.name, &info.score);
        getchar();

        fprintf(fp, "%d %s %.1f\n", info.ID, info.name, info.score);
    }

    fclose(fp);

    if(fileOpen(&fp, file_name, "r") < 0)
        exit(1);

    while(!feof(fp))
    {
        fscanf(fp, "%d %s %f\n", &info.ID, (char*) &info.name, &info.score);
        sum += info.score;
        num_student++;
    }

    printf("%d students, Average = %.2f\n", num_student, sum/num_student);

    fclose(fp);

    return 0;
}   

int fileOpen(FILE** _fp, char* _file_name, char* _mode)
{
    *_fp = fopen(_file_name, _mode);
    if(! *_fp)
    {
        printf("Fail to open - %s\n", _file_name);
        return -1;
    }
    return 0;
}