#include "AVL.h"
#include "CoursesManager.h"
#include "TemArray.h"

using std::cout;
using std::endl;

int main() {
    CoursesManager boom;
    boom.AddCourse(1, 5);
    boom.AddCourse(2, 7);
    int time = -5;
    boom.TimeViewed(1,3,&time);
    cout << time;
    boom.course_tree.in_order(boom.course_tree.get_root());
    return 0;
}