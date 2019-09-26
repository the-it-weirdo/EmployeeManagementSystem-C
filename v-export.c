/*Headers*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

/*variables
  I thought of giving descriptive names.
  But that was just a thought
*/
int k, j, s, val, iop, ss, sccs=0, srl_num, append_num, mod_srl, var, ret=0, p=0, count=0, _a, _b;
char i[100], cyt, c, _c[10000], initialise[100], surity[20], dtl[10], srl[100], append_number[10], modi_srl[10], remod[100], pass[100], hash[100], new_pass[100], new_hash[100];
char erase_message[]={"¹œ‰œÝŠœŽÝ˜œŽ˜™Ý™ˆ˜Ý‰’ÝÈÝ”“ž’˜ž‰ÝœŽŽŠ’™Ý˜“‰„Ýœ‰‰˜‰Ü\n"};

/*Files*/
FILE *pass_file;
FILE *employee_file;
FILE *branch_file;
FILE *position_file;
FILE *year_of_joining_file;
FILE *college_roll_number_file;
FILE *special_notes_file;
FILE *number_file;
FILE *export_file;

/*Employee structure*/
typedef struct _employee
{
    char name[10000];
    char branch[10000];
    char year[10000];
    char number[10000];
    char position[10000];
    char college_roll[10000];
    char special_notes[10000];
}employee;

/*multiple employee structures*/
employee a[10000];

/*functions declarations*/
int success_message();
void encrypt();
int number_of_line();
int surity_check();
int number();
void new_list();
void old_list();
void append();
void modify();
void detail();
int serial();
void confirm_view_detail();
int password();
void change_pass();
void sort();


/*success_message(): checks existence of all the seven files. Returns -1 if any one of the file is not found. */
int success_message()
{
    employee_file=fopen("EMployee file", "r");
    branch_file = fopen("Branch", "r");
    position_file = fopen("Position", "r");
    year_of_joining_file = fopen("Year of Joining", "r");
    college_roll_number_file = fopen("College Roll Number", "r");
    special_notes_file = fopen("Special Notes", "r");
    number_file=fopen("Number", "r");
   if(employee_file == NULL)
    {
      perror("\tError opening file");
      printf("\a\t***Failure! Employee List NOT FOUND!***\n");
      sccs=-1;
      return(-1);
    }
    else if(employee_file != NULL)
    {
        printf("\n\t\t*Success!* Employee List open successful.\n");
        sccs=0;
        if(branch_file == NULL)
        {
            perror("\tError opening Batch List");
            printf("\t\a***Branch List file NOT FOUND!***");
            sccs=-1;
            return(-1);
        }
        else if(branch_file != NULL)
        {
           printf("\n\t\t*Success!* Batch List open successful.\n");
        }
        if(position_file == NULL)
        {
            perror("\tError opening Position List");
            printf("\t\a***Position List file NOT FOUND!***");
            sccs=-1;
            return(-1);
        }
        else if(position_file != NULL)
        {
           printf("\n\t\t*Success!* Position List open successful.\n");
        }
        if(year_of_joining_file == NULL)
        {
            perror("\tError opening Year of Joining List");
            printf("\t\a***Year of Joining List file NOT FOUND!***");
            sccs=-1;
            return(-1);
        }
        else if(year_of_joining_file != NULL)
        {
           printf("\n\t\t*Success!* Year of Joining List open successful.\n");
        }
        if(college_roll_number_file == NULL)
        {
            perror("\tError opening College Roll Number List");
            printf("\t\a***College Roll Number List file NOT FOUND!***");
            sccs=-1;
            return(-1);
        }
        else if(college_roll_number_file != NULL)
        {
            printf("\n\t\t*Success!* College Roll Number List open successful.\n");
        }
        if(special_notes_file == NULL)
        {
            perror("\tError opening Special Notes List");
            printf("\t\a***Special Notes List file NOT FOUND!***");
            sccs=-1;
            return(-1);
        }
        else if(special_notes_file != NULL)
        {
            printf("\n\t\t*Success!* Special Notes List open successful.\n");
        }
        if(number_file == NULL)
        {
            perror("\tError opening Contact List");
            printf("\t\a***Contact List file NOT FOUND!***");
            sccs=-1;
            return(-1);
        }
        else if(number_file != NULL)
        {
            printf("\n\t\t*Success!* Contact List open successful.\n");
        }
    }
    fclose(employee_file);
    fclose(number_file);
    fclose(branch_file);
    fclose(position_file);
    fclose(year_of_joining_file);
    fclose(college_roll_number_file);
    fclose(special_notes_file);
}


/*encrypt(): 1st call encrypts character by character. 2nd call decrypts character by character*/
void encrypt(char *message)
{
    while(*message!='\n')
    {
        *message = ~(*message ^ 2);
        message++;
    }
}


/*Getting the number of lines in the file(val) when 'o' is entered
  number_of_line() function
*/
int number_of_line()
{
    employee_file = fopen("EMployee file", "r");
    val=0;
    for(c = getc(employee_file); c!=EOF; c= getc(employee_file))
        {
            if(c=='\n')
            {
                val=val+1;
            }
        }
    fclose(employee_file);
    return val;
}


