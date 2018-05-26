//
// Created by yanchunlan on 2018/5/24.
//

#include <jni.h>
#include <string>
#include <iostream>

using namespace std;


// c++ 类型转换
// static_cast 普遍情况
// const_cast 去常量
// dynamic_cast 子类类型转为父类类型
// reinterpret_cast 函数指针类型，不具备移植性，就是说不一定支持能够转换成功

// //原始类型转换，所有情况都是一种写法，可读性不高，有可能有潜在的风险

/*void *func(int type) {
    switch (type) {
        case 1: {
            int i = 9;
            return &i;
        }
        case 2: {
            int a = 'x';
            return &a;
        }
        default: {
            return NULL;
        }
    }
};

void func2(char *c_p) {
    cout << *c_p << endl;
};

int main() {
//    int i = 0;
//    //自动转换
//    double d = i;
//
//    double d1 = 9.5;
//    int i1 = d1;

    int i = 8;
    double d = 9.5;
    i = static_cast<int >(d); // 强制转换
    cout << i << endl;

//    void* -> char*  转换
    char *c_p = (char *) func(2);
    char *c_p1 = static_cast<char *>(func(2));


    // c++ 意图明显
    func2(static_cast<char * >(func(2)));
    // c
    func2((char *) func(2));
    return 0;
};*/

// 修改字符数组
/*void func(const char c[]) { // const之后就不能够修改了
    //     c[1] = 'a';
    // 通过 指针 间接赋值
    // 其他人并不知道，这次转型是为了去常量
    char *c_p = (char *) c;
    c_p[1] = 'x';
    //提高了可读性
    char *c_p1 = const_cast<char *>(c);
    c_p1[1] = 'x';
};

void main() {
    char c[] = "hello";
    func(c);// 打印出 hxllo
};*/

/*
class Person {
public:
// 因为多态所以需要 virtual
    virtual void print(){
        cout << "人" << endl;
    }
};

class Man : public Person{
public:
    void print(){
        cout << "男人" << endl;
    }

    void chasing(){
        cout << "泡妞" << endl;
    }
};

class Woman : public Person{
public:
    void print(){
        cout << "女人" << endl;
    }

    void carebaby(){
        cout << "生孩子" << endl;
    }
};

void func(Person *obj) {
    obj->print();

    // 调用子类的特有的函数，转为实际类型
    // 并不知道转型失败  下面危险
    //Man *man=(Man*)obj;
    //man->print();


    //转型失败，返回NULL
    Man* m=dynamic_cast<Man*>(obj);
	if(m!=NULL){
        m->chasing();
	}


    Woman* w = dynamic_cast<Woman*>(obj);
	if (w != NULL){
		w->carebaby();
	}

}

void main(){
    Woman  w1;
    Person *p1=&w1;

    func(p1)

    //Woman w1;
	//Woman* w_p = &w1;
}*/

/*
void func1(){
	cout << "func1" << endl;
}

char* func2(){
	cout << "func2" << endl;
	return "abc";
}

typedef void(*f_p)();// 函数指针类型

void main(){
//函数指针数组
    f_p f_array[6];
    //赋值
    f_array[0] = func1;

    //C方式
	//f_array[1] = (f_p)(func2);
    //C++方式
	f_array[1] = reinterpret_cast<f_p>(func2);

	f_array[1]();
}*/










extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_jnidemo_cplusplusdemo_MainActivity_byteFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    string hello = "Hello from C++";

    main();
    return env->NewStringUTF(hello.c_str());
}