#include "../svg.h"
#include <cassert>

void the_same ()
{
    size_t height_1;
    show_histogram_svg({1,1,1},height_1);
    size_t height_2;
    show_histogram_svg({5,5,5},height_2);
    assert (height_1==height_2);
}
void bin_empty ()
{
    size_t height;
    show_histogram_svg({},height);
}

void scalling()
{
    size_t height_1;
    show_histogram_svg({1, 2, 3}, height_1);
    size_t height_2;
    show_histogram_svg({6,5,4}, height_2);
    assert(height_1>height_2);
}

int main ()
{
    the_same();
    bin_empty ();
    scalling ();
}
