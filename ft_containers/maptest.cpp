/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maptest.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 15:09:36 by qperrot-          #+#    #+#             */
/*   Updated: 2020/10/26 15:56:01 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.hpp"
#include "map.hpp"

void test_basic()
{
	std::pair<int, char> pr[] = {
		std::make_pair(1, 'a'),
		std::make_pair(2, 'b'),
		std::make_pair(3, 'c'),
		std::make_pair(4, 'd'),
		std::make_pair(5, 'e')};
	ft::pair<int, char> pm[] = {
		ft::make_pair(1, 'a'),
		ft::make_pair(2, 'b'),
		ft::make_pair(3, 'c'),
		ft::make_pair(4, 'd'),
		ft::make_pair(5, 'e')};

	std::cout << "# map()" << std::endl;
	COMP_MAP((std::map<int, char>()), (ft::map<int, char>()))

	std::map<int, char> real(pr, pr + 5);
	ft::map<int, char> me(pm, pm + 5);
	std::cout << "# map(Iter first, Iter last)" << std::endl;
	COMP_MAP(real, me)

	std::cout << "# map(map other)" << std::endl;
	COMP_MAP((std::map<int, char>(real)), (ft::map<int, char>(me)))

	std::cout << "# map1 = map2" << std::endl;
	std::map<int, char> real2 = real;
	ft::map<int, char> me2 = me;
	COMP_MAP(real2, me2)

	std::pair<char, long> pr2[] = {
		std::make_pair('a', 22234423),
		std::make_pair('b', 88665),
		std::make_pair('c', 23435343),
		std::make_pair('d', 988776),
		std::make_pair('e', 4354376)};
	ft::pair<char, long> pm2[] = {
		ft::make_pair('a', 22234423),
		ft::make_pair('b', 88665),
		ft::make_pair('c', 23435343),
		ft::make_pair('d', 988776),
		ft::make_pair('e', 4354376)};

	std::cout << "# map()" << std::endl;
	COMP_MAP((std::map<char, long>()), (ft::map<char, long>()))

	std::map<char, long> real3(pr2, pr2 + 5);
	ft::map<char, long> me3(pm2, pm2 + 5);
	std::cout << "# map(Iter first, Iter last)" << std::endl;
	COMP_MAP(real3, me3)

	std::cout << "# map(map other)" << std::endl;
	COMP_MAP((std::map<char, long>(real3)), (ft::map<char, long>(me3)))

	std::cout << "# map1 = map2" << std::endl;
	std::map<char, long> real4 = real3;
	ft::map<char, long> me4 = me3;
	COMP_MAP(real4, me4)
}

void test_iterator()
{
	std::pair<int, char> pr[] = {
		std::make_pair(3, 'c'),
		std::make_pair(1, 'a'),
		std::make_pair(4, 'd'),
		std::make_pair(2, 'b'),
		std::make_pair(5, 'e')};
	ft::pair<int, char> pm[] = {
		ft::make_pair(3, 'c'),
		ft::make_pair(1, 'a'),
		ft::make_pair(4, 'd'),
		ft::make_pair(2, 'b'),
		ft::make_pair(5, 'e')};

	std::map<int, char> real(pr, pr + 5);
	ft::map<int, char> me(pm, pm + 5);
	size_t n;
	
	std::cout << "# iterator begin(), end()" << std::endl;
	std::map<int, char>::iterator itr = real.begin();
	ft::map<int, char>::iterator itm = me.begin();
	for (n = 0; itr != real.end() && itm != me.end() ; ++itr, ++itm, ++n)
	{
		if (itr->first != itm->first)
		{
			KO("KO : different index")
		}
		if (itr->second != itm->second)
		{
			KO("KO : different second elem")
		}
	}
	if (n != real.size() || n != me.size()) {
		KO("KO : different size")
	}
	OK("OK")
	
	std::cout << "# const_iterator begin(), end()" << std::endl;
	std::map<int, char>::const_iterator citr = real.begin();
	ft::map<int, char>::const_iterator citm = me.begin();
	for (n = 0; citr != real.end() && citm != me.end(); ++citr, ++citm, ++n)
	{
		if (citr->first != citm->first)
		{
			KO("KO : different index")
		}
		if (citr->second != citm->second)
		{
			KO("KO : different second elem")
		}
	}
	if (n != real.size() || n != me.size())
	{
		KO("KO : different size")
	}
	OK("OK")

	std::cout << "# rbegin(), rend()" << std::endl;
	std::map<int, char>::reverse_iterator ritr = real.rbegin();
	ft::map<int, char>::reverse_iterator ritm = me.rbegin();
	for (n = 0; ritr != real.rend() && ritm != me.rend(); ++ritr, ++ritm, ++n)
	{
		if (ritr->first != ritm->first)
		{
			KO("KO : different index")
		}
		if (ritr->second != ritm->second)
		{
			KO("KO : different second elem")
		}
	}
	if (n != real.size() || n != me.size())
	{
		KO("KO : different size")
	}
	OK("OK")

	std::cout << "# const_iterator rbegin(), rend()" << std::endl;
	std::map<int, char>::const_reverse_iterator critr = real.rbegin();
	ft::map<int, char>::const_reverse_iterator critm = me.rbegin();
	for (n = 0; critr != real.rend() && critm != me.rend(); ++critr, ++critm, ++n)
	{
		if (critr->first != critm->first)
		{
			KO("KO : different index")
		}
		if (critr->second != critm->second)
		{
			KO("KO : different second elem")
		}
	}
	if (n != real.size() || n != me.size())
	{
		KO("KO : different size")
	}
	OK("OK")
}

void test_capacity()
{
	std::pair<int, char> pr[] = {
		std::make_pair(3, 'c'),
		std::make_pair(1, 'a'),
		std::make_pair(4, 'd'),
		std::make_pair(2, 'b'),
		std::make_pair(5, 'e')};
	ft::pair<int, char> pm[] = {
		ft::make_pair(3, 'c'),
		ft::make_pair(1, 'a'),
		ft::make_pair(4, 'd'),
		ft::make_pair(2, 'b'),
		ft::make_pair(5, 'e')};

	std::map<int, char> real(pr, pr + 5);
	ft::map<int, char> me(pm, pm + 5);
	std::map<int, char> real2;
	ft::map<int, char> me2;

	std::cout << "# empty()" << std::endl;
	std::cout << "real = " << real.empty() << std::endl;
	std::cout << "me = " << me.empty() << std::endl;
	std::cout << "real2 = " << real2.empty() << std::endl;
	std::cout << "me2 = " << me2.empty() << std::endl;

	std::cout << "# size()" << std::endl;
	std::cout << "real = " << real.size() << std::endl;
	std::cout << "me = " << me.size() << std::endl;
	std::cout << "real2 = " << real2.size() << std::endl;
	std::cout << "me2 = " << me2.size() << std::endl;

	std::cout << "# max_size() : can be different" << std::endl;
	std::cout << "> orig: " << real.max_size() << std::endl;
	std::cout << "> mine: " << me.max_size() << std::endl;

	std::cout << "# max_size() : can be different" << std::endl;
	std::map<char, double> real3;
	ft::map<char, double> me3;
	std::cout << "> orig: " << real3.max_size() << std::endl;
	std::cout << "> mine: " << me3.max_size() << std::endl;

	std::cout << "# max_size() : can be different" << std::endl;
	std::map<char, std::string> real4;
	ft::map<char, std::string> me4;
	std::cout << "> orig: " << real4.max_size() << std::endl;
	std::cout << "> mine: " << me4.max_size() << std::endl;
}

void test_element_access()
{
	std::pair<int, char> pr[] = {
		std::make_pair(3, 'c'),
		std::make_pair(1, 'a'),
		std::make_pair(4, 'd'),
		std::make_pair(2, 'b'),
		std::make_pair(5, 'e')};
	ft::pair<int, char> pm[] = {
		ft::make_pair(3, 'c'),
		ft::make_pair(1, 'a'),
		ft::make_pair(4, 'd'),
		ft::make_pair(2, 'b'),
		ft::make_pair(5, 'e')};

	std::map<int, char> real(pr, pr + 5);
	ft::map<int, char> me(pm, pm + 5);
	std::map<int, char> real2;
	ft::map<int, char> me2;

	std::cout << "# operator[new_key]" << std::endl;
	std::cout << "real = " << real[3] << std::endl;
	std::cout << "me = " << me[3] << std::endl;
	COMP_MAP(real, me)

	std::cout << "# operator[new_key]" << std::endl;
	std::cout << "real = " << real[1] << std::endl;
	std::cout << "me = " << me[1] << std::endl;
	COMP_MAP(real, me)

	std::cout << "# operator[new_key]" << std::endl;
	std::cout << "real = " << real[0] << std::endl;
	std::cout << "me = " << me[0] << std::endl;
	COMP_MAP(real, me)

	std::cout << "# operator[key] = val" << std::endl;
	real[6] = 'f';
	me[6] = 'f';
	std::cout << "real = " << real[6] << std::endl;
	std::cout << "me = " << me[6] << std::endl;
	COMP_MAP(real, me)

	real[10] = 'k';
	me[10] = 'k';
	std::cout << "real = " << real[10] << std::endl;
	std::cout << "me = " << me[10] << std::endl;
	COMP_MAP(real, me)
	
	real[6] = 'n';
	me[6] = 'n';
	std::cout << "real = " << real[6] << std::endl;
	std::cout << "me = " << me[6] << std::endl;
	COMP_MAP(real, me)
}

void test_modifiers()
{
	std::pair<int, char> pr[] = {
		std::make_pair(3, 'c'),
		std::make_pair(1, 'a'),
		std::make_pair(4, 'd'),
		std::make_pair(2, 'b'),
		std::make_pair(5, 'e'),
		std::make_pair(80, 'f'),
		std::make_pair(50, 'g'),
		std::make_pair(60, 'h'),
		std::make_pair(44, 'i'),
		std::make_pair(33, 'j')
	};
	ft::pair<int, char> pm[] = {
		ft::make_pair(3, 'c'),
		ft::make_pair(1, 'a'),
		ft::make_pair(4, 'd'),
		ft::make_pair(2, 'b'),
		ft::make_pair(5, 'e'),
		ft::make_pair(80, 'f'),
		ft::make_pair(50, 'g'),
		ft::make_pair(60, 'h'),
		ft::make_pair(44, 'i'),
		ft::make_pair(33, 'j')
	};

	std::map<int, char> real;
	ft::map<int, char> me;
	std::map<char, std::string> real4;
	ft::map<char, std::string> me4;
	std::map<int, char> real2(pr, pr + 1);
	ft::map<int, char> me2(pm, pm + 1);
	std::map<int, char>::iterator itr;
	ft::map<int, char>::iterator itm;
	std::map<char, std::string>::iterator itr4;
	ft::map<char, std::string>::iterator itm4;

	std::cout << "# pair<iterator,bool> insert (val)" << std::endl;
	real.insert(std::make_pair(42, 'z'));
	me.insert(ft::make_pair(42, 'z'));
	real[42] = 'a';
	me[42] = 'a';
	COMP_MAP(real, me)

	std::cout << "# iterator insert (iterator prs, val)" << std::endl;
	itr = real.insert(real.begin(), std::make_pair(42, 'z'));
	itm = me.insert(me.begin(), ft::make_pair(42, 'z'));
	itr = real.insert(itr, std::make_pair(17, 'z'));
	itm = me.insert(itm, ft::make_pair(17, 'z'));
	itr = real.insert(itr, std::make_pair(21, '!'));
	itm = me.insert(itm, ft::make_pair(21, '!'));
	itr = real.insert(itr, std::make_pair(68, '?'));
	itm = me.insert(itm, ft::make_pair(68, '?'));
	itr = real.insert(itr, std::make_pair(-11, 'A'));
	itm = me.insert(itm, ft::make_pair(-11, 'A'));
	itr = real.insert(itr, std::make_pair(13, '['));
	itm = me.insert(itm, ft::make_pair(13, '['));

    itr = real.insert(real.begin(), std::make_pair(0, 'z'));
	itm = me.insert(me.begin(), ft::make_pair(0, 'z'));
	itr = real.insert(itr, std::make_pair(-3121122, 'z'));
	itm = me.insert(itm, ft::make_pair(-3121122, 'z'));
	itr = real.insert(itr, std::make_pair(-21, '!'));
	itm = me.insert(itm, ft::make_pair(-21, '!'));
	itr = real.insert(itr, std::make_pair(-68, '?'));
	itm = me.insert(itm, ft::make_pair(-68, '?'));
	itr = real.insert(itr, std::make_pair(11, 'A'));
	itm = me.insert(itm, ft::make_pair(11, 'A'));
	itr = real.insert(itr, std::make_pair(1345544, '['));
	itm = me.insert(itm, ft::make_pair(1345544, '['));

	itr = real.insert(real.begin(), std::make_pair(9, 'z'));
	itm = me.insert(me.begin(), ft::make_pair(9, 'z'));
	itr = real.insert(itr, std::make_pair(-3121121, 'z'));
	itm = me.insert(itm, ft::make_pair(-3121121, 'z'));
	itr = real.insert(itr, std::make_pair(-212, '!'));
	itm = me.insert(itm, ft::make_pair(-212, '!'));
	itr = real.insert(itr, std::make_pair(-688, '?'));
	itm = me.insert(itm, ft::make_pair(-688, '?'));
	itr = real.insert(itr, std::make_pair(14, 'A'));
	itm = me.insert(itm, ft::make_pair(14, 'A'));
	itr = real.insert(itr, std::make_pair(1345545888, '['));
	itm = me.insert(itm, ft::make_pair(1345545888, '['));
	COMP_MAP(real, me)

	itr4 = real4.insert(real4.begin(), std::make_pair('z', "hello"));
	itm4 = me4.insert(me4.begin(), ft::make_pair('z', "hello"));
	itr4 = real4.insert(itr4, std::make_pair('a', "fff"));
	itm4 = me4.insert(itm4, ft::make_pair('a', "fff"));
	itr4 = real4.insert(itr4, std::make_pair('!', "je suis"));
	itm4 = me4.insert(itm4, ft::make_pair('!', "je suis"));
	itr4 = real4.insert(itr4, std::make_pair('?', "my man"));
	itm4 = me4.insert(itm4, ft::make_pair('?', "my man"));
	itr4 = real4.insert(itr4, std::make_pair('A', "nom de zeus"));
	itm4 = me4.insert(itm4, ft::make_pair('A', "nom de zeus"));
	itr4 = real4.insert(itr4, std::make_pair('[', "la vache est là"));
	itm4 = me4.insert(itm4, ft::make_pair('[', "la vache est là"));

	std::cout << "# void insert (InputIt first, InputIt last)" << std::endl;
	real.insert(pr, pr + 10);
	me.insert(pm, pm + 10);
	COMP_MAP(real, me)

	std::cout << "# void erase (iterator prsition)" << std::endl;
	real.erase(itr);
	me.erase(itm);
	COMP_MAP(real, me)

	std::cout << "# size_type erase (key)" << std::endl;
	real.erase(33);
	me.erase(33);
	real.erase(123456);
	me.erase(123456);
	real.erase(5);
	me.erase(5);
	real.erase(17);
	me.erase(17);
	real.erase(21);
	me.erase(21);
	real.erase(42);
	me.erase(42);
	real.erase(44);
	me.erase(44);

	COMP_MAP(real, me)

	std::cout << "# void erase (iterator first, iterator last)" << std::endl;
	itr = real.begin();
	itm = me.begin();
	std::advance(itr, 5);
	std::advance(itm, 5);
	real.erase(itr, real.end());
	me.erase(itm, me.end());
	COMP_MAP(real, me)

	itr4 = real4.begin();
	itm4 = me4.begin();
	std::advance(itr4, 5);
	std::advance(itm4, 5);
	real4.erase(itr4, real4.end());
	me4.erase(itm4, me4.end());
	COMP_MAP(real4, me4)

	std::cout << "# void swap (map& x)" << std::endl;
	real.swap(real2);
	me.swap(me2);
	COMP_MAP(real, me)
	COMP_MAP(real2, me2)

	std::cout << "# void clear()" << std::endl;
	real.clear();
	me.clear();
	COMP_MAP(real, me)

	real4.clear();
	me4.clear();
	COMP_MAP(real4, me4)
}

void test_observers()
{
	std::pair<int, char> pr[] = {
		std::make_pair(3, 'c'),
		std::make_pair(1, 'a'),
		std::make_pair(4, 'd')
	};
	ft::pair<int, char> pm[] = {
		ft::make_pair(3, 'c'),
		ft::make_pair(1, 'a'),
		ft::make_pair(4, 'd')
	};

	std::map<int, char> real(pr, pr + 3);
	ft::map<int, char> me(pm, pm + 3);
	std::map<int, char>::iterator itr;
	ft::map<int, char>::iterator itm;

	std::cout << "# key_compare key_comp()" << std::endl;
	itr = real.begin();
	itm = me.begin();
	std::advance(itr, 1);
	std::advance(itm, 1);
	std::cout << "real = " << real.key_comp()(real.begin()->first, itr->first) << std::endl;
	std::cout << "me = " << me.key_comp()(me.begin()->first, itm->first) << std::endl;
	COMP_MAP(real, me)
	
	std::advance(itr, 1);
	std::advance(itm, 1);
	std::cout << "real = " << real.key_comp()(real.begin()->first, itr->first) << std::endl;
	std::cout << "me = " << me.key_comp()(me.begin()->first, itm->first) << std::endl;
	COMP_MAP(real, me)
	std::cout << "real = " << real.value_comp()(*itr, *real.begin()) << std::endl;
	std::cout << "me = " << me.value_comp()(*itm, *me.begin()) << std::endl;
	COMP_MAP(real, me)

	std::cout << "# value_compare value_comp()" << std::endl;
	itr = real.begin();
	itm = me.begin();
	std::advance(itr, 1);
	std::advance(itm, 1);
	std::cout << "real = " << real.value_comp()(*real.begin(), *itr) << std::endl;
	std::cout << "me = " << me.value_comp()(*me.begin(), *itm) << std::endl;
	COMP_MAP(real, me)

	std::advance(itr, 1);
	std::advance(itm, 1);
	std::cout << "real = " << real.value_comp()(*real.begin(), *itr) << std::endl;
	std::cout << "me = " << me.value_comp()(*me.begin(), *itm) << std::endl;
	COMP_MAP(real, me)
	std::cout << "real = " << real.value_comp()(*itr, *real.begin()) << std::endl;
	std::cout << "me = " << me.value_comp()(*itm, *me.begin()) << std::endl;
	COMP_MAP(real, me)
}

void test_operations()
{
	std::pair<int, char> pr[] = {
		std::make_pair(3, 'c'),
		std::make_pair(1, 'a'),
		std::make_pair(4, 'd'),
		std::make_pair(2, 'b'),
		std::make_pair(5, 'e'),
		std::make_pair(80, 'f'),
		std::make_pair(50, 'g'),
		std::make_pair(60, 'h'),
		std::make_pair(44, 'i'),
		std::make_pair(33, 'j')};
	ft::pair<int, char> pm[] = {
		ft::make_pair(3, 'c'),
		ft::make_pair(1, 'a'),
		ft::make_pair(4, 'd'),
		ft::make_pair(2, 'b'),
		ft::make_pair(5, 'e'),
		ft::make_pair(80, 'f'),
		ft::make_pair(50, 'g'),
		ft::make_pair(60, 'h'),
		ft::make_pair(44, 'i'),
		ft::make_pair(33, 'j')};

	std::map<int, char> real(pr, pr + 10);
	ft::map<int, char> me(pm, pm + 10);
	std::map<int, char>::iterator itr;
	ft::map<int, char>::iterator itm;
	std::map<int, char>::const_iterator citr;
	ft::map<int, char>::const_iterator citm;

	std::cout << "# iterator find(const key_type &k)" << std::endl;
	itr = real.find(33);
	itm = me.find(33);
	std::cout << "real = " << itr->second << std::endl;
	std::cout << "me = " << itm->second << std::endl;

	std::cout << "# const_iterator find(const key_type &k)" << std::endl;
	citr = real.find(100);
	citm = me.find(100);
	std::cout << "real = " << citr->second << std::endl;
	std::cout << "me = " << citm->second << std::endl;
	if (citr == real.end() && citm == me.end())
		std::cout << "100 not found in both map" << std::endl;

	std::cout << "# size_type count(const key_type &k)" << std::endl;
	std::cout << "real = " << real.count(80) << std::endl;
	std::cout << "me = " << me.count(80) << std::endl;
	std::cout << "real = " << real.count(0) << std::endl;
	std::cout << "me = " << me.count(0) << std::endl;
	std::cout << "real = " << real.count(50) << std::endl;
	std::cout << "me = " << me.count(50) << std::endl;
	std::cout << "real = " << real.count(40) << std::endl;
	std::cout << "me = " << me.count(40) << std::endl;
	std::cout << "real = " << real.count(33) << std::endl;
	std::cout << "me = " << me.count(33) << std::endl;

	std::cout << "# iterator lower_bound (const key_type& k)" << std::endl;
	itr = real.lower_bound(33);
	itm = me.lower_bound(33);
	std::cout << "real = " << itr->first << std::endl;
	std::cout << "me = " << itm->first << std::endl;

	itr = real.lower_bound(80);
	itm = me.lower_bound(80);
	std::cout << "real = " << itr->first << std::endl;
	std::cout << "me = " << itm->first << std::endl;

	itr = real.lower_bound(44);
	itm = me.lower_bound(44);
	std::cout << "real = " << itr->first << std::endl;
	std::cout << "me = " << itm->first << std::endl;

	std::cout << "# const_iterator lower_bound(const key_type &k)" << std::endl;
	citr = real.lower_bound(100);
	citm = me.lower_bound(100);
	std::cout << "real = " << citr->first << std::endl;
	std::cout << "me = " << citm->first << std::endl;
	if (citr == real.end() && citm == me.end())
		std::cout << "100 not found in both map" << std::endl;

	std::cout << "# iterator upper_bound (const key_type& k)" << std::endl;
	itr = real.upper_bound(33);
	itm = me.upper_bound(33);
	std::cout << "real = " << itr->first << std::endl;
	std::cout << "me = " << itm->first << std::endl;

	itr = real.upper_bound(80);
	itm = me.upper_bound(80);
	std::cout << "real = " << itr->first << std::endl;
	std::cout << "me = " << itm->first << std::endl;

	itr = real.upper_bound(44);
	itm = me.upper_bound(44);
	std::cout << "real = " << itr->first << std::endl;
	std::cout << "me = " << itm->first << std::endl;

	std::cout << "# const_iterator upper_bound(const key_type &k)" << std::endl;
	citr = real.upper_bound(100);
	citm = me.upper_bound(100);
	std::cout << "real = " << citr->first << std::endl;
	std::cout << "me = " << citm->first << std::endl;
	if (citr == real.end() && citm == me.end())
		std::cout << "100 not found in both map" << std::endl;

	std::cout << "# pair<iterator, iterator> equal_range (const key_type& k)" << std::endl;
	std::pair<std::map<int, char>::iterator, std::map<int, char>::iterator> retr = real.equal_range(33);
	ft::pair<ft::map<int, char>::iterator, ft::map<int, char>::iterator> retm = me.equal_range(33);
	std::cout << "real = " << retr.first->first << " => " << retr.first->second << std::endl;
	std::cout << "me = " << retm.first->first << " => " << retm.first->second << std::endl;
	std::cout << "real = " << retr.second->first << " => " << retr.second->second << std::endl;
	std::cout << "me = " << retm.second->first << " => " << retm.second->second << std::endl;

	std::cout << "# pair<const_iterator, const_iterator> equal_range (const key_type& k)" << std::endl;
	std::pair<std::map<int, char>::const_iterator, std::map<int, char>::const_iterator> cretr = real.equal_range(33);
	ft::pair<ft::map<int, char>::const_iterator, ft::map<int, char>::const_iterator> cretm = me.equal_range(33);
	std::cout << "real = " << cretr.first->first << " => " << cretr.first->second << std::endl;
	std::cout << "me = " << cretm.first->first << " => " << cretm.first->second << std::endl;
	std::cout << "real = " << cretr.second->first << " => " << cretr.second->second << std::endl;
	std::cout << "me = " << cretm.second->first << " => " << cretm.second->second << std::endl;

}

void non_member_fonction()
{
	std::pair<int, char> pr[] = {
		std::make_pair(3, 'c'),
		std::make_pair(1, 'a'),
		std::make_pair(4, 'd'),
		std::make_pair(2, 'b'),
		std::make_pair(5, 'e'),
		std::make_pair(80, 'f'),
		std::make_pair(50, 'g'),
		std::make_pair(60, 'h'),
		std::make_pair(44, 'i'),
		std::make_pair(33, 'j')};
	ft::pair<int, char> pm[] = {
		ft::make_pair(3, 'c'),
		ft::make_pair(1, 'a'),
		ft::make_pair(4, 'd'),
		ft::make_pair(2, 'b'),
		ft::make_pair(5, 'e'),
		ft::make_pair(80, 'f'),
		ft::make_pair(50, 'g'),
		ft::make_pair(60, 'h'),
		ft::make_pair(44, 'i'),
		ft::make_pair(33, 'j')};

	std::map<int, char> real(pr, pr + 5);
	ft::map<int, char> me(pm, pm + 5);
	std::map<int, char> real2(pr, pr + 6);
	ft::map<int, char> me2(pm, pm + 6);

	std::cout << "# relational operator" << std::endl;

	if (real == real2)
		std::cout << "real = true" << std::endl;
	else
	{
		std::cout << "real = false" << std::endl;
	}
	
	if (me == me2)
		std::cout << "me = true" << std::endl;
	else
	{
		std::cout << "me = false" << std::endl;
	}

	if (real != real2)
		std::cout << "real = true" << std::endl;
	else
	{
		std::cout << "real = false" << std::endl;
	}

	if (me != me2)
		std::cout << "me = true" << std::endl;
	else
	{
		std::cout << "me = false" << std::endl;
	}

	if (real < real2)
		std::cout << "real = true" << std::endl;
	else
	{
		std::cout << "real = false" << std::endl;
	}
	if (me < me2)
		std::cout << "me = true" << std::endl;
	else
	{
		std::cout << "me = false" << std::endl;
	}

	if (real <= real2)
		std::cout << "real = true" << std::endl;
	else
	{
		std::cout << "real = false" << std::endl;
	}
	if (me <= me2)
		std::cout << "me = true" << std::endl;
	else
	{
		std::cout << "me = false" << std::endl;
	}

	if (real > real2)
		std::cout << "real = true" << std::endl;
	else
	{
		std::cout << "real = false" << std::endl;
	}
	if (me > me2)
		std::cout << "me = true" << std::endl;
	else
	{
		std::cout << "me = false" << std::endl;
	}

	if (real >= real2)
		std::cout << "real = true" << std::endl;
	else
	{
		std::cout << "real = false" << std::endl;
	}
	if (me >= me2)
		std::cout << "me = true" << std::endl;
	else
	{
		std::cout << "me = false" << std::endl;
	}

	std::cout << "# void swap (list& x, list& y)" << std::endl;
	real2.clear();
	me2.clear();
	std::swap(real, real2);
	ft::swap(me, me2);
	COMP_MAP(real, me)
	COMP_MAP(real2, me2)
}

int main(void)
{
	/* test function test */
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
	return 0;
}
