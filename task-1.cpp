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
    //���߳�״̬������
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
    cout << "���ѧ���� �� ��էߧ������ߧ�� �������ߧڧ�:" << endl << "time: " << t2 - t1 << endl;
    //2
        //˫�߳�״̬������
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
    cout << "���ѧ���� �� �էӧ�������ߧ�� �������ߧڧ�:" << endl << "time: " << t4 - t3 << endl;
    //4
        //���߳�״̬������
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
    cout << "���ѧ���� �� ��֧���֧������ߧ�� �������ߧڧ�:" << endl << "time: " << t6 - t5 << endl;
    //8
        //���߳�״̬������
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
    cout << "���ѧ���� �� �ӧ���ާڧ�����ߧ�� �������ߧڧ�:" << endl << "time: " << t8 - t7 << endl;
    //16
        //ʮ���߳�״̬������
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
    cout << "���ѧ���� �� ��֧��ߧѧէ�ѧ�� �����ܧѧ�:" << endl << "time: " << t6 - t5 << endl;
    //32
        //��ʮ���߳�״̬������
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
    cout << "���ѧ���� �� �������ߧڧ� ���ڧէ�ѧ�� �էӧ�� �����ܧ��:" << endl << "time: " << t12 - t11 << endl;
}
