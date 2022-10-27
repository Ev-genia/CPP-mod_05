# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/06 11:54:51 by mlarra            #+#    #+#              #
#    Updated: 2022/10/27 10:03:13 by mlarra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ex02

SRCS	=	main.cpp	Bureaucrat.cpp	Form.cpp	ShrubberyCreationForm.cpp\
			RobotomyRequestForm.cpp	PresidentialPardonForm.cpp

OBJS	=	${SRCS:.cpp=.o}

HEADER	=	Bureaucrat.hpp	Form.hpp	ShrubberyCreationForm.hpp\
			RobotomyRequestForm.hpp		PresidentialPardonForm.hpp

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
			${RM} *_shrubbery

re		:	fclean all