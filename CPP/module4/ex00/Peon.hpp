/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 16:46:03 by qperrot-          #+#    #+#             */
/*   Updated: 2020/09/14 10:54:46 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PEON_HPP
#define PEON_HPP

#include "Victim.hpp"

class Peon : public Victim
{
	private:
		//std::string		_Nom;
		Peon();

	public:
		Peon(std::string name);
		Peon(Peon const & src);
		virtual ~Peon();
		Peon &	operator=(Peon const & rhs);
		std::string		getName( void ) const;
		virtual void	getPolymorphed() const;
};

//std::ostream &	operator<<(std::ostream & o, Peon const & rhs);

#endif