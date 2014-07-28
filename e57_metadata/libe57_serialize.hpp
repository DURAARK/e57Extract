#ifndef DURAARK_LIBE57_SERIALIZE_HPP_
#define DURAARK_LIBE57_SERIALIZE_HPP_

#include <e57/E57Simple.h>

namespace cereal {

/**
  *  Serialization function for the cereal library
  */
template <class Archive>
void load(Archive& ar, ::e57::DateTime& dt) {
	int year, month, day, hour, minute;
	float seconds;
	ar(cereal::make_nvp("year", year),
		cereal::make_nvp("month", month),
		cereal::make_nvp("day", day),
		cereal::make_nvp("hour", hour),
		cereal::make_nvp("minute", minute),
		cereal::make_nvp("seconds", seconds));
	dt.SetUTCDateTime(year, month, day, hour, minute, seconds);
}

/**
  *  Serialization function for the cereal library
  */
template <class Archive>
void save(Archive& ar, const ::e57::DateTime& dt) {
	int year, month, day, hour, minute;
	float seconds;
	dt.GetUTCDateTime(year, month, day, hour, minute, seconds);
	ar(cereal::make_nvp("year", year),
		cereal::make_nvp("month", month),
		cereal::make_nvp("day", day),
		cereal::make_nvp("hour", hour),
		cereal::make_nvp("minute", minute),
		cereal::make_nvp("seconds", seconds));
}

/**
  *  Serialization function for the cereal library
  */
template <class Archive>
void serialize(Archive& ar, ::e57::Quaternion& q) {
	ar(cereal::make_nvp("w", q.w),
		cereal::make_nvp("x", q.x),
		cereal::make_nvp("y", q.y),
		cereal::make_nvp("z", q.z));
}

/**
  *  Serialization function for the cereal library
  */
template <class Archive>
void serialize(Archive& ar, ::e57::Translation& t) {
	ar(cereal::make_nvp("x", t.x),
		cereal::make_nvp("y", t.y),
		cereal::make_nvp("z", t.z));
}

/**
  *  Serialization function for the cereal library
  */
template <class Archive>
void serialize(Archive& ar, ::e57::RigidBodyTransform& t) {
	ar(cereal::make_nvp("rotation", t.rotation),
		cereal::make_nvp("translation", t.translation));
}

/**
  *  Serialization function for the cereal library
  */
template <class Archive>
void serialize(Archive& ar, ::e57::IndexBounds& b) {
	ar(cereal::make_nvp("row_minimum", b.rowMinimum),
		cereal::make_nvp("row_maximum", b.rowMaximum),
		cereal::make_nvp("col_minimum", b.columnMinimum),
		cereal::make_nvp("col_maximum", b.columnMaximum),
		cereal::make_nvp("return_minimum", b.returnMinimum),
		cereal::make_nvp("return_maximum", b.returnMaximum));
}

/**
  *  Serialization function for the cereal library
  */
template <class Archive>
void serialize(Archive& ar, ::e57::CartesianBounds& b) {
	ar(cereal::make_nvp("x_minimum", b.xMinimum),
		cereal::make_nvp("x_maximum", b.xMaximum),
		cereal::make_nvp("y_minimum", b.yMinimum),
		cereal::make_nvp("y_maximum", b.yMaximum),
		cereal::make_nvp("z_minimum", b.zMinimum),
		cereal::make_nvp("z_maximum", b.zMaximum));
}

/**
  *  Serialization function for the cereal library
  */
template <class Archive>
void serialize(Archive& ar, ::e57::SphericalBounds& b) {
	ar(cereal::make_nvp("range_minimum", b.rangeMinimum),
		cereal::make_nvp("range_maximum", b.rangeMaximum),
		cereal::make_nvp("elevation_minimum", b.elevationMinimum),
		cereal::make_nvp("elevation_maximum", b.elevationMaximum),
		cereal::make_nvp("azimuth_minimum", b.azimuthStart),
		cereal::make_nvp("azimuth_maximum", b.azimuthEnd));
}

/**
  *  Serialization function for the cereal library
  */
template <class Archive>
void serialize(Archive& ar, ::e57::IntensityLimits& l) {
	ar(cereal::make_nvp("intensity_minimum", l.intensityMinimum),
		cereal::make_nvp("intensity_maximum", l.intensityMaximum));
}

/**
  *  Serialization function for the cereal library
  */
template <class Archive>
void serialize(Archive& ar, ::e57::ColorLimits& l) {
	ar(cereal::make_nvp("color_red_minimum", l.colorRedMinimum),
		cereal::make_nvp("color_red_maximum", l.colorRedMaximum),
		cereal::make_nvp("color_green_minimum", l.colorGreenMinimum),
		cereal::make_nvp("color_green_maximum", l.colorGreenMaximum),
		cereal::make_nvp("color_blue_minimum", l.colorBlueMinimum),
		cereal::make_nvp("color_blue_maximum", l.colorBlueMaximum));
}

/**
  *  Serialization function for the cereal library
  */
template <class Archive>
void serialize(Archive& ar, ::e57::PointStandardizedFieldsAvailable& f) {
	ar( cereal::make_nvp("cartesian_x_field", f.cartesianXField),
		cereal::make_nvp("cartesian_y_field", f.cartesianYField),
		cereal::make_nvp("cartesian_z_field", f.cartesianZField),
		cereal::make_nvp("cartesian_invalid_state_field", f.cartesianInvalidStateField),
		cereal::make_nvp("spherical_range_field", f.sphericalRangeField),
		cereal::make_nvp("spherical_azimuth_field", f.sphericalAzimuthField),
		cereal::make_nvp("spherical_elevation_field", f.sphericalElevationField),
		cereal::make_nvp("spherical_invalid_state_field", f.sphericalInvalidStateField),
		cereal::make_nvp("point_range_minimum", f.pointRangeMinimum),
		cereal::make_nvp("point_range_maximum", f.pointRangeMaximum),
		cereal::make_nvp("point_range_scaled_integer", f.pointRangeScaledInteger),
		cereal::make_nvp("angle_minimum", f.angleMinimum),
		cereal::make_nvp("angle_maximum", f.angleMaximum),
		cereal::make_nvp("angle_scaled_integer", f.angleScaledInteger),
		cereal::make_nvp("row_index_field", f.rowIndexField),
		cereal::make_nvp("row_index_maximum", f.rowIndexMaximum),
		cereal::make_nvp("column_index_field", f.columnIndexField),
		cereal::make_nvp("column_index_maximum", f.columnIndexMaximum),
		cereal::make_nvp("return_index_field", f.returnIndexField),
		cereal::make_nvp("return_count_field", f.returnCountField),
		cereal::make_nvp("return_maximum", f.returnMaximum),
		cereal::make_nvp("time_stamp_field", f.timeStampField),
		cereal::make_nvp("is_Time_Stamp_Invalid_field", f.isTimeStampInvalidField),
		cereal::make_nvp("time_Maximum", f.timeMaximum),
		cereal::make_nvp("intensity_field", f.intensityField),
		cereal::make_nvp("is_intensity_invalid_field", f.isIntensityInvalidField),
		cereal::make_nvp("intensity_scaled_integer", f.intensityScaledInteger),
		cereal::make_nvp("color_red_field", f.colorRedField),
		cereal::make_nvp("color_green_field", f.colorGreenField),
		cereal::make_nvp("color_blue_field", f.colorBlueField),
		cereal::make_nvp("is_color_invalid_field", f.isColorInvalidField));
}

template <class Archive>
void serialize(Archive& ar, ::e57::VisualReferenceRepresentation& r) {
	ar(cereal::make_nvp("jpeg_image_size", r.jpegImageSize),
		cereal::make_nvp("png_image_size", r.pngImageSize),
		cereal::make_nvp("image_mask_size", r.imageMaskSize),
		cereal::make_nvp("image_width", r.imageWidth),
		cereal::make_nvp("image_height", r.imageHeight));
}

template <class Archive>
void serialize(Archive& ar, ::e57::PinholeRepresentation& r) {
	ar(cereal::make_nvp("jpeg_image_size", r.jpegImageSize),
		cereal::make_nvp("png_image_size", r.pngImageSize),
		cereal::make_nvp("image_mask_size", r.imageMaskSize),
		cereal::make_nvp("image_width", r.imageWidth),
		cereal::make_nvp("image_height", r.imageHeight),
		cereal::make_nvp("focal_length", r.focalLength),
		cereal::make_nvp("pixel_width", r.pixelWidth),
		cereal::make_nvp("pixel_height", r.pixelHeight),
		cereal::make_nvp("principal_point_x", r.principalPointX),
		cereal::make_nvp("principal_point_y", r.principalPointY)
		);
}

template <class Archive>
void serialize(Archive& ar, ::e57::SphericalRepresentation& r) {
	ar(cereal::make_nvp("jpeg_image_size", r.jpegImageSize),
		cereal::make_nvp("png_image_size", r.pngImageSize),
		cereal::make_nvp("image_mask_size", r.imageMaskSize),
		cereal::make_nvp("image_width", r.imageWidth),
		cereal::make_nvp("image_height", r.imageHeight),
		cereal::make_nvp("pixel_width", r.pixelWidth),
		cereal::make_nvp("pixel_height", r.pixelHeight)
		);
}

template <class Archive>
void serialize(Archive& ar, ::e57::CylindricalRepresentation& r) {
	ar(cereal::make_nvp("jpeg_image_size", r.jpegImageSize),
		cereal::make_nvp("png_image_size", r.pngImageSize),
		cereal::make_nvp("image_mask_size", r.imageMaskSize),
		cereal::make_nvp("image_width", r.imageWidth),
		cereal::make_nvp("image_height", r.imageHeight),
		cereal::make_nvp("pixel_width", r.pixelWidth),
		cereal::make_nvp("pixel_height", r.pixelHeight),
		cereal::make_nvp("radius", r.radius),
		cereal::make_nvp("principal_point_y", r.principalPointY)
		);
}


} // cereal


#endif // DURAARK_LIBE57_SERIALIZE_HPP_