/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 18:31:28 by mdahani           #+#    #+#             */
/*   Updated: 2025/10/24 18:47:16 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// ! Definitions of Orthodox Canonical Form, Member functions, and Setters, Getters

// * Default constructor
RobotomyRequestForm::RobotomyRequestForm():
        // ! A constructor of a base class can be called even if it is abstract, because it is part of the derived object.
        AForm("RobotomyRequestForm", 72, 45), target("unknown target"){
    std::cout << "Default constructor of RobotomyRequestForm is called" << std::endl;
}

// * Parametrised constructor
RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    // ! A constructor of a base class can be called even if it is abstract, because it is part of the derived object.
    : AForm("RobotomyRequestForm", 72, 45), target(target){
    std::cout << "Parametrised constructor of RobotomyRequestForm is called" << std::endl;
}

// * Copy constructor with initializer list
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other), target(other.target){
    std::cout << "Copy constructor of RobotomyRequestForm is called" << std::endl;
}

// * Copy assignment operator
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other){
    (void)other;

    std::cout << "Copy assignment operator of RobotomyRequestForm is called" << std::endl;
    
    return *this;
}

// * Destructor
RobotomyRequestForm::~RobotomyRequestForm(){
    std::cout << "RobotomyRequestForm is destroyed" << std::endl;
}

// * Setters & Getters
std::string RobotomyRequestForm::getTarget() const{
    return this->target;
}

// * Methods
void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    if (!getIsSigned()){
        throw GradeTooLowException();
    }
    
    // * check if he can excute it
    if (executor.getGrade() > getGradeExecute()){
        throw GradeTooLowException();
    }

    std::cout << "*drilling noises*" << std::endl;

    if (rand() % 2 == 0){
        std::cout << getTarget() + " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "Robotomy failed on " + getTarget() << std::endl;
    }
    
}

// * Insertion operator
std::ostream &operator<<(std::ostream &output, const RobotomyRequestForm &other){
    return output << other.getTarget()
        << ", sign grade: " << other.getGradeSign()
        << ", exec grade: " << other.getGradeExecute();
}
