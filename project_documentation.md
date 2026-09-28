# Solar System Simulation Project Documentation

**Authors and Student ID**: 
- Dylan Atkinson
- Basleal ABshiro
- Omar Abdeen

## Technical Documentation

### System Architecture
The project follows MVC (Model-View-Controller) architecture:
- **Model**: Solar.cpp/hpp - Handles planetary data and physics
- **View**: Sphere.cpp/hpp - Manages rendering and display
- **Controller**: Menu.cpp/hpp - Processes user input

### Class Structure
1. **Solar Class**
   - Manages celestial bodies and their relationships
   - Handles orbital calculations
   - Updates positions

2. **Sphere Class**
   - Renders 3D spheres
   - Manages textures
   - Handles lighting and materials

3. **Camera Class**
   - Controls view perspective
   - Manages camera movement
   - Handles zoom and rotation

4. **Light Class**
   - Controls lighting conditions
   - Manages light position
   - Sets lighting parameters

### Setup Instructions
1. Install prerequisites:
   ```bash
   - Install MinGW
   - Set up OpenGL libraries
   - Install FreeGLUT
   ```

2. Project setup:
   ```bash
   - Clone repository
   - Create 'textures' folder
   - Add texture files (sun.bmp, earth.bmp, moon.bmp)
   ```

## 2. User Guide

### Controls
- **Mouse Controls**:
  - Left click + drag: Rotate camera
  - Right click: Menu options
  - Scroll: Zoom in/out

- **Keyboard Controls**:
  - W/S: Camera up/down
  - A/D: Camera left/right
  - Q/E: Zoom in/out
  - R: Reset camera
  - O: Toggle orbit paths
  - +/-: Adjust simulation speed