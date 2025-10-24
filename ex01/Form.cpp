/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:15:56 by mdahani           #+#    #+#             */
/*   Updated: 2025/10/24 08:19:26 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

// ! Definitions of Orthodox Canonical Form, Member functions, and Setters, Getters

// * Default constructor
Form::Form(): name("unknown name"), isSigned(false), gradeSign(150), gradeExecute(150){
    std::cout << "Default constructor of Form is called" << std::endl;
}

// * Parametrised constructor
Form::Form(const std::string &name, const unsigned int &gradeSign, const unsigned int &gradeExecute)
    : name(name), isSigned(false), gradeSign(gradeSign), gradeExecute(gradeExecute){
    if (gradeSign < 1 || gradeExecute < 1){
        throw Form::GradeTooHighException();
    } else if (gradeSign > 150 || gradeExecute > 150){
        throw Form::GradeTooLowException();
    }
    
    std::cout << "Parametrised constructor of Form is called" << std::endl;
}

// * Copy constructor with initializer list
Form::Form(const Form &other)
    : name(other.name), isSigned(other.isSigned), gradeSign(other.gradeSign), gradeExecute(other.gradeExecute){
    std::cout << "Copy constructor of Form is called" << std::endl;
}

// * Copy assignment operator
Form &Form::operator=(const Form &other){
    this->isSigned = other.isSigned;

    std::cout << "Copy assignment operator of Form is called" << std::endl;
    
    return *this;
}

// * Destructor
Form::~Form(){
    std::cout << "Form is destroyed" << std::endl;
}

// * Setters & Getters
std::string Form::getName() const{
    return this->name;
}

bool Form::getIsSigned() const{
    return this->isSigned;
}

unsigned int Form::getGradeSign() const {
    return this->gradeSign;
}

unsigned int Form::getGradeExecute() const {
    return this->gradeExecute;
}

// * Methods
void Form::beSigned(const Bureaucrat &bureaucrat){
    if (bureaucrat.getGrade() > getGradeSign()){
        throw Form::GradeTooLowException();
    }

    this->isSigned = true;
}

// * Nested Class
// ! _GLIBCXX_NOTHROW: is mean (noexcept) will not throw
const char *Form::GradeTooHighException::what() const _GLIBCXX_NOTHROW {
    return "Form grade is too high!";
}

const char *Form::GradeTooLowException::what() const _GLIBCXX_NOTHROW {
    return "Form grade is too low!";
}

// * Insertion operator
std::ostream &operator<<(std::ostream &output, const Form &other){
    return output << other.getName() << ", signed: "
           << (other.getIsSigned() ? "yes" : "no" ) << ", sign grade: " 
           << other.getGradeSign() << ", exec grade: " << other.getGradeExecute();
}
