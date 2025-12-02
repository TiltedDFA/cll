//
// Created by Malik T on 02/12/2025.
//

#ifndef CLL_LINKEDLIST_HPP
#define CLL_LINKEDLIST_HPP
#include "types.hpp"
#include "vector.hpp"

namespace cll
{
    template<typename T>
    struct ListNode
    {
        ListNode<T>* next;
        T data;
    };
    template<typename T>
    struct DoubleListNode final : public ListNode<T>
    {
        ListNode<T>* prev;
    };
    template<typename T>
    auto Find(ListNode<T> const* st, T const& val) -> ListNode<T>*
    {
        while(st != nullptr)
        {
            if(st->data == val) return st;
            st = st->next;
        }
        return nullptr;
    }
    template<typename T, typename Pred>
        requires UnaryBoolPredicate<Pred, T const&>
    auto FindIf(ListNode<T>* st, Pred pred) -> ListNode<T>*
    {
        while(st != nullptr)
        {
            if(pred(st->data)) return st;
            st = st->next;
        }
        return nullptr;
    }
    template<typename T>
    class LinkedList
    {
    public:
        LinkedList();
        ~LinkedList();
        auto add(T const& v) -> void;
        auto size() const -> size_t {return size_;}

    private:
        ListNode<T>* head_;
        size_t size_;
    };

}


#endif //CLL_LINKEDLIST_HPP