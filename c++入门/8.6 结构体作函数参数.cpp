#include <iostream>
#include <string>
using namespace std;

struct student {
  string name;
  int age;
  int score;
};

void PrintStudent1(student s) {
  s.age = 100;
  cout << "子函数中 姓名:" << s.name << " 年龄: " << s.age
       << " 考试分数: " << s.score << endl;
}

void PrintStudent2(student *p) {
  p->age = 100;
  cout << "子函数2中 姓名:" << p->name << " 年龄: " << p->age
       << " 考试分数: " << p->score << endl;
}

int main() {
  student s = {"张三", 20, 85};
  //   PrintStudent1(s);
  PrintStudent2(&s);

  cout << "main函数中打印 姓名: " << s.name << " 年龄: " << s.age
       << " 考试分数:" << s.score << endl;

  system("pause");
  return 0;
}