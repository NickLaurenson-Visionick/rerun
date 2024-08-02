# DO NOT EDIT! This file was auto-generated by crates/build/re_types_builder/src/codegen/python/mod.rs
# Based on "crates/store/re_types/definitions/rerun/components/scale3d.fbs".

# You can extend this class by creating a "LeafScale3DExt" class in "leaf_scale3d_ext.py".

from __future__ import annotations

from .. import datatypes
from .._baseclasses import (
    ComponentBatchMixin,
    ComponentMixin,
)
from .leaf_scale3d_ext import LeafScale3DExt

__all__ = ["LeafScale3D", "LeafScale3DBatch", "LeafScale3DType"]


class LeafScale3D(LeafScale3DExt, datatypes.Vec3D, ComponentMixin):
    """
    **Component**: A 3D scale factor that doesn't propagate in the transform hierarchy.

    A scale of 1.0 means no scaling.
    A scale of 2.0 means doubling the size.
    Each component scales along the corresponding axis.
    """

    _BATCH_TYPE = None
    # __init__ can be found in leaf_scale3d_ext.py

    # Note: there are no fields here because LeafScale3D delegates to datatypes.Vec3D
    pass


class LeafScale3DType(datatypes.Vec3DType):
    _TYPE_NAME: str = "rerun.components.LeafScale3D"


class LeafScale3DBatch(datatypes.Vec3DBatch, ComponentBatchMixin):
    _ARROW_TYPE = LeafScale3DType()


# This is patched in late to avoid circular dependencies.
LeafScale3D._BATCH_TYPE = LeafScale3DBatch  # type: ignore[assignment]