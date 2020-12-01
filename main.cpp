#include "AVL.h"
#include "CoursesManager.h"
#include "TemArray.h"

using std::cout;
using std::endl;

int main() {
    CoursesManager boom;
    //boom.AddCourse(1, 5);
    TemArray<int> t(5);
    t[1] = 5;
    cout << t[3] << endl;
    t[3] = 10;
    cout << t[3] << endl;

    return 0;
}