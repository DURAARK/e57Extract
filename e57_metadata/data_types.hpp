#ifndef DURAARK_DATA_TYPES_HPP_
#define DURAARK_DATA_TYPES_HPP_

#include <string>
#include <vector>
#include <e57/E57Simple.h>

namespace duraark {

/** Structure for storing metadata information associated to one single point cloud scan. */
struct e57_scan_metadata_t {
	std::string                            name;
	std::string 	                       guid;
	std::vector<std::string>               original_guids;
	std::string                            description;
	std::string 	                       sensor_vendor;
	std::string 	                       sensor_model;
	std::string 	                       sensor_serial_number;
	std::string 	                       sensor_hardware_version;
	std::string 	                       sensor_software_version;
	std::string 	                       sensor_firmware_version;
	float 	                               temperature;
	float 	                               relative_humidity;
	float 	                               atmospheric_pressure;
	e57::DateTime                          acquisition_start;
	e57::DateTime                          acquisition_end;
	e57::RigidBodyTransform 	           pose;
	e57::IndexBounds 	                   index_bounds;
	e57::CartesianBounds                   cartesian_bounds;
	e57::SphericalBounds                   spherical_bounds;
	e57::IntensityLimits                   intensity_limits;
	e57::ColorLimits                       color_limits;
	e57::PointStandardizedFieldsAvailable  point_fields;
	int64_t 	                           points_size;

	/**
	 *  Serialization function for the cereal c++ library.
	 *
	 *  @tparam Archive Archive type.
	 *  @param: ar Reference to archive object.
	 */
	template <class Archive>
	void serialize(Archive& ar);
};

/** Structure for storing metadata information associated to one single image. */
struct e57_image_metadata_t {
	std::string                            name;
	std::string 	                       guid;
	std::string                            description;
	std::string                            representation;
	e57::DateTime                          acquisition_datetime;
	std::string                            associated_data3D_guid;
	std::string 	                       sensor_vendor;
	std::string 	                       sensor_model;
	std::string 	                       sensor_serial_number;
	e57::RigidBodyTransform 	           pose;
	e57::VisualReferenceRepresentation 	   visual_ref_representation;
	e57::PinholeRepresentation             pinhole_representation;
	e57::SphericalRepresentation           spherical_representation;
	e57::CylindricalRepresentation         cylindrical_representation;

	/**
	 *  Serialization function for the cereal c++ library.
	 *
	 *  @tparam Archive Archive type.
	 *  @param: ar Reference to archive object.
	 */
	template <class Archive>
	void serialize(Archive& ar);
};

/** Structure for storing metadata information associated to the entire e57 cloud file. */
struct e57_metadata_t {
	std::string guid;
	uint32_t version_major;
	uint32_t version_minor;
	e57::DateTime creation_datetime;
	std::string coord_metadata;
	uint32_t scan_count;
	uint32_t image_count;
	uint32_t scan_size;
	uint32_t image_size;
	std::vector<e57_scan_metadata_t> scans;
	std::vector<e57_image_metadata_t> images;

	/**
	 *  Serialization function for the cereal c++ library.
	 *
	 *  @tparam Archive Archive type.
	 *  @param: ar Reference to archive object.
	 */
	template <class Archive>
	void serialize(Archive& ar);
};

}

#endif // DURAARK_DATA_TYPES_HPP_