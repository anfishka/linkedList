#include <SFML/Graphics.hpp>
#include <iostream>


//1) Создать класс list с свойством head и методом test() : void
//Который будет схож с main примера


class Node 
{
private:
    int _data;
    Node* _pNext;

public:
    Node(int data, Node* pNext)
    {
        this->_data = data;
        this->_pNext = pNext;
    }

    int getValue()
    {
        return this->_data;
    }

    Node* getAddr()
    {
        return &(*this);
    }

    void setNextAddr(Node* pNext)
    {
        this->_pNext = pNext;
    }

    Node* getNextAddr()
    {
        return _pNext;
    }


    
};

class List
{
private:
    Node* _head;
public:
    List() : _head(nullptr) {};

    int getLength()
    {
        int length = 0;
        Node* current = _head;
        while (current != nullptr) 
        {
            length++;
            current = current->getNextAddr();
        }
        return length;
    }

    Node* getLast()
    {
        Node* current = _head;

        if (current == nullptr)
        {
            return nullptr;
        }

        while (current->getNextAddr() != nullptr)
        {
            current = current->getNextAddr();
        }
        return current;
    }

    void test()
    {
        Node* f = new Node(0, nullptr);
        Node* s = new Node(1, nullptr);
        Node* t = new Node(2, nullptr);

        f->setNextAddr(s);
        s->setNextAddr(t);
       
        _head = f;

        Node* iter = _head;
        while (iter)
        {
            std::cout << "My addr:" << iter->getAddr() << "\tvalue: " << iter->getValue() << "\tnext address: "<< iter->getNextAddr()<<std::endl;
            iter = iter->getNextAddr();
        }
    }
};

//2) Сдеать метод getLength() : int для получения количества ячеек списка
//Сделать метод getLast() : Item * для получения последней ячейки

int main()
{
    List lst;
    lst.test();

    std::cout << "\nLast item of the list: " << lst.getLast();
    std::cout << "\nLength of the list: " << lst.getLength() << std::endl;

    return 0;
};

