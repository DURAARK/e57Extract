using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;

namespace e57_metadata_wrapper {

    class e57_metadata_wrapper {
        /**
         *  Output file type of serialized metadata.
         */
        public enum output_type_t { XML, JSON }

        /**
         *  Extract e57 file metadata and write results to output file.
         *
         *  @param input_file Path to E57 input file to parse and extract metadata from.
         *  @param output_file Path to output file (extension is ignored).
         *  @param file_type File type of output file. Either output_type_t.XML or output_type_t.JSON.
         */
        public static bool extract_metadata(string input_file, string output_file, output_type_t file_type) {
            string t;
            switch (file_type) {
                case output_type_t.XML: t = "xml"; break;
                default: t = "json"; break;
            }
            return extract_metadata(input_file, output_file, t);
        }

        [DllImport("e57_metadata.dll")]
        private static extern int extract(string input_file, string output_file, string file_type);

        static private bool extract_metadata(string input_file, string output_file, string file_type) {
            int result = extract(input_file, output_file, file_type);
            return result == 0;
        }

    }

}
