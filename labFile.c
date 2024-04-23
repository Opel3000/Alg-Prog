#include <stdio.h>
#include <stdlib.h>

#define LONGARRLAB5 10

//Выполнил: Сереенко Александр Романович, группа 1338, номер в списке 11


//функция для возведения числа в степень
//вход: (double x - созводимое число), (short degree - степень возведение)
//выход: (double newX - число x возведенное в степень degree)
double myPow(double x, short degree){
    double newX = x;
	for(short i = 0; i < degree-1; i++){
		newX=newX*x;
	}
	//printf("%lf", newX); //вывод результата функции
	return newX;
}


//рекурсивная функция для вычисления суммы псоледовательности из лабораторной №2
//вход: (int bot - числитель, int top - знаминатель, short sig - флаг для определения знака, float summa - сама сумма, float e - значение е(см. условмие))
//выход: (float summa - сумма последовательности)
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


//функиця для проверки буквы на гласную
//вход: (int letter - буква в ASCII)
//выход: (0 - согласная, 1 - главная)
short findVowel(char letter){
    char vowel[12] = "aeiouyAEIOUY"; //создаем массив переченя гласных букв для дальнейшей сверки
    for (short i = 0; i < (sizeof(vowel) / sizeof(vowel[0])); i++) //проверка на гласные
    {
        if (letter == vowel[i]) return 1;
    }
    return 0;
}


//функция для чтения stdin до определенного значения или EOF
//вход: (size - размер массива)
//выход: (введенная строка)
char *inputSting(size_t size){

    getchar();
    char letter;
    char *arrayStr = (char*) calloc(size, sizeof(char));
    int countLongStr = 0;
    while ((letter = getchar()) != EOF){       //читаем посимвольно stdin, проверяя символ на конец файла

        if (countLongStr == size) {
            arrayStr[size-1]='\0';
            //printf(" %c==", letter); ///АНОМАЛИЯ
            return arrayStr; //защита от переполнения
        }
        else arrayStr[countLongStr] = letter;
        countLongStr++;
    }
    arrayStr[countLongStr]='\0';
    return arrayStr;
}


//функция проверяющая разделитель ли
//вход: (letter - текущий символ)
//выход: (если разделитель - 1, иначе 0)
int checkWalls(char letter){
    char wall[5] = "., \n\0"; //создаем массив переченя разделителей для дальнейшей сверки
    for (short i = 0; i < (sizeof(wall) / sizeof(wall[0])); i++)
    {
        if (letter == wall[i]) return 1;
    }
    return 0;
}


//функция для поиска слов неподходящих под условие(к удалению)
//вход: (size - размер массива, strMass - сама строка)
//выход: (массив, где четный элемент - ячейка начала слова, а каждый нечетный - его конец)
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


//рекурсивная функция для удаления слов по позиции
//вход: (size - размер массива, strMass - сама строка, startMas - массив координат для удаления, iter - итерация рекурсии, longDelWords - количство удалённых символов)
//выход: (очищенный от нечести массив)
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



//ТЗ: Вычислить P = x^4-3x^2+11x-8
void lab1(){
    double x, p;      //определяем переменные(можно и float, в ТЗ ограничений нет)
    scanf("%lf", &x); //считываем ввод с терминала
    p = myPow(x, 4) - myPow((3*x), 2) + 11*x - 8; //расчет по ТЗ
    printf("%lf", p); //вывод результата
}


//ТЗ: Вычислить сумму первых элементов ряда: (1-2/2+3/4-4/8). Вычисления проводить, пока модуль очередного элемента больше e.
void lab2(){
    float e;
    scanf("%f", &e); //считываем ввод с терминала
    unsigned short topNum = 1; //числитель
    unsigned short botNum = 1; //знаменатель
    unsigned short i = 1; //номер итерации последовательности
    float summa = 0; //сумма
    //(про строку ниже) при делении целочисленных отбрасывается дробная часть, поэтому используем преобразование для получения числа с отстатком
    float num = (float)topNum/(float)botNum;

    while (num > e) //пока модуль элемента больше e
    {
        if (i % 2 == 0) //определение текущего знака элемента ряда
        {
            summa -= num;
        }
        else
        {
            summa += num;
        }

        topNum++;
        botNum*=2;
        //(про строку ниже) при делении целочисленных отбрасывается дробная часть, поэтому используем преобразование для получения числа с отстатком
        num = ((float)topNum)/((float)botNum);
        i++;

    }
    printf("%f", summa);
}


