#ifndef STACK_H
#define STACK_H

#include <stdexcept>

template<typename T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };
    
    Node* top;
    size_t size_;

public:
    // 构造函数
    Stack() : top(nullptr), size_(0) {}
    
    // 析构函数
    ~Stack() {
        clear();
    }
    
    // 拷贝构造函数
    Stack(const Stack& other) : top(nullptr), size_(0) {
        *this = other;
    }
    
    // 赋值操作符
    Stack& operator=(const Stack& other) {
        if (this != &other) {
            clear();
            if (other.top) {
                Node* current = other.top;
                Node* prev = nullptr;
                while (current) {
                    Node* newNode = new Node(current->data);
                    if (prev) {
                        prev->next = newNode;
                    } else {
                        top = newNode;
                    }
                    prev = newNode;
                    current = current->next;
                }
                size_ = other.size_;
            }
        }
        return *this;
    }
    
    // 入栈
    void push(const T& value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        size_++;
    }
    
    // 出栈
    T pop() {
        if (isEmpty()) {
            throw std::runtime_error("Stack is empty");
        }
        Node* temp = top;
        T value = top->data;
        top = top->next;
        delete temp;
        size_--;
        return value;
    }
    
    // 查看栈顶元素
    T peek() const {
        if (isEmpty()) {
            throw std::runtime_error("Stack is empty");
        }
        return top->data;
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
            pop();
        }
    }
};

#endif // STACK_H
