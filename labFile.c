#include <stdio.h>
#include <stdlib.h>

#define LONGARRLAB5 10

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


//������� ��� �������� ����� �� �������
//����: (int letter - ����� � ASCII)
//�����: (0 - ���������, 1 - �������)
short findVowel(char letter){
    char vowel[12] = "aeiouyAEIOUY"; //������� ������ �������� ������� ���� ��� ���������� ������
    for (short i = 0; i < (sizeof(vowel) / sizeof(vowel[0])); i++) //�������� �� �������
    {
        if (letter == vowel[i]) return 1;
    }
    return 0;
}


//������� ��� ������ stdin �� ������������� �������� ��� EOF
//����: (size - ������ �������)
//�����: (��������� ������)
char *inputSting(size_t size){

    getchar();
    char letter;
    char *arrayStr = (char*) calloc(size, sizeof(char));
    int countLongStr = 0;
    while ((letter = getchar()) != EOF){       //������ ����������� stdin, �������� ������ �� ����� �����

        if (countLongStr == size) {
            arrayStr[size-1]='\0';
            //printf(" %c==", letter); ///��������
            return arrayStr; //������ �� ������������
        }
        else arrayStr[countLongStr] = letter;
        countLongStr++;
    }
    arrayStr[countLongStr]='\0';
    return arrayStr;
}


//������� ����������� ����������� ��
//����: (letter - ������� ������)
//�����: (���� ����������� - 1, ����� 0)
int checkWalls(char letter){
    char wall[5] = "., \n\0"; //������� ������ �������� ������������ ��� ���������� ������
    for (short i = 0; i < (sizeof(wall) / sizeof(wall[0])); i++)
    {
        if (letter == wall[i]) return 1;
    }
    return 0;
}


//������� ��� ������ ���� ������������ ��� �������(� ��������)
//����: (size - ������ �������, strMass - ���� ������)
//�����: (������, ��� ������ ������� - ������ ������ �����, � ������ �������� - ��� �����)
int *detectWords(size_t size, char *strMas){
    short countVowel = 0;
    short countConsonant = 0;
    short countDC = 0;
    int flagVowel = 0;

    int *deleteCoords = (int*) calloc(size, sizeof(int));

    for(short i = 0; strMas[i] != '\0'; i++){
        if (checkWalls(strMas[i])){
                //printf("%c \n",strMass[i]);
            if ((countVowel > countConsonant) && ((countVowel != 0) || (countConsonant != 0)))
            {
                deleteCoords[countDC] = i-(countVowel+countConsonant)-1;
                deleteCoords[countDC+1] = i-1;
                countDC+=2;
                //printf("%i - %i \n", i-(countVowel+countConsonant)-1, i-1);
            }

            countVowel = 0;
            countConsonant = 0;
        }
        else {
            flagVowel = findVowel(strMas[i]);
            if (flagVowel == 1) countVowel++;
            else countConsonant++;

        }
    }
    return deleteCoords;
}


//����������� ������� ��� �������� ���� �� �������
//����: (size - ������ �������, strMass - ���� ������, startMas - ������ ��������� ��� ��������, iter - �������� ��������, longDelWords - ��������� �������� ��������)
//�����: (��������� �� ������� ������)
char *deleteWords(size_t size, char *strMas, int *startMas, int iter, int longDelWords){
    longDelWords += startMas[iter+1]-startMas[iter]+1;
    for(int i = startMas[iter]; strMas[i] != '\0'; i++){ //i <= startMas[iter+1]
        strMas[i]=strMas[i+(startMas[iter+1]-startMas[iter])+1];
    }
    //puts(strMas);
    iter+=2;
    startMas[iter] -= longDelWords;
    startMas[iter+1] -= longDelWords;
    //printf("lw %i| smiN %i| \n", longDelWords, startMas[iter]);
    if (startMas[iter] > 0)
        return deleteWords(size, strMas, startMas, iter, longDelWords);
    else
        return strMas;
}


//str to int arr without libs
int *str2intArray(size_t size, char *strMas){
    int *intMas = (int*) calloc(10, sizeof(int));
    int countIntMas = 0;
    int numInStr = 0;

    for (int i = 0; i < size; i++){
        if(countIntMas == 10) break;
        if(checkWalls(strMas[i])){
            intMas[countIntMas] = numInStr;
            countIntMas++;
            numInStr = 0;

        }
        else{
            //printf("%i DA", strMas[i] - '0');
            numInStr = 10*numInStr+(strMas[i] - '0');
        }

    }

    return intMas;
}


