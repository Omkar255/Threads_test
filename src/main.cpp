// C++ program to demonstrate multi-threading using three different callables
#include<iostream>
#include<thread>
#include<my_inc.h>
using namespace std;

// A dummy funbction
void foo(int Z)
{
  for (int i = 0; i < Z; i++) {
    cout << "Thread using function pointer as callable\n";
  }
}

// A callable object
class thread_obj {
public:
  void operator() (int x)
  {
    for (int i = 0; i < x; i++)
      cout << "Thread using function object as callable\n";
  }
};

// class definition
class Base {
public:
  // non-static memeber function
  void foo()
  {
    cout << "Thread using non-static member function as callable" << endl;
  }
  // static member function
  void foo1()
  {
    cout << "Thread using static member functino as callable" << endl;
  }
};

// Driver code
int main()
{
  cout << "Threads 1 and 2 and 3 operating independently" << endl;

  // This thread is launched by using function pointer as callable
  thread th1(foo, 3);

  // This thread is launched by using function object as callable
  thread th2(thread_obj(), 3);

  // Define a lambda Expression
  auto f = [](int x) {
    for (int i = 0; i < x; i++)
      cout << "Thread using lambda expression as callable\n";
  };

  // This thread is launched by using lambda expression as callable
  thread th3(f, 3);

  // object of base class
  Base b;

  thread th4(&Base::foo, &b);

  thread th5(&Base::foo1, &b);

  // Wait for threads to finish
  // Wait for thread th1 to finish
  th1.join();

  // Wait for thread th2 to finish
  th2.join();

  // Wait for thread th3 to finish
  th3.join();

  // Wait for thread th4 to finish
  th4.join();

  // Wait for thread th5 to finish
  th5.join();

  return 0;
}
