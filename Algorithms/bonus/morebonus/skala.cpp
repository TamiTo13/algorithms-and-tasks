//https://www.hackerrank.com/contests/daa-2021-2022-winter-1/challenges/challenge-2593


#include <algorithm>
#include <iostream>



struct Student
{

    int facultyNumber;
    int score;
    std::string name;

    Student(int score = 0)
        : name(""), facultyNumber(0), score(score) {}
 
    bool operator<(const Student &other)
    {
        return (score == other.score && facultyNumber < other.facultyNumber) || score < other.score;
    }
};




class Sollution {
    public:

    Student university[100004];
    int n;
    int q;
    int x;

    void sollution() {
        scanf("%d%d", &n, &q);
 
        for (int i = 0; i < n; ++i)
        {
            std::cin >> university[i].name;
            scanf("%d%d", &university[i].facultyNumber, &university[i].score);
        }
        std::sort(university, university + n);
 
        for (int i = 0; i < q; ++i)
        {
         scanf("%d", &x);

          Student* res = std::lower_bound(university, university + n, Student(x));
          std::cout << res->name << ' ' << res->facultyNumber << '\n';
        }
    }
};
 
int main()
{
    Sollution a;
    a.sollution();
    return 0;
}