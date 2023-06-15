#include <iostream>
#include <vector>

namespace Students {
    using ull = long long;

    struct Student {
        ull isu, points;
        Student(ull isu, ull points) : isu(isu), points(points) {}
    };
}

namespace Groups {
    using ull = long long;
    using Students::Student;

    struct Group {
        std::vector<Student> students;
        ull totalPoints;

        Group() : totalPoints(0) {}

        void addStudent(const Student& student) {
            students.push_back(student);
            totalPoints += student.points;
        }

        void removeStudent(ull isu) {
            for (auto it = students.begin(); it != students.end(); ++it) {
                if (it->isu == isu) {
                    totalPoints -= it->points;
                    students.erase(it);
                    break;
                }
            }
        }

        ull AveragePoints() {
            return totalPoints / students.size();
        }

        ull HighestPoints() {
            ull highestPoints = 0;
            for (auto& student : students) {
                highestPoints = std::max(highestPoints, student.points);
            }
            return highestPoints;
        }
    };
}

namespace HashTables {
    using ull = long long;
    using Groups::Group;

    class HashTable {
    private:
        ull TABLE_SIZE = 10009;
        std::vector<Group> table;

        ull hash(ull group) {
            return group % TABLE_SIZE;
        }

    public:
        HashTable() : table(TABLE_SIZE) {}

        void add(ull group, ull isu, ull points) {
            ull index = hash(group);
            table[index].addStudent(Students::Student(isu, points));
        }

        void remove(ull group, ull isu) {
            ull index = hash(group);
            table[index].removeStudent(isu);
        }

        ull AveragePoints(ull group) {
            ull index = hash(group);
            return table[index].AveragePoints();
        }

        ull MaxPoints(ull group) {
            ull index = hash(group);
            return table[index].HighestPoints();
        }
    };
}

void processQueries(int Q) {
    using ull = long long;
    using HashTables::HashTable;

    HashTable hashTable;
    while (Q > 0) {
        char query;
        ull group, isu, points;
        std::cin >> query >> group;

        switch (query) {
            case '+':
                std::cin >> isu >> points;
                hashTable.add(group, isu, points);
                break;
            case '-':
                std::cin >> isu;
                hashTable.remove(group, isu);
                break;
            case 'a':
                std::cout << hashTable.AveragePoints(group) << "\n";
                break;
            case 'm':
                std::cout << hashTable.MaxPoints(group) << "\n";
                break;
        }
        Q--;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int M, Q;
    std::cin >> M >> Q;
    processQueries(Q);
    return 0;
}
