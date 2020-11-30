#include "AVL.h"
#include <vector>
#include <chrono>
#include <algorithm>
#include <iostream>
#include <random>
#include "BoomManager.h"
using std::cout;
using std::endl;

int main() {
    BoomManager boom;
    boom.Init();
    boom.AddCourse(nullptr, 1,10);
    return 0;
}