/*surity_check()
  checks if the user is sure to create a new list if a previous list already exist
*/
int surity_check()
{
    employee_file = fopen("EMployee file", "r");
   if(employee_file == NULL)
    {
        ss=1;
    }
    else if(employee_file != NULL)
    {
        ss=0;
    }
    fclose(employee_file);
    system("CLS");
    if(ss==0)
    {
        system("CLS");
        swtc:
        printf("\nAre you sure you want to create a NEW list? Note: The previous list will be ERASED !!\nPress 'Y' for YES or 'N' for NO\n: ");
        //fgets(surity, 5, stdin);
        surity[0]=_getch();
        strupr(surity);
        switch(surity[0])
        {
        case 'N':
            {
                s=1;
                break;
            }
        case 'Y':
            {
                s=0;
                break;
            }
        default:
            {
                printf("\nPlease Enter a Valid entry!!\a");
                goto swtc;
            }
        }
    }
    return s;
}


/*gets the number of employees when 'n' is entered. val & k has the same work. The code is working fine and I don't have the time.
  So I don't think i will change the variable names accordingly.
*/
int number()
{
    nn:
    printf("\nEnter the number of employees you want to add: \n\t## NOTE: Maximum 900 entries. ##\n:");
    fgets(i, 100, stdin);
    k=atoi(i);
    if(k==0 || k>900)
    {
        printf("\n\t\a ### Please enter a VALID number. DO NOT enter 0 or more than 900. ###\n\t ## NOTE: Maximum 900 entries. ##\n");
        goto nn;
    }
    return k;
}


/*Well the name explains the function!*/
void new_list()
{
    system("CLS");
    employee_file=fopen("EMployee file", "w+");
    branch_file = fopen("Branch", "w+");
    position_file = fopen("Position", "w+");
    year_of_joining_file = fopen("Year of Joining", "w+");
    college_roll_number_file = fopen("College Roll Number", "w+");
    special_notes_file = fopen("Special Notes", "w+");
    number_file=fopen("Number", "w+");
    for(j=1; j<=k; j++)
    {
    printf("\n-------------------\n");
    printf("\n%d. Enter employee name: ", j);
    fgets(a[j].name, 100, stdin);
    printf("\nEnter branch of %s: ", a[j].name);
    fgets(a[j].branch, 1000, stdin);
    encrypt(a[j].branch);
    fprintf(branch_file, "%s", a[j].branch);
    printf("\nEnter position of %s: ", a[j].name);
    fgets(a[j].position, 100, stdin);
    encrypt(a[j].position);
    fprintf(position_file, "%s", a[j].position);
    printf("\nEnter phone number of %s: ", a[j].name);
    fgets(a[j].number, 100, stdin);
    encrypt(a[j].number);
    fprintf(number_file, "%s", a[j].number);
    printf("\nEnter year of joining of %s: ", a[j].name);
    fgets(a[j].year, 10000, stdin);
    encrypt(a[j].year);
    fprintf(year_of_joining_file, "%s", a[j].year);
    printf("\nEnter College Roll Number of %s: ", a[j].name);
    fgets(a[j].college_roll, 10000, stdin);
    encrypt(a[j].college_roll);
    fprintf(college_roll_number_file, "%s", a[j].college_roll);
    printf("\nEnter skills of %s: ", a[j].name);
    fgets(a[j].special_notes, 10000, stdin);
    encrypt(a[j].special_notes);
    fprintf(special_notes_file, "%s", a[j].special_notes);
    encrypt(a[j].name);
    fprintf(employee_file, "%s", a[j].name);
    system("CLS");
    }
    fclose(employee_file);
    fclose(number_file);
    fclose(branch_file);
    fclose(position_file);
    fclose(year_of_joining_file);
    fclose(college_roll_number_file);
    fclose(special_notes_file);
    sort();
    success_message();
    system("PAUSE");
}


/*Name explains everything! But this one just shows th employee names!
  You want details? Go find the function!
*/
void old_list()
{
    system("CLS");
    if(success_message()==-1)
    {
        printf("\n\t\a\t*** ERROR! ***\n");
        system("PAUSE");
    }
    else
    {
        system("CLS");
        number_of_line();
        sort();
        employee_file=fopen("EMployee file", "r");
        for(j=1; j<=val; j++)
        {
            fgets(a[j].name, 1000, employee_file);
            encrypt(a[j].name);
        }

        printf("\nThe Employee list is: \n---------------------\n");
        printf("\nSerial Number\t\t\tEmployee Name\n");
        printf("-------------\t\t\t-------------\n");
        for(j=1; j<=val; j++)
        {
            printf("  %d\t\t\t\t %s",j, a[j].name);
        }
    fclose(employee_file);
    system("PAUSE");
    }
}


