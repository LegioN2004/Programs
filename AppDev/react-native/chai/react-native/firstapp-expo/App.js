import { StatusBar } from "expo-status-bar";
import { StyleSheet, Text, View } from "react-native";

export default function App() {
  return (
    <View style={styles.container}>
      <Text style={styles.text1}>A fun fact!</Text>
      <Text style={styles.text1}>Ananda is a goru!</Text>
      <StatusBar style="auto" />
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: "#fff",
    alignItems: "center",
    justifyContent: "center",
  },
  text1: {
    fontSize: 50,
    color: "#333", // Change the text color
    textShadowColor: "#ddd", // Add a text shadow color
    textShadowOffset: { width: -1, height: 1 }, // Specify the text shadow offset
    textShadowRadius: 10, // Specify the text shadow radius
  },
});
