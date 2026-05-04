/*
prend en parametre :
- sexe - age - poids - 
taille - activité - bf (optionnel)

OBJECTIF afficher les calories de maintenance
*/
#include <stdio.h>
int str2int(char *str)
{
    int i = 0;
    int digit = 0;
    int temp; 

    if (!((str[i] >= 48) && (str[i] <= 57)
    || (str[i] >= 65) && (str[i] <= 90) ||
    (str[i] >= 97) && (str[i] <= 122)))
        return (1);

    while (str[i])
    {
        temp = str[i] - '0';
        digit = (digit * 10) + temp;
        i++;
    }
    
    //if (str[i] == 46) //poids 70.6
    //    i++;
    return (digit);
}
int char2int(char sexe)
{
    if (!(sexe >= 97) && (sexe <= 122))
        return (1);
    int temp; 
    temp = sexe - '0';
    printf("print sex %d\n", sexe);

    return (temp);
}

int leanlearner(char *age, char *height, char *mass, char sexe)
{
    /*int equation = (mass + height - age) + s;*/
    int result = 0;
    int convertsex = char2int(sexe);
    int intage = str2int(age);
    int intheight = str2int(height);
    int intmass = str2int(mass);
    //printf("intage : %d\n", intage);
    //printf("sex : %d\n", convertsex);
    if (sexe == 102)
        convertsex = convertsex + 5;
    else 
        convertsex = convertsex - 152;
    printf("print sex %d\n", convertsex);
    result = ((10 * intmass) + (6.25 *intheight) - (5 * intage)) - convertsex;
    printf("\nYour Maintenance Calories : %d\n", result);

    return (result);
}


int main (void)
{
    char age[10];
    char height[10];
    char mass[10];
    char sexe;

    printf("+= Welcome2 leanlearner =+\n");

    printf("\nEnter if your a female (f) or if your a male (m) : ");
    scanf("%c", &sexe);
    //printf("le sexe : %c", sexe);
    
    printf("Enter your age (format : '20') : ");
    scanf("%s", age);
    //printf("%s", age);

    printf("\nEnter your height in cm (format ('175') : ");
    scanf("%s", height);
    //printf("%s", height);

    printf("\nEnter your mass (format '70' or '70.6') : ");
    scanf("%s", mass);
    //printf("%s", mass);

    

    leanlearner(age, height, mass, sexe);

    // faire passer age, height, mass dans atoi pour avoir des caractere
    return (0);
    
}