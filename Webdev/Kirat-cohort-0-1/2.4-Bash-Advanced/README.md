# Bash advanced

## File permissions

- you need to use the command `chmod` and then the arguments for user, group or others you need to use `u`,`g`,`o` and
  - user - means the current user
- for the permissions to remove you need to use `-` minus with the users stuff and to add permissions you need to use `+` plus instead of minus.
- Also what kind of permissions you need to add should be specified after the `+`/`-` without any spaces and the permissions are read, write or execute(for binary/executables) and they're `r`,`w`, `x` respectively
- So the examples for making a binary executable with the permissions for all the group users and others will be `chmod ugo+x file/folder_name`. For folder you will need to add a recursive param
- You can also use numbers which represents the permisssions like read,write and execute and also the users, group and others. eg: `chmod 664 file_name`:

## viewing files

- `head`: When we want to see first 10 rows of a specific file something like cat, we can use head followed by the filename. Note that it shows 10 by default, if you want to see 20 lines you need to pass `-20` after the head command in order to see 20 lines, provided it contains that many lines.
- `tail`: When we want to see last 10 rows of a specific file something like cat, we can use tail we can use head followed by the filename. Note that it shows 10 by default, if you want to see 20 lines you need to pass `-20` after the tail command in order to see 20 lines, provided it contains that many lines.
- If you want to see certain specific lines you can use pipe to make the command flow from the tail to the head. eg: `tail -n +25 file_name | head -5`, where `-n` is used to give the no flag such that after that we can specify

## All about Head and Tail cli tool

Certainly! In Linux, the `tail` and `head` commands are useful utilities for viewing the contents of files. Here are some notes on these commands:

### `tail` Command:

#### Purpose:

- The `tail` command is used to display the last part of a file. It's often used to view log files in real-time.

#### Syntax:

```bash
tail [OPTIONS] [FILE]
```

#### Common Options:

- `-n N`: Show the last N lines (default is 10).
- `-f`: Output appended data as the file grows (follow mode).
- `-c N`: Show the last N bytes instead of lines.
- `-q`: Quiet mode (suppress headers when multiple files are specified).

#### Examples:

1. Display the last 10 lines of a file:

   ```bash
   tail filename.txt
   ```

2. Display the last 20 lines of a file:

   ```bash
   tail -n 20 filename.txt
   ```

3. Follow the growth of a log file in real-time:

   ```bash
   tail -f /var/log/syslog
   ```

4. Display the last 100 bytes of a file:
   ```bash
   tail -c 100 filename.txt
   ```

### `head` Command:

#### Purpose:

- The `head` command is used to display the beginning of a file. It's often used to preview the contents of a file.

#### Syntax:

```bash
head [OPTIONS] [FILE]
```

#### Common Options:

- `-n N`: Show the first N lines (default is 10).
- `-c N`: Show the first N bytes instead of lines.
- `-q`: Quiet mode (suppress headers when multiple files are specified).

#### Examples:

1. Display the first 10 lines of a file:

   ```bash
   head filename.txt
   ```

2. Display the first 5 lines of a file:

   ```bash
   head -n 5 filename.txt
   ```

3. Display the first 50 bytes of a file:

   ```bash
   head -c 50 filename.txt
   ```

4. Display the first 20 lines of multiple files with filenames:
   ```bash
   head -n 20 file1.txt file2.txt
   ```

### Additional Notes:

- Both `tail` and `head` commands are versatile tools that can be combined with other commands in shell pipelines.
- They are commonly used for monitoring logs, previewing file contents, or extracting specific portions of large files.

These are basic notes, and each command has more options and use cases. You can refer to the manual pages (`man tail` and `man head`) for comprehensive information on all available options and functionalities.

## `wc` command wordcount

The `wc` command in Linux is a versatile command-line utility that is used to display the number of lines, words, and bytes in a file or standard input. The name `wc` stands for "word count," but it can provide additional information beyond just word counts.

### Syntax:

```bash
wc [OPTIONS] [FILE]
```

### Common Options:

- `-l`: Display the number of lines.
- `-w`: Display the number of words.
- `-c`: Display the number of bytes.
- `-m`: Display the number of characters.
- `-L`: Display the length of the longest line.
- `-help` or `--help`: Display help information.

### Examples:

1. Display the number of lines, words, and bytes in a file:

   ```bash
   wc filename.txt
   ```

2. Display only the number of lines in a file:

   ```bash
   wc -l filename.txt
   ```

