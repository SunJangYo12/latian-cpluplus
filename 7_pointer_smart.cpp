// pdf title: The C++ Standard Library: A Tutorial and Reference
// page 86

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <dirent.h> // for opendir(), ...
#include <cstring> // for strerror()
#include <cerrno>

using namespace std;

// class weak_ptr
class Person {
   public:
      string name;
      shared_ptr<Person> mother;
      shared_ptr<Person> father;
      //vector<shared_ptr<Person>> kids; //jika menggunakan ini deconstructor tidak pernah dipanggil
      vector<weak_ptr<Person>> kids; // weak pointer 

      Person(const string& n,
             shared_ptr<Person> m = nullptr,
             shared_ptr<Person> f = nullptr)
      : name(n), mother(m), father(f) { }

      ~Person() {
         cout << "delete " << name << endl;
      }
};

shared_ptr<Person> initFamily(const string& name)
{
     shared_ptr<Person> mom(new Person(name+"'s mom"));
     shared_ptr<Person> dad(new Person(name+"'s dad"));
     shared_ptr<Person> kid(new Person(name, mom, dad));
     mom->kids.push_back(kid);
     dad->kids.push_back(kid);
     return kid;
}
// class weak_ptr

// class unique_ptr
class DirCloser
{
   public:
      void operator() (DIR *dp) {
         if (closedir(dp) != 0)
             cerr << "OOPS: closedir() failed" << endl;
      }
};
// class unique_ptr

// auto_ptr bad example
template <typename T>
void bad_print(auto_ptr<T> p) {
    // apakah p memiliki object ?
    if (p.get() == NULL) {
       cout << "NULL";
    }
    else {
       cout << "auto_ptr: " << *p << endl;
    }
    // oops, keluar menghapus objek yang mengacu pada P
}
// auto_ptr bad example


int main()
{

    shared_ptr<string> pNico(new string("nico"));
    shared_ptr<string> pJutta(new string("jutta"));

    // memodalkan person names
    (*pNico)[0] = 'N';
    pJutta->replace(0, 1, "J");

    // menempatkan mereka beberapa kali dalam wadah
    vector<shared_ptr<string>> whoMadeCoffe;
    whoMadeCoffe.push_back(pJutta);
    whoMadeCoffe.push_back(pJutta);
    whoMadeCoffe.push_back(pNico);
    whoMadeCoffe.push_back(pJutta);
    whoMadeCoffe.push_back(pNico);

    // print all elements
    for (auto ptr : whoMadeCoffe)
    {
       cout << *ptr << " ";
    }
    cout << endl;

    // overwritte a name again
    *pNico = "Nicolai";

    // print all elements again
    for (auto ptr : whoMadeCoffe) {
       cout << *ptr << " ";
    }
    cout << endl;

    // print some internal data
    cout << "use_count: " << whoMadeCoffe[0].use_count() << endl << endl;

    // class weak_ptr
    shared_ptr<Person> p = initFamily("nico");
    cout << "nico's family exists" << endl;
    cout << "- nico is shared " << p.use_count() << " times" << endl;
    cout << "- name of 1st kid of nico's mom: "
         // << p->mother->kids[0]->name << endl;
         << p->mother->kids[0].lock()->name << endl; // if use weak_ptr

    p = initFamily("jim");
    cout << "jim's family exists" << endl;

    // melihat jika masih ada pointer
    try {
       shared_ptr<string> sp(new string("hi")); // create shared pointer
       weak_ptr<string> wp = sp; 		// create weak pointer out of it
       sp.reset(); 				// release object of shared pointer

       cout << wp.use_count() << endl; 		// print 0
       cout << boolalpha << wp.expired() << endl; // print true
       shared_ptr<string> p(wp); 		// throws std::bad_weak_ptr
    }
    catch(const std::exception& e) {
        cerr << "exception: " << e.what() << endl; // prints: bad_weak_ptr
    }


    // unique_ptr
    unique_ptr<string> up(new string("nico"));
    (*up)[0] = 'N';
    up->append("lai");
    cout << *up << endl;

    // open current directory
    unique_ptr<DIR, DirCloser> pDir(opendir("."));

    // process each directory entry
    struct dirent *dp;
    while ((dp = readdir(pDir.get())) != nullptr)
    {
       string filename(dp->d_name);
       cout << "process " << filename << endl;
    }


    // auto_ptr bad example
    auto_ptr<int> badp(new int);
    *badp = 42;
    bad_print(badp); // Oops, deletes the memory to which refers
    //*badp = 10;	     // RUNTIME ERROR
    // auto_ptr bad example

}
