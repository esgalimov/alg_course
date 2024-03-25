#include <vector>
#include <iterator>
#include <memory>
#include <cstddef>
#include <stdexcept>

template <typename ElemT>
requires std::is_arithmetic_v<ElemT>
class my_list;

namespace detail {
    template <typename ElemT>
    struct node_t final {
        ElemT value_;
        node_t* next_;

        node_t(ElemT value = 0, node_t* next = nullptr) :
            value_(value), next_(next) {}
    };
};

template <typename ElemT>
class list_iterator final {
public:
    using iterator_category = std::forward_iterator_tag;
    using difference_type   = std::ptrdiff_t;
    using value_type        = ElemT;
    using pointer           = value_type*;
    using reference         = value_type&;
    using const_pointer     = const value_type*;
    using const_reference   = const value_type&;

    using node_ptr          = detail::node_t<ElemT>*;

    list_iterator& operator++() {
        ptr_ = ptr_->next_;
        return *this;
    }

    list_iterator operator++(int) {
        auto temp{*this};
        operator++();
        return temp;
    }

    reference operator*()  const noexcept { return                ptr_->value_;  }
    pointer   operator->() const noexcept { return std::addressof(ptr_->value_); }

    bool operator==(list_iterator rhs) const noexcept { return ptr_ == rhs.ptr_; }
    bool operator!=(list_iterator rhs) const noexcept { return !(*this == rhs); }

    void set_next(list_iterator iter) { ptr_->next_ = iter.ptr_; }

private:
    node_ptr ptr_;

public:
    list_iterator(node_ptr ptr = nullptr) : ptr_(ptr) {}
};

template <typename ElemT>
    requires std::is_arithmetic_v<ElemT>
class my_list final {
public:
    using iterator = list_iterator<ElemT>;

private:
    std::vector<std::unique_ptr<detail::node_t<ElemT>>> buffer_;

    iterator before_begin_, begin_, end_;

    size_t sz_ = 0;

public:
    my_list() {
        before_begin_ = create_node(ElemT{});
        begin_        = create_node(ElemT{});
        end_          = begin_;

        before_begin_.set_next(end_);
    }

    my_list(const my_list& lst) = delete;
    my_list(my_list&& lst)      = delete;

    my_list& operator=(const my_list& lst) = delete;
    my_list& operator=(my_list&& lst)      = delete;

    void emplace_after(iterator iter, int value = ElemT{}) {
        if (iter == end_) throw std::runtime_error("Cannot emplace after end!");

        iterator new_elem = create_node(value),
                 it = iter,
                 new_after  = ++iter;

        it.set_next(new_elem);
        new_elem.set_next(new_after);
        sz_++;

        if (it == before_begin_) begin_ = new_elem;
    }

    void push_front(int value = ElemT{}) {
        emplace_after(before_begin_, value);
    }

    bool has_cycle() const {
        if (begin_ == end_) return false;

        iterator slow =   begin();
        iterator fast = ++begin();

        while (slow != fast) {
            if (fast++ == end_ || fast == end_) return false;

            slow++; fast++;
        }

        return true;
    }

    void reverse() {
        iterator prev = end_, curr = begin_, next;

        while (curr != end_) {
            next = std::next(curr);
            curr.set_next(prev);
            prev = curr;
            curr = next;
        }
        begin_ = prev;
        before_begin_.set_next(begin_);
    }

    iterator get_middle_node() const {
        iterator slow = begin_, fast = begin_;

        while (fast++ != end_ && fast != end_) {
            slow++;
            fast++;
        }
        return slow;
    }

    void erase(ElemT value) {
        iterator prev = before_begin_, curr = begin_;

        while (curr != end_) {
            if (*curr == value) {
                prev.set_next(++curr);
                sz_--;
            }
            else prev = curr++;
        }

        begin_ = std::next(before_begin_);
    }

    void merge_sorted_lists(my_list<ElemT>& lst) {
        iterator head1 = begin_, 
                 next1 = std::next(begin_), 
                 head2 = lst.begin_;
                 
        
        while (head1 != end_ && next1 != end_ && head2 != lst.end_) {
            if (*head1 <= *head2 && *head2 <= *next1) {
                emplace_after(head1, *head2);
                head2++;
            }
            else next1++;  

            head1++;    
        }
    }

    bool empty() { return sz_ == 0;}

    size_t size() { return sz_;}

    iterator begin()        { return begin_; }

    iterator before_begin() { return before_begin_; }

    iterator end()          { return end_; }

private:
    iterator create_node(int value) {
        buffer_.push_back(std::move(std::make_unique<detail::node_t<ElemT>>(value)));
        return iterator(buffer_.back().get());
    }

};
