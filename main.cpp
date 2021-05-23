#include <iostream>
#include <vector>
#include "histogram.h"
#include "svg.h"
#include <windows.h>
using namespace std;

vector<double>
input_numbers(size_t count)
{
    vector<double> result(count);
    for (size_t i = 0; i < count; i++)
    {
        cin >> result[i];
    }
    return result;
}

int
main() {
    // ���� ������
   /*size_t number_count;
    cerr << "Enter number count: ";
    cin >> number_count;

    cerr << "Enter numbers: ";
    const auto numbers=input_numbers(number_count);

    size_t bin_count;
    cerr << "Enter column count: ";
    cin >> bin_count;
    // ��������� ������
    double min,max;
    find_minmax(numbers,min,max);
    const auto bins=make_histogram(numbers,bin_count);

    // ����� ������
    /*size_t bin_height;
    show_histogram_svg(bins,bin_height);
    */

DWORD WINAPI GetVersion(void);
printf("Windows (decimal) version is %u.\n", GetVersion());
printf("WINDOWS (16x) version is %x. \n",GetVersion());

    return 0;
}
