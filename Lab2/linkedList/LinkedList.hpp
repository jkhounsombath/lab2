/**
*	@author 
*	@date 
*	@file LinkedList.hpp
*	@brief Implementation file for templated LinkedList class
*/

template <typename T>
LinkedList<T>::LinkedList() : m_front(nullptr), m_size(0)
{

}

template <typename T>
LinkedList<T>::~LinkedList() 
{
	while(!isEmpty())
	{
		removeFront();
	}
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
	return(m_size == 0);
}

template <typename T>
int LinkedList<T>::size() const
{
	/**
	TODO
	**/
	return(m_size);
}

template <typename T>
bool LinkedList<T>::search(T value) const
{
	Node<T>* temp = m_front;
	bool isFound = false;
	//empty list
	if(isEmpty())
	{
		return isFound;
	}
	//frontlist
	else if(m_front->getValue() == value)
	{
		isFound = true;
		return isFound;
	}
	//anything else
	else
	{
		for(int i=0; i<  size()-1; i++)
		{
			temp= temp->getNext();
			if(temp->getValue() == value)
			{
				isFound = true;
				return(isFound);
			}
		}
	}
	return(isFound);
}

template <typename T>
std::vector<T> LinkedList<T>::toVector() const
{
	std::vector<T> vec;
	Node<T>* temp = m_front;

	while( temp != nullptr )
	{
		vec.push_back(temp->getValue());
		temp = temp->getNext();
	}

	return(vec);	
	
}

template <typename T>
void LinkedList<T>::addBack(T value)
{
	Node<T>* temp = nullptr;

	if(isEmpty())
	{
		m_front = new Node<T>(value);	
	}
	else
	{
		temp = m_front;
		while(temp->getNext() != nullptr)
		{
			temp = temp->getNext();
		}

		temp->setNext( new Node<T>(value) );		
	}

	m_size++;
}

template <typename T>
void LinkedList<T>::addFront(T value)
{
	Node<T>* temp = m_front;
	m_front = new Node<T>(value);
	m_front->setNext( temp );
	m_size++;
}

template <typename T>
bool LinkedList<T>::removeBack()
{
	Node<T>* lastNode = nullptr;
	bool isRemoved = false;
	if(isEmpty())
	{
		return isRemoved;
	}
	else
	{
		if(m_front->getNext() == nullptr)
		{
			delete m_front;
			m_front= nullptr;
			isRemoved= true;
		}
		else
		{
			lastNode= m_front;
			while(lastNode->getNext()->getNext() != nullptr)
			{
				lastNode= lastNode->getNext();
			}
			delete lastNode->getNext();
			lastNode->setNext(nullptr);
		}
		m_size--;
	}
		
	return(isRemoved);
}	

template <typename T>
bool LinkedList<T>::removeFront()
{
	Node<T>* temp = nullptr;
	bool isRemoved = false;

	if(!isEmpty())
	{
		temp = m_front;
		m_front = temp->getNext();
		delete temp;
		m_size--;
		isRemoved = true;
	}

	return(isRemoved);
}
