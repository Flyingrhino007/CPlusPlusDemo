#include <jni.h>
#include <string>
#include <iostream>

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

void main() {
//    std::cout << "this is c plus plus " << std::endl;// c++ 运算符重载  使其有意义
    cout << "this is c plus plus " << endl;// 等效上面
    // 使用命名空间
    // :: 访问修饰符
    cout << NSP_A::a << endl;
    cout << NSP_B::a << endl;
    //
    cout << NSP_B::NSP_C::c << endl;

    // 使用结构体 Teacher
//    struct NSP_B::NSP_C::Teacher teacher;
//    teacher.age = 10;

    // 太长了，所以为了缩短 使用 using
//    using namespace NSP_A;
//    Teacher teacher1;
//    teacher1.age = 10;

    // 为了防止重复，直接指定使用的using   struct没写都ok，故可以去掉
    using NSP_B::NSP_C::Teacher;
    Teacher teacher;
    teacher.age = 10;
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

void mian4(){
    int a = 10;
    int b = 20;
    // 三元运算符 可以作值
    ((a > b) ? a : b) = 30;

    cout << b << endl;
};

// 引用
void main5(){
    int a = 10;//门牌号(内存空间0x00001的别名，可不可以有多个名字？)
    //C语言正常语法 &表示：取地址
    //C++ &表示：引用
    int &b = a; //b实际上就是另外一个别名

    //引用必须要初始化
    //int &c;

    cout << b << endl;
};
//指针交换值
void swip1(int *a, int *b){
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

void main6(){
    int x = 10;
    int y = 30;
    printf("%d,%d\n", x, y);
//    swip1(&x,&y);

    //a 成了x的别名， b 成了y的别名
    swip2(x,y);
    printf("%d,%d\n",x,y);
};










