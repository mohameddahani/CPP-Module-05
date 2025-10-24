/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 08:21:18 by mdahani           #+#    #+#             */
/*   Updated: 2025/10/24 18:25:53 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

// * Includes
#include <iostream>
#include <fstream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

// * Class With Orthodox Canonical Form
class ShrubberyCreationForm: public AForm {
    // ! private
    private:
        const std::string target;

    // ! public
    public:
        // * Default constructor
        ShrubberyCreationForm();

        // * Parametrised constructor
        ShrubberyCreationForm(const std::string &target);

        // * Copy constructor
        ShrubberyCreationForm(const ShrubberyCreationForm &other);

        // * Copy assignment operator
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

        // * Destructor
        ~ShrubberyCreationForm();

        // * Setters & Getters
        std::string getTarget() const;
        
        // * Methods
        void execute(Bureaucrat const & executor) const;

        // * Nested Class
        class ErrorCreateFile: public std::exception {
             const char *what() const _GLIBCXX_NOTHROW;
        };
};

std::ostream &operator<<(std::ostream &output, const ShrubberyCreationForm &other);

#endif