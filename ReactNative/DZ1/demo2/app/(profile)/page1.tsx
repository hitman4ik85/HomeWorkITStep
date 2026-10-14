import React from "react";
import { View, Text, StyleSheet } from "react-native";

const Page1 = () => {
  return (
    <View style={s.wrap}>
      <View style={s.box}>
        <Text style={s.title}>Page 1</Text>
        <Text style={s.text}>Стартовий екран. Короткий опис.</Text>
      </View>
    </View>
  );
};

const s = StyleSheet.create({
  wrap: { flex: 1, backgroundColor: "#f1f5f9", padding: 16 },
  box: { backgroundColor: "#ffffff", borderRadius: 12, padding: 16 },
  title: { fontSize: 20, fontWeight: "700", marginBottom: 8, color: "#0f172a" },
  text: { fontSize: 14, color: "#334155" }
});

export default Page1;
