#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_STUDENT 25

enum action
{
    ADD, 
    FIND,
    EXIT
};

typedef struct
{
    int ID;
    char name[8];
    float score;

} Student;

int fileOpen(FILE** _fp, char* _file_name, char* _mode);
int selectAction(void);
int printStudentInfo(Student* _info);
int addStudentInfo(FILE* _fp, Student* _info);
long findStudent(FILE* _fp, Student* _info);

int main(void)
{
    FILE* fp = NULL;
    Student data = {0, };
    fileOpen(&fp, "StudentDB", "ab+");

    while(1)
    {
        switch (selectAction())
        {
        case ADD:
            addStudentInfo(fp, &data);
            break;
        case FIND:
            if(findStudent(fp, &data) < 0)
                printf("Cannot find the student\n");
            else
                printStudentInfo(&data);
            break;
        case EXIT:
            exit(0);
            break;
        default:
            break;
        }
    }
}

int selectAction(void)
{
    int sel = 0;
    printf("[%d]add [%d]find [%d]exit: ", ADD, FIND, EXIT);
    scanf("%d", &sel);

    return sel;
}

int printStudentInfo(Student* _info)
{
    printf("%d %s %.2f\n", _info->ID, _info->name, _info->score);
}

int addStudentInfo(FILE* _fp, Student* _info)
{
    printf("Enter ID Name Score: ");
    scanf("%d %s %f", &_info->ID, (char*) &_info->name, &_info->score);
    getchar();

    fseek(_fp, 0, SEEK_END);
    fwrite(_info, sizeof(Student), 1, _fp);

    return 0;
}

long findStudent(FILE* _fp, Student* _info)
{
    char name[255] = {0, };
    printf("Name: ");
    scanf("%s", name);
    getchar();

    int element_size = sizeof(Student);
    fseek(_fp, 0, SEEK_SET);

    while(!feof(_fp))
    {
        fread(_info, element_size, 1, _fp);
        if(strcmp(_info->name, name) == 0)
        {
            fseek(_fp, -element_size, SEEK_CUR);
            return ftell(_fp);
        }
    }

    return -1;
}

int fileOpen(FILE** _fp, char* _file_name, char* _mode)
{
    *_fp = fopen(_file_name, _mode);
    if(!*_fp)
    {
        printf("Fail to open - %s\n", _file_name);
        return -1;
    }

    return 0;
}