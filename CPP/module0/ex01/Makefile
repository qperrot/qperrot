# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qperrot- <qperrot-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/10 13:31:05 by qperrot-          #+#    #+#              #
#    Updated: 2020/08/10 13:34:29 by qperrot-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= phonebook
SRCS	= Contact.class.cpp \
			main.cpp 
OBJS	= $(SRCS:.cpp=.o)
CPPC	= clang++
FLAGS	= -Wall -Wextra -Werror

.cpp.o:
	$(CPPC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CPPC) $(FLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean .cpp.o