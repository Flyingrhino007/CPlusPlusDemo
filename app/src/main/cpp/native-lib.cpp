#include <jni.h>
#include <string>
#include <iostream>
#include <malloc.h>

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_jnidemo_cplusplusdemo_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}


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

//void main() {
////    std::cout << "this is c plus plus " << std::endl;// c++ 运算符重载  使其有意义
//    cout << "this is c plus plus " << endl;// 等效上面
//    // 使用命名空间
//    // :: 访问修饰符
//    cout << NSP_A::a << endl;
//    cout << NSP_B::a << endl;
//    //
//    cout << NSP_B::NSP_C::c << endl;
//
//    // 使用结构体 Teacher
////    struct NSP_B::NSP_C::Teacher teacher;
////    teacher.age = 10;
//
//    // 太长了，所以为了缩短 使用 using
////    using namespace NSP_A;
////    Teacher teacher1;
////    teacher1.age = 10;
//
//    // 为了防止重复，直接指定使用的using   struct没写都ok，故可以去掉
//    using NSP_B::NSP_C::Teacher;
//    Teacher teacher;
//    teacher.age = 10;
//};


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

void main1() {
    // new 出来的是一个指针
    Circle *c = new Circle();
    c->setR(4);
    c->getS();
    // 定义
    Circle circle;
    circle.setR(4);
    cout << "圆的面积：" << circle.getS() << endl;
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

    cout << isSingle << endl;
    cout << sizeof(isSingle) << endl;  // 字节数=1         == char
};

void mian4() {
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

//C++类的普遍写法
#include "MyTeacher.h"

void main17(){
    MyTeacher1 myTeacher;
    myTeacher.name = "";
    myTeacher.age = 0;
    cout << myTeacher.getName() << endl;
};

//构造函数、析构函数、拷贝构造函数


