#include "data_types.hpp"

#include <cereal/cereal.hpp>
#include <cereal/archives/json.hpp>
#include <cereal/archives/xml.hpp>
#include <cereal/types/vector.hpp>
#include "libe57_serialize.hpp"

namespace duraark {

template <class Archive>
void e57_scan_metadata_t::serialize(Archive& ar) {
	ar(::cereal::make_nvp("name", name),
		::cereal::make_nvp("guid", guid),
		::cereal::make_nvp("original_guids", original_guids),
		::cereal::make_nvp("description", description),
		::cereal::make_nvp("sensor_vendor", sensor_vendor),
		::cereal::make_nvp("sensor_model", sensor_model),
		::cereal::make_nvp("sensor_serial_number", sensor_serial_number),
		::cereal::make_nvp("sensor_hardware_version", sensor_hardware_version),
		::cereal::make_nvp("sensor_software_version", sensor_software_version),
		::cereal::make_nvp("sensor_firmware_version", sensor_firmware_version),
		::cereal::make_nvp("temperature", temperature),
		::cereal::make_nvp("relative_humidity", relative_humidity),
		::cereal::make_nvp("atmospheric_pressure", atmospheric_pressure),
		::cereal::make_nvp("acquisition_start", acquisition_start),
		::cereal::make_nvp("acquisition_end", acquisition_end),
		::cereal::make_nvp("pose", pose),
		::cereal::make_nvp("index_bounds", index_bounds),
		::cereal::make_nvp("cartesian_bounds", cartesian_bounds),
		::cereal::make_nvp("spherical_bounds", spherical_bounds),
		::cereal::make_nvp("intensity_limits", intensity_limits),
		::cereal::make_nvp("color_limits", color_limits),
		::cereal::make_nvp("point_fields", point_fields),
		::cereal::make_nvp("points_size", points_size));
}

template <class Archive>
void e57_image_metadata_t::serialize(Archive& ar) {
	ar(::cereal::make_nvp("name", name),
		::cereal::make_nvp("guid", guid),
		::cereal::make_nvp("description", description),
		::cereal::make_nvp("representation", representation),
		::cereal::make_nvp("acquisition_datetime", acquisition_datetime),
		::cereal::make_nvp("associated_data3D_guid", associated_data3D_guid),
		::cereal::make_nvp("sensor_vendor", sensor_vendor),
		::cereal::make_nvp("sensor_model", sensor_model),
		::cereal::make_nvp("sensor_serial_number", sensor_serial_number),
		::cereal::make_nvp("pose", pose),
		::cereal::make_nvp("visual_ref_representation", visual_ref_representation),
		::cereal::make_nvp("pinhole_representation", pinhole_representation),
		::cereal::make_nvp("spherical_representation", spherical_representation),
		::cereal::make_nvp("cylindrical_representation", cylindrical_representation));
}

template <class Archive>
void e57_metadata_t::serialize(Archive& ar) {
	ar(cereal::make_nvp("guid", guid),
	   cereal::make_nvp("version_major", version_major),
	   cereal::make_nvp("version_minor", version_minor),
	   cereal::make_nvp("creation_datetime", creation_datetime),
	   cereal::make_nvp("coordinate_metadata", coord_metadata),
	   cereal::make_nvp("scan_count", scan_count),
	   cereal::make_nvp("image_count", image_count),
	   cereal::make_nvp("scan_size", scan_size),
	   cereal::make_nvp("image_size", image_size),
	   cereal::make_nvp("scans", scans),
	   cereal::make_nvp("images", images));
}

}


#define X(type) \
	template void duraark::e57_scan_metadata_t::serialize<type>(type& ar); \
	template void duraark::e57_metadata_t::serialize<type>(type& ar);
#include "archive_types.def"