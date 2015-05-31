PKGS = glew glfw3

CC = gcc
CFLAGS = -Wall -Wextra -Werror $(shell pkg-config --cflags $(PKGS))
LDFLAGS = $(shell pkg-config --libs $(PKGS)) -framework OpenGL

CFLAGS += -g -O0

NAME = scop
OBJS = scop.o load_shaders.o

all: $(NAME)

$(NAME): $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

test: $(NAME)
	./$(NAME)
