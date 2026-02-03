# Command Interpreter 
![Static Badge](https://img.shields.io/badge/STATUS-CONCLUIDO-%234BC732)

---

### :owl: About the project
This project was developed to put some C concepts into practice and with the intention of creating my own command interpreter.

The number of functionalities is still limited, but easily expandable.

Note:
- Since it was a small project, I used some global variables.

- I applied clean code principles, assigning the correct type to each variable and constant, clearly defining variable names, separating the code by functionality, assigning unique responsibilities to each function, etc.

I used some limitations in the project to sharpen my creativity:

- I couldn't use either structs or pointers, except for strings.

- Since this was a small project, mostly an exercise, and unlikely to be expanded, I didn't see the need to separate it with a .h file. However, I separated the function prototypes at the top of the code and the development of those functions at the end.

- One of the parts I enjoyed most was developing the load functions; I learned a lot from this exercise, especially the incredible things you can do with carriage return, nested within loops and with good logic.

---

### :notebook: Features
- [x] Write a text.

- [x] Number of times this text will be executed.

- [x] Clears the screen.

- [x] Clears the screen and resets all control variables.

- [x] Executes the text and the number of times it should be repeated.

- [x] Executes the text the number of times it should be repeated with a 'beep'.

- [x] Shows the list with all commands.

- [x] Ends the program.

---

### :pushpin: Requirements
You need to have the following installed:

> A code editor, such as **VS Code**, or an IDE like **Code::Blocks**.

2. Make sure you have a C compiler installed. I recommend **MinGW**:  
   [MinGW official website](https://www.mingw-w64.org/downloads/#mingw-w64-builds).

3. Select MinGW-W64-builds and download the latest release version.

4. Extract the file to the root directory c:

5. Now configure the environment variables: press `Win + R`, type `sysdm.cpl`, go to the **Advanced** tab, then **Environment Variables**, and add the following path to both the **User Path** and the **System Path**:

`C:\mingw32\bin`

5. Run the command `gcc --version`. You should see something similar to this:

> gcc (i686-mcf-dwarf-rev0, Built by MinGW-Builds project) 15.2.0  
> Copyright (C) 2025 Free Software Foundation, Inc.  

6. If this message does not appear, check whether the environment variable path was set correctly.

---

### :computer: How to execute the project
1.  To compile a C program, open the VS Code terminal using `Ctrl + \`` and run:

> gcc \<file_name.c\> -o \<executable_name\>

To run the program:

> ./\<executable_name\>

---

### :rocket: Technologies
> Language C ANSI




