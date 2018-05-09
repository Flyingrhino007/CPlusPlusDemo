
//1.指针常量
//*p可以修改*p = 8；（OK）
//p不可以修改 p++（ERROR）
int a；
int * const p = &a

//2.常量指针
int a，b；
//*p不可修改 *p = 8；（ERROR）
//p 可以修改 p = &b  （OK）
const int *p = &a；

//指针的话看const离谁（ 是‘*’  还是‘指针变量名’）比较近就是修饰谁的

//还有一种*p 和 p均不可改变了
const int * const p = &a；