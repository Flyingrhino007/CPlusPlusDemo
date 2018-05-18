#include <jni.h>
#include <string>
#include <iostream>
#include <malloc.h>
#include <string.h>


//继承
//代码的重用性
using namespace std;

//人类
/*class Human {
public:
    void say() {
        cout << "说话" << endl;
    };
protected:
    char *name;
    int age;
};

//男人
class Man : public Human {
public:
    //泡妞
    void chasing() {
        cout << "泡妞" << endl;
//        this->name = "sss"; // protected 子类可用

    };

private:
    // 兄弟
    char *brother;
};


void work(Human &human) {
    human.say();
};


void main() {
    Man m1;
    m1.say();

    //1.父类类型的引用或指针
    Human *human0 = &m1;
    human0->say();

    Human &human1 = m1;
    human1.say();

    //子类对象初始化父类类型的对象  ,新开辟的空间
    Human h2 = m1;
    h2.say();
};*/



//子类 向父类构造方法传参
//人类
/*
class Human{
public:
    Human(char* name, int age){
        this->name = name;
        this->age = age;
    }
    void say(){
        cout << "说话" << endl;
    }
protected:
    char* name;
    int age;
};

//男人
class Man : public Human{
public:
    //给父类构造函数传参，同时给属性对象赋值 ,需要给父类，子类全部参数都赋值，都构造才行
    Man(char *brother, char *s_name, int s_age, char *h_name, int h_age) : Human(s_name, s_age), h(h_name,h_age){
        this->brother = brother;
    }

    Man(char *name, int age, char *brother, const Human &h) : Human(name, age), brother(brother), h(h) {}

    //泡妞
    void chasing(){
        cout << "泡妞" << endl;
    }
private:
    //兄弟
    char* brother;
    Human h;
};

int main(){
    Man man("danny","jack",18,"jason",18);
    return 0;
}*/

//构造函数与析构函数调用的顺序

/*class Human {
public:
    Human(char *name, int age) {
        this->name = name;
        this->age = age;
        cout << "Human 构造函数" << endl;
    }

    ~Human() {
        cout << "Human 析构函数" << endl;
    }

    void say() {
        cout << "说话" << endl;
    }

protected:
    char *name;
    int age;
};

class Man : public Human {
public:
    Man(char *brother, char *name, int age) : Human(name, age), brother(brother) {}

    Man(char *name, int age, char *brother) : Human(name, age) {
        this->brother = brother;
    }

    ~Man() {
        cout << "Man 析构函数" << endl;
    };

    //泡妞
    void chasing() {
        cout << "泡妞" << endl;
    }

private:
    //兄弟
    char *brother;
};

void main() {
    // 构造函数 ， 父类-》子类
    // 析构函数 ， 子类 —》父类
    Man m1("danny", "jack", 18);
};*/

//子类对象调用父类的成员

/*class Human {
public:
    Human(char *name, int age) {
        this->name = name;
        this->age = age;
        cout << "Human 构造函数" << endl;
    }

    ~Human() {
        cout << "Human 析构函数" << endl;
    }

    // 成员函数
    void say() {
        cout << "Human 说话" << endl;
    }

public:
    char *name;
    int age;
};

class Man : public Human {
public:
    Man(char *brother, char *name, int age) : Human(name, age), brother(brother) {
        cout << "Man 构造函数" << endl;
    }

    ~Man() {
        cout << "Man 析构函数" << endl;
    }

    void say() {
        cout << "Man  说话" << endl;
    };

private:
    //兄弟
    char *brother;
};

void Main() {
    Man m1("alan", "john", 18);
    m1.say(); //    调用的子类的say()

    //调用父类，可以这样使用
    m1.Human::say();
    m1.Human::age = 10;
};*/

//多继承

//人
class Person {
};

//公民
class Citizen {
};

//学生，既是人，又是公民
class Student : public Person, public Citizen {
};

//继承的访问修饰
//基类中      继承方式             子类中
//public     ＆ public继承 = > public
//public     ＆ protected继承 = > protected
//public     ＆ private继承 = > private
//
//protected  ＆ public继承 = > protected
//protected  ＆ protected继承 = > protected
//protected  ＆ private继承 = > private
//
//private    ＆ public继承 = > 子类无权访问
//private    ＆ protected继承 = > 子类无权访问
//private    ＆ private继承 = > 子类无权访问

/*class Human{
public:
    void say(){
        cout << "说话" << endl;
    }
private:
    char* name;
    int age;
};

//男人
class Man : protected Human{
public:
    //泡妞
    void chasing(){
        cout << "泡妞" << endl;
    }
private:
    //兄弟
    char* brother;
};

void main(){
    Man man;
    man.chasing();

    man.Human::chasing();
};*/

// 继承的二义性
// 虚继承：( virtual )  不同路径继承来的同名成员只有一份拷贝，解决不明确的问题

class A {
public:
    char *name;
};

class A1 : virtual public A {
};

class A2 : virtual public A {
};

class B : public A1, public A2 {
};

void main() {
    // 我想保持name 只有一个 copy ,就需要  虚继承
    B b;
    b.name = "json";

    // 指定父类显示调用  ,这样就有2份
    b.A1::name = "json";
    b.A2::name = "json";

}


//虚函数
//多态（程序的扩展性）




extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_jnidemo_cplusplusdemo_MainActivity_intFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";


    main();
    return env->NewStringUTF(hello.c_str());
}

