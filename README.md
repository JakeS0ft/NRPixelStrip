# NRPixelStrip
No RAM NeoPixel library for Arduino. 

This library drives a WS2812 (a.k.a. "NeoPixel") strip of addressable LEDs in a manner that is RAM efficient. The library allows for each frame to be calculated on-the-fly and each pixel of the frame can be sent individually. This different than the typical approach of buffering the entire frame. As a consequence, a strip of arbitrary length may be driven even from AVR chips that would otherwise not have enough RAM.

This library is based on research and demo code by Josh Levine (https://github.com/bigjosh/SimpleNeoPixelDemo). Modification and adaptation to a library by JakeSoft.

