#pragma once
#include "Node.h"
#include "Cargo.h"

template <class T>
class LinkedList 
{
	Node<T>* Head;

public:
	LinkedList()
	{
		Head = nullptr;
	}

	bool IsEmpty()
	{
		return (Head == nullptr);
	}

	bool insert(T data)
	{
		Node<T>* NewNode = new Node<T>(data, nullptr);
		if (IsEmpty())
		{
			Head = NewNode;
		return true;
		}
		Node<T>* Temp = Head;
		while (Temp->GetNext())
			Temp = Temp->GetNext();
		Temp->SetNext(NewNode);
		return true;
	}

	T* Delete(T val)
	{
		if (!isfound(val))
		{
			return;
		}

		if (Head->GetNext() == nullptr)
		{
			Head = nullptr;
			return;
		}

		Node<T>* temp = Head;

		while (temp->GetNext() != nullptr)
		{
			if (temp->GetData() == val)
			{
				temp->GetData() = temp->GetNext()->GetData();
				temp->GetNext() = temp->GetNext()->GetNext();
				return;
			}
			if (temp->GetNext()->GetNext() == nullptr)
			{
				temp->GetNext() = nullptr;
				break;
			}
			temp = temp->GetNext();
		}
	}

	bool RemoveFirst(T& Data)
	{
		if (IsEmpty())
			return false;

		Node<T>* NodeToBeDeleted = Head;
		Data = NodeToBeDeleted->GetData();
		Head = Head->GetNext();
		delete NodeToBeDeleted;
		return true;
	}

	int GetCount()
	{
		int Counter = 0;
		Node<T>* Temp = Head;
		while (Temp)
		{
			Counter++;
			Temp = Temp->GetNext();
		}
		return Counter;
	}

	void Print()
	{
		Node<T>* Temp = Head;
		while (Temp)
		{
			cout << Temp->GetData();
			Temp = Temp->GetNext();
		}
	}
};


template <>
class LinkedList <Cargo>
{
	Node<Cargo>* Head;

public:
	LinkedList()
	{
		Head = nullptr;
	}

	bool IsEmpty()
	{
		return (Head == nullptr);
	}

	bool insert(Cargo data)
	{
		Node<Cargo>* NewNode = new Node<Cargo>(data, nullptr);
		if (IsEmpty())
		{
			Head = NewNode;
			return true;
		}
		Node<Cargo>* Temp = Head;
		while (Temp->GetNext())
			Temp = Temp->GetNext();
		Temp->SetNext(NewNode);
		return true;
	}

	Cargo* Delete(int id)
	{
		Node<Cargo>* temp = Head;

		if (IsEmpty())
			return nullptr;
		if (temp->GetData().GetID() == id)
		{
			Head = temp->GetNext();
			return &(temp->GetData());
		}
		Node<Cargo>* NodeToBeDeleted;
		while (temp->GetNext())
		{
			if (temp->GetNext()->GetData().GetID() == id)
			{
				NodeToBeDeleted = temp->GetNext();
				temp->SetNext(NodeToBeDeleted->GetNext());
				return &(NodeToBeDeleted->GetData());
			}
			temp = temp->GetNext();
		}
		return nullptr;
	}

	bool RemoveFirst(Cargo& Data)
	{
		if (IsEmpty())
			return false;

		Node<Cargo>* NodeToBeDeleted = Head;
		Data = NodeToBeDeleted->GetData();
		Head = Head->GetNext();
		delete NodeToBeDeleted;
		return true;
	}

	int GetCount()
	{
		int Counter = 0;
		Node<Cargo>* Temp = Head;
		while (Temp)
		{
			Counter++;
			Temp = Temp->GetNext();
		}
		return Counter;
	}

	void Print()
	{
		Node<Cargo>* Temp = Head;
		while (Temp)
		{
			if (!Temp->GetNext())
			{
				cout << Temp->GetData().GetID();
				return;
			}
			cout << Temp->GetData().GetID() << ",";
			Temp = Temp->GetNext();
		}
	}
};

