#include <jni.h>
#include <string>
#include <iostream>
#include <malloc.h>
#include <string.h>


// 标准命名空间（包含很多标准的定义）
// std == standard
using namespace std;
// 命名空间等效于java包(归类)

namespace NSP_A {
    int a = 9;
    struct Teacher {
        char name[20];
        int age;
    };
}

namespace NSP_B {
    int a = 12;
    //命名空间嵌套
    namespace NSP_C {
        int c = 90;
        struct Teacher {
            char name[20];
            int age;
        };
    }
}

int main() {
    std::cout << "this is c plus plus " << std::endl;// c++ 运算符重载  使其有意义
    cout << "this is c plus plus " << endl;// 等效上面
    // 使用命名空间
    // :: 访问修饰符
    cout << NSP_A::a << endl;
    cout << NSP_B::a << endl;
    //
    cout << NSP_B::NSP_C::c << endl;

    // 使用结构体 Teacher
    struct NSP_B::NSP_C::Teacher teacher;
    teacher.age = 10;

    // 太长了，所以为了缩短 使用 using
    using namespace NSP_A;
    Teacher teacher1;
    teacher1.age = 10;

    // 为了防止重复，直接指定使用的using   struct没写都ok，故可以去掉
    using NSP_B::NSP_C::Teacher;
    Teacher teacher2;
    teacher2.age = 10;
    return 0;
};


const double PI = 3.14;
//#define PI 3.14

// c++ 类 于java一致
class Circle {
// 属性    ---   区别与java :共用同一个修饰符
private:
    double r;
    double s;

public:
    void setR(double r) {
        this->r = r;
    };

    double getS() {
        return PI * r * r;
    };
};

int main1() {
    // new 出来的是一个指针
    Circle *c = new Circle();
    c->setR(4);
    c->getS();
    // 定义
    Circle circle;
    circle.setR(4);
    cout << "圆的面积：" << circle.getS() << endl;
    return 0;
};


struct MyTeacher {
public:
    char name[20];
    int age;
public:
    void say() {
        cout << "说话" << endl;
    };
};

void main2() {
    // new 出来的是一个指针
    MyTeacher myTeacher; // 结构体 可以省略struct
    myTeacher.age = 10;

    myTeacher.say();
};

void main3() {
    // 1 true( > 0 ) 0 false( < 0 )
    bool isSingle = -17;
    bool isSingle1 = 0;
    bool isSingle2 = 17;
    bool isSingle3 = 1;

    cout << isSingle << endl;
    cout << sizeof(isSingle) << endl;  // 字节数=1         == char
};

void main4() {
    int a = 10;
    int b = 20;
    // 三元运算符 可以作值
    ((a > b) ? a : b) = 30;

    cout << b << endl;
};

// 引用
void main5() {
    int a = 10;//门牌号(内存空间0x00001的别名，可不可以有多个名字？)
    //C语言正常语法 &表示：取地址
    //C++ &表示：引用
    int &b = a; //b实际上就是另外一个别名

    //引用必须要初始化
    //int &c;

    cout << b << endl;
};

//指针交换值
void swip1(int *a, int *b) {
    int c = 0;
    c = *a;
    *a = *b;
    *b = c;
};

//引用交换
void swip2(int &a, int &b) {
    int c = 0;
    c = a;
    a = b;
    b = c;
};

void main6() {
    int x = 10;
    int y = 30;
    printf("%d,%d\n", x, y);
//    swip1(&x,&y);

    //a 成了x的别名， b 成了y的别名
    swip2(x, y);
    printf("%d,%d\n", x, y);
};


//复杂类型的引用
//struct Teacher
//{
//    char name[20];
//    int age;
//};
//
//void myprint0(Teacher &teacher){
//    cout << teacher.age<<","<<teacher.name << endl;
//};
//
//
//void myprint1(Teacher *teacher){
//    cout << teacher->age<<","<<teacher->name<< endl;
//};
//
//
//void myprint2(Teacher teacher){
//    //p只是t1的拷贝，并不会影响t1
//    // 相当于新建的一个结构体，互不影响
//    cout << teacher .age<<","<<teacher.name<< endl;
//};
//
//
//void main7(){
//
//    Teacher t1;
//    t1.age = 20;
//    myprint0(t1);
//    cout << t1.age << endl;
//
//    myprint1(&t1);
//
//    cout << t1.age << endl;
//
//    myprint2(t1);
//
//    cout << t1.age << endl;
//
//}


