#include <iostream>
using namespace std;
#include <fstream>
#include "LL_T.h"

class Person{
protected:
  static int num;
  static int current_id;
  int ID;
  string first;
  string last;
  string ssn;
  string email;
public:
  int temp;
  Person(string f = "unknown", string l = "unknown", string ss = "000-00-0000", string e = "unknown", int t = 0);
  virtual void showInfo();
  static int getCurrentId();
  static int getNum();
};

int Person::num = 1;
int Person::current_id = 1000;

Person::Person(string f, string l, string ss, string e, int t): ID(current_id)  
{
  temp = t;
  first = f;
  last = l;
  ssn = ss;
  email = e;
  num++;
  current_id++;
}

void Person::showInfo(){
  cout << "Person::showInfo()" << endl;
  cout << "FN: " << first << " LN: " << last << " SSN: " << ssn << " email " << email << endl; 
}

int Person::getCurrentId(){
  return current_id;
}

int Person::getNum(){
  return num;
}

class Faculty : public Person{
public:
  int dID;
  int years;
  //public:
  Faculty(string f = "unknown", string l = "unknown", string ss = "000-00-0000", string e = "unknown", int d = -1, int y = -1) : Person(f, l, ss, e) {
    dID = d;
    years = y;
  }
  void showInfo(){
    cout << "Faculty::showInfo()" << endl;
    Person::showInfo();
    cout << " department ID: " << dID << " years: " << years << endl;
  }
};

class Student: public Person{
  string major;
  double gpa;
  char grade;
public:
  Student(string f = "unknown", string l = "unknown", string ss = "000-00-0000", string e = "unknown", string m = "unknown", double g = -1.00, char y = '?') : Person(f, l, ss, e) {
    major = m;
    gpa = g;
    grade = y;
  }
  void showInfo(){
    cout << "Student::showInfo()" <<endl;
    Person::showInfo();
    cout << " Major: " << major << " GPA: " << gpa << " Grade: " << grade << endl;
  }
};

void sdisp(Person *obj) {
  obj->showInfo();
}

void display(LL<Person*> llist){
  node<Person>* ptr = llist.getFront();
  while(ptr != llist.getRear()->next){
    ptr->elem->showInfo();   
    ptr = ptr->next;
  }
}
void readData(LL<Person>& llist){
  int row;
  ifstream fin("campus.dat", ios::in);
  while(fin >> row){
    string f, l, ss, e;
    if(row == 1){
      fin >> f; fin >> l; fin >> ss; fin >> e;
      Person P(f, l, ss, e, row);
      //node * ptr = new node();
      //ptr->elem = P;
      llist.addRear(P);
      //llist.getRear()->elem.showInfo();
      //llist.getRear()->showInfo();
    }
    else if(row == 2) {
      int d, y;
      fin >> f; fin >> l; fin >> ss; fin >> e;
      fin >> d; fin >> y;
      Faculty F(f, l, ss, e, d, y);
      llist.addRear(F);
      //llist.getRear()->elem.showInfo();
    }
    else if(row == 3){
      string m; double g; char y;
      fin >> f; fin >> l; fin >> ss; fin >> e;
      fin >> m; fin >> g; fin >> y;
      Student S(f, l, ss, e, m, g, y);
      llist.addRear(S);
      //S.showInfo();
    }
  }
}

int main(){

  LL<Person> lis;
  readData(lis);
  display(lis);

}
