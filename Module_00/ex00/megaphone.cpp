#include <iostream>

int	main(int argc, char *argv[]){

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else {
		for (int i = 1; i < argc; i++){
			std::string holder = argv[i];
			for (size_t j = 0; j < holder.length(); j++)
				holder[j] = std::toupper(static_cast<unsigned char>(holder[j]));
			std::cout << holder ;
			if (i != argc - 1)
				std::cout << " ";
			else
				std::cout << "\n";
		}
	}

}
