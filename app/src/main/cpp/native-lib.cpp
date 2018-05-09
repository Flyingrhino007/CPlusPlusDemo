#include <jni.h>
#include <string>
#include <iostream>

extern "C"
JNIEXPORT jstring

JNICALL
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
