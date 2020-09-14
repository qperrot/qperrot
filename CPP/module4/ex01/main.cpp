/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 16:15:39 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/20 18:03:12 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"
#include "Character.hpp"
#include "RadScorpion.hpp"
#include "PlasmaRifle.hpp"
#include "SuperMutant.hpp"
#include "PowerFist.hpp"

int main()
{
	Character* moi = new Character("moi");
	std::cout << *moi;
	Enemy* b = new RadScorpion();
	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();
	AWeapon* pf2 = pf;

	moi->equip(pr);
	std::cout << *moi;
	moi->equip(pf);
	moi->attack(b);
	std::cout << *moi;
	moi->equip(pr);
	std::cout << *moi;
	moi->attack(b);
	std::cout << *moi;
	moi->attack(b);
	std::cout << *moi;

	Enemy* k = new SuperMutant();
	moi->equip(pf2);
	std::cout << *moi;
	moi->attack(k);
	std::cout << *moi;
	moi->attack(k);
	std::cout << *moi;
	moi->attack(k);
	std::cout << *moi;
	moi->recoverAP();
	std::cout << *moi;
	moi->recoverAP();
	std::cout << *moi;
	moi->recoverAP();
	std::cout << *moi;
	moi->recoverAP();
	std::cout << *moi;
	moi->recoverAP();
	std::cout << *moi;
	moi->recoverAP();
	std::cout << *moi;
	moi->attack(k);
	std::cout << *moi;
	return 0;
}