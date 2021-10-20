************************************
  CS-210: Programming Languages   
  Project 3: Corner Grocer        
************************************

1. Summarize the project and what problem it was solving.

For this project, I had to create a program that used combined C++ and Python integration to manage daily purchases for a grocery store. It had to have three main functionalities: 

  - Output each product purchased in a day, with the number purchased
  - Output the number of a specific requested item purchased in one day
  - Display a histogram of the items purchased in one day

For each of these requirements, the program had to run a C++ function that connected to a Python script, then returned to the C++ function.


2. What did you do particularly well?

I feel that I did a particularly good job at handling user input, as well as output formatting. The program looks relatively neat and does not accept any invalid input at any step.


3. Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?

I feel that I could have compressed my main function a bit, by splitting the input handling into separate distinct functions. I also could have been more vigilant when removing old pieces of code; there is one section where I commented out a section of code that existed in the initial start file, but forgot to delete it before I submitted my project. I feel that these improvements, as a whole, would make my code more efficient and more legible to other programmers who may look at it.


4.Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?

The most difficult piece of code for me was the input handling. I had some difficulty handling situations where users entered a string instead of an expected integer, in particular. I had situations where infinite loops were created and I had a bit of trouble trying to sort out what the problem was. Ultimately, Stack Overflow saved the day, and I will be keeping that website in my back pocket for whenever I may have issues with my code in the future.


5. What skills from this project will be particularly transferable to other projects or course work?

The experience in integrating C++ and Python will be particularly useful as I continue with school and my future career. I feel that these two languages, while powerful on their own, are infinitely more capable when paired together. Hopefully this skill will help me in the future; if not with C++ and Python, then just integrating two programming languages, and the ways that they can work together in general.


6. How did you make this program maintainable, readable, and adaptable?

To make this program maintainable and adaptable, I separated as much code from the main function as possible. This was not one of the requirements in the rubric, but I did it anyway, splitting the necessary C++ functions into a new header file. This allowed me to compress the main function (though not as much as I would like), and future changes to those functions would not have an effect on the main function itself. 
