#include <iostream>
#include <fstream>


class Node 
{
private:
    int _data;
    Node* _pNext;

public:
    Node(int data, Node* pNext = nullptr) : _data(data), _pNext(pNext) {}

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

    void pushBack(int data)
    {
        if (_head == nullptr)
        {
            _head = new Node(data);
        }
        else
        {
            Node* lastNode = getLast();
            Node* nodeToPush = new Node(data);
            lastNode->setNextAddr(nodeToPush);
        }   
    }

    Node& operator[](const int index)
    {
        int counter = 0;
        Node* current = this->_head;
        while (current != nullptr)
        {
            if (counter == index)
            {
                return *current;
            }
            current = current->getNextAddr();
            counter++;
        }
        return *_head;
    }

    void DeleteItem(int index)
    {
        if (_head == nullptr || index < 0)
        {
            return;
        }
        else if (index == 0)
        {
            Node* temp = _head;
            _head = _head->getNextAddr();
            delete temp;
            return;
        }
        else
        {
            Node& previousNode = (*this)[index-1];
            Node* current = previousNode.getNextAddr();

            if (current == nullptr)
            {
                return;
            }
            previousNode.setNextAddr(current->getNextAddr());
            if (current == getLast())
            {
                delete current;
                return;
            }
            delete current;
        }
    }

    void DeleteLast()
    {
        if (_head == nullptr)
        {
            return;
        }
        else if(_head->getNextAddr()==nullptr)
        {
            delete _head;
            _head = nullptr;
        }
        else
        {
            Node* current = _head;
            Node* previous = nullptr;

            while (current->getNextAddr() != nullptr)
            {
                previous = current;
                current = current->getNextAddr();
            }
            delete current;
            previous->setNextAddr(nullptr);
        }

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

    Node* getHead()
    {
        return _head;
    }

    ~List()
    {
        Node* current = _head;
        while (current != nullptr)
        {
            Node* temp = current;
            current = current->getNextAddr();
            delete temp;
        }
        _head = nullptr;
    }

    void saveToTxt(std::string& filename)
    {
        std::ofstream outputFile(filename);
        if (!outputFile.is_open())
        {
            std::cout << "Unable to open file." << std::endl;
            return;
        }
        Node* current = _head;
        while (current != nullptr)
        {
            outputFile << current->getValue() << "\n";
            current = current->getNextAddr();
        }
        outputFile.close();
    }

    void readFromTxt(std::string filename)
    {
        std::ifstream inputFile(filename);
        if (!inputFile.is_open())
        {
            std::cout << "Unable to open file." << std::endl;
            return;
        }
        int data;
        while (inputFile >> data)
        {
            pushBack(data);
        }
        inputFile.close();
    }

    

};


int main()
{
    List lst;
    lst.pushBack(55);
    lst.pushBack(5580);
    lst.pushBack(559);
    lst.pushBack(5455);
    lst.pushBack(5650);
    lst.pushBack(550);

    Node* iter = lst.getHead();
    while (iter)
    {
        std::cout << "My addr:" << iter->getAddr() << "\tvalue: " << iter->getValue() << "\tnext address: " << iter->getNextAddr() << std::endl;
        iter = iter->getNextAddr();
    }

    std::cout << "\nLast item of the list: " << lst.getLast();
    std::cout << "\nLength of the list: " << lst.getLength() << std::endl;
    std::cout << std::endl;

    lst.DeleteItem(2);
    lst.DeleteLast();

    std::cout << "\nLast item of the list: " << lst.getLast();
    std::cout << "\nLength of the list: " << lst.getLength() << std::endl;
    std::cout << std::endl;

    


    lst.test();

    std::cout << "\nLast item of the list: " << lst.getLast();
    std::cout << "\nLength of the list: " << lst.getLength() << std::endl;

    return 0;
};


