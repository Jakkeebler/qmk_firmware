# handwired/arcboard_mk19
![handwired/arcboard_mk19](https://i.imgur.com/WryFchU.jpg)

*KeyDesk? DeskBoard? UltraDorito?*

Introducing ArcBoard mk19, the latest in a line of medical needs-focused input devices that allow you to operate a computer while...
- keeping flat, at-rest hands
- avoiding long keypressses & awkward combinations
- avoiding any kind of 'dedicated mouse/trackball' devices
- minimizing repetitive motions
- accelerating keymap learning through the use of led colours
- doesn't look like a medical device

Specific focus has been applied to maintaining the tension of minimizing combos, button holds, and repetitive motion while not losing out on the benefits of layers and QMK's vast scope of programmability.

Where does it fall 'flat'?
- repetitive mousing is still a challenge, e.g. games (_requires you to still learn a lot of keyboard shortcuts_)
- repetitive movements like scrolling need to be moved to the feet (_which works well!_) or eyes (_something made difficult by the current state of eye tracking tech_)
- you need to understand a bit about QMK, code, and microcontroller flashing to customize it

Despite all of that, as a good anecdote, these boards have enabled me to continue working for over two years now.

# Features
## Ergonomics
- Never move your fingers from homerow yet still mouse using the 34mm thumb trackball and auto-mouse layer.
- Moving functionality from pinkies to thumbs reduces strain.
- Four encoders - two on each half - with generous 70mm backlit knobs allow you to offload repetitive actions.
- Large 1.5u thumb keycaps make for comfortable thumb actioning, with six thumb keys available.
- Grifiti FatMat palm rests (18mm thick neoprene) reach all the way out to the macropad, making every action comfy.

## Functionality
- Right-half has a PMW33xx sensor with a 34mm trackball on NSK roller-bearings.
- Dedicated arrow keys (or any keys) via directional pads at your thumb-tips.
- 51 keys/side [keywell(5x6) + thumbs(6) + 5-way(5) + falcons (2 push-buttons) + macropad (8)]

## Learning
- RGB leds on each button for rapid learning of your custom keymaps.

## Customizability
- The flat encoder panel can be swapped out for another type of device, like a USB SpaceMouse Compact or touchpad.
- The two integrated 8-key macropads allow one-key functions for whatever shortcuts you need. 
- Each keyboard half has two individually addressable 1.25" GC9A01 circular LCDs
- The "slats" lighting is fully customizable via the secret 7-key keyboard under the palm rests.
- A bank of dedicated indicator LEDs allow whatever state you want to be made visible.

## Assembly
- Custom RP2040 microcontroller pcb and flex-pcb interconnect designed to integrate with the Cyboard flex-pcb system
- USB-C connectivity for all external wiring - main usb in, split connection, screen-mounted indicators
- No glue in the assembly, so future customization just a print away.
- Minimal amount of soldering required.
- Open-source models, schematics, and code.

# Development
New learnings on this build were custom pcb design in Kicad, SPI shift-registers and custom QMK matrix code, flex-pcb design, integrated-microcontroller pcb design, learning how to deal with pcb assembly, and working with pcb manufacturer sponsorships.

