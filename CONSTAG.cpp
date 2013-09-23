/*
c o n s t可以用于集合，但编译器不能把一个集合存放在它的符号表里，所以必须分配内存。
在这种情况下，c o n s t意味着“不能改变的一块存储”。然而，其值在编译时不能被使用，因为
编译器在编译时不需要知道存储的内容。
*/

const int i[]={1,2,3,4};

//float f[i[3]];  //Illegal

struct s{int i, j;};

const s S[]={{1,2},{3,4}};

//double d[S[1].j]; //Illegal