/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 18:24:50 by mdahani           #+#    #+#             */
/*   Updated: 2025/10/24 18:49:15 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

// * Includes
#include <iostream>
#include <bits/stdc++.h>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

// * Class With Orthodox Canonical Form
class RobotomyRequestForm: public AForm {
    // ! private
    private:
        const std::string target;

    // ! public
    public:
        // * Default constructor
        RobotomyRequestForm();

        // * Parametrised constructor
        RobotomyRequestForm(const std::string &target);

        // * Copy constructor
        RobotomyRequestForm(const RobotomyRequestForm &other);

        // * Copy assignment operator
        RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

        // * Destructor
        ~RobotomyRequestForm();

        // * Setters & Getters
        std::string getTarget() const;
        
        // * Methods
        void execute(Bureaucrat const & executor) const;
};

std::ostream &operator<<(std::ostream &output, const RobotomyRequestForm &other);

#endif