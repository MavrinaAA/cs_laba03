#pragma once
#include <vector>
#include <iostream>

using namespace std;

struct Input {
    vector<double> numbers;
    size_t bin_count;
};
struct Verb
{
    bool verbose;
    bool help;
    char* urladress;
};

void
find_minmax(const vector<double>& numbers, double& min, double& max);

vector<size_t>
make_histogram (const vector<double>& numbers,size_t bin_count);

void
show_histogram_text (const vector<size_t>& bins);

vector<size_t>
make_histogram (const Input& data);

void
show_histogram_text (const vector<size_t>& bins);

