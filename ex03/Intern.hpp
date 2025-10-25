/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 09:02:25 by mdahani           #+#    #+#             */
/*   Updated: 2025/10/25 09:58:23 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

// * Includes
#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

// * Class With Orthodox Canonical Form
class Intern {
    // ! private
    private:
        AForm *allForms[3];
    // ! public
    public:
        // * Default constructor
        Intern();

        // * Copy constructor
        Intern(const Intern &other);

        // * Copy assignment operator
        Intern &operator=(const Intern &other);

        // * Destructor
        ~Intern();
        
        // * Methods
        AForm *makeForm(const std::string &formName, const std::string &target);
};

#endif