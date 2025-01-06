# Simple Shell 0.1

## Description
Write a UNIX command line interpreter.

### Expectations

#### Your Shell should:

- Display a prompt and wait for the user to type a command. A command line always ends with a new line.
- The prompt is displayed again each time a command has been executed.
- The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
- The command lines are made only of one word. No arguments will be passed to programs.
- If an executable cannot be found, print an error message and display the prompt again.
- Handle errors.
- You have to handle the “end of file” condition (Ctrl+D)

#### You don’t have to:

- Use the PATH.
- Implement built-ins.
- Handle special characters : ", ', `, \, *, &, #
- Be able to move the cursor.
- Handle commands with arguments.
