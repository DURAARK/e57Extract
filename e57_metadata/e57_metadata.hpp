#ifndef DURAARK_E57METADATA_HPP_
#define DURAARK_E57METADATA_HPP_

#include "extractor.hpp"
#include "compiler.hpp"

extern "C" {

/**
  *  Extract metadata from e57 file and serialize to either JSON or XML output file.
  *  
  *  @param input_file String representing path to input e57 file.
  *  @param output_file String representing path to output file (extension is irrelevant).
  *  @param file_type String that is either "json" or "xml" depending on desired output format.
  */
int DLLEXPORT extract(const char input_file[], const char output_file[], const char file_type[]);

}



#endif // DURAARK_E57METADATA_HPP_
