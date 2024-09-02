NAME = Serializer

#########
RM = rm -f
CC = c++
CFLAGS = -Werror -Wextra -Wall -std=c++98
##$-g -fsanitize=address
#########

#########
FILES = main Serializer

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