//ТЗ: В потоке символов сосчитать число слов, не содержащих гласных букв.
void lab3(){

    char str;
    int countWord = 0; //счеттчик подходящих слов
    unsigned short flagNewCorrectWord = 1; //флаг отвечающий за разделители
    unsigned short flagVowel = 1;      //флаг отвечающий за то, что слово подходит по условию


    while ((str = getchar()) != EOF)       //читаем посимвольно stdin, проверяя символ на конец файла
    {
        if (str == ' ' || str == '.'|| str == ',' || str == '\n') // "\n" разделитель, который появляется между вводами через enter
        {
            if (flagVowel == 0) countWord++;  //слово подходит

            flagNewCorrectWord = 1;
            flagVowel = 1;
        }
        else { //встретилась буква
            if (flagNewCorrectWord == 0) continue; //если слово уже не подходит пропускаем всю остальную часть

            flagVowel = findVowel(str); //проверка на гласный

            if (flagVowel == 1) flagNewCorrectWord = 0;//если встретилась гласная, сообщаем, что текущее слово не подходит
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


/*ТЗ: В массиве из 10 целых чисел обнулить все нечётные элементы, если их число
меньше числа чётных элементов. В противном случае обнулить все чётные
элементы. */
void lab5(){

    int long_arr;
    long_arr = 10;
    //scanf("%i Enter long array ", &long_arr);

    short coutnOddNum = 0; //счетчик нечет
    short coutnEvenNum = 0; //счетчик чет
    int arr[long_arr]; //сам массив

    for (short i = 0; i < long_arr; i++) //заполнение массива + подсчет чет/нечет
    {
        scanf("%d", &arr[i]);
        if (arr[i] % 2 == 0)
            coutnEvenNum++;
        else
            coutnOddNum++;

    }

    for (short i = 0; i < long_arr; i++) //обнуление элементов по условию в ТЗ
    {
        if (coutnOddNum < coutnEvenNum){
            if (arr[i] % 2 == 1) arr[i] = 0; //нечет
        }
        else{
            if(arr[i] % 2 == 0) arr[i] = 0; //чет
        }
    }

    for (short i = 0; i < long_arr; i++) //вывод массива
        printf("%d ", arr[i]);
}


/*ТЗ: В двумерном целочисленном массиве размера N на K обнулить диагональ с
максимальной суммой элементов. Следует рассмотреть все диагонали, а не
только главные*/
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


//ТЗ: Вычислить сумму первых элементов ряда: (1-2/2+3/4-4/8). Вычисления проводить, пока модуль очередного элемента больше e.
//ДопТЗ: вместо цикла использовать рекурсию
void lab2WithRecurs(){
    float e;
    scanf("%f", &e); //считываем ввод с терминала
    int topNum = 1; //числитель
    int botNum = 1; //знаменатель
    float summa = 0; //сумма

    summa = recurs(botNum, topNum, 0, summa, e);
    printf("%f", summa);

}



void lab5WithDop(){

    //scanf("%i Enter long array ", &long_arr);

    size_t arrButBuffLong = 100;

    short coutnOddNum = 0; //счетчик нечет
    short coutnEvenNum = 0; //счетчик чет
    //int arr[LONGARRLAB5]; //сам массив

    char *arrButBuff = inputSting(arrButBuffLong);
    int *arr = str2intArray(arrButBuffLong, arrButBuff);

    for (int i = 0; i < LONGARRLAB5; i++) //заполнение массива + подсчет чет/нечет
    {
        if (arr[i] % 2 == 0)
            coutnEvenNum++;
        else
            coutnOddNum++;
    }

    for (int i = 0; i < LONGARRLAB5; i++) //обнуление элементов по условию в ТЗ
    {
        if (coutnOddNum < coutnEvenNum){
            if (arr[i] % 2 == 1) arr[i] = 0; //нечет
        }
        else{
            if(arr[i] % 2 == 0) arr[i] = 0; //чет
        }
    }

    for (short i = 0; i < LONGARRLAB5; i++) //вывод массива
        printf("%i ", arr[i]);
}



//полигон для испытаний
void poligon(){
    float summa = 5.5;
    printf("%i", matrixDiagonalKiller(summa, 3, 6, 1));
}

