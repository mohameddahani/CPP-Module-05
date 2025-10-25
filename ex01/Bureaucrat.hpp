/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:10:39 by mdahani           #+#    #+#             */
/*   Updated: 2025/10/25 13:11:17 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

// * Includes
#include <iostream>

// * forward declaration
class Form;

// * Class With Orthodox Canonical Form
class Bureaucrat {
    // ! private
    private:
        const std::string name;
        unsigned int grade;

    // ! public
    public:
        // * Default constructor
        Bureaucrat();

        // * Parametrised constructor
        Bureaucrat(const std::string &name, const unsigned int &grade);

        // * Copy constructor
        Bureaucrat(const Bureaucrat &other);

        // * Copy assignment operator
        Bureaucrat &operator=(const Bureaucrat &other);

        // * Destructor
        ~Bureaucrat();

        // * Setters & Getters
        std::string getName() const;
        unsigned int getGrade() const;
        
        // * Methods
        void incrementBureaucrat();
        void decrementBureaucrat();
        void signForm(const Form &form);

        // * Nested Class
        class GradeTooHighException: public std::exception {
            // ! overrinding the what() method
            const char *what() const throw();
        };
        class GradeTooLowException: public std::exception {
            // ! overrinding the what() method
            const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &output, const Bureaucrat &other);

#endif