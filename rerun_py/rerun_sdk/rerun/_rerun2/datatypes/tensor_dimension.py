# NOTE: This file was autogenerated by re_types_builder; DO NOT EDIT.

from __future__ import annotations

from typing import Sequence, Union

import pyarrow as pa
from attrs import define, field

from .._baseclasses import (
    BaseExtensionArray,
    BaseExtensionType,
)
from .._converters import (
    str_or_none,
)

__all__ = [
    "TensorDimension",
    "TensorDimensionArray",
    "TensorDimensionArrayLike",
    "TensorDimensionLike",
    "TensorDimensionType",
]


@define
class TensorDimension:
    """A single dimension within a multi-dimensional tensor."""

    size: int = field(converter=int)
    name: str | None = field(default=None, converter=str_or_none)


TensorDimensionLike = TensorDimension
TensorDimensionArrayLike = Union[
    TensorDimension,
    Sequence[TensorDimensionLike],
]


# --- Arrow support ---


class TensorDimensionType(BaseExtensionType):
    def __init__(self) -> None:
        pa.ExtensionType.__init__(
            self,
            pa.struct(
                [
                    pa.field("size", pa.uint64(), nullable=False, metadata={}),
                    pa.field("name", pa.utf8(), nullable=True, metadata={}),
                ]
            ),
            "rerun.datatypes.TensorDimension",
        )


class TensorDimensionArray(BaseExtensionArray[TensorDimensionArrayLike]):
    _EXTENSION_NAME = "rerun.datatypes.TensorDimension"
    _EXTENSION_TYPE = TensorDimensionType

    @staticmethod
    def _native_to_pa_array(data: TensorDimensionArrayLike, data_type: pa.DataType) -> pa.Array:
        raise NotImplementedError


TensorDimensionType._ARRAY_TYPE = TensorDimensionArray

# TODO(cmc): bring back registration to pyarrow once legacy types are gone
# pa.register_extension_type(TensorDimensionType())