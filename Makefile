# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/28 01:07:53 by alan              #+#    #+#              #
#    Updated: 2019/02/28 01:07:54 by alan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME :=			diceroll
LIB :=			libft/libftprintf.a

C_SRCS :=		$(wildcard ./srcs/*.c)
C_OBJS :=		$(patsubst %.c,%.o,$(C_SRCS))
DEPENDS :=		$(patsubst $.c,$.d,$(C_SRCS))

INCLUDE_DIRS :=	-I./includes -I./libft/includes
CFLAGS +=		-g -Wall -Wextra -Werror $(INCLUDE_DIRS)
LDFLAGS +=		-L./libft -lftprintf

.PHONY:			all clean fclean re

all: $(NAME)
	@ctags -R

$(LIB):
	make -C libft

$(NAME): $(LIB) $(C_OBJS)
	$(CC) $(CFLAGS) $(C_OBJS) -o $(NAME) $(LDFLAGS)

#-include $(DEPENDS)
#
#%.o: %.c Makefile
#	$(CC) $(CFLAGS) -MMD $<
#
clean:
	@- $(RM) $(C_OBJS)
	@- make -C libft clean

fclean: clean
	@- $(RM) $(NAME)
	@- make -C libft fclean

re: fclean all
