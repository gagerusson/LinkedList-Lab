#pragma once

#include <string>

#include "LinkedListInterface.h"
#include <string>
#include <sstream>
#include <exception>

using namespace std;

template<typename T>
class LinkedList: public LinkedListInterface<T> {
private:
    class Node {
    public:
        Node(T value) : value(value), next(nullptr) {}
        T value;
        Node* next;
    };
    Node* head;
    Node* tail;
    size_t len;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
        len = 0;
    }

    virtual ~LinkedList() {
        clear();
    }

    virtual void push_front(T item) {
        Node *newNode = new Node(item);
        if (len == 0) {
            tail = newNode;
        }
        //newNode->value = item;
        newNode->next = head;
        head = newNode;
        len++;
    }

    virtual void push_back(T item) {
        Node* newNode = new Node(item);
        if (is_empty()) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        len++;
    }

    virtual void insert(T item, size_t position) {
        if (position > len || position < 0) {
            throw out_of_range("Index is out of range");
        }
        len++;
        Node *newNode = new Node(item);
        if (position == 0) {
            newNode->next = head;
            head = newNode;
            return;
        }
        if (position == len) {
            newNode->next = nullptr;
            tail = newNode;
            return;
        }
        Node *temp = head;
        for (int i = 0; i < position - 1; i++) {
            if (temp == nullptr) {
                break;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    virtual void pop_front() {
        if (is_empty()) {
            throw length_error("Insufficient Length");
        }
        head = head->next;
        len--;
    }

    virtual void pop_back() {
        if (is_empty()) {
            throw length_error("Insufficient Length");
        }
        if (len == 1) {
            delete head;
            head = NULL;
            tail = nullptr;
            len--;
            return;
        }
        Node *temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        tail = temp;
        temp->next = nullptr;
        len--;
    }

    virtual void remove(size_t position) {
        if (position >= len || position < 0) {
            throw out_of_range("Index is out of range");
        }
        if (position == 0) {
            pop_front();
        }
        Node *temp = head;
        for (int i = 0; i < position - 1; i++) {
            if (temp == nullptr || temp->next == nullptr) {
                return;
            }
            temp = temp->next;
        }
        temp->next = temp->next->next;
        len--;
    }

    virtual T front() const {
        if (len == 0) {
            throw length_error("Insufficient Length");
        }
        return head->value;
    }

    virtual T back() const {
        if (len == 0) {
            throw length_error("Insufficient Length");
        }
        //return tail->value;
        Node *temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        return temp->value;
   }

    virtual T at(size_t index) const {
        if (index >= len || index < 0) {
            throw out_of_range("Index is out of range");
        }
        Node *temp = head;
        for (int i = 0; i < index; i++) {
            if (temp == nullptr) {
                break;
            }
            temp = temp->next;
        }
        return temp->value;
    }

    virtual bool contains(const T& item) const {
        Node *temp = head;
        while (temp != nullptr) {
            if (temp->value == item) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    virtual size_t size() const {
        return len;
    }

    virtual void clear() {
        while (head != nullptr) {
            pop_front();
        }
        head = nullptr;
        tail = nullptr;
    }

    virtual std::string toString() const {
        stringstream ss;
        Node *temp = head;
        while (temp != nullptr) {
            ss << temp->value << " ";
            temp = temp->next;
        }
        return ss.str();
    }

    virtual bool is_empty() const {
        return len == 0;
    }

};
