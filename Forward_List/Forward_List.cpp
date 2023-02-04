#include <iostream>

using namespace std;

template <typename T>
class forward_list
{
public:

	forward_list() {
		Size = 0;
		head = nullptr;
	}
	~forward_list() {
		clear();
	};

private:
	template <typename T>
	class Node
	{
	public:
		T data;
		Node* Pnext;
		Node(T& data = T(), Node* Pnext = nullptr) {
			this->data = data;
			this->Pnext = Pnext;

		};
		~Node() {
			
		};

	private:
		
	};
	int Size;
	Node<T>* head;
public:
	void push_back(T data) {
		if (head == nullptr)
		{
			head = new Node<T>(data);
		}
		else
		{
			Node<T>* currrent = this->head;
			while (currrent->Pnext != nullptr)
			{
				currrent = currrent->Pnext;
			}
			currrent->Pnext = new Node<T>(data);
		}
		Size++;
	}
	bool is_empty() {

	}
	int Get_size() {
		return Size;
	}
	T& operator [](const int index) {
		int counter = 0;
		Node<T>* current = this->head;
		while (current != nullptr)
		{
			if (counter == index)
			{
				return current->data;
			}
			current = current->Pnext;
			counter++;
		}
	};
	void pop_front() {
		Node<T>* temp = head;
		head = head->Pnext;
		delete temp;
		Size--;
	}
	void clear() {
		while (Size)
		{
			pop_front();
		}
	}

};


int main()
{
	int a = 10;
	forward_list<int> lst;
	lst.push_back(10);
	cout << lst[0];
}