/*Adds data to existing list*/
void append()
{
    if(success_message()!=-1)
    {
        if(val!=900)
        {
            employee_file=fopen("EMployee file", "a");
            branch_file = fopen("Branch", "a");
            position_file = fopen("Position", "a");
            year_of_joining_file = fopen("Year of Joining", "a");
            college_roll_number_file = fopen("College Roll Number", "a");
            special_notes_file = fopen("Special Notes", "a");
            number_file=fopen("Number", "a");

            dd:
                printf("\n\nEnter the number of employee you want to add to the existing %i employee:\n*NOTE: Maximum more employees that can be added is %i.\n", val, (900-val));
                fgets(append_number, 5, stdin);
                printf("\n");
                append_num = atoi(append_number);
                if(append_num>(900-val))
                {
                    system("CLS");
                    printf("\n\a\t ### NOTE: Maximum more employees that can be added is %i. ###\n", (900-val));
                    goto dd;
                }
                system("CLS");
                printf("\nPlease enter the data of the employees you want to add in the list:\n");
                printf("NOTE: # Maximum %i entries.\n      # Maximum 9000 characters in a line.\n", append_num);
                for(j=(val+1); j<=(val+append_num); j++)
                {
                    printf("%i. ", j);
                    printf("\n-------------------\n");
                    printf("\nEnter employee name: ");
                    fgets(a[j].name, 100, stdin);
                    printf("\nEnter branch of %s: ", a[j].name);
                    fgets(a[j].branch, 1000, stdin);
                    encrypt(a[j].branch);
                    fprintf(branch_file, "%s", a[j].branch);
                    printf("\nEnter position of %s: ", a[j].name);
                    fgets(a[j].position, 100, stdin);
                    encrypt(a[j].position);
                    fprintf(position_file, "%s", a[j].position);
                    printf("\nEnter phone number of %s: ", a[j].name);
                    fgets(a[j].number, 100, stdin);
                    encrypt(a[j].number);
                    fprintf(number_file, "%s", a[j].number);
                    printf("\nEnter year of joining of %s: ", a[j].name);
                    fgets(a[j].year, 10000, stdin);
                    encrypt(a[j].year);
                    fprintf(year_of_joining_file, "%s", a[j].year);
                    printf("\nEnter College Roll Number of %s: ", a[j].name);
                    fgets(a[j].college_roll, 10000, stdin);
                    encrypt(a[j].college_roll);
                    fprintf(college_roll_number_file, "%s", a[j].college_roll);
                    printf("\nEnter skills of %s: ", a[j].name);
                    fgets(a[j].special_notes, 10000, stdin);
                    encrypt(a[j].special_notes);
                    fprintf(special_notes_file, "%s", a[j].special_notes);
                    encrypt(a[j].name);
                    fprintf(employee_file, "%s", a[j].name);
                    system("CLS");
                }

            fclose(employee_file);
            fclose(number_file);
            fclose(branch_file);
            fclose(position_file);
            fclose(year_of_joining_file);
            fclose(college_roll_number_file);
            fclose(special_notes_file);
            success_message();
            system("PAUSE");
        }
        else
        {
            system("CLS");
            printf("\n\n\t ### Error! Maximum number of employee already present!\n\t     NOTE: Maximum 900 employees!\n\a");
            system("PAUSE");
        }
    }
}


