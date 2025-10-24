/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:06:08 by mdahani           #+#    #+#             */
/*   Updated: 2025/10/24 18:00:00 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(){
    // // ! test higher
    // try {
    //     Bureaucrat akhnouch("akhnouch", 2);
    //     std::cout << akhnouch << std::endl;
        
    //     ShrubberyCreationForm form("garden");
    //     form.beSigned(akhnouch);
    //     std::cout << "========================================================================" << std::endl;
    //     std::cout << form << std::endl;
    //     std::cout << "========================================================================" << std::endl;
        
    //     std::cout << "========================================================================" << std::endl;
    //     form.execute(akhnouch);
    //     std::cout << "========================================================================" << std::endl;
    // }
    // catch (const std::exception &e){
    //     std::cout << e.what() << std::endl;
    // }
    
    // ! test lower
    try {
        Bureaucrat citizen("citizen", 145);
        std::cout << citizen << std::endl;
        
        ShrubberyCreationForm form("health");
        
        std::cout << "========================================================================" << std::endl;
        citizen.signForm(form);
        std::cout << "========================================================================" << std::endl;
        
        form.beSigned(citizen);
        
        std::cout << "========================================================================" << std::endl;
        std::cout << form << std::endl;
        std::cout << "========================================================================" << std::endl;
        
        std::cout << "========================================================================" << std::endl;
        form.execute(citizen);
        std::cout << "========================================================================" << std::endl;
    }
    catch (const std::exception &e){
        std::cout << e.what() << std::endl;
    }
}
