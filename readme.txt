Introduction:
    In the following assignment we first made a function to check for primality.
    After that we made a queue that is safe for multi-threading.
    Afterwards we made an "ActiveObject" that we can run as a thread and assign it 
    to different functions and have different functionality.
    Finally we built a pipeline that uses the queue we implemented to safely output
    numbers to the next "ActiveObject" that will use it's own function on the number
    according to the function we assigned to it.

This document provides instructions for running the task "st_pipeline." It outlines the necessary steps to compile and execute the program successfully. Please follow the guidelines below.
System Requirements:

    Operating System: Linux
    Compiler: GCC (GNU Compiler Collection)

Compilation Steps:

    Open a terminal window.

    Navigate to the directory containing the source code files.

    Run the following command to compile the program:

    go

    make all

    This command will generate an executable file named "st_pipeline."

Execution Steps:

    After successful compilation, run the following command in the terminal:

    ./st_pipeline <num_iterations> [<random_seed>]

    <num_iterations>: The number of iterations to run the pipeline.
    <random_seed> (optional): An integer value to seed the random number generator. If not provided, a random seed will be generated.

Example:

    ./st_pipeline 5 12345

    This command will execute the program with 5 iterations and a random seed of 12345.

    The program will display the output on the terminal, showing the generated random numbers and their primality.