/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectortest.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 10:53:02 by qperrot-          #+#    #+#             */
/*   Updated: 2020/10/26 15:07:51 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.hpp"
#include "vector.hpp"

void test_basic()
{
	std::cout << "\033[1;33m" << "TEST INT" << "\033[0m" << std::endl;
	std::cout << "# vector()" << std::endl;
	COMP(std::vector<int>(), ft::vector<int>())

	std::cout << "# vector(5)" << std::endl;
	COMP(std::vector<int>(5), ft::vector<int>(5))

	std::cout << "# vector(5, 100)" << std::endl;
	COMP(std::vector<int>(5, 100), ft::vector<int>(5, 100))

	std::cout << "# vector(iter1, iter2)" << std::endl;
	std::vector<int> v(3, 100);
	COMP(std::vector<int>(v.begin(), v.end()), ft::vector<int>(v.begin(), v.end()))

	std::cout << "# vector(arr, arr + n)" << std::endl;
	int a[] = {1, 2, 3, 4, 5};
	COMP(std::vector<int>(a, a + 5), ft::vector<int>(a, a + 5))

	std::cout << "# vector(vector2)" << std::endl;
	ft::vector<int> v1(3, 123);
	ft::vector<int> v2(v1);
	COMP(v1, v2)

	std::cout << "# ft::vector1 = ft::vector2" << std::endl;
	ft::vector<int> v3 = v1;
	COMP(v1, v3)

	std::cout << "\033[1;33m" << "TEST CHAR" << "\033[0m" << std::endl;
	
	std::cout << "# vector()" << std::endl;
	COMP(std::vector<char>(), ft::vector<char>())

	std::cout << "# vector(10)" << std::endl;
	COMP(std::vector<char>(10), ft::vector<char>(10))

	std::cout << "# vector(5, a)" << std::endl;
	COMP(std::vector<char>(5, 'a'), ft::vector<char>(5, 'a'))

	std::cout << "# vector(iter1, iter2)" << std::endl;
	std::vector<char> vc(3, 'f');
	COMP(std::vector<char>(vc.begin(), vc.end()), ft::vector<char>(vc.begin(), vc.end()))

	std::cout << "# vector(arr, arr + n)" << std::endl;
	char ac[] = {'s', 't', 'u', 'v', 'w'};
	COMP(std::vector<char>(ac, ac + 5), ft::vector<char>(ac, ac + 5))

	std::cout << "# vector(vector2)" << std::endl;
	ft::vector<char> v4(3, 'm');
	ft::vector<char> v5(v4);
	COMP(v4, v5)

	std::cout << "# ft::vector1 = ft::vector2" << std::endl;
	ft::vector<char> v6 = v4;
	COMP(v4, v6)
}

void test_iterator()
{
	std::cout << "\033[1;33m" << "TEST INT" << "\033[0m" << std::endl;
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 45, 32, 98, 43};
	std::vector<int> real(a, a + 14);
	ft::vector<int> me(a, a + 14);

	std::cout << "# iterator begin(), end()" << std::endl;
	std::vector<int>::iterator itr = real.begin();
	ft::vector<int>::iterator itm = me.begin();
	for (; itm != me.end(); ++itr, ++itm)
	{
		if (*itr != *itm)
		{
			KO("KO")
		}
	}
	OK("OK")

	std::cout << "# const_iterator begin(), end()" << std::endl;
	std::vector<int>::const_iterator citr = real.begin();
	ft::vector<int>::const_iterator citm = me.begin();
	for (; citm != me.end(); ++citr, ++citm)
	{
		if (*citr != *citm)
		{
			KO("KO")
		}
	}
	OK("OK")

	std::cout << "# rbegin(), rend()" << std::endl;
	std::vector<int>::reverse_iterator ritr1(real.end());
	std::vector<int>::reverse_iterator ritr2(real.rbegin());

	ft::vector<int>::reverse_iterator ritm1(me.end());
	ft::vector<int>::reverse_iterator ritm2(me.rbegin());

	std::vector<int>::reverse_iterator ritr = ritr1;
	ft::vector<int>::reverse_iterator ritm = ritm1;
	for (; ritm != me.rend(); ++ritr, ++ritm)
	{
		if (*ritr != *ritm)
		{
			KO("KO")
		}
	}
	ritr = ritr2;
	ritm = ritm2;
	for (; ritm != me.rend(); ++ritr, ++ritm)
	{
		if (*ritr != *ritm)
		{
			KO("KO")
		}
	}
	OK("OK")

	std::cout << "# const_iterator rbegin(), rend()" << std::endl;
	std::vector<int>::const_reverse_iterator critr = real.rbegin();
	ft::vector<int>::const_reverse_iterator critm = me.rbegin();
	for (; critm != me.rend(); ++critr, ++critm)
	{
		if (*critr != *critm)
		{
			KO("KO")
		}
	}
	OK("OK")

	std::cout << "\033[1;33m" << "TEST CHAR" << "\033[0m" << std::endl;
	
	char as[] = {'B', 'j', 'Q', 'e', '4'};
	std::vector<char> real2(as, as + 5);
	ft::vector<char> me2(as, as + 5);

	std::cout << "# iterator begin(), end()" << std::endl;
	std::vector<char>::iterator itr1 = real2.begin();
	ft::vector<char>::iterator itm1 = me2.begin();
	for (; itm1 != me2.end(); ++itr1, ++itm1)
	{
		if (*itr1 != *itm1)
		{
			KO("KO")
		}
	}
	OK("OK")

	std::cout << "# const_iterator begin(), end()" << std::endl;
	std::vector<char>::const_iterator citr1 = real2.begin();
	ft::vector<char>::const_iterator citm1 = me2.begin();
	for (; citm1 != me2.end(); ++citr1, ++citm1)
	{
		if (*citr1 != *citm1)
		{
			KO("KO")
		}
	}
	OK("OK")

	std::cout << "# rbegin(), rend()" << std::endl;
	std::vector<char>::reverse_iterator ritr3(real2.end());
	std::vector<char>::reverse_iterator ritr4(real2.rbegin());

	ft::vector<char>::reverse_iterator ritm3(me2.end());
	ft::vector<char>::reverse_iterator ritm4(me2.rbegin());

	std::vector<char>::reverse_iterator ritrr = ritr3;
	ft::vector<char>::reverse_iterator ritmm = ritm3;
	for (; ritmm != me2.rend(); ++ritrr, ++ritmm)
	{
		if (*ritrr != *ritmm)
		{
			KO("KO")
		}
	}
	ritrr = ritr4;
	ritmm = ritm4;
	for (; ritmm != me2.rend(); ++ritrr, ++ritmm)
	{
		if (*ritrr != *ritmm)
		{
			KO("KO")
		}
	}
	OK("OK")

	std::cout << "# const_iterator rbegin(), rend()" << std::endl;
	std::vector<char>::const_reverse_iterator critr1 = real2.rbegin();
	ft::vector<char>::const_reverse_iterator critm1 = me2.rbegin();
	for (; critm1 != me2.rend(); ++critr1, ++critm1)
	{
		if (*critr1 != *critm1)
		{
			KO("KO")
		}
	}
	OK("OK")
}

void test_capacity()
{
	int a[] = {1, 2, 3, 4, 5};
	std::vector<int> real(a, a + 5);
	ft::vector<int> me(a, a + 5);
	std::cout << "# size()" << std::endl;
	std::cout << "real = " << real.size() << std::endl;
	std::cout << "me = " << me.size() << std::endl;

	std::cout << "# max_size()" << std::endl;
	std::cout << "# max_size()" << std::endl;
	std::cout << "\033[1;33m" << "TEST INT" << "\033[0m" << std::endl;
	std::cout << "real = " << real.max_size() << std::endl;
	std::cout << "me = " << me.max_size() << std::endl;

	std::cout << "\033[1;33m" << "TEST CHAR" << "\033[0m" << std::endl;
	char ac[] = {'1', '2', '3', '4', '5'};
	std::vector<char> real1(ac, ac + 5);
	ft::vector<char> me1(ac, ac + 5);
	std::cout << "real = " << real1.max_size() << std::endl;
	std::cout << "me = " << me1.max_size() / 2 << std::endl;
	std::cout << "\033[1;33m" << "TEST LONG" << "\033[0m" << std::endl;
	long al[] = {186757565646, 25654563334553, 34535242324243, 47867875646534243, 578667543354534345};

	std::vector<long> real2(al, al + 5);
	ft::vector<long> me2(al, al + 5);
	std::cout << "real = " << real2.max_size() << std::endl;
	std::cout << "me = " << me2.max_size() << std::endl;

	std::cout << "# resize(10)" << std::endl;
	real.resize(10);
	me.resize(10);
	std::cout << "real cap vs me cap : " << real.capacity() << " " << me.capacity() << std::endl;
	COMP(real, me)

	std::cout << "# resize(2)" << std::endl;
	real.resize(2);
	me.resize(2);
	std::cout << "real cap vs me cap : " << real.capacity() << " " << me.capacity() << std::endl;
	COMP(real, me)

	std::cout << "# 2->10 resize(10, 123)" << std::endl;
	real.resize(10, 123);
	me.resize(10, 123);
	std::cout << "real cap vs me cap " << real.capacity() << " " << me.capacity() << std::endl;
	COMP(real, me)

	std::cout << "# 10->0 resize(0) and empty()" << std::endl;
	real.resize(0);
	me.resize(0);
	std::cout << "real cap vs me cap : " << real.capacity() << " " << me.capacity() << std::endl;
	COMP(real, me)

	std::cout << "# reserve(100)" << std::endl;
	real.reserve(10);
	me.reserve(10);
	std::cout << "real cap vs me cap : " << real.capacity() << " " << me.capacity() << std::endl;
	COMP(real, me)

	std::cout << "# reserve(20)" << std::endl;
	real.reserve(20);
	me.reserve(20);
	std::cout << "real cap vs me cap : " << real.capacity() << " " << me.capacity() << std::endl;

	std::cout << "# reserve(1)" << std::endl;
	real.reserve(1);
	me.reserve(1);
	std::cout << "real cap vs me cap : " << real.capacity() << " " << me.capacity() << std::endl;

}

void test_element_access()
{
	int a[] = {1, 2, 3, 4, 5};
	std::vector<int> real(a, a + 5);
	ft::vector<int> me(a, a + 5);

	std::cout << "# operator[]" << std::endl;
	std::cout << "real = " << real[3] << std::endl;
	std::cout << "me = " << me[3] << std::endl;

	std::cout << "# operator[]" << std::endl;
	std::cout << "real = " << real[1] << std::endl;
	std::cout << "me = " << me[1] << std::endl;

	std::cout << "# operator[]" << std::endl;
	std::cout << "real = " << real[0] << std::endl;
	std::cout << "me = " << me[0] << std::endl;

	std::cout << "# at" << std::endl;
	std::cout << "real = " << real.at(2) << std::endl;
	std::cout << "me = " << me.at(2) << std::endl;

	std::cout << "# at (exception test)" << std::endl;
	try
	{
		me.at(20);
		KO("'at' exception not defined")
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	OK("OK")

	std::cout << "\033[1;33m" << "TEST INT" << "\033[0m" << std::endl;

	std::cout << "# front()" << std::endl;
	std::cout << "real = " << real.front() << std::endl;
	std::cout << "me = " << me.front() << std::endl;

	std::cout << "# back()" << std::endl;
	std::cout << "real = " << real.back() << std::endl;
	std::cout << "me = " << me.back() << std::endl;

	std::cout << "\033[1;33m" << "TEST CHAR" << "\033[0m" << std::endl;
	
	char ac[] = {'1', '2', '3', '4', '5'};
	std::vector<char> real1(ac, ac + 5);
	ft::vector<char> me1(ac, ac + 5);
	std::cout << "# front()" << std::endl;
	std::cout << "real = " << real1.front() << std::endl;
	std::cout << "me = " << me1.front() << std::endl;
	std::cout << "# back()" << std::endl;
	std::cout << "real = " << real1.back() << std::endl;
	std::cout << "me = " << me1.back() << std::endl;

	std::cout << "\033[1;33m" << "TEST LONG" << "\033[0m" << std::endl;

	long al[] = {186757565646, 25654563334553, 34535242324243, 47867875646534243, 578667543354534345};
	std::vector<long> real2(al, al + 5);
	ft::vector<long> me2(al, al + 5);
	std::cout << "# front()" << std::endl;
	std::cout << "real = " << real2.front() << std::endl;
	std::cout << "me = " << me2.front() << std::endl;
	std::cout << "# back()" << std::endl;
	std::cout << "real = " << real2.back() << std::endl;
	std::cout << "me = " << me2.back() << std::endl;
}

void test_modifiers()
{
	int a[] = {1, 2, 3, 4, 5};
	std::vector<int> real(a, a + 5);
	ft::vector<int> me(a, a + 5);

	std::cout << "# assign(Iter first, Iter last)" << std::endl;
	real.assign(a, a + 5);
	me.assign(a, a + 5);
	std::cout << "real cap vs me cap : " << real.capacity() << " " << me.capacity() << std::endl;
	COMP(real, me)

	std::cout << "# assign(n, val) 1, 42" << std::endl;
	real.assign(1, 42);
	me.assign(1, 42);
	std::cout << "real cap vs me cap : " << real.capacity() << " " << me.capacity() << std::endl;
	COMP(real, me)

	std::cout << "# push_back(val)" << std::endl;
	for (size_t i = 0; i < 10; i++)
	{
		real.push_back(i);
		me.push_back(i);
	}
	COMP(real, me)

	std::cout << "# pop_back(val)" << std::endl;
	for (size_t i = 0; i < 10; i++)
	{
		real.pop_back();
		me.pop_back();
	}
	COMP(real, me)

	std::cout << "# iterator insert(pos, val)" << std::endl;
	std::cout << "real ";
	std::cout << *real.insert(real.begin() + 1, 11);
	std::cout << *real.insert(real.begin() + 1, 50);
	std::cout << *real.insert(real.begin() + 2, 150) << std::endl;
	std::cout << "me ";
	std::cout << *me.insert(me.begin() + 1, 11);
	std::cout << *me.insert(me.begin() + 1, 50);
	std::cout << *me.insert(me.begin() + 2, 150) << std::endl;
	std::cout << "real cap vs me cap : " << real.capacity() << " " << me.capacity() << std::endl;
	COMP(real, me)

	std::cout << "# void insert(pos, n, val)" << std::endl;
	real.insert(real.begin() + 3, 3, 3);
	me.insert(me.begin() + 3, 3, 3);
	std::cout << "real cap vs me cap : " << real.capacity() << " " << me.capacity() << std::endl;
	COMP(real, me)

	std::cout << "# void insert(pos, first, last)" << std::endl;
	real.insert(real.end(), a, a + 5);
	me.insert(me.end(), a, a + 5);
	std::cout << "real cap vs me cap : " << real.capacity() << " " << me.capacity() << std::endl;
	COMP(real, me)

	std::cout << "# iterator erase(pos)" << std::endl;
	real.erase(real.end() - 1);
	me.erase(me.end() - 1);
	std::cout << "real cap vs me cap : " << real.capacity() << " " << me.capacity() << std::endl;
	COMP(real, me)

	std::cout << "# iterator erase(first, last)" << std::endl;
	real.erase(real.begin(), real.begin() + 1);
	real.erase(real.begin() + 2, real.begin() + 5);
	me.erase(me.begin(), me.begin() + 1);
	me.erase(me.begin() + 2, me.begin() + 5);
	std::cout << "real cap vs me cap : " << real.capacity() << " " << me.capacity() << std::endl;
	COMP(real, me)

	std::cout << "# void swap (vector& x)" << std::endl;
	std::vector<int> vo(5);
	ft::vector<int> vm(5);
	real.swap(vo);
	me.swap(vm);
	COMP(real, me);

	std::cout << "# void clear()" << std::endl;
	real.clear();
	me.clear();
	COMP(real, me);
}

void non_member_fonction()
{
	int a[] = {1, 2, 3, 4, 5};
	int b[] = {1, 2, 3, 4, 5, 6};
	std::vector<int> vo1;
	std::vector<int> vo2;
	ft::vector<int> vm1;
	ft::vector<int> vm2;

	vo1.assign(a, a + 5);
	vo2.assign(b, b + 6);
	vm1.assign(a, a + 5);
	vm2.assign(b, b + 6);
	std::cout << "# relational operator" << std::endl;
		std::cout << "# relational operator" << std::endl;

	if (vo1 == vo2)
		std::cout << "real = true" << std::endl;
	else
	{
		std::cout << "real = false" << std::endl;
	}
	
	if (vm1 == vm2)
		std::cout << "me = true" << std::endl;
	else
	{
		std::cout << "me = false" << std::endl;
	}

	if (vo1 != vo2)
		std::cout << "real = true" << std::endl;
	else
	{
		std::cout << "real = false" << std::endl;
	}

	if (vm1 != vm2)
		std::cout << "me = true" << std::endl;
	else
	{
		std::cout << "me = false" << std::endl;
	}

	if (vo1 < vo2)
		std::cout << "real = true" << std::endl;
	else
	{
		std::cout << "real = false" << std::endl;
	}
	if (vm1 < vm2)
		std::cout << "me = true" << std::endl;
	else
	{
		std::cout << "me = false" << std::endl;
	}

	if (vo1 <= vo2)
		std::cout << "real = true" << std::endl;
	else
	{
		std::cout << "real = false" << std::endl;
	}
	if (vm1 <= vm2)
		std::cout << "me = true" << std::endl;
	else
	{
		std::cout << "me = false" << std::endl;
	}

	if (vo1 > vo2)
		std::cout << "real = true" << std::endl;
	else
	{
		std::cout << "real = false" << std::endl;
	}
	if (vm1 > vm2)
		std::cout << "me = true" << std::endl;
	else
	{
		std::cout << "me = false" << std::endl;
	}

	if (vo1 >= vo2)
		std::cout << "real = true" << std::endl;
	else
	{
		std::cout << "real = false" << std::endl;
	}
	if (vm1 >= vm2)
		std::cout << "me = true" << std::endl;
	else
	{
		std::cout << "me = false" << std::endl;
	}

	std::cout << "# void swap (vector& x, vector& y)" << std::endl;
	vo2.clear();
	vm2.clear();
	std::swap(vo1, vo2);
	ft::swap(vm1, vm2);
	COMP(vo1, vm1)
	COMP(vo2, vm2)
}

int main(void)
{
	std::cout << "\033[1;4;34m" << "-----------------test basic function---------------------" << "\033[0m" << std::endl;
	test_basic();
	std::cout << "\033[1;4;34m" << "-----------------test iterator function------------------" << "\033[0m" << std::endl;
	test_iterator();
	std::cout << "\033[1;4;34m" << "-----------------test capacity function------------------" << "\033[0m" << std::endl;
	test_capacity();
	std::cout << "\033[1;4;34m" << "-----------------test element access---------------------" << "\033[0m" << std::endl;
	test_element_access();
	std::cout << "\033[1;4;34m" << "-----------------test modifiers--------------------------" << "\033[0m" << std::endl;
	test_modifiers();
	std::cout << "\033[1;4;34m" << "-----------------non member fonction function overloads----------" << "\033[0m" << std::endl;
	non_member_fonction();
	return (0);
}