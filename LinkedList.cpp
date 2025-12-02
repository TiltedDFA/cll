//
// Created by Malik T on 02/12/2025.
//

#include "LinkedList.hpp"

namespace cll
{
    template <typename T>
    LinkedList<T>::LinkedList():
        head_(nullptr), size_(0ull)
    { }
    template <typename T>
    LinkedList<T>::~LinkedList()
    {
        Vector<ListNode<T>*> nodes;
        ListNode<T>* node = head_;
        while(node != nullptr)
        {
         nodes.push_back(node);
         node = node->next;
        }
        for(auto&& n : nodes)
            delete n;
    }

}