struct Teacher {
    char *name;
    int age;
};


void getTeacher(Teacher **p) {
    Teacher *tem = (Teacher *) malloc(sizeof(Teacher));
    tem->age = 20;
    *p = tem;
}

//指针的引用，代替二级指针
//Teacher* &p = (Teacher * *p)
void getTeacher(Teacher *&p) {
    p = (Teacher *) malloc(sizeof(Teacher));
    p->age = 20;
}


void main8() {
    Teacher *teacher;
    getTeacher(teacher);
}


//指针常量与常量指针

void main10() {
    // 指针常量，不改变地址的指针，但是可以修改其内容
    int a = 2, b = 3;
    int *const p1 = &a;
//    p1 = &b;// p1 是指地址  *p1 是内容
    *p1 = 4;

    // 常量指针，指向常量的指针，内容不能修改，
    const int *p2 = &a;
    p2 = &b;
//    *p2 = 5; // 值不能修改，引用可以被修改
}


// 1.单纯给变量区别名没有任何意义，作为函数参数传递，能保证参数传递过程中不产生副本
// 2.引用可以直接操作变量，指针要通过取值（*p）,间接操作变量，指针的可读性差


//常引用类似于java中final
void myprintf(const int &a) {
    cout << a << endl;
}

void main11() {
//    const int a; // 常量必须赋值
//    int &a=NULL; // 引用不能为NUll

    //常引用
    int a = 10, b = 9;
    const int &c = a;

    //字面量
    const int &d = 70;

    //c = b;
    myprintf(c);
}

//引用的大小
struct Teacher1 {
    char name[20];
    int age;
};

void main12() {
    Teacher1 t;

    Teacher1 &t1 = t;
    Teacher1 *p = &t;

    cout << sizeof(t1) << endl; // 24  引用是变量的别名
    cout << sizeof(p) << endl;  // 4  指针保存的是变量的地址，所有的指针保存的都是4字节
}

// 引用会自动进行null判断,是不允许为null的
struct Teacher3 {
    char name[20];
    int age;
};

void myprint(Teacher3 *t) {
    cout << t->name << "," << t->age << endl;
}

void myprint2(Teacher3 &t) {
    cout << t.name << "," << t.age << endl;
    t.age = 21;
}

void main13() {
    Teacher3 t;

    Teacher3 *p = NULL;
    //报错，防止不报错，进行非空判断
    myprint(p);

    //引用不能为空，没法传进去    引用是自动判断了，为NULL就不能传进去
//    Teacher3 &t2 = NULL;
//    myprint2(t2);
}


// ----------------------------  函数部分  start   --------------------------

//函数默认参数  ,第二个设置默认参数之后，后面的必须设置默认参数
void myPrint(int x, int y = 9, int z = 10) {
    cout << x << endl;
    cout << y << endl;
    cout << z << endl;
};

//重载
void myPrint(int x, bool ret) {
    cout << x << endl;
    cout << ret << endl;
};


void main14() {
    myPrint(0, 1, 2);
    myPrint(1, true);
};


//可变参数
//int...
void func(int i, ...) {   // 只能取固定参数
    //可变参数指针
    va_list args_p;
    va_start(args_p, i);
    //开始读取可变参数，i是最后一个固定参数
    int a = va_arg(args_p, char);
    char b = va_arg(args_p, char);
    int c = va_arg(args_p, int);
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;

    //结束
    va_end(args_p);
}


void main15() {
    func(0, 8, 8, 8, 8, 8, 0, 8, 88, 1);
};

// 循环读取
void func1(int i, ...) { // 读出所有的参数
    //可变参数指针
    va_list args_p;
    va_start(args_p, i);
    //开始读取可变参数，i是最后一个固定参数

    int value;
    while (1) {
        value = va_arg(args_p, int);
        if (value <= 0) { // 代表取不到数据了
            break;
        }
        cout << value << endl;
    }

    //结束
    va_end(args_p);
}

