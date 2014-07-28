#include "e57_metadata.hpp"

int extract(const char input_file[], const char output_file[], const char file_type[]) {
	duraark::file_type_t ft = duraark::JSON;
	if (file_type != nullptr) {
		std::string ft_str(file_type);
		if (ft_str == "xml") {
			ft = duraark::XML;
		}
		else if (ft_str != "json") {
			std::cout << "Unknown file type." << "\n";
			return 1;
		}
	}
	return static_cast<int>(duraark::extractor::extract(input_file, output_file, ft));
}

int test(const char input_file[]) {
	std::cout << input_file << "\n";
	return 0;
}