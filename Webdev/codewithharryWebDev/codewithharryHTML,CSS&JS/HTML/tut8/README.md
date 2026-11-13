# Forms and Input tags

1. **Form action**: `<form action="backend.php"></form>` this form action will give the form details filled in by the user to backend.php(backend.php is an example, may be different backend)

2. **Input** tags: `<input action=""></input>` Forms can have input tags where users will give input, it can be any text, button, checkbox, date, time, email, file, etc. these values text and all go into the quotes as values for the action attribute.
   - `<input>` is an inline element as well as *self closing tag* so it takes as much hori space as possible
   - **self closing tags** can have '/' before the closing '>' but it is not a necessity, not giving the slash will also mean the same as it is a self closing tag.

3. ***Label*** tag:

   ```html
   <label for="_name_">_Name_</label>
   <input type="text" name="myName" id="name">
   ```

   - this is an example of a label tag, **The `<label>` tag in HTML is used to associate text with form elements, such as `<input>`, `<select>`, or `<textarea>`. It provides a textual description or caption for the associated form control, helping users understand the purpose or expected input of the form element.**

   - **Usage**: It gives a label btw like the name written above something heading like. As in the example for using the label tag, the `input` tag (maybe others too) is given an *`id="name"`* (*name* or any word can be used) to which the label must point and then in the label we have to add that same *'`name`'* to the *'`for="_put here value_"`'* so that the pointing completes and now what happens here is that  we can start writing in the box assigned to the name *`id`* of the same `input` tag just by clicking on the label/heading(as written on the top) itself instead of clicking on the box (for convenience in forms). But the same won't work on the other input tags since it doesn't have the label tag.

4. For better line breaks use the **`div`** tags, avoid *`br`* as much as possible. This line break will be done in a better way using css.
   - **`div`**: div tags are one of the important tags, it is like a rectangle box which has some width but 0 height(note we'll not see a line since line has some height) so we'll see nothing. Also div's own height is 0 but the height of its children's makes up the total height of the div(by children it means the nested stuff inside that div tags) so for example if div has some children elements lets say 2, which has height 10 and 20 respectively then the overall div's height will be 30. It is a block element and so it takes the whole width in an html doc and so the next element has to go down.

5. **`Input`** tags can have many options ranging from different types and values, use those accordingly from the *emmet abbrs* given by the lsp

6. ***name*** attribute: In the html file we have used the email type input tag, `Email: <input type="email" name="myEmail" />` here in this type and in all the input tags, we can use the `name` tag that assigns the input/value to its value(`name="value"`) which then backend will use to recognise the corresponding tag(that the value is this tag's); It is so because when we put data in backend, then it has to identify everything, here in this case the email is myEmail. More examples : `<div>Role: <input type="text" name="myRole" /></div>`

7. For the ***submit*** button you can use the 'input:submit emmet abbr' which gives `<input type="submit" value="Submit" />`, where the type is submit and the value should be the name inside the button you want it to be.

8. **`reset`** : It is used to reset any value that is entered in the form, just press the button with the assigned name and everything will reset.

9. You can show square checkboxes using the **`type="checkbox"`** and assign its value to name in the input tag. If you want to make the checkbox checked by default you can use the `checked` attribute(maybe attribute or something other idk)

10. ***Radio button*** (circle and ticked with a dot like checkbox) can be shown using the `type="radio"` and suitable name in the input tag.

11. If the type is **`number`** then you can't add any text. But the only text that can be added is 'e' which shows 10 to the power *the no*. eg: 43 * 10 to the power 2 can be written as = 43e2.

12. ***text area*** is an element provided by html that helps to take long paras as inputs from users. It is like a big box. It also provides `cols` and `height` to adjust the height and width of the box.

13. ***select*** tag:The `select` element represents a control like drop down menu and selecting amongst a set of options

14. **`options`** : As the name suggests it is used to show the options using the `<options value="_some-name_">main_name</options>` tag. `options` will always be in the `select` tags.
      - Here value of `value` should be a name that can be used to recognise what value has been chosen in the menu(in this case) (or used in the form or elsewhere) by the backend.
      - and the one that is in between the tags is for the frontend and is mainly what the user sees as an option.
      - If you want your option to be selected by default then write `selected` after the `value` attribute.
