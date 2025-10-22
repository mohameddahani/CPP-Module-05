/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:15:56 by mdahani           #+#    #+#             */
/*   Updated: 2025/10/22 18:19:46 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// ! Definitions of Orthodox Canonical Form, Member functions, and Setters, Getters

// * Default constructor
Bureaucrat::Bureaucrat(){
    std::cout << "Default constructor of Bureaucrat is called" << std::endl;
}

// * Copy constructor with initializer list
Bureaucrat::Bureaucrat(const Bureaucrat &other){
    std::cout << "Copy constructor of Bureaucrat is called" << std::endl;
}

// * Copy assignment operator
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other){
    std::cout << "Copy assignment operator of Bureaucrat is called" << std::endl;
    
    return *this;
}

// * Destructor
Bureaucrat::~Bureaucrat(){
    std::cout << "Bureaucrat is destroyed" << std::endl;
}
