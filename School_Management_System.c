/**********************|| A Project Work on SCHOOL MANAGEMENT SYSTEM ||**********************/
/*------------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
FILE *ptr, *ptr_cpy;
void insert_specific_record();
void insert_whole_record();
void display_specific_record();
void display_whole_record();
void search_record_by_student_ID();
void search_record_by_s_name();
void search_record_by_class();
void search_record_by_age();
void search_record_by_roll();
void result(int *);
void modify_record();
void copy_whole_data_in_array_structure();
void sort_record_by_student_ID();
void sort_record_by_s_name();
void sort_record_by_class();
void sort_record_by_age();
void sort_record_by_roll();
void display_sorted_record(int *);
void delete_record();
void confirmation();
struct student
{
    int student_ID;
    char s_name[20];
    char f_name[20];
    char m_name[20];
    struct date_of_birth
    {
        int day;
        int month;
        int year;
    } dob;
    char blood_group[5];
    int age;
    char address[100];
    char class[10];
    char sec;
    int roll;
    struct date_of_add
    {
        int day;
        int month;
        int year;
    } doa;
} stud, stud_sort[10], temp;
int i = 0;
int main()
{
    int choice;
    do
    {
        printf("\n********************||SCHOOL MANAGEMENT SYSTEM||********************\n");
        printf("\n--------------------------------------------------------------------\n");
        printf("\nEnter 1 to INSERT records.\n");
        printf("\nEnter 2 to DISPLAY records.\n");
        printf("\nEnter 3 to SEARCH any record.\n");
        printf("\nEnter 4 to MODIFY any record.\n");
        printf("\nEnter 5 to SORT the inserted records.\n");
        printf("\nEnter 6 to DELETE any record.\n");
        printf("\nEnter 7 to EXIT.\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            fflush(stdin);
            insert_whole_record();
            break;
        case 2:
            display_whole_record();
            break;
        case 3:
            do
            {
                printf("\nEnter 1 to search record by Student ID.\n");
                printf("\nEnter 2 to search record by Student's Name.\n");
                printf("\nEnter 3 to search record by Student's Class.\n");
                printf("\nEnter 4 to search record by Student's Age.\n");
                printf("\nEnter 5 to search record by Student's Roll No..\n");
                printf("\nEnter 0 for MAIN MENU.\n");
                printf("\nEnter your choice: ");
                scanf("%d", &choice);
                switch (choice)
                {
                case 1:
                    search_record_by_student_ID();
                    break;
                case 2:
                    fflush(stdin);
                    search_record_by_s_name();
                    break;
                case 3:
                    fflush(stdin);
                    search_record_by_class();
                    break;
                case 4:
                    search_record_by_age();
                    break;
                case 5:
                    search_record_by_roll();
                    break;
                case 0:
                    main();
                default:
                    printf("\nInvalid Input.\n");
                    printf("Choose options only from the menu.\n");
                    break;
                }
                printf("\nPress any key to continue ... ");
                getch();
                printf("\n");
            } while (1);
            break;
        case 4:
            fflush(stdin);
            modify_record();
            break;
        case 5:
            ptr = fopen("School_Management_System.txt", "rb");
            if (ptr == NULL)
            {
                printf("\nNo records found.\n");
                fclose(ptr);
            }
            else
            {
                copy_whole_data_in_array_structure();
                do
                {
                    printf("\nEnter 1 to sort record by Student ID.\n");
                    printf("\nEnter 2 to sort record by Student's Name.\n");
                    printf("\nEnter 3 to sort record by Student's Class.\n");
                    printf("\nEnter 4 to sort record by Student's Age.\n");
                    printf("\nEnter 5 to sort record by Student's Roll No..\n");
                    printf("\nEnter 0 for MAIN MENU.\n");
                    printf("\nEnter your choice: ");
                    scanf("%d", &choice);
                    switch (choice)
                    {
                    case 1:
                        sort_record_by_student_ID();
                        break;
                    case 2:
                        sort_record_by_s_name();
                        break;
                    case 3:
                        sort_record_by_class();
                        break;
                    case 4:
                        sort_record_by_age();
                        break;
                    case 5:
                        sort_record_by_roll();
                        break;
                    case 0:
                        main();
                    default:
                        printf("\nInvalid Input.\n");
                        printf("Choose options only from the menu.\n");
                        break;
                    }
                    printf("\nPress any key to continue ... ");
                    getch();
                    printf("\n");
                } while (1);
            }
            break;
        case 6:
            fflush(stdin);
            delete_record();
            break;
        case 7:
            fflush(stdin);
            confirmation();
            break;
        default:
            printf("\nInvalid Input.\n");
            printf("Choose options only from the menu.\n");
        }
        printf("\nPress any key to continue ... ");
        getch();
        printf("\n");
    } while (1);
    return 0;
}
void insert_specific_record()
{
    printf("\nSTUDENT DETAILS\n\n");
    printf("Enter Student ID: ");
    scanf("%d", &stud.student_ID);
    fflush(stdin);
    printf("Enter Student's Name: ");
    gets(stud.s_name);
    fflush(stdin);
    printf("Enter Father's Name: ");
    gets(stud.f_name);
    fflush(stdin);
    printf("Enter Mother's Name: ");
    gets(stud.m_name);
    printf("Enter Date of Birth(DD/MM/YYYY): ");
    scanf("%d%d%d", &stud.dob.day, &stud.dob.month, &stud.dob.year);
    fflush(stdin);
    printf("Enter Blood Group: ");
    gets(stud.blood_group);
    printf("Enter Age: ");
    scanf("%d", &stud.age);
    fflush(stdin);
    printf("Enter Full Address: ");
    gets(stud.address);
    fflush(stdin);
    printf("Enter Class: ");
    gets(stud.class);
    fflush(stdin);
    printf("Enter Section: ");
    scanf("%c", &stud.sec);
    printf("Enter Roll No.: ");
    scanf("%d", &stud.roll);
    printf("Enter Date of Admission(DD/MM/YYYY): ");
    scanf("%d%d%d", &stud.doa.day, &stud.doa.month, &stud.doa.year);
    fwrite(&stud, sizeof(stud), 1, ptr);
}
void insert_whole_record()
{
    ptr = fopen("School_Management_System.txt", "ab");
    char ch;
    do
    {
        insert_specific_record();
        fflush(stdin);
        printf("\nDo you want to add more records[Y/N]: ");
        scanf("%c", &ch);
    } while (ch == 'y' || ch == 'Y');
    fclose(ptr);
}
void display_specific_record()
{
    printf("Student ID: %d\n", stud.student_ID);
    printf("Student's Name: %s\tFather's Name: %s\n", stud.s_name, stud.f_name);
    printf("Mother's Name: %s\tDate of Birth: %d/%d/%d\n", stud.m_name, stud.dob.day, stud.dob.month, stud.dob.year);
    printf("Blood Group: %s\t\t\tAge: %d\n", stud.blood_group, stud.age);
    printf("Full Address: %s\n", stud.address);
    printf("Class: %s\t\tSection: %c\t\tRoll No.: %d\n", stud.class, stud.sec, stud.roll);
    printf("Date of Admission: %d/%d/%d\n\n", stud.doa.day, stud.doa.month, stud.doa.year);
}
void display_whole_record()
{
    ptr = fopen("School_Management_System.txt", "rb");
    if (ptr == NULL)
    {
        printf("\nNo records found.\n");
        return;
    }
    printf("\nDisplaying records:\n\n");
    while (fread(&stud, sizeof(stud), 1, ptr) == 1)
    {
        display_specific_record();
    }
    fclose(ptr);
}
void search_record_by_student_ID()
{
    int student_ID, count = 0;
    ptr = fopen("School_Management_System.txt", "rb");
    if (ptr == NULL)
    {
        printf("\nNo records found.\n");
        return;
    }
    printf("\nEnter Student ID: ");
    scanf("%d", &student_ID);
    while (fread(&stud, sizeof(stud), 1, ptr) == 1)
    {
        if (stud.student_ID == student_ID)
        {
            printf("\n");
            display_specific_record();
            count++;
        }
    }
    fclose(ptr);
    result(&count);
}
void search_record_by_s_name()
{
    int count = 0;
    char search_name[20];
    ptr = fopen("School_Management_System.txt", "rb");
    if (ptr == NULL)
    {
        printf("\nNo records found.\n");
        return;
    }
    printf("\nEnter Student's Name: ");
    gets(search_name);
    while (fread(&stud, sizeof(stud), 1, ptr) == 1)
    {
        if (strcmpi(stud.s_name, search_name) == 0)
        {
            printf("\n");
            display_specific_record();
            count++;
        }
    }
    fclose(ptr);
    result(&count);
}
void search_record_by_class()
{
    int count = 0;
    char search_name[20];
    ptr = fopen("School_Management_System.txt", "rb");
    if (ptr == NULL)
    {
        printf("\nNo records found.\n");
        return;
    }
    printf("\nEnter Class: ");
    gets(search_name);
    while (fread(&stud, sizeof(stud), 1, ptr) == 1)
    {
        if (strcmpi(stud.class, search_name) == 0)
        {
            printf("\n");
            display_specific_record();
            count++;
        }
    }
    fclose(ptr);
    result(&count);
}
void search_record_by_age()
{
    int age, count = 0;
    ptr = fopen("School_Management_System.txt", "rb");
    if (ptr == NULL)
    {
        printf("\nNo records found.\n");
        return;
    }
    printf("\nEnter Age: ");
    scanf("%d", &age);
    while (fread(&stud, sizeof(stud), 1, ptr) == 1)
    {
        if (stud.age == age)
        {
            printf("\n");
            display_specific_record();
            count++;
        }
    }
    fclose(ptr);
    result(&count);
}
void search_record_by_roll()
{
    int roll, count = 0;
    ptr = fopen("School_Management_System.txt", "rb");
    if (ptr == NULL)
    {
        printf("\nNo records found.\n");
        return;
    }
    printf("\nEnter Roll No.: ");
    scanf("%d", &roll);
    while (fread(&stud, sizeof(stud), 1, ptr) == 1)
    {
        if (stud.roll == roll)
        {
            printf("\n");
            display_specific_record();
            count++;
        }
    }
    fclose(ptr);
    result(&count);
}

void result(int *count)
{
    if (*count > 0)
    {
        printf("Record got searched.\n");
        printf("%d search(s) found.\n", *count);
    }
    else
    {
        printf("\n\nInvalid input!Record not found.\n");
    }
}
void modify_record()
{
    int student_ID, flag = 0;
    long si = sizeof(stud);
    char ch;
    ptr = fopen("School_Management_System.txt", "rb+");
    if (ptr == NULL)
    {
        printf("\nNo records found.\n");
        return;
    }
    printf("\nEnter Student ID: ");
    scanf("%d", &student_ID);
    while (fread(&stud, sizeof(stud), 1, ptr) == 1)
    {
        if (stud.student_ID == student_ID)
        {
            flag = 1;
            printf("\n");
            display_specific_record();
            fflush(stdin);
            printf("Do you really want to modify this record?[Y/N]: ");
            scanf("%c", &ch);
            if (ch == 'y' || ch == 'Y')
            {
                break;
            }
            else
            {
                fclose(ptr);
                return;
            }
        }
    }
    if (flag == 1)
    {
        fseek(ptr, -si, 1);
        printf("\nEnter new data to modify this record: \n");
        insert_specific_record();
        printf("\nRecord modified successfully.\n");
    }
    else
    {
        printf("\nRecord not found.\n");
    }
    fclose(ptr);
}
void copy_whole_data_in_array_structure()
{
    i = 0;
    ptr = fopen("School_Management_System.txt", "rb");
    while (fread(&stud, sizeof(stud), 1, ptr) == 1)
    {
        stud_sort[i].student_ID = stud.student_ID;
        strcpy(stud_sort[i].s_name, stud.s_name);
        strcpy(stud_sort[i].f_name, stud.f_name);
        strcpy(stud_sort[i].m_name, stud.m_name);
        stud_sort[i].dob = stud.dob;
        strcpy(stud_sort[i].blood_group, stud.blood_group);
        stud_sort[i].age = stud.age;
        strcpy(stud_sort[i].address, stud.address);
        strcpy(stud_sort[i].class, stud.class);
        stud_sort[i].sec = stud.sec;
        stud_sort[i].roll = stud.roll;
        stud_sort[i].doa = stud.doa;
        i++;
    }
    fclose(ptr);
}
void sort_record_by_student_ID()
{
    for (int j = 0; j < i - 1; j++)
    {
        for (int k = j + 1; k < i; k++)
        {
            if (stud_sort[j].student_ID > stud_sort[k].student_ID)
            {
                temp = stud_sort[j];
                stud_sort[j] = stud_sort[k];
                stud_sort[k] = temp;
            }
        }
    }
    printf("\nDisplaying records after sorting:\n\n");
    display_sorted_record(&i);
    printf("Records sorted successfully.\n");
}
void sort_record_by_s_name()
{
    for (int j = 0; j < i - 1; j++)
    {
        for (int k = j + 1; k < i; k++)
        {
            if (strcmpi(stud_sort[j].s_name, stud_sort[k].s_name) > 0)
            {
                temp = stud_sort[j];
                stud_sort[j] = stud_sort[k];
                stud_sort[k] = temp;
            }
        }
    }
    printf("\nDisplaying records after sorting:\n\n");
    display_sorted_record(&i);
    printf("Records sorted successfully.\n");
}
void sort_record_by_class()
{
    for (int j = 0; j < i - 1; j++)
    {
        for (int k = j + 1; k < i; k++)
        {
            if (strcmpi(stud_sort[j].class, stud_sort[k].class) > 0)
            {
                temp = stud_sort[j];
                stud_sort[j] = stud_sort[k];
                stud_sort[k] = temp;
            }
        }
    }
    printf("\nDisplaying records after sorting:\n\n");
    display_sorted_record(&i);
    printf("Records sorted successfully.\n");
}
void sort_record_by_age()
{
    for (int j = 0; j < i - 1; j++)
    {
        for (int k = j + 1; k < i; k++)
        {
            if (stud_sort[j].age > stud_sort[k].age)
            {
                temp = stud_sort[j];
                stud_sort[j] = stud_sort[k];
                stud_sort[k] = temp;
            }
        }
    }
    printf("\nDisplaying records after sorting:\n\n");
    display_sorted_record(&i);
    printf("Records sorted successfully.\n");
}
void sort_record_by_roll()
{
    for (int j = 0; j < i - 1; j++)
    {
        for (int k = j + 1; k < i; k++)
        {
            if (stud_sort[j].roll > stud_sort[k].roll)
            {
                temp = stud_sort[j];
                stud_sort[j] = stud_sort[k];
                stud_sort[k] = temp;
            }
        }
    }
    printf("\nDisplaying records after sorting:\n\n");
    display_sorted_record(&i);
    printf("Records sorted successfully.\n");
}
void display_sorted_record(int *m)
{
    for (int x = 0; x < *m; x++)
    {
        printf("Student ID: %d\n", stud_sort[x].student_ID);
        printf("Student's Name: %s\tFather's Name: %s\n", stud_sort[x].s_name, stud_sort[x].f_name);
        printf("Mother's Name: %s\tDate of Birth: %d/%d/%d\n", stud_sort[x].m_name, stud_sort[x].dob.day, stud_sort[x].dob.month, stud_sort[x].dob.year);
        printf("Blood Group: %s\t\t\tAge: %d\n", stud_sort[x].blood_group, stud_sort[x].age);
        printf("Full Address: %s\n", stud_sort[x].address);
        printf("Class: %s\t\tSection: %c\t\tRoll No.: %d\n", stud_sort[x].class, stud_sort[x].sec, stud_sort[x].roll);
        printf("Date of Admission: %d/%d/%d\n\n", stud_sort[x].doa.day, stud_sort[x].doa.month, stud_sort[x].doa.year);
    }
}
void delete_record()
{
    int student_ID, flag = 0;
    char ch;
    ptr = fopen("School_Management_System.txt", "rb");
    if (ptr == NULL)
    {
        printf("\nNo records found.\n");
        return;
    }
    ptr_cpy = fopen("Temp.txt", "wb");
    printf("\nEnter Student ID: ");
    scanf("%d", &student_ID);
    while (fread(&stud, sizeof(stud), 1, ptr) == 1)
    {
        if (stud.student_ID != student_ID)
        {
            fwrite(&stud, sizeof(stud), 1, ptr_cpy);
        }
        else
        {
            printf("\n");
            display_specific_record();
            flag = 1;
        }
    }
    fclose(ptr);
    fclose(ptr_cpy);
    if (flag == 1)
    {
        fflush(stdin);
        printf("\n\nDo you want to continue[Y/N]: ");
        scanf("%c", &ch);
        if (ch == 'y' || ch == 'Y')
        {
            remove("School_Management_System.txt");
            rename("Temp.txt", "School_Management_System.txt");
            printf("\nRecord deleted successfully.\n");
        }
        else
        {
            remove("Temp.txt");
            return;
        }
    }
    else
    {
        printf("\nRecord not found.\n");
        remove("Temp.txt");
    }
}
void confirmation()
{
    char ch;
    printf("\nARE YOU SURE?[Y/N]: ");
    scanf("%c", &ch);
    if (ch == 'y' || ch == 'Y')
    {
        printf("\nProgram exited successfully.\n");
        exit(0);
    }
    else
    {
        return;
    }
}