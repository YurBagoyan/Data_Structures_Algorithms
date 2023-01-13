#ifndef LIST_HPP
#define LIST_HPP

#include <cassert>
#include <iostream>

namespace DataStructure {
	template <typename T>
	class List
	{
		struct Node;

	public: /// Bidirectional iterators

		class Iterator {
		public:
			// Iterator constraints
			using difference_type = std::ptrdiff_t;
			using value_type = T;
			using pointer = const T*;
			using reference = const T&;
			using iterator_category = std::bidirectional_iterator_tag;

			Iterator() = default;

			T& operator*();
			const T& operator*() const;

			Iterator& operator++();		// prefix
			Iterator operator++(int);	// postfix   --- Test needed

			Iterator& operator--();		//prefix
			Iterator operator--(int);	// postfix   --- Test needed

			bool operator==(const Iterator&) const;
			bool operator!=(const Iterator&) const;

		private:
			Iterator(Node*);
			friend class List;

		private:
			Node* node_{ nullptr };
		}; // class Iterator

		class ConstIterator {
		public:
			// Iterator constraints
			using difference_type = std::ptrdiff_t;
			using value_type = T;
			using pointer = const T*;
			using reference = const T&;
			using iterator_category = std::bidirectional_iterator_tag;

			ConstIterator() = default;

			const T& operator*() const;

			ConstIterator& operator++();		// prefix
			ConstIterator operator++(int);		// postfix   --- Test needed

			ConstIterator& operator--();		//prefix
			ConstIterator operator--(int);		// postfix   --- Test needed

			bool operator==(const ConstIterator&) const;
			bool operator!=(const ConstIterator&) const;

		private:
			ConstIterator(Node*);
			friend class List;

		private:
			const Node* node_{ nullptr };
		}; // class ConstIterator

		Iterator begin();
		ConstIterator cbegin() const;
		Iterator end();
		ConstIterator cend() const;

	public:

		List() = default;
		~List();

		/// Copy constructor
		List(const List&);
		List& operator=(const List);

		/// Move constructor
		List(List&&) noexcept;
		List& operator=(List&&) noexcept;

		T& operator[](const size_t);
		bool operator==(const List&) const;
		bool operator!=(const List&) const;

		bool empty() const noexcept;
		size_t size() const noexcept;
		void push_back(const T&);
		void push_front(const T&);
		void swap(List&) noexcept;
		void print() const;
		void insert(size_t, const T);

	private: /// Helpers

		void createNode(const T& value);
		void clearList();

	private: /// Members

		struct Node {
			Node() = default;
			Node(const T& v) : value(v) {};
			T value;
			Node* next{ nullptr };
			Node* prev{ nullptr };
		};

		Node* dummy_ = new Node(NULL);
		Node* first_{ dummy_ };
		Node* last_{ dummy_ };
		size_t size_{ 0 };

	public: /// Problems

		/// Problem 3
		const T find_Middle_Node_Value() const;

		/// problem 4
		// This function only for testing, it will create a loop and will crash when Destructor is triggered
		void createLoop();
		bool detectLoop() const;

		/// Problem 5
		void reverse();
	}; // class List

	template<typename T>
	inline void swap(List<T>& l1, List<T>& l2) noexcept
	{
		l1.swap(l2);
	}
} // namespace DataStructure

#include "List.impl.hpp"

#endif // LIST_HPP