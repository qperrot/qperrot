/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 14:37:54 by qperrot-          #+#    #+#             */
/*   Updated: 2020/09/14 10:54:50 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SORCERER_HPP
#define SORCERER_HPP

#include "Victim.hpp"

class Sorcerer
{
	private:
		std::string		_Nom;
		std::string		_Titre;
		Sorcerer();

	public:
		Sorcerer(std::string name, std::string titre);
		Sorcerer(Sorcerer const & src);
		~Sorcerer();
		Sorcerer &		operator=(Sorcerer const & rhs);
		std::string		getName( void ) const;
		std::string		getTitre( void ) const;
		void 			polymorph(Victim const &) const;
};

std::ostream &	operator<<(std::ostream & o, Sorcerer const & rhs);

#endif