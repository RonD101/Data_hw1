#ifndef HW1_LECTURE_H
#define HW1_LECTURE_H
class Lecture {
public:
    Lecture(int id, int timed_watched) : id(id), timed_watched(timed_watched) {}
    int id;
    int timed_watched;
    bool operator==(Lecture other) const {
        return (id == other.id);
    }
    bool operator<(Lecture other) const {
        return (id < other.id);
    }
    bool operator>(Lecture other) const {
        return (id > other.id);
    }
    friend std::ostream& operator<<(std::ostream& os, const Lecture& l){
        os << l.id << " : " << l.timed_watched << std::endl;
        return os;
    }
};
#endif //HW1_LECTURE_H
