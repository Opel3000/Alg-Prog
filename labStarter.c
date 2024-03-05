#include <stdio.h>
#include "labHeader.h"

int main(){

    int numLab, SorH;
    printf("Chose number lab: ");
    scanf("%i", &numLab);
    printf("Simply(1) or Hard(2): ");
    scanf("%i", &SorH);

    switch (numLab){
        case 1:
            if (SorH == 1) lab1();
            else lab1(); //т.к. практика была сделана заранее
            break;
        case 2:
            if (SorH == 1) lab2();
            else lab2WithRecurs();
            break;
        case 3:
            if (SorH == 1) lab3();
            else if (SorH == 2) printf("This lab not ready \n"); //lab3();
            else lab3WithLibs();
            break;
        case 4:
            if (SorH == 1) printf("This lab not ready \n"); //lab4();
            else printf("This lab not ready \n"); //lab4();
            break;
        case 5:
            if (SorH == 1) lab5();
            else printf("This lab not ready \n"); //lab5();
            break;
        case 6:
            if (SorH == 1) printf("This lab not ready \n"); //lab6();
            else printf("This lab not ready \n"); //lab6();
            break;
        case 7:
            if (SorH == 1) printf("This lab not ready \n"); //lab7();
            else printf("This lab not ready \n"); //lab7();
            break;
        case 404:
            poligon();
            break;
        default:
            printf("You select not correct number lab, try again, but use 1-7 for number lab and 1-2 for difficulty");
    }

    return 0;
}
