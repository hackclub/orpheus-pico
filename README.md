# Orpheus Pico 2

### Hack Club's Flagship Microcontroller

![banner image](https://cdn.hackclub.com/019c5454-4d86-78af-80d0-e447d5894a78/_70104768-5015-42e8-b1ec-89713ee45285_.png)

Welcome! This is the newest edition of the Orpheus Pico - an RP2040-based development board, similar to a Raspberry Pi Pico.

## Features

The Orpheus Pico 2 features:

- Identical footprint to the Raspberry Pi Pico
- an RP2040 microcontroller
- 32 addressable GPIO pins
- onboard active-high LED (IO25)
- onboard RGB LED (IO24)
- USB-C connection
- high-current power lines
- and more!

## What's Different?

There have been many major changes from earlier versions of the Orpheus Pico! Several notable ones are:

- epic new silkscreen!
- higher power capability (thickened a bunch of power traces that caused overheating)
- new voltage regulator which doesn't overheat
- dimmed the onboard leds
- significantly improved grounding, meaning lower-impedance path to ground
- made the crystal on the rp2040 more stable
- general cleanup of routing and components

| Previous Orpheus Pico                                                                                                                             | Latest Orpheus Pico                                                                                                                               |
| ------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------- |
| <img src="https://cdn.hackclub.com/019c545d-06b4-7870-8304-50c3f775f1f8/_fb1148c1-2daf-466b-bcb7-04b470788b5b_.png" width="300" alt="old board"/> | <img src="https://cdn.hackclub.com/019c5450-5932-737b-908f-54818d81e987/_b638822d-f8d2-4200-8548-4a8502d05596_.png" width="300" alt="new board"/> |

## Usage

Usage of the Orpheus Pico almost completely matches that of a Raspberry Pi Pico. You can use several different frameworks, such as the Pico SDK in C++, Arduino, or Micro/Circuitpython. Some board specific stuff:

- onboard active-high LED on IO25
- onboard RGB LED on IO24
- user-configurable button on IO23 (use a pullup in code)

The RGB led can be controlled as a typical neopixel. You can use libraries like the Adafruit Neopixel library in C++.

---

## Ordering

Want to fabricate your own? Here's a short guide for using JLCPCB to produce assembled versions of these boards!

1. Clone and extract this repository. All production files are found in the /productions directory.
2. Open up JLCPCB, and get to the "Order Now" screen.
3. Drag-and-drop or select through the file menu the orphkicad.zip file in production under the Gerber box at the top.
4. Set PCB settings as desired. We suggest:
    - Quantity - however much you please
    - PCB Color - Black
    - Surface Finish - ENIG (for that gold-colored look)
5. Scroll to the bottom and check "PCB Assembly"
6. Ensure PCBA type is set to Standard (or set to Economic if you don't want the neopixel)
7. Set PCBA Quantity as desired
8. Press "Next" on the right (x2)
9. Upload bom.csv and positions.csv to their corresponding file uploads (BOM File & CPL File)
10. _**Check D2, D3, SW1, SW2, and SW3**_ in BOM confirmation and press "Next"
11. Press "Next" in Component Placements confirmation.
12. You've made it! Review the price and press Save to Cart.