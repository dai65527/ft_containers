/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 10:19:40 by dnakano           #+#    #+#             */
/*   Updated: 2021/02/03 15:51:40 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This file is re-impremantation of std::vector<T> as ft::vector<T>.
** Supports only C++98 features.
**
** References
** - 42 cursus subject
** - http://www.cplusplus.com/reference/vector/vector/
** - https://cpprefjp.github.io/reference/vector/vector.html
*/

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstring>
#include <iterator>
#include <limits>
#include <memory>

// self-made headers (rekkaban copy)
#include "iterator.hpp"
#include "type_traits.hpp"

namespace ft {

template <class T, class Allocator = std::allocator<T> >
class vector {
 public:
  /*** member type definitions ***/
  typedef T value_type;
  typedef Allocator allocator_type;
  typedef typename allocator_type::reference reference;
  typedef typename allocator_type::const_reference const_reference;
  typedef typename allocator_type::size_type size_type;
  typedef typename allocator_type::difference_type difference_type;
  typedef typename allocator_type::pointer pointer;
  typedef typename allocator_type::const_pointer const_pointer;

  /*** iterators ***/
 public:
  typedef ft::random_access_iterator_base_<value_type, difference_type, pointer,
                                           reference>
      iterator;

  typedef ft::random_access_iterator_base_<const value_type, difference_type,
                                           pointer, reference>
      const_iterator;

  typedef std::reverse_iterator<iterator> reverse_iterator;

  typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

 private:
  value_type* values_;
  allocator_type alloc_;
  size_type size_;
  size_type capacity_;

 public:
  /*** constuctors ***/
  // default constructor
  explicit vector(const allocator_type& alloc = allocator_type()) {
    alloc_ = alloc;
    values_ = NULL;
    size_ = 0;
    capacity_ = 0;
  }

  // fill constructor
  explicit vector(size_type n, const value_type& value,
                  const allocator_type& alloc = allocator_type()) {
    alloc_ = alloc;
    values_ = alloc_.allocate(n);
    for (size_type idx = 0; idx < n; ++idx) {
      values_[idx] = value;
    }
    size_ = n;
    capacity_ = n;
  }

  // range constructor
  // template <class InputIterator>
  // vector(InputIterator first, InputIterator last,
  //        const allocator_type& alloc = allocator_type());

  // copy constructor
  vector(const vector& x) {
    alloc_ = x.alloc_;
    if (x.capacity_ != 0) {
      values_ = alloc_.allocate(x.size_);
      for (size_type idx = 0; idx < x.size_; ++idx) {
        values_[idx] = x.values_[idx];
      }
      capacity_ = x.size_;
    } else {
      values_ = NULL;
      capacity_ = 0;
    }
    size_ = x.size_;
  }

  virtual ~vector() {
    if (capacity_ == 0) {
      alloc_.deallocate(values_, capacity_);
      return;
    }
    for (size_type idx = 0; idx < size_; ++idx) {
      alloc_.destroy(&values_[idx]);
    }
    alloc_.deallocate(values_, capacity_);
  }

  /*** operator overload ***/
  vector& operator=(const vector& x) {
    if (size_ > 0) {
      for (size_type idx = 0; idx < size_; ++idx) {
        alloc_.destroy(&values_[idx]);
      }
      alloc_.deallocate(values_, capacity_);
    }
    alloc_ = x.alloc_;
    values_ = alloc_.allocate(x.capacity_);
    for (size_type idx = 0; idx < x.size_; ++idx) {
      values_[idx] = x.values_[idx];
    }
    size_ = x.size_;
    capacity_ = x.capacity_;
    return (*this);
  }

  reference operator[](size_type n) { return values_[n]; }

  const_reference operator[](size_type n) const { return values_[n]; }

  friend bool operator==(const vector& x, const vector& y) {
    if ((x.size_ != y.size_)) {
      return false;
    }
    for (size_type idx = 0; idx < x.size_; ++idx) {
      if (x.values_[idx] != y.values_[idx]) {
        return false;
      }
    }
    return true;
  }

  friend bool operator!=(const vector& x, const vector& y) { return !(x == y); }

  /*** iterators ***/
  iterator begin() { return iterator(values_); }
  const_iterator begin() const { return const_iterator(values_); }
  iterator end() { return iterator(values_ + size_); }
  const_iterator end() const { return iterator(values_ + size_); }
  reverse_iterator rbegin() { return std::reverse_iterator<iterator>(end()); }

  const_reverse_iterator rbegin() const {
    return std::reverse_iterator<const_iterator>(end());
  }

  reverse_iterator rend() { return std::reverse_iterator<iterator>(begin()); }

  const_reverse_iterator rend() const {
    return std::reverse_iterator<const_iterator>(begin());
  }

  /*** private functions ***/
 private:
  size_type getNewCapacity_(size_type cap_prev, size_type cap_req) {
    if (cap_prev == 0) {
      return cap_req;
    } else if (cap_prev * 2 >= cap_req) {
      return cap_prev * 2;
    } else {
      return cap_req;
    }
  }

