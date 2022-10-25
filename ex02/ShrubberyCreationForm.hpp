/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarra <mlarra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:24:31 by mlarra            #+#    #+#             */
/*   Updated: 2022/10/26 00:05:51 by mlarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Form.hpp"
# include <fstream>

# define ASCII_THREE                                                 \
"                                                         .\n"       \
"                                              .         ;  \n"      \
"                 .              .              ;%     ;;   \n"      \
"                   ,           ,                :;%  %;   \n"       \
"                    :         ;                   :;%;'     .,   \n"\
"           ,.        %;     %;            ;        %;'    ,;\n"     \
"             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"      \
"              %;       %;%;      ,  ;       %;  ;%;   ,%;' \n"      \
"               ;%;      %;        ;%;        % ;%;  ,%;'\n"         \
"                `%;.     ;%;     %;'         `;%%;.%;'\n"           \
"                 `:;%.    ;%%. %@;        %; ;@%;%'\n"              \
"                    `:%;.  :;bd%;          %;@%;'\n"                \
"                      `@%:.  :;%.         ;@@%;'   \n"              \
"                        `@%.  `;@%.      ;@@%;         \n"          \
"                          `@%%. `@%%    ;@@%;        \n"            \
"                            ;@%. :@%%  %@@%;       \n"              \
"                              %@bd%%%bd%%:;     \n"                 \
"                                #@%%%%%:;;\n"                       \
"                                %@@%%%::;\n"                        \
"                                %@@@%(o);  . '         \n"          \
"                                %@@@o%;:(.,'         \n"            \
"                            `.. %@@@o%::;         \n"               \
"                               `)@@@o%::;         \n"               \
"                                %@@(o)::;        \n"                \
"                               .%@@@@%::;         \n"               \
"                               ;%@@@@%::;.          \n"             \
"                              ;%@@@@%%:;;;. \n"                     \
"                          ...;%@@@@@%%:;;;;,..\n"                   \

class ShrubberyCreationForm: public Form
{
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &);
	ShrubberyCreationForm(const ShrubberyCreationForm &);
	~ShrubberyCreationForm();

	ShrubberyCreationForm(std::string);
	void	execute(Bureaucrat const &) const;
};



#endif