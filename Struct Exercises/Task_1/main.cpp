﻿#include <iostream>
#include <cmath>
using namespace std;

const int MAX_N = 1000;
const int MIN_N = 1;
const int MIN_COORD = -100;
const int MAX_COORD = 100;

struct Point {
    int x, y;
};

struct Triangle {
    Point a, b, c;

    double area() const {
        return abs((a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)) / 2.0);
    }
};

void swap(Triangle& a, Triangle& b) {
    Triangle temp = a;
    a = b;
    b = temp;
}

int getCoord() {
    int x;
    do {
        cin >> x;
        if (x < MIN_COORD || x > MAX_COORD) {
            cout << "Bad coordinate! Min: " << MIN_COORD << " Max: " << MAX_COORD << endl;
        }
    } while (x < MIN_COORD || x > MAX_COORD);
    return x;
}

int getN() {
    int N;
    do {
        cin >> N;
        if (N < MIN_N || N > MAX_N) {
            cout << "Number too big. Min: " << MIN_N << " Max: " << MAX_N << endl;
        }
    } while (N < MIN_N || N > MAX_N);
    return N;
}

int main() {
    int N = getN();

    Triangle triag[MAX_N];
    //от това че има максимално N предполагам че не се изисква диначина памет! 

    for (int i = 0; i < N; i++) {
        triag[i].a.x = getCoord();
        triag[i].a.y = getCoord();
        triag[i].b.x = getCoord();
        triag[i].b.y = getCoord();
        triag[i].c.x = getCoord();
        triag[i].c.y = getCoord();
    }

    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (triag[j].area() > triag[j + 1].area()) {
                swap(triag[j], triag[j + 1]);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (i > 0) cout << " ";
        cout << triag[i].area();
    }
    cout << endl;

    return 0;
}
