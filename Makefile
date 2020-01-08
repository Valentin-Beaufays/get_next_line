CC=				gcc

CFLAGS=			-Wall -Wextra -Werror

BUFFER_SIZE=	1

NAME=			get_next_line

FILES=			get_next_line.c\
				main.c

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -o $(NAME) -D BUFFER_SIZE=$(BUFFER_SIZE) $(FILES)

clean:
	@rm -rf $(NAME)

fclean: clean

re: fclean $(NAME)

exe:
	@./$(NAME)
