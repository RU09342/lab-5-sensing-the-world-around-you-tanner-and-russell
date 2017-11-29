# Lab 5: Getting a sense of the world around you
So far, you have had really only looked at what your microcontroller has inside of it and how to get internal peripherals to behave with one another. Now it is time to start thinking about how the microcontroller can see the world. In previous labs, you have brought your controller from the mouth of the stork (or from the package from TI), fed it electrons, got it to say its first words, and helped it make its first steps. You have spent many sleepless night consoling your quintuplets when they threw tantrums, sometimes making you question your commitment to become a Junior ECE; but now it is time to send your little prodigies to kindergarten to make you proud. They will learn all about the world around them, not just the binary conditions of your dreary lifestyle. 

## Goals for the lab:
By the end of this lab, you should:
* Interface your microcontrollers to multiple sensor types (voltage, current, and resistive)
* Design Multiple types of signal conditioning circuits for these types of sensors.
* Access and set up the internal ADC's
* Design a basic breakout board for the MSP430FR2311

## Deliverables
By the end of the lab, you will need to provide at a minimum well documented main.c files for *EACH* of the 5 development platforms. You will also need to provide a README at the top of each section in your repository. The reason I say minimum is because there are going to be some recommended further practice that is not mandatory, but heavily recommended, especially if you are finishing this lab in only a couple hours. So come Milestone time, I should see 3 folders in your repository with the following titles:
* PCB Design
* Sensors and Signal Conditioning
* Visualizing Data

each with the .c and README files for each board. The .c and README files should include the minimum amount of work as well as any extra work that you have done. Each processor should have its project saved in its own folder in each part of the assignment, however you only need one README per part of the assignment.

### README Files
Since most of these projects will have just a simple main.c file, you do not need to generate 20 README files. Instead, unless you go for a more advanced implementation of the exercises, you just need 1 README per exercise folder. "But how do I make a README with all of the processors included?" Well now we are getting somewhere. You should talk about the general form of your code as it should be very similar for each processor, but you should highlight what the differences are between each processor. For example, do the clocks need to be initialized differently? As another step forward, you could take that information and somehow make it where your code would work on any of the processors without the need to change it between projects.

### Header Files
You may find yourself by the end of this lab not having generated any header files, which in this case, ignore this section. If you have generated more than just a main.c you most likely have yourself a .h file or two. Remember from the first lab that any header files or libraries that you generate need to have their own README.md which tell the user what dependencies there are, how to install them into their projects, etc.

## Documentation
Since you will most likely be using pre-made code to make most of your code, so what I am going to require you to do is comment each line of code and what it is doing. If you are using code from TI themselves, it will most likely have some of the comments there. But I want you to use your own words when writing these comments. Dive into the datasheets, look into the MSP430.h file to see what registers are being manipulated and tell me why you need to configure them. 