/*Descriptive function name again! */
void modify()
{
    system("CLS");
    if(sccs!=-1)
    {
    number_of_line();
    employee_file=fopen("EMployee file", "r");
    branch_file = fopen("Branch", "r");
    position_file = fopen("Position", "r");
    year_of_joining_file = fopen("Year of Joining", "r");
    college_roll_number_file = fopen("College Roll Number", "r");
    special_notes_file = fopen("Special Notes", "r");
    number_file=fopen("Number", "r");
    for(j=1; j<=val; j++)
        {
            fgets(a[j].name, 1000, employee_file);
            encrypt(a[j].name);
            fgets(a[j].branch, 1000, branch_file);
            encrypt(a[j].branch);
            fgets(a[j].position, 1000, position_file);
            encrypt(a[j].position);
            fgets(a[j].number, 1000, number_file);
            encrypt(a[j].number);
            fgets(a[j].year, 1000, year_of_joining_file);
            encrypt(a[j].year);
            fgets(a[j].college_roll, 1000, college_roll_number_file);
            encrypt(a[j].college_roll);
            fgets(a[j].special_notes, 1000, special_notes_file);
            encrypt(a[j].special_notes);
        }
        fclose(employee_file);
        fclose(number_file);
        fclose(branch_file);
        fclose(position_file);
        fclose(year_of_joining_file);
        fclose(college_roll_number_file);
        fclose(special_notes_file);

    mod:
    printf("\nSerial Number of employee: %d.\n---------------------------\n", srl_num);
    printf("\n  Serial Number of data\t\t\tData\t\t\t\t\tValue\n");
    printf("  ______ ______ __ ____\t\t\t____\t\t\t\t\t_____\n");
    printf("  ---------------------\t\t\t----\t\t\t\t\t-----\n");
    printf("    1.\t\t\t\t\tEmployee Name: \t\t\t\t%s\n", a[srl_num].name);
    printf("    2.\t\t\t\t\tBranch: \t\t\t\t%s\n", a[srl_num].branch);
    printf("    3.\t\t\t\t\tDesignation: \t\t\t\t%s\n", a[srl_num].position);
    printf("    4.\t\t\t\t\tContact: \t\t\t\t%s\n", a[srl_num].number);
    printf("    5.\t\t\t\t\tJoining Year: \t\t\t\t%s\n", a[srl_num].year);
    printf("    6.\t\t\t\t\tCollege Roll Number: \t\t\t%s\n", a[srl_num].college_roll);
    printf("    7.\t\t\t\t\tSkills: \t\t\t\t%s\n", a[srl_num].special_notes);
    printf("\n---------------------------\n");
    printf("\nEnter the SERIAL NUMBER of the data you want to modify\n: ");
    fgets(modi_srl, 10, stdin);
    mod_srl=atoi(modi_srl);
    system("CLS");
    switch(mod_srl)
        {
        case 1:
            {
                printf("\nThe current value of Data in Serial Number 1 is: %s", a[srl_num].name);
                printf("\nModification\n------------\n");
                printf("\n  Serial Number of data\t\t\tData\n");
                printf("  ---------------------\t\t\t----\n");
                printf("    1.\t\t\t\t\tEmployee Name:\n");
                printf("\n");
                printf("Value: ");
                fgets(a[srl_num].name, 10000, stdin);
                printf("\nThe updated data is: \n");
                printf("\n  Serial Number of data\t\t\tData\t\t\t\t\tValue\n");
                printf("    1.\t\t\t\t\tEmployee Name: \t\t\t\t%s\n", a[srl_num].name);
                break;
            }
        case 2:
            {
                printf("\nThe current value of Data in Serial Number 2 is: %s", a[srl_num].branch);
                printf("\nModification\n------------\n");
                printf("\n  Serial Number of data\t\t\tData\n");
                printf("  ---------------------\t\t\t----\n");
                printf("    2.\t\t\t\t\tBranch:\n");
                printf("\n");
                printf("Value: ");
                fgets(a[srl_num].branch, 10000, stdin);
                printf("\nThe updated data is: \n");
                printf("\n  Serial Number of data\t\t\tData\t\t\t\t\tValue\n");
                printf("    2.\t\t\t\t\tBranch: \t\t\t\t%s\n", a[srl_num].branch);
                break;
            }
        case 3:
            {
                printf("\nThe current value of Data in Serial Number 3 is: %s", a[srl_num].position);
                printf("\nModification\n------------\n");
                printf("\n  Serial Number of data\t\t\tData\n");
                printf("  ---------------------\t\t\t----\n");
                printf("    3.\t\t\t\t\tDesignation:\n");
                printf("\n");
                printf("Value: ");
                fgets(a[srl_num].position, 10000, stdin);
                printf("\nThe updated data is: \n");
                printf("\n  Serial Number of data\t\t\tData\t\t\t\t\tValue\n");
                printf("    3.\t\t\t\t\tDesignation: \t\t\t\t%s\n", a[srl_num].position);
                break;
            }
        case 4:
            {
                printf("\nThe current value of Data in Serial Number 4 is: %s", a[srl_num].number);
                printf("\nModification\n------------\n");
                printf("\n  Serial Number of data\t\t\tData\n");
                printf("  ---------------------\t\t\t----\n");
                printf("    4.\t\t\t\t\tContact:\n");
                printf("\n");
                printf("Value: ");
                fgets(a[srl_num].number, 10000, stdin);
                printf("\nThe updated data is: \n");
                printf("\n  Serial Number of data\t\t\tData\t\t\t\t\tValue\n");
                printf("    4.\t\t\t\t\tContact: \t\t\t\t%s\n", a[srl_num].number);
                break;
            }
        case 5:
            {
                printf("\nThe current value of Data in Serial Number 5 is: %s", a[srl_num].year);
                printf("\nModification\n------------\n");
                printf("\n  Serial Number of data\t\t\tData\n");
                printf("  ---------------------\t\t\t----\n");
                printf("    5.\t\t\t\t\tJoining Year:\n");
                printf("\n");
                printf("Value: ");
                fgets(a[srl_num].year, 10000, stdin);
                printf("\nThe updated data is: \n");
                printf("\n  Serial Number of data\t\t\tData\t\t\t\t\tValue\n");
                printf("    5.\t\t\t\t\tJoining Year: \t\t\t\t%s\n", a[srl_num].year);
                break;
            }
        case 6:
            {
                printf("\nThe current value of Data in Serial Number 6 is: %s", a[srl_num].college_roll);
                printf("\nModification\n------------\n");
                printf("\n  Serial Number of data\t\t\tData\n");
                printf("  ---------------------\t\t\t----\n");
                printf("    6.\t\t\t\t\tCollege Roll Number:\n");
                printf("\n");
                printf("Value: ");
                fgets(a[srl_num].college_roll, 10000, stdin);
                printf("\nThe updated data is: \n");
                printf("\n  Serial Number of data\t\t\tData\t\t\t\t\tValue\n");
                printf("    6.\t\t\t\t\tCollege Roll Number: \t\t\t\t%s\n", a[srl_num].college_roll);
                break;
            }
        case 7:
            {
                printf("\nThe current value of Data in Serial Number 7 is: %s", a[srl_num].special_notes);
                printf("\nModification\n------------\n");
                printf("\n  Serial Number of data\t\t\tData\n");
                printf("  ---------------------\t\t\t----\n");
                printf("    7.\t\t\t\t\tSkills:\n");
                printf("\n");
                printf("Value: ");
                fgets(a[srl_num].special_notes, 10000, stdin);
                printf("\nThe updated data is: \n");
                printf("\n  Serial Number of data\t\t\tData\t\t\t\t\tValue\n");
                printf("    7.\t\t\t\t\tSkills: \t\t\t\t%s\n", a[srl_num].special_notes);
                break;
            }
        default:
            {
                system("CLS");
                printf("\n\a\t### ERROR! Please enter a VALID SERIAL NUMBER! ###\n");
                system("PAUSE");
                goto mod;
            }
        }
        modd:
        printf("\nDo you want to modify more data of the employee?\nIf 'YES', press 'Y'\nIf 'NO', press 'N'\n:");
        //fgets(remod, 100, stdin);
        remod[0]=_getch();
        strupr(remod);
        switch(remod[0])
        {
            case 'Y':
        {
            system("CLS");
            goto mod;
            break;
        }
            case 'N':
                {
                    system("CLS");
                    break;
                }
            default:
                {
                    system("CLS");
                    printf("\n\t\a### Please provide a valid entry! ###\n");
                    system("PAUSE");
                    goto modd;
                }
        }
    employee_file=fopen("EMployee file", "w+");
    branch_file = fopen("Branch", "w+");
    position_file = fopen("Position", "w+");
    year_of_joining_file = fopen("Year of Joining", "w+");
    college_roll_number_file = fopen("College Roll Number", "w+");
    special_notes_file = fopen("Special Notes", "w+");
    number_file=fopen("Number", "w+");
    for(j=1; j<=val;j++)
    {
    encrypt(a[j].name);
    fprintf(employee_file, "%s", a[j].name);
    encrypt(a[j].branch);
    fprintf(branch_file, "%s", a[j].branch);
    encrypt(a[j].position);
    fprintf(position_file, "%s", a[j].position);
    encrypt(a[j].year);
    fprintf(year_of_joining_file, "%s", a[j].year);
    encrypt(a[j].college_roll);
    fprintf(college_roll_number_file, "%s", a[j].college_roll);
    encrypt(a[j].number);
    fprintf(number_file, "%s", a[j].number);
    encrypt(a[j].special_notes);
    fprintf(special_notes_file, "%s", a[j].special_notes);
    }
    fclose(employee_file);
    fclose(number_file);
    fclose(branch_file);
    fclose(position_file);
    fclose(year_of_joining_file);
    fclose(college_roll_number_file);
    fclose(special_notes_file);
    success_message();
    }
    system("PAUSE");
}


