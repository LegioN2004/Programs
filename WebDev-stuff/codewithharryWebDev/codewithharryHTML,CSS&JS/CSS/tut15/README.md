# All about CSS selectors

- What is a CSS selector?
  1. CSS selectors are used to find the element whose property will be set
  2. Selectors are used to target the HTML elements3
  3. Selectors make it easy for us to easily target single/mutliple HTML elements in the markup, and can set all the properties to those elements

  - eg: Here in the example, it is selecting all the paragraph elements in the markup

  ``` css
    p { color: blue; }
  ```

- Types of CSS selectors
  1. CSS element selector
  2. CSS id selector
  3. CSS class selector
  4. CSS grouping selector
  - Usage examples, refer the index.html file
    1. Element selector: When we use the p selector then all the paragraph tags gets selected, so any style applied to that selector will get added to all the `<p>` tags, even if p tag is inside the `<div>` tags that will also get styled. So using the element selector we can target all the elements present in markup regardless of any other tags present here and there
    2. id selector: Here we can give an `id` (id value can be anything be it name, number, etc) to a certain element to target only that individual element for styling. To use that we follow this syntax: `#_id name_{ property: value; }`, first a `#` to denote that we are using the id then secondly the `name` with that `#` followed by the regular syntax of curly braces, opening and property and its value and closing curly braces after the ending of the property addition. If we use a different id then obviously the styles we have applied will not take effect.
    **NOTE**: id is unique in the html elements so the id selector can be used to give styling to a single element only and that will be unique to that element only
    ***When to use: When we need to apply a certain styling to only one element then use the id selector in css. For eg: when we want to darken only a certain element we'll use the id selector***
    3. class selector: Same as the previous id selector, we need to add a class to the element which we want to target and then in the style.css add a `.` like the id selector but inplace of the `#`. By using `.` we can target that element even if the `#` points somewhere else. The syntax goes like this: `._id name_ { property: value; }` (similar to what the id selector does)
    **NOTE**: class can be multiple and can be used multiple times in the html elements so the class selector can be used to give styling to a many elements.
    ***When to use: When we need to apply a certain styling to same elements a no of times then we use the class selector in css***
    4. CSS grouping: if we want to add some property to different elements we can do that by adding the names separated by commas. For example: Here we have added background-color as cyan to both footer and span

    ``` css
    footer, span{ background-color: cyan; }
    ```
