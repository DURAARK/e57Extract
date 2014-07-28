#ifndef DURAARK_EXTRACTOR_HPP_
#define DURAARK_EXTRACTOR_HPP_

#include "data_types.hpp"


namespace duraark {

typedef enum { JSON, XML/*, CSV*/ } file_type_t;

struct extractor {
	static bool extract(const char input_file[], const char output_file[], file_type_t file_type);

protected:
	static bool write_file_(const char output_file[], file_type_t file_type, const e57_metadata_t& data);

};


}

#endif // DURAARK_EXTRACTOR_HPP_