/*VOILA! The details are here!!*/
void detail()
{
    system("CLS");
    employee_file=fopen("EMployee file", "r");
    branch_file = fopen("Branch", "r");
    position_file = fopen("Position", "r");
    year_of_joining_file = fopen("Year of Joining", "r");
    college_roll_number_file = fopen("College Roll Number", "r");
    special_notes_file = fopen("Special Notes", "r");
    number_file=fopen("Number", "r");
    for(j=1; j<=val; j++)
        {
            fgets(a[j].name, 1000, employee_file);
            encrypt(a[j].name);
            fgets(a[j].branch, 1000, branch_file);
            encrypt(a[j].branch);
            fgets(a[j].position, 1000, position_file);
            encrypt(a[j].position);
            fgets(a[j].number, 1000, number_file);
            encrypt(a[j].number);
            fgets(a[j].year, 1000, year_of_joining_file);
            encrypt(a[j].year);
            fgets(a[j].college_roll, 1000, college_roll_number_file);
            encrypt(a[j].college_roll);
            fgets(a[j].special_notes, 1000, special_notes_file);
            encrypt(a[j].special_notes);
        }
    printf("\nSerial Number: %d.\n---------------------------\n", srl_num);
    printf("Employee Name: %s\n", a[srl_num].name);
    printf("Branch: %s\n", a[srl_num].branch);
    printf("Designation: %s\n", a[srl_num].position);
    printf("Contact: %s\n", a[srl_num].number);
    printf("Joining Year: %s\n", a[srl_num].year);
    printf("College Roll Number: %s\n", a[srl_num].college_roll);
    printf("Skills: %s\n", a[srl_num].special_notes);
    printf("\n---------------------------\n");
    fclose(employee_file);
    fclose(number_file);
    fclose(branch_file);
    fclose(position_file);
    fclose(year_of_joining_file);
    fclose(college_roll_number_file);
    fclose(special_notes_file);
    system("PAUSE");
    old_list();
    confirm_view_detail();
}


/*Gets the serial number of employee in the list*/
int serial()
{
    if(sccs!=-1)
    {
    dds:
    printf("\nEnter the SERIAL NUMBER of the employee\n: ");
    fgets(srl, 100, stdin);
    srl_num=atoi(srl);
    if(srl_num>val || srl_num==0)
    {
        printf("\n\a\t### Please enter a valid SERIAL NUMBER! ###\n");
        goto dds;
    }
    return srl_num;
    }
}


/*It does not confirms! It just asks!*/
void confirm_view_detail()
{
    if(sccs!=-1)
    {
    dd:
    printf("\nDo you want to view the detail of any employee?\n1.Press Y for yes\n2.Press N for no & to go back to the main-menu\n");
    //fgets(dtl, 10, stdin);
    dtl[0]=_getch();
    strupr(dtl);
    switch(dtl[0])
    {
    case 'Y':
        {
            serial();
            detail();
            break;
        }
    case 'N':
        {
            system("CLS");
            break;
        }
    default:
        {
            printf("\n\a\t### Please enter a valid entry! ###\n");
            goto dd;
        }
    }
    }
}


