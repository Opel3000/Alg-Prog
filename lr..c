#include <stdio.h>
#include <stdlib.h>

#define LONGARRLAB5 10
#define SIZEPIRAMID 10

//Âûïîëíèë: Ñåðååíêî Àëåêñàíäð Ðîìàíîâè÷, ãðóïïà 1338, íîìåð â ñïèñêå 11


//ôóíêöèÿ äëÿ âîçâåäåíèÿ ÷èñëà â ñòåïåíü
//âõîä: (double x - ñîçâîäèìîå ÷èñëî), (short degree - ñòåïåíü âîçâåäåíèå)
//âûõîä: (double newX - ÷èñëî x âîçâåäåííîå â ñòåïåíü degree)
double myPow(double x, short degree){
    double newX = x;
	for(short i = 0; i < degree-1; i++){
		newX=newX*x;
	}
	//printf("%lf", newX); //âûâîä ðåçóëüòàòà ôóíêöèè
	return newX;
}


//ðåêóðñèâíàÿ ôóíêöèÿ äëÿ âû÷èñëåíèÿ ñóììû ïñîëåäîâàòåëüíîñòè èç ëàáîðàòîðíîé ¹2
//âõîä: (int bot - ÷èñëèòåëü, int top - çíàìèíàòåëü, short sig - ôëàã äëÿ îïðåäåëåíèÿ çíàêà, float summa - ñàìà ñóììà, float e - çíà÷åíèå å(ñì. óñëîâìèå))
//âûõîä: (float summa - ñóììà ïîñëåäîâàòåëüíîñòè)
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


//ôóíêèöÿ äëÿ ïðîâåðêè áóêâû íà ãëàñíóþ
//âõîä: (int letter - áóêâà â ASCII)
//âûõîä: (0 - ñîãëàñíàÿ, 1 - ãëàâíàÿ)
short findVowel(char letter){
    char vowel[12] = "aeiouyAEIOUY"; //ñîçäàåì ìàññèâ ïåðå÷åíÿ ãëàñíûõ áóêâ äëÿ äàëüíåéøåé ñâåðêè
    for (short i = 0; i < (sizeof(vowel) / sizeof(vowel[0])); i++) //ïðîâåðêà íà ãëàñíûå
    {
        if (letter == vowel[i]) return 1;
    }
    return 0;
}


//ôóíêöèÿ äëÿ ÷òåíèÿ stdin äî îïðåäåëåííîãî çíà÷åíèÿ èëè EOF
//âõîä: (size - ðàçìåð ìàññèâà)
//âûõîä: (ââåäåííàÿ ñòðîêà)
char *inputSting(size_t size){

    getchar();
    char letter;
    char *arrayStr = (char*) calloc(size, sizeof(char));
    int countLongStr = 0;
    while ((letter = getchar()) != EOF){       //÷èòàåì ïîñèìâîëüíî stdin, ïðîâåðÿÿ ñèìâîë íà êîíåö ôàéëà

        if (countLongStr == size) {
            arrayStr[size-1]='\0';
            //printf(" %c==", letter); ///ÀÍÎÌÀËÈß
            return arrayStr; //çàùèòà îò ïåðåïîëíåíèÿ
        }
        else arrayStr[countLongStr] = letter;
        countLongStr++;
    }
    arrayStr[countLongStr]='\0';
    return arrayStr;
}


//ôóíêöèÿ ïðîâåðÿþùàÿ ðàçäåëèòåëü ëè
//âõîä: (letter - òåêóùèé ñèìâîë)
//âûõîä: (åñëè ðàçäåëèòåëü - 1, èíà÷å 0)
int checkWalls(char letter){
    char wall[5] = "., \n\0"; //ñîçäàåì ìàññèâ ïåðå÷åíÿ ðàçäåëèòåëåé äëÿ äàëüíåéøåé ñâåðêè
    for (short i = 0; i < (sizeof(wall) / sizeof(wall[0])); i++)
    {
        if (letter == wall[i]) return 1;
    }
    return 0;
}


