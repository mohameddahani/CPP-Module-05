/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:06:08 by mdahani           #+#    #+#             */
/*   Updated: 2025/10/24 18:17:02 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(){
    // ! test higher
    try {
        Bureaucrat akhnouch("akhnouch", 2);
        std::cout << akhnouch << std::endl;
        
        Form form("health", 3, 1);
        
        form.beSigned(akhnouch);
        
        std::cout << "========================================================================" << std::endl;
        akhnouch.signForm(form);
        std::cout << "========================================================================" << std::endl;
        
        std::cout << form << std::endl;
    }
    catch (const std::exception &e){
        std::cout << "========================================================================" << std::endl;
        std::cout << e.what() << std::endl;
        std::cout << "========================================================================" << std::endl;
    }
    
    // ! test higher
    try {
        Bureaucrat citizen("citizen", 140);
        std::cout << citizen << std::endl;
        
        Form form("health", 3, 1);

        form.beSigned(citizen);
        
        std::cout << "========================================================================" << std::endl;
        citizen.signForm(form);
        std::cout << "========================================================================" << std::endl;
        
        std::cout << form << std::endl;
    }
    catch (const std::exception &e){
        std::cout << "========================================================================" << std::endl;
        std::cout << e.what() << std::endl;
        std::cout << "========================================================================" << std::endl;
    }
}