int matrixDiagonalKiller(float x, int N, int K, int MorN){
    //printf("%f x", x);
    int y = 0;
    if(MorN)
        y = (x/K)*(-N);
    else
        y = (((x/K)*(N))-N);

    y*=-1;
    return y;
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

    char str;
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

    size_t longStr;
    scanf("%zu", &longStr);

    char *stringArr = inputSting(longStr);
    int *CoodrsStartWords = detectWords(longStr, stringArr);
    char *resultStr = deleteWords(longStr, stringArr, CoodrsStartWords, 0, 0);

    puts(resultStr);
}


/*��: � ������� �� 10 ����� ����� �������� ��� �������� ��������, ���� �� �����
������ ����� ������ ���������. � ��������� ������ �������� ��� ������
��������. */
void lab5(){

    int long_arr;
    long_arr = 10;
    //scanf("%i Enter long array ", &long_arr);

    short coutnOddNum = 0; //������� �����
    short coutnEvenNum = 0; //������� ���
    int arr[long_arr]; //��� ������

    for (short i = 0; i < long_arr; i++) //���������� ������� + ������� ���/�����
    {
        scanf("%d", &arr[i]);
        if (arr[i] % 2 == 0)
            coutnEvenNum++;
        else
            coutnOddNum++;

    }

    for (short i = 0; i < long_arr; i++) //��������� ��������� �� ������� � ��
    {
        if (coutnOddNum < coutnEvenNum){
            if (arr[i] % 2 == 1) arr[i] = 0; //�����
        }
        else{
            if(arr[i] % 2 == 0) arr[i] = 0; //���
        }
    }

    for (short i = 0; i < long_arr; i++) //����� �������
        printf("%d ", arr[i]);
}


/*��: � ��������� ������������� ������� ������� N �� K �������� ��������� �
������������ ������ ���������. ������� ����������� ��� ���������, � ��
������ �������*/
void lab6(){
    int N, K;
    int mainD = 0;
    int mainDNOT = 0;
    scanf("%i", &N);
    scanf("%i", &K);
    int arrMatrix[N][K];

    for(int i = 0; i < N; i++){
        for(int j = 0; j < K; j++){
            printf("Line %i, Column %i ", i, j);
            scanf("%i", &arrMatrix[i][j]);
        }
    }



    for(int i = 0; i < K; i++){
        mainD += arrMatrix[matrixDiagonalKiller((float)i+0.5, N, K, 1)][i];
        mainDNOT += arrMatrix[matrixDiagonalKiller((float)i+0.5, N, K, 0)][i];

        }

    //printf("%i / % i \n", mainDNOT, mainD);
    if(mainDNOT > mainD){
        for(int i = 0; i < K; i++){
            arrMatrix[matrixDiagonalKiller((float)i+0.5, N, K, 0)][i] = 0;
        }
    }

    else if (mainDNOT == mainD){
        for(int i = 0; i < K; i++){
            arrMatrix[matrixDiagonalKiller((float)i+0.5, N, K, 1)][i] = 0;
            arrMatrix[matrixDiagonalKiller((float)i+0.5, N, K, 0)][i] = 0;
        }
    }

    else{
        for(int i = 0; i < K; i++){
            arrMatrix[matrixDiagonalKiller((float)i+0.5, N, K, 1)][i] = 0;
        }

    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < K; j++){
            printf(" %i /", arrMatrix[i][j]);
        }
        printf("\n");
    }
}



void lab7(){
    int N, K;
    printf("Number = ");
    scanf("%i", &N);
    printf("Shift count = ");
    scanf("%i", &K);
    for(int i = 0; i < K; i++){
        N = N >> 1;
    }
    printf("%i", N);
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



void lab5WithDop(){

    //scanf("%i Enter long array ", &long_arr);

    size_t arrButBuffLong = 100;

    short coutnOddNum = 0; //������� �����
    short coutnEvenNum = 0; //������� ���
    //int arr[LONGARRLAB5]; //��� ������

    char *arrButBuff = inputSting(arrButBuffLong);
    int *arr = str2intArray(arrButBuffLong, arrButBuff);

    for (int i = 0; i < LONGARRLAB5; i++) //���������� ������� + ������� ���/�����
    {
        if (arr[i] % 2 == 0)
            coutnEvenNum++;
        else
            coutnOddNum++;
    }

    for (int i = 0; i < LONGARRLAB5; i++) //��������� ��������� �� ������� � ��
    {
        if (coutnOddNum < coutnEvenNum){
            if (arr[i] % 2 == 1) arr[i] = 0; //�����
        }
        else{
            if(arr[i] % 2 == 0) arr[i] = 0; //���
        }
    }

    for (short i = 0; i < LONGARRLAB5; i++) //����� �������
        printf("%i ", arr[i]);
}



//������� ��� ���������
void poligon(){
    float summa = 5.5;
    printf("%i", matrixDiagonalKiller(summa, 3, 6, 1));
}

