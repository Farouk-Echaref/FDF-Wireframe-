# FDF-Wireframe-
Fils De Fer (Wireframe Model 3D)

<img width="1499" alt="Screen Shot 2023-06-05 at 8 27 01 AM" src="https://github.com/Mushigarou/FDF/assets/115739322/307b3535-3602-4f7f-b67a-93bf4d0f54f5">

FDF is a project that aims to create a wireframe model representation of a 3D landscape by connecting various points using line segments (edges). The program renders the model in an isometric projection.

## Usage

To run the FDF project, follow these steps:
```
$> git clone https://github.com/Mushigarou/FDF.git
$> cd fdf
$> make
$> ./bin/fdf maps/file.fdf
```
## File Format

The coordinates of the landscape are stored in a .fdf file. Each number in the file represents a point in 3D space, where:

- The horizontal position corresponds to the x-axis.
- The vertical position corresponds to the y-axis.
- The value represents the altitude.

Make sure that the .fdf file is properly formatted to avoid unexpected behavior.
## Features

- The program displays the wireframe model in a window.
- Smooth window management allows easy navigation between windows.
- Pressing the ```ESC key or clicking the window's close button``` gracefully closes the program.
- The MiniLibX library is used to handle graphics and images.
- One extra projection parallel! `use p to change projection `
- Zoom in and out. `use - and + signs`
- Translate your model. `use arrow keys`

## Images
<img width="1499" alt="Screen Shot 2023-06-05 at 8 28 11 AM" src="https://github.com/Mushigarou/FDF/assets/115739322/17887a18-d9d2-4b0a-b2e3-baca4bc2c771">

<img width="1499" alt="Screen Shot 2023-06-05 at 8 28 43 AM" src="https://github.com/Mushigarou/FDF/assets/115739322/18ac0962-ac44-4a87-b84b-1b2250764392">

<img width="1499" alt="Screen Shot 2023-06-05 at 8 29 24 AM" src="https://github.com/Mushigarou/FDF/assets/115739322/6314229f-148c-4f1e-97fc-769b142142f4">

<img width="1499" alt="Screen Shot 2023-06-05 at 8 29 48 AM" src="https://github.com/Mushigarou/FDF/assets/115739322/5d24f0e5-c030-436c-92b1-c83da125d575">

## Preview


https://github.com/Farouk-Echaref/FDF-Wireframe-/assets/66710845/c513910e-d640-4f06-a80c-3fdcc3eb93cb



## Contributing

Contributions to this project are welcome! If you find any issues or have improvements to suggest, please feel free to submit a pull request.
