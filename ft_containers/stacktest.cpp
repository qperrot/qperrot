/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacktest.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 16:39:45 by qperrot-          #+#    #+#             */
/*   Updated: 2020/10/26 16:42:54 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.hpp"
#include "stack.hpp"

void test_basic()
{
	std::cout << "# stack()" << std::endl;
	ft::stack<int> empty_stack;

	std::cout << "# stack(container_type)" << std::endl;
	int arr[] = {1, 2, 3, 4, 5};
	ft::list<int> cpy(arr, arr + 5);
	ft::stack<int> me(cpy);
	print_stack(me);

	std::cout << "# stack1 = stack2" << std::endl;
	ft::stack<int> me2 = me;
	print_stack(me2);

	std::cout << "# stack1(stack2)" << std::endl;
	ft::stack<int> me3(me);
	print_stack(me3);
}

void test_capacity()
{
	int arr[] = {1, 2, 3, 4, 5};
	ft::list<int> mcpy(arr, arr + 5);
	std::deque<int> rcpy(arr, arr + 5);

	ft::stack<int> me;
	std::stack<int> real;
	ft::stack<int> me2(mcpy);
	std::stack<int> real2(rcpy);

	std::cout << "# empty()" << std::endl;
	std::cout << "# empty()" << std::endl;
	std::cout << "real = " << real.empty() << std::endl;
	std::cout << "me = " << me.empty() << std::endl;
	std::cout << "# empty()" << std::endl;
	std::cout << "real = " << real2.empty() << std::endl;
	std::cout << "me = " << me2.empty() << std::endl;

	std::cout << "# size()" << std::endl;
	std::cout << "real = " << real.size() << std::endl;
	std::cout << "me = " << me.size() << std::endl;
	std::cout << "# size()" << std::endl;
	std::cout << "real = " << real2.size() << std::endl;
	std::cout << "me = " << me2.size() << std::endl;

	std::cout << "# top()" << std::endl;
	std::cout << "real = " << real2.top() << std::endl;
	std::cout << "me = " << me2.top() << std::endl;


	std::cout << "# push(val) : val = 6" << std::endl;
	real2.push(6);
	me2.push(6);
	COMP_STACK(real2, me2);

	std::cout << "# push(val) : val = 9" << std::endl;
	real2.push(9);
	me2.push(9);
	COMP_STACK(real2, me2);


	std::cout << "# push(val) : val = -1" << std::endl;
	real2.push(-1);
	me2.push(-1);
	COMP_STACK(real2, me2);

	std::cout << "# pop()" << std::endl;
	real2.pop();
	me2.pop();
	COMP_STACK(real2, me2);
	std::cout << "# pop()" << std::endl;
	real2.pop();
	me2.pop();
	COMP_STACK(real2, me2);
	std::cout << "# pop()" << std::endl;
	real2.pop();
	me2.pop();
	COMP_STACK(real2, me2);
	std::cout << "# pop()" << std::endl;
	real2.pop();
	me2.pop();
	COMP_STACK(real2, me2);
	std::cout << "# pop()" << std::endl;
	real2.pop();
	me2.pop();
	COMP_STACK(real2, me2);
	std::cout << "# pop()" << std::endl;
	real2.pop();
	me2.pop();
	COMP_STACK(real2, me2);
	std::cout << "# pop()" << std::endl;
	real2.pop();
	me2.pop();
	COMP_STACK(real2, me2);
	std::cout << "# pop()" << std::endl;
	real2.pop();
	me2.pop();
	COMP_STACK(real2, me2);
}

void non_member_fonction()
{
	int arr[] = {1, 2, 3, 4, 5};
	ft::list<int> mcpy(arr, arr + 5);
	std::deque<int> rcpy(arr, arr + 5);
	ft::stack<int> me(mcpy);
	std::stack<int> real(rcpy);
	ft::stack<int> me2(mcpy);
	std::stack<int> real2(rcpy);
	real2.push(6);	
	me2.push(6);

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


}

int main(void)
{
	std::cout << "\033[1;4;34m" << "-----------------test basic function---------------------" << "\033[0m" << std::endl;
	test_basic();
	std::cout << "\033[1;4;34m" << "-----------------test capacity function------------------" << "\033[0m" << std::endl;
	test_capacity();
	std::cout << "\033[1;4;34m" << "-----------------non member fonction function overloads----------" << "\033[0m" << std::endl;
	non_member_fonction();

	return 0;
}