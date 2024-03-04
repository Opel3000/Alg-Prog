#include <stdio.h>

//��������: �������� ��������� ���������, ������ 1338, ����� � ������ 11


//������� ��� ���������� ����� � �������
//����: (double x - ���������� �����), (short degree - ������� ����������)
//�����: (double newX - ����� x ����������� � ������� degree)
double myPow(double x, short degree){
    double newX = x;
	for(short i = 0; i < degree-1; i++){
		newX=newX*x;
	}
	//printf("%lf", newX); //����� ���������� �������
	return newX;
}


//����������� ������� ��� ���������� ����� ������������������ �� ������������ �2
//����: (int bot - ���������, int top - �����������, short sig - ���� ��� ����������� �����, float summa - ���� �����, float e - �������� �(��. ��������))
//�����: (float summa - ����� ������������������)
float recurs(int bot, int top, short sig, float summa, float e){
    float num = ((float)top)/((float)bot);
    if (sig == 0) sig = 1;
    else sig = 0;
    if (num > e){
       if (sig == 1) summa+=num;
       else summa-=num;
       return recurs(bot*2, top+1, sig, summa, e);
    }
   else return summa;
}


//
short findVowel(int letter){
    char vowel[] = "aeiouyAEIOUY"; //������� ������ �������� ������� ���� ��� ���������� ������
    for (short i = 0; i < (sizeof(vowel) / sizeof(vowel[0])); i++) //�������� �� �������
    {
        if (letter == vowel[i]) return 1;
    }
    return 0;
}


//��: ��������� P = x^4-3x^2+11x-8
void lab1(){
    double x, p;      //���������� ����������(����� � float, � �� ����������� ���)
    scanf("%lf", &x); //��������� ���� � ���������
    p = myPow(x, 4) - myPow((3*x), 2) + 11*x - 8; //������ �� ��
    printf("%lf", p); //����� ����������
}


//��: ��������� ����� ������ ��������� ����: (1-2/2+3/4-4/8). ���������� ���������, ���� ������ ���������� �������� ������ e.
void lab2(){
    float e;
    scanf("%f", &e); //��������� ���� � ���������
    unsigned short topNum = 1; //���������
    unsigned short botNum = 1; //�����������
    unsigned short i = 1; //����� �������� ������������������
    float summa = 0; //�����
    //(��� ������ ����) ��� ������� ������������� ������������� ������� �����, ������� ���������� �������������� ��� ��������� ����� � ���������
    float num = (float)topNum/(float)botNum;

    while (num > e) //���� ������ �������� ������ e
    {
        if (i % 2 == 0) //����������� �������� ����� �������� ����
        {
            summa -= num;
        }
        else
        {
            summa += num;
        }

        topNum++;
        botNum*=2;
        //(��� ������ ����) ��� ������� ������������� ������������� ������� �����, ������� ���������� �������������� ��� ��������� ����� � ���������
        num = ((float)topNum)/((float)botNum);
        i++;

    }
    printf("%f", summa);
}


//��: � ������ �������� ��������� ����� ����, �� ���������� ������� ����.
void lab3(){

    int str;
    int countWord = 0; //�������� ���������� ����
    unsigned short flagNewCorrectWord = 1; //���� ���������� �� �����������
    unsigned short flagVowel = 1;      //���� ���������� �� ��, ��� ����� �������� �� �������


    while ((str = getchar()) != EOF)       //������ ����������� stdin, �������� ������ �� ����� �����
    {
        if (str == ' ' || str == '.'|| str == ',' || str == '\n') // "\n" �����������, ������� ���������� ����� ������� ����� enter
        {
            if (flagVowel == 0) countWord++;  //����� ��������

            flagNewCorrectWord = 1;
            flagVowel = 1;
        }
        else { //����������� �����
            if (flagNewCorrectWord == 0) continue; //���� ����� ��� �� �������� ���������� ��� ��������� �����

            flagVowel = findVowel(str); //�������� �� �������

            if (flagVowel == 1) flagNewCorrectWord = 0;//���� ����������� �������, ��������, ��� ������� ����� �� ��������
        }
    }
    printf("%d", countWord);
}



void lab4(){
    //����� ����� 4
}


/*��: � ������� �� 10 ����� ����� �������� ��� �������� ��������, ���� �� �����
������ ����� ������ ���������. � ��������� ������ �������� ��� ������
��������. */
void lab5(){

    int long_arr;
    scanf("%i Enter long array ", &long_arr);

    short coutnOddNum = 0; //������� �����
    short coutnEvenNum = 0; //������� ���
    int arr[long_arr]; //��� ������

    for (short i = 0; i < long_arr; i++) //���������� ������� + ������� ���/�����
    {
        scanf("%d", &arr[i]);
        if (arr[i] % 2 == 0) coutnEvenNum++;
        else coutnOddNum++;

    }

    for (short i = 0; i < long_arr; i++) //��������� ��������� �� ������� � ��
    {
        if (coutnOddNum < coutnEvenNum)
        {
            if (arr[i] % 2 == 1) arr[i] = 0; //�����
        }
        else
        {
            if(arr[i] % 2 == 0) arr[i] = 0; //���
        }
    }

    for (short i = 0; i < long_arr; i++) //����� �������
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}



void lab6(){
    //����� ����� 4
}



void lab7(){
    //����� ����� 4
}


//��: ��������� ����� ������ ��������� ����: (1-2/2+3/4-4/8). ���������� ���������, ���� ������ ���������� �������� ������ e.
//�����: ������ ����� ������������ ��������
void lab2WithRecurs(){
    float e;
    scanf("%f", &e); //��������� ���� � ���������
    int topNum = 1; //���������
    int botNum = 1; //�����������
    float summa = 0; //�����

    summa = recurs(botNum, topNum, 0, summa, e);
    printf("%f", summa);

}


/*Test lab
���1:
�������� ����: (3)
�������� �����: (25.0)

���2:
�������� ����: (0.5)
�������� �����: (0.750)

���3:
�������� ����: (,tteR ,.. eiOy.g,htDb wFdG)
�������� �����: (3)

���4:
�������� ����: ()
�������� �����: ()

���5:
�������� ����: (3)
�������� �����: (25.0)

���6:
�������� ����: (3)
�������� �����: (25.0)

���7:
�������� ����: (3)
�������� �����: (25.0)
*/
