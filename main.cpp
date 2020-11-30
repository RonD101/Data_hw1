#include "AVL.h"
#include <random>
#include "CoursesManager.h"

using std::cout;
using std::endl;

int main() {
    CoursesManager boom;
    boom.Init();
    boom.AddCourse(nullptr, 1,10);
    return 0;
}