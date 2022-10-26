# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/06 11:54:51 by mlarra            #+#    #+#              #
#    Updated: 2022/10/27 00:26:05 by mlarra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ex02

SRCS	=	main.cpp	Bureaucrat.cpp	Form.cpp	ShrubberyCreationForm.cpp\
			RobotomyRequestForm.cpp

OBJS	=	${SRCS:.cpp=.o}

HEADER	=	Bureaucrat.hpp	Form.hpp	ShrubberyCreationForm.hpp\
			RobotomyRequestForm.hpp

CC		=	c++

CFLAGS	=	-Wall -Wextra -Werror -std=c++98

RM		=	rm -f

.PHONY	:	all clean fclean re

${NAME}	:	${OBJS} ${HEADER}
			${CC} ${CFLAFS} ${SRCS} -o ${NAME}

all		:	${NAME}

clean	:
			${RM} ${OBJS}

fclean	:	clean
			${RM} ${NAME}

re		:	fclean all