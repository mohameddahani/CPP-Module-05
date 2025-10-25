/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:15:56 by mdahani           #+#    #+#             */
/*   Updated: 2025/10/25 13:12:04 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

// ? Exception: An exception is a runtime error or an unexpected event that occurs during program execution.

// ? Exception Handling: A mechanism that allows a program to detect, catch, and handle exceptions 
// ? so that the program can continue executing or terminate gracefully instead of crashing.

// ! std::exception: It’s a base (super) class for all standard exceptions in C++. 
// ! It defines a virtual function called what(), which returns a C-style string describing the error.
// ! Every derived exception class can override the what() function to provide a custom error message.

// ? what(): A virtual function that returns a const char* — the description of the exception.

// ! try: Defines a block of code that will be tested for exceptions. 
// ! If an exception is thrown inside this block, control passes to the matching catch block.

// ! throw: Used to signal (or "throw") an exception when a problem occurs. 
// ! The thrown object is typically an instance of a class derived from std::exception.

// ! catch: Defines a block of code that handles an exception. 
// ! It catches the thrown exception if its type matches or is compatible with the type specified in the catch block.


// ! Definitions of Orthodox Canonical Form, Member functions, and Setters, Getters

// * Default constructor
Bureaucrat::Bureaucrat(): name("unknown name"), grade(150){
    std::cout << "Default constructor of Bureaucrat is called" << std::endl;
}

// * Parametrised constructor
Bureaucrat::Bureaucrat(const std::string &name, const unsigned int &grade): name(name){
    if (grade < 1){
        throw Bureaucrat::GradeTooHighException();
    } else if (grade > 150){
        throw Bureaucrat::GradeTooLowException();
    } else {
        this->grade = grade;
    }
    
    std::cout << "Parametrised constructor of Bureaucrat is called" << std::endl;
}

// * Copy constructor with initializer list
Bureaucrat::Bureaucrat(const Bureaucrat &other): name(other.name), grade(other.grade){
    std::cout << "Copy constructor of Bureaucrat is called" << std::endl;
}

// * Copy assignment operator
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other){
    this->grade = other.grade;

    std::cout << "Copy assignment operator of Bureaucrat is called" << std::endl;
    
    return *this;
}

// * Destructor
Bureaucrat::~Bureaucrat(){
    std::cout << "Bureaucrat is destroyed" << std::endl;
}

// * Setters & Getters
std::string Bureaucrat::getName() const{
    return this->name;
}
unsigned int Bureaucrat::getGrade() const{
    return this->grade;
}

// * Methods
void Bureaucrat::incrementBureaucrat(){
    if (this->grade <= 1){
        throw Bureaucrat::GradeTooHighException();
    }

    this->grade--;
}

void Bureaucrat::decrementBureaucrat(){
    if (this->grade >= 150){
        throw Bureaucrat::GradeTooLowException();
    }

    this->grade++;
}

void Bureaucrat::signForm(const AForm &form){
    if (form.getIsSigned()){
        std::cout << getName() << " signed " << form.getName() << std::endl;
    } else {
        std::cout << getName() << " couldn’t sign " << form.getName() << " because " << "The Grade of Bureaucrat is Lower" << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &form){
    form.execute(*this);
}

// * Nested Class
// ! throw(): is mean will not throw
const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Bureaucrat grade is too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Bureaucrat grade is too low!";
}

// * Insertion operator
std::ostream &operator<<(std::ostream &output, const Bureaucrat &other){
    return output << other.getName() << ", bureaucrat grade " << other.getGrade();
}
