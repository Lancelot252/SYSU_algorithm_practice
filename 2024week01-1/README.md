# z1-Constructor and destructor

题目描述（中文）：
给定如下的 Object 类实现（不得修改该类），请编写一个函数 TestObjects() 以产生所需的输出。输出应完全由 Object 的构造函数和析构函数产生。main() 将调用 TestObjects()。

示例提供的 Object 类（仅为说明，实际代码中不要修改）：
```cpp
class Object {
public:
    Object(int i) {
        id = i;
        count++;
        cout<<"Object "<<id<<" is created, we've got "<<count<<" object(s) now!"<<endl;
    }
    ~Object() { 
        count--;
        cout<<"Object "<<id<<" is deleted, we've got "<<count<<" object(s) now!"<<endl;
    }
private:
    int id;
    static int count;
};
int Object::count = 0;
```

要求：
- 不要修改上述 Object 类。
- 在 TestObjects() 中通过局部变量和作用域控制构造与析构顺序，以产生题目要求的输出。

Sample Output（示例输出，保持不变）：
```
Object 1 is created, we've got 1 object(s) now!
Object 2 is created, we've got 2 object(s) now!
Object 3 is created, we've got 3 object(s) now!
Object 3 is deleted, we've got 2 object(s) now!
Object 2 is deleted, we've got 1 object(s) now!
Object 4 is created, we've got 2 object(s) now!
Object 4 is deleted, we've got 1 object(s) now!
```