  template <class InputIterator>
  typename ft::enable_if<
      ft::is_same<std::input_iterator_tag,
                  typename InputIterator::iterator_category>::value ||
          ft::is_same<std::forward_iterator_tag,
                      typename InputIterator::iterator_category>::value ||
          ft::is_same<std::bidirectional_iterator_tag,
                      typename InputIterator::iterator_category>::value,
      size_type>::type
  getSizeFromIterator(InputIterator first, InputIterator last) {
    // TODO: add check function if first < last
    InputIterator iter = first;
    size_type n = 0;
    while (iter != last) {
      ++iter;
      ++n;
    }
    return n;
  }

  template <class InputIterator>
  typename ft::enable_if<
      ft::is_same<std::random_access_iterator_tag,
                  typename InputIterator::iterator_category>::value,
      size_type>::type
  getSizeFromIterator(InputIterator first, InputIterator last) {
    // TODO: add check function if first < last
    return last - first;
  }

  template <class Pointer>
  typename ft::enable_if<ft::is_pointer<Pointer>::value, size_type>::type
  getSizeFromIterator(Pointer first, Pointer last) {
    // TODO: add check function if first < last
    return last - first;
  }

  /*** capacity ***/
 public:
  size_type size() const { return size_; }
  size_type max_size() const { return alloc_.max_size(); }
  size_type capacity() const { return capacity_; }
  bool empty() const { return (size_ == 0); }

  void reserve(size_type n) {
    // no need to reserve
    if (n <= capacity_) {
      return;
    }
    value_type* values_new = alloc_.allocate(n);
    if (values_) {
      for (size_type idx = 0; idx < size_; ++idx) {
        values_new[idx] = values_[idx];
      }
      alloc_.deallocate(values_, capacity_);
    }
    values_ = values_new;
    capacity_ = n;
  }

  void resize(size_type n, value_type val = value_type()) {
    if (n <= size_) {
      size_ = n;
      return;
    }
    if (n > capacity_) {
      value_type* values_new = alloc_.allocate(n);
      for (size_type idx = 0; idx < size_; ++idx) {
        values_new[idx] = values_[idx];
      }
      alloc_.deallocate(values_, capacity_);
      values_ = values_new;
      capacity_ = n;
    }
    for (size_type idx = size_; idx < n; ++idx) {
      values_[idx] = val;
    }
    size_ = n;
  }

  /*** Element access ***/
  reference at(size_type n) {
    if (n >= size_) {
      throw std::out_of_range("vector");
    }
    return values_[n];
  }

  reference front() { return values_[0]; }
  const_reference front() const { return values_[0]; }
  reference back() { return values_[size_ - 1]; }
  const_reference back() const { return values_[size_ - 1]; }

  /*** modifiers ***/
  void assign(size_type n, const value_type& val) {
    for (size_type idx = 0; idx < size_; ++idx) {
      alloc_.destroy(&values_[idx]);
    }
    if (n > capacity_) {
      delete[] values_;
      values_ = alloc_.allocate(n);
      capacity_ = n;
    }
    for (size_type idx = 0; idx < n; ++idx) {
      values_[idx] = val;
    }
    size_ = n;
  }

  template <class InputIterator>
  typename ft::enable_if<
      ft::is_same<std::input_iterator_tag,
                  typename InputIterator::iterator_category>::value ||
          ft::is_same<std::forward_iterator_tag,
                      typename InputIterator::iterator_category>::value ||
          ft::is_same<std::bidirectional_iterator_tag,
                      typename InputIterator::iterator_category>::value ||
          ft::is_same<std::random_access_iterator_tag,
                      typename InputIterator::iterator_category>::value,
      void>::type
  assign(InputIterator first, InputIterator last) {
    InputIterator iter = first;
    size_type n = getSizeFromIterator(first, last);
    for (size_type idx = 0; idx < size_; ++idx) {
      alloc_.destroy(&values_[idx]);
    }
    if (n > capacity_) {
      delete[] values_;
      values_ = alloc_.allocate(n);
      capacity_ = n;
    }
    n = 0;
    iter = first;
    while (iter != last) {
      values_[n] = *iter;
      ++n;
      ++iter;
    }
    size_ = n;
  }

  template <class Pointer>
  typename ft::enable_if<ft::is_pointer<Pointer>::value, void>::type assign(
      Pointer first, Pointer last) {
    Pointer iter = first;
    size_type n = getSizeFromIterator(first, last);
    for (size_type idx = 0; idx < size_; ++idx) {
      alloc_.destroy(&values_[idx]);
    }
    if (n > capacity_) {
      delete[] values_;
      values_ = alloc_.allocate(n);
      capacity_ = n;
    }
    n = 0;
    iter = first;
    while (iter != last) {
      values_[n] = *iter;
      ++n;
      ++iter;
    }
    size_ = n;
  }

  void push_back(const value_type& val) {
    if (size_ + 1 > capacity_) {
      reserve(size_ == 0 ? 1 : size_ * 2);
    }
    values_[size_] = val;
    ++size_;
  }

  void pop_back() {
    if (size_ != 0) {
      alloc_.destroy(&values_[size_ - 1]);
    }
    --size_;
  }

