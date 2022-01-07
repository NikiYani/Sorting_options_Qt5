#include <QCoreApplication>
#include <time.h>
#include <iostream>
#include <QTextStream>
#include <QTextCodec>

using namespace std;

void GenRandArray(int *, const int);
void PrintArray(int *, const int);
void BubbleSort(int *, const int);
void ChoicesSort(int *, const int);
void InsertionSort(int *, const int);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTextStream outStream(stdout);
    outStream.setCodec(QTextCodec::codecForName("cp866"));

    srand(time(0));

    outStream << QString("Введите размерность массива: ") << flush;

    int sizeArray = 0;
    while (sizeArray <= 0){
        cin >> sizeArray;
        if(sizeArray <= 0){
            outStream << QString("Размер массива должен быть положительный!") << flush;
        }
    }

    int *array = new int[sizeArray];
    GenRandArray(array, sizeArray);

    outStream << QString("Массив до сортировки: ") << flush;
    PrintArray(array, sizeArray);

    outStream << QString("Результат сортировки пузырьком (по возрастанию): ") << flush;
    BubbleSort(array, sizeArray);
    PrintArray(array, sizeArray);

    GenRandArray(array, sizeArray);

    outStream << QString("Массив до сортировки: ") << flush;
    PrintArray(array, sizeArray);

    outStream << QString("Результат сортировки выбором (по возрастанию): ") << flush;
    ChoicesSort(array, sizeArray);
    PrintArray(array, sizeArray);

    GenRandArray(array, sizeArray);

    outStream << QString("Массив до сортировки: ") << flush;
    PrintArray(array, sizeArray);

    outStream << QString("Результат сортировки вставками (по возрастанию): ") << flush;
    InsertionSort(array, sizeArray);
    PrintArray(array, sizeArray);

    return a.exec();
}

void GenRandArray(int *array, const int sizeArray)
{
    for(int i = 0; i < sizeArray; i++){
        array[i] = rand() % 100 - rand() % 100;
    }
}

void PrintArray(int *array, const int sizeArray)
{
    for(int i = 0; i < sizeArray; i++){
        cout << array[i] << " ";
    }

    cout << endl;
}

void BubbleSort(int *array, const int sizeArray)
{
    int temp;
    int checkSwap = true;

    while(checkSwap == true){
        checkSwap = false;
        for(int j = 0; j < sizeArray - 1; j++){
            if(array[j] > array[j + 1]){
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                checkSwap = true;
            }
        }
    }
}

void ChoicesSort(int *array, const int sizeArray)
{
    int temp;
    int sortIter = 0;

    for(int i = 0; i < sizeArray; i++){
        for(int j = sortIter; j < sizeArray - 1; j++){
            if(array[sortIter] > array[j + 1]){
                temp = array[sortIter];
                array[sortIter] = array[j + 1];
                array[j + 1] = temp;
            }
        }
        sortIter++;
    }
}

void InsertionSort(int *array, const int sizeArray)
{
    int temp;
    int sortedPartSize = 0;

    for(int i = 0; i < sizeArray - 1; i++){
        for(int j = 0; j < sortedPartSize + 1; j++){
            if(array[j] > array[sortedPartSize + 1]){
                temp = array[j];
                array[j] = array[sortedPartSize + 1];
                array[sortedPartSize + 1] = temp;
            }
        }
        sortedPartSize++;
    }
}