3. Display the number of words in a file:

   ```bash
   wc -w filename.txt
   ```

4. Display the number of bytes in a file:

   ```bash
   wc -c filename.txt
   ```

5. Display the length of the longest line in a file:

   ```bash
   wc -L filename.txt
   ```

6. Count the number of lines, words, and bytes from the output of another command (using a pipe `|`):
   ```bash
   some_command | wc
   ```

### Additional Notes:

- If no file is specified, `wc` reads from standard input.
- The output format is typically "lines words bytes filename."
- The `-m` option may not accurately represent the number of characters in some locales due to multibyte characters.
- `wc` is often used in combination with other commands and in shell scripts for various text-processing tasks.

Overall, `wc` is a handy utility for quickly obtaining statistics about the content of files or the output of other commands in the terminal. It's particularly useful when working with text data and when you need a quick overview of file characteristics.

## Grep

The `grep` command in Linux is a powerful and widely used command-line utility for searching and matching patterns within text files. The name "grep" stands for "Global Regular Expression Print."

### Syntax:

```bash
grep [OPTIONS] PATTERN [FILE...]
```

### Common Options:

- `-i`: Ignore case distinctions.
- `-r` or `-R`: Recursively search subdirectories.
- `-n`: Display line numbers along with matching lines.
- `-l`: Display only the names of files containing the pattern.
- `-v`: Invert the match, displaying non-matching lines.
- `-c`: Display the count of matching lines.
- `-e PATTERN`: Specify multiple patterns to match.
- `-A N`: Display N lines after a match.
- `-B N`: Display N lines before a match.
- `-w`: Match whole words.

### Examples:

1. Search for a pattern in a single file:

   ```bash
   grep "pattern" filename.txt
   ```

2. Search for a pattern in multiple files:

   ```bash
   grep "pattern" file1.txt file2.txt
   ```

3. Search for a pattern recursively in all files within a directory:

   ```bash
   grep -r "pattern" /path/to/directory
   ```

4. Search for a case-insensitive pattern:

   ```bash
   grep -i "pattern" filename.txt
   ```

5. Display line numbers along with matching lines:

   ```bash
   grep -n "pattern" filename.txt
   ```

6. Display only the names of files containing the pattern:

   ```bash
   grep -l "pattern" file1.txt file2.txt
   ```

7. Invert the match, displaying non-matching lines:

   ```bash
   grep -v "pattern" filename.txt
   ```

8. Count the number of lines that match a pattern:

   ```bash
   grep -c "pattern" filename.txt
   ```

9. Search for lines containing either of multiple patterns:

   ```bash
   grep -e "pattern1" -e "pattern2" filename.txt
   ```

10. Display lines after a match:

    ```bash
    grep -A 3 "pattern" filename.txt
    ```

11. Display lines before a match:

    ```bash
    grep -B 2 "pattern" filename.txt
    ```

12. Display 5 lines before and after a match:

    ```bash
    grep -C 5 "pattern" filename.txt
    ```

13. Display lines that matches the pattern

    ```bash
    grep -w "pattern" filename.txt
    ```

14. Display lines that matches the pattern but only the matched part/word/pattern and not the whole line which in it may be present
    ```bash
    grep -o "pattern" filename.txt
    ```

### Additional Notes:

- `grep` is commonly used in conjunction with other commands in pipelines (`|`) to filter and process text data.
- Regular expressions can be used as patterns to enable more complex and flexible searches.
- `grep` is a versatile tool for text processing, log analysis, and file content extraction.

Understanding `grep` and regular expressions can significantly enhance your ability to work with and manipulate text data in the command line. It's a fundamental tool for any Linux or Unix-like system.

# The main scripting part

Example

```bash
#!/bin/bash
echo "hello there"
mkdir automated_dir
cd automated_dir && touch new_file.txt
```

- Firstly, in the first line of our script we specify the interpreter we would like to use to parse the scrip, in our example we will be using bash, so we need to use the shebang `#!/bin/bash` telling the script to parse using the bash interpreter
- Followed by the shebang we need to write our commands in a sequential order in which we want them to execute line by line

# `sed` and `awk` cli-tool

Certainly! Here are notes on `sed` and `awk`, two powerful text-processing utilities in Linux:

### `sed` (Stream Editor):

#### Purpose:

- `sed` is a stream editor used for text transformations on an input stream (a file or input from a pipeline).

