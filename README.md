# ✴️ fract-ol ![Static Badge](https://img.shields.io/badge/Barcelona-black?style=for-the-badge&logo=42&logoColor=%23FFFFFF)
![Static Badge](https://img.shields.io/badge/c-grey?style=flat&logo=c)
![Static Badge](https://img.shields.io/badge/Makefile-green?style=flat&logo=AnkerMake)
![Static Badge](https://img.shields.io/badge/status-completed-green?style=flat)
```output
███████╗██████╗  █████╗  ██████╗████████╗    ██████╗ ██╗
██╔════╝██╔══██╗██╔══██╗██╔════╝╚══██╔══╝   ██╔═══██╗██║
█████╗  ██████╔╝███████║██║        ██║█████╗██║   ██║██║
██╔══╝  ██╔══██╗██╔══██║██║        ██║╚════╝██║   ██║██║
██║     ██║  ██║██║  ██║╚██████╗   ██║      ╚██████╔╝███████╗
╚═╝     ╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝   ╚═╝       ╚═════╝ ╚══════╝
```
A program to visualize the Mandelbrot and Julia fractals with 42's Minilibx

## ⚒️ Compilation
Firstly, copy the repository into you computer directory

```bash
git clone https://github.com/alexpg7/fract-ol.git fract-ol && cd fract-ol
```

Once copied, just execute the `make` command

```bash
make
```

> [!WARNING]
> The **mlx_linux/configure** file can lead to some problems during the compilation.
> 
> To solve them, execute
> ```bash
> chmod 777 mlx_linux/configure
> ```
> And make sure to execute `make` multiple times until the executable **``fractol``** is created. (These errors are a minilibx issue, which was not programmed by me)

Finally, execute the program to see the instructions. It should output these ones:

```output
No fractal selected.

- Available parameters:

	- Fractals: [Mandelbrot, Julia x y]
		('x' and 'y' are the initial values of Julia set)
	- X-window resolution (pixels)
	- Y-window resolution (pixels)
```
## ❓ How to use it

Execute the program with the ``Mandelbrot`` or ``Julia x y`` arguments, where ``x`` and ``y`` are the real and imaginary components of the initial iteration of the Julia fractal, given by $z=x+iy$. As extra arguments, you can give it the resolution of the window in pixels (if not specified, it will be set to $1080\times 1920\text{px}$

Once executed, it will pop up a new window with the fractal in a red color scale. The controls will also be printed in the standard output:

```output
	- CONTROLS:

	ARROWS:		move
	MOUSE SCROLL:	zoom
	'ESC':		exit program
	'M':		more resolution
	'N':		less resolution
```

## ✏️ Example

We can visualize the Julia set for some interesting points, like $0+0.8i$ or $-0.8-0.25i$. For example, for the first one:

```bash
./fractol Julia 0 0.8 1080 720
```

![til](https://github.com/alexpg7/Images/blob/main/fract-ol/julia.png)

We can zoom in or move with arrows to explore (almost) the infinite points that this set offers us :D

## ⚠️ Limitations

Since this program uses ``float`` as the datatype to do calculations, at some point the resolution of the fractal will be lost completely. This is due to the fact that floats cannot give more precision once reached $1.17549435\cdot 10^{-38}$. The consequence is that we see a pixel-like structure in the fractal. This is just the consequence of the imprecision of the computer, do not dare to blame mathematics!

![til](https://github.com/alexpg7/Images/blob/main/fract-ol/precision.png)
