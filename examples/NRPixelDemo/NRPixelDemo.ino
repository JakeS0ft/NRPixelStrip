/******************************************************************************
 * This code is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 ******************************************************************************/

/**
 * This simple demo program cycles a pixel strip through colors using
 * no RAM (well, 3 bytes of RAM to hold the colors, but that is in 
 * this sketch; the library itself allocates no RAM).
 * 
 * Note: The library defaults to use Arduino pin 13 (PORTB, BIT 5)
 *      To use a differnt pin, edit the #define in NRPixelStrip.h
 *      digitalWrite() is too slow, so PORT-level writes are
 *      necessary and that is what the library uses.
 */

#include <NRPixelStrip.h>

//Number of pixels in the strip Increase this to show more pixels.
//Note: Increasing this does not affect RAM usage at all!
//Use as many pixels as you'd like!
#define NUM_PIXELS 40

//How long to show each color. Decrease this to speed up, increase to slow down
#define DELAY_PER_COLOR 250

//Highest value (brightness) to allow
//Increase this for brighter pixels, decrease for dimmer
#define MAX_POWER_LEVEL 128

//Super light-weight pixel strip
NRPixelStrip gPixelStrip;

unsigned char gRed;
unsigned char gGreen;
unsigned char gBlue;
void setup()
{
  gPixelStrip.Init(); //Initalizes the I/O pin

  //Set starting default RGB values
  gRed = MAX_POWER_LEVEL;
  gGreen = 0;
  gBlue = 0;
}

void loop()
{

  //Ramp up the green
  for(gGreen = 0; gGreen < MAX_POWER_LEVEL; gGreen++)
  {
    cli();//Turn off interrupts
    gPixelStrip.SendPixels(gRed,gGreen,gBlue,NUM_PIXELS);
    sei();//Turn interrupts back on
    
    gPixelStrip.Show();
    delay(DELAY_PER_COLOR);
  }
  //Ramp down the red
  for(gRed = MAX_POWER_LEVEL; gRed > 0; gRed--)
  {
    cli();//Turn off interrupts
    gPixelStrip.SendPixels(gRed,gGreen,gBlue,NUM_PIXELS);
    sei();//Turn interrupts back on
    
    gPixelStrip.Show();
    delay(DELAY_PER_COLOR);
  }
  //Ramp up the blue
  for(gBlue = 0; gBlue < MAX_POWER_LEVEL; gBlue++)
  {
    cli();//Turn off interrupts
    gPixelStrip.SendPixels(gRed,gGreen,gBlue,NUM_PIXELS);
    sei();//Turn interrupts back on
    
    gPixelStrip.Show();
    delay(DELAY_PER_COLOR);
  }
  //Ramp down the green
  for(gGreen = MAX_POWER_LEVEL; gGreen > 0; gGreen--)
  {
    cli();//Turn off interrupts
    gPixelStrip.SendPixels(gRed,gGreen,gBlue,NUM_PIXELS);
    sei();//Turn interrupts back on
    
    gPixelStrip.Show();
    delay(DELAY_PER_COLOR);
  }
  //Ramp up the red
  for(gRed = 0; gRed < MAX_POWER_LEVEL; gRed++)
  {
    cli();//Turn off interrupts
    gPixelStrip.SendPixels(gRed,gGreen,gBlue,NUM_PIXELS);
    sei();//Turn interrupts back on
    
    gPixelStrip.Show();
    delay(DELAY_PER_COLOR);
  }
  //Ramp down the blue
  for(gBlue = MAX_POWER_LEVEL; gBlue > 0; gBlue--)
  {
    cli();//Turn off interrupts
    gPixelStrip.SendPixels(gRed,gGreen,gBlue,NUM_PIXELS);
    sei();//Turn interrupts back on
    
    gPixelStrip.Show();
    delay(DELAY_PER_COLOR);
  }
}
