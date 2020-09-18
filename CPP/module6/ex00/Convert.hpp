/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 14:25:11 by qperrot-          #+#    #+#             */
/*   Updated: 2020/09/17 14:38:30 by qperrot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>
#include <exception>
#include <sstream>
#include <string>
#include <cstring>
#include <stdlib.h> 
#include <float.h>
#include <limits>

class Convert
{
	private:
		char		t_char;
		int			t_int;
		float		t_float;
		double		t_double;
		bool		t_neg;
		std::string	t_tab[6];

	public:
		class WrongConvException : public std::exception
		{
			public:
				WrongConvException() throw();
				WrongConvException(WrongConvException const &) throw();
				virtual ~WrongConvException() throw();
				WrongConvException & operator=(WrongConvException const &rhs) throw();
				virtual const char* what() const throw();
		};
		Convert();
		Convert(std::string num);
		Convert(Convert const &);
		~Convert();
		Convert & operator=(Convert const &rhs);
		int		Printinf(std::string copy) const;
		int		Parsing(std::string num);
		int		getInt() const;
		float	getFloat() const;
		double	getDouble() const;
		char	getChar() const;
		bool	getNeg() const;
		void	PrintChar() const;
		void	PrintInt() const;
		void	PrintFloat() const;
		void	PrintDouble() const;
};


#endif
