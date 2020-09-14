/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 09:51:19 by qperrot-          #+#    #+#             */
/*   Updated: 2020/09/14 10:55:59 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SQUAD_HPP
#define SQUAD_HPP

#include "ISquad.hpp"

class Squad : public ISquad
{
	private:
		int		_Unit;
		typedef struct s_Unit
		{
			ISpaceMarine* _Marine;
			struct s_Unit *_next;
		}			t_Unit;
		t_Unit  *_Begin;
		
	public:
		Squad();
		Squad(Squad const &);
		virtual ~Squad();
		virtual int getCount() const;
		Squad &	operator=(Squad const & rhs);
		virtual ISpaceMarine* getUnit(int) const;
		virtual int push(ISpaceMarine*);
};

#endif