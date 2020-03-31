#include <assert.h>
#include <stdio.h>

double my_abs(double d);
double my_sqrt(double a, double epsilon);
int is_real_number_equal(double a, double b);

int main(void) {

    assert(is_real_number_equal(my_sqrt(4, 0.01), 2.00000009));
    assert(is_real_number_equal(my_sqrt(81, 0.1), 9.01427238));
    assert(is_real_number_equal(my_sqrt(100, 0.0000001), 10.00000000));
    assert(is_real_number_equal(my_sqrt(124, 0.0000001), 11.13552873));
    assert(is_real_number_equal(my_sqrt(12, 0.001), 3.46410165));

    return 0;
}

double my_abs(double d) { return d >= 0 ? d : -d; }

double my_sqrt(double a, double epsilon) {
    double x0 = (1 + a) / 2.0;
    double xn = x0;

    while (1) {
        x0 = xn;
        xn = (xn + a / xn) / 2.0;
        if (my_abs((xn - x0) / x0) < epsilon)
            break;
    }
    return xn;
}

#define EPSILON 0.00001
int is_real_number_equal(double a, double b) { return (a - b) < EPSILON; }
