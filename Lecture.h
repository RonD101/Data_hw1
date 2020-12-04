#ifndef HW1_LECTURE_H
#define HW1_LECTURE_H

class Lecture {
public:
    explicit Lecture(int id = 0, int timed_watched = 0, int my_course_id = 0) : id(id), timed_watched(timed_watched), my_course_id(my_course_id) {}
    int id;
    int timed_watched;
    int my_course_id;
    void add_time(const int time) { timed_watched += time; }

    bool operator==(const Lecture &other) const {
        return (id == other.id);
    }

    // Lectures are ordered according to timed_watched. If equal, the ordered by id.
    bool operator<(const Lecture &other) const {
        if(timed_watched < other.timed_watched)
            return true;
        else if(timed_watched == other.timed_watched)
            return (id < other.id);
        else
            return false;
    }

    bool operator>(const Lecture &other) const {
        if(timed_watched > other.timed_watched)
            return true;
        else if(timed_watched == other.timed_watched)
            return (id > other.id);
        else
            return false;
    }

    friend std::ostream& operator<<(std::ostream& os, const Lecture& l) {
        os << "Lecture ID : " << l.id << " | Watch time : " << l.timed_watched << std::endl;
        return os;
    }
};

#endif //HW1_LECTURE_H