/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:10:39 by mdahani           #+#    #+#             */
/*   Updated: 2025/10/22 18:18:29 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

// * Includes
#include <iostream>

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

        // * Copy constructor
        Bureaucrat(const Bureaucrat &other);

        // * Copy assignment operator
        Bureaucrat &operator=(const Bureaucrat &other);

        // * Destructor
        ~Bureaucrat();

        // * Setters & Getters
        std::string getName();
        unsigned int getGrade();

        // * Methods
};

#endif