/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listtest.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 09:29:25 by qperrot-          #+#    #+#             */
/*   Updated: 2020/10/26 10:51:46 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.hpp"
#include "list.hpp"

bool single_digit(const int &value) { return (value < 10 && value > -10); }

bool is_near(int a, int b)
{
	if (a - b < 5)
		return true;
	return false;
}

bool mycomparison(int first, int second)
{
	return (first > second);
}

void test_basic()
{
	std::cout << "\033[1;33m" << "TEST INT" << "\033[0m" << std::endl;
	std::cout << "# list()" << std::endl;
	COMP(std::list<int>(), ft::list<int>())

	std::cout << "# list(5)" << std::endl;
	COMP(std::list<int>(5), ft::list<int>(5))

	std::cout << "# list(5, 100)" << std::endl;
	COMP(std::list<int>(5, 100), ft::list<int>(5, 100))

	std::cout << "# list(iter1, iter2)" << std::endl;
	std::list<int> v(3, 100);
	COMP(std::list<int>(v.begin(), v.end()), ft::list<int>(v.begin(), v.end()))

	std::cout << "# list(arr, arr + n)" << std::endl;
	int a[] = {1, 2, 3, 4, 5};
	COMP(std::list<int>(a, a + 5), ft::list<int>(a, a + 5))

	std::cout << "# list(list2)" << std::endl;
	ft::list<int> v1(3, 123);
	ft::list<int> v2(v1);
	COMP(v1, v2)

	std::cout << "# ft::list1 = ft::list2" << std::endl;
	ft::list<int> v3 = v1;
	COMP(v1, v3)

	std::cout << "\033[1;33m" << "TEST CHAR" << "\033[0m" << std::endl;
	
	std::cout << "# list()" << std::endl;
	COMP(std::list<char>(), ft::list<char>())

	std::cout << "# list(10)" << std::endl;
	COMP(std::list<char>(10), ft::list<char>(10))

	std::cout << "# list(5, a)" << std::endl;
	COMP(std::list<char>(5, 'a'), ft::list<char>(5, 'a'))

	std::cout << "# list(iter1, iter2)" << std::endl;
	std::list<char> vc(3, 'f');
	COMP(std::list<char>(vc.begin(), vc.end()), ft::list<char>(vc.begin(), vc.end()))

	std::cout << "# list(arr, arr + n)" << std::endl;
	char ac[] = {'s', 't', 'u', 'v', 'w'};
	COMP(std::list<char>(ac, ac + 5), ft::list<char>(ac, ac + 5))

	std::cout << "# list(list2)" << std::endl;
	ft::list<char> v4(3, 'm');
	ft::list<char> v5(v4);
	COMP(v4, v5)

	std::cout << "# ft::list1 = ft::list2" << std::endl;
	ft::list<char> v6 = v4;
	COMP(v4, v6)

	std::cout << "\033[1;33m" << "TEST STRING" << "\033[0m" << std::endl;
	std::cout << "# list()" << std::endl;
	COMP(std::list<std::string>(), ft::list<std::string>())

	std::cout << "# list(10)" << std::endl;
	COMP(std::list<std::string>(10), ft::list<std::string>(10))

	std::cout << "# list(5, a)" << std::endl;
	COMP(std::list<std::string>(5, "hello"), ft::list<std::string>(5, "hello"))

	std::cout << "# list(iter1, iter2)" << std::endl;
	std::list<std::string> vs(3, "je suis la");
	COMP(std::list<std::string>(vs.begin(), vs.end()), ft::list<std::string>(vs.begin(), vs.end()))

	std::cout << "# list(arr, arr + n)" << std::endl;
	std::string as[] = {"Bonjour", "je suis", "Quentin", "etudiant à", "42"};
	COMP(std::list<std::string>(as, as + 5), ft::list<std::string>(as, as + 5))

	std::cout << "# list(list2)" << std::endl;
	ft::list<std::string> v7(3, "Fin");
	ft::list<std::string> v8(v7);
	COMP(v7, v8)

	std::cout << "# ft::list1 = ft::list2" << std::endl;
	ft::list<std::string> v9 = v7;
	COMP(v7, v9)

}

void test_iterator()
{
	std::cout << "\033[1;33m" << "TEST INT" << "\033[0m" << std::endl;
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 45, 32, 98, 43};
	std::list<int> real(a, a + 14);
	ft::list<int> me(a, a + 14);

	std::cout << "# iterator begin(), end()" << std::endl;
	std::list<int>::iterator itr = real.begin();
	ft::list<int>::iterator itm = me.begin();
	for (; itm != me.end(); ++itr, ++itm)
	{
		if (*itr != *itm)
		{
			KO("KO")
		}
	}
	OK("OK")

	std::cout << "# const_iterator begin(), end()" << std::endl;
	std::list<int>::const_iterator citr = real.begin();
	ft::list<int>::const_iterator citm = me.begin();
	for (; citm != me.end(); ++citr, ++citm)
	{
		if (*citr != *citm)
		{
			KO("KO")
		}
	}
	OK("OK")

	std::cout << "# rbegin(), rend()" << std::endl;
	std::list<int>::reverse_iterator ritr1(real.end());
	std::list<int>::reverse_iterator ritr2(real.rbegin());

	ft::list<int>::reverse_iterator ritm1(me.end());
	ft::list<int>::reverse_iterator ritm2(me.rbegin());

	std::list<int>::reverse_iterator ritr = ritr1;
	ft::list<int>::reverse_iterator ritm = ritm1;
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
	std::list<int>::const_reverse_iterator critr = real.rbegin();
	ft::list<int>::const_reverse_iterator critm = me.rbegin();
	for (; critm != me.rend(); ++critr, ++critm)
	{
		if (*critr != *critm)
		{
			KO("KO")
		}
	}
	OK("OK")

	std::cout << "\033[1;33m" << "TEST STRING" << "\033[0m" << std::endl;
	
	std::string as[] = {"Bonjour", "je suis", "Quentin", "etudiant à", "42"};
	std::list<std::string> real2(as, as + 5);
	ft::list<std::string> me2(as, as + 5);

	std::cout << "# iterator begin(), end()" << std::endl;
	std::list<std::string>::iterator itr1 = real2.begin();
	ft::list<std::string>::iterator itm1 = me2.begin();
	for (; itm1 != me2.end(); ++itr1, ++itm1)
	{
		if (*itr1 != *itm1)
		{
			KO("KO")
		}
	}
	OK("OK")

	std::cout << "# const_iterator begin(), end()" << std::endl;
	std::list<std::string>::const_iterator citr1 = real2.begin();
	ft::list<std::string>::const_iterator citm1 = me2.begin();
	for (; citm1 != me2.end(); ++citr1, ++citm1)
	{
		if (*citr1 != *citm1)
		{
			KO("KO")
		}
	}
	OK("OK")

	std::cout << "# rbegin(), rend()" << std::endl;
	std::list<std::string>::reverse_iterator ritr3(real2.end());
	std::list<std::string>::reverse_iterator ritr4(real2.rbegin());

	ft::list<std::string>::reverse_iterator ritm3(me2.end());
	ft::list<std::string>::reverse_iterator ritm4(me2.rbegin());

	std::list<std::string>::reverse_iterator ritrr = ritr3;
	ft::list<std::string>::reverse_iterator ritmm = ritm3;
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
	std::list<std::string>::const_reverse_iterator critr1 = real2.rbegin();
	ft::list<std::string>::const_reverse_iterator critm1 = me2.rbegin();
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

	std::list<int> real(a, a + 5);
	ft::list<int> me(a, a + 5);

	std::cout << "# empty()" << std::endl;
	std::cout << "real = " << real.empty() << std::endl;
	std::cout << "me = " << me.empty() << std::endl;

	std::cout << "# size()" << std::endl;
	std::cout << "real = " << real.size() << std::endl;
	std::cout << "me = " << me.size() << std::endl;

	std::cout << "# max_size()" << std::endl;
	std::cout << "\033[1;33m" << "TEST INT" << "\033[0m" << std::endl;
	std::cout << "real = " << real.max_size() << std::endl;
	std::cout << "me = " << me.max_size() << std::endl;

	std::cout << "\033[1;33m" << "TEST CHAR" << "\033[0m" << std::endl;
	char ac[] = {'1', '2', '3', '4', '5'};
	std::list<char> real1(ac, ac + 5);
	ft::list<char> me1(ac, ac + 5);
	std::cout << "real = " << real1.max_size() << std::endl;
	std::cout << "me = " << me1.max_size() << std::endl;
	std::cout << "\033[1;33m" << "TEST LONG" << "\033[0m" << std::endl;
	long al[] = {186757565646, 25654563334553, 34535242324243, 47867875646534243, 578667543354534345};

	std::list<long> real2(al, al + 5);
	ft::list<long> me2(al, al + 5);
	std::cout << "real = " << real2.max_size() << std::endl;
	std::cout << "me = " << me2.max_size() << std::endl;
}

void test_element_access()
{
	std::cout << "\033[1;33m" << "TEST INT" << "\033[0m" << std::endl;
	int a[] = {1, 2, 3, 4, 5};
	std::list<int> real(a, a + 5);
	ft::list<int> me(a, a + 5);

	std::cout << "# front()" << std::endl;
	std::cout << "real = " << real.front() << std::endl;
	std::cout << "me = " << me.front() << std::endl;

	std::cout << "# back()" << std::endl;
	std::cout << "real = " << real.back() << std::endl;
	std::cout << "me = " << me.back() << std::endl;

	std::cout << "\033[1;33m" << "TEST CHAR" << "\033[0m" << std::endl;
	
	char ac[] = {'1', '2', '3', '4', '5'};
	std::list<char> real1(ac, ac + 5);
	ft::list<char> me1(ac, ac + 5);
	std::cout << "# front()" << std::endl;
	std::cout << "real = " << real1.front() << std::endl;
	std::cout << "me = " << me1.front() << std::endl;
	std::cout << "# back()" << std::endl;
	std::cout << "real = " << real1.back() << std::endl;
	std::cout << "me = " << me1.back() << std::endl;

	std::cout << "\033[1;33m" << "TEST LONG" << "\033[0m" << std::endl;

	long al[] = {186757565646, 25654563334553, 34535242324243, 47867875646534243, 578667543354534345};
	std::list<long> real2(al, al + 5);
	ft::list<long> me2(al, al + 5);
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
	std::list<int> real(a, a + 5);
	ft::list<int> me(a, a + 5);
	std::list<int>::iterator itr;
	ft::list<int>::iterator itm;

	std::cout << "# assign(Iter first, Iter last)" << std::endl;
	real.assign(a, a + 5);
	me.assign(a, a + 5);
	COMP(real, me)

	std::cout << "# assign(n, val) 1, 42" << std::endl;
	real.assign(1, 42);
	me.assign(1, 42);
	COMP(real, me)

	std::cout << "# push_front(val)" << std::endl;
	for (size_t i = 0; i < 5; i++)
	{
		real.push_front(i);
		me.push_front(i);
	}
	COMP(real, me)
	
	std::cout << "# push_back(val)" << std::endl;
	for (size_t i = 5; i < 10; i++)
	{
		real.push_back(i);
		me.push_back(i);
	}
	COMP(real, me)

	std::cout << "# pop_front(val)" << std::endl;
	for (size_t i = 0; i < 3; i++)
	{
		real.pop_front();
		me.pop_front();
	}
	COMP(real, me)
	
	std::cout << "# pop_back(val)" << std::endl;
	for (size_t i = 0; i < 5; i++)
	{
		real.pop_back();
		me.pop_back();
	}
	COMP(real, me)

	std::cout << "# iterator insert(pos, val)" << std::endl;
	itr = real.begin();
	itm = me.begin();
	std::advance(itr, 1);
	std::advance(itm, 1);
	std::cout << "real ";
	std::cout << *real.insert(itr, 11);
	std::cout << *real.insert(itr, 50);
	std::cout << *real.insert(++itr, 150) << std::endl;
	std::cout << "me ";
	std::cout << *me.insert(itm, 11);
	std::cout << *me.insert(itm, 50);
	std::cout << *me.insert(++itm, 150) << std::endl;
	COMP(real, me)

	std::cout << "# void insert(pos, n, val)" << std::endl;
	real.insert(itr, 3, 3);
	me.insert(itm, 3, 3);
	COMP(real, me)

	std::cout << "# void insert(pos, first, last)" << std::endl;
	real.insert(real.end(), a, a + 5);
	me.insert(me.end(), a, a + 5);
	COMP(real, me)

	std::cout << "# iterator erase(pos)" << std::endl;
	real.erase(--real.end());
	me.erase(--me.end());
	COMP(real, me)

	std::cout << "# iterator erase(first, last)" << std::endl;
	itr = real.begin();
	itm = me.begin();
	std::advance(itr, 2);
	std::advance(itm, 2);
	real.erase(real.begin(), itr);
	me.erase(me.begin(), itm);
	COMP(real, me)

	std::cout << "# void swap (list& x)" << std::endl;
	std::list<int> real2(5);
	ft::list<int> me2(5);
	real.swap(real2);
	me.swap(me2);
	COMP(real, me);
	COMP(real2, me2);
	real.swap(real2);
	me.swap(me2);

	std::cout << "# void resize (n, val)" << std::endl;
	real.resize(3);
	me.resize(3);
	COMP(real, me);
	real.resize(10, 10);
	me.resize(10, 10);
	COMP(real, me);

	std::cout << "# void clear()" << std::endl;
	real.clear();
	me.clear();
	COMP(real, me);
}

void test_operations()
{
	int a[] = {1, 2, 3, 4, 5};
	int b[] = {10, 20, 60, 20, 30, -40, -40, 50, -40, 10, 20, 33, 90};
	int c[] = { 990, 999};
	std::list<int> real(a, a + 5);
	ft::list<int> me(a, a + 5);
	std::list<int> real2;
	ft::list<int> me2;
	std::list<int>::iterator itr;
	ft::list<int>::iterator itm;

	std::cout << "# splice (iter pos, list& x)" << std::endl;
	itr = real.begin();
	itm = me.begin();
	real2.assign(b, b + 13);
	me2.assign(b, b + 13);
	real.splice(++itr, real2);
	me.splice(++itm, me2);
	COMP(real, me)
	COMP(real2, me2)

	std::cout << "# splice (iter pos, list& x, iter i)" << std::endl;
	real2.assign(c, c + 2);
	me2.assign(c, c + 2);
	real.splice(++itr, real2, real2.begin());
	me.splice(++itm, me2, me2.begin());
	COMP(real, me)
	COMP(real2, me2)

	std::cout << "# splice (iter pos, list& x, iter first, iter last)" << std::endl;
	real2.assign(a, a + 5);
	me2.assign(a, a + 5);
	real.splice(++itr, real2, real2.begin(), --real2.end());
	me.splice(++itm, me2, me2.begin(), --me2.end());
	COMP(real, me)
	COMP(real2, me2)

	std::cout << "# void remove (val)" << std::endl;
	real.remove(20);
	me.remove(20);
	real.remove(-1);
	me.remove(-1);
	COMP(real, me)

	std::cout << "# void remove_if(Predicate pred)" << std::endl;
	real.remove_if(single_digit);
	me.remove_if(single_digit);
	COMP(real, me)

	std::cout << "# void unique()" << std::endl;
	real.unique();
	me.unique();
	COMP(real, me)

	std::cout << "# void unique()" << std::endl;
	real.unique(is_near);
	me.unique(is_near);
	COMP(real, me)

	std::cout << "# void merge (list& x)" << std::endl;
	real2.assign(b, b + 13);
	me2.assign(b, b + 13);
	real.merge(real2);
	me.merge(me2);
	COMP(real, me)
	COMP(real2, me2)

	std::cout << "# void merge (list& x, Compare comp);" << std::endl;
	real2.assign(b, b + 13);
	me2.assign(b, b + 13);
	real.merge(real2, mycomparison);
	me.merge(me2, mycomparison);
	COMP(real, me)
	COMP(real2, me2)

	std::cout << "# void sort()" << std::endl;
	real.sort();
	me.sort();
	COMP(real, me)

	std::cout << "# void sort(Compare comp)" << std::endl;
	real.sort(mycomparison);
	me.sort(mycomparison);
	COMP(real, me)

	std::cout << "# void reverse()" << std::endl;
	real.reverse();
	me.reverse();
	COMP(real, me)
}

void non_member_fonction()
{
	int a[] = {1, 2, 3, 4, 5};
	int b[] = {1, 2, 3, 4, 5, 6};
	std::list<int> vo1;
	std::list<int> vo2;
	ft::list<int> vm1;
	ft::list<int> vm2;

	vo1.assign(a, a + 5);
	vo2.assign(b, b + 6);
	vm1.assign(a, a + 5);
	vm2.assign(b, b + 6);
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

	std::cout << "# void swap (list& x, list& y)" << std::endl;
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
	std::cout << "\033[1;4;34m" << "-----------------test operations------------------------" << "\033[0m" << std::endl;
	test_operations();
	std::cout << "\033[1;4;34m" << "-----------------non member fonction function overloads----------" << "\033[0m" << std::endl;
	non_member_fonction();
	return (0);
}