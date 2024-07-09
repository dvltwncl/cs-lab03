#include <iostream>
#include <vector>

using namespace std;
const size_t SCREEN_WIDTH = 80;
const size_t MAX_ASTERISK = SCREEN_WIDTH - 4 - 1;
//���� ������� �����
vector<double> input_numbers(size_t number_count){
    cerr << "Enter numbers: ";
    vector<double> numbers(number_count);
    for (size_t i = 0; i < number_count; i++) {
        cin >> numbers[i];
    }
    return numbers;
}
//����� �������� � ���������
void
find_minmax(const vector<double>& numbers, double& min, double& max) {

    min = numbers[0];
    max = numbers[0];
    for (double number : numbers) {
        if (number < min) {
            min = number;
        }
        if (number > max) {
            max = number;
        }
    }

}
vector<size_t> make_histogram(const vector<double> &numbers, size_t bin_count){

    // ��������� ������
    double min = numbers[0];
    double max = numbers[0];
    find_minmax(numbers, min, max);

    vector<size_t> bins(bin_count);
    for (double number : numbers) {
        size_t bin = (size_t)((number - min) / (max - min) * bin_count);
        if (bin == bin_count) {
            bin--;
        }
        bins[bin]++;
    }
    return bins;
}
void svg_begin(double width, double height) {
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg ";
    cout << "width='" << width << "' ";
    cout << "height='" << height << "' ";
    cout << "viewBox='0 0 " << width << " " << height << "' ";
    cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}

void svg_end() {
    cout << "</svg>\n";
}

void svg_text(double left, double baseline, string text) {
    cout << "<text x='" << left << "' y='" << baseline << "'>" << text << "</text>\n";
}

void svg_rect(double x, double y, double width, double height,string stroke, string fill){
    cout << "<rect x='" << x << "' y='" << y << "' width='" << width << "' height='" << height
         << "' stroke='" << stroke << "' fill='" << fill << "' />\n";
}

void show_histogram_svg(const vector<size_t>& bins) {
const auto IMAGE_WIDTH = 400;
const auto IMAGE_HEIGHT = 300;
const auto TEXT_LEFT = 20;
const auto TEXT_BASELINE = 20;
const auto TEXT_WIDTH = 50;
const auto BIN_HEIGHT = 30;
const auto BLOCK_WIDTH = 10;
    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);
    double top = 0;
for (size_t i = 0; i < bins.size(); i++) {
    const double bin_width = BLOCK_WIDTH * bins[i];
    svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bins[i]));
    svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT,"black", "#aaffaa");
    top += BIN_HEIGHT;
}
    //svg_text(TEXT_LEFT, TEXT_BASELINE, to_string(bins[0]));
    //svg_rect(TEXT_WIDTH, 0, bins[0] * BLOCK_WIDTH, BIN_HEIGHT);
    svg_end();
}


int
main() {
    // ���� ������
    size_t number_count;
    cerr << "Enter number count: ";
    cin >> number_count;

const auto numbers = input_numbers(number_count);
    size_t bin_count;
    cerr << "Enter column count: ";
    cin >> bin_count;
    // ����� ������

    const auto bins= make_histogram(numbers, bin_count);

    show_histogram_svg(bins);


    return 0;
}

