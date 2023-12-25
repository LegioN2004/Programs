import React from 'react';
import {Button, StyleSheet, Text, View, useColorScheme} from 'react-native';

function AppPro(): JSX.Element {
  const isDarkMode = useColorScheme() === 'dark';
  return (
    <View style={styles.container}>
      <Text style={isDarkMode ? styles.whiteText : styles.darkText}>
        Hello hiiiiiiiiiii
      </Text>
      <Text style={isDarkMode ? styles.whiteText : styles.darkText}>
        This is apparently my first app and ironically I am doing this in the
        midst of exams
      </Text>
      <View>
        <Button title="kick me" style={styles.button} />
      </View>
    </View>
  );
}
const styles = StyleSheet.create({
  container: {
    flex: 1,
    alignItems: 'center',
    justifyContent: 'center',
    fontWeight: '800',
  },
  whiteText: {
    color: '#FFFFFF',
  },
  darkText: {
    color: '#000000',
  },
  button: {
    paddingTop: 20,
  },
});

export default AppPro;
