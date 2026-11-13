# LISTS and TABLES

## ordered lists and unordered lists

- list items can be shown using the `<li></li>` tags
  - you cannot add another nested `li` tag in the `li` tag, but what you can add is `ul` at the top level then another `ul` and inside it will be the `li` as the list item, to show subitems individually or in the list.
  eg:

  ``` html
  <ul>
    <li>to show as first level heading</li> <!-- if you don't show this line then it will become the same as the other list items if there are any above -->
    <ul>
      <li>this is the second level nested heading</li>
    </ul>
  </ul>
  ```

- Unordered lists come in bulletpoints, it is written with the `<ul></ul>`
  - You can use the `ul` tag with the type attribute and the value in the double quotes, there are three of them present: square, circle, disc.
  how to write

  ``` html
  <ul type="circle"> <!-- to get the circle type same goes for the other types -->
    <li>This is a list item</li>
  </ul>
  <ul type="disc">
    <li>This is a list item</li>
  </ul>
  <ul type="square">
    <li>This is a list item</li>
  </ul>
  ```

- ordered lists come in numbers or letters, it is written with the `<ol></ol>`
how to write

  ``` html
  <!-- to get the circle type same goes for the other types -->
  <ol type="a"> <!-- to get alphabetical numbering first value used is 'a' rest are adjusted auto -->
    <li>This is a list item</li>
  </ol>
  <ol type="1"> <!-- to get normal numbering first value used is '1' rest are adjusted auto -->
    <li>This is a list item</li>
  </ol>
  <ol type="I"> <!-- to get romanized numbering first value used is capital 'i' rest are adjusted auto -->
    <li>This is a list item</li>
  </ol>
  <ol type="i"> <!-- to get this type of numbering (i, ii, iii, etc)  first value used is 'i' rest are adjusted auto -->
    <li>This is a list item</li>
  </ol>
  ```

  - You can use any type using the type attribute with different values to get different types of numbering like:
  a) use value 1 to get normal digit numbering,
  b) I to get romanized numbering,
  c) a ( or A i.e capital to get captal ones) to get alphabetical numbering,
  d) i to get numbering in i, ii, iii, etc when written inside ol tag

## Tables

- Tables are shown using the `<table></table>` tag and it contains two more sub tags:
the following is a table example
| Column 1 | Column 2 | Column 3 |
|----------+----------+----------|
| Value 1  | Value 1  | Value 2  |
| Value 2  | Value 3  | Value 4  |

  a) `thead` tag and
  - `thead` tag `<thead></thead>` stands for table head which is used to show like the heading of the columns in a table, eg: above words column 1, 2, 3.
  - The `thead` element represents the block of rows that consist of the column labels (headers) for the parent table element, if the `thead` element has a parent and it is a table.
    - to add values to the column heads, you'll use the `<th></th>` tags inside of the `thead` tags which represents a header cell in a html table

  b) `tbody` tag
  - `tbody` tag `<tbody></tbody>` stands for table body and is used to show the table body
  - The `tbody` element represents a block of rows that consist of a body of data for the parent table element, if the `tbody` element has a parent and it is a table.
    - To represent a row of cells in a table `<tr></tr>` tags is used and to add values to the body of data, you'll use the `<td></td>` tag inside of tr tag to respectively add values to the corresponding header cells and also using the same order so that the data goes to the correct place. You can add more tr tags to increase the no of rows and add values accordingly to the needs.
