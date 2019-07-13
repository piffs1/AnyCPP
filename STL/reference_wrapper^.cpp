// Example program
#include "stdafx.h"
#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <cassert>
#include <string>
#include <thread>
namespace STL_BOOK {
	template<typename T>
	class reference_wrapper {
		T* m_ptr;
	public:
		reference_wrapper(T& t) noexcept : m_ptr(&t) {}

		operator T&() const noexcept { return *m_ptr; }
		T& get() const noexcept { return *m_ptr; }
	};

	template<typename T>
	reference_wrapper<T> ref(T& t);
}

using namespace std;

int main()
{
	int result = 0;
	auto task = [](int &x) {
		x = 42;
	};
	/// Передача по ссылке в поток
	thread t(task, ref(result));
	t.join();
	return 0;
}
