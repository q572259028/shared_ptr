#ifndef MYSHARED_PTR_HPP
#define MYSHARED_PTR_HPP

template <typename T>
class Myshared_ptr
{
public:
	Myshared_ptr();
	explicit Myshared_ptr(T*);
	Myshared_ptr(const Myshared_ptr<T>&);
	~Myshared_ptr();
	Myshared_ptr<T>& operator = (const Myshared_ptr<T>&);
	int operator - (const Myshared_ptr<T>&);
	bool operator < (const Myshared_ptr<T>&);
	T* operator -> ();
	operator bool();
	operator T*();
	int use_count();
	T* get();
	void swap(Myshared_ptr<T>&);

private:
	T* _ptr;
	int* _cnt;
};
template <typename T>
Myshared_ptr<T>::Myshared_ptr() :_ptr(nullptr), _cnt(new int(0))
{

}
template <typename T>
Myshared_ptr<T>::Myshared_ptr(T* source) : _ptr(source), _cnt(new int(1))
{

}
template <typename T>
Myshared_ptr<T>::Myshared_ptr(const Myshared_ptr<T>& source)
{
	_ptr = source._ptr;
	_cnt = source._cnt;
	if(_ptr!=nullptr)
	*_cnt += 1;
}
template <typename T>
Myshared_ptr<T>::~Myshared_ptr()
{
	if (_ptr == nullptr)return;
	if (*_cnt <= 1)
	{
		delete _ptr;
		delete _cnt;
		_ptr = nullptr;
		_cnt = 0;
	}
	else
	{
		*_cnt -= 1;
	}
}

template <typename T>
Myshared_ptr<T>& Myshared_ptr<T>::operator = (const Myshared_ptr<T>& source)
{
	if (this == &source)
		return *this;
	if (_ptr!=nullptr && --(*_cnt) <= 0)
	{
		delete _ptr;
		delete _cnt;
	}
	_ptr = source._ptr;
	_cnt = source._cnt;
	if (_ptr != nullptr)
	*_cnt += 1;
	return *this;
}
template <typename T>
int Myshared_ptr<T>::operator - (const Myshared_ptr<T>& source)
{
	return _ptr - source._ptr;
}
template <typename T>
bool Myshared_ptr<T>::operator < (const Myshared_ptr<T>& source)
{
	return _ptr < source._ptr;
}
template <typename T>
T* Myshared_ptr<T>::operator -> ()
{
	return _ptr;
}
template <typename T>
Myshared_ptr<T>::operator bool()
{
	return _ptr;
}
template <typename T>
Myshared_ptr<T>::operator T*()
{
	return _ptr;
}
template <typename T>
int Myshared_ptr<T>::use_count()
{
	return *_cnt;
}
template <typename T>
T* Myshared_ptr<T>::get()
{
	return _ptr;
}
template <typename T>
void Myshared_ptr<T>::swap(Myshared_ptr<T>& source)
{
	auto t1 = _ptr;
	auto t2 = _cnt;
	_ptr = source._ptr;
	_cnt = source._cnt;
	source._ptr = t1;
	source._cnt = t2;
}

#endif // MYSHARED_PTR_HPP
/*
myshared_ptr<int> p(a,b,c...);
myshared_ptr<int> p2();
myshared_ptr<int> p = p2;
if(p)
*p
p->..
p++;
p--
p+=
p - p2
!p
*/
