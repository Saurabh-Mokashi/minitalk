# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smokashi <smokashi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/16 19:31:09 by smokashi          #+#    #+#              #
#    Updated: 2022/07/22 15:15:14 by smokashi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client.c

SERVER = server.c

CLIENT_BONUS = client_bonus.c

SERVER_BONUS = server_bonus.c

CC = cc

CFLAGS = -Wall -Wextra -Werror

OBJC = $(CLIENT:.c=.o)
OBJS = $(SERVER:.c=.o)
OBJBC = $(CLIENT_BONUS:.c=.o)
OBJBS = $(SERVER_BONUS:.c=.o)

NAMEC =  client
NAMES =  server
NAMEBC =  client_bonus
NAMEBS =  server_bonus
NAME = temp
RM = rm -rf

all : $(NAME)

$(NAME) : $(OBJC) $(OBJS) follow

follow : $(NAMES) $(NAMEC)


bonus : followb

followb : $(OBJBS) $(OBJBC) $(NAMEBS) $(NAMEBC)

%.o :	%.c 
	$(CC)  $(CFLAGS) $< -c -o $@


clean :	
		$(RM) $(OBJS)
		$(RM) $(OBJC)
		$(RM) $(OBJBS)
		$(RM) $(OBJBC)

fclean:	clean
		$(RM) $(NAMEC) $(NAMES) $(NAMEBC) $(NAMEBS)

re: clean all

re_bonus : clean bonus