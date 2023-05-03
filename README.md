# 42-get_next_line

## Goal

The goal of get_next_line is to read a file line by line in a C program. This function reads a single line from a file descriptor each time it is called and returns that line to the caller.

get_next_line is especially useful for reading large files or streams of data, where it may be impractical or inefficient to read the entire file or stream into memory at once. By reading one line at a time, programs can process the data more efficiently and with less memory usage.

Additionally, the get_next_line function is often used in conjunction with other functions to implement more complex functionality. For example, it can be used to implement command line interfaces, network protocols, or log file parsers.

## Value returned

The get_next_line function returns an integer that indicates whether the line was successfully read, reached the end of the file (EOF), or if there was an error.

Specifically, the get_next_line function returns:

    * 1 if a line was read successfully

    * 0 if the end of the file (EOF) was reached

    * -1 if there was an error during reading

It is important to note that the get_next_line function reads only one line per call and keeps track of the reading state for subsequent calls. This means that it can be called multiple times until the end of the file is reached.

Additionally, the get_next_line function dynamically allocates memory to store the line read from the file. This memory must be freed by the caller after use by calling the free function on the pointer returned by get_next_line.
