# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/11 14:05:20 by qperrot-          #+#    #+#              #
#    Updated: 2020/09/11 14:05:44 by qperrot-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CPPC= clang++
CFLAGS= -Wall -Werror -Wextra
NAME= whatever
SRCS=	whatever.cpp
OBJS= $(SRCS:.cpp=.o)

.cpp.o:
	$(CPPC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CPPC) $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean .cpp.o