# B-MUL-200-REN-2-1-myworld-pierre.hamel

A terrain generation simulator created in CSFML

USAGE
  - make
  - ./my_world
  - ./my_world [path_to_map]
  - ./my_world [path_to_map] --image

OPTIONS
  - Edit terrain hight
  - Edit terrain color/textures
  - Edit map size
  - Edit map isometric angles
  - Generate a new flat map
  - Generate a new map with perlin noise
  - Switch between rendering mods (textures, colors, nothing)
  - Activate line rendering
  - Switch between draw mod and terrain edit mod
  - Activate single point selection

COMMANDS
  - crtl + S = Save map
  - crtl + O = Increase map on x axis
  - crtl + L = Decrease map on x axis
  - crtl + P = Increase map on y axis
  - crtl + M = Decrease map on y axis
  - R = Create new flat map
  - T = Create new perlin map
  - Arrow Keys = Move
  - Page up/down = Zoom in/out
  - Scroll = Change selection size
  - Left click = Edit terrain up / Apply selected color
  - Right click = Edit terrain down
  - Enter = hide buttons

BONUS
  - Image rendering of saved maps
  - OpenGL shaders on water (dig straight down to see the water)
  - You can paint the map when you change mode
  - When you quit the "--image" mode, an image is saved in the path asset/image_map/image.png

REQUIREMENT
  - CSFML v-2.5.1
    - Take care to have the good version of CSFML
