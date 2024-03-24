#include <vector>
#include <iterator>
#include <memory>
#include <cstddef>

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
    using value_type        = detail::node_t<ElemT>;
    using pointer           = value_type*;
    using reference         = value_type&;
    using const_pointer     = const value_type*;
    using const_reference   = const value_type&;

    list_iterator& operator++() {
        ptr_ = ptr_->next_;
        return *this;
    }

    list_iterator operator++(int) {
        auto temp{*this};
        operator++();
        return temp;
    }

    ElemT& operator*()         const noexcept { return ptr_->value_; }
    list_iterator operator->() const noexcept { return *this; }

    bool operator==(list_iterator rhs) const noexcept { return ptr_ == rhs.ptr_; }
    bool operator!=(list_iterator rhs) const noexcept { return !(*this == rhs); }

private:
    friend class my_list<ElemT>;

    void set_next(list_iterator iter) { ptr_->next_ = iter.ptr_; }

    pointer ptr_;

public:
    list_iterator(pointer ptr = nullptr) : ptr_(ptr) {}
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

    void emplace_after(iterator iter, int value = ElemT{}) {
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
