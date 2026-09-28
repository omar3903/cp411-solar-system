# CP411 Project: Interactive 3D Solar System Simulation
**Authors and Student ID**: 
- Dylan Atkinson
- Basleal ABshiro
- Omar Abdeen

**Date**: 2024-11-23

## Introduction

The proposed project is an Interactive 3D Solar System Simulation that will visualize the movement of planets around the sun. The system will allow users to view the solar system from different perspectives, toggle the planetary orbits, and adjust the simulation speed. The project provides a way to explore planetary motion and showcases the creative implementation of OpenGL features.

The primary goal of this project is to simulate the orbital mechanics of planets using circular motion algorithms, display realistic 3D models of celestial bodies, and enable interactivity. This project is manageable within the timeframe and uses knowledge of the previously developed tools (SimpleView) as the baseline system.

## Problem Solving and Algorithms

The main computational challenges include:

1. **Orbital Mechanics**: Simulating a circular or elliptical motion using parametric equations.
    - Position (x, y, z):
    - x = r · cos(θ), y = 0, z = r · sin(θ)
    - where r is the orbital radius, and θ increases over time to simulate movement.

2. **Lighting and Texture Mapping**: Creating a realistic rendering of planets with OpenGL's lighting models and texture mapping for surfaces.

3. **Interactivity**: Implementing user input to adjust the simulation speed and toggle orbits using OpenGL callbacks for mouse and keyboard events.

## Design Consideration

The system will follow the Model-View-Controller (MVC) architecture:

- **Model**: Represents the planetary data (size, orbit radius, textures).
- **View**: Handles rendering using OpenGL's 3D graphics pipeline.
- **Controller**: Manages user input to control the simulation.

Key design features include:

- **Dynamic Camera**: A movable camera to allow different perspectives of the solar system.
- **Planetary Textures**: Adding realistic textures for each planet using OpenGL texture mapping.
- **Toggle Features**: Orbit paths and speed adjustments for user interactivity.

## Milestones & Schedule

| Task ID | Description | Due Date | Lead |
|---------|-------------|-----------|-------|
| 1 | Research & team formation | Day 7 of week 10 | Dylan |
| 2 | Proposal submission | Day 6 of week 11 | Dylan |
| 3 | Basic system setup (planet models, orbit logic) | Day 7 of week 11 | Dylan |
| 4 | Interactive features (camera, user inputs) | Day 3 of week 12 | Dylan |
| 5 | Testing and debugging | Day 5 of week 12 | Dylan |
| 6 | Final demonstration and submission | Day 7 of week 12 | Dylan |

## References

1. OpenGL Code from lectures given throughout the CP411 course.
2. Solar System Simulation Example: [https://www.geeksforgeeks.org/c-program-to-draw-a-solar-system-using-computer-graphics/](https://www.geeksforgeeks.org/c-program-to-draw-a-solar-system-using-computer-graphics/)
3. SimpleView Framework Documentation from CP411 Assignments.

---

This proposal aims to balance simplicity with creativity. This will ensure that the project is both feasible and aligns with our course requirements and expectations. The interactive solar system leverages OpenGL features, applies learned techniques, texture mapping, and explores new elements such as dynamic user interactivity.
