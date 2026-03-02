# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/07 13:36:07 by jweber            #+#    #+#              #
#    Updated: 2026/03/02 15:08:02 by jweber           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ./a.out
CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std="c++98" -MMD -MP -g3

SOURCE_FILES := main.cpp \
				Data.cpp \
				Serialize.cpp \


OBJECT_DIR := .obj/
OBJECT_FILES := $(addprefix $(OBJECT_DIR), $(SOURCE_FILES:.cpp=.o))

OBJECT_DEBUG_DIR := .obj_debug/

DEPS_FILES := $(OBJECT_FILES:.o=.d)

.PHONY : all clean fclean re debug

all: $(NAME)

$(NAME):  $(OBJECT_FILES)
	$(CXX) $(CXXFLAGS) $^ -o $@

-include $(DEPS_FILES)

$(OBJECT_DIR)%.o: %.cpp | $(OBJECT_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJECT_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJECT_DIR)

fclean:
	$(MAKE) clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

debug:
	rm -f $(NAME)
	$(MAKE) OBJECT_DIR=$(OBJECT_DEBUG_DIR) CXXFLAGS="$(CXXFLAGS) -D\"MY_DEBUG\""

debug_clean:
	$(MAKE) OBJECT_DIR= clean

debug_fclean:
	$(MAKE) OBJECT_DIR=$(OBJECT_DEBUG_DIR) fclean

debug_re:
	$(MAKE) OBJECT_DIR=$(OBJECT_DEBUG_DIR) CXXFLAGS="$(CXXFLAGS) -D\"MY_DEBUG\"" re