//ôóíêöèÿ äëÿ ïîèñêà ñëîâ íåïîäõîäÿùèõ ïîä óñëîâèå(ê óäàëåíèþ)
//âõîä: (size - ðàçìåð ìàññèâà, strMass - ñàìà ñòðîêà)
//âûõîä: (ìàññèâ, ãäå ÷åòíûé ýëåìåíò - ÿ÷åéêà íà÷àëà ñëîâà, à êàæäûé íå÷åòíûé - åãî êîíåö)
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


//ðåêóðñèâíàÿ ôóíêöèÿ äëÿ óäàëåíèÿ ñëîâ ïî ïîçèöèè
//âõîä: (size - ðàçìåð ìàññèâà, strMass - ñàìà ñòðîêà, startMas - ìàññèâ êîîðäèíàò äëÿ óäàëåíèÿ, iter - èòåðàöèÿ ðåêóðñèè, longDelWords - êîëè÷ñòâî óäàë¸ííûõ ñèìâîëîâ)
//âûõîä: (î÷èùåííûé îò íå÷åñòè ìàññèâ)
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



void siftDown(int* numbers, int root, int bottom){
    int maxChild; // èíäåêñ ìàêñèìàëüíîãî ïîòîìêà
    int done = 0; // ôëàã òîãî, ÷òî êó÷à ñôîðìèðîâàíà
    // Ïîêà íå äîøëè äî ïîñëåäíåãî ðÿäà
    while ((root * 2 <= bottom) && (!done))
    {
        if (root * 2 == bottom)    // åñëè ìû â ïîñëåäíåì ðÿäó,
            maxChild = root * 2;    // çàïîìèíàåì ëåâûé ïîòîìîê
        // èíà÷å çàïîìèíàåì áîëüøèé ïîòîìîê èç äâóõ
        else if (numbers[root * 2] > numbers[root * 2 + 1])
            maxChild = root * 2;
        else
            maxChild = root * 2 + 1;
        // åñëè ýëåìåíò âåðøèíû ìåíüøå ìàêñèìàëüíîãî ïîòîìêà
        if (numbers[root] < numbers[maxChild])
        {
            int temp = numbers[root]; // ìåíÿåì èõ ìåñòàìè
            numbers[root] = numbers[maxChild];
            numbers[maxChild] = temp;
            root = maxChild;
        }
        else // èíà÷å
            done = 1; // ïèðàìèäà ñôîðìèðîâàíà
    }
}


void heapSort(int* numbers, int array_size){
    // Ôîðìèðóåì íèæíèé ðÿä ïèðàìèäû
    for (int i = (array_size / 2); i >= 0; i--)
        siftDown(numbers, i, array_size - 1);
    // Ïðîñåèâàåì ÷åðåç ïèðàìèäó îñòàëüíûå ýëåìåíòû
    for (int i = array_size - 1; i >= 1; i--)
    {
        int temp = numbers[0];
        numbers[0] = numbers[i];
        numbers[i] = temp;
        siftDown(numbers, 0, i - 1);
    }
}


void piramidkaSort(){
    int a[SIZEPIRAMID];
    // Ðàíäîì çàïîëíåíèå ìàññèâà
    for (int i = 0; i < SIZEPIRAMID; i++)
        a[i] = rand() % 201 - 100;
    // Âûâîä
    for (int i = 0; i < SIZEPIRAMID; i++)
        printf("%d ", a[i]);
    printf("\n");
    heapSort(a, SIZEPIRAMID);
    // Âûâîä
    for (int i = 0; i < SIZEPIRAMID; i++)
        printf("%d ", a[i]);
    printf("\n");
    getchar();
    return 0;
}


//ÒÇ: Âû÷èñëèòü P = x^4-3x^2+11x-8
void lab1(){
    double x, p;      //îïðåäåëÿåì ïåðåìåííûå(ìîæíî è float, â ÒÇ îãðàíè÷åíèé íåò)
    scanf("%lf", &x); //ñ÷èòûâàåì ââîä ñ òåðìèíàëà
    p = myPow(x, 4) - myPow((3*x), 2) + 11*x - 8; //ðàñ÷åò ïî ÒÇ
    printf("%lf", p); //âûâîä ðåçóëüòàòà
}


