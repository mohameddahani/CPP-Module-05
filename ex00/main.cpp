/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:06:08 by mdahani           #+#    #+#             */
/*   Updated: 2025/10/23 11:26:28 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(){
    // ! test lower
    try {
        Bureaucrat akhnouch("akhnouch", 2);
        akhnouch.incrementBureaucrat();   
        // akhnouch.incrementBureaucrat();
        std::cout << akhnouch << std::endl;
    }
    catch (const std::exception &e){
        std::cout << e.what() << std::endl;
    }
    
    // ! test higher
    try {
        // Bureaucrat citizen("genZ", 150);
        Bureaucrat citizen;
        citizen.decrementBureaucrat();
        std::cout << citizen << std::endl;
    }
    catch (const std::exception &e){
        std::cout << e.what() << std::endl;
    }
}
