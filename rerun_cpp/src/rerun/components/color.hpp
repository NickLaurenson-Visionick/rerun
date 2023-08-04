// NOTE: This file was autogenerated by re_types_builder; DO NOT EDIT.
// Based on "crates/re_types/definitions/rerun/components/color.fbs"

#pragma once

#include "../data_cell.hpp"

#include <arrow/type_fwd.h>
#include <cstdint>
#include <utility>

namespace rerun {
    namespace components {
        /// An RGBA color tuple with unmultiplied/separate alpha, in sRGB gamma space with linear
        /// alpha.
        struct Color {
            uint32_t rgba;

            /// Name of the component, used for serialization.
            static const char* NAME;

          public:
            Color(uint32_t rgba) : rgba(std::move(rgba)) {}

            /// Returns the arrow data type this type corresponds to.
            static const std::shared_ptr<arrow::DataType>& to_arrow_datatype();

            /// Creates a new array builder with an array of this type.
            static arrow::Result<std::shared_ptr<arrow::UInt32Builder>> new_arrow_array_builder(
                arrow::MemoryPool* memory_pool
            );

            /// Fills an arrow array builder with an array of this type.
            static arrow::Status fill_arrow_array_builder(
                arrow::UInt32Builder* builder, const Color* elements, size_t num_elements
            );

            /// Creates a Rerun DataCell from an array of Color components.
            static arrow::Result<rerun::DataCell> to_data_cell(
                const Color* instances, size_t num_instances
            );
        };
    } // namespace components
} // namespace rerun