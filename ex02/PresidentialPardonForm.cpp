/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 20:48:39 by mdahani           #+#    #+#             */
/*   Updated: 2025/10/24 20:51:26 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// ! Definitions of Orthodox Canonical Form, Member functions, and Setters, Getters

// * Default constructor
PresidentialPardonForm::PresidentialPardonForm():
        // ! A constructor of a base class can be called even if it is abstract, because it is part of the derived object.
        AForm("PresidentialPardonForm", 25, 5), target("unknown target"){
    std::cout << "Default constructor of PresidentialPardonForm is called" << std::endl;
}

// * Parametrised constructor
PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    // ! A constructor of a base class can be called even if it is abstract, because it is part of the derived object.
    : AForm("PresidentialPardonForm", 25, 5), target(target){
    std::cout << "Parametrised constructor of PresidentialPardonForm is called" << std::endl;
}

// * Copy constructor with initializer list
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
    : AForm(other), target(other.target){
    std::cout << "Copy constructor of PresidentialPardonForm is called" << std::endl;
}

// * Copy assignment operator
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other){
    (void)other;

    std::cout << "Copy assignment operator of PresidentialPardonForm is called" << std::endl;
    
    return *this;
}

// * Destructor
PresidentialPardonForm::~PresidentialPardonForm(){
    std::cout << "PresidentialPardonForm is destroyed" << std::endl;
}

// * Setters & Getters
std::string PresidentialPardonForm::getTarget() const{
    return this->target;
}

// * Methods
void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    if (!getIsSigned()){
        throw GradeTooLowException();
    }
    
    // * check if he can excute it
    if (executor.getGrade() > getGradeExecute()){
        throw GradeTooLowException();
    }

    std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

// * Insertion operator
std::ostream &operator<<(std::ostream &output, const PresidentialPardonForm &other){
    return output << other.getTarget()
        << ", sign grade: " << other.getGradeSign()
        << ", exec grade: " << other.getGradeExecute();
}
