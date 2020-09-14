/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 16:25:03 by qperrot-          #+#    #+#             */
/*   Updated: 2020/09/14 10:54:54 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef VICTIM_HPP
#define VICTIM_HPP

#include <string>
#include <iostream>
#include <iomanip> 

class Victim
{
	private:
		Victim();

	protected:
		std::string		_Nom;

	public:
		Victim(std::string name);
		Victim(Victim const & src);
		virtual ~Victim();
		Victim &	operator=(Victim const & rhs);
		std::string		getName( void ) const;
		virtual void	getPolymorphed() const;
};

std::ostream &	operator<<(std::ostream & o, Victim const & rhs);

#endif