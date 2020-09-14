/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 16:09:37 by qperrot-          #+#    #+#             */
/*   Updated: 2020/08/24 10:33:28 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AssaultTerminator.hpp"
#include "Squad.hpp"
#include "ISpaceMarine.hpp"
#include "ISquad.hpp"
#include "TacticalMarine.hpp"

int main()
{
    // ISpaceMarine* bob = new TacticalMarine;
    // ISpaceMarine* jim = new AssaultTerminator;
    
    ISquad* vlc = new Squad;
    // vlc->push(bob);
    // vlc->push(jim);

    // for (int i = 0; i < vlc->getCount(); ++i)
    // {
    //     ISpaceMarine* cur = vlc->getUnit(i);
    //     cur->battleCry();
    //     cur->rangedAttack();
    //     cur->meleeAttack();
    // }

    delete vlc;

    // std::cout << std::endl << std::endl;

	// AssaultTerminator	*Arnold = new AssaultTerminator;
	// ISpaceMarine		*Stallon = new AssaultTerminator(*Arnold);
	// TacticalMarine		*John = new TacticalMarine;
	// ISpaceMarine		*Mike = new TacticalMarine(*John);
	// ISquad				*ElSquad = new Squad;
	// AssaultTerminator	*Jack = Arnold->clone();

	// ElSquad->push(Stallon);
	// ElSquad->push(John);
	// ElSquad->push(Mike);
	// ElSquad->push(Jack);

	// std::cout << std::endl;
	// ElSquad->push(Stallon);
	// std::cout << std::endl;

	// for (int i = 0; i < ElSquad->getCount(); ++i)
    // {
    //     ISpaceMarine* cur = ElSquad->getUnit(i);
    //     cur->battleCry();
    //     cur->rangedAttack();
    //     cur->meleeAttack();
    // }
	
	// delete Arnold;
	// delete ElSquad;

    return 0;
}