void main16() {
    func1(0, 8, 8, 8, 8, 8, 0, 8, 88, 1);
};
//
////C++类的普遍写法
//#include "MyTeacher.h"
//
//void main17() {
//    MyTeacher1 myTeacher;
//    myTeacher.name = "sdsads";
//    myTeacher.age = 0;
//    cout << myTeacher.getName() << endl;
//};

//构造函数、析构函数、拷贝构造函数
class Teacher4 {
private:
    char *name;
    int age;
public:
    //无参构造函数（写了，就会覆盖默认的无参构造函数）
    Teacher4() {
        cout << "无参构造函数" << endl;
    };

    //有参构造函数会覆盖默认的构造函数
    Teacher4(char *name, int age) {
        this->name = name;
        this->age = age;
        cout << "有参构造函数" << endl;
    };
};

void main18() {
    Teacher4 teacher; // 创建就会调用 无惨构造函数
    Teacher4 teacher1("jick", 25);

    //另外一种调用方式    类似于new一个对象的方式，针对类，针对引用
    Teacher4 teacher2 = Teacher4("jick", 25);
};


// 析构函数
class Teacher5 {
private:
    char *name;
    int age;
public:
    //无参构造函数赋默认值
    Teacher5() {
        this->name = (char *) malloc(100);
        strcpy(name, "jick");
        this->age = 20;
        cout << "无参构造函数" << endl;
    };

    Teacher5(char *name, int age) {
        int len = strlen(name);
        this->name = (char *) malloc(len + 1);
        strcpy(this->name, name);
        this->age = age;
        cout << "有参构造函数" << endl;
    }

    //析构函数
    //当对象要被系统释放时，析构函数被调用
    //作用：善后处理
    ~Teacher5() {
        cout << "析构" << endl;
        free(this->name);
    }

    void myprint() {
        cout << name << "," << age << endl;
    }
};

void main19() {
    Teacher5 teacher5; // 调用无惨赋值，释放的时候调用析构函数
}

//拷贝构造函数
class Teacher6 {
private:
    char *name;
    int age;
public:
    Teacher6(char *name, int age) {
        int len = strlen(name);
        this->name = (char *) malloc(len + 1);
        strcpy(this->name, name);
        this->age = age;
        cout << "有参构造函数" << endl;
    }

    ~Teacher6() {
        cout << "析构" << endl;
        //释放内存
        free(this->name);
    }

    // 引用就是其别名
    Teacher6(const Teacher6 &obj) {
        //复制name属性
        int len = strlen(obj.name);
        this->name = (char *) malloc(len + 1);
        strcpy(this->name, obj.name);
        this->age = obj.age;
        cout << "拷贝构造函数" << endl;
    };

    void myprint() {
        cout << name << "," << age << endl;
    }
};


Teacher6 func1(Teacher6 t) {
    t.myprint();
    return t;
}


void main20() {
    Teacher6 teacher6("jick", 20);

    //拷贝构造函数被调用的场景
    //1.声明时赋值
//    Teacher6 teacher61(teacher6);
//    Teacher6 teacher62=Teacher6((teacher6));
    Teacher6 teacher63 = teacher6;
    teacher63.myprint();


    //2.作为参数传入，实参给形参赋值 ,(因为里面是创建了一个局部的类，所以相当于copy)
    func1(teacher6);
    //3.作为函数返回值返回，给变量初始化赋值
    Teacher6 t3 = func1(teacher6);


    //这里不会被调用
    //Teacher6 t1 ;
    //Teacher6 t2;
    //t1 = t2;
}

//浅拷贝（值拷贝）问题
void main21() {
    Teacher5 t1("rose", 20);

    Teacher5 t2 = t1; // 因为没有实现内部值的copy，所以算是浅copy
    t2.myprint();
}

//深拷贝
void main22() {
    Teacher6 t1("rose", 20);

    Teacher6 t2 = t1; //内部的值进行了赋值，所以算是深copy
    t2.myprint();
}

// 浅copy : 仅仅只是copy指针的地址
// 深copy : copy 的是指针指向的数据内容

//构造函数的属性初始化列表

