/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 10:11:10 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/26 09:50:31 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

// int main()
// {
// 	IMateriaSource* src = new MateriaSource();
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());
// 	ICharacter* moi = new Character("moi");
// 	AMateria* tmp;
// 	tmp = src->createMateria("ice");
// 	moi->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	moi->equip(tmp);
// 	ICharacter* bob = new Character("bob");
// 	moi->use(0, *bob);
// 	moi->use(1, *bob);
// 	delete bob;
// 	delete moi;
// 	delete src;
// 	return 0;
// }
int main() {
	IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    ICharacter* me = new Character("me");
    
    AMateria* tmp;
    AMateria* tmp2;
	AMateria* tmp3 = new Ice();
	AMateria* tmp4 = new Cure();
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp2 = src->createMateria("cure");
    me->equip(tmp2);
    tmp2 = src->createMateria("plop");
	me->equip(tmp3);
	me->equip(tmp4);
    std::cout << "tmp2 = " << tmp2 << std::endl;
    
    ICharacter* bob = new Character("bob");
    
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	std::cout << "type = " << tmp->getType() << " xp = " << tmp->getXP() << std::endl;
    
   	me->use(0, *bob);
    std::cout << "xp = " << tmp->getXP() << std::endl;
	
    delete bob;
    delete me;
    delete src;
    
    return 0;
}
