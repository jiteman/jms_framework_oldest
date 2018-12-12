#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class foo {
    int v;
public:
    foo();
    foo(int);
    void* operator new(long unsigned) throw(const char*);
    void* operator new[](long unsigned) throw(const char*);
    void operator delete(void*);
    void operator delete[](void*);
    ~foo();
};

void* operator new(long unsigned);
void* operator new[](long unsigned);
void operator delete(void*);
void operator delete[](void*);

int
main() {
    int *pi = new int;
    delete pi;
    char *pc = new char('a');
    delete pc;

    cout << "*****" << endl;

    pi = new int[2];
    delete [] pi;
    pc = new char[2];
    delete [] pc;

    cout << "*****" << endl;

    foo *fp = new foo(2);
    delete fp;

    cout << "*****" << endl;

    fp = new foo[3];
    delete [] fp;

    return 0;
}

foo::foo() {
    v = 0;
    cout << "foo::foo(" << v << ")" << endl;
}

foo::foo(int i) {
    v = i;
    cout << "foo::foo(" << v << ")" << endl;
}

void*
foo::operator new(long unsigned size) throw(const char*) {
    cout << "foo::operator new(" << size << ")\t";

    void *p = malloc(size);
    if (!p)
        throw "foo::operator new() error";

    cout << static_cast<void*>(p) << endl;

    return p;
}
void*
foo::operator new[](long unsigned size) throw(const char*) {
    cout << "foo::operator new[](" << size << ")\t";

    void *p = malloc(size);
    if (!p)
        throw "foo::operator new[]() error";

    cout << static_cast<void*>(p) << endl;

    return p;
}

void
foo::operator delete(void *p) {
    foo *fp = static_cast<foo*>(p);

    cout << "foo::operator delete(" << p << "):\t" << fp->v << endl;

    free(p);
}

void
foo::operator delete[](void *p) {
    cout << "foo::operator delete[]()" << endl;

    cout << "foo::operator delete[](" << p << ")" << endl;

    free(p);
}

foo::~foo() {
    cout << "foo::~foo():\t" << v << endl;
}


void*
operator new(unsigned long size) {
    cout << "operator new(" << size << "):\t";

    void *p = malloc(size);
    if (!p)
        throw "operator new() error";

    cout << static_cast<void*>(p) << endl;

    return p;
}

void*
operator new[](unsigned long size) {
    cout << "operator new[](" << size << "):\t";

    void *p = malloc(size);
    if (!p)
        throw "operator new() error";

    cout << static_cast<void*>(p) << endl;

    return p;
}

void
operator delete(void *p) {
    cout << "operator delete(" << p << ")" << endl;

    free(p);
}

void
operator delete[](void *p) {
    cout << "operator delete[](" << p << ")" << endl;

    free(p);
}
}