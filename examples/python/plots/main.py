#!/usr/bin/env python3
"""
Demonstrates how to log simple plots with the Rerun SDK.

Run:
```sh
./examples/python/plot/main.py
```
"""
from __future__ import annotations

import argparse
import random
from math import cos, sin, tau

import numpy as np
import rerun as rr  # pip install rerun-sdk


def clamp(n, smallest, largest):  # type: ignore[no-untyped-def]
    return max(smallest, min(n, largest))


def log_bar_chart() -> None:
    rr.set_time_sequence("frame_nr", 0)
    # Log a gauss bell as a bar chart
    mean = 0
    std = 1
    variance = np.square(std)
    x = np.arange(-5, 5, 0.1)
    y = np.exp(-np.square(x - mean) / 2 * variance) / (np.sqrt(2 * np.pi * variance))
    rr.log("bar_chart", rr.BarChart(y))


def log_parabola() -> None:
    # Log a parabola as a time series
    for t in range(0, 1000, 10):
        rr.set_time_sequence("frame_nr", t)

        f_of_t = (t * 0.01 - 5) ** 3 + 1
        radius = clamp(abs(f_of_t) * 0.1, 0.5, 10.0)
        color = [255, 255, 0]
        if f_of_t < -10.0:
            color = [255, 0, 0]
        elif f_of_t > 10.0:
            color = [0, 255, 0]

        rr.log(
            "curves/parabola",
            rr.TimeSeriesScalar(
                f_of_t,
                label="f(t) = (0.01t - 3)³ + 1",
                radius=radius,
                color=color,
            ),
        )


def log_trig() -> None:
    # Log a time series
    for t in range(0, int(tau * 2 * 100.0)):
        rr.set_time_sequence("frame_nr", t)

        sin_of_t = sin(float(t) / 100.0)
        rr.log("trig/sin", rr.TimeSeriesScalar(sin_of_t, label="sin(0.01t)", color=[255, 0, 0]))

        cos_of_t = cos(float(t) / 100.0)
        rr.log("trig/cos", rr.TimeSeriesScalar(cos_of_t, label="cos(0.01t)", color=[0, 255, 0]))


def log_segmentation() -> None:
    # Log a time series
    for t in range(0, 1000, 2):
        rr.set_time_sequence("frame_nr", t)

        f_of_t = (2 * 0.01 * t) + 2
        color = [255, 255, 0]
        rr.log("segmentation/line", rr.TimeSeriesScalar(f_of_t, color=color, radius=3.0))

        g_of_t = f_of_t + random.uniform(-5.0, 5.0)
        if g_of_t < f_of_t - 1.5:
            color = [255, 0, 0]
        elif g_of_t > f_of_t + 1.5:
            color = [0, 255, 0]
        else:
            color = [255, 255, 255]
        radius = abs(g_of_t - f_of_t)
        rr.log("segmentation/samples", rr.TimeSeriesScalar(g_of_t, color=color, scattered=True, radius=radius))


def main() -> None:
    parser = argparse.ArgumentParser(
        description="demonstrates how to integrate python's native `logging` with the Rerun SDK"
    )
    rr.script_add_args(parser)
    args = parser.parse_args()

    rr.script_setup(args, "rerun_example_plot")

    log_bar_chart()
    log_parabola()
    log_trig()
    log_segmentation()

    rr.script_teardown(args)


if __name__ == "__main__":
    main()
