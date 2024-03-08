# react-native notes from the channel javascript-mastery

- `<View>` component: it is used to create a container or "view" for the other component

  - It is like a box that holds other components
  - It is similar to `<div>` in html but with some added functionality specific to mobile apps
  - It is often used to create layout structures for other components
  - It has a no of props that can be used to control its appearence and behaviour
  - NOTE: it use flexbox layout by default and that makes it easy to control how its child components are laid out within the container

- more components for creating more fancy stuff that interacts

  - buttons, links, etc
  - But we don't have buttons, but TouchableOpacity
  - TouchableOpacity: if you are looking to create a button or another interactive element that fades in opacity when pressed, you can use the TouchableOpacity component.
  - similar to the button component in react but with more customization and flexibility

- AcitivityIndicator used to show a spinner or a loading indication/animation in the app and its fully customizable, you can customize the size and color of the spinner by setting the size and color props

- Important components

  - Flatlist: used for rendering a long list of items that need to be scrolled efficiently. It's like a map funtion in React but the react-native version has extra features like optimized scroll perf and item separation
    - When to use Flatlist: for larger lists with smooth scrolling
    - When to use map: for smaller lists
  - ScrollView: It is like a box that can hold multiple components and views, providing a scrolling container for them
    - It is like overflow: scroll in html allowing you to easily navigate through a list of items or a large amount of content in our app
    - By using ScrollView we can make sure that the users can easily explore all the content, making the app more intuitive and user-friendly
  - SafeAreaView: It provides a safe zone to render your app's content without being covered by the device's hardware features like the notch, home indicator, or status bar, etc. It ensures the content is displayed within the visible area, making the app more accessible

  ```

  ```

- Firstly we are gonna import the following stuff from the various libraries

```js
import { Stack, useRouter } from 'expo-router';
import { useState } from 'react';
import { SafeAreaView, ScrollView, View } from 'react-native';

import { COLORS, SIZES, icons, images } from '../constants';
import {
 NearbyJobs,
 PopularJobs,
 ScreenHeaderBtn,
 Welcome,
} from '../components';
```
