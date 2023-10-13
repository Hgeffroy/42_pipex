# 42_pipex

## Overview

Welcome to the Pipex project! This project is part of the 42 school curriculum, designed to help you understand and implement basic shell functionality. In this project, you'll create a simplified version of the Unix command `pipex`, which allows you to redirect the output of one command as input to another.

## Project Objectives

The main objectives of the Pipex project are as follows:

1. **Command Line Arguments**: Implement the ability to take two commands as arguments along with their respective flags and arguments.

2. **Pipes**: Use the pipe (`|`) to redirect the output of the first command as input to the second command.

3. **File Redirection**: Implement the ability to redirect the output of the first command to a file and use that file as input for the second command.

4. **Error Handling**: Properly handle errors, such as command execution failures or incorrect command line arguments.

## Usage

To use the Pipex program, follow the format below:

```bash
./pipex file1 cmd1 cmd2 file2
```

- `file1`: Input file whose content will be passed as the standard input to `cmd1`.
- `cmd1`: First command to be executed.
- `cmd2`: Second command to be executed.
- `file2`: Output file to store the final result.

Example:

```bash
./pipex infile "ls -l" "wc -l" outfile
```

In this example, the output of the `ls -l` command will be used as the input for the `wc -l` command, and the result will be stored in the `outfile`.

## Building and Running

To build the Pipex program, use the provided Makefile:

```bash
make
```

This will generate the `pipex` executable.

To run the program, use the following command format:

```bash
./pipex file1 cmd1 cmd2 file2
```

## Additional Notes

- The project requires a good understanding of Unix system calls, processes, and file descriptors.
- Error messages and handling should be informative and help users understand what went wrong.
- Make sure your program handles edge cases gracefully.

## Resources

Here are some resources that may be helpful for completing the Pipex project:

- [Pipes in C](https://www.geeksforgeeks.org/pipe-system-call/)
- [Youtube video](https://www.youtube.com/@CodeVault/)

## Conclusion

Good luck with the Pipex project! If you encounter any issues or have questions, don't hesitate to reach out to your peers or instructors for assistance. Happy coding!
