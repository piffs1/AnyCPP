// Example program
#include "stdafx.h"
#include <iostream>
#include <memory>
/*
	operator bool() ???
*/

namespace STL_BOOK {
	template<typename T>
	class unique_ptr
	{
		T* m_ptr = nullptr;
	public:
		constexpr unique_ptr() noexcept = default;
		constexpr unique_ptr(T* ptr) : m_ptr(ptr) {}
		T* get() noexcept { return m_ptr; }
		operator bool() const noexcept { return bool(get()); }
		T& operator*() const noexcept { return *get(); }
		T* operator->() const noexcept { return get(); }
		void Reset(T* ptr = nullptr) noexcept {
			T* old_ptr = std::exchange(m_ptr, ptr);
			delete old_ptr;
		}
		
		T* Release() noexcept {
			return std::exchange(m_ptr, nullptr);
		}
		
		unique_ptr(unique_ptr&& rhs) noexcept {
			this->Reset(rhs.Release());
		}

		unique_ptr& operator=(unique_ptr&& rhs) noexcept {
			Reset(rhs.Release());
			return *this;
		}

		~unique_ptr() {
			Reset();
		}
	};

	template<typename T, typename... Args>
	unique_ptr<T> make_unique(Args&&... args)
	{
		return unique_ptr<T>(new T(std::forward<Agrs>(agrs)...));
	}

}

using namespace std;



int main()
{
	
	unique_ptr<int> pBadRealisation(new int(5));
	int nTest = *pBadRealisation;
	int* pnTest = pBadRealisation.get(); /// ok
	
	pBadRealisation.reset(new int(6));
	nTest = *pBadRealisation;

	unique_ptr<int> pGoodRealisation = make_unique<int>(5);
	nTest = *pGoodRealisation;
	pGoodRealisation.reset(new int(6));
	nTest = *pGoodRealisation;


	return 0;
}
