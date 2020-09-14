/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 13:51:25 by qperrot-          #+#    #+#             */
/*   Updated: 2020/09/14 10:56:25 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class AMateria;
class ICharacter;

class Cure : public AMateria
{
	private:
		unsigned int _xp;
		std::string	_type;
		// Cure();

	public:
		Cure();
		Cure(std::string const & type);
		Cure(Cure const &);
		virtual ~Cure();
		Cure &	operator=(Cure const & rhs);
		std::string const & getType() const; //Returns the materia type
		unsigned int getXP() const; //Returns the Materia's XP
		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
};

#endif

