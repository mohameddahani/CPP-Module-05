/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:10:39 by mdahani           #+#    #+#             */
/*   Updated: 2025/10/25 13:11:33 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

// * Includes
#include <iostream>

// * forward declaration
class Bureaucrat;

// * Class With Orthodox Canonical Form
class Form {
    // ! private
    private:
        const std::string name;
        bool isSigned;
        const unsigned int gradeSign;
        const unsigned int gradeExecute;

    // ! public
    public:
        // * Default constructor
        Form();

        // * Parametrised constructor
        Form(const std::string &name, const unsigned int &gradeSign, const unsigned int &gradeExecute);

        // * Copy constructor
        Form(const Form &other);

        // * Copy assignment operator
        Form &operator=(const Form &other);

        // * Destructor
        ~Form();

        // * Setters & Getters
        std::string getName() const;
        bool getIsSigned() const;
        unsigned int getGradeSign() const;
        unsigned int getGradeExecute() const;
        
        // * Methods
        void beSigned(const Bureaucrat &bureaucrat);

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

std::ostream &operator<<(std::ostream &output, const Form &other);

#endif