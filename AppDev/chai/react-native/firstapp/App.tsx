import React from 'react'; // built on same functionality of reactJS
import {
  // import something from react-native library
  View, // its is almost like a div of the web, but its not
  // you can use it to wrap around text and other stuff
  Text, // to write text strings
  SafeAreaView, // SafeAreaView to  avoid the notches
} from 'react-native';
// import homeScreen from '../firstapp/Screens/homeScreen'

// we are now writing jsx which is html wrapped inside JS, it is neither pure JS or html
function App() {
  // this is all you need to create an app
  // in a jsx tag you need to have an ending tag after an opening tag
  // but this will not work until you return something, so you will need to have a return statement(since it is a function) and in that we'll be writing all the body
  return (
    <SafeAreaView>
      <View>
        <Text>hello whatsapp!</Text>
        <Text>this is my first ugly app</Text>
        <Text>this is my first ugly app</Text>
        <Text>😂😂 emoji bhi lelo</Text>
      </View>
    </SafeAreaView>
  );
}

export default App;
