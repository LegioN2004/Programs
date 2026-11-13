# Refrsher CSS

**NOTE: here parent element means the main parent div and the child elements means the nested stuff/ child stuff inside that parent div can be more divs or p or any other tags**

## understading units, Percentage(%) and Pixels(px)

### Percentage %

- If there is a screen whose full width is x, then its half width will be x/2. We can also say that full width is 100% and half width is 50%. Eg: the computer screen that you are working with probably has 1920*1080 resolution but people assume it to be width, actually it is the width resolution.(1920 is not always the width.)
- Uski width kitni bhi ho sakta hai, but jitni bhi width hoga uski aadhi width 50% hi hoga. So whenever you will need to take whole screen's half or full or 1/3rd or 1/4th, you will use percentage because it makes those stuff easier. So for half it becomes 50%, for quarter it will be 25%, etc yada iyada.
- So Jab aap screen ke respect main element ke respect main uska ek particular bhaag leenaa chahte ho then you can use percentage, kyunki isme easy parta hai wo sab and wosab pixel ya units me bolna possible hota hai nhi.

### Pixels px

- Lets say we have an element and we want to go not so far as halfway but we want to go thoda sa hi dur then we'll use pixels to do those.
- Pixel is a fixed value, so say we want a element 20px down then that will shift 20px down.
- Pixels are comparatively smaller in respect to percentage values and are used to make the very distinct changes to the dimensions.

### Units

A CSS unit determines the size of a property you're setting for an element or its content. For example, if you wanted to set the property margin of a paragraph, you would give it a specific value. This value includes the CSS unit. Let's look at a small example: p { margin: 20px; }.

## Margin

- The space between two elements is termed as margin.
- When you give margin property values like four of them together then the values go like top right bottom left in a clockwise fashion and if you give two values then it'll go like first top then bottom. eg: `margin: 20px 30px 40px 20px` and `margin: 20px 20px`. Or you can give specific values to different sides since there are side specific properties like `margin-top`, `margin-bottom`, `margin-left`, `margin-right`.

## How to add background image in CSS

- use the property of CSS which goes like `background-image: url()`
- the `background-image` shows the image and the `url()` is used to fetch the image from any given url.
- **NOTE** We'll use another property here which makes the bg image cover the whole area i.e `background-size: cover;` since the image never comes correctly with only the above properties
- **NOTE** We'll use another property here i.e `background-position: ;` which gives us more options(as values) as to which part of the image we want to see, the options include 'top/ bottom/ right/ left/ center' and many more and it does the same as the name suggests like some other properties. This is used to fit the image if it is not fitting properly.

## Understanding position absolute

- Position absolute can be understood by an example of three cars 1, 2, and 3 are going in same direction at the same speed on the same road one after the another. Lets say second car 2 from the middle goes to an overbridge and the two cars 1 and 3 goes from below that bridge one following the other since the place of the second car 2 is blank now, all at the same pace. So if you look from the car 2 that is above then you will only see the car 2 and car 1 since the car 3 is being overlapped from the view by car 2 and if the car 2 goes forward then the car 1 will get overlapped by it ultimately blocking the view of the car 1 and the car 3 will get in view again. **Position absolute** does the same thing, any element that is position absolute will rise up (like car 2) then that element's place will become blank and the next element will take its place. So if we convert the car 1, 2, 3 to element 1,2,3, when element 1 in the first place becomes position absolute then it'll rise up and the following element 2 and 3 will move forward and take the place of 1 and 2 respectively. Same goes for 2, 3 will take 2's place and in case of 3 nothing will take it's place since no element is after 3, if there is then it'll surely take its place.

- Position relative: It is a property relative to the element, we know that an element stays in the boundary position of a box and it cannot move out of that box. When we use the position absolute property it'll be able to move out of that box's boundary but if we want the element to stay inside of the box even after rising up i.e even after using the absolute property then we'll use the position relative property. The relative property is used relative to the thing which we want to keep it limited to, so if we want the element to be limited to that box, we'll use the relative property to that box. So in summary we'll apply absolute to the element and the thing which we want to keep it limited will get the relative one.
  - When we use the position relative on the then the inner stuff which will be relative to that outer element will take values with respect not to the screen but to the outer element.
  - NOTE: if we want to make an element both absolute and relative (when there are child elements to that element which needs to stay relative) then we don't need to do so since using absolute automatically does that for us and as such the child elements to that absolute parent element will take values with respect to the parent element only.

- read the style.css to get more idea in realistic usage

- Also the element 1 , 2 and 3 stay in layers and they rise in the opposite order, so if we use position absolute in 1 it will stay in layer 1 at the lowest for the first, then if layer 2 gets absolute then it'll be above the layer 1 and if layer 3 gets then it will be above both the layer 1 and 2 i.e above all. So layer 1 is at the bottom then comes layer 2 and then comes layer 3.

## Understanding flexbox

- Let's say we have three elements in a parent element(the parent element is big and the child elements are taking less that half the width) which are sitting in a top to bottom order. Now say we want to order them side by side, then we'll apply flexbox to it but not on the child elements, we'll find the parent element of those child elements and then apply **`display: flex`** to it and it'll apply flexbox to it.

- Whenever we apply flexbox to an element, it automatically creates a imaginary top to bottom and left to right axis most commonly known as x and y axis to the element. To work on x-axis(height), **`align-items: ;`** is used, and t y-axis(width) **`justify-content: ;`** is used.
  - justify-content values
    1. center makes all the child elements come together as centered with respect to the parent element
    2. space-between makes the child elements evenly spaced between them only and not on the other side of the extremes with respect to the parent
  - align-items values (does the same things btw but only in the top to bottom direction, some names may be similar and some may not be present)
    1. center makes all the child elements come together as centered with respect to the parent element
    2. space-between makes the child elements evenly spaced between them only and not on the other side of the extremes with respect to the parent
  - Here start means the starting point of the x (top) and y(extreme left) axis and end means ending point of the x(bottom) and y(extreme right).

- NOTE: Always think like this, firstly think of the width where it is then think of the height.
