#include "svg.h"

string
make_info_text() {
    stringstream buffer;

    DWORD info = GetVersion();
     DWORD mask = 0x0000ffff;
    DWORD version = info & mask;
    DWORD platform = info >> 16;
    DWORD mask_2 = 0x0000ff;

   if ((info & 0x80000000) == 0)
    {
        DWORD version_major = version & mask_2;
        DWORD version_minor = version >> 8;
        DWORD build = platform;
        buffer << "Windows v"<<version_major<<"."<<version_minor<<"(build"<<build<<")";

    }
    char computer_name[MAX_COMPUTERNAME_LENGTH + 1];
    DWORD size = MAX_COMPUTERNAME_LENGTH+1;
    GetComputerNameA(computer_name, &size);
    buffer<<"Computer name:" <<computer_name;
    // TODO: �������� ������ �������, �������� � �����.
    // TODO: �������� ��� ����������, �������� � �����.
    return buffer.str();
}
void
svg_begin(double width, double height)
{
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg ";
    cout << "width='" << width << "' ";
    cout << "height='" << height << "' ";
    cout << "viewBox='0 0 " << width << " " << height << "' ";
    cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}

void
svg_end()
{
    cout << "</svg>\n";
}

void
svg_text(double left, double baseline , string text)
{
    cout << "<text x='" << left << "' y='" << baseline << "'>"<<text<<"</text>";
}

void
svg_rect(double x, double y, double width, double height, string stroke, string fill)
{
    cout << "<rect x='" << x << "' y='" << y <<"' width='"<< width <<"' height='"<<height<<"' stroke='"<<stroke<<"' fill='"<<fill<<"' />";
}

void show_histogram_svg(const vector<size_t>& bins, size_t& bin_height)
{
    if (bins.size() == 0)
    {
        return;
    }
    const auto IMAGE_WIDTH = 500;
    const auto IMAGE_HEIGHT = 300;
    const auto TEXT_LEFT = 15;
    const auto TEXT_BASELINE = 20;
    const auto TEXT_HEIGHT = 30;
    const auto BIN_WIDTH = 30;
    const auto TEXT_TOP=10;

    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);

    double left =0;

    size_t max_count=bins[0];
    for (size_t count : bins)
    {
        if ( count >max_count)
        {
            max_count=count;
        }
    }

    for (size_t bin: bins)
    {
        const double scaling_factor = (double)(IMAGE_HEIGHT - TEXT_HEIGHT-TEXT_TOP) / max_count;
        bin_height=(size_t)(bin*scaling_factor);

        svg_text(left + TEXT_LEFT, TEXT_BASELINE+TEXT_TOP, to_string(bin));
        svg_rect(left, TEXT_HEIGHT+TEXT_TOP, BIN_WIDTH, bin_height);
        left += BIN_WIDTH;
    }
       svg_text(0, TEXT_TOP, make_info_text());

    svg_end();
}