class Teacher7 {
private:
    char *name;
public:
    // 浅赋值
    Teacher7(char *name) {
        this->name = name;
        cout << "Teacher有参构造函数" << endl;
    }

    ~Teacher7() {
        cout << "Teacher析构函数" << endl;
    }

    char *getName() {
        return this->name;
    }
};


class Student {
private:
    int id;
    // 属性对象
//    Teacher7 t=Teacher7("jick");// 调用有参  ,但是不好，因为值固定了，按道理来说不需要固定值
    Teacher7 t1;// 调用无惨
    Teacher7 t2;

public:

    // 有参构造 需要把里面的属性对象全部初始化
    Student(int id, char *t1_n, char *t2_n) : t1(t1_n), t2(t2_n) {
        this->id = id;
        cout << "Student有参构造函数" << endl;
    };


    void myPrintf() {
        cout << id << "," << t1.getName() << "," << t2.getName() << endl;
    };

    ~Student() {
        cout << "Student析构函数" << endl;
    };
};

void main23() {
    Student s1(10, "miss bo", "mrs liu");
    //Student s2(20, "miss cang", "jason");
    s1.myPrintf();
    //s2.myPrintf();

    // 顺序 teacher先创建 -> student 先析构
}


//C++ 通过new(delete)动态内存分配   ,  new 出来的是存堆内存的，所以需要释放堆内存空间
//C	  malloc(free)


class Teacher8 {
private:
    char *name;
public:
    Teacher8(char *name)
//            : name(name)
    {
        this->name = name;
//        Teacher8::name = name;
        cout << "Teacher有参构造函数" << endl;
    }

    char *getName() const {
        return name;
    }

    void setName(char *name) {
        Teacher8::name = name;
    }

    ~Teacher8() {
        cout << "Teacher8析构函数" << endl;
    }
};


//C++ 通过new(delete)动态内存分配
//C	  malloc(free)
void main24() {
    // c++
    // 与c的写法的区别：    new调用构造  delete调用析构函数
    Teacher8 *t1 = new Teacher8("jack");
    cout << t1->getName() << endl;
    //释放
    delete t1;

    //C
//    Teacher8 *t2 = (Teacher8*)malloc(sizeof(Teacher8));
//    t2->setName("jack");
//    free(t2);

    // 数组类型
    // C
    int *p = (int *) malloc(sizeof(int) * 10);
    p[0] = 9;
    free(p);

    // C++
    int *p2 = new int[10];
    p2[0] = 2;
    // 释放数组
    delete[] p2;
}


//static 静态属性和方法

class Teacher9 {
public:
    char *name;
    //计数器
    static int total;
public:
    Teacher9(char *name) {
        this->name = name;
        cout << "Teacher有参构造函数" << endl;
    }

    ~Teacher9() {
        cout << "Teacher析构函数" << endl;
    }

    void setName(char *name) {
        this->name = name;
    }

    char *getName() {
        return this->name;
    }

    //计数，静态函数
    static void count() {
        total++;
        cout << total << endl;
    }
};

//静态属性初始化赋值   - 只能全局初始化，可以局部代码修改
int Teacher9::total = 9;

void main25() {
    Teacher9::total++;
    cout << Teacher9::total << endl;
    //直接通过类名访问
    Teacher9::count();
//    BB::AA::Teacher9::count();  // 命名空间+内部命名空间+类名+函数名

    //也可以通过对象名访问
    Teacher9 teacher9("sds");
    teacher9.total++;
    teacher9.count();
}


//类的大小
class A {
public:
    int i;
    int j;
    int k;
    static int m;
};

class B {
public:
    int i;
    int j;
    int k;

    // 函数可以理解成  指针存的函数地址
    void myprintf() {
        cout << "打印" << endl;
    }
};

void main26() {
    cout << sizeof(A) << endl;
    cout << sizeof(B) << endl; // 按照道理是 4*4=16，实际12 就是因为分区的不同

    //C/C++ 内存分区：栈、堆、全局（静态、全局）、常量区（字符串）、程序代码区

    //普通属性与结构体相同的内存布局
    //JVM Stack（基本数据类型、对象引用）
    //Native Method Stack（本地方法栈）
    //方法区
}

