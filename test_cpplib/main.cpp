#include <iostream>
#include <e57_metadata/e57_metadata.hpp>

int main(int argc, char* argv[]) {
	if (argc < 3 || argc > 4) {
		std::cout << "Usage: test_cpplib input_file.e57 output_file.ext [{json|xml}]\n";
		return 1;
	}

	return extract(argv[1], argv[2], argc > 3 ? argv[3] : nullptr) == 1;
}