/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Gryphon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 17:22:34 by qperrot-          #+#    #+#             */
/*   Updated: 2020/09/14 10:54:42 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GRYPHON_HPP
#define GRYPHON_HPP

#include "Victim.hpp"

class Gryphon : public Victim
{
	private:
		//std::string		_Nom;
		Gryphon();

	public:
		Gryphon(std::string name);
		Gryphon(Gryphon const & src);
		virtual ~Gryphon();
		Gryphon &	operator=(Gryphon const & rhs);
		std::string		getName( void ) const;
		void	getPolymorphed() const;
};

//std::ostream &	operator<<(std::ostream & o, Gryphon const & rhs);

#endif