//ÒÇ: Âû÷èñëèòü ñóììó ïåðâûõ ýëåìåíòîâ ðÿäà: (1-2/2+3/4-4/8). Âû÷èñëåíèÿ ïðîâîäèòü, ïîêà ìîäóëü î÷åðåäíîãî ýëåìåíòà áîëüøå e.
void lab2(){
    float e;
    scanf("%f", &e); //ñ÷èòûâàåì ââîä ñ òåðìèíàëà
    unsigned short topNum = 1; //÷èñëèòåëü
    unsigned short botNum = 1; //çíàìåíàòåëü
    unsigned short i = 1; //íîìåð èòåðàöèè ïîñëåäîâàòåëüíîñòè
    float summa = 0; //ñóììà
    //(ïðî ñòðîêó íèæå) ïðè äåëåíèè öåëî÷èñëåííûõ îòáðàñûâàåòñÿ äðîáíàÿ ÷àñòü, ïîýòîìó èñïîëüçóåì ïðåîáðàçîâàíèå äëÿ ïîëó÷åíèÿ ÷èñëà ñ îòñòàòêîì
    float num = (float)topNum/(float)botNum;

    while (num > e) //ïîêà ìîäóëü ýëåìåíòà áîëüøå e
    {
        if (i % 2 == 0) //îïðåäåëåíèå òåêóùåãî çíàêà ýëåìåíòà ðÿäà
        {
            summa -= num;
        }
        else
        {
            summa += num;
        }

        topNum++;
        botNum*=2;
        //(ïðî ñòðîêó íèæå) ïðè äåëåíèè öåëî÷èñëåííûõ îòáðàñûâàåòñÿ äðîáíàÿ ÷àñòü, ïîýòîìó èñïîëüçóåì ïðåîáðàçîâàíèå äëÿ ïîëó÷åíèÿ ÷èñëà ñ îòñòàòêîì
        num = ((float)topNum)/((float)botNum);
        i++;

    }
    printf("%f", summa);
}


