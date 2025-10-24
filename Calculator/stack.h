#ifndef STACK_H
#define STACK_H

#include <stdexcept>

template<typename T>//模板类：支持任意数据类型
class Stack {
private:
    struct Node {//节点结构体
        T data;//节点储存数据
        Node* next;//指向后一个点的指针
        Node(const T& value) : data(value), next(nullptr) {}// 节点构造函数：初始化数据和指针
    };
    
    Node* top;//栈顶指针
    size_t size_;//栈中元素数量

public:
    // 构造函数，初始化空栈
    Stack() : top(nullptr), size_(0) {}
    
    // 析构函数，释放内存
    ~Stack() {
        clear();
    }
    
    // 拷贝构造函数（深拷贝）复制指针的动态内存，让新对象的指针指向新复制的内存块
    Stack(const Stack& other) : top(nullptr), size_(0) {//初始化新栈
        *this = other;//把被拷贝的对象拷贝到当前对象
    }
    
    // 赋值操作符
    Stack& operator=(const Stack& other) {
        if (this != &other) {//避免自我赋值
            clear();
            if (other.top) {//如果另一个栈为非空，则逐个复制节点
                Node* current = other.top;//遍历另一个栈的节点
                Node* prev = nullptr;//记录当前复制的节点（用于连接新链表）
                while (current) {//循环遍历，直到current为nullptr
                    Node* newNode = new Node(current->data);//调用node结构体创建新节点对象，将被复制的节点中的数据复制
                    if (prev) {//若已有前一个节点，让前一个节点的next指向新节点
                        prev->next = newNode;
                    } else {//若无则更新top指针
                        top = newNode;
                    }
                    prev = newNode;// prev指向当前新节点
                    current = current->next;// current移动到被复制栈的下一个节点
                }
                size_ = other.size_;//同步栈的大小
            }
        }
        return *this;//返回当前对象
    }
    
    // 入栈
    void push(const T& value) {
        Node* newNode = new Node(value);//创建新节点，存储待入栈的数据
        newNode->next = top;//让新节点的next指针指向当前栈顶
        top = newNode;//更新栈顶指针，使新节点成为新的栈顶
        size_++;//栈的大小加1
    }
    
    // 出栈
    T pop() {
        if (isEmpty()) {//检查栈是否是空
            throw std::runtime_error("Stack is empty");
        }
        Node* temp = top;//临时变量储存栈顶的指针
        T value = top->data;//保存栈顶节点的数据
        top = top->next;//top指向原栈顶的下一个节点（即新栈顶）
        delete temp;//释放原栈顶节点的内存
        size_--;//栈大小减一
        return value;//返回原栈顶节点的数据
    }
    
    // 查看栈顶元素
    T peek() const {//const表示不会修改，只进行只读操作
        if (isEmpty()) {
            throw std::runtime_error("Stack is empty");
        }
        return top->data;//返回栈顶元素的值
    }
    
    // 判断栈是否为空
    bool isEmpty() const {
        return top == nullptr;
    }
    
    // 获取栈大小
    size_t size() const {
        return size_;
    }
    
    // 清空栈
    void clear() {
        while (!isEmpty()) {
            pop();//通过循环调用 pop() 函数，每次删除栈顶元素，直到栈为空
        }
    }
};

#endif // STACK_H
