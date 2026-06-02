# Step-Up Radar Point Offset Table Design

## Goal

Add a small C++ data table that lists every allowed low-to-high step edge in the plum
blossom forest map. Each radar trigger point is stored as an offset from the calibrated
`0 -> 2` front-edge midpoint `(x, y)`, so a new field calibration changes only one
base coordinate.

## Map And Coordinate Convention

The square layout is:

```text
      entrance 0
3   2   1
6   5   4
9   8   7
12  11  10
      exit 13
```

- Each square is `1.2 m` wide.
- Moving from the entrance toward the exit increases `x`.
- Moving left increases `y`.
- `(x, y)` is the front-edge midpoint used by the radar for `0 -> 2`.
- A forward edge midpoint changes `x` by a whole square width.
- A horizontal edge midpoint changes both axes by half a square width (`0.6 m`).
- The table includes forward and horizontal low-to-high moves only. It excludes
  backward moves and diagonal moves.

The square heights are:

```text
40 cm  20 cm  40 cm
60 cm  40 cm  20 cm
40 cm  60 cm  40 cm
20 cm  40 cm  20 cm
```

## Offset Table

The table stores offsets `offset_x` and `offset_y`, not absolute coordinates.
The runtime radar target for an entry is:

```text
(base_x + offset_x, base_y + offset_y)
```

| Step edge | `offset_x` | `offset_y` |
|---|---:|---:|
| `0 -> 2` | `0.0` | `0.0` |
| `2 -> 3` | `0.6` | `0.6` |
| `2 -> 1` | `0.6` | `-0.6` |
| `2 -> 5` | `1.2` | `0.0` |
| `3 -> 6` | `1.2` | `1.2` |
| `4 -> 5` | `1.8` | `-0.6` |
| `5 -> 6` | `1.8` | `0.6` |
| `4 -> 7` | `2.4` | `-1.2` |
| `5 -> 8` | `2.4` | `0.0` |
| `7 -> 8` | `3.0` | `-0.6` |
| `9 -> 8` | `3.0` | `0.6` |
| `10 -> 11` | `4.2` | `-0.6` |
| `12 -> 11` | `4.2` | `0.6` |

## C++ Shape

Add a `StepUpPointOffset` structure with:

- `from_square`
- `to_square`
- `offset_x`
- `offset_y`

Add one constant array containing the thirteen rows above. Add `base_x` and `base_y`
constants beside the table as the only values intended for direct field calibration.
Keep this as reference data only; do not change the existing turtlesim timer behavior.

The Chinese problem statement currently pasted after the final closing brace in
`turtle_circle.cpp` must be converted into a valid comment or replaced by a concise
comment, because raw text after the C++ program prevents compilation.

## Verification

1. Build the `demo_cpp_topic` package with `colcon build --packages-select demo_cpp_topic`.
2. Confirm that all thirteen expected low-to-high edges appear exactly once.
3. Confirm that changing only `base_x` and `base_y` shifts all computed trigger points
   without editing the offset rows.
