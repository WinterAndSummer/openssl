#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/safestack.h>

typedef struct Student_st
{
    char *name;
    int age;
    char *otherInfo;
}Student;


DEFINE_STACK_OF(Student)

Student *Student_Malloc()
{
    Student *a=malloc(sizeof(Student));
    a->name=malloc(20);
    strcpy(a->name,"zcp");
    a->otherInfo=malloc(20);
    strcpy(a->otherInfo,"no info");
    return a;
}

Student *Student_Malloc2()
{
    Student *a=malloc(sizeof(Student));
    a->name=malloc(20);
    strcpy(a->name,"tom");
    a->otherInfo=malloc(20);
    strcpy(a->otherInfo,"no info");
    return a;
}
void Student_Free(Student *a)
{
    free(a->name);
    free(a->otherInfo);
    free(a);
}

static int Student_cmp(Student *a,Student *b)
{
    int ret;

    ret=strcmp(a->name,b->name);
    return ret;
}

int main()
{
    Students *stu_stack1,*stu_stack2;
    Student *stu1,*stu2,*stu3,*stu4,*one;
    int i;

    stu_stack1=sk_Student_new_null();
    stu_stack2=sk_Student_new(Student_cmp);


    stu1=Student_Malloc();
    stu2=Student_Malloc2();
    stu3=Student_Malloc();
    stu4=Student_Malloc2();

    sk_Student_push(stu_stack1,stu1);
    sk_Student_push(stu_stack1,stu2);
    sk_Student_push(stu_stack2,stu3);
    sk_Student_push(stu_stack2,stu4);


    i = sk_Student_find(stu_stack2,stu4);
    printf("i = %d\n",i);
    int num1=sk_Student_num(stu_stack1);
    int num2=sk_Student_num(stu_stack2);

    printf("num1 is %d\n",num1);
    printf("num2 is %d\n",num2);

    printf("=========stu_student1==============\n");
    for(i=0;i<num1;i++)
    {
        one=sk_Student_value(stu_stack1,i);
        printf("student name : %s\n",one->name);
        printf("sutdent age  : %d\n",one->age);
        printf("student otherinfo : %s\n",one->otherInfo);
        printf("======================\n");    
    }
    printf("=========stu_student2==============\n");

    for(i=0;i<num2;i++)
    {
        one=sk_Student_value(stu_stack2,i);
        printf("student name : %s\n",one->name);
        printf("sutdent age  : %d\n",one->age);
        printf("student otherinfo : %s\n",one->otherInfo);
        printf("======================\n");    
    }


    sk_Student_pop_free(stu_stack1,Student_Free);
    sk_Student_pop_free(stu_stack2,Student_Free);
    return 0;
}


