#include <iostream>
#include <string>
using namespace std;

struct student {
  string name;
  int age;
  int score;
};

void PrintStudent(const student *s) {
  // s->age = 150;
  cout << "姓名: " << s->name << " 年龄: " << s->age << " 考试分数 " << s->score
       << endl;
}

int main() {
  student s = {"张三", 15, 70};
  PrintStudent(&s);
  cout << "main中张三的年龄为: " << s.age << endl;

  return 0;
}