/*The password() function.*/
int password()
{
    iop=0;
    pass_file = fopen("2.6", "r");
    if(pass_file==NULL)
    {
        ret=-1;
        printf("\n\a\t\t\t ### Program Failure! Contact Developer! ###\n");
        system("PAUSE");
        return(-1);
    }
    fgets(pass, 100, pass_file);
    fclose(pass_file);
    for(iop=0;pass[iop]!='\0'; iop++)
    {
        pass[iop]= ~(pass[iop]^2);
    }
    //encrypt(pass);
    while(pass[p]!='\0')
    {
        if(pass[p]=='\n')
        {
            pass[p]='\0';
        }
        p++;
    }
    pad:
        iop=0;
        for(iop=0; iop<100; iop++)
        {
            hash[iop]='\0';
        }
        iop=0;
    printf("\n\n\t\t\tEnter password: ");
    //fgets(hash, 100, stdin);
    while(cyt=_getch())
    {
        if(cyt==13)
        {
            break;
        }
        if(cyt==8)
        {
            printf("\b \b");
            iop--;
            hash[iop]='\0';
        }
        else
        {
            printf("@");
            hash[iop]=cyt;
            iop++;
        }
    }
    system("CLS");
    p=0;
    ret=0;
    while(hash[p]!='\0')
    {
        if(hash[p]=='\n')
        {
            hash[p]='\0';
        }
        p++;
    }
    for(var=0; var<strlen(pass); var++)
    {
        if(pass[var]!=hash[var] || strlen(pass)!=strlen(hash))
        {
            printf("\n\t\t\t\a### Password does not match! ###\n");
            ret=1;
            count++;
            break;
        }
    }
    if(count<5 && ret!=0)
    {
        printf("\n\t\t\t ### %d tries remaining! ###", (5-count));
        goto pad;
    }
    if(count>=5)
    {
        employee_file=fopen("EMployee file", "r");
        if(employee_file!=NULL)
        {
    employee_file=fopen("EMployee file", "w");
    branch_file = fopen("Branch", "w");
    position_file = fopen("Position", "w");
    year_of_joining_file = fopen("Year of Joining", "w");
    college_roll_number_file = fopen("College Roll Number", "w");
    special_notes_file = fopen("Special Notes", "w");
    number_file=fopen("Number", "w");
        fprintf(employee_file, erase_message);
        fprintf(branch_file, erase_message);
        fprintf(position_file, erase_message);
        fprintf(year_of_joining_file, erase_message);
        fprintf(college_roll_number_file, erase_message);
        fprintf(special_notes_file, erase_message);
        fprintf(number_file, erase_message);
        fclose(employee_file);
        fclose(number_file);
        fclose(branch_file);
        fclose(position_file);
        fclose(year_of_joining_file);
        fclose(college_roll_number_file);
        fclose(special_notes_file);
        printf("\n\t\t\t ### DATA ERASED! ###\n");
        system("PAUSE");
        }
        else
        {
            fclose(employee_file);
            return(-1);
        }
    }
    return ret;
}

/*change_pass()*/
void change_pass()
{
    count=0;
    pad:
    for(iop=0; iop<100; iop++)
    {
        hash[iop]='\0';
    }
    iop=0;
    printf("\n\n\t\t\tEnter password: ");
    //fgets(hash, 100, stdin);
    while(cyt=_getch())
    {
        if(cyt==13)
        {
            break;
        }
        if(cyt==8)
        {
            printf("\b \b");
            iop--;
            hash[iop]='\0';
        }
        else
        {
            printf("@");
            hash[iop]=cyt;
            iop++;
        }
    }
    system("CLS");
    p=0;
    ret=0;
    while(hash[p]!='\0')
    {
        if(hash[p]=='\n')
        {
            hash[p]='\0';
        }
        p++;
    }
    for(var=0; var<strlen(pass); var++)
    {
        if(pass[var]!=hash[var] || strlen(pass)!=strlen(hash))
        {
            printf("\n\t\t\t\a### Password does not match! ###\n");
            ret=1;
            count++;
            break;
        }
    }
    if(count<5 && ret!=0)
    {
        printf("\n\t\t\t ### %d tries remaining! ###", (5-count));
        goto pad;
    }
    if(count>=5)
    {
    employee_file=fopen("EMployee file", "w");
    branch_file = fopen("Branch", "w");
    position_file = fopen("Position", "w");
    year_of_joining_file = fopen("Year of Joining", "w");
    college_roll_number_file = fopen("College Roll Number", "w");
    special_notes_file = fopen("Special Notes", "w");
    number_file=fopen("Number", "w");
        fprintf(employee_file, erase_message);
        fprintf(branch_file, erase_message);
        fprintf(position_file, erase_message);
        fprintf(year_of_joining_file, erase_message);
        fprintf(college_roll_number_file, erase_message);
        fprintf(special_notes_file, erase_message);
        fprintf(number_file, erase_message);
        fclose(employee_file);
        fclose(number_file);
        fclose(branch_file);
        fclose(position_file);
        fclose(year_of_joining_file);
        fclose(college_roll_number_file);
        fclose(special_notes_file);
        printf("\n\t\t\t ### DATA ERASED! ###\n");
        system("PAUSE");
    }
    if(ret==0)
    {
        klpd:
            iop=0;
            for(iop=0; iop<100; iop++)
            {
                new_pass[iop]='\0';
            }
            iop=0;
        printf("\n\t\tEnter new password: ");
        //fgets(new_pass, 100, stdin);
        while(cyt=_getch())
        {
        if(cyt==13)
        {
            break;
        }
        if(cyt==8)
        {
            printf("\b \b");
        }
        else
        {
            printf("@");
            new_pass[iop]=cyt;
            iop++;
        }
        }
        system("CLS");
        if(strlen(new_pass)<8)
        {
            printf("\n\t\t\t\a# Password must be 8 characters long! #\n");
            goto klpd;
        }
        for(iop=0; iop<100; iop++)
        {
            new_hash[iop]='\0';
        }
        iop=0;
        printf("\n\t\tRe-enter new password: ");
        iop=0;
        //fgets(new_hash, 100, stdin);
        while(cyt=_getch())
    {
        if(cyt==13)
        {
            break;
        }
        if(cyt==8)
        {
            printf("\b \b");
        }
        else
        {
            printf("@");
            new_hash[iop]=cyt;
            iop++;
        }
    }
        if(strcmp(new_pass,new_hash)==0)
        {
            pass_file=fopen("2.6", "w");
            for(iop=0; new_pass[iop]!='\0'; iop++)
            {
                new_pass[iop]= ~(new_pass[iop]^2);
            }
            for(iop=0; new_pass[iop]!='\0'; iop++)
            {
                fputc(new_pass[iop], pass_file);
            }
            fclose(pass_file);
            printf("\n\t\t\t# Password Updated Successfully! #\n");
            system("PAUSE");
        }
        else
        {
            printf("\n\t\t\t\a# Password does not match! #\n");
            goto klpd;
        }
    }
}

