##
## EPITECH PROJECT, 2023
## make
## File description:
## make
##

#/--------------------------------------------------------------------/#
#/--------------MADE BY THEO LEMAIRE ET ROMAIN COLLIGNON--------------/#
#/--------------------------------------------------------------------/#


SRC	=	src/main.c \
		src/my_bird_function.c \
		src/help_function.c \

NAME	=	my_bird

OBJ	= $(SRC:.c=.o)

CFLAGS	=	-I./include/

CSFML = -lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system -lm

all: $(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(CSFML)

debug:
	$(CC) -g $(SRC) -o $(NAME) $(CFLAGS) $(CSFML)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
