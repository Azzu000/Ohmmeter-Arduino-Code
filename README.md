
1. Introduction

No EE class is any fun without a project! You may do this by yourself or work together with a partner, but only one partner., but... If you wanted to work alone and there is someone who needs a partner, you're it.

Note that I gave the same project for previous teams. Note that I have all of the reports from the previous classes. Please don't copy someone's project.

The project is the capstone element of the course. It is designed to bring together the following elements:

Translating a generalized algorithmic problem statement into a microprocessor-based, schematic design.
Choosing the components that represent the best engineering solution to your project design objectives.
Using a modern CAD design tool for creating the schematic diagram.
dilbert18.jpg
You will create a digitally-controlled, auto-ranging ohmmeter. The ohmmeter should be either battery powered or operate from a modular power supply, also known as a "wall wart." Your project must be self-sufficient. You cannot demonstrate it being connected to your laptop.

In order to complete this project, you must design a printed circuit board (PCB) that holds the circuitry and your TIVA Launchpad Board or Arduino Board. No project will be accepted if the circuitry is on a solderless breadboard. For many of you, this will be the first time that you'll have to design a printed circuit board, or PCB. There is plenty of design information in the lecture slides and I wrote a  little tutorial that you can refer to. In addition, the lecture slides have almost an entire lesson on designing PCBs. 

Also, this goal of this project is to:

Help prepare you for your Capstone Experience. It is critical for your Capstone success that you understand how to give yourself plenty of lead time and how to design a printed circuit board. Most students who do poorly on the project just started too late. Thus, if by the midterm exam you have not started your project, you will likely not be able to complete it in time. 
 Give you something to discuss at a job interview. Interviewers will ask about projects you've done. This one will impress an interviewer, particularly if you are able to discuss your design and debug processes and how you dealt with:
Analog and digital issues
Accuracy

II. Deliverables

Your design and project submission should include the following elements:

A description of your design. This is textural. It includes the following:
Specification sheet,
Theory of operation (what are you doing in hardware, what would the software control)
List of parts
Your source code
Test plan
Citations for sources of all code that you did not write yourself. Unless you cite your sources, it is considered to be plagiarism. I can search for Arduino code or a DIY ohmmeter on-line just as easily as you can.
Schematic diagram drawn using a real schematic capture tool such as the free one from ExpressPCB (there are others out there as well).
Your PCB layout.
Demonstration of a working design with your PCB from ExpressPCB or equivalent at the end of the quarter.
Considering that the total cost of parts should be under $100 (not counting the cost of the printed circuit board)  there is no textbook for the class, and you and your partner are sharing the expenses, your course expenses are still very modest. Note if you are seeing your costs rise, beyond $100, please consult with the instructor, you may be purchasing unnecessarily expensive components. 
Your measurements of the accuracy of the ohmmeter on the various ranges. Note that the accuracy you claim that you measured and the accuracy that I measure should agree. If your meter is out-of-spec on any range, then your report should consider why you have not met the spec on a particular range. Your analysis of why the ohmmeter did not meet the formal spec is as important as the analysis where you did meet the spec. I will actually test your meters in the lab during Final Exam week in December.
 Each team member must also include an evaluation of what they did on the project and what their partner did. This is confidential and should be e-mailed to your lab instructor.  List your tasks and give an overall estimate of the percentage of the project that you did and the percentage that your partner did. The evaluation is confidential.
Considering that the total cost of parts should be under $200, you are splitting the cost, and there is no textbook for the class, your course expenses are still very modest. Note that if you are running up costs over $200, see me ASAP! You may be wasting money and I can help you here.

III. Formal specifications

Battery operated, or from 5V-15V wall power supply
Auto-ranges for best accuracy over 1 ohm to 1 mega-ohm resistance range
Resolution 3-1/2 digits (0000 - 1999)
Accuracy 1 ohm and 1 mega-ohm ranges 1%
Accuracy: 10 ohm and 100 kilo-ohm range 0.1%
All other ranges 0.05%
Minimum update frequency 5 updates per second
Operate independently from a PC or laptop
Have attached flying leads with alligator clips to attach to the unknown resistor
There needs to be some clarification of the formal specification. I accept responsibility for this. I should have given a better explanation. The ambiguity comes in the range and resolution specs. The resolution of 3-1/2 digits mean that on any range, the displayed value, which includes the decimal point, should be displayable over a range of 0000 to 1999. Let's do some examples. to make it clearer:

Assume that you are on the 1 ohm range. The accuracy is specified to be +/- 1% The readings on that range should be between

0.000 ohms and 1.999 ohms +/- 1%

Now, 1% of 1 ohm is 10 milliohms, and your meter should be able to read down to 1 milliohm. This basically means that on the 1 ohm range, the last digits (10^-3) ohms are meaningless in terms of accuracy.  Also, when you are trying to accurately read very small voltages, a lot of other effects come into play, such as thermocouple effects, which can swamp your accuracy. 

Therefore, if you decided not to include a 1 ohm range, but instead made your most sensitive range 10 ohms, then you should be able to display 00.00 to 19.99 ohms. On this range, if the resistance is under 10 ohms, then it should be accurate to 1%. If it is over 10 ohms, it should be accurate to 0.1%.

Of course, if you feel up to it and are really proud of your design, then go for the 1 ohm range. Do it for yourselves, and the interviewer, not for me.