void sort()
{
    number_of_line();

    employee_file=fopen("EMployee file", "r");
    branch_file = fopen("Branch", "r");
    position_file = fopen("Position", "r");
    year_of_joining_file = fopen("Year of Joining", "r");
    college_roll_number_file = fopen("College Roll Number", "r");
    special_notes_file = fopen("Special Notes", "r");
    number_file=fopen("Number", "r");

    for(j=1; j<=val; j++)
        {
            fgets(a[j].name, 1000, employee_file);
            encrypt(a[j].name);
            fgets(a[j].branch, 1000, branch_file);
            encrypt(a[j].branch);
            fgets(a[j].position, 1000, position_file);
            encrypt(a[j].position);
            fgets(a[j].number, 1000, number_file);
            encrypt(a[j].number);
            fgets(a[j].year, 1000, year_of_joining_file);
            encrypt(a[j].year);
            fgets(a[j].college_roll, 1000, college_roll_number_file);
            encrypt(a[j].college_roll);
            fgets(a[j].special_notes, 1000, special_notes_file);
            encrypt(a[j].special_notes);
        }

        fclose(employee_file);
        fclose(number_file);
        fclose(branch_file);
        fclose(position_file);
        fclose(year_of_joining_file);
        fclose(college_roll_number_file);
        fclose(special_notes_file);


    employee_file=fopen("EMployee file", "w");
    branch_file = fopen("Branch", "w");
    position_file = fopen("Position", "w");
    year_of_joining_file = fopen("Year of Joining", "w");
    college_roll_number_file = fopen("College Roll Number", "w");
    special_notes_file = fopen("Special Notes", "w");
    number_file=fopen("Number", "w");


    for(_a=1; _a<=val; _a++)
    {
        for(_b=(_a+1); _b<=val; _b++)
        {
            if(strcmpi(a[_a].name, a[_b].name)>0)
            {
                strcpy(_c, a[_a].name);
                strcpy(a[_a].name, a[_b].name);
                strcpy(a[_b].name, _c);

                strcpy(_c, a[_a].branch);
                strcpy(a[_a].branch, a[_b].branch);
                strcpy(a[_b].branch, _c);

                strcpy(_c, a[_a].position);
                strcpy(a[_a].position, a[_b].position);
                strcpy(a[_b].position, _c);

                strcpy(_c, a[_a].number);
                strcpy(a[_a].number, a[_b].number);
                strcpy(a[_b].number, _c);

                strcpy(_c, a[_a].year);
                strcpy(a[_a].year, a[_b].year);
                strcpy(a[_b].year, _c);

                strcpy(_c, a[_a].college_roll);
                strcpy(a[_a].college_roll, a[_b].college_roll);
                strcpy(a[_b].college_roll, _c);

                strcpy(_c, a[_a].special_notes);
                strcpy(a[_a].special_notes, a[_b].special_notes);
                strcpy(a[_b].special_notes, _c);
            }
        }
    }


    for(j=1; j<=val;j++)
    {
    encrypt(a[j].name);
    fprintf(employee_file, "%s", a[j].name);
    encrypt(a[j].branch);
    fprintf(branch_file, "%s", a[j].branch);
    encrypt(a[j].position);
    fprintf(position_file, "%s", a[j].position);
    encrypt(a[j].year);
    fprintf(year_of_joining_file, "%s", a[j].year);
    encrypt(a[j].college_roll);
    fprintf(college_roll_number_file, "%s", a[j].college_roll);
    encrypt(a[j].number);
    fprintf(number_file, "%s", a[j].number);
    encrypt(a[j].special_notes);
    fprintf(special_notes_file, "%s", a[j].special_notes);
    }


        fclose(employee_file);
        fclose(number_file);
        fclose(branch_file);
        fclose(position_file);
        fclose(year_of_joining_file);
        fclose(college_roll_number_file);
        fclose(special_notes_file);
}

