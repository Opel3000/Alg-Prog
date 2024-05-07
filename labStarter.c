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
            else lab3(); //т.к. практика была сделана заранее
            break;
        case 4:
            if (SorH == 1) lab4();
            else lab4(); //т.к. практика была сделана заранее
            break;
        case 5:
            if (SorH == 1) lab5();
            else lab5WithDop();
            break;
        case 6:
            if (SorH == 1) lab6();
            else piramidkaSort();
            break;
        case 7:
            if (SorH == 1) lab7();
            else printf("This lab not live \n"); //lab7();
            break;
        case 404:
            poligon();
            break;
        default:
            printf("You select not correct number lab, try again, but use 1-7 for number lab and 1-2 for difficulty");
    }
    char d;
    while(d = getchar() != '-'){}
    return 0;
}
