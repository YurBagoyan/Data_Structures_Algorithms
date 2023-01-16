#include <cassert>
#include <iostream>

#include "Doubly_linked_list.hpp"

namespace DataStructure {
	/******************* Bidirectional iterator *******************/
	template<typename T>
	List<T>::Iterator::Iterator(Node* node)
		: node_{ node }
	{
	}

	template<typename T>
	T& List<T>::Iterator::operator*()
	{
		return const_cast<T&>(const_cast<const Iterator*>(this)->operator*());
	}

	template<typename T>
	const T& List<T>::Iterator::operator*() const
	{
		assert(node_);
		return node_->value;
	}

	template<typename T>
	typename List<T>::Iterator& List<T>::Iterator::operator++()
	{
		node_ = node_->next;
		return *this;
	}

	template<typename T>
	typename List<T>::Iterator List<T>::Iterator::operator++(int)
	{
		Iterator temp(*this);
		node_ = node_->next;
		return temp;
	}

	template<typename T>
	typename List<T>::Iterator& List<T>::Iterator::operator--()
	{
		node_ = node_->prev;
		return *this;
	}

	template<typename T>
	typename List<T>::Iterator List<T>::Iterator::operator--(int)
	{
		Iterator temp(*this);
		node_ = node_->prev;
		return temp;
	}

	template<typename T>
	typename bool List<T>::Iterator::operator==(const Iterator& iter) const
	{
		return this->node_ == iter.node_;
	}

	template<typename T>
	typename bool List<T>::Iterator::operator!=(const Iterator& iter) const
	{
		return this->node_ != iter.node_;
	}

	/******************* Bidirectional const iterator *******************/

	template<typename T>
	List<T>::ConstIterator::ConstIterator(Node* node)
		: node_{ node }
	{
	}

	template<typename T>
	const T& List<T>::ConstIterator::operator*() const
	{
		assert(node_);
		return node_->value;
	}

	template<typename T>
	typename List<T>::ConstIterator& List<T>::ConstIterator::operator++()
	{
		node_ = node_->next;
		return *this;
	}

	template<typename T>
	typename List<T>::ConstIterator List<T>::ConstIterator::operator++(int)
	{
		ConstIterator temp(*this);
		node_ = node_->next;
		return temp;
	}

	template<typename T>
	typename List<T>::ConstIterator& List<T>::ConstIterator::operator--()
	{
		node_ = node_->prev;
		return *this;
	}

	template<typename T>
	typename List<T>::ConstIterator List<T>::ConstIterator::operator--(int)
	{
		ConstIterator temp(*this);
		node_ = node_->prev;
		return temp;
	}

	template<typename T>
	typename bool List<T>::ConstIterator::operator==(const ConstIterator& citer) const
	{
		return this->node_ == citer.node_;
	}

	template<typename T>
	typename bool List<T>::ConstIterator::operator!=(const ConstIterator& citer) const
	{
		return this->node_ != citer.node_;
	}

	/******************* begin(), cbegin(), end(), cend() *******************/
	template<typename T>
	typename List<T>::Iterator List<T>::begin()
	{
		return Iterator{ first_ };
	}

	template<typename T>
	typename List<T>::Iterator List<T>::end()
	{
		return Iterator{ dummy_ };
	}

	template<typename T>
	typename List<T>::ConstIterator List<T>::cbegin() const
	{
		return ConstIterator{ first_ };
	}

	template<typename T>
	typename List<T>::ConstIterator List<T>::cend() const
	{
		return ConstIterator{ dummy_ };
	}

	/******************** List implementation *********************/
	template<typename T>
	List<T>::~List()
	{
		clearList();
	}

	//Copy init
	template<typename T>
	List<T>::List(const List& rhs)
	{
		Node* temp = rhs.first_;
		while (temp->next != nullptr) {
			createNode(temp->value);
			temp = temp->next;
		}

		this->last_->next = dummy_;
		dummy_->prev = last_;
	}

	//Copy assign
	template<typename T>
	List<T>& List<T>::operator=(List rhs)
	{
		swap(*this, rhs);
		return *this;
	}

	//Move init
	template<typename T>
	List<T>::List(List&& rhs) noexcept
	{
		this->size_ = rhs.size_;
		this->first_ = rhs.first_;
		this->last_ = rhs.last_;

		rhs.first_ = rhs.last_ = nullptr;
		rhs.size_ = 0;
	}

	//Move assign
	template<typename T>
	List<T>& List<T>::operator=(List&& rhs) noexcept
	{
		List temp = std::move(rhs);
		swap(*this, temp);
		return *this;
	}

