# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vifernan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 17:42:37 by vifernan          #+#    #+#              #
#    Updated: 2022/02/21 17:48:22 by vifernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo

CFLAGS	= -Wall -Werror -Wextra

LINK	= -pthread

SRCS	= 	philo.c \

OBJS	= $(SRCS:.c=.o)
CC		= 	gcc
INCLUDES = -I./includes

all: $(NAME)

BCyan = \033[1;36m
GREEN = \033[0;32m
Yellow = \033[0;33m
Red = \033[0;31m
NO_COLOR = \033[0m

$(NAME): $(OBJS) 
	@$(MAKE) -C ./libft
	@$(CC) $(CFLAGS) $(LINK) libft/libft.a $(OBJS) -o $(NAME)
	@echo "$(GREEN)[COMPILED]$(NO_COLOR)"

clean:
	rm -rf $(OBJS)
	@$(MAKE) fclean -C ./libft
	@echo "$(Yellow)[CLEAN]$(NO_COLOR)"

fclean: clean
	rm -rf $(NAME)
	@echo "$(Red)[FCLEAN]$(NO_COLOR)"
	
re: fclean all

.PHONY: all clean fclean re test
