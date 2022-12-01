#include <stdio.h>
#include <math.h>
#include <windows.h>

//Invalid License Example: WDKT-19JD-1931-19AN
/*
This is a program designed for people trying to find something to easily reverse engineer or circumvent.
PLEASE DO NOT USE THIS IS ANY OTHER PROGRAMS. THIS IS NOT MADE FOR EFFECTIVELY CHECKING VALID KEYS.
*/
#define LICENSE_SIZE 32

int validA = 0;
int validB = 0;

int is_a_license(char license[])
{
    int license_marks = 0;

    if(license != NULL)
    {
        for(int i = 0; i < LICENSE_SIZE; i++)
        {
            //printf("%s\n", license[i]);
            if(license[i] != '\0' && license[i] != '-')
            {
                license_marks++;
            }
        }
    }


    return license_marks;
}

void check_license(char x_la_carr[])
{
    //Utilizes bad and vague variable names to confuse someone attempting to circumvent or reverse engineer it.

    char f_lb_carr[LICENSE_SIZE];

    int _la_evn_c, _la_odd_c;
    double _la_evn_f, _la_odd_f;

    for(int x_itt = 0; x_itt < LICENSE_SIZE; x_itt++)
    {
        if(x_la_carr[x_itt] != '-' && x_la_carr[x_itt] != '\0')
        {
            f_lb_carr[x_itt] = x_la_carr[x_itt];
            //printf("Arr Elm.: %c\n", f_lb_carr[x_itt]);
        }

        if(x_itt % 2 == 0)
        {
            _la_evn_c = f_lb_carr[x_itt];
            _la_evn_f = floor(sqrt(_la_evn_c));

            if((int)_la_evn_f % 2 == 0)
            {
                validA++;
            }
            else
            {
                validB++;
            }
            //printf("1  [%i]: %0.1f\n", x_itt, _la_evn_f);
        }

        if(x_itt % 2 == 1)
        {
            _la_odd_c = f_lb_carr[x_itt];
            _la_odd_f = floor(sqrt(_la_odd_c));

            if((int)_la_odd_f % 2 == 1)
            {
                validB++;
            }
            else
            {
                validA++;
            }
            //printf("2  [%i]: %0.1f\n", x_itt, _la_odd_f);
        }
    }

    return;
}

int main()
{
    char license[LICENSE_SIZE];
    printf("Please enter a license (ex. AAAA-0000-BBBB-1111)\n");

    scanf("%s", &license);
    printf("\nEntered License: %s", &license);

    if(license == NULL)
    { 
        return 0; 
    }

    int license_marks = is_a_license(license);
    //printf("\nMarks: %i\n", license_marks);

    if(license_marks > 11)
    {
        printf("\n(Success) String is in a license format.");
        check_license(license);

        //printf("\n%i, %i", validA, validB);

        if(validA == validB)
        {
            printf("\n(Success) License is VALID!");
        }
        else
        {
           printf("\n(Failure) License is INVALID!"); 
        }
    }
    else
    {
        printf("\n(Error) String is NOT in a license format.");
    }

    Sleep(5);
    return 0;
}