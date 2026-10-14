import { Text, View } from "react-native";
import SearchBar from "../components/searchBar";

export default function Index() {
  return (
    <View
      style={{
        flex: 1,
        width: "100%",
        alignItems: "center",
      }}
    >
      <SearchBar />
    </View>
  );
}
