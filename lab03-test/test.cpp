#include "Histogram.h"
#include "svg.h"
#include <cassert>
void
test_positive() {
    double min = 0;
    double max = 0;
    find_minmax({1, 2, 3}, min, max);
    assert(min == 1);
    assert(max == 3);
}
void test_negative() {
    double min = 0;
    double max = 0;
    find_minmax({-1, -2, -3}, min, max);
    assert(min == -3);
    assert(max == -1);
}

void test_same() {
    double min = 0;
    double max = 0;
    find_minmax({5, 5, 5}, min, max);
    assert(min == 5);
    assert(max == 5);
}

void test_one_element() {
    double min = 0;
    double max = 0;
    find_minmax({7}, min, max);
    assert(min == 7);
    assert(max == 7);
}
void test_empty() {
    double min = 0;
    double max = 0;
    find_minmax({}, min, max);
    assert(min == 0);
    assert(max == 0);
}

//
void test_format_number_positive_integer() {
    double num = 1234.5678;
    string expected = "1234.568";
    string result = format_number(num);
    assert(result == expected);
}

void test_format_number_negative_decimal() {
    double num = -0.00123;
    string expected = "-0.001";
    string result = format_number(num);
    assert(result == expected);
}
int
main() {
    test_positive();
    test_negative();
    test_same();
    test_one_element();
    test_empty();
    test_format_number_positive_integer();
    test_format_number_negative_decimal();
}