#### Basic Syntax:

```bash
sed [OPTIONS] 'command' filename
```

#### Common Commands:

- `s/old/new/g`: Substitute all occurrences of "old" with "new" globally.
- `p`: Print the current pattern space.
- `d`: Delete the current pattern space; start the next cycle.

#### Examples:

1. Replace "apple" with "orange" in a file:

   ```bash
   sed 's/apple/orange/g' filename.txt
   ```

2. Print lines containing "pattern":

   ```bash
   sed -n '/pattern/p' filename.txt
   ```

3. Delete lines containing "pattern":

   ```bash
   sed '/pattern/d' filename.txt
   ```

4. Replace the first occurrence of "word" with "term":

   ```bash
   sed 's/word/term/' filename.txt
   ```

5. Print only lines 3 to 7:
   ```bash
   sed -n '3,7p' filename.txt
   ```
6. Makes a backup of the file so as to keep old changes as well as changes the main file with the specified substitution
   ```bash
   sed -ibackup 's/word/replacement/' filename.txt
   ```
7. Make the specified changes to only the line no or can give comma followed by another number to make changes to a set of lines from one to another
   ```bash
   sed '3 s/word/replacement/' filename.txt
   sed '3,7 s/word/replacement/' filename.txt
   ```
8. Print lines containing "pattern": you need to use the p to print at the end of the regex before the closing single quote

   ```bash
   sed -n '3, /pattern/ p' filename.txt
   ```

### `awk`:

#### Purpose:

- `awk` is a versatile programming language or a scripting language designed for text processing and data extraction.

#### Basic Syntax:

```bash
awk 'pattern { action }' filename
```

#### Common Features:

- **Patterns:** Conditions that define when an action should be performed.
- **Actions:** Commands executed when a pattern is matched.
- **Fields:** Divisions of a line, separated by a delimiter (default is whitespace).

#### Examples:

1. Print the first field of each line:

   ```bash
   awk '{ print $1 }' filename.txt
   ```

2. Sum the values in the second column:

   ```bash
   awk '{ sum += $2 } END { print sum }' filename.txt
   ```

3. Print lines where the third field is greater than 50:

   ```bash
   awk '$3 > 50' filename.txt
   ```

4. Print lines where the first field contains the pattern "apple":

   ```bash
   awk '/apple/' filename.txt
   ```

5. Print lines with more than four fields:

   ```bash
   awk 'NF > 4' filename.txt
   ```

6. Print lines between patterns "start" and "end":

   ```bash
   awk '/start/,/end/' filename.txt
   ```

7. Print the lines with the follwing changes/patterns "start" and "end" but do not write in the file

   ```bash
   awk '{gsub(/word/, "replacement")}{print}' filename.txt
   ```

8. to add a header or footer to a file using some text, we will use the word BEGIN to add the header and END to add the footer just like in sql and others

   ```bash
   awk 'BEGIN {print "LOG SUMMARY\n----------------------"} {print} END {print "------------------------\nEND OF LOG SUMMARY"}' filename.txt
   ```

9. If you want to cherry pic data that you want to pick in special files like columnar files or CSVs, etc you can use the following where $1 means the first column and $2 means the second column so on and so forth and can do a bunch of operations on

   ```bash
   awk 'print $1, $2' filename.txt
   ```

10. By default the delimiter for awk is space but we can specify it to use it in place of space

    ```bash
    awk -F "," '{print $1, $2}' filename.txt
    ```

11. To do a arithmetic operation on top of the file, lets say to find how many times an error has occured by counting the 'ERROR' string that has occured in a log file, etc etc

    ```bash
    awk '{count[$2]++} END {print count ["ERROR"]}' filename.txt
    ```

12. To pull logs only after a certain timestamp or any parameter(can be modified according to the need), timestamp used here is in the example file as the heading of the first column so `$1` has also been used

    ```bash
    awk '{if ($!>1599999999999) {print $0}}' filename.txt

    ```

### Additional Notes:

- Both `sed` and `awk` are often used together in pipelines for more complex text processing tasks.
- Regular expressions are commonly used in both `sed` and `awk` for pattern matching.
- Learning `sed` and `awk` can greatly enhance your ability to manipulate and analyze text data efficiently in the command line.

These notes cover the basics of `sed` and `awk`, but each of these tools is powerful and has many more features and options. Exploring the respective manual pages (`man sed` and `man awk`) can provide a comprehensive reference.
