/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 09:02:35 by mdahani           #+#    #+#             */
/*   Updated: 2025/10/28 10:01:26 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// ! Definitions of Orthodox Canonical Form, Member functions, and Setters, Getters

// * Default constructor
Intern::Intern(){
    // * fill the array by NULL
    for (int i = 0; i < 3; i++){
        allForms[i] = NULL;
    }

    std::cout << "Default constructor of Intern is called" << std::endl;
}

// * Copy constructor with initializer list
Intern::Intern(const Intern &other){
    (void)other;

    std::cout << "Copy constructor of Intern is called" << std::endl;
}

// * Copy assignment operator
Intern &Intern::operator=(const Intern &other){
    (void)other;

    std::cout << "Copy assignment operator of Intern is called" << std::endl;
    
    return *this;
}

// * Destructor
Intern::~Intern(){
     // ! free the all forms
    for (int i = 0; i < 3; i++){
        delete this->allForms[i];
    }
    
    std::cout << "Intern is destroyed" << std::endl;
}

// * Methods
AForm *Intern::makeForm(const std::string &formName, const std::string &target){
    std::string allFormsNames[3] = {
        "ShrubberyCreationForm",
        "RobotomyRequestForm",
        "PresidentialPardonForm",
    };
    

    // ! fill the array if empty    
    if (!allForms[0])
        this->allForms[0] = new ShrubberyCreationForm(target);
    if (!allForms[1])
        this->allForms[1] = new RobotomyRequestForm(target);
    if (!allForms[2])
        this->allForms[2] = new PresidentialPardonForm(target);


    for (int i = 0; i < 3; i++){
        if (formName == allFormsNames[i]){
            std::cout << "========================================================================" << std::endl;
            std::cout << "Intern creates " << target << std::endl;
            std::cout << "========================================================================" << std::endl;

            return this->allForms[i];
        }
    }

    std::cout << "========================================================================" << std::endl;
    std::cout << "Intern cannot create form: " << formName << " (Unknown form name)" << std::endl;
    std::cout << "========================================================================" << std::endl;

    return NULL;
}
