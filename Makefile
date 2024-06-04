# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkoca <dkoca@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/12 01:06:15 by dkoca             #+#    #+#              #
#    Updated: 2024/06/01 10:14:15 by dkoca            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap
BONUS := checker

SRCDIR := src
_SRC := main.c input_check.c utils.c free.c list.c list2.c operations.c operations2.c algorithm.c small_algorithms.c alg_utils.c alg_utils2.c alg_utils3.c
SRC := $(addprefix $(SRCDIR)/, $(_SRC))

_BSRC := checker_bonus.c input_check.c utils.c free.c list.c list2.c operations.c operations2.c alg_utils3.c small_algorithms.c alg_utils.c checker_utils.c
BSRC := $(addprefix $(SRCDIR)/, $(_BSRC))

OBJDIR := obj
_OBJ := $(_SRC:.c=.o)
_BOBJ := $(_BSRC:.c=.o)
OBJ := $(addprefix $(OBJDIR)/, $(_OBJ))
BOBJ := $(addprefix $(OBJDIR)/, $(_BOBJ))

LIBFTDIR := libft
LIBFT := $(LIBFTDIR)/libft.a

CC := cc
CFLAGS := -Wall -Wextra -Werror -g -I$(SRCDIR) -I$(LIBFTDIR)
LDFLAGS :=  -L$(LIBFTDIR) -lft
RM := /bin/rm -f


all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LDFLAGS)

$(BONUS): $(LIBFT) $(BOBJ)
	$(CC) $(CFLAGS) -o $@ $(BOBJ) $(LDFLAGS)

$(LIBFT):
	@make -C $(LIBFTDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

bonus: all $(BONUS)

clean:
	$(RM) $(OBJ) $(BONUS)
	$(RM) -rf $(OBJDIR)
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	$(RM) $(NAME) $(BONUS)
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

.PHONY:
	all clean fclean re bonus