//this，当前对象的指针
//函数是共享的，必须要有能够标识当前对象是谁的办法
class Teacher10 {
private:
    char *name;
    int age;
public:
    Teacher10(char *name, int age) {
        this->name = name;
        this->age = age;
        cout << "Teacher有参构造函数" << endl;
    }

    ~Teacher10() {
        cout << "Teacher析构函数" << endl;
    }

    //常函数，修饰的是this, 就是this 被禁止不能修改属性和其他
    //既不能改变指针的值，又不能改变指针指向的内容
    //const Teacher* const this
    void myprint() const {
        printf("%#x\n", this);
        //改变属性的值
//		this->name = "yuehang";
        //改变this指针的值
//		this = (Teacher*)0x00009;
        cout << this->name << "," << this->age << endl;
    }

    void myprint2() {
        cout << this->name << "," << this->age << endl;
    }
};

void main27() {
    Teacher10 t1("jack", 18);

    const Teacher10 t2("rose", 20);
    //    t2.myprint2();// 常量对象只能调用常量函数，不能调用非常量函数
    //常函数，当前对象不能被修改，防止数据成员被非法访问


    printf("%#x\n", &t1);
    t1.myprint();

    printf("%#x\n", &t2);
    t2.myprint();
}

//友元函数
class C {
    // 友元函数
    friend void modify_i(C *p, int a);

private:
    int i;
public:
    C(int i) {
        this->i = i;
    };

    void myprint() {
        cout << i << endl;
    };
};

//友元函数的实现，在友元函数中可以访问私有的属性
void modify_i(C *p, int a) {
    p->i = a;
};


void main28() {
    C *a = new C(201);
    a->myprint();

    // 目的：外部使用友元函数 访问内部的属性
    modify_i(a, 20);
    a->myprint();
};

//友元类
class D {
    //友元类
    friend class E;

private:
    int i;
public:
    D(int i) {
        this->i = i;
    }

    void myprint() {
        cout << i << endl;
    }
};

class E {
private:
    D d;
public:
    //E这个友元类可以访问A类的任何成员
    void accessAny() {
        d.i = 30;
    };
};


//运算符重载   operator  XX
/*class Point {
public:
    int x;
    int y;
public:
    Point(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
    };

    void myprint() {
        cout << x << "," << y << endl;
    }
};

// 重载+号
Point operator+(Point &p1, Point &p2) {
    Point tem(p1.x + p2.x, p1.y + p2.y);
    return tem;
};


// 重载-号
Point operator-(Point &p1, Point &p2) {
    Point tem(p1.x - p2.x, p1.y - p2.y);
    return tem;
};


void main29() {
    Point point(10, 20);
    Point point1(20, 10);

    Point point2 = point + point1;
    point2.myprint();

    Point point3 = point - point1;
    point2.myprint();
};*/

//成员函数，运算符重载
/*
class Point{
public:
    int x;
    int y;
public:
    Point(int x = 0, int y = 0){
        this->x = x;
        this->y = y;
    }
    // 重载+号    成员函数，运算符重载
    Point operator+(Point &p2) {
        Point tem(this->x + p2.x, this->y + p2.y);
        return tem;
    };
    void myprint(){
        cout << x << "," << y << endl;
    }
};

void main30() {
    Point p1(10, 20);
    Point p2(20, 10);

    //运算符的重载，本质还是函数调用
    Point p3 = p1.operator+(p2);
    p3.myprint();

    Point p4 = p1 + p2;
    p4.myprint();
};*/

//当属性私有时，通过友元函数完成运算符重载
class Point {
    friend Point operator+(Point &p1, Point &p2);

private:
    int x;
    int y;
public:
    Point(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
    }

    void myprint() {
        cout << x << "," << y << endl;
    }
};

Point operator+(Point &p1, Point &p2) {
    Point tmp(p1.x + p2.x, p1.y + p2.y);
    return tmp;
}

void main31() {
    Point p1(10, 20);
    Point p2(20, 10);

//运算符的重载，本质还是函数调用
    Point p4 = p1 + p2;
    p4.myprint();
};



extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_jnidemo_cplusplusdemo_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";

    main23();
    main24();
    main25();
    main26();
    return env->NewStringUTF(hello.c_str());
}