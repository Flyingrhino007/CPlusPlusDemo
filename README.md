# CPlusPlusDemo C++基础

##< native-lib1 >

1 . 标准命名空间 using namespace (解决命名太长问题)<br>

	命名空间嵌套 
	访问修饰符 ::
	class类（new 出来的是一个指针，一般只需要声明即可，声明会默认初始化无参构造函数 、与结构体一致）
	bool类型
	三元运算符
	引用&（对象的别名）： 指针比地址，引用比值
	指针，引用使用的区别（指针的引用等效于二级指针）
	指针常量与常量指针
	常引用与字面量const
2 . 函数<br>

	函数的默认参数
	可变参数
	构造函数
	析构函数~: 当对象要被系统释放时，析构函数被调用,一般释放资源
	拷贝构造函数:参数就是对象自己，具体的copy自己处理，类似于做clone操作
		浅拷贝深拷贝：
			 浅copy : 仅仅只是copy指针的地址
			 深copy : copy 的是指针指向的数据内容
	资源释放区别c:
		C++   通过new(delete)动态内存分配 , new 出来的是存堆内存的，所以需要释放堆内存空间
		C	  malloc(free)
			c++里面new 调用构造函数，delete调用析构函数
	静态属性和方法：静态属性只能全局初始化，但是可以局部代码修改，都可以类名.方法或者对象名.方法
	存储区域：
		C/C++ 内存分区：栈、堆、全局（静态、全局）、常量区（字符串）、程序代码区
	常函数与常对象：(被const修饰)
		常函数，修饰的是this, 就是this 被禁止不能修改属性和其他（既不能改变指针的值，又不能改变指针指向的内容）
		常对象：只能调用常量函数，不能调用非常量函数
	有元函数：（friend修饰的函数）
		目的：外部使用友元函数，当前函数访问内部的私有属性
	有元类：与有元函数类似，可以访问其有元的内部所有属性
	重载：operator+ ，operator- ，可以在方法外部调用，也可以在类中的方法中使用
	
***

###< 01.c，02.c >

1 . 类<br>

	继承
		子类初始化：
			1.父类类型的引用或指针 （ Human *human = &m， Human &human = m1）
			2.直接赋值是新开辟的空间（Human human = m）
		父类初始化，属性初始化
			3.给父类构造函数传参，同给属性对象赋值 ,需要给父类，子类全部参数都构造才行
		父子类，构造，析构函数调用顺序
			构造函数：父类->子类
			析构函数：子类->父类
		子类调用父类的方法：
			man.Human::xxx()    : man 子类  human 父类
	继承的访问修饰
			基(父)类中    继承方式        子类中
			public     ＆ public继承 = > public
			public     ＆ protected继承 = > protected
			public     ＆ private继承 = > private
			
			protected  ＆ public继承 = > protected
			protected  ＆ protected继承 = > protected
			protected  ＆ private继承 = > private
			
			private    ＆ public继承 = > 子类无权访问
			private    ＆ protected继承 = > 子类无权访问
			private    ＆ private继承 = > 子类无权访问
	继承的二义性
		虚继承：( virtual )  
			针对类：不同路径继承来的同名成员只有一份拷贝，解决不明确的问题
			class A {public:char *name;};
			class A1 : virtual public A {};
			class A2 : virtual public A {};
			class B : public A1, public A2 {};
			使用： 
				保持一份copy:
					B b;   
					b.name = "json";
				指定父类显示调用  ,这样就有2份
					b.A1::name = "json";
					b.A2::name = "json";
		虚函数：一般在多态中使用（并且函数被重写），一般在子类重写父类的函数中，用virtual 修饰函数
		纯虚函数：
			1.当一个类具有一个纯虚函数，这个类就是抽象类
			2.抽象类不能实例化对象
			3.子类继承抽象类，必须要实现纯虚函数，如果没有，子类也是抽象类
		接口：当内部都是虚函数的时候

		模板函数：  类似于java的泛型
			template<typename T,typename Z>
			void myswip(T &a, T &b) {
				T temp = a;
				a = b;
				b = temp;
			};
			使用：
				myswip<int >(a, b);
				myswip<char >(x, y);
		模板类：
			template<class T>
		普通类继承模板类
		模板类继承模板类
2 . 异常处理<br>

	捕获：
		try {
			throw 9.8;  // throw 抛出异常
		} catch (char *b) {
			cout << "char异常" << b << endl;
		} catch (int a) {
			cout << "int异常" << endl;
		} catch (out_of_range e) {
			cout << e1.what() << endl;
		} catch (...) {
			cout << "未知异常" << endl;
		}
	抛出：throw
	定义异常类：
		1>	MyException {
			};
			使用：throw MyException(); // 不要new，因为new出来的是一个指针
				在捕获的时候 MyException &exception1（MyException *e1） 才行，否则会创建副本
		2> 	#include <stdexcept>
			//标准异常（类似于JavaNullPointerException）
			class NullPointerException : public exception {
			public:
				NullPointerException(char *msg) : exception() {
				}
			};
3 . 类型转换<br>

	默认赋值，自动转换
	static_cast 普遍情况
	const_cast 去常量
	dynamic_cast 子类类型转为父类类型 // 转型之后需要做NULL判断，如果为NULL则转型失败
	reinterpret_cast 函数指针类型，不具备移植性，就是说不一定支持能够转换成功（针对函数）
4 . IO流 ( #include <fstream> )<br>

	输出：
		ofstream fout
		fout.bad  return	
		fout.close
	输入：
		ifstream fin
		fin.get  return
		fin.close
	写入：
		while (!fin.eof()){
			// 读取
			char buff[1024] = {0};
			fin.read(buff,1024);
			// 写入
			fout.write(buff,1024);
		}
	写入对象：
		Person p("柳岩", 22);
		ofstream fout("c://c_obj.data", ios::binary);
		fout.write((char*)(&p), sizeof(Person)); //指针能够读取到正确的数据，读取内存区的长度 
		fout.close();
		
***

###< native-lib2，native-lib3，native-lib4 >

1 . 函数对象<br>

		列如：	template<typename T>   // 模板函数
				class A{
				  void operator()(T &t){}   // 重载函数
				}
		结合集合：vector (#include <vector> )，使用for_each(v1.begin(), v1.end(), Func<int>());
	谓词
		列如：	template<typename T>
				class MyDivision {
				public:
					bool operator()(T &t) {
						return (t % 5 == 0);
					};
				};
		结合集合：vector<int>::iterator it = find_if(v1.begin(), v1.end(), MyDivision<int>());
	二元谓词
		列如：
				template<typename T>
				class MyAdd {
				public:
					T operator()(T &t1, T &t2) {
						return t1 + t2;
					};
				};
		结合集合：transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), MyPrint<int>());
		count_if : 查找
2 . string（#include <string>）<br>

	初始化
	遍历（数组，迭代器，at函数 三种方式）
	string->c 转换 （s.c_str()，s.copy()）
	字符串拼接	append (+ ，append )
	字符串查找	find
	字符串替换	replace
	字符串插入	insert
	
3 . 集合：<br>

	vector (栈  #include <vector> )
		添加: push_back
		复制：初始化或者== ，直接赋值
		修改： 修改头部：.front()=xxx，修改尾部：.back()=xxx
		弹出：pop_back
		迭代：vector<int>::iterator  it
		删除：v.erase (it)
		插入：v.insert()
	deque (双向队列  #include <deque> ) 
		添加：push_back  （添加到头部 push_front）
		弹出：pop_back （头部弹出 pop_front）