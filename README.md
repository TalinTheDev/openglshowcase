# OpenGl Tests

This repository holds a bunch of different (probably random) rendering tests I made using OpenGL. Keep in mind that
while doing all this, I am currently learning OpenGL so most of this is not useful for production anything due to
optimization issues and what not.

But it's a way for me to try things out myself outside the absolutely *amazing* [learnopengl.com
tutorial](http://learnopengl.com).


## Dev

To setup `compile_commands.json`:
```bash
cmake -S . -B build
ln -s build/compile_commands.json .
```

## Roadmap
I want to be able to use this by opening a menu and being able to add various *things* to the scene.

Example:
- Add a 2D triangle, change its position, color, and maybe even edit vertex data.
- Add a 3D cube, change its position, color, and maybe even edit vertex data.
- Add a 3D camera

In `main.cpp`:
- Array of scene *objects* (e.g. triangle, cube)
- Array of scene *systems* (e.g. camera, sky)

- Loop through objects and call `render()` on each
- Loop through systems and call `run()` on each

In the `Object` class:
- `setup()`
- `render()`
- `destroy()`

In the `System` class:
- `setup()`
- `run()`
- `destroy()`
