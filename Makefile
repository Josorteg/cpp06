# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: josorteg <josorteg@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/02 15:07:56 by josorteg          #+#    #+#              #
#    Updated: 2024/07/12 10:14:57 by josorteg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Bureaucrat

#########
RM = rm -f
CC = c++
CFLAGS = -Werror -Wextra -Wall -std=c++98
##$-g -fsanitize=address
#########

#########
FILES = main Converter

SRC = $(addsuffix .cpp, $(FILES))

##vpath %.cpp
#########

#########
OBJ = $(SRC:.cpp=.o)
DEP = $(addsuffix .d, $(basename $(OBJ)))
#########

#########
%.o: %.cpp
	${CC} $(CFLAGS) -MMD -c $< -o $@

all:
	$(MAKE) $(NAME) 

$(NAME):: $(OBJ) Makefile
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)


clean:
	$(RM) $(OBJ) $(DEP) 


fclean: clean
	$(RM) $(NAME) 

re:	fclean all

.PHONY: all clean fclean re

-include $(DEP)
