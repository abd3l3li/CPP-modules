NAME = megaphone #dont forget the name

CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror
RM = rm -rf

SRC = megaphone.cpp 
OBJ = $(SRC:.cpp=.o) #add .cpp

BOLD      = \e[1m
CGREEN    = \e[32m

all: $(NAME)

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJ) #name here must be in parentheses
	@echo "$(BOLD)$(CGREEN)building the project...\e[0m"
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	@echo "$(BOLD)$(CGREEN)cleaning ...\033[0m"
	@$(RM) $(OBJ)

fclean: clean #no need for parentheses
	@$(RM) $(NAME)

re: fclean all #no need for parentheses

.PHONY: all clean fclean re #no need for parentheses