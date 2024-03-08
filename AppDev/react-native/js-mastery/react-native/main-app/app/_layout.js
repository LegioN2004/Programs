import { View, Text } from "react-native";

const home = () => {
  return (
    <View>
      <Text styles="styles.container"> home</Text>
    </View>
  );
};

const styles = () => {
  container: {
    alignItems: "center";
    justifyContent: "center";
  }
};

export default home;
