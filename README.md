## Synopsis

A project developed for Embedded Computational Systems at Instituto Superior Técnico. This project is intended to work with **Microchip's 44-pin PICDEM-2 Board** (based on the **PIC18F4520 microcontroller**) and a normal **PC** (using and **Ubuntu** based Linux OS). Microchip's board is programmed to be running as a **clock with a temperature/luminosity sensor and alarm capabilities**. It also has the capability to **store read values**, as they change, to an **internal EEPROM** and to communicate through an **RS-232 serial line** with the chosen PC. This is done with resource to the eCOS multitasking kernel (http://ecos.sourceware.org/). 

## Code Example

For the moment, we have none. Updates coming!

## Motivation

As stated in the synopsis, this project was developed for Embedded Computational Systems class at Instituto Superior Técnico.

## Installation

In order for everything to work and to be able to change the code, this project is divided in 3 parts.
Technicaly, the only requirement is eCos (http://ecos.sourceware.org/getstart.html). However, if you're new to eCos, you can find it really difficult to install configure. For that reason, you should work on the virtual box enviroment supplied by the professor.

**The 3 parts that you need**
Part 1: *Computer running a Virtual Box using Linux with eCos installed and configured* (supplied by the professor)
Part 2: *Computer running a Virtual Box using eCOs* (supplied by the professor)
Part :*PICDEM-2 Board* (you should already how to make it run)

### Steps for Part 1 & Part 2

#### Step 1:
Download **Virtual Box** or VMWare (VMWare doesn't work on some computers so I used Virtual Box)

#### Step 2:
Download or copy from a flashdrive the Ubuntu and eCos disc image mentioned in the beginning.

#### Step 3:
In Virtual Box, click the "New" button and enter the following information:

**Name:** Ubuntu
**Type:** Linux
**Version:** Ubuntu
**Memory Size:** 2042 Mb (or anything else above 1Gb, really)
**Hard Disk:** Use an existing hard drive file (and browse to the "Ubuntu" folder where you select the first .vmdk file)

#### Step 4:
In Virtual Box, click the "New" button and enter the following information (just click through the warnings at the end):

**Name:** eCos
**Type:** Other
**Version:** Oter
**Memory Size:** 256 Mb
**Hard Disk:** Do not add a virtual hard disk

#### Step 5:
Go to your new VM (eCos) settings (big orange cog wheel button).

#### Step 6:
In storage, click on the "add new storage controller" button (it's the green upmost left button on the bottom) and select "Add Floppy controller"

#### Step 7:
On the floopy controller add a new *image* and browse to the location of "ecos.img" in tmp-dskecos.

#### Step 8:
Add the serial line (unsure about this one). I'll update it when I figure this one out!

**If you want to install everything on your own:** (not recommended)
Use the official steps or http://www.rte.se/blog/blogg-modesty-corex/ecos-real-time-operating-system/2.15 and check on http://www.ecoscentric.com/devzone/configtool.shtml just to make sure everything version is up-to-date (should be). You might have to change some paths, so if you are just copy-pasting and there are errors.

## API Reference

For the moment, we have none. Updates coming!

## Tests

For the moment, we have none. Updates coming!

## Contributors

This is maintained by Fernando Silva, Madalena Moreira and Paul Kastner. Feel free to create a new Issue, submit a pull request on gitHub or e-mail me at *marquesdasilvaf@gmail.com*.

## License

GNU GPLv3.0 (see LICENSE for more information)

