#include <iostream>

using namespace std;

// 水果类型
enum TypeFruit {
    APPLE,
    PEAR,
    OTHER
};

// 水果基类
class Fruit {
public:
    Fruit() {}
    virtual ~Fruit() {}
    
    virtual void Name() = 0;
};

class Apple : public Fruit {
public:
    void Name() {
        cout << "factory create apple" << endl;
    }
};

class Pear : public Fruit {
public:
    void Name() {
        cout << "factory create pear" << endl;
    }
};


// 水果工厂
class Factory {
public:
    Fruit *CreateFruit(TypeFruit t) {
        switch (t)
        {
        case APPLE:
            return new Apple();

        case PEAR:
            return new Pear();
        
        default:
            cout << "factory create empty" << endl;
            break;
        }
        return (Fruit*)nullptr;
    }
};


int main()  {
    cout << "-------01.简单工厂-----------" <<endl;
    Fruit *f = Factory().CreateFruit(APPLE);
    f->Name();
    if(f) delete f;

    auto f2 = Factory().CreateFruit(PEAR);
    f2->Name();
    if(f2) delete f2;

    auto i = "auto test";
    cout << i << endl;
}