#include "extractor.hpp"

#include <iostream>
#include <fstream>
#include <stdexcept>

#include <cereal/cereal.hpp>
#include <cereal/types/vector.hpp>
#include <cereal/archives/json.hpp>
#include <cereal/archives/xml.hpp>

#include <e57/E57Simple.h>
#include <boost/filesystem.hpp>
namespace fs = boost::filesystem;


namespace duraark {


bool extractor::extract(const char input_file[], const char output_file[], file_type_t file_type) {
	fs::path input_path(input_file);
	if (!fs::exists(input_path)) {
		std::cout << "Input file \"" + input_path.string() + "\" does not exist" << "\n";
		return false;
	}

	// try to read E57 and extract data
	duraark::e57_metadata_t data;
	try {
		e57::Reader reader(input_path.string().c_str());
		e57::E57Root root;
		reader.GetE57Root(root);
		data.guid = root.guid;
		data.creation_datetime = root.creationDateTime;
		data.version_major = root.versionMajor;
		data.version_minor = root.versionMinor;
		data.coord_metadata = root.coordinateMetadata == std::string("") ? "undefined" : root.coordinateMetadata;
		data.scan_count = reader.GetData3DCount();
		data.image_count = reader.GetImage2DCount();
		data.scan_size = root.data3DSize;
		data.image_size = root.images2DSize;
		for (uint32_t scan = 0; scan < data.scan_count; ++scan) {
			duraark::e57_scan_metadata_t scan_data;
			e57::Data3D scan_header;
			reader.ReadData3D(scan, scan_header);

			scan_data.name = scan_header.name;
			scan_data.guid = scan_header.guid;
			scan_data.original_guids = scan_header.originalGuids;
			scan_data.description = scan_header.description;
			scan_data.sensor_vendor = scan_header.sensorVendor;
			scan_data.sensor_model = scan_header.sensorModel;
			scan_data.sensor_serial_number = scan_header.sensorSerialNumber;
			scan_data.sensor_hardware_version = scan_header.sensorHardwareVersion;
			scan_data.sensor_software_version = scan_header.sensorSoftwareVersion;
			scan_data.sensor_firmware_version = scan_header.sensorFirmwareVersion;
			scan_data.temperature = scan_header.temperature;
			scan_data.relative_humidity = scan_header.relativeHumidity;
			scan_data.atmospheric_pressure = scan_header.atmosphericPressure;
			scan_data.acquisition_start = scan_header.acquisitionStart;
			scan_data.acquisition_end = scan_header.acquisitionEnd;
			scan_data.pose = scan_header.pose;
			scan_data.index_bounds = scan_header.indexBounds;
			scan_data.cartesian_bounds = scan_header.cartesianBounds;
			scan_data.spherical_bounds = scan_header.sphericalBounds;
			scan_data.intensity_limits = scan_header.intensityLimits;
			scan_data.color_limits = scan_header.colorLimits;
			scan_data.point_fields = scan_header.pointFields;
			scan_data.points_size = scan_header.pointsSize;

			data.scans.push_back(scan_data);
		}

		for (uint32_t img = 0; img < data.image_count; ++img) {
			duraark::e57_image_metadata_t img_data;
			e57::Image2D img_header;
			reader.ReadImage2D(img, img_header);

			img_data.name = img_header.name;
			img_data.guid = img_header.guid;
			img_data.description = img_header.description;
			img_data.acquisition_datetime = img_header.acquisitionDateTime;
			img_data.associated_data3D_guid = img_header.associatedData3DGuid;
			img_data.sensor_vendor = img_header.sensorVendor;
			img_data.sensor_model = img_header.sensorModel;
			img_data.sensor_serial_number = img_header.sensorSerialNumber;
			img_data.pose = img_header.pose;
			img_data.visual_ref_representation = img_header.visualReferenceRepresentation;
			img_data.pinhole_representation = img_header.pinholeRepresentation;
			img_data.spherical_representation = img_header.sphericalRepresentation;
			img_data.cylindrical_representation = img_header.cylindricalRepresentation;

			if (img_data.visual_ref_representation.jpegImageSize != 0 || img_data.visual_ref_representation.pngImageSize != 0) img_data.representation = "visual_ref";
			if (img_data.pinhole_representation.jpegImageSize != 0 || img_data.pinhole_representation.pngImageSize != 0) img_data.representation = "pinhole";
			if (img_data.spherical_representation.jpegImageSize != 0 || img_data.spherical_representation.pngImageSize != 0) img_data.representation = "spherical";
			if (img_data.cylindrical_representation.jpegImageSize != 0 || img_data.cylindrical_representation.pngImageSize != 0) img_data.representation = "cylindrical";

			data.images.push_back(img_data);
		}
	} catch (std::exception& ex) {
		std::cout << std::string("Exception catched while loading E57 file:\n") + ex.what();
		return false;
	}

	try {
		return write_file_(output_file, file_type, data);
	} catch (std::exception& e) {
		std::cout << std::string("Unable to write output file:\n") + e.what();
	}
	return false;
}

bool extractor::write_file_(const char output_file[], file_type_t file_type, const e57_metadata_t& data) {
	std::string out_str(output_file);
	{
		// open file for writing
		std::ostream* out;
		if (out_str == "##stdout##") {
			out = &std::cout;
		} else {
			out = new std::ofstream(output_file);
			if (!out->good()) {
				std::cout << "Error while opening \"" + std::string(output_file) + "\" for writing.\n";
				return false;
			}
		}

		// call specific serialization method
		if (file_type == XML) {
			cereal::XMLOutputArchive ar(*out); ar(cereal::make_nvp("e57_metadata", data));
		} else if (file_type == JSON) {
			cereal::JSONOutputArchive ar(*out); ar(cereal::make_nvp("e57_metadata", data));
		} else {
			//data.serialize_csv(out);
		}
		if (out_str != "##stdout##") {
			dynamic_cast<std::ofstream*>(out)->close();
			delete out;
		}
	}

	return true;
}



}