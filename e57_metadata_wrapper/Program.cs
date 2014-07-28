using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Mono.Options;

using e57_metadata_wrapper;
using out_type = e57_metadata_wrapper.e57_metadata_wrapper.output_type_t;

namespace e57_metadata_wrapper {
    class Program {
        static void Main(string[] args) {
            string input_file = null;
            string output_file = null;
            bool out_xml = false;
            out_type file_type = out_type.JSON;
            bool show_help = false;
            var p = new OptionSet () {
                { "i|input=", "{PATH} to input .e57 file.", v => input_file = v },
                { "o|output=", "{PATH} to output file (extension is irrelevant).", v => output_file = v },
                { "f|format=", "Output file type. One of {[JSON|XML]}.", v => { if (v.ToLower() == "xml") out_xml = true; }},
                { "h|help",  "show this message and exit", v => show_help = v != null },
            };
            List<string> extra;
            try {
                extra = p.Parse (args);
                if (input_file == null) throw new OptionException("Missing input file name.", "--input");
                if (output_file == null) output_file = "##stdout##";
                if (out_xml) file_type = out_type.XML;
            } catch (OptionException e) {
                Console.Write ("e57_metadata: ");
                Console.WriteLine (e.Message);
                Console.WriteLine ("Try `e57_metadata --help' for more information.");
                return;
            }

            if (show_help) {
                p.WriteOptionDescriptions(Console.Out);
                return;
            }
            if (e57_metadata_wrapper.extract_metadata(input_file, output_file, file_type)) {
                System.Console.Out.WriteLine("%s", "Successfully wrote "+file_type+" metadata file.");
            }
        }
    }
}
