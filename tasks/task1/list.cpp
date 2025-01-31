#include "list.h"

List::List() : first(nullptr), last(nullptr) {}

void List::clear()
{
    while (first) {
        remove_front();
    }
}

bool List::is_empty()
{
    return first == nullptr;
}

Node* List::find(int _val)
{
    Node* current = first;
    while (current) {
        if (current->val == _val)
        {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

void List::push_front(int _val)
{
    Node* new_node = new Node(_val);
    if (!first)
    {
        first = last = new_node;
    }
    else
    {
        new_node->next = first;
        first = new_node;
    }
}

void List::push_back(int _val)
{
    Node* new_node = new Node(_val);
    if (!first)
    {
        first = last = new_node;
    }
    else
    {
        last->next = new_node;
        last = new_node;
    }
}

void List::remove_front()
{
    if (first)
    {
        Node* tmp = first;
        first = first->next;
        if (!first)
        {
            last = nullptr;
        }
        delete tmp;
    }
}

void List::remove_back()
{
    {
    if (is_empty()) return;
    if (first == last) {
        remove_first();
        return;
    }
    Node* p = first;
    while (p->next != last) p = p->next;
    p->next = nullptr;
    delete last;
    last = p;
}
}

bool List::remove(const Node* _node)
{
    bool flag = false;
    if (!first || !_node) flag = false;

    if (first == _node)
    {
        remove_front();
        flag = true;
    }

    Node* current = first;
    while (current->next && current->next != _node)
    {
        current = current->next;
    }

    if (current->next)
    {
        Node* temp = current->next;
        current->next = current->next->next;
        if (temp == last)
        {
            last = current;
        }
        delete temp;
        flag = true;
    }

    return flag;
}