void export_()
{
    number_of_line();

    employee_file=fopen("EMployee file", "r");
    branch_file = fopen("Branch", "r");
    position_file = fopen("Position", "r");
    year_of_joining_file = fopen("Year of Joining", "r");
    college_roll_number_file = fopen("College Roll Number", "r");
    special_notes_file = fopen("Special Notes", "r");
    number_file=fopen("Number", "r");
    export_file = fopen("Export.csv", "w");

    for(j=1; j<=val; j++)
        {
            fgets(a[j].name, 1000, employee_file);
            encrypt(a[j].name);
            fgets(a[j].branch, 1000, branch_file);
            encrypt(a[j].branch);
            fgets(a[j].position, 1000, position_file);
            encrypt(a[j].position);
            fgets(a[j].number, 1000, number_file);
            encrypt(a[j].number);
            fgets(a[j].year, 1000, year_of_joining_file);
            encrypt(a[j].year);
            fgets(a[j].college_roll, 1000, college_roll_number_file);
            encrypt(a[j].college_roll);
            fgets(a[j].special_notes, 1000, special_notes_file);
            encrypt(a[j].special_notes);
        }

        fclose(employee_file);
        fclose(number_file);
        fclose(branch_file);
        fclose(position_file);
        fclose(year_of_joining_file);
        fclose(college_roll_number_file);
        fclose(special_notes_file);

        fprintf(export_file, "Name,Branch,Designation,Year,College Roll,Number,Skills,");
        for(j=1; j<=val; j++)
        {
            fprintf(export_file, "\n%s", a[j].name);
            fseek(export_file, -2, SEEK_CUR);
            fprintf(export_file, ",%s", a[j].branch);
            fseek(export_file, -2, SEEK_CUR);
            fprintf(export_file, ",%s", a[j].position);
            fseek(export_file, -2, SEEK_CUR);
            fprintf(export_file, ",%s", a[j].year);
            fseek(export_file, -2, SEEK_CUR);
            fprintf(export_file, ",%s", a[j].college_roll);
            fseek(export_file, -2, SEEK_CUR);
            fprintf(export_file, ",%s", a[j].number);
            fseek(export_file, -2, SEEK_CUR);
            fprintf(export_file, " ,\"=\"\"%s", a[j].special_notes);
            fseek(export_file, -2, SEEK_CUR);
            fprintf(export_file, " \"\"\" ");
        }

        fclose(export_file);
}

/*The main as well as the start menu!*/
int main()
{
    system("COLOR 75");
    system("Title *Employee Handler V-1.4 by Debaleen Das Spandan*");
    printf("\t\t\t\t   # WELCOME!! #\n\t\t*This program has been created by Debaleen Das Spandan.\n\t\t*This program lets you create or view your Employee-list.\n\n");
    system("PAUSE");
    system("CLS");
    password();
    if(ret==0)
    {
    while(initialise[0]!='X')
    {
        system("CLS");
        printf("\n\t\t\t\t\t\t\t Main Menu\n\t\t\t\t\t\t\t~~~~~~~~~~~\n\t\t\t\t\t\t\t-----------\n\t\t\t1.Create a new Employee-list\t\t\t(Press 'N') \n\n\t\t\t\tor\n\n\t\t\t2.View the old Employee-list\t\t\t(Press 'V') \n\n\t\t\t\tor\n\n\t\t\t3.Add data to the old Employee-list\t\t(Press 'A') \n\n\t\t\t\tor\n\n\t\t\t4.Modify data in the old Employee-list\t\t(Press 'M') \n\n\t\t\t\tor\n\n\t\t\t5.Export data from the old Employee-list\t(Press 'E') \n\n\t\t\t\tor\n\n\t\t\t6.Change Password\t\t\t\t('Press 'P') \n\n\t\t\t\tor\n\n\t\t\t7.Exit           \t\t\t\t(Press 'X') ");
        printf("\n\n\t\t\t*NOTE: If you are running the program for first time, create a new Data-list.\n\t\t\t\t\t\t\t      &\n                \t\t\t\t\tChange your password! *\n:");
        //fgets(initialise, 100, stdin);
        initialise[0]=_getch();
        strupr(initialise);
        switch (initialise[0])
        {
        case 'N':
            {
                surity_check();
                if(s==0)
                {
                printf("\n");
                number();
                new_list();
                sort();
                }
                else
                {
                    printf("\nCreating NEW list operation Canceled!\n");
                    system("PAUSE");
                }
                break;
            }
        case 'V':
            {
                printf("\n");
                old_list();
                confirm_view_detail();
                break;
            }
        case 'A':
            {
                old_list();
                append();
                sort();
                break;
            }
        case 'M':
            {
                old_list();
                serial();
                modify();
                sort();
                break;
            }
        case 'X':
            {
                system("CLS");
                break;
            }
        case 'P':
            {
                system("CLS");
                change_pass();
                break;
            }
        case 'E':
            {
                system("CLS");
                password();
                if(ret==0)
                {
                    export_();
                    printf("\nExport to .csv successful.\n");
                    system("PAUSE");
                    break;
                }
            }
        default:
            {
                system("CLS");
                printf("\n\t**ERROR!** Please enter a valid entry!!\a\n");
                system("PAUSE");
            }
        }
    }
    }
    return 0;
}


/*Program works fine. Gotta add some more feature!. And most importantly gotta modify the code and functions.
  I don't know why I have this feeling that although the program works, the code is lousy! :-(
  Gotta do something about it.
*/
