 =========================================================================
 =                                                                       =
 =  LED Matrix Studio v0.7.13                                            =
 =  March 21st 2014                                                      =
 =                                                                       =
 =  www.freshney.org // paul@freshney.org                                =
 =                                                                       =
 =  www.maximumoctopus.com/electronics/builder.htm                       =
 =                                                                       =
 =  www.maximumoctopus.com/electronics/downloads/LEDMatrixStudio.zip     =
 =                                                                       =
 =  www.iLoveLEDs.co.uk                                                  =
 =                                                                       = 
 =========================================================================

 Hello!
 
 Thanks for downloading the latest version of my LED matrix studio.

 A couple of years ago I started playing with Picaxe and Arduino 
 microcontrollers and one of the first things I bought was an 8x8
 LED matrix. In the passing couple of years I've bought lots and lots
 of LED boards! I love LEDs, I think it's an addiction!

 After working out the bit-patterns on a piece of paper a couple of
 times I did what any programmer would do - I wrote a simple 
 program to work out the bit-patterns for me. That simple program
 morphed in to three separate programs all designed for slightly 
 different things. 

 On the 10th of June 2012 I decided to start from scratch and
 build an all-purpose application with every feature I (and others)
 could ever want.
 
 I've designed it to be as easy to use as possible. Select a grid
 size and click "New". 

 Column and row data are available at the bottom in two separate
 boxes. Columns can be calculated from the top or bottom of the matrix,
 rows from the left or right.

 There is a special Sure Electronics 24x16 mode that outputs the column
 data in the order that the device requires. This is one of my favourite
 matrix devices, hence why I have this mode! Email me if you have any
 special requests for other devices. 

 Features:
 
 - Supports up to a 64x64 matrix
 - Supports single and bicolour matrices
 - Six sizes of "pixel" allows for use on almost any resolution PC
 - Output data in all possible combinations
 - Select either decimal or hex output (with $ or 0x prefix)
 - Select either normal, curly or square brackets
 - Six different draw modes
     simple click to toggle on/off (left mouse button)
     Freehand draw mode (right mouse buttom)
     Filled rectangles
     Empty rectangles
     Line from A->B
     Text (using customisable fonts, two included 5x7 and 3x5)
 - Flip, mirror, invert, rotate, scroll a matrix
 - Animation support, up to 500 frames
 - Font designer mode
 - Save/Load native format
 - Unlimited "presets", predefined sizes and formats
 - Export animation or single frame
 - 10 separate buffers for use solely by the user as scratchpads/temporary
 - Auto save option
 - Import from bitmap image (one or more frames)

 If you find a bug or have a feature request then please email me.

 Thanks,

 Paul A Freshney (paul@freshney.org)

========================================================================

 Credits:

 All coding     : Paul A Freshney
 Testing/Ideas  : Steve Turner
 Thanks         : Andrew, Apostolos, Peter, Zoltan and Gary

========================================================================

========================================================================
== Updates for 0.7.13 ==================================================
========================================================================

- Fixed the loader :(

========================================================================
== Updates for 0.7.12 ==================================================
========================================================================

- Much improved export functionality
- User memories can be exported in the same way as normal matrix data
- Removed separate Row/Column toolbars, replaced with a single toolbar
- Fixed a couple of minor bugs

========================================================================
== Updates for 0.7.11b =================================================
========================================================================

- Fixed a bug with row display showing MSB/LSB wrong way around
- Fixed a number of bugs with export
- Added a couple of Python export formats
- Changed the default start char of font mode from 33 to 32

========================================================================
== Updates for 0.7.10 ==================================================
========================================================================

- Fixed a bug that would multiply the amount of dat when saving
  animations with some settings
- Added "combine nibbles" option, useful for displays with a width or
  length of 4 pixels (like the Orion4x4 grid board)
- Hex and bracket option settings are saved in each animation file now
- Added option to use above when loading or use the current application
  settings (View->Use format embedded in save files)
- Added ability to change the start ASCII code in font mode
  (default is 33)

========================================================================
== Updates for 0.7.9d ==================================================
========================================================================

- Fix when editing text in column/row boxes with 0x prefix

========================================================================
== Updates for 0.7.9c ==================================================
========================================================================

- Couple of minor fixes

========================================================================
== Updates for 0.7.9b ==================================================
========================================================================

- Fixed a bug which wouldn't select no hex prefix
- Changed a couple of button/control tooltips

========================================================================
== Updates for 0.7.9 ===================================================
========================================================================

- Added option of circular or square pixels

========================================================================
== Updates for 0.7.8 ===================================================
========================================================================

- Fixed a bug that caused the grid to hide behind the top tool bars on
  systems using large fonts

========================================================================
== Updates for 0.7.7 ===================================================
========================================================================

- Added a "gradient" mode for bicolour matrices
- Added a "random" colour drawing mode for bicolour matrices
- Minor bug fixes etc.

========================================================================
== Updates for 0.7.6b ==================================================
========================================================================

- Fixed bug that stopped some files loading :(

========================================================================
== Updates for 0.7.6 ===================================================
========================================================================

- Added bicolour matrix support
- Added optimise mode (beta at moment)
- Added mousewheel up/down to select frame
- Minor modifications to the GUI and other minor updates
- Fixed a few minor bugs

========================================================================
== Updates for 0.7.5 ===================================================
========================================================================

- Added Auto Save option (2/5/10 minute intervals)
  Saves to \saves\_autosave.leds
- Added new icon!
- Added import from bitmap image option
- Increased max frame limit to 500
- Increased max frame size to 64x64
- Column and Row "data boxes" now accept hex values ($ and 0x)
- Fixed a couple of minor bugs

========================================================================
== Updates for 0.7.4 ===================================================
========================================================================

- Added Padding option for hex values
- Fixed a couple of minor bugs (load/save location is now remembered)
- Added option to toggle matrix grid

========================================================================
== Updates for 0.7.3 ===================================================
========================================================================

- Fixed a bug which outputs the 24x16 data incorrectly
- Fixed a bug which makes the hex output settings not correctly
  set on startup
- Fixed a bug which stops the update checker connecting to my website
  (for some reason it's become very picky over agent strings?!)

========================================================================
== Updates for 0.7.2 ===================================================
========================================================================

- Fixed a few minor bugs
- Added flip/invert/mirror all frames option on menu
- Added import option. Imports a single frame from a saved matrix to the
  currently selected frame.
- Increased frame limit to 200.
- Other minor tweaks!


========================================================================
== Updates for 0.7.1 ===================================================
========================================================================

- Fixed a few minor bugs
- Added rotate by any angle feature. Well, actually multiples of 5'.
  Select the angle, and number of frames and the software will generate
  them for you. Each new frame being x degrees further rotated than
  the preceeding frame. Works best with square grids...
- Now shows which user buffers have content by the appearance of a little
  icon beside the menu item
- Customisable animation playback speed, press the right mouse button
  over the play button.
- Other minor tweaks!

========================================================================
========================================================================