//ÒÇ: Â ïîòîêå ñèìâîëîâ ñîñ÷èòàòü ÷èñëî ñëîâ, íå ñîäåðæàùèõ ãëàñíûõ áóêâ.
void lab3(){

    char str;
    int countWord = 0; //ñ÷åòò÷èê ïîäõîäÿùèõ ñëîâ
    unsigned short flagNewCorrectWord = 1; //ôëàã îòâå÷àþùèé çà ðàçäåëèòåëè
    unsigned short flagVowel = 1;      //ôëàã îòâå÷àþùèé çà òî, ÷òî ñëîâî ïîäõîäèò ïî óñëîâèþ


    while ((str = getchar()) != EOF)       //÷èòàåì ïîñèìâîëüíî stdin, ïðîâåðÿÿ ñèìâîë íà êîíåö ôàéëà
    {
        if (str == ' ' || str == '.'|| str == ',' || str == '\n') // "\n" ðàçäåëèòåëü, êîòîðûé ïîÿâëÿåòñÿ ìåæäó ââîäàìè ÷åðåç enter
        {
            if (flagVowel == 0) countWord++;  //ñëîâî ïîäõîäèò

            flagNewCorrectWord = 1;
            flagVowel = 1;
        }
        else { //âñòðåòèëàñü áóêâà
            if (flagNewCorrectWord == 0) continue; //åñëè ñëîâî óæå íå ïîäõîäèò ïðîïóñêàåì âñþ îñòàëüíóþ ÷àñòü

            flagVowel = findVowel(str); //ïðîâåðêà íà ãëàñíûé

            if (flagVowel == 1) flagNewCorrectWord = 0;//åñëè âñòðåòèëàñü ãëàñíàÿ, ñîîáùàåì, ÷òî òåêóùåå ñëîâî íå ïîäõîäèò
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


/*ÒÇ: Â ìàññèâå èç 10 öåëûõ ÷èñåë îáíóëèòü âñå íå÷¸òíûå ýëåìåíòû, åñëè èõ ÷èñëî
ìåíüøå ÷èñëà ÷¸òíûõ ýëåìåíòîâ. Â ïðîòèâíîì ñëó÷àå îáíóëèòü âñå ÷¸òíûå
ýëåìåíòû. */
void lab5(){

    int long_arr;
    long_arr = 10;
    //scanf("%i Enter long array ", &long_arr);

    short coutnOddNum = 0; //ñ÷åò÷èê íå÷åò
    short coutnEvenNum = 0; //ñ÷åò÷èê ÷åò
    int arr[long_arr]; //ñàì ìàññèâ

    for (short i = 0; i < long_arr; i++) //çàïîëíåíèå ìàññèâà + ïîäñ÷åò ÷åò/íå÷åò
    {
        scanf("%d", &arr[i]);
        if (arr[i] % 2 == 0)
            coutnEvenNum++;
        else
            coutnOddNum++;

    }

    for (short i = 0; i < long_arr; i++) //îáíóëåíèå ýëåìåíòîâ ïî óñëîâèþ â ÒÇ
    {
        if (coutnOddNum < coutnEvenNum){
            if (arr[i] % 2 == 1) arr[i] = 0; //íå÷åò
        }
        else{
            if(arr[i] % 2 == 0) arr[i] = 0; //÷åò
        }
    }

    for (short i = 0; i < long_arr; i++) //âûâîä ìàññèâà
        printf("%d ", arr[i]);
}


/*ÒÇ: Â äâóìåðíîì öåëî÷èñëåííîì ìàññèâå ðàçìåðà N íà K îáíóëèòü äèàãîíàëü ñ
ìàêñèìàëüíîé ñóììîé ýëåìåíòîâ. Ñëåäóåò ðàññìîòðåòü âñå äèàãîíàëè, à íå
òîëüêî ãëàâíûå*/
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


//ÒÇ: Âû÷èñëèòü ñóììó ïåðâûõ ýëåìåíòîâ ðÿäà: (1-2/2+3/4-4/8). Âû÷èñëåíèÿ ïðîâîäèòü, ïîêà ìîäóëü î÷åðåäíîãî ýëåìåíòà áîëüøå e.
//ÄîïÒÇ: âìåñòî öèêëà èñïîëüçîâàòü ðåêóðñèþ
void lab2WithRecurs(){
    float e;
    scanf("%f", &e); //ñ÷èòûâàåì ââîä ñ òåðìèíàëà
    int topNum = 1; //÷èñëèòåëü
    int botNum = 1; //çíàìåíàòåëü
    float summa = 0; //ñóììà

    summa = recurs(botNum, topNum, 0, summa, e);
    printf("%f", summa);

}



void lab5WithDop(){

    //scanf("%i Enter long array ", &long_arr);

    size_t arrButBuffLong = 100;

    short coutnOddNum = 0; //ñ÷åò÷èê íå÷åò
    short coutnEvenNum = 0; //ñ÷åò÷èê ÷åò
    //int arr[LONGARRLAB5]; //ñàì ìàññèâ

    char *arrButBuff = inputSting(arrButBuffLong);
    int *arr = str2intArray(arrButBuffLong, arrButBuff);

    for (int i = 0; i < LONGARRLAB5; i++) //çàïîëíåíèå ìàññèâà + ïîäñ÷åò ÷åò/íå÷åò
    {
        if (arr[i] % 2 == 0)
            coutnEvenNum++;
        else
            coutnOddNum++;
    }

    for (int i = 0; i < LONGARRLAB5; i++) //îáíóëåíèå ýëåìåíòîâ ïî óñëîâèþ â ÒÇ
    {
        if (coutnOddNum < coutnEvenNum){
            if (arr[i] % 2 == 1) arr[i] = 0; //íå÷åò
        }
        else{
            if(arr[i] % 2 == 0) arr[i] = 0; //÷åò
        }
    }

    for (short i = 0; i < LONGARRLAB5; i++) //âûâîä ìàññèâà
        printf("%i ", arr[i]);
}



//ïîëèãîí äëÿ èñïûòàíèé
void poligon(){
    float summa = 5.5;
    printf("%i", matrixDiagonalKiller(summa, 3, 6, 1));
}

