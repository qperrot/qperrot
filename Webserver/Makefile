# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmaokham <vmaokham@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/23 12:40:31 by vmaokham          #+#    #+#              #
#    Updated: 2021/03/01 10:35:23 by vmaokham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colours
YELLOW		= \033[0;33m
GREEN		= \033[0;32m
END			= \033[0;0m

NAME	= webserv
CC		= clang++
CFLAGS	= -Wall -Werror -Wextra -std=c++98
FILES	= main \
		  parser \
		  config \
		  location \
		  server \
		  client \
		  request \
		  response \
		  cgi \
		  log \
		  utils

SRCS = $(addprefix srcs/, $(addsuffix .cpp, $(FILES)))
OBJS = $(SRCS:.cpp=.o)
INCLUDE = -I includes

PREFIX	= $(YELLOW)$(NAME) $(END)\xc2\xbb

all: $(NAME)

$(NAME): $(OBJS)
	@echo $(ECHO) "$(PREFIX)$(GREEN) Building executable... $(END)Name: $(NAME)"
	@$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) -o $@
	@mkdir ./www/upload/
	@chmod 755 ./cgi-bin/

%.o: %.cpp
	@echo $(ECHO) "$(PREFIX)$(GREEN) Compiling file $(END)$<"
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@echo $(ECHO) "$(PREFIX)$(GREEN) Removing .o files $(END)"
	@rm -f $(OBJS)
	@rm -f www/test42/YoupiBanane/file_should_exist_after
	@rm -f www/test42/YoupiBanane/multiple_same

fclean: clean
	@echo $(ECHO) "$(PREFIX)$(GREEN) Removing executable $(END)"
	@rm -rf $(NAME)
	@rm -rf ./www/upload

re: fclean all

.PHONY: clean fclean re all