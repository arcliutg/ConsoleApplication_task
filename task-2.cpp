#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

void start_computing_b(void)
{
    /*b.	添加矩阵（Bsgl、Csgl、Bdbl、Cdbl）
c.	用随机数填写 Bsgl、Bdbl
d.	为顺序和并行代码创建矩阵乘法代码 C=A*B
*/
    clock_t t1 = clock();
    static int Bsgl[1000][1000];
    static double Bdbl[1000][1000];
    static int Csgl[1000 * 1000];
    static double Cdbl[1000 * 1000];

    //1
    //单线程状态下运行
#pragma omp parallel for num_threads(32)
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            Bsgl[i][j] = rand() % 1000000;
            Bdbl[i][j] = rand() % 1000000;
        }
    }
    int index = 0;
    for (int a = 0; a < 1000; a++)//a为A矩阵的行标
    {
        for (int b = 0; b < 1000; b++)//b为B矩阵的列标
        {
            for (int c = 0; c < 1000; c++)//c为B矩阵的行标、A矩阵的列标
            {
                Csgl[index] += Bsgl[a][c] * Bdbl[c][b];
            }
            index++;
        }
    }
    index = 0;
    for (int a = 0; a < 1000; a++)//a为A矩阵的行标
    {
        for (int b = 0; b < 1000; b++)//b为B矩阵的列标
        {
            for (int c = 0; c < 1000; c++)//c为B矩阵的行标、A矩阵的列标
            {
                Cdbl[index] += Bdbl[a][c] * Bsgl[c][b];
            }
            index++;
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
            Bsgl[i][j] = rand() % 1000000;
            Bdbl[i][j] = rand() % 1000000;
        }
    }
    index = 0;
    for (int a = 0; a < 1000; a++)//a为A矩阵的行标
    {
        for (int b = 0; b < 1000; b++)//b为B矩阵的列标
        {
            for (int c = 0; c < 1000; c++)//c为B矩阵的行标、A矩阵的列标
            {
                Csgl[index] += Bsgl[a][c] * Bdbl[c][b];
            }
            index++;
        }
    }
    index = 0;
    for (int a = 0; a < 1000; a++)//a为A矩阵的行标
    {
        for (int b = 0; b < 1000; b++)//b为B矩阵的列标
        {
            for (int c = 0; c < 1000; c++)//c为B矩阵的行标、A矩阵的列标
            {
                Cdbl[index] += Bdbl[a][c] * Bsgl[c][b];
            }
            index++;
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
            Bsgl[i][j] = rand() % 1000000;
            Bdbl[i][j] = rand() % 1000000;
        }
    }
    index = 0;
    for (int a = 0; a < 1000; a++)//a为A矩阵的行标
    {
        for (int b = 0; b < 1000; b++)//b为B矩阵的列标
        {
            for (int c = 0; c < 1000; c++)//c为B矩阵的行标、A矩阵的列标
            {
                Csgl[index] += Bsgl[a][c] * Bdbl[c][b];
            }
            index++;
        }
    }
    index = 0;
    for (int a = 0; a < 1000; a++)//a为A矩阵的行标
    {
        for (int b = 0; b < 1000; b++)//b为B矩阵的列标
        {
            for (int c = 0; c < 1000; c++)//c为B矩阵的行标、A矩阵的列标
            {
                Cdbl[index] += Bdbl[a][c] * Bsgl[c][b];
            }
            index++;
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
            Bsgl[i][j] = rand() % 1000000;
            Bdbl[i][j] = rand() % 1000000;
        }
    }
    index = 0;
    for (int a = 0; a < 1000; a++)//a为A矩阵的行标
    {
        for (int b = 0; b < 1000; b++)//b为B矩阵的列标
        {
            for (int c = 0; c < 1000; c++)//c为B矩阵的行标、A矩阵的列标
            {
                Csgl[index] += Bsgl[a][c] * Bdbl[c][b];
            }
            index++;
        }
    }
    index = 0;
    for (int a = 0; a < 1000; a++)//a为A矩阵的行标
    {
        for (int b = 0; b < 1000; b++)//b为B矩阵的列标
        {
            for (int c = 0; c < 1000; c++)//c为B矩阵的行标、A矩阵的列标
            {
                Cdbl[index] += Bdbl[a][c] * Bsgl[c][b];
            }
            index++;
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
            Bsgl[i][j] = rand() % 1000000;
            Bdbl[i][j] = rand() % 1000000;
        }
    }
    index = 0;
    for (int a = 0; a < 1000; a++)//a为A矩阵的行标
    {
        for (int b = 0; b < 1000; b++)//b为B矩阵的列标
        {
            for (int c = 0; c < 1000; c++)//c为B矩阵的行标、A矩阵的列标
            {
                Csgl[index] += Bsgl[a][c] * Bdbl[c][b];
            }
            index++;
        }
    }
    index = 0;
    for (int a = 0; a < 1000; a++)//a为A矩阵的行标
    {
        for (int b = 0; b < 1000; b++)//b为B矩阵的列标
        {
            for (int c = 0; c < 1000; c++)//c为B矩阵的行标、A矩阵的列标
            {
                Cdbl[index] += Bdbl[a][c] * Bsgl[c][b];
            }
            index++;
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
            Bsgl[i][j] = rand() % 1000000;
            Bdbl[i][j] = rand() % 1000000;
        }
    }
    index = 0;
    for (int a = 0; a < 1000; a++)//a为A矩阵的行标
    {
        for (int b = 0; b < 1000; b++)//b为B矩阵的列标
        {
            for (int c = 0; c < 1000; c++)//c为B矩阵的行标、A矩阵的列标
            {
                Csgl[index] += Bsgl[a][c] * Bdbl[c][b];
            }
            index++;
        }
    }
    index = 0;
    for (int a = 0; a < 1000; a++)//a为A矩阵的行标
    {
        for (int b = 0; b < 1000; b++)//b为B矩阵的列标
        {
            for (int c = 0; c < 1000; c++)//c为B矩阵的行标、A矩阵的列标
            {
                Cdbl[index] += Bdbl[a][c] * Bsgl[c][b];
            }
            index++;
        }
    }
    clock_t t12 = clock();
    cout << "Запуск в состоянии тридцати двух потоков:" << endl << "time: " << t12 - t11 << endl;
}