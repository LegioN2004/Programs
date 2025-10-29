# grep and awk

# grep

It stands for **Global Regular Expression Print**

`grep` command searches for a particular string or keyword from a file and
prints lines matching a given pattern. It checks line by line and prints lines matching given pattern.

We can use it anywhere like with directories, files, searching for files, for
any command output, finding strings, etc.

## Syntax

grep [option].. pattern [File]..

## Types of usage

1. To ignore the upper and lower case while searching: `grep -i "keyword" file`
    - grep is case sensitive by default
    - To fix that we can use `-i` flag to tell the command to ignore the case
      sensitivity. `grep -i hello some_datasheet.csv`
2. To search everything except given pattern/keyword: `grep -v "keyword" file`
3. To print how many times (count) given keyword is present. `grep -c "keyword" file`
4. To find the exact match of a keyword in a file. `grep -w "keyword" file`
    - What this means is that if we provide half name, let's say rohi instead of
      rohit, we'll still get the results of 'rohi' and 'rohit' using grep. But if we want to find
      someone having the names 'rohi' only then we can use the `-w` flag to find the
      exact match of the keyword (here it's name)
5. To print the line no of the exact matches of the given keyword in a file:
   `grep -n "keyword" file`
6. To find a keyword in multiple files: `grep "keyword" file1 file2 ...`
7. When using the 6th command, the output spews filenames along with the strings that are being outputted in the cli. To not show the filenames when outputting the strings, we can use the `-h` flag to not show the output. `grep -h "keyword" file1.csv file2.csv ...`. You will only get the results when you'll use this and no filenames attached to it.
8. To search multiple keywords in a file, use `grep -e "keyword1" -e "keyword2"
file`
    - There is a shortcut for this command as well, by using `egrep
"word1|word2|word3" filename.csv `
9. To find multiple keywords in multiple files, `grep -e "keyword1" -e
"keyword2" file1 file2 ....`
    - There is a shortcut for this command as well, by using `egrep
"word1|word2|word3" filename.csv filename2.csv`
10. To only print file names that matches only given keyword, `grep -l "keyword"
file1 file2 ...`
11. To print the matching line which start with given keyword, `grep "^100"
filename.csv` for finding out keywords that start with string '100'.
12. To print the matching line which end with given keyword, `grep "word$"
    filename.csv` for finding out keywords that start with the word 'word',
    let's say the sentence is something like "it should have the following keyword".
13. To find a word in all the files of the directory, use `grep -R "keyword"
director/`. `-R` means that find the files recursively in the directory so it will go through all the files in the directory.

14. that same `egrep` command to find the file
15. If you just want to search but don't want to printout something in the
    terminal, use `grep -q "keyword" file`. And if you want to suppress the
    error message, then you can use `grep -s "keyword" file`

To find if previous command is successfull or not, i.e the exit status. Then
take
