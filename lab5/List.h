#include <iostream>
#include <memory>

#ifndef CPP5LIST3_LIST_H
#define CPP5LIST3_LIST_H

class ListException : public std::exception{
public:

    std::string what(){
        return "EmptyListException thrown!";
    }
};

template<class T>
struct Node {
    std::unique_ptr<Node> next = nullptr;
    T val;
public:
    Node(T _val): val(_val) {};
    ~Node(){};
    std::string getVal() const {return std::to_string(val); };

    Node(const Node &node) = delete;
    Node &operator=(const Node &list) = delete;
};

template <class T>
class LinkList {
    std::unique_ptr<Node<T>> start;
    int length = 0;

public:
    LinkList<T>():start(nullptr){};
    ~LinkList();
    void add(T val, int pos);

    template<class U>
    friend std::ostream &operator<<(std::ostream &out, const LinkList<U> &list);

    LinkList(const LinkList &list) = delete;
    LinkList &operator=(const LinkList &list) = delete;
};

template<class T>
void LinkList<T>::add(T val, int pos) {
    if (pos > length) {
        throw ListException();
    }

    if(pos == 0){
        auto tmp = std::make_unique<Node<T>>(val);
        tmp->next = std::move(start);
        start = std::move(tmp);
        length++;
        return;
    }

    auto tmp = std::make_unique<Node<T>>(val);

    Node<T> *ptr = start->next.get();
    Node<T> *prev = start.get();


    for (int index = 1; ptr != nullptr && index != pos; index++) {
        prev = prev->next.get();
        ptr = ptr->next.get();
    }

    tmp->next.reset(ptr);
    prev->next.release();
    prev->next = std::move(tmp);

    length++;
}

template<class T>
std::ostream &operator<<(std::ostream &out, const LinkList<T> &list) {
    Node<T> *ptr = list.start.get();

    if(ptr == nullptr){
        out << "empty list";
    }else{
        while (ptr != nullptr){
            out << ptr->getVal() << "->";
            ptr = ptr->next.get();
        }
    }

    out << std::endl;

    return out;
}

template<class T>
LinkList<T>::~LinkList() {
    std::cout << "Deleting list" << std::endl;
}


#endif //CPP5LIST3_LIST_H