  iterator insert(iterator position, const value_type& val) {
    if (position == iterator(NULL)) {
      assign(1, val);
      return begin();
    }

    value_type* new_values;
    size_type new_capacity;
    const size_type offset = position - begin();

    if (size_ + 1 > capacity_) {
      new_capacity = getNewCapacity_(capacity_, size_ + 1);
      new_values = alloc_.allocate(new_capacity);
      for (size_type idx = 0; idx < offset; ++idx) {
        new_values[idx] = values_[idx];
      }
    } else {
      new_values = values_;
    }
    for (size_type idx = size_; idx > offset; --idx) {
      new_values[idx] = values_[idx - 1];
    }
    new_values[offset] = val;
    if (new_values != values_) {
      alloc_.deallocate(values_, capacity_);
      capacity_ = new_capacity;
      values_ = new_values;
    }
    ++size_;
    return begin() + offset;
  }

 public:
  void insert(iterator position, size_type n, const value_type& val) {
    if (position == iterator(NULL)) {
      assign(n, val);
      return;
    }

    value_type* new_values;
    size_type new_capacity;
    const size_type offset = position - begin();

    if (size_ + n > capacity_) {
      new_capacity = getNewCapacity_(capacity_, size_ + n);
      new_values = alloc_.allocate(new_capacity);
      for (size_type idx = 0; idx < offset; ++idx) {
        new_values[idx] = values_[idx];
      }
    } else {
      new_values = values_;
    }
    for (size_type idx = size_; idx > offset; --idx) {
      new_values[idx + n - 1] = values_[idx - 1];
    }
    for (size_type idx = offset; idx < offset + n; ++idx) {
      new_values[idx] = val;
    }
    if (new_values != values_) {
      alloc_.deallocate(values_, capacity_);
      capacity_ = new_capacity;
      values_ = new_values;
    }
    size_ += n;
    return;
  }

  template <class InputIterator>
  typename ft::enable_if<
      ft::is_same<std::input_iterator_tag,
                  typename InputIterator::iterator_category>::value ||
          ft::is_same<std::forward_iterator_tag,
                      typename InputIterator::iterator_category>::value ||
          ft::is_same<std::bidirectional_iterator_tag,
                      typename InputIterator::iterator_category>::value ||
          ft::is_same<std::random_access_iterator_tag,
                      typename InputIterator::iterator_category>::value,
      void>::type
  insert(iterator position, InputIterator first, InputIterator last) {
    if (position == iterator(NULL)) {
      assign(first, last);
      return;
    }

    size_type n = getSizeFromIterator(first, last);
    value_type* new_values;
    size_type new_capacity;
    size_type idx;
    InputIterator iter;
    const size_type offset = position - begin();

    if (size_ + n > capacity_) {
      new_capacity = getNewCapacity_(capacity_, size_ + n);
      new_values = alloc_.allocate(new_capacity);
      for (idx = 0; idx < offset; ++idx) {
        new_values[idx] = values_[idx];
      }
    } else {
      new_values = values_;
    }
    for (idx = size_; idx > offset; --idx) {
      new_values[idx + n - 1] = values_[idx - 1];
    }

    for (idx = offset, iter = first; idx < offset + n; ++idx, ++iter) {
      new_values[idx] = *iter;
    }
    if (new_values != values_) {
      alloc_.deallocate(values_, capacity_);
      capacity_ = new_capacity;
      values_ = new_values;
    }
    size_ += n;
    return;
  }

  template <class Pointer>
  typename ft::enable_if<ft::is_pointer<Pointer>::value, void>::type
  insert(iterator position, Pointer first, Pointer last) {
    if (position == iterator(NULL)) {
      assign(first, last);
      return;
    }

    size_type n = getSizeFromIterator(first, last);
    value_type* new_values;
    size_type new_capacity;
    size_type idx;
    Pointer iter;
    const size_type offset = position - begin();

    if (size_ + n > capacity_) {
      new_capacity = getNewCapacity_(capacity_, size_ + n);
      new_values = alloc_.allocate(new_capacity);
      for (idx = 0; idx < offset; ++idx) {
        new_values[idx] = values_[idx];
      }
    } else {
      new_values = values_;
    }
    for (idx = size_; idx > offset; --idx) {
      new_values[idx + n - 1] = values_[idx - 1];
    }

    for (idx = offset, iter = first; idx < offset + n; ++idx, ++iter) {
      new_values[idx] = *iter;
    }
    if (new_values != values_) {
      alloc_.deallocate(values_, capacity_);
      capacity_ = new_capacity;
      values_ = new_values;
    }
    size_ += n;
    return;
  }

  // void insert(iterator position, size_type n, const value_type& val);
  // template <class InputIterator>
  // void insert(iterator position, InputIterator first, InputIterator last);
  // iterator erase (iterator position);
  // iterator erase (iterator first, iterator last);

  void swap(vector& x) {
    vector tmp(x);
    x = *this;
    *this = tmp;
  }

  void clear() {
    for (size_type idx = 0; idx < size_; ++idx) {
      alloc_.destroy(&values_[idx]);
    }
    size_ = 0;
  }
};

}  // namespace ft

#endif /* VECTOR_HPP */
