#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

void start_computing_a(void)
{
    static long int Asgl[1000][1000];
    static long double Adbl[1000][1000];
    static int sum_int = 0;
    static double sum_double = 0;
    clock_t t1 = clock();
    //1
    //单线程状态下运行
#pragma omp parallel for num_threads(1)
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            Asgl[i][j] = rand() % 1000000;
            Adbl[i][j] = rand() % 1000000;
        }
    }
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            sum_int = Asgl[i][j] + sum_int;
            sum_double = Adbl[i][j] + sum_double;
        }
    }
    clock_t t2 = clock();
    cout << "Запуск в однопоточном состоянии:" << endl << "time: " << t2 - t1 << endl;
    //2
        //双线程状态下运行
    clock_t t3 = clock();
#pragma omp parallel for num_threads(2)
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            Asgl[i][j] = rand() % 1000000;
            Adbl[i][j] = rand() % 1000000;
        }
    }
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            sum_int = Asgl[i][j] + sum_int;
            sum_double = Adbl[i][j] + sum_double;
        }
    }
    clock_t t4 = clock();
    cout << "Запуск в двухпоточном состоянии:" << endl << "time: " << t4 - t3 << endl;
    //4
        //四线程状态下运行
    clock_t t5 = clock();
#pragma omp parallel for num_threads(4)
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            Asgl[i][j] = rand() % 1000000;
            Adbl[i][j] = rand() % 1000000;
        }
    }
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            sum_int = Asgl[i][j] + sum_int;
            sum_double = Adbl[i][j] + sum_double;
        }
    }
    clock_t t6 = clock();
    cout << "Запуск в четырехпоточном состоянии:" << endl << "time: " << t6 - t5 << endl;
    //8
        //八线程状态下运行
    clock_t t7 = clock();
#pragma omp parallel for num_threads(8)
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            Asgl[i][j] = rand() % 1000000;
            Adbl[i][j] = rand() % 1000000;
        }
    }
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            sum_int = Asgl[i][j] + sum_int;
            sum_double = Adbl[i][j] + sum_double;
        }
    }
    clock_t t8 = clock();
    cout << "Запуск в восьмипоточном состоянии:" << endl << "time: " << t8 - t7 << endl;
    //16
        //十六线程状态下运行
    clock_t t9 = clock();
#pragma omp parallel for num_threads(16)
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            Asgl[i][j] = rand() % 1000000;
            Adbl[i][j] = rand() % 1000000;
        }
    }
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            sum_int = Asgl[i][j] + sum_int;
            sum_double = Adbl[i][j] + sum_double;
        }
    }
    clock_t t10 = clock();
    cout << "Запуск в шестнадцати потоках:" << endl << "time: " << t6 - t5 << endl;
    //32
        //三十二线程状态下运行
    clock_t t11 = clock();
#pragma omp parallel for num_threads(32)
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            Asgl[i][j] = rand() % 1000000;
            Adbl[i][j] = rand() % 1000000;
        }
    }
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            sum_int = Asgl[i][j] + sum_int;
            sum_double = Adbl[i][j] + sum_double;
        }
    }
    clock_t t12 = clock();
    cout << "Запуск в состоянии тридцати двух потоков:" << endl << "time: " << t12 - t11 << endl;
}
