/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 20:46:32 by mdahani           #+#    #+#             */
/*   Updated: 2025/10/24 20:47:35 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

// * Includes
#include <iostream>
#include <fstream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

// * Class With Orthodox Canonical Form
class PresidentialPardonForm: public AForm {
    // ! private
    private:
        const std::string target;

    // ! public
    public:
        // * Default constructor
        PresidentialPardonForm();

        // * Parametrised constructor
        PresidentialPardonForm(const std::string &target);

        // * Copy constructor
        PresidentialPardonForm(const PresidentialPardonForm &other);

        // * Copy assignment operator
        PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

        // * Destructor
        ~PresidentialPardonForm();

        // * Setters & Getters
        std::string getTarget() const;
        
        // * Methods
        void execute(Bureaucrat const & executor) const;

        // * Nested Class
        class ErrorCreateFile: public std::exception {
             const char *what() const _GLIBCXX_NOTHROW;
        };
};

std::ostream &operator<<(std::ostream &output, const PresidentialPardonForm &other);

#endif