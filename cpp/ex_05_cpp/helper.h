#ifndef HELPER_H
#define HELPER_H

double min(const double* nums) {
    double min = *nums;
    for (int i = 1; i < MAX_VALUE; i++) {
        if (min > *(nums + i)) {
            min = *(nums + i);
        }
    }
    return min;
}

double max(const double* nums) {
    double max = *nums;
    for (int i = 1; i < MAX_VALUE; i++) {
        if (max < *(nums + i)) {
            max = *(nums + i);
        }
    }
    return max;
}

double avg(const double* nums) {
    double sum = 0;
    for (int i = 0; i < MAX_VALUE; i++) {
        sum += *(nums + i);
    }
    return sum / MAX_VALUE;
}

void swap(double* arr, int i, int j) {
    double t = *(arr + i);
    *(arr + i) = *(arr + j);
    *(arr + j) = t;
}
#endif