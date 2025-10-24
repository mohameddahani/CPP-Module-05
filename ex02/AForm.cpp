/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 08:32:25 by mdahani           #+#    #+#             */
/*   Updated: 2025/10/24 18:02:48 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

// ! Definitions of Orthodox Canonical Form, Member functions, and Setters, Getters

// * Default constructor
AForm::AForm(): name("unknown name"), isSigned(false), gradeSign(150), gradeExecute(150){
    std::cout << "Default constructor of AForm is called" << std::endl;
}

// * Parametrised constructor
AForm::AForm(const std::string &name, const unsigned int &gradeSign, const unsigned int &gradeExecute)
    : name(name), isSigned(false), gradeSign(gradeSign), gradeExecute(gradeExecute){
    if (gradeSign < 1 || gradeExecute < 1){
        throw AForm::GradeTooHighException();
    } else if (gradeSign > 150 || gradeExecute > 150){
        throw AForm::GradeTooLowException();
    }
    
    std::cout << "Parametrised constructor of AForm is called" << std::endl;
}

// * Copy constructor with initializer list
AForm::AForm(const AForm &other)
    : name(other.name), isSigned(other.isSigned), gradeSign(other.gradeSign), gradeExecute(other.gradeExecute){
    std::cout << "Copy constructor of AForm is called" << std::endl;
}

// * Copy assignment operator
AForm &AForm::operator=(const AForm &other){
    this->isSigned = other.isSigned;

    std::cout << "Copy assignment operator of AForm is called" << std::endl;
    
    return *this;
}

// * Destructor
AForm::~AForm(){
    std::cout << "AForm is destroyed" << std::endl;
}

// * Setters & Getters
std::string AForm::getName() const{
    return this->name;
}

bool AForm::getIsSigned() const{
    return this->isSigned;
}

unsigned int AForm::getGradeSign() const {
    return this->gradeSign;
}

unsigned int AForm::getGradeExecute() const {
    return this->gradeExecute;
}

// * Methods
void AForm::beSigned(const Bureaucrat &bureaucrat){
    if (bureaucrat.getGrade() > getGradeSign()){
        throw AForm::GradeTooLowException();
    }

    this->isSigned = true;
}

// * Nested Class
// ! _GLIBCXX_NOTHROW: is mean (noexcept) will not throw
const char *AForm::GradeTooHighException::what() const _GLIBCXX_NOTHROW {
    return "AForm grade is too high!";
}

const char *AForm::GradeTooLowException::what() const _GLIBCXX_NOTHROW {
    return "AForm grade is too low!";
}

// * Insertion operator
std::ostream &operator<<(std::ostream &output, const AForm &other){
    return output << other.getName() << ", signed: "
           << (other.getIsSigned() ? "yes" : "no" ) << ", sign grade: " 
           << other.getGradeSign() << ", exec grade: " << other.getGradeExecute();
}
