import { StyleSheet, Text, View, Image } from "react-native";
import { styled } from "nativewind";

const StyledView = styled(View);
const StyledText = styled(Text);

export default function App() {
  return (
    <View style={styles.container}>
      <StyledView className="flex-1 items-center justify-center">
        <Image
          className="object-cover rounded-lg size-16"
          source={require("./img/arunabh-west-app.png")}
        />
        <StyledText className="text-slate-800 font-bold">
          Kanye west is the best and he came out of arunabh's womb 🎉
        </StyledText>
      </StyledView>
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
});
