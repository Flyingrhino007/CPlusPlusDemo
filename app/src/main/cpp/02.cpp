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
// reinterpret_cast 函数指针类型，不具备移植性

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

/*class Person {
public:
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

void func(Person* obj){

    //调用子类的特有的函数，转为实际类型
    //并不知道转型失败
    //Man* m = (Man*)obj;
    //m->print();

    //转型失败，返回NULL
    Man* m = dynamic_cast<Man*>(obj);
    if (m != NULL){
        m->chasing();
    }

    Woman* w = dynamic_cast<Woman*>(obj);
    if (w != NULL){
        w->carebaby();
    }
}

void main(){

    //Woman w1;
    //Person *p1 = &w1;

    //func(p1);

    Woman w1;
    Woman* w_p = &w1;
}*/


/*
void func1(){
	cout << "func1" << endl;
}

char* func2(){
	cout << "func2" << endl;
	return "abc";
}

typedef void(*f_p)();

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

	system("pause");
}*/


#include <fstream>

//IO流
//文本文件操作
/*
void main(){
	char* fname = "c://dest.txt";
	//输出流
	ofstream fout(fname);
	//创建失败
	if (fout.bad()){
		return;
	}

	fout << "jack" << endl;
	fout << "rose" << endl;

	//关闭
	fout.close();

	//读取
	ifstream fin(fname);
	if (fin.bad()){
		return;
	}
	char ch;
	while (fin.get(ch)){
		//输出
		cout << ch;
	}
	fin.close();

}
*/

//二进制文件
/*
void main(){
	char* src = "c://src.jpg";
	char* dest = "c://dest.jpg";

	//输入流
	ifstream fin(src, ios::binary);
	//输出流
	ofstream fout(dest, ios::binary);

	if (fin.bad() || fout.bad()){
		return;
	}

	while (!fin.eof()){
		//读取
		char buff[1024] = {0};
		fin.read(buff,1024);

		//写入
		fout.write(buff,1024);
	}

	//关闭
	fin.close();
	fout.close();

}
*/

/*
//C++对象的持久化
class Person
{
public:
	Person()
	{

	}
	Person(char * name, int age)
	{
		this->name = name;
		this->age = age;
	}
	void print()
	{
		cout << name << "," << age << endl;
	}
private:
	char * name;
	int age;
};


void main()
{
	Person p1("柳岩", 22);
	Person p2("rose", 18);
	//输出流
	ofstream fout("c://c_obj.data", ios::binary);
	fout.write((char*)(&p1), sizeof(Person)); //指针能够读取到正确的数据，读取内存区的长度
	fout.write((char*)(&p2), sizeof(Person));
	fout.close();

	//输入流
	ifstream fin("c://c_obj.data", ios::binary);
	Person tmp;
	fin.read((char*)(&tmp), sizeof(Person));
	tmp.print();

	fin.read((char*)(&tmp), sizeof(Person));
	tmp.print();

}
*/


// stl standard template library 标准模板库
// util
// c++ 集合 -> java 集合


 /* void main(){
    string s1 = " craig david";
    string s2(" 7 days");
    string s3 = s1 + s2;
//    string s4 = s1.append(s2);

    cout << s3 << endl;

    // 转c字符串
    const char *c_str = s3.c_str();
    cout << c_str << endl;

    s1.at(2); // 访问2个元素
    s1.length(); // 长度

};*/



// 容器
#include <vector>

void main(){

    // 动态数组
    // 不需要使用动态内存分配，就可以使用动态数组
    vector<int> v;
    v.push_back(12);
    v.push_back(10);
    v.push_back(5);

    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << endl;
    }
};


extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_jnidemo_cplusplusdemo_MainActivity_byteFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    string hello = "Hello from C++";

    main();
    return env->NewStringUTF(hello.c_str());
}