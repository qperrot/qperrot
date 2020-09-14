/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 13:51:40 by qperrot-          #+#    #+#             */
/*   Updated: 2020/09/14 10:56:27 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"

// class AMateria;

class Character : public ICharacter
{
	private:
		std::string	_Name;
		AMateria*	_tab[4];
		Character();

	public:
		Character(std::string name);
		Character(Character const &);
		virtual ~Character();
		Character &	operator=(Character const & rhs);
		virtual std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
};

#endif

