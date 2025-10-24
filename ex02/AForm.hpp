/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:10:39 by mdahani           #+#    #+#             */
/*   Updated: 2025/10/24 18:03:01 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

// * Includes
#include <iostream>

// * forward declaration
class Bureaucrat;

// * Class With Orthodox Canonical Form
class AForm {
    // ! private
    private:
        const std::string name;
        bool isSigned;
        const unsigned int gradeSign;
        const unsigned int gradeExecute;

    // ! public
    public:
        // * Default constructor
        AForm();

        // * Parametrised constructor
        AForm(const std::string &name, const unsigned int &gradeSign, const unsigned int &gradeExecute);

        // * Copy constructor
        AForm(const AForm &other);

        // * Copy assignment operator
        AForm &operator=(const AForm &other);

        // * Destructor
        virtual ~AForm();

        // * Setters & Getters
        std::string getName() const;
        bool getIsSigned() const;
        unsigned int getGradeSign() const;
        unsigned int getGradeExecute() const;
        
        // * Methods
        void beSigned(const Bureaucrat &bureaucrat);
        virtual void execute(Bureaucrat const & executor) const = 0;

        // * Nested Class
        class GradeTooHighException: public std::exception {
            // ! overrinding the what() method
            const char *what() const _GLIBCXX_NOTHROW;
        };
        class GradeTooLowException: public std::exception {
            // ! overrinding the what() method
            const char *what() const _GLIBCXX_NOTHROW;
        };
};

std::ostream &operator<<(std::ostream &output, const AForm &other);

#endif
