#include <stdio.h>

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


//
short findVowel(int letter){
    char vowel[] = "aeiouyAEIOUY"; //создаем массив переченя гласных букв для дальнейшей сверки
    for (short i = 0; i < (sizeof(vowel) / sizeof(vowel[0])); i++) //проверка на гласные
    {
        if (letter == vowel[i]) return 1;
    }
    return 0;
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

    int str;
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
    //здесь будет 4
}


/*ТЗ: В массиве из 10 целых чисел обнулить все нечётные элементы, если их число
меньше числа чётных элементов. В противном случае обнулить все чётные
элементы. */
void lab5(){

    int long_arr;
    scanf("%i Enter long array ", &long_arr);

    short coutnOddNum = 0; //счетчик нечет
    short coutnEvenNum = 0; //счетчик чет
    int arr[long_arr]; //сам массив

    for (short i = 0; i < long_arr; i++) //заполнение массива + подсчет чет/нечет
    {
        scanf("%d", &arr[i]);
        if (arr[i] % 2 == 0) coutnEvenNum++;
        else coutnOddNum++;

    }

    for (short i = 0; i < long_arr; i++) //обнуление элементов по условию в ТЗ
    {
        if (coutnOddNum < coutnEvenNum)
        {
            if (arr[i] % 2 == 1) arr[i] = 0; //нечет
        }
        else
        {
            if(arr[i] % 2 == 0) arr[i] = 0; //чет
        }
    }

    for (short i = 0; i < long_arr; i++) //вывод массива
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}



void lab6(){
    //здесь будет 4
}



void lab7(){
    //здесь будет 4
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


/*Test lab
Лаб1:
Тестовый ввод: (3)
Тестовый вывод: (25.0)

Лаб2:
Тестовый ввод: (0.5)
Тестовый вывод: (0.750)

Лаб3:
Тестовый ввод: (,tteR ,.. eiOy.g,htDb wFdG)
Тестовый вывод: (3)

Лаб4:
Тестовый ввод: ()
Тестовый вывод: ()

Лаб5:
Тестовый ввод: (3)
Тестовый вывод: (25.0)

Лаб6:
Тестовый ввод: (3)
Тестовый вывод: (25.0)

Лаб7:
Тестовый ввод: (3)
Тестовый вывод: (25.0)
*/
