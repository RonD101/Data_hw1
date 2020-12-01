#include "AVL.h"
#include "CoursesManager.h"

using std::cout;
using std::endl;

int main() {
    CoursesManager boom;
    boom.AddCourse(1, 5);
   // boom.AddCourse(2, 10);
   // boom.AddCourse(3, 15);
    boom.course_tree.in_order(boom.course_tree.get_root());
    boom.WatchClass(1, 2, 10);
    boom.course_tree.in_order(boom.course_tree.get_root());
    return 0;
}