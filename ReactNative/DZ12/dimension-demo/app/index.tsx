import { Pressable, StyleSheet, Text, View } from "react-native";

export default function Index() {
  return (
    <View style={style.container}>
      <Text>Main Page</Text>

      <View style={style.row1}>
        <View style={style.box}></View>
        <View style={style.box2}></View>
      </View>

      <View style={style.row2}>
        <Pressable style={style.button}>
          <Text style={style.text}>Button1</Text>
        </Pressable>
        <Pressable style={style.button}>
          <Text style={style.text}>Button2</Text>
        </Pressable>
        <Pressable style={style.button}>
          <Text style={style.text}>Button3</Text>
        </Pressable>
      </View>
    </View>
  );
}

const style = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: "#fff",
    alignItems: "center",
    justifyContent: "flex-start",
  },

  // Перший ряд: два блоки
  row1: {
    width: "92%",
    backgroundColor: "#e7f291ff",
    flexDirection: "row",
    justifyContent: "space-between",
    alignItems: "center",
    padding: 10,
    borderRadius: 10,
    marginTop: 12
  },
  box: {
    width: "48%",
    height: 120,
    backgroundColor: "#f7ffcc",
    borderRadius: 10,
    borderWidth: 1,
    borderColor: "#dfeaa0"
  },
  box2: {
    width: "48%",
    height: 120,
    backgroundColor: "#f7ffcc",
    borderRadius: 10,
    borderWidth: 1,
    borderColor: "#dfeaa0"
  },

  // Другий ряд: три кнопки
  row2: {
    width: "92%",
    backgroundColor: "#aad2f2ff",
    flexDirection: "row",
    justifyContent: "space-between",
    alignItems: "center",
    padding: 10,
    borderRadius: 10,
    marginTop: 12
  },
  button: {
    width: "31%",
    paddingVertical: 12,
    backgroundColor: "#1e90ff",
    borderRadius: 8,
    borderWidth: 1,
    borderColor: "#1476d6",
    alignItems: "center",
    justifyContent: "center"
  },
  text: {
    fontSize: 14,
    fontWeight: "600",
    color: "#ffffff"
  }
});