	template<typename T>
	T& List<T>::operator[](const size_t index)
	{
		Iterator it = begin();
		for (size_t i = 1; i < index; ++i) {
			++it;
		}

		return *it;
	}

	template<typename T>
	bool List<T>::operator==(const List& oth) const
	{
		if (this->size_ != oth.size_) {
			return false;
		}

		ConstIterator ItThis = this->cbegin();
		ConstIterator ItOth = oth.cbegin();

		for (; ItThis != cend(); ++ItThis, ++ItOth) {
			if (*ItThis != *ItOth) {
				return false;
			}
		}

		return true;
	}

	template<typename T>
	bool List<T>::operator!=(const List& oth) const
	{
		return !(*this == oth);
	}

	template<typename T>
	void List<T>::push_back(const T& value)
	{
		Node* temp = new Node(value);

		if (last_ == dummy_) {
			assert(last_ == dummy_ && first_ == dummy_);
			first_ = last_ = temp;
			first_->prev = last_->next = dummy_;
		}
		else {
			assert(last_ != dummy_);
			last_->next = temp;
			temp->prev = last_;
			temp->next = dummy_;
			last_ = temp;
		}

		dummy_->next = first_;
		dummy_->prev = last_;
		++size_;
	}

	template<typename T>
	void List<T>::push_front(const T& value)
	{
		Node* temp = new Node(value);

		if (empty()) {
			assert(first_ == dummy_ && last_ == dummy_);
			first_ = last_ = temp;
			first_->prev = last_->next = dummy_;
		}
		else {
			assert(first_ != dummy_ && last_ != dummy_);
			first_->prev = temp;
			temp->next = first_;
			temp->prev = dummy_;
			first_ = temp;
		}

		dummy_->next = first_;
		dummy_->prev = last_;
		++size_;
	}

	template<typename T>
	void List<T>::insert(const size_t index, const T value)
	{
		Iterator it = begin();
		for (size_t i = 1; i < index - 1; ++i) {
			++it;
		}

		Node* temp = new Node(value);

		temp->prev = it.node_;
		temp->next = it.node_->next;

		it.node_->next->prev = temp;
		it.node_->next = temp;
		++size_;
	}

	template<typename T>
	void List<T>::swap(List& l) noexcept
	{
		std::swap(first_, l.first_);
		std::swap(last_, l.last_);
		std::swap(dummy_, l.dummy_);
		std::swap(size_, l.size_);
		*this->last_->next = dummy_;
	}

	template<typename T>
	inline bool List<T>::empty() const noexcept
	{
		return size() == 0;
	}

	template<typename T>
	inline size_t List<T>::size() const noexcept
	{
		return size_;
	}

	template<typename T>
	void List<T>::createNode(const T& value)
	{
		Node* temp = new Node(value);

		if (last_ == dummy_) {
			assert(last_ == dummy_ && first_ == dummy_);
			last_ = temp;
			first_ = last_;
			++size_;
			return;
		}

		assert(last_ != dummy_);
		last_->next = temp;
		temp->prev = last_;
		last_ = temp;
		++size_;
	}

	template<typename T>
	void List<T>::clearList()
	{
		while (first_ != dummy_) {
			Node* temp = first_;
			first_ = first_->next;
			delete temp;
		}
		last_ = nullptr;
		size_ = 0;
	}

	template<typename T>
	void List<T>::print() const
	{
		for (List<T>::ConstIterator it = cbegin(); it != cend(); ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}

	/************************** Problem 3 *************************/

	template<typename T>
	const T List<T>::find_Middle_Node_Value() const
	{
		ConstIterator it = cbegin();

		for (size_t i = 0; i < size_ / 2; ++i) {
			++it;
		}

		return *it;
	}

	/************************** Problem 4 *************************/
	template<typename T>
	bool List<T>::detectLoop() const
	{
		Node* temp = first_->next;
		while (temp != dummy_) {
			if (temp == first_) {
				return true;
			}

			temp = temp->next;
		}

		return false;
	}

	template<typename T>
	void List<T>::createLoop()
	{
		first_->next->next->next->next = first_;
	}

	/************************** Problem 5 *************************/
	template<typename T>
	void List<T>::reverse()
	{
		Iterator leftIt = begin();
		Iterator rightIt = --end();

		for (size_t i = 0; i < size_ / 2; ++i, --rightIt, ++leftIt) {
			std::swap(*rightIt, *leftIt);
		}
	}
} // namespace DataStructure
