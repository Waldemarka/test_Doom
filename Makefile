# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/24 15:12:04 by vomelchu          #+#    #+#              #
#    Updated: 2018/09/06 13:34:56 by vomelchu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC_WOLF = ./files/get_next_line.c ./files/raycast.c\
		./files/other.c ./files/read.c ./files/main.c\
		./files/raycast2.c ./files/sdl.c ./files/keys.c\
		./files/sprite.c ./files/keys2.c ./files/door.c\
		./files/skybox.c ./files/fresh.c 

OBJECT_WOLF = $(SRC_WOLF:.c=.o)

FLAGS = -Wall -Wextra

INCLUDES_WOLF = -I ./includes/

INCLUDES_LIBFT = -I ./source/libft/includes

INCLUDES_SDL2 = -I ./source/SDL/SDL2.framework/Headers

INCLUDES_SDL2_IMAGE = -I ./source/SDL/SDL2_image.framework/Headers

INCLUDES_SDL2_MIXER = -I ./source/SDL/SDL2_mixer.framework/Headers

LIBFT = ./source/libft/libft.a

INCLUDES_SDL2_TTF = -I ./source/SDL/SDL2_ttf.framework/Headers

FRAMEWORK_SDL2 = -F ./source/SDL -framework SDL2 \
	-framework SDL2_image \
	-framework SDL2_ttf \
	-framework SDL2_mixer

FRAMEWORK_MLX = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME) : $(OBJECT_WOLF)
	make -C ./source/libft
	@echo "file: */Wolf"
	@gcc -o $(NAME) $(FLAGS) $(LIBFT) $(INCLUDES_SDL2) $(INCLUDES_SDL2_IMAGE) -rpath @loader_path/source/sdl $(FRAMEWORK_SDL2) $(OBJECT_WOLF) $(INCLUDES_SDL2_TTF) $(INCLUDES_SDL2_MIXER)

%.o: %.c includes/*.h
	gcc -g $(FLAGS) -o $@ -c $< $(INCLUDES_WOLF) $(INCLUDES_SDL2) $(INCLUDES_LIBFT) \
$(INCLUDES_SDL2_IMAGE) $(INCLUDES_SDL2_TTF) $(INCLUDES_SDL2_MIXER)

%.o: %.c
	gcc -g 	$(FLAGS) -o $@ -c $< $(INCLUDES_WOLF) $(INCLUDES_SDL2) $(INCLUDES_LIBFT) \
$(INCLUDES_SDL2_IMAGE) $(INCLUDES_SDL2_TTF) $(INCLUDES_SDL2_MIXER)

	@echo "Wolf compiled"
clean:
	make -C ./source/libft clean
	/bin/rm -f $(OBJECT_WOLF)
	rm -f TAGS

fclean: clean
	/bin/rm -f ./source/libft/libft.a
	/bin/rm -f $(NAME)

re: fclean all tags

tags:
	etags -R *.c *.h
