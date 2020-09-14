# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/09 10:40:51 by qperrot-          #+#    #+#              #
#    Updated: 2020/09/09 10:51:27 by qperrot-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CPPC= clang++
CFLAGS= -Wall -Werror -Wextra
NAME= convert
SRCS=	main.cpp \
		Convert.cpp
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