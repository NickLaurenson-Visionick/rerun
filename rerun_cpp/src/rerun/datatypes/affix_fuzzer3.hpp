// NOTE: This file was autogenerated by re_types_builder; DO NOT EDIT.
// Based on "crates/re_types/definitions/rerun/testing/datatypes/fuzzy.fbs"

#pragma once

#include "../datatypes/affix_fuzzer1.hpp"

#include <arrow/type_fwd.h>
#include <cstdint>
#include <cstring>
#include <new>
#include <optional>
#include <utility>
#include <vector>

namespace rerun {
    namespace datatypes {
        namespace detail {
            enum class AffixFuzzer3Tag {
                /// Having a special empty state makes it possible to implement move-semantics. We
                /// need to be able to leave the object in a state which we can run the destructor
                /// on.
                NONE = 0,
                degrees,
                radians,
                craziness,
                fixed_size_shenanigans,
            };

            union AffixFuzzer3Data {
                float degrees;

                std::optional<float> radians;

                std::vector<rerun::datatypes::AffixFuzzer1> craziness;

                float fixed_size_shenanigans[3];

                AffixFuzzer3Data() {}

                ~AffixFuzzer3Data() {}

                void swap(AffixFuzzer3Data& other) noexcept {
                    // This bitwise swap would fail for self-referential types, but we don't have
                    // any of those.
                    char temp[sizeof(AffixFuzzer3Data)];
                    std::memcpy(temp, this, sizeof(AffixFuzzer3Data));
                    std::memcpy(this, &other, sizeof(AffixFuzzer3Data));
                    std::memcpy(&other, temp, sizeof(AffixFuzzer3Data));
                }
            };
        } // namespace detail

        struct AffixFuzzer3 {
            AffixFuzzer3(const AffixFuzzer3& other) : _tag(other._tag) {
                switch (other._tag) {
                    case detail::AffixFuzzer3Tag::craziness: {
                        _data.craziness = other._data.craziness;
                        break;
                    }
                    default:
                        memcpy(&this->_data, &other._data, sizeof(detail::AffixFuzzer3Data));
                        break;
                }
            }

            AffixFuzzer3& operator=(const AffixFuzzer3& other) noexcept {
                AffixFuzzer3 tmp(other);
                this->swap(tmp);
                return *this;
            }

            AffixFuzzer3(AffixFuzzer3&& other) noexcept : _tag(detail::AffixFuzzer3Tag::NONE) {
                this->swap(other);
            }

            AffixFuzzer3& operator=(AffixFuzzer3&& other) noexcept {
                this->swap(other);
                return *this;
            }

            ~AffixFuzzer3() {
                switch (this->_tag) {
                    case detail::AffixFuzzer3Tag::NONE: {
                        break; // Nothing to destroy
                    }
                    case detail::AffixFuzzer3Tag::degrees: {
                        break; // has a trivial destructor
                    }
                    case detail::AffixFuzzer3Tag::radians: {
                        break; // has a trivial destructor
                    }
                    case detail::AffixFuzzer3Tag::craziness: {
                        typedef std::vector<rerun::datatypes::AffixFuzzer1> TypeAlias;
                        _data.craziness.~TypeAlias();
                        break;
                    }
                    case detail::AffixFuzzer3Tag::fixed_size_shenanigans: {
                        break; // has a trivial destructor
                    }
                }
            }

            void swap(AffixFuzzer3& other) noexcept {
                auto tag_temp = this->_tag;
                this->_tag = other._tag;
                other._tag = tag_temp;
                this->_data.swap(other._data);
            }

            static AffixFuzzer3 degrees(float degrees) {
                AffixFuzzer3 self;
                self._tag = detail::AffixFuzzer3Tag::degrees;
                self._data.degrees = std::move(degrees);
                return std::move(self);
            }

            static AffixFuzzer3 radians(std::optional<float> radians) {
                AffixFuzzer3 self;
                self._tag = detail::AffixFuzzer3Tag::radians;
                self._data.radians = std::move(radians);
                return std::move(self);
            }

            static AffixFuzzer3 craziness(std::vector<rerun::datatypes::AffixFuzzer1> craziness) {
                typedef std::vector<rerun::datatypes::AffixFuzzer1> TypeAlias;
                AffixFuzzer3 self;
                self._tag = detail::AffixFuzzer3Tag::craziness;
                new (&self._data.craziness) TypeAlias(std::move(craziness));
                return std::move(self);
            }

            static AffixFuzzer3 fixed_size_shenanigans(float fixed_size_shenanigans[3]) {
                typedef float TypeAlias;
                AffixFuzzer3 self;
                self._tag = detail::AffixFuzzer3Tag::fixed_size_shenanigans;
                for (size_t i = 0; i < 3; i += 1) {
                    self._data.fixed_size_shenanigans[i] = std::move(fixed_size_shenanigans[i]);
                }
                return std::move(self);
            }

            /// Returns the arrow data type this type corresponds to.
            static const std::shared_ptr<arrow::DataType>& to_arrow_datatype();

            /// Creates a new array builder with an array of this type.
            static arrow::Result<std::shared_ptr<arrow::DenseUnionBuilder>> new_arrow_array_builder(
                arrow::MemoryPool* memory_pool
            );

            /// Fills an arrow array builder with an array of this type.
            static arrow::Status fill_arrow_array_builder(
                arrow::DenseUnionBuilder* builder, const AffixFuzzer3* elements, size_t num_elements
            );

          private:
            detail::AffixFuzzer3Tag _tag;
            detail::AffixFuzzer3Data _data;

            AffixFuzzer3() : _tag(detail::AffixFuzzer3Tag::NONE) {}

          public:
        };
    } // namespace datatypes
} // namespace rerun