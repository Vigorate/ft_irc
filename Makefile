NAME = ircserv

CC	= clang++

CFLAGES = -Wall -Wextra -std=c++98 -fsanitize=address -g3


IFLAGES =  -I./inc -I./inc/cmd

SRCS := ./main.cpp \
		./Socket.cpp \
		./Utils.cpp \
		./Server.cpp \
		./User.cpp \

OBJS := $(SRCS:%.cpp=%.o)

$(NAME): $(OBJS)
		@echo "compiler>>>>>>>>" 
		@$(CC) $(CFLAGES) $(OBJS) -o $@ 
		@echo "IRC done!"		

all: $(NAME)

clean:
		@rm -rf $(OBJS)
		@echo "Delete"

fclean:clean
		@rm -rf $(NAME)
		@echo "Delete all"

%.o: %.cpp
		@$(CC) $(CFLAGES) $(IFLAGES) -c $< -o $@
		
re: fclean all

.PHONY: all clean fclean re
	
