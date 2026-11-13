# IDs and classes in HTML

## IDs

`id` known as identifier, is the attribute and what it means is that `id="mainBox"` says identify this element or whatever with this name mainBox.

- This `id="-value-"` value will be unique to this html file/document, other websites may contain same names but this doc will have only one unique id for every element, since it is used to identify this element.
- Why it is used: In **JS**, we can grab/target particular elements using its `id` (as shown above) and then we can do all sorts of things to that element and its contents. Similarly in **CSS** we can also do the same by using the `id` and then we can do all sorts of styling by grabbing that element.
- An element can contain only one `id` and it is only reserved for that element, it can't be used elsewhere.

## classes

- Classes provide a way to group related elements together. By assigning the same class to multiple elements, you can apply the same styling or behavior to all of them. This makes it easier to manage and maintain consistent styles or functionality across different elements (this is one of the uses, can be used for many other cases using JS, CSS, etc).
  - For example: If you want to style 100 elements like adding background, solid color border, size: 2px,etc , there are 2 ways that can be done;
    1. One way is to add the inline styles (in CSS) to every element by repeatedly writing inside every element,
    2. The other way is to make a class `class="redBg _more classes_'` and then add/define all the inline styles, properties(and others) to a single class name or more of them and add it to that class. So whenever this redbg class or more class is given to a particular element all those defined properties and styles will be added automatically. Class must be given properties firsthand in CSS. 
    3. If you have defined one or more classes, then a single element (or a no of different elements) can contain those 1 or more class. You can add mutliple classes using spaces

- **note**: The class name in HTML is typically user-defined. When assigning a class to an element, you can choose a name that is meaningful and relevant to the purpose or styling of that element.
