# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qperrot- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/11 13:45:05 by qperrot-          #+#    #+#              #
#    Updated: 2019/10/16 09:22:11 by qperrot-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

SRC			=	ft_atoi.c ft_isdigit.c ft_memcpy.c ft_putstr_fd.c ft_strlcpy.c ft_strtrim.c ft_bzero.c ft_isprint.c ft_memmove.c \
				ft_split.c ft_strlen.c ft_substr.c ft_calloc.c ft_itoa.c ft_memset.c ft_strchr.c ft_strmapi.c ft_tolower.c \
				ft_isalnum.c ft_memccpy.c ft_putchar_fd.c ft_strdup.c ft_strncmp.c ft_toupper.c ft_isalpha.c ft_memchr.c \
				ft_putendl_fd.c ft_strjoin.c ft_strnstr.c ft_isascii.c ft_memcmp.c ft_putnbr_fd.c ft_strlcat.c ft_strrchr.c \

BONUSSRC	=	ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c \
				ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c \

OBJSBONUS	=	${BONUSSRC:.c=.o}

OBJS		=	${SRC:.c=.o}

.c.o:
		gcc -Wall -Wextra -Werror -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		ar rcs ${NAME} ${OBJS}
		ranlib ${NAME}

all:	${NAME}

bonus:	${OBJS} ${OBJSBONUS}
		ar rcs ${NAME} ${OBJS} ${OBJSBONUS}

clean:
		rm -f ${OBJS} ${OBJSBONUS}

fclean: clean
		rm -f ${NAME}